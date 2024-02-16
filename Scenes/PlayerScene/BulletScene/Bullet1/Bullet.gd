extends Area2D

@export var speed = 1500

var screen_size
var damage = 1


@onready var angle_in_radians = get_angle_to(get_global_mouse_position())

func _ready():
	screen_size = get_viewport_rect().size


func quit():
	print("I quit")
	queue_free()
	

func _process(delta):
	$Sprite2D.rotate(1)
	position += Vector2(1, 0).rotated(angle_in_radians) * speed * delta


func _on_on_screen_screen_exited():
	queue_free()


# bodies should have collision layer 2 active for taking damage
func _on_body_entered(body):
	if !body.is_in_group("team"):
		body.take_damage(damage)
		queue_free()
