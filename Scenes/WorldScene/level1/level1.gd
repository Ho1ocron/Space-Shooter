extends Node2D

var isSettings = false


# Called when the node enters the scene tree for the first time.
func _ready():
	process_mode = Node.PROCESS_MODE_PAUSABLE
	#$Music1.play()


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	if Input.is_action_just_pressed("ESC") && isSettings == false:
		$Settings.show()
		isSettings = true
		get_tree().paused = true
		$CanvasGroup.visible = false


func _on_settings_settings_back():
	$SettingsTimer.start()
	get_tree().paused = false
	$CanvasGroup.visible = true
	


func _on_settings_timer_timeout():
	isSettings = false
