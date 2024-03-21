Godot 4.2.1\
godot-git-plugin https://github.com/godotengine/godot-git-plugin
---

```
git clone git@github.com:Ho1ocron/Space-Shooter.git
```
(optional --branch=Dev)

``` 
git submodule init
git submodule update
```

---

build godot-cpp:
```
cd space_gdext/godot-cpp
scons target=template_debug generate_bindings=yes -s -j8
```
`-j` is number of compile jobs\
you can set `platform=`

---

build gdextension:
```
cd space_gdext
scons target=template_debug -s -j8
```
`-j` is number of compile jobs\
you can set `platform=`

