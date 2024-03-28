#ifndef SHIP_CLASS_CPP
#define SHIP_CLASS_CPP

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/core/class_db.hpp>
// #include <godot_cpp/godot.hpp>
#include "ship.h"

godot::Ref<HealthComponent> ShipBase::get_health_component() { return godot::Ref<HealthComponent>(health); }
void ShipBase::set_health_component(const godot::Ref<HealthComponent>& other) {
    if (this->health != nullptr) {
        this->health->disconnect("taken_damage", godot::Callable(this, "_on_hc_taken_damage"));
        this->health->disconnect("died", godot::Callable(this, "_on_hc_died"));
    }
    this->health = other;
    this->health->connect("taken_damage", godot::Callable(this, "_on_hc_taken_damage"));
    this->health->connect("died", godot::Callable(this, "_on_hc_died"));
}

Ref<Specifications> ShipBase::get_specifications() { return Ref<Specifications>(specifications); }
void ShipBase::set_specifications(const Ref<Specifications>& other) { specifications = other; }

void ShipBase::set_direction(Vector2 dir) { this->direction = dir; }

Vector2 ShipBase::get_direction() { return this->direction; }

void ShipBase::_integrate_forces(godot::PhysicsDirectBodyState2DExtension* state) {
    ERR_FAIL_NULL_MSG(specifications, (get_path().get_concatenated_names() + godot::StringName(": ShipBase::Specifications is null!")));

    Vector2 lv = state->get_linear_velocity();
    if (direction != Vector2(0.0f, 0.0f)) {
        // // тут фиксить движение // ща // ща буду с сорса копировать движение, всем оставаться на своих местах
        Vector2 tmp{direction * state->get_step() * specifications->speed};
        float currentSpeed = lv.dot(direction.normalized());  // геймпадщикам
        float addSpeed = specifications->max_speed - currentSpeed;
        if (addSpeed <= 0.0f) return;
        float accelSpeed = specifications->speed * state->get_step() * specifications->max_speed;
        if (accelSpeed > addSpeed) accelSpeed = addSpeed * state->get_step();
        lv += direction * accelSpeed;
    } else {  // perform slowing and stop
        if (lv.length() <= state->get_step() * specifications->speed)
            lv = Vector2(0.0f, 0.0f);
        else {
            lv.x += lv.x > 0 ? -specifications->speed * state->get_step() : specifications->speed * state->get_step();
            lv.y += lv.y > 0 ? -specifications->speed * state->get_step() : specifications->speed * state->get_step();
        }
    }
    for (unsigned int i = 0; i < state->get_contact_count(); i++) lv += state->get_contact_collider_velocity_at_position(i);
    state->set_linear_velocity(lv);
}

godot::NodePath ShipBase::get_left_lightgun() { return left_lightgun; }
void ShipBase::set_left_lightgun(const godot::NodePath& other) { this->left_lightgun = other; }
godot::NodePath ShipBase::get_right_lightgun() { return right_lightgun; }
void ShipBase::set_right_lightgun(const godot::NodePath& other) { this->right_lightgun = other; }
godot::NodePath ShipBase::get_hardgun() { return hardgun; }
void ShipBase::set_hardgun(const godot::NodePath& other) { this->hardgun = other; }

void ShipBase::apply_specifications() {
    if (get_node<Node2D>(left_lightgun) != nullptr) get_node<Node2D>(left_lightgun)->set_position(specifications->left_lightgun_pos);
    if (get_node<Node2D>(right_lightgun) != nullptr) get_node<Node2D>(right_lightgun)->set_position(specifications->right_lightgun_pos);
    if (get_node<Node2D>(hardgun) != nullptr) get_node<Node2D>(hardgun)->set_position(specifications->hardgun_pos);
}

void ShipBase::_editor_apply_specifications(int) {
    ERR_FAIL_NULL_MSG(specifications, (get_path().get_concatenated_names() + godot::StringName(": ShipBase::Specifications is null!")));
    if (get_node<Node2D>(left_lightgun) != nullptr) get_node<Node2D>(left_lightgun)->set_position(specifications->left_lightgun_pos);
    if (get_node<Node2D>(right_lightgun) != nullptr) get_node<Node2D>(right_lightgun)->set_position(specifications->right_lightgun_pos);
    if (get_node<Node2D>(hardgun) != nullptr) get_node<Node2D>(hardgun)->set_position(specifications->hardgun_pos);
}
void ShipBase::_editor_read_specifications(int) {
    ERR_FAIL_NULL_MSG(specifications, (get_path().get_concatenated_names() + godot::StringName(": ShipBase::Specifications is null!")));
    if (get_node<Node2D>(left_lightgun) != nullptr) specifications->left_lightgun_pos = get_node<Node2D>(left_lightgun)->get_position();
    if (get_node<Node2D>(right_lightgun) != nullptr) specifications->right_lightgun_pos = get_node<Node2D>(right_lightgun)->get_position();
    if (get_node<Node2D>(hardgun) != nullptr) specifications->hardgun_pos = get_node<Node2D>(hardgun)->get_position();
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
    godot::ClassDB::bind_method(godot::D_METHOD("_editor_read_specifications"), &ShipBase::_editor_read_specifications);
    godot::ClassDB::bind_method(godot::D_METHOD("_false"), &ShipBase::_false);
    godot::ClassDB::bind_method(godot::D_METHOD("_on_hc_taken_damage"), &ShipBase::_on_hc_taken_damage);
    godot::ClassDB::bind_method(godot::D_METHOD("_on_hc_died"), &ShipBase::_on_hc_died);
    godot::ClassDB::bind_method(godot::D_METHOD("get_direction"), &ShipBase::get_direction);
    godot::ClassDB::bind_method(godot::D_METHOD("set_direction"), &ShipBase::set_direction);

    godot::ClassDB::add_property("ShipBase", godot::PropertyInfo(Variant::VECTOR2, "direction", godot::PROPERTY_HINT_NONE, "", PROPERTY_USAGE_NO_EDITOR),
                                 "set_direction", "get_direction");

    godot::ClassDB::add_property_group("ShipBase", "Components", "");

    godot::ClassDB::add_property("ShipBase",
                                 godot::PropertyInfo(Variant::OBJECT, "health_component", PROPERTY_HINT_RESOURCE_TYPE, "HealthComponent",
                                                     PROPERTY_USAGE_DEFAULT | PROPERTY_USAGE_EDITOR_INSTANTIATE_OBJECT),
                                 "set_health_component", "get_health_component");

    godot::ClassDB::add_property("ShipBase",
                                 godot::PropertyInfo(Variant::OBJECT, "specifications", PROPERTY_HINT_RESOURCE_TYPE, "Specifications",
                                                     PROPERTY_USAGE_DEFAULT | PROPERTY_USAGE_EDITOR_INSTANTIATE_OBJECT),
                                 "set_specifications", "get_specifications");
    godot::ClassDB::add_property("ShipBase", godot::PropertyInfo(Variant::BOOL, "apply_specifications"), "_editor_apply_specifications", "_false");
    godot::ClassDB::add_property("ShipBase", godot::PropertyInfo(Variant::BOOL, "read_specifications"), "_editor_read_specifications", "_false");

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

    ADD_SIGNAL(godot::MethodInfo("taken_damage", godot::PropertyInfo(godot::Variant::FLOAT, "damage")));
    ADD_SIGNAL(godot::MethodInfo("died"));
}

ShipBase::ShipBase() {}
ShipBase::~ShipBase() {}

#endif  // SHIP_CLASS_CPP