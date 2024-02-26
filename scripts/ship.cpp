#include "ship.h"


using namespace godot;


void Ship::_bind_methods() {

}


Ship::Ship() {
    time_passed = 0.0;
}


Ship::~Ship() {

}


void Ship::_process(double delta) {
    time_passed += delta;

    Input* input = Input::get_singleton();

    if (input->is_key_pressed(KEY_W)) {
        set_position(Vector2(10.0 + (10.0 * sin(time_passed * 2.0)), 10.0 + (10.0 * cos(time_passed * 2.0))));
    }

    if (input->is_key_pressed(KEY_A)) {
        set_position(Vector2(576.0, 324.0));
    }
}