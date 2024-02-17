extends ship_base 

var target: Node2D

func common_movingF(): #: "F" means Function
	#if not Input.is_action_pressed("StopRotation"):
		#rotation = lerp_angle(rotation, (get_viewport().get_mouse_position() - global_position).angle()+PI/2, rotation_speed) #: Rotating player if button Alt isn't being pressed 

	var direction = Input.get_vector("move_left", "move_right", "move_up", "move_down")
	velocity = direction * SPEED #: Moving player
	#direction = direction.normalized()
	var tmp = Vector2.ZERO
	
	#if rad_to_deg(velocity.angle_to(direction)) > 136 || rad_to_deg(velocity.angle_to(direction)) < -136:
		#pass
	#else:
		#pass
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




func _physics_process(delta):
	common_movingF()
	#inertiaF(delta)
	move_and_slide()
