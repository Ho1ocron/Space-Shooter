/* godot-cpp integration testing project.
 *
 * This is free and unencumbered software released into the public domain.
 */

#include "example.h"

#include <godot_cpp/core/class_db.hpp>


using namespace godot;

void MyExample::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_speed"), &MyExample::get_speed);
	ClassDB::bind_method(D_METHOD("set_speed", "p_speed"), &MyExample::set_speed);
    ClassDB::add_property("MyExample", PropertyInfo(Variant::FLOAT, "speed", PROPERTY_HINT_RANGE, "0,20,0.01"), "set_speed", "get_speed");
}

MyExample::MyExample(){
    time_passed = 0.0;
    speed = 1.0;
}

MyExample::~MyExample(){
}

void MyExample::_process(double delta){
    time_passed += delta;
    set_position(Vector2(128.0 * sin(time_passed * speed), 128.0 * cos(time_passed * speed)));
}


void MyExample::set_speed(const double& p_speed) {
	speed = p_speed;
}

double MyExample::get_speed() const {
	return speed;
}