

#ifndef GOAPACTION_CLASS_H
#define GOAPACTION_CLASS_H

// We don't need windows.h in this plugin but many others do and it throws up on itself all the time
// So best to include it and make sure CI warns us when we use something Microsoft took for their own goals....
#ifdef WIN32
#include <windows.h>
#endif

#include "shared.hpp"


namespace goap 
{

class GoapAction : public RefCounted {
	GDCLASS(GoapAction, RefCounted);

protected:
	static void _bind_methods();

	virtual void reset();
	virtual bool is_done();
	virtual bool check_procedural_condition(Node* agent);
	virtual bool perform(Node* agent);
	virtual bool requires_in_range();

private:
	strob_map preconditions;
	strob_map effects;

	bool in_range = false;

public:
	float cost = 1.0f;
	Node* target;

	void do_reset();
	bool is_in_range();
	void set_in_range(bool in_range);
	void add_precondition(StringName key, Object value);
	void remove_precondition(StringName key);
	void add_effect(StringName key, Object value);
	void remove_effect(StringName key);
	strob_map* get_preconditions();
	strob_map* get_effects();
	

	GoapAction();
	~GoapAction();

};

}

#endif // ! GOAPACTION_CLASS_H
