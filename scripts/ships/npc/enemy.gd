extends ShipBase 

var target: Node2D

#func inertiaF(delta):
	#if velocity == Vector2.ZERO && velocity.length() > 5 || doStop:
		#doStop = true
	#
	#if resistanceEnabled && doStop:
		#velocity -= velocity.normalized() * RESISTANCE * delta
		##print(velocity)
	#
	#velocity = velocity.limit_length(MAX_SPEED)
	#
	#if velocity.length() <= 3 * delta:
		#velocity = Vector2.ZERO




func _physics_process(delta):
	#inertiaF(delta)
	move_and_slide()
