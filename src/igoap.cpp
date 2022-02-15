

#include "igoap.h"

namespace goap
{
	void IGoap::_bind_methods() {
		
		// ClassDB::bind_method(D_METHOD("simple_func"), &IGoap::simple_func);

	}

	

	IGoap::IGoap() {
		UtilityFunctions::print("Constructor.");
	}

	IGoap::~IGoap() {
		UtilityFunctions::print("Destructor.");
	}

}