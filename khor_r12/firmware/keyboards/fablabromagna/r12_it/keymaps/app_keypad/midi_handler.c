/*

 https://docs.qmk.fm/features/midi

*/




#include QMK_KEYBOARD_H
#include "keys_definitions.h"


#define MIDI_CC_OFF 0
#define MIDI_CC_ON  127

extern MidiDevice midi_device;

uint8_t cc_val = 0;

bool handler_encoder_midi(uint8_t index, bool clockwise) {

    bool ret = false;

    if (clockwise) {
        if (cc_val < 127) cc_val ++;
    } else {
        if (cc_val > 0) cc_val--;
    }

    midi_send_cc(&midi_device, midi_config.channel, 80, cc_val);

    return ret;
}


bool handler_oled_midi(current_selection_t current_selection) {
  oled_write_P(PSTR(APP_NAME_MIDI), false);

  if (current_selection.mode == 0) {
    /* Part Design and Views */
    oled_write_P(PSTR(" M0 \n\n"), false);

    oled_write_P(PSTR("ccON "), false);
    oled_write_P(PSTR("ccOF "), false);
    oled_write_P(PSTR("     "), false);
    oled_write_P(PSTR("     \n"), false);

    oled_write_P(PSTR("PC1   "), false);
    oled_write_P(PSTR("PC2   "), false);
    oled_write_P(PSTR("      "), false);
    oled_write_P(PSTR("      \n"), false);

    oled_write_P(PSTR("     "), false);
    oled_write_P(PSTR("     "), false);
    oled_write_P(PSTR("     "), false);
    oled_write_P(PSTR("     "), false);
  }

    return false;
}

return_selection_t handler_keypad_midi(uint8_t appid, uint8_t mode,uint8_t key_id, uint8_t tap_count, bool is_hold) {

    
    return_selection_t ret_selection = {
        .appid = appid,
        .mode = mode
    };
    

    if (mode == 0) {
                    
                /* Part Design and Views Mode */
                switch (key_id) {
                case KEY_1:
                    if (tap_count == 1 && !is_hold) {
                         midi_send_cc(&midi_device, midi_config.channel, 80, MIDI_CC_ON);
                    } else if (tap_count == 2) {
                        //tap_code(KC_A); // Send F1 on double tap
                    } else if (tap_count == 1 && is_hold) {
                        //tap_code(KC_Q); // Hold Ctrl
                    }
                    break;
                    
                case KEY_2:
                    if (tap_count == 1 && !is_hold) {
                        midi_send_cc(&midi_device, midi_config.channel, 80, MIDI_CC_OFF);
                    }
                    if (tap_count == 2 && !is_hold) {
                    }
                    break;
                    
                case KEY_3:
                    if (tap_count == 1 && !is_hold) {
                        
                    }
                    break;

                case KEY_4:
                    if (tap_count == 1 && !is_hold) {
                    }
                    break;

                case KEY_5:
                    if (tap_count == 1 && !is_hold) {
                        midi_send_programchange(&midi_device, midi_config.channel, 1);
                    }
                    if (tap_count == 2 && !is_hold) {
                    }
                    break;

                case KEY_6:
                    if (tap_count == 1 && !is_hold) {
                        midi_send_programchange(&midi_device, midi_config.channel, 2);
                    }
                    break;
                    
                case KEY_7:
                    if (tap_count == 1 && !is_hold) {
                    }
                    break;
                
                case KEY_8:
                    if (tap_count == 1 && !is_hold) {
                    }
                    break;

                case KEY_9:
                    if (tap_count == 1 && !is_hold) {
                    }
                    else if (tap_count == 1 && is_hold) {
                        ret_selection.mode = 0;
                    }

                    break;

                case KEY_10:
                    if (tap_count == 1 && !is_hold) {
                    }
                    else if (tap_count == 1 && is_hold) {
                        ret_selection.mode = 1;
                    }
                    break;

                case KEY_11:
                    if (tap_count == 1 && !is_hold) {
                    }
                    else if (tap_count == 1 && is_hold) {
                    }

                    break;
                    
                case KEY_12:
                    if (tap_count == 1 && !is_hold) {
                    }
                    else if (tap_count == 1 && is_hold) {
                    }

                    break;
                
                case KEY_ENCODER:
                    if (tap_count == 1 && !is_hold) {
                    }
                    break;
                }
            }
    else if (mode == 1) {
                /* Sketch Mode */
                
                switch (key_id) {
                case KEY_1:
                    if (tap_count == 1 && !is_hold) {
                    } else if (tap_count == 2) {
                    } else if (tap_count == 1 && is_hold) {
                        
                    }
                    break;
                    
                case KEY_2:
                    if (tap_count == 1 && !is_hold) {
                    }
                    if (tap_count == 2 && !is_hold) {
                    }
                    break;
                    
                case KEY_3:
                    if (tap_count == 1 && !is_hold) {
                    }
                    break;

                case KEY_4:
                    if (tap_count == 1 && !is_hold) {
                    }
                    else if (tap_count == 1 && is_hold) {
                    }
                    break;

                case KEY_5:
                    if (tap_count == 1 && !is_hold) {
                    }
                    if (tap_count == 2 && !is_hold) {
                    }
                    break;

                case KEY_6:
                   if (tap_count == 1 && !is_hold) {
                    }
                    if (tap_count == 2 && !is_hold) {
                    }
                    break;
                    
                case KEY_7:
                    if (tap_count == 1 && !is_hold) {
                    }
                    if (tap_count == 2 && !is_hold) {
                    }                    
                    break;
                
                case KEY_8:
                    if (tap_count == 1 && !is_hold) {
                    }
                    if (tap_count == 2 && !is_hold) {
                    }                    
                    break;

                case KEY_9:
                    if (tap_count == 1 && !is_hold) {
                    }
                    if (tap_count == 2 && !is_hold) {
                    }                    
                    break;

                case KEY_10:
                    if (tap_count == 1 && !is_hold) {
                    }
                    if (tap_count == 2 && !is_hold) {
                    }                    
                    break;

                case KEY_11:
                    if (tap_count == 1 && !is_hold) {
                    }
                    if (tap_count == 2 && !is_hold) {
                    }                    
                    break;
                    
                case KEY_12:
                    if (tap_count == 1 && !is_hold) {
                    }
                    if (tap_count == 2 && !is_hold) {
                    }                    
                    break;
                
                case KEY_ENCODER:
                    if (tap_count == 1 && !is_hold) {
                    }
                    break;
                }
            }
            
            return ret_selection;
}
    