#pragma once
#include "Flow.h"
#include "Data.h"
#include <string>

namespace vulgar { namespace blueprint {

	class Branch : public Flow {
	public:
		Flow* trueFlow = nullptr;
		Flow* falseFlow = nullptr;

		Data<bool>* condition;

		virtual Flow* getNextFlow(Context &context) const {
			return condition->get(context) ? trueFlow : falseFlow;
		}

		virtual void run(Context& context) override { }
	};

} };