extends CharacterBody2D

class_name ship_base
signal got_damage
signal dash_charge

@export_category("HP")
@export var max_hp = 100
@export var hp = max_hp

@export var gun1_node_path: NodePath
@export var gunResource: PackedScene
@onready var settings = preload("res://Scenes/MainScene/Settings/settings.tscn")
@onready var screen_size = get_viewport_rect().size

var gun_left: Node2D
var gun_right: Node2D
@export var SPEED = 500
@export var MAX_SPEED = 1000
@export var MYCURVE: Curve
@export var RESISTANCE = 500
@export var isPlayer = false
@export var TWOGUNS = true
var rotation_speed = 0.1
var doStop = false
var resistanceEnabled = true
var max_tick = 31
var tick = 0
const acceleration = 1

#var screen_size = get_viewport_rect().size

func _enter_tree():
	if TWOGUNS:
		gun_left = gunResource.instantiate()
		gun_right = gunResource.instantiate()
		add_child(gun_left)
		add_child(gun_right)
		gun_left.owner = self
		gun_right.owner = self
		gun_left.global_transform = $gunpos_left.global_transform
		gun_right.global_transform = $gunpos_right.global_transform

func take_damage(damage: int):
	hp -= damage




#func _physics_process(delta):
	#pass
	##common_movingF()
	##Dash_Timer_Ticking()
	###inertiaF(delta)
	##move_and_slide()
	##
	##position = position.clamp(Vector2.ZERO, screen_size)





func hurt():
	got_damage.emit()

func _process(delta):
	gun_left.try_shoot() # УБИВАТЬ УБИВАТЬ УБИВАТЬ УБИВАТЬ
	gun_right.try_shoot()
