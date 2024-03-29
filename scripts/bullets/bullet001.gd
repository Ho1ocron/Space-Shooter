extends Area2D

@export var speed = 1500

var screen_size
var damage = 1



func _ready():
	screen_size = get_viewport_rect().size


func quit():
	print("I quit")
	queue_free()
	

func _process(delta):
	$sprite.rotate(1)
	position += Vector2(1, 0).rotated(global_rotation) * speed * delta


func _on_on_screen_screen_exited():
	queue_free()


# для получения урона объект должен иметь хотя бы один слой из маски пули
# маска пули назначается отправителем пули
func _on_body_entered(body):
	body.health_component.take_damage(damage)
	queue_free()
