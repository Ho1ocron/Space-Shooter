extends CharacterBody2D

class_name ship_base

signal got_damage
signal dash_charge

@export_category("HP")
@export var max_hp = 100 # Какого то фига не работает @export var max_hp: int, почему-то он постоянно = 0, даже когда не 0
@export_flags_2d_physics var bullet_target: int
@export var SPEED = 500
@export var MAX_SPEED = 1000
@export var RESISTANCE = 500
@export var isPlayer = false
@export var TWOGUNS = true
@export var MYCURVE: Curve
@export var gunResource: PackedScene

#@onready var settings = preload("res://Scenes/MainScene/Settings/settings.tscn")
#@onready var screen_size = get_viewport_rect().size

var gun_left: Node2D
var gun_right: Node2D
var rotation_speed = 0.1
var max_tick = 31
var tick = 0
var hp = max_hp
var doStop = false
var resistanceEnabled = true

const acceleration = 1

#@export_flags_2d_physics var bullet_target = (1 << 1) | (1 << 2) # 2, 3

#var screen_size = get_viewport_rect().size


func _enter_tree():
	if TWOGUNS:
		print(hp)
		gun_left = gunResource.instantiate()
		gun_right = gunResource.instantiate()
		
		add_child(gun_left)
		add_child(gun_right)
		
		gun_left.owner = self
		gun_right.owner = self
		
		#gun_left.transform = $gunpos_left.transform
		#gun_right.transform = $gunpos_right.transform
		
		gun_left.global_transform = $gunpos_left.global_transform
		gun_right.global_transform = $gunpos_right.global_transform
		gun_left.bullet_target = bullet_target
		gun_right.bullet_target = bullet_target


func take_damage(damage: int):
	hp -= damage
	if hp <= 0:
		queue_free()
	print("hp: ", hp)


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
	print("smt")


func _process(delta):
	pass
	#gun_left.try_shoot() # УБИВАТЬ УБИВАТЬ УБИВАТЬ УБИВАТЬ
	#gun_right.try_shoot()
