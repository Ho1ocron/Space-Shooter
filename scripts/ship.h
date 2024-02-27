#ifndef SHIP_CLASS_H
#define SHIP_CLASS_H


#ifdef WIN32
#include <windows.h>
#endif


#include <godot_cpp/classes/character_body2d.hpp>
#include <godot_cpp/classes/input_event_key.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/core/binder_common.hpp>


using namespace godot;


class Ship : public CharacterBody2D 
{
    GDCLASS(Ship, CharacterBody2D)

    private:

    protected:
        static void _bind_methods();

    public:
        Ship();
        ~Ship();
        
        void _process(double delta) override;

};

#endif