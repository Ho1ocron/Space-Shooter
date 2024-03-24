#ifndef SHIP_CLASS_CPP
#define SHIP_CLASS_CPP

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/core/class_db.hpp>
// #include <godot_cpp/godot.hpp>
#include "ship.h"


godot::Ref<HealthComponent> ShipBase::get_health_component() { return godot::Ref<HealthComponent>(health); }
void ShipBase::set_health_component(const godot::Ref<HealthComponent>& health) { this->health = health; }


Ref<Specifications> ShipBase::get_specifications() { return Ref<Specifications>(specifications); }
void ShipBase::set_specifications(const Ref<Specifications>& other) { specifications = other; }


void ShipBase::set_direction(Vector2 dir) {
    this->direction = dir;
}


Vector2 ShipBase::get_direction() {
    return this->direction;
}


void ShipBase::_process(double delta) {
    move_and_collide(this->direction);
}


void ShipBase::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_health_component"), &ShipBase::get_health_component);
    godot::ClassDB::bind_method(godot::D_METHOD("set_health_component", "health_component"), &ShipBase::set_health_component);
    godot::ClassDB::bind_method(godot::D_METHOD("get_specifications"), &ShipBase::get_specifications);
    godot::ClassDB::bind_method(godot::D_METHOD("set_specifications", "specifications"), &ShipBase::set_specifications);
    godot::ClassDB::bind_method(godot::D_METHOD("get_direction"), &ShipBase::get_direction);
    godot::ClassDB::bind_method(godot::D_METHOD("set_direction"), &ShipBase::set_direction);

    godot::ClassDB::add_property("ShipBase",
                                 godot::PropertyInfo(Variant::OBJECT, "health_component", PROPERTY_HINT_RESOURCE_TYPE, "HealthComponent",
                                                     PROPERTY_USAGE_DEFAULT | PROPERTY_USAGE_EDITOR_INSTANTIATE_OBJECT),
                                 "set_health_component", "get_health_component");

    godot::ClassDB::add_property("ShipBase",
                                 godot::PropertyInfo(Variant::OBJECT, "specifications", PROPERTY_HINT_RESOURCE_TYPE, "Specifications",
                                                     PROPERTY_USAGE_DEFAULT | PROPERTY_USAGE_EDITOR_INSTANTIATE_OBJECT),
                                 "set_specifications", "get_specifications");

    godot::ClassDB::add_property (   
        "ShipBase",
        godot::PropertyInfo(Variant::VECTOR2, "direction"),
        "set_direction", "get_direction"
    );
}


ShipBase::ShipBase() {}
ShipBase::~ShipBase() {}





Vector2 Specifications::get_left_lightgun_pos() { return left_lightgun_pos; }
void Specifications::set_left_lightgun_pos(const Vector2& other) { left_lightgun_pos = other; }
Vector2 Specifications::get_right_lightgun_pos() { return right_lightgun_pos; }
void Specifications::set_right_lightgun_pos(const Vector2& other) { right_lightgun_pos = other; }
Vector2 Specifications::get_hardgun_pos() { return hardgun_pos; }
void Specifications::set_hardgun_pos(const Vector2& other) { hardgun_pos = other; }


void Specifications::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_left_lightgun_pos"), &Specifications::get_left_lightgun_pos);
    godot::ClassDB::bind_method(godot::D_METHOD("set_left_lightgun_pos", "left_lightgun_pos"), &Specifications::set_left_lightgun_pos);
    godot::ClassDB::bind_method(godot::D_METHOD("get_right_lightgun_pos"), &Specifications::get_right_lightgun_pos);
    godot::ClassDB::bind_method(godot::D_METHOD("set_right_lightgun_pos", "right_lightgun_pos"), &Specifications::set_right_lightgun_pos);

    godot::ClassDB::add_property("Specifications", godot::PropertyInfo(Variant::VECTOR2, "left_lightgun_pos"), "get_left_lightgun_pos",
                                 "set_left_lightgun_pos");

    godot::ClassDB::add_property("Specifications", godot::PropertyInfo(Variant::VECTOR2, "right_lightgun_pos"), "get_right_lightgun_pos",
                                 "set_right_lightgun_pos");
}

#endif  // SHIP_CLASS_CPP