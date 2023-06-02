#pragma once
#include "Data.h"
#include <functional>

namespace vulgar { namespace blueprint {

	template<typename I1, typename I2, typename O, typename Operation>
	class BinaryFunction : public Data<O>{
	public:
		Data<I1>* param1;
		Data<I2>* param2;
		virtual O get(Context& context) {
			return Operation{}(param1->get(context), param2->get(context));
		}
	};

	template<typename T>
	class Sum : public BinaryFunction<T, T, T, std::plus<T>> { };

	template<typename T>
	class Subtract : public BinaryFunction<T, T, T, std::minus<T>>{ };

	template<typename T>
	class Multiply: public BinaryFunction<T, T, T, std::multiplies<T>> { };

	template<typename T>
	class Divide: public BinaryFunction<T, T, T, std::divides<T>> { };

	template<typename T>
	class Modulo : public BinaryFunction<T, T, T, std::modulus<T>> { };

	template<typename T>
	class Equal : public BinaryFunction<T, T, bool, std::equal_to<T>> {};

	template<typename T>
	class NotEqual : public BinaryFunction<T, T, bool, std::not_equal_to<T>> {};

	template<typename T>
	class Greater : public BinaryFunction<T, T, bool, std::greater<T>> {};

	template<typename T>
	class GreaterEqual : public BinaryFunction<T, T, bool, std::greater_equal<T>> {};

	template<typename T>
	class Less : public BinaryFunction<T, T, bool, std::less<T>> {};

	template<typename T>
	class LessEqual : public BinaryFunction<T, T, bool, std::less_equal<T>> {};

    class And : public BinaryFunction<bool, bool, bool, std::logical_and<>> {};

    class Or : public BinaryFunction<bool, bool, bool, std::logical_or<>> {};
}};