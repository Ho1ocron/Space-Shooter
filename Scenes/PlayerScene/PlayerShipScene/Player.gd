extends CharacterBody2D

signal got_damage

@export var gun1_node_path: NodePath

@onready var gun1_node = get_node(gun1_node_path)
@onready var bullet_node = preload("res://Scenes/PlayerScene/BulletScene/Bullet1/Bullet.tscn")
@onready var screen_size = get_viewport_rect().size

var SPEED = 500.0
var DashForce = 10000
var rotation_speed = 0.1
var can_dash = true
var dashing = false
var dash_direction = Vector2()
var max_HP = 6
var HP = max_HP

#var screen_size = get_viewport_rect().size


func common_movingF(): #: "F" means Function
	var mouse_position = get_viewport().get_mouse_position() #: Getting the mouse position
	var angle = (mouse_position - position).angle() #: Getting an angle between the mouse position and player position
	
	if not Input.is_action_pressed("StopRotation"):
		rotation = lerp_angle(rotation, angle, rotation_speed) #: Rotating player if button Alt isn't being pressed 
	
	if Input.is_action_just_pressed("Dash") and can_dash == true:
		$DashCooldown.start()
		dashing = true
		dash_direction = Input.get_vector("move_left", "move_right", "move_up", "move_down")
		velocity = dash_direction * DashForce
		$CollisionPolygon2D.set_deferred("disabled", true)
		can_dash = false
		HP -= 1
		got_damage.emit()
	else:
		var direction = Input.get_vector("move_left", "move_right", "move_up", "move_down") #: Getting moving direction
		velocity = direction * SPEED #: Moving player
		

func _physics_process(delta):
	
	#position.x = clamp(position.x, 0, screen_size.x)
	common_movingF()
	move_and_slide()
	
	position = position.clamp(Vector2.ZERO, screen_size)


func _on_dash_cooldown_timeout():
	can_dash = true
	$CollisionPolygon2D.set_deferred("disabled", false)
	

func hurt():
	HP -= 1
	got_damage.emit()
