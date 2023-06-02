#pragma once
#include "Node.h"
#include "Context.h"

namespace vulgar {	namespace blueprint {

	template<typename R>
	class Data : virtual public Node {
	public:
		virtual R get(Context&) = 0;
	};

}};