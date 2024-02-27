#ifndef SHIP_CLASS_H
#define SHIP_CLASS_H

#include <godot_cpp/classes/character_body2d.hpp>
#include "health_component.h"
#include <memory>

using namespace godot;

struct Specifications{
    unsigned int speed;
    unsigned int rotation_speed;

    Specifications(unsigned int speed, unsigned int rotation_speed) : speed(speed), rotation_speed(rotation_speed){}
};

class ShipBase : public CharacterBody2D{
    GDCLASS(ShipBase, CharacterBody2D)

    public:
        std::shared_ptr<HealthComponent> health;
        Specifications specifications;

        HealthComponent get_health_component();

        // ShipBase(std::shared_ptr<HealthComponent> health);
        ShipBase();
        ~ShipBase();
    
    protected:
        static void _bind_methods();
};


#endif // SHIP_CLASS_H