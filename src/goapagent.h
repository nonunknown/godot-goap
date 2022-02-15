

#ifndef GOAPAGENT_CLASS_H
#define GOAPAGENT_CLASS_H

// We don't need windows.h in this plugin but many others do and it throws up on itself all the time
// So best to include it and make sure CI warns us when we use something Microsoft took for their own goals....
#ifdef WIN32
#include <windows.h>
#endif

#include "shared.hpp"
#include "fsm.h"
#include "goapaction.h"
#include "igoap.h"
#include "goapplanner.h"

namespace goap
{
	class GoapAgent : public Node {
		GDCLASS(GoapAgent, Node);

	protected:
		static void _bind_methods();
		void start();
		void update();

	private:

		FSM state_machine;
		FSMState state_idle, state_moveto, state_perform_action;
		std::unordered_set<Ref<GoapAction>> available_actions;
		std::queue<Ref<GoapAction>> current_actions;
		IGoap data_provider;
		GoapPlanner planner;

		void create_state_idle();
		void create_state_moveto();
		void create_state_perform_action();
		void find_data_provider();
		void load_actions();

		// String pretty_print(strob_map state);
		// String pretty_print(std::queue<GoapAction> actions);
		// String pretty_print(GoapAction** actions);
		// String pretty_print(GoapAction action);


	public:

		
		void add_action(Ref<GoapAction> action);
		Ref<GoapAction> get_action();
		void remove_action();
		bool has_action_plan();


		GoapAgent();
		~GoapAgent();

	};

}

#endif // ! GOAPAGENT_CLASS_H
