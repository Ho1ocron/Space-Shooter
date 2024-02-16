extends Node2D
@onready var bullet_node = preload("res://Scenes/PlayerScene/BulletScene/Bullet1/Bullet.tscn")

var gun_1_can_shoot = true
var gun_2_can_shoot = true

var gun_1_base_damage = 1
var gun_2_base_damage = 1


func _ready():
	pass 


func shoot1F():
	$Gun1AttackSpeed.start()
	var bullet = bullet_node.instantiate()
	bullet.position = $Gun1.global_position
	owner.owner.add_child(bullet)
	gun_1_can_shoot = false


func shoot2F():
	$Gun2AttackSpeed.start()
	var bullet = bullet_node.instantiate()
	bullet.position = $Gun2.global_position
	owner.owner.add_child(bullet)
	gun_2_can_shoot = false


func _process(delta):
	$Gun1.look_at(get_viewport().get_mouse_position())
	$Gun2.look_at(get_viewport().get_mouse_position())
	
	if Input.is_action_pressed("Shoot") and gun_1_can_shoot == true:
		shoot1F()
	
	if Input.is_action_pressed("Shoot") and gun_2_can_shoot == true:
		shoot2F()


func _on_timer_timeout():
	gun_1_can_shoot = true


func _on_gun_2_attack_speed_timeout():
	gun_2_can_shoot = true
