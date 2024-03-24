#ifndef SHIP_CLASS_H
#define SHIP_CLASS_H

#include <godot_cpp/classes/character_body2d.hpp>
#include <godot_cpp/classes/marker2d.hpp>
#include <memory>

#include "health_component.h"
#include "specifications.h"

using namespace godot;

class ShipBase : public CharacterBody2D {
    GDCLASS(ShipBase, CharacterBody2D)
    Vector2 direction;

public:
    Ref<HealthComponent> health;
    Ref<Specifications> specifications;
    NodePath left_lightgun;
    NodePath right_lightgun;
    NodePath hardgun;

    Ref<HealthComponent> get_health_component();
    void set_health_component(const godot::Ref<HealthComponent>&);

    Ref<Specifications> get_specifications();
    void set_specifications(const godot::Ref<Specifications>&);

    NodePath get_left_lightgun();
    void set_left_lightgun(const godot::NodePath&);
    NodePath get_right_lightgun();
    void set_right_lightgun(const godot::NodePath&);
    NodePath get_hardgun();
    void set_hardgun(const godot::NodePath&);

    void apply_specifications();
    // this int should be here
    void _editor_apply_specifications(int);
    ShipBase(Ref<HealthComponent> health, Ref<Specifications> specifications) : health(health), specifications(specifications) {}
    ShipBase();
    ~ShipBase();

    bool _false() { return false; }

    // void _physics_process(double delta);

    Vector2 get_direction();
    void set_direction(Vector2 dir);

    void _process(double delta);

protected:
    static void _bind_methods();
};

#endif  // SHIP_CLASS_H
