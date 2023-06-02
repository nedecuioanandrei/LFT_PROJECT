#pragma once

#include "Flow.h"
#include "Data.h"
#include <string>
#include <iostream>

namespace vulgar { namespace blueprint {

        class PushContext : public Flow {
        public:
            Flow *nextFlow;

            virtual Flow* getNextFlow(Context& context) const {
                return nextFlow;
            }

            virtual void run(Context& context) {
                context.pushContext();
            }
        };

        class PopContext : public Flow {
        public:
            Flow *nextFlow;

            virtual Flow* getNextFlow(Context& context) const {
                return nextFlow;
            }

            virtual void run(Context& context) {
                context.popContext();
            }
        };

    } };