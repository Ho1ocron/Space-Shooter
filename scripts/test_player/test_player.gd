extends Node2D

@onready var screen_size = get_viewport_rect().size

var velocity = Vector2(100, 0)


func _ready():
	pass 


func moving(delta):
	if not Input.is_action_pressed("StopRotation"):
		rotation = lerp_angle(rotation, (get_viewport().get_mouse_position() - global_position).angle()+PI/2, $ship.rotation_speed) #: Rotating player if button Alt isn't being pressed
		 
	var input_vector = Vector2.ZERO
	input_vector.x = Input.get_action_strength("move_right") - Input.get_action_strength("move_left")
	input_vector.y = Input.get_action_strength("move_down") - Input.get_action_strength("move_up")
	
	velocity = input_vector.normalized() * $ship.SPEED
	
	# Move the Node2D based on the velocity
	position += velocity * delta

func _process(delta):
	moving(delta)
	
