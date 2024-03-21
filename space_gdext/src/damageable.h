////// ща смержу с другой веткой и продолжу делать <-- clueless
// #ifndef SPECIFICATIONS_CLASS_H
// #define SPECIFICATIONS_CLASS_H

// #include <godot_cpp/core/binder_common.hpp>
// #include <godot_cpp/core/class_db.hpp>

// struct Specifications : public godot::Resource{
//     GDCLASS(Specifications, godot::Resource)
    
//     int hp = 100, max_hp = 100;


//     protected:
//         static void _bind_methods(){
//     	    godot::ClassDB::bind_method(godot::D_METHOD("get_hp"), &Specifications::get_hp);
//     	    godot::ClassDB::bind_method(godot::D_METHOD("set_hp", "hp"), &Specifications::set_hp);
//     	    godot::ClassDB::bind_method(godot::D_METHOD("get_max_hp"), &Specifications::get_hp);
//     	    godot::ClassDB::bind_method(godot::D_METHOD("set_max_hp", "hp"), &Specifications::set_max_hp);
//             godot::ClassDB::add_property("Specifications", godot::PropertyInfo(godot::Variant::INT, "hp"), "set_hp", "get_hp");
//             godot::ClassDB::add_property("Specifications", godot::PropertyInfo(godot::Variant::INT, "max_hp"), "set_max_hp", "get_max_hp");

//             ADD_SIGNAL(godot::MethodInfo("died"));
//             ADD_SIGNAL(godot::MethodInfo("taken_damage", godot::PropertyInfo(godot::Variant::INT, "damage")));
//         }
// };

// #endif // SPECIFICATIONS_CLASS_H