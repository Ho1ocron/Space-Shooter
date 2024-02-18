extends Node2D



@export var attack_speed: float
@export var rotation_speed: float
@export var bullet_node: PackedScene
## Target of bullet.
## Example: target is enemy == 2; target is player and enemy == 1, 2
var bullet_target
var can_shoot = false


#@onready var bullet_node = preload("res://Scenes/PlayerScene/BulletScene/Bullet1/Bullet.tscn")

func try_shoot(): # called by ship
	if (can_shoot):
		can_shoot = false
		$cooldown.start()
		var bullet = bullet_node.instantiate()
		owner.owner.add_child(bullet)
		bullet.global_transform = global_transform
		bullet.collision_mask = bullet_target


func _process(delta):
	#global_rotation = lerp_angle(global_rotation, (get_viewport().get_mouse_position() - global_position).angle()+PI/2, rotation_speed) #: Rotating player if button Alt isn't being pressed 
	look_at(get_viewport().get_mouse_position())
	#rotation = (get_global_mouse_position() - global_position).angle()+PI/2
	#print(get_global_mouse_position())


func _on_cooldown():
	can_shoot = true


func _ready():
	$cooldown.wait_time = (1/attack_speed)
