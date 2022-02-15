

#ifndef IGOAP_CLASS_H
#define IGOAP_CLASS_H

// We don't need windows.h in this plugin but many others do and it throws up on itself all the time
// So best to include it and make sure CI warns us when we use something Microsoft took for their own goals....
#ifdef WIN32
#include <windows.h>
#endif

#include "shared.hpp"

namespace goap
{

	class IGoap : public RefCounted {
		GDCLASS(IGoap, RefCounted);

	protected:
		static void _bind_methods();

		strob_map* get_world_state();
		strob_map create_goal_state();
		void plan_failed(strob_map* failed_goal);
		void plan_found(strob_map* goal, action_queue* actions);
		void actions_finished();
		void plan_aborted(Ref<GoapAction> aborter);
		bool move_agent(Ref<GoapAction> next_action);

	private:

	public:

		IGoap();
		~IGoap();

	};

}

#endif // ! IGOAP_CLASS_H
