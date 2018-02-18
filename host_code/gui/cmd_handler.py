import sys



def slider_update(source, value):
	#if true: # check which slider
	print(source, ": ", value)

def attack_update(value) :
	slider_update("Attack", value)

def decay_update(value) :
	slider_update("Decay", value)

def sustain_update(value) :
	slider_update("Sustain", value)

def release_update(value) :
	slider_update("Release", value)

def program_action():
	print("Programming")