OLED_ENABLE = yes

ENCODER_ENABLE = yes

TAP_DANCE_ENABLE = yes

SEND_STRING_ENABLE = yes

# enable this if you want to send MIDI events
MIDI_ENABLE = yes

# Enable if you wwant to use console for debug
CONSOLE_ENABLE = yes

SRC += default_handler.c freecad_handler.c midi_handler.c
