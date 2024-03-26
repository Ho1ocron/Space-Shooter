extends StaticBody2D


@export var health_component: HealthComponent
# Called when the node enters the scene tree for the first time.
func _ready():
	health_component.connect("died", _died)

func _process(delta):
	get_node("sprite").rotate(delta)

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _died():
	print("oh no facility is destroyed")
	queue_free()
