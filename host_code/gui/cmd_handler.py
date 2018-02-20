import sys

import serial_if as serial

com_port = ''

def cmd_init():
	print(com_port+"hej")
	serial.serial_init(com_port)

def cmd_deinit():
	serial.serial_exit()

def set_com_port(port):
	com_port = port;
	print(com_port)

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