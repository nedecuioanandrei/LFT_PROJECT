#pragma once
#include "Flow.h"
#include "Data.h"
#include <string>
#include <iostream>

namespace vulgar { namespace blueprint {

	template<typename R>
	class GetVar : public Data<R> {
	public:
		std::string varName; //this offset is used to calulate the address of the variable relative to the Execution context.b

		virtual R get(Context& context) {
            return context.getVar<R>(varName);
		}
	};

} };