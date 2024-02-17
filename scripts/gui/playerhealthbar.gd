extends TextureProgressBar

@export var player_node: NodePath
@onready var player = get_node(player_node)


func _ready():
	player.got_damage.connect(update)
	update()


func update():
	#print("s")
	value = player.hp * 100 / player.max_hp
