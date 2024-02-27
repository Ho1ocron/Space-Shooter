#ifndef DAMAGEABLE_CLASS_H
#define DAMAGEABLE_CLASS_H

#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/core/class_db.hpp>

// class HealthComponent : public godot::Object{
//     GDCLASS(HealthComponent, godot::Object)
class HealthComponent : public godot::RefCounted{
    GDCLASS(HealthComponent, godot::RefCounted)
    int hp, max_hp;

    protected:
        static void _bind_methods(){
    	    godot::ClassDB::bind_method(godot::D_METHOD("take_damage"), &HealthComponent::take_damage);
            // godot::ClassDB::add_property("Damageable", godot::PropertyInfo());
            ADD_SIGNAL(godot::MethodInfo("died"));
        }
    public:
        void take_damage(int damage);

        HealthComponent(int hp, int max_hp): hp(hp), max_hp(max_hp){}
};

#endif