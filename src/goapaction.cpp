

#include "goapaction.h"
namespace goap
{

	void GoapAction::_bind_methods() {
		
		// ClassDB::bind_method(D_METHOD("simple_func"), &GoapAction::simple_func);

	}

	void GoapAction::do_reset() {
		in_range = false;
		target = NULL;
		reset();
	}

	bool GoapAction::is_in_range() {
		return in_range;
	}

	void GoapAction::set_in_range(bool in_range) {
		this->in_range = in_range;
	}

	void GoapAction::add_precondition(StringName key, Object value) {
		preconditions.insert(strob(key, value));
	}

	void GoapAction::add_effect(StringName key, Object value) {
		effects.insert(strob(key, value));
	}

	void GoapAction::remove_precondition(StringName key) {
		preconditions.erase(key);
	}

	void GoapAction::remove_effect(StringName key) {
		effects.erase(key);

	}

	strob_map* GoapAction::get_preconditions() {
		return &preconditions;
	}

	strob_map* GoapAction::get_effects() {
		return &effects;
	}

	GoapAction::GoapAction() {
		
	}

	GoapAction::~GoapAction() {
		
	}
}