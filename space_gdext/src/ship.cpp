#ifndef SHIP_CLASS_CPP
#define SHIP_CLASS_CPP

#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/ref.hpp>
// #include <godot_cpp/godot.hpp>
#include "ship.h"

godot::Ref<HealthComponent> ShipBase::get_health_component(){ return godot::Ref<HealthComponent>(health);}
void ShipBase::set_health_component(const godot::Ref<HealthComponent> &health){ this->health = health;}


void ShipBase::_bind_methods(){
    // godot::ClassDB::bind_method(godot::D_METHOD("get_health_component"), &ShipBase::get_health_component);
    godot::ClassDB::bind_method(godot::D_METHOD("get_health_component"), &ShipBase::get_health_component);
	godot::ClassDB::bind_method(godot::D_METHOD("set_health_component", "health_component"), &ShipBase::set_health_component);
	godot::ClassDB::add_property("ShipBase", godot::PropertyInfo(Variant::OBJECT, "health_component", PROPERTY_HINT_RESOURCE_TYPE, "HealthComponent", PROPERTY_USAGE_DEFAULT | PROPERTY_USAGE_EDITOR_INSTANTIATE_OBJECT), "set_health_component", "get_health_component");
}

ShipBase::ShipBase(){
}
ShipBase::~ShipBase(){}

#endif // SHIP_CLASS_CPP