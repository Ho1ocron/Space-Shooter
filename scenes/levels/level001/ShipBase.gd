extends ShipBase

func _ready():
	health_component.connect("taken_damage", _on_damage)
	health_component.connect("died", _on_death)
	print(self, ": ", health_component.hp, "/", health_component.max_hp)

#func _physics_process(delta):
	#health_component.take_damage(1)

func _on_death():
	print("ded")
	queue_free()

func _on_damage(damage):
	$"../CanvasGroup/ProgressBar".value = health_component.hp
	print(self, ": ", health_component.hp, "/", health_component.max_hp)
