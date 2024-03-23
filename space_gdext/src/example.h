/* godot-cpp integration testing project.
 *
 * This is free and unencumbered software released into the public domain.
 */

#ifndef EXAMPLE_CLASS_H
#define EXAMPLE_CLASS_H

// We don't need windows.h in this example plugin but many others do, and it can
// lead to annoying situations due to the ton of macros it defines.
// So we include it and make sure CI warns us if we use something that conflicts
// with a Windows define.
#ifdef WIN32
#include <windows.h>
#endif

#include <godot_cpp/classes/sprite2d.hpp>

#include <godot_cpp/core/binder_common.hpp>

using namespace godot;



class MyExample : public Sprite2D {
    GDCLASS(MyExample, Sprite2D)
    private:
        double time_passed;
        double speed;
    protected:
        static void _bind_methods();
    public:
        MyExample();
        ~MyExample();

        void set_speed(const double& p_speed);
        double get_speed() const;
        void _process(double delta) override;
};

#endif // EXAMPLE_CLASS_H
