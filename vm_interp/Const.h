#pragma once
#include "Data.h"

namespace vulgar { namespace blueprint {

	template<typename R>
	class Const : public Data<R>{
	private:
		R value;
	public:
		Const(R value) : value(value) {}

		virtual R get(Context& executionContext) {
			return value;
		}
	};

}};