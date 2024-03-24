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

void ShipBase::set_direction(Vector2 dir) { this->direction = dir; }

Vector2 ShipBase::get_direction() { return this->direction; }

void ShipBase::_process(double delta) {
    if (specifications == nullptr) {
        ERR_FAIL_NULL(specifications);
        // move_and_collide(this->direction * 500 * delta);
    } else {
        move_and_collide(this->direction.normalized() * specifications->speed * delta);
        // move_and_collide(this->direction.normalized() * 500 * delta);
    }
}

godot::NodePath ShipBase::get_left_lightgun() { return left_lightgun; }
void ShipBase::set_left_lightgun(const godot::NodePath& other) { this->left_lightgun = other; }
godot::NodePath ShipBase::get_right_lightgun() { return right_lightgun; }
void ShipBase::set_right_lightgun(const godot::NodePath& other) { this->right_lightgun = other; }
godot::NodePath ShipBase::get_hardgun() { return hardgun; }
void ShipBase::set_hardgun(const godot::NodePath& other) { this->hardgun = other; }

void ShipBase::apply_specifications() {
    get_node<Node2D>(left_lightgun)->set_position(specifications->left_lightgun_pos);
    get_node<Node2D>(right_lightgun)->set_position(specifications->right_lightgun_pos);
    get_node<Node2D>(hardgun)->set_position(specifications->hardgun_pos);
    // тут бы еще ограничение длины velocity по новому max_speed но лень
}

void ShipBase::_editor_apply_specifications(int) {
    get_node<Node2D>(left_lightgun)->set_position(specifications->left_lightgun_pos);
    get_node<Node2D>(right_lightgun)->set_position(specifications->right_lightgun_pos);
    get_node<Node2D>(hardgun)->set_position(specifications->hardgun_pos);
}

void ShipBase::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_health_component"), &ShipBase::get_health_component);
    godot::ClassDB::bind_method(godot::D_METHOD("set_health_component", "health_component"), &ShipBase::set_health_component);
    godot::ClassDB::bind_method(godot::D_METHOD("get_specifications"), &ShipBase::get_specifications);
    godot::ClassDB::bind_method(godot::D_METHOD("set_specifications", "specifications"), &ShipBase::set_specifications);
    godot::ClassDB::bind_method(godot::D_METHOD("get_left_lightgun"), &ShipBase::get_left_lightgun);
    godot::ClassDB::bind_method(godot::D_METHOD("set_left_lightgun", "specifications"), &ShipBase::set_left_lightgun);
    godot::ClassDB::bind_method(godot::D_METHOD("get_right_lightgun"), &ShipBase::get_right_lightgun);
    godot::ClassDB::bind_method(godot::D_METHOD("set_right_lightgun", "specifications"), &ShipBase::set_right_lightgun);
    godot::ClassDB::bind_method(godot::D_METHOD("get_hardgun"), &ShipBase::get_hardgun);
    godot::ClassDB::bind_method(godot::D_METHOD("set_hardgun", "specifications"), &ShipBase::set_hardgun);
    godot::ClassDB::bind_method(godot::D_METHOD("apply_specifications"), &ShipBase::apply_specifications);
    godot::ClassDB::bind_method(godot::D_METHOD("_editor_apply_specifications"), &ShipBase::_editor_apply_specifications);
    godot::ClassDB::bind_method(godot::D_METHOD("_false"), &ShipBase::_false);

    godot::ClassDB::add_property_group("ShipBase", "Components", "");
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
    godot::ClassDB::add_property("ShipBase", godot::PropertyInfo(Variant::BOOL, "apply_specs"), "_editor_apply_specifications", "_false");

    godot::ClassDB::add_property_group("ShipBase", "Guns", "");
    godot::ClassDB::add_property("ShipBase",
                                 godot::PropertyInfo(Variant::NODE_PATH, "left_lightgun", PROPERTY_HINT_RESOURCE_TYPE, "Node2D",
                                                     PROPERTY_USAGE_DEFAULT | PROPERTY_USAGE_EDITOR_INSTANTIATE_OBJECT),
                                 "set_left_lightgun", "get_left_lightgun");
    godot::ClassDB::add_property("ShipBase",
                                 godot::PropertyInfo(Variant::NODE_PATH, "right_lightgun", PROPERTY_HINT_RESOURCE_TYPE, "Node2D",
                                                     PROPERTY_USAGE_DEFAULT | PROPERTY_USAGE_EDITOR_INSTANTIATE_OBJECT),
                                 "set_right_lightgun", "get_right_lightgun");
    godot::ClassDB::add_property("ShipBase",
                                 godot::PropertyInfo(Variant::NODE_PATH, "hardgun", PROPERTY_HINT_RESOURCE_TYPE, "Node2D",
                                                     PROPERTY_USAGE_DEFAULT | PROPERTY_USAGE_EDITOR_INSTANTIATE_OBJECT),
                                 "set_hardgun", "get_hardgun");

    godot::ClassDB::add_property("ShipBase", godot::PropertyInfo(Variant::VECTOR2, "direction"), "set_direction", "get_direction");
}

ShipBase::ShipBase() {}
ShipBase::~ShipBase() {}

#endif  // SHIP_CLASS_CPP