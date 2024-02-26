/* godot-cpp integration testing project.
 *
 * This is free and unencumbered software released into the public domain.
 */

#include "example.h"

#include <godot_cpp/core/class_db.hpp>

#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/label.hpp>
#include <godot_cpp/classes/multiplayer_api.hpp>
#include <godot_cpp/classes/multiplayer_peer.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;


void MyExample::_bind_methods() {
}


MyExample::MyExample() {
    time_passed = 0.0;
}


MyExample::~MyExample() {
}


void MyExample::_process(double delta) {
    time_passed += delta;

    Input* input = Input::get_singleton();

    if (input->is_key_pressed(KEY_A)) {
        set_position(Vector2(10.0 + (10.0 * sin(time_passed * 2.0)), 10.0 + (10.0 * cos(time_passed * 2.0))));
    }

    if (input->is_key_pressed(KEY_W)) {
        set_position(Vector2(576.0, 324.0));
    }
}

