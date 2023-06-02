#pragma once
#include "Flow.h"
#include "Data.h"
#include <string>
#include <iostream>

namespace vulgar { namespace blueprint {

	class Print : public Flow{
	public:
		Flow* nextFlow = nullptr;
		Data<std::string>* input;

		virtual Flow* getNextFlow(Context& context) const {
			return nextFlow;
		}
	
		virtual void run(Context& context) {
			std::cout << input->get(context);
		}
	};

}};