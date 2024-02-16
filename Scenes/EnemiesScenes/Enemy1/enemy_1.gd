extends RigidBody2D

@export var isPlayer = false

@export var max_HP = 10
var HP = max_HP


# Called when the node enters the scene tree for the first time.
func _ready():
	pass # Replace with function body.


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	if HP <= 0:
		queue_free()
	

func took_damage():
	HP -= 1
