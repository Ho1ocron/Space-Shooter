#ifndef SHIP_CLASS_CPP
#define SHIP_CLASS_CPP

#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/core/class_db.hpp>
// #include <godot_cpp/godot.hpp>
#include "ship.h"

HealthComponent ShipBase::get_health_component(){ return *health;}


void ShipBase::_bind_methods(){
    godot::ClassDB::bind_method(godot::D_METHOD("get_health_component"), &ShipBase::get_health_component);
}


#endif // SHIP_CLASS_CPP