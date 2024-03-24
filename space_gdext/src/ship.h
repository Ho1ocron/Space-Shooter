#ifndef SHIP_CLASS_H
#define SHIP_CLASS_H

#include <godot_cpp/classes/character_body2d.hpp>
#include <godot_cpp/classes/marker2d.hpp>
#include <memory>

#include "health_component.h"

using namespace godot;

struct Specifications : public Resource 
{
    GDCLASS(Specifications, Resource)

    unsigned int speed;
    unsigned int max_speed;
    unsigned int rotation_speed;
    unsigned int max_hp;

    Vector2 left_lightgun_pos; 
    Vector2 right_lightgun_pos;
    Vector2 hardgun_pos;

   


    Vector2 get_left_lightgun_pos();
    void set_left_lightgun_pos(const Vector2& other);
    Vector2 get_right_lightgun_pos();
    void set_right_lightgun_pos(const Vector2& other);
    Vector2 get_hardgun_pos();
    void set_hardgun_pos(const Vector2& other);

    Specifications(unsigned int speed = 0, unsigned int rotation_speed = 0) : speed(speed), rotation_speed(rotation_speed) {}

protected:
    static void _bind_methods();
};


class ShipBase : public CharacterBody2D 
{
    GDCLASS(ShipBase, CharacterBody2D)
    Vector2 direction;
    

public:

    Ref<HealthComponent> health;
    Ref<Specifications> specifications;

    

    Ref<HealthComponent> get_health_component();
    void set_health_component(const godot::Ref<HealthComponent>&);
    
    Ref<Specifications> get_specifications();
    void set_specifications(const godot::Ref<Specifications>&);

    // ShipBase(std::shared_ptr<HealthComponent> health);
    ShipBase();
    ~ShipBase();

    //void _physics_process(double delta);

    Vector2 get_direction();
    void set_direction(Vector2 dir);

    void _process(double delta);

protected:
    static void _bind_methods();
};


#endif  // SHIP_CLASS_H