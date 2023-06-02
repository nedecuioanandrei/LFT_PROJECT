#pragma once
#include "Data.h"
#include "Context.h"
#include <sstream>

namespace vulgar {	namespace blueprint {

	template<typename I, typename O>
	class Cast : public Data<O>{
	public:
		Data<I>* param;

		virtual O get(Context &context) {
			return (O)(param->get(context));
		}
	};

	
	template<typename T>
	class Cast<T, std::string> : public Data<std::string>{
	public:
		Data<T>* param;

		std::string get(Context& context) {
			return std::to_string(param->get(context));
		}
	};

	template<typename T>
	class Cast<std::string, T> : public Data<T> {
	public:
		Data <std::string> * param;

		T get(Context& context) {
			std::stringstream ss;
			T result;
			ss << param->get(context);
			ss >> result;
			return result;
		}
	};

}};

