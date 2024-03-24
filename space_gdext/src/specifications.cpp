#ifndef SPECIFICATIONS_CLASS_CPP
#define SPECIFICATIONS_CLASS_CPP

#include "specifications.h"

Vector2 Specifications::get_left_lightgun_pos() { return left_lightgun_pos; }
void Specifications::set_left_lightgun_pos(const Vector2& other) { this->left_lightgun_pos = other; }
Vector2 Specifications::get_right_lightgun_pos() { return right_lightgun_pos; }
void Specifications::set_right_lightgun_pos(const Vector2& other) { this->right_lightgun_pos = other; }
Vector2 Specifications::get_hardgun_pos() { return hardgun_pos; }
void Specifications::set_hardgun_pos(const Vector2& other) { this->hardgun_pos = other; }

double Specifications::get_speed() { return speed; }
void Specifications::set_speed(const double& other) { this->speed = other; }
double Specifications::get_max_speed() { return max_speed; }
void Specifications::set_max_speed(const double& other) { this->max_speed = other; }
double Specifications::get_rotation_speed() { return rotation_speed; }
void Specifications::set_rotation_speed(const double& other) { this->rotation_speed = other; }

void Specifications::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_left_lightgun_pos"), &Specifications::get_left_lightgun_pos);
    godot::ClassDB::bind_method(godot::D_METHOD("set_left_lightgun_pos", "left_lightgun_pos"), &Specifications::set_left_lightgun_pos);
    godot::ClassDB::bind_method(godot::D_METHOD("get_right_lightgun_pos"), &Specifications::get_right_lightgun_pos);
    godot::ClassDB::bind_method(godot::D_METHOD("set_right_lightgun_pos", "right_lightgun_pos"), &Specifications::set_right_lightgun_pos);
    godot::ClassDB::bind_method(godot::D_METHOD("get_hardgun_pos"), &Specifications::get_hardgun_pos);
    godot::ClassDB::bind_method(godot::D_METHOD("set_hardgun_pos", "hardgun_pos"), &Specifications::set_hardgun_pos);
    godot::ClassDB::bind_method(godot::D_METHOD("get_speed"), &Specifications::get_speed);
    godot::ClassDB::bind_method(godot::D_METHOD("set_speed", "speed"), &Specifications::set_speed);
    godot::ClassDB::bind_method(godot::D_METHOD("get_max_speed"), &Specifications::get_max_speed);
    godot::ClassDB::bind_method(godot::D_METHOD("set_max_speed", "max_speed"), &Specifications::set_max_speed);
    godot::ClassDB::bind_method(godot::D_METHOD("get_rotation_speed"), &Specifications::get_rotation_speed);
    godot::ClassDB::bind_method(godot::D_METHOD("set_rotation_speed", "rotation_speed"), &Specifications::set_rotation_speed);
    godot::ClassDB::add_property("Specifications", godot::PropertyInfo(godot::Variant::VECTOR2, "left_lightgun_pos"), "set_left_lightgun_pos",
                                 "get_left_lightgun_pos");
    godot::ClassDB::add_property("Specifications", godot::PropertyInfo(godot::Variant::VECTOR2, "right_lightgun_pos"), "set_right_lightgun_pos",
                                 "get_right_lightgun_pos");
    godot::ClassDB::add_property("Specifications", godot::PropertyInfo(godot::Variant::VECTOR2, "hardgun_pos"), "set_hardgun_pos", "get_hardgun_pos");
    godot::ClassDB::add_property("Specifications", godot::PropertyInfo(godot::Variant::FLOAT, "speed"), "set_speed", "get_speed");
    godot::ClassDB::add_property("Specifications", godot::PropertyInfo(godot::Variant::FLOAT, "max_speed"), "set_max_speed", "get_max_speed");
    godot::ClassDB::add_property("Specifications", godot::PropertyInfo(godot::Variant::FLOAT, "rotation_speed"), "set_rotation_speed", "get_rotation_speed");
}

#endif  // SPECIFICATIONS_CLASS_CPP