#pragma once
#include "Flow.h"
#include "Data.h"
#include <string>
#include <iostream>

namespace vulgar { namespace blueprint {

	template<typename ParamT>	
	class SetVar : public Flow {
	public:
		Flow* nextFlow = nullptr;
		Data<ParamT>* input;
		std::string varName;

		virtual Flow* getNextFlow(Context& context) const {
			return nextFlow;
		}

		virtual void run(Context& context) {
            ParamT value = input->get(context);
            context.setVar<ParamT>(varName, value);
		}
	};

}};