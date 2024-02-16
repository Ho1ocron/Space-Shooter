extends Control

signal level_back

var levels = ["", "res://Scenes/WorldScene/level1/level1.tscn", "res://Scenes/WorldScene/Level2/Level2.tscn"]


func _ready():
	pass # Replace with function body.


func _on_level_1_pressed():
	get_tree().change_scene_to_file(levels[1])


func _on_level_2_pressed():
	get_tree().change_scene_to_file(levels[2])


func _on_back_pressed():
	hide()
	level_back.emit()
