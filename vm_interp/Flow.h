#pragma once
#include "Node.h"
#include "Context.h"

namespace vulgar { namespace blueprint {

	class Flow : virtual public Node {
	public:
		/*
		* This method will retrun the next FlowExe to be run
		*/
		virtual Flow* getNextFlow(Context&) const = 0;
		
		/*
		* The execution of any function starts from one Flow node, it calls the this method [run] for it.
		* After that it calls the getNextFlow to go to the next node and it repeats the process for it.
		* TODO: expain this a little better. 
		*/
		virtual void run(Context&) = 0;
	};

}};