


#include "fsm.h"

namespace goap
{

	void FSM::_bind_methods() {
		
		// ClassDB::bind_method(D_METHOD("simple_func"), &FSM::simple_func);

	}

	void FSM::push_state(FSMState* state) {
		state_stack.push(state);
	}

	void FSM::pop_state() {
		state_stack.pop();
	}

	void FSM::update(Node* node) {
		if ( state_stack.empty() ) {return;}
		state_stack.top()->update(this, node);
		
	}

	FSM::FSM() {
		UtilityFunctions::print("Constructor.");
	}

	FSM::~FSM() {
		UtilityFunctions::print("Destructor.");
	}

}
