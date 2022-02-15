#ifndef SHARED_H
#define SHARED_H

#include <map>
#include <stack>
#include <unordered_set>
#include <functional>
#include <queue>

#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/variant/string_name.hpp>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/variant/callable.hpp>
#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/label.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

namespace goap {

    typedef std::pair<StringName, Object> strob;
    typedef std::map<StringName, Object> strob_map;

}

#endif