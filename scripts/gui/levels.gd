extends Control

signal level_back
signal change_level(id: int)

func _on_level_1_pressed():
	change_level.emit(0)


func _on_level_2_pressed():
	change_level.emit(1)


func _on_back_pressed():
	hide()
	level_back.emit()
