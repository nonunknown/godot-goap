

#include "goapagent.h"


namespace goap
{

	void GoapAgent::_bind_methods() {
		
		// ClassDB::bind_method(D_METHOD("simple_func"), &GoapAgent::simple_func);

	}

	void GoapAgent::start() {
		state_machine = FSM();
		available_actions = strob_map();
		current_actions = std::queue<GoapAction>();
		planner = GoapPlanner();
		find_data_provider();
		create_state_idle();
		create_state_moveto();
		create_state_perform_action();
		state_machine.push_state(state_idle);
		load_actions();
	}

	void GoapAgent::create_state_idle() {
		state_idle.update = [](FSM* fsm, Node* node){
			std::cout << "test";
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
		state_machine.update(this);
	}

	void GoapAgent::add_action(Ref<GoapAction> action) {
		available_actions.insert(action);
	}

	Ref<GoapAction> GoapAgent::get_action()


	GoapAgent::GoapAgent() {
		UtilityFunctions::print("Constructor.");
	}

	GoapAgent::~GoapAgent() {
		UtilityFunctions::print("Destructor.");
	}

}