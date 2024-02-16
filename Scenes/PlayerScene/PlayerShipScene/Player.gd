extends CharacterBody2D

signal got_damage
signal dash_charge

@export var gun1_node_path: NodePath

@onready var gun1_node = get_node(gun1_node_path)
@onready var bullet_node = preload("res://Scenes/PlayerScene/BulletScene/Bullet1/Bullet.tscn")
@onready var settings = preload("res://Scenes/MainScene/Settings/settings.tscn")
@onready var screen_size = get_viewport_rect().size

@export var SPEED = 500
@export var MAX_SPEED = 1000
@export var MYCURVE: Curve
@export var RESISTANCE = 500
@export var isPlayer = false

var DashForce = 10000
var DashChargeMax = 100
var DashCharge = DashChargeMax
var rotation_speed = 0.1
var can_dash = true
var dashing = false
var Dash_Timer_Started = false
var dash_direction = Vector2()
var max_HP = 200
var HP = max_HP
var doStop = false
var resistanceEnabled = true
var max_tick = 31
var tick = 0
const acceleration = 1

#var screen_size = get_viewport_rect().size


func common_movingF(): #: "F" means Function
	if not Input.is_action_pressed("StopRotation"):
		rotation = lerp_angle(rotation, (get_viewport().get_mouse_position() - position).angle(), rotation_speed) #: Rotating player if button Alt isn't being pressed 
	
	if Input.is_action_just_pressed("Dash") and can_dash == true:
		$DashCooldown.start()
		dashing = true
		Dash_Timer_Started = true
		dash_direction = Input.get_vector("move_left", "move_right", "move_up", "move_down")
		velocity = dash_direction * DashForce
		$CollisionPolygon2D.set_deferred("disabled", true)
		can_dash = false
		HP -= 25
		DashCharge -= 100
		dash_charge.emit()
		
	else:
		var direction = Input.get_vector("move_left", "move_right", "move_up", "move_down") #: Getting moving direction
		velocity = direction * SPEED #: Moving player
		#direction = direction.normalized()
		var tmp = Vector2.ZERO
		
		if rad_to_deg(velocity.angle_to(direction)) > 136 || rad_to_deg(velocity.angle_to(direction)) < -136:
			pass
		else:
			pass
		#doStop = false
			#print("moving")
			#tmp = direction * MYCURVE.sample_baked((direction * velocity / 1000).length()) * SPEED
			#print("TMP: ", tmp)	
			#velocity += tmp * delta
		

func inertiaF(delta):
	if velocity == Vector2.ZERO && velocity.length() > 5 || doStop:
		doStop = true
	
	if resistanceEnabled && doStop:
		velocity -= velocity.normalized() * RESISTANCE * delta
		#print(velocity)
	
	velocity = velocity.limit_length(MAX_SPEED)
	
	if velocity.length() <= 3 * delta:
		velocity = Vector2.ZERO


func Dash_Timer_Ticking():
	if Dash_Timer_Started == true:
		tick += 1;
		dash_charge.emit()
	else:
		tick = 0
	

func _physics_process(delta):
	common_movingF()
	Dash_Timer_Ticking()
	#inertiaF(delta)
	move_and_slide()
	
	position = position.clamp(Vector2.ZERO, screen_size)


func _on_dash_cooldown_timeout():
	can_dash = true
	Dash_Timer_Started = false
	DashCharge += 100
	dash_charge.emit()
	$CollisionPolygon2D.set_deferred("disabled", false)
	

func hurt():
	got_damage.emit()
