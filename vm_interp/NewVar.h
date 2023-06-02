#pragma once

#include "Flow.h"
#include "Data.h"
#include <string>
#include <iostream>

namespace vulgar { namespace blueprint {

        template<typename T>
        class NewVar : public Flow {
        public:
            Flow *nextFlow;
            std::string varName;
            T value;

            virtual Flow* getNextFlow(Context& context) const {
                return nextFlow;
            }

            virtual void run(Context& context) {
                context.newVar<T>(varName, value);
            }
        };

    } };