extends ShipBase 

signal dash_charge()

# добавить в цпп:
@export var gunResource: PackedScene
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
@export_flags_2d_physics var bullet_target: int
# end

var DashForce = 10000
var DashChargeMax = 100
var DashCharge = DashChargeMax
var can_dash = true
var dashing = false
var dash_direction = Vector2()
@onready var screen_size = get_viewport_rect().size


func _enter_tree():
	if TWOGUNS:
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


func common_movingF(): #: "F" means Function
	if not Input.is_action_pressed("StopRotation"):
		rotation = lerp_angle(rotation, (get_viewport().get_mouse_position() - global_position).angle()+PI/2, rotation_speed) #: Rotating player if button Alt isn't being pressed 
	
	if Input.is_action_just_pressed("Dash") and can_dash == true:
		$dash_cooldown.start()
		dashing = true
		dash_direction = Input.get_vector("move_left", "move_right", "move_up", "move_down")
		velocity = dash_direction * DashForce
		#$colshape.set_deferred("disabled", true)
		can_dash = false
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


func test_moving():
	if not Input.is_action_pressed("StopRotation"):
		rotation = lerp_angle(rotation, (get_viewport().get_mouse_position() - global_position).angle()+PI/2, rotation_speed) #: Rotating player if button Alt isn't being pressed 
	direction = Vector2(500, 500)
	direction = Input.get_vector("move_left", "move_right", "move_up", "move_down")


	#print(direction)
	


func inertiaF(delta):
	if velocity == Vector2.ZERO && velocity.length() > 5 || doStop:
		doStop = true
	
	if resistanceEnabled && doStop:
		velocity -= velocity.normalized() * RESISTANCE * delta
		#print(velocity)
	
	velocity = velocity.limit_length(MAX_SPEED)
	
	if velocity.length() <= 3 * delta:
		velocity = Vector2.ZERO




func _physics_process(delta):
	test_moving()
	#common_movingF()
	#inertiaF(delta)
	#move_and_slide()
	
	if Input.is_action_pressed("Shoot"):
		gun_left.try_shoot()
		gun_right.try_shoot()
	
	position = position.clamp(Vector2.ZERO, screen_size)


func _on_dash_cooldown():
	can_dash = true
	dash_charge.emit()
