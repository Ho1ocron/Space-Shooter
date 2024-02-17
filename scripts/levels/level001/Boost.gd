extends ProgressBar

@export var player_node: NodePath
@onready var player = get_node(player_node)
@onready var timer = player.find_child("DashCooldown")


func _ready():
	player.dash_charge.connect(update)
	update()
	


func update():
	if player.get_node("dash_cooldown").is_stopped():
		value = player.tick * 100 / player.max_tick
	else:
		value = 100
