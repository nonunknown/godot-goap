

#ifndef FSM_CLASS_H
#define FSM_CLASS_H

// We don't need windows.h in this plugin but many others do and it throws up on itself all the time
// So best to include it and make sure CI warns us when we use something Microsoft took for their own goals....
#ifdef WIN32
#include <windows.h>
#endif

#include "shared.hpp"

namespace goap
{
	

	struct FSMState
	{
		std::function<void(FSM* fsm, Node* node )> update;
	};


	class FSM : public RefCounted {
		GDCLASS(FSM, RefCounted);

	protected:
		static void _bind_methods();
		void push_state(FSMState state);
		void pop_state();

	private:
		std::stack<FSMState> state_stack;
		
	public:
		// FSMState create_state(StringName name);
		void update(Node* node);
		
		FSM();
		~FSM();

	};

}

#endif // ! FSM_CLASS_H
