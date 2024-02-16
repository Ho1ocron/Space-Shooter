extends Node2D


@export var base_damage = 1
var can_shoot = false



@onready var bullet_node = preload("res://Scenes/PlayerScene/BulletScene/Bullet1/Bullet.tscn")

func try_shoot(): # called by ship
	if (can_shoot):
		can_shoot = false
		$cooldown.start()
		var bullet = bullet_node.instantiate()
		bullet.position = global_position
		owner.owner.add_child(bullet)

func _process(delta):
	look_at(get_viewport().get_mouse_position())

func _on_cooldown():
	can_shoot = true
