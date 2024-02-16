extends Control

signal settings_back

var isFullscreen = false


# Called when the node enters the scene tree for the first time.
func _ready():
	process_mode = Node.PROCESS_MODE_ALWAYS
	hide()


func _on_fullscreen_pressed():
	if isFullscreen == false:
		DisplayServer.window_set_mode(DisplayServer.WINDOW_MODE_FULLSCREEN)
		$Panel/Fullscreen.text = "Windowed"
		isFullscreen = true
	else:
		DisplayServer.window_set_mode(DisplayServer.WINDOW_MODE_WINDOWED)
		$Panel/Fullscreen.text = "Fullscreen"
		isFullscreen = false


func _on_back_pressed():
	#print("I'm pressed")
	hide()
	settings_back.emit()
	
	print("I'm pressed")
