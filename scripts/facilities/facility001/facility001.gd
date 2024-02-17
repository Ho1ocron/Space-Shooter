extends StaticBody2D


@export var Max_HP = 100
var HP = Max_HP
# Called when the node enters the scene tree for the first time.
func _ready():
	pass # Replace with function body.


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	pass

func take_damage(damage: int):
	HP -= damage
