

#include "register_types.h"

#include <godot/gdnative_interface.h>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

#include "fsm.h"
#include "goapaction.h"
#include "goapplanner.h"
#include "goapagent.h"
#include "igoap.h"

using namespace godot;
using namespace goap;

void register_goap_types() {
	ClassDB::register_class<FSM>();
	ClassDB::register_class<GoapAgent>();
	ClassDB::register_class<GoapPlanner>();
	ClassDB::register_class<IGoap>();
	ClassDB::register_class<GoapAgent>();
	ClassDB::register_class<GoapAction>();
}

void unregister_goap_types() {}

extern "C" {

// Initialization.

GDNativeBool GDN_EXPORT goap_library_init(const GDNativeInterface *p_interface, const GDNativeExtensionClassLibraryPtr p_library, GDNativeInitialization *r_initialization) {
	godot::GDExtensionBinding::InitObject init_obj(p_interface, p_library, r_initialization);

	init_obj.register_scene_initializer(register_goap_types);
	init_obj.register_scene_terminator(unregister_goap_types);

	return init_obj.init();
}
}
