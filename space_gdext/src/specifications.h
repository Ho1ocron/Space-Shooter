#ifndef SPECIFICATIONS_CLASS_H
#define SPECIFICATIONS_CLASS_H

#include <godot_cpp/classes/character_body2d.hpp>
#include <godot_cpp/classes/marker2d.hpp>
#include <memory>

#include "health_component.h"

using namespace godot;

struct Specifications : public Resource {
    GDCLASS(Specifications, Resource)

public:
    double speed;           // units per second
    double max_speed;       // units per second
    double rotation_speed;  // radians per second

    Vector2 left_lightgun_pos;
    Vector2 right_lightgun_pos;
    Vector2 hardgun_pos;

    Vector2 get_left_lightgun_pos();
    void set_left_lightgun_pos(const Vector2& other);
    Vector2 get_right_lightgun_pos();
    void set_right_lightgun_pos(const Vector2& other);
    Vector2 get_hardgun_pos();
    void set_hardgun_pos(const Vector2& other);

    double get_speed();
    void set_speed(const double& other);
    double get_max_speed();
    void set_max_speed(const double& other);
    double get_rotation_speed();
    void set_rotation_speed(const double& other);

    Specifications(double speed = 1.0, double max_speed = 1.0, double rotation_speed = 6.28)
        : speed(speed), max_speed(max_speed), rotation_speed(rotation_speed) {}

protected:
    static void _bind_methods();
};

#endif  // SPECIFICATIONS_CLASS_H