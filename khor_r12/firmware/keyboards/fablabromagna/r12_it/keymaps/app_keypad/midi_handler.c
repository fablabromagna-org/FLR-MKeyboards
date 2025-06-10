/*

 https://docs.qmk.fm/features/midi

*/

#include QMK_KEYBOARD_H
#include "keys_definitions.h"

#define MIDI_CC_OFF 0
#define MIDI_CC_ON 127

extern MidiDevice midi_device;

uint8_t cc_val[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
uint8_t cc_selected = 1;
bool channel_selecting = false;
uint8_t channel_selected = 0;

bool handler_encoder_midi(uint8_t index, bool clockwise) {

  bool ret = false;

  if (channel_selecting) {
    if (clockwise) {
        if (channel_selected < 16) channel_selected++;
    }
    else {
        if (channel_selected > 0) channel_selected--;
    }
    midi_config.channel = channel_selected;

  } 
  else {
    if (clockwise) {
      if (cc_val[cc_selected - 1] < 127)
        cc_val[cc_selected - 1]++;
    } else {
      if (cc_val[cc_selected - 1] > 0)
        cc_val[cc_selected - 1]--;
    }

    midi_send_cc(&midi_device, midi_config.channel, cc_selected,
                 cc_val[cc_selected - 1]);
  }
  return ret;
}

bool handler_oled_midi(current_selection_t current_selection) {
  char selected_str[20];

  oled_write_P(PSTR(APP_NAME_MIDI), false);

  
  if (channel_selecting) {
    
    sprintf(selected_str, "\n\n CH %02d", channel_selected);

    oled_write_P(PSTR(selected_str), false);

  } else {

    sprintf(selected_str, " - CH %2d  CC %d\n\n", channel_selected, cc_selected);

    if (current_selection.mode == 0) {
      /* Part Design and Views */
      oled_write_P(PSTR(selected_str), false);

      oled_write_P(PSTR("PC1  "), false);
      oled_write_P(PSTR("PC2  "), false);
      oled_write_P(PSTR("PC3  "), false);
      oled_write_P(PSTR("PC4  \n\n"), false);

      oled_write_P(PSTR("PC5  "), false);
      oled_write_P(PSTR("PC6  "), false);
      oled_write_P(PSTR("PC7  "), false);
      oled_write_P(PSTR("PC8  \n\n"), false);

      oled_write_P(PSTR("PC9  "), false);
      oled_write_P(PSTR("PC10 "), false);
      oled_write_P(PSTR("PC11 "), false);
      oled_write_P(PSTR("PC12 "), false);
    }
  }

  return false;
}

return_selection_t handler_keypad_midi(uint8_t appid, uint8_t mode,
                                       uint8_t key_id, uint8_t tap_count,
                                       bool is_hold) {

  return_selection_t ret_selection = {.appid = appid, .mode = mode};

  if (mode == 0) {

    switch (key_id) {
    case KEY_ENCODER:
      if (tap_count == 1 && !is_hold) {
        channel_selecting = !channel_selecting;
        oled_clear();
      }
      break;
    default:
      // KEYS 1-12
      if (tap_count == 1 && !is_hold) {
        midi_send_programchange(&midi_device, midi_config.channel, key_id);
      } 
      else if (tap_count == 2) {
        cc_selected = key_id;
      } 
      else if (tap_count == 1 && is_hold) {
      }

    }

    /* Mode 0 */
    // switch (key_id) {
    // case KEY_1:
    //   if (tap_count == 1 && !is_hold) {
    //     midi_send_cc(&midi_device, midi_config.channel, 80, MIDI_CC_ON);
    //   } else if (tap_count == 2) {
    //     // tap_code(KC_A); // Send F1 on double tap
    //   } else if (tap_count == 1 && is_hold) {
    //     // tap_code(KC_Q); // Hold Ctrl
    //   }
    //   break;

    // case KEY_2:
    //   if (tap_count == 1 && !is_hold) {
        

    //     midi_send_cc(&midi_device, midi_config.channel, 80, MIDI_CC_OFF);
    //   }
    //   if (tap_count == 2 && !is_hold) {
    //   }
    //   break;

    // case KEY_3:
    //   if (tap_count == 1 && !is_hold) {
    //   }
    //   break;

    // case KEY_4:
    //   if (tap_count == 1 && !is_hold) {
    //   }
    //   break;

    // case KEY_5:
    //   if (tap_count == 1 && !is_hold) {
    //     midi_send_programchange(&midi_device, midi_config.channel, 1);
    //   }
    //   if (tap_count == 2 && !is_hold) {
    //   }
    //   break;

    // case KEY_6:
    //   if (tap_count == 1 && !is_hold) {
    //     midi_send_programchange(&midi_device, midi_config.channel, 2);
    //   }
    //   break;

    // case KEY_7:
    //   if (tap_count == 1 && !is_hold) {
    //   }
    //   break;

    // case KEY_8:
    //   if (tap_count == 1 && !is_hold) {
    //   }
    //   break;

    // case KEY_9:
    //   if (tap_count == 1 && !is_hold) {
    //   } else if (tap_count == 1 && is_hold) {
    //     ret_selection.mode = 0;
    //   }

    //   break;

    // case KEY_10:
    //   if (tap_count == 1 && !is_hold) {
    //   } else if (tap_count == 1 && is_hold) {
    //     ret_selection.mode = 1;
    //   }
    //   break;

    // case KEY_11:
    //   if (tap_count == 1 && !is_hold) {
    //   } else if (tap_count == 1 && is_hold) {
    //   }

    //   break;

    // case KEY_12:
    //   if (tap_count == 1 && !is_hold) {
    //   } else if (tap_count == 1 && is_hold) {
    //   }

    //   break;

    // case KEY_ENCODER:
    //   if (tap_count == 1 && !is_hold) {
    //     channel_selecting = !channel_selecting;
    //     oled_clear();
    // }
    //   break;
    // }
  } 
  
  return ret_selection;
}
