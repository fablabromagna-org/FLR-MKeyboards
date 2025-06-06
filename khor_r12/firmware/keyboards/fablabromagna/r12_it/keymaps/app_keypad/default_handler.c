#include QMK_KEYBOARD_H
#include "keys_definitions.h"

return_selection_t handler_keypad_default(uint8_t appid, uint8_t mode,
                                         uint8_t key_id, uint8_t tap_count,
                                         bool is_hold) {
  return_selection_t ret_selection = {.appid = appid, .mode = mode};

  if (mode == 0) {

    /* Part Design and Views Mode */
    switch (key_id) {
    case KEY_1:
      if (tap_count == 1 && !is_hold) {
        tap_code(KC_F1);
      } else if (tap_count == 2) {
      } else if (tap_count == 1 && is_hold) {
      }
      break;

    case KEY_2:
      if (tap_count == 1 && !is_hold) {
        tap_code(KC_F2);
      }
      if (tap_count == 2 && !is_hold) {
      }
      break;

    case KEY_3:
      if (tap_count == 1 && !is_hold) {
        tap_code(KC_F3);
      }
      break;

    case KEY_4:
      if (tap_count == 1 && !is_hold) {
        tap_code(KC_F4);
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
        tap_code(KC_1);
      } else if (tap_count == 1 && is_hold) {
        ret_selection.mode = 0;
      }

      break;

    case KEY_10:
      if (tap_count == 1 && !is_hold) {
        tap_code(KC_2);
      } else if (tap_count == 1 && is_hold) {
        ret_selection.mode = 1;
      }
      break;

    case KEY_11:
      if (tap_count == 1 && !is_hold) {
                tap_code(KC_3);
      } else if (tap_count == 1 && is_hold) {
        ret_selection.mode = 2;
      }
      break;

    case KEY_12:
      if (tap_count == 1 && !is_hold) {
                tap_code(KC_4);
      } else if (tap_count == 1 && is_hold) {
        ret_selection.mode = 3;
      }

      break;

    case KEY_ENCODER:
      if (tap_count == 1 && !is_hold) {
        tap_code(KC_ENTER);
      }
      break;
    }
  } else if (mode == 1) {
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
        // SEND_STRING("vs");
      }
      if (tap_count == 2 && !is_hold) {
        // SEND_STRING(SS_LALT(SS_LCTL(SS_LSFT("p"))) "a" );
      }
      break;

    case KEY_3:
      if (tap_count == 1 && !is_hold) {
      }
      break;

    case KEY_4:
      if (tap_count == 1 && !is_hold) {
      } else if (tap_count == 1 && is_hold) {
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
        tap_code(KC_ENTER);
      }
      break;
    }
  }

  return ret_selection;
}


bool handler_encoder_default(uint8_t index, bool clockwise) {

  if (clockwise) {
    tap_code(KC_UP);
  } else {
    tap_code(KC_DOWN);
  }

  return false;
}

bool handler_oled_default(current_selection_t current_selection) {

  
  oled_write_P(PSTR(APP_NAME_DEFAULT), false);

  if (current_selection.mode == 0) {
    /* Part Design and Views */
    oled_write_P(PSTR(" M0 \n\n"), false);

    oled_write_P(PSTR("F1   "), false);
    oled_write_P(PSTR("F2   "), false);
    oled_write_P(PSTR("F3   "), false);
    oled_write_P(PSTR("F4  \n"), false);

    oled_write_P(PSTR("      "), false);
    oled_write_P(PSTR("      "), false);
    oled_write_P(PSTR("      "), false);
    oled_write_P(PSTR("      \n"), false);

    oled_write_P(PSTR("1     "), false);
    oled_write_P(PSTR("2     "), false);
    oled_write_P(PSTR("3     "), false);
    oled_write_P(PSTR("4     "), false);
  }
  return false;
}
