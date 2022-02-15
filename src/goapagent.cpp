

#include "goapagent.h"


namespace goap
{

	void GoapAgent::_bind_methods() {
		
		// ClassDB::bind_method(D_METHOD("simple_func"), &GoapAgent::simple_func);

	}

	void GoapAgent::start() {
		state_machine.instantiate();
		planner.instantiate();

		available_actions = {};
		current_actions = {};

		find_data_provider();
		create_state_idle();
		create_state_moveto();
		create_state_perform_action();

		state_machine->push_state(&state_idle);

		load_actions();
	}

	void GoapAgent::create_state_idle() {
		Ref<IGoap> data = data_provider;

		state_idle.update = [data](FSM* fsm, Node* node){
			
			// strob_map world_state = 

		};
	}

	void GoapAgent::create_state_moveto() {
		state_moveto.update = [](FSM* fsm, Node* node) {

		};
	}

	void GoapAgent::create_state_perform_action() {
		state_perform_action.update = [](FSM* fsm, Node* node) {

		};
	}

	void GoapAgent::update() {
		state_machine->update(this);
	}

	void GoapAgent::add_action(Ref<GoapAction> action) {
		available_actions.insert(action);
	}

	//TODO: FINISH THIS
	Ref<GoapAction> GoapAgent::get_action() {
		return nullptr;
	}


	GoapAgent::GoapAgent() {
		state_idle = FSMState();
		state_moveto = FSMState();
		state_perform_action = FSMState();
		UtilityFunctions::print("Constructor.");
	}

	GoapAgent::~GoapAgent() {
		UtilityFunctions::print("Destructor.");
	}

}