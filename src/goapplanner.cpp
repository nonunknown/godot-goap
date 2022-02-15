

#include "goapplanner.h"

namespace goap
{

	void GoapPlanner::_bind_methods() {
		
		// ClassDB::bind_method(D_METHOD("simple_func"), &GoapPlanner::simple_func);

	}

	GoapPlanner::GoapPlanner() {
		UtilityFunctions::print("Constructor.");
	}

	GoapPlanner::~GoapPlanner() {
		UtilityFunctions::print("Destructor.");
	}

}