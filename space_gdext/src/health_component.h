#ifndef HEALTHCOMPONENT_CLASS_H
#define HEALTHCOMPONENT_CLASS_H

#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/core/class_db.hpp>

// class HealthComponent : public godot::Object{
//     GDCLASS(HealthComponent, godot::Object)
// class HealthComponent : public godot::RefCounted{
//     GDCLASS(HealthComponent, godot::RefCounted)
class HealthComponent : public godot::Resource {
    GDCLASS(HealthComponent, godot::Resource)

    float hp, max_hp;

protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("take_damage", "damage"), &HealthComponent::take_damage);
        godot::ClassDB::bind_method(godot::D_METHOD("set_hp", "hp"), &HealthComponent::set_hp);
        godot::ClassDB::bind_method(godot::D_METHOD("get_hp"), &HealthComponent::get_hp);
        godot::ClassDB::bind_method(godot::D_METHOD("set_max_hp", "max_hp"), &HealthComponent::set_max_hp);
        godot::ClassDB::bind_method(godot::D_METHOD("get_max_hp"), &HealthComponent::get_max_hp);
        godot::ClassDB::add_property("HealthComponent", godot::PropertyInfo(godot::Variant::FLOAT, "hp"), "set_hp", "get_hp");
        godot::ClassDB::add_property("HealthComponent", godot::PropertyInfo(godot::Variant::FLOAT, "max_hp"), "set_max_hp", "get_max_hp");

        ADD_SIGNAL(godot::MethodInfo("died"));
        ADD_SIGNAL(godot::MethodInfo("taken_damage", godot::PropertyInfo(godot::Variant::FLOAT, "damage")));
    }

public:
    void take_damage(const float& damage) {
        hp -= damage;
        emit_signal("taken_damage", damage);
        if (hp <= damage) {
            emit_signal("died");
        }
    }
    float get_hp() { return hp; }
    void set_hp(const float& hp) { this->hp = hp; }
    float get_max_hp() { return max_hp; }
    void set_max_hp(const float& max_hp) { this->max_hp = max_hp; }

    HealthComponent() : max_hp(100.0f), hp(100.0f) {}
    HealthComponent(float hp, float max_hp) : hp(hp), max_hp(max_hp) {}
};

#endif