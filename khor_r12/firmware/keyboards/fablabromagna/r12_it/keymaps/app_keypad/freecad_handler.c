#include QMK_KEYBOARD_H
#include "keys_definitions.h"

return_selection_t handler_keypad_freecad(uint8_t appid, uint8_t mode,
                                         uint8_t key_id, uint8_t tap_count,
                                         bool is_hold) {
  return_selection_t ret_selection = {.appid = appid, .mode = mode};

  if (mode == 0) {

    /* Part Design and Views Mode */
    switch (key_id) {
    case KEY_1:
      if (tap_count == 1 && !is_hold) {
        // tap_code(KC_1);
      } else if (tap_count == 2) {
        // tap_code(KC_A); // Send F1 on double tap
      } else if (tap_count == 1 && is_hold) {
        // tap_code(KC_Q); // Hold Ctrl
      }
      break;

    case KEY_2:
      if (tap_count == 1 && !is_hold) {
        SEND_STRING("vs");
      }
      if (tap_count == 2 && !is_hold) {
        SEND_STRING(SS_LALT(SS_LCTL(SS_LSFT("p"))) "a");
      }
      break;

    case KEY_3:
      if (tap_count == 1 && !is_hold) {
        static bool toogle_state = false;
        toogle_state = !toogle_state;
        if (toogle_state) {
          SEND_STRING("v1");
        } else {
          SEND_STRING("v3");
        }
      }
      break;

    case KEY_4:
      if (tap_count == 1 && !is_hold) {
        SEND_STRING("vt");
      }
      break;

    case KEY_5:
      if (tap_count == 1 && !is_hold) {
        SEND_STRING(SS_LALT(SS_LCTL(SS_LSFT("p"))) "f");
      }
      if (tap_count == 2 && !is_hold) {
        SEND_STRING(SS_LALT(SS_LCTL(SS_LSFT("p"))) "c");
      }
      break;

    case KEY_6:
      if (tap_count == 1 && !is_hold) {
        SEND_STRING(SS_LALT(SS_LCTL(SS_LSFT("p"))) "t");
      }
      break;

    case KEY_7:
      if (tap_count == 1 && !is_hold) {
        SEND_STRING(SS_LALT(SS_LCTL(SS_LSFT("p"))) "b");
      }
      break;

    case KEY_8:
      if (tap_count == 1 && !is_hold) {
        SEND_STRING(SS_LALT(SS_LCTL(SS_LSFT("p"))) "s");

        // Enter skecth mode
        ret_selection.mode = 1;
      }
      break;

    case KEY_9:
      if (tap_count == 1 && !is_hold) {
        SEND_STRING(SS_LALT(SS_LCTL(SS_LSFT("p"))) "p");
      } else if (tap_count == 1 && is_hold) {
        ret_selection.mode = 1;
      }

      break;

    case KEY_10:
      if (tap_count == 1 && !is_hold) {
        SEND_STRING(SS_LALT(SS_LCTL(SS_LSFT("p"))) "r");
      } else if (tap_count == 1 && is_hold) {
        ret_selection.mode = 1;
      }
      break;

    case KEY_11:
      if (tap_count == 1 && !is_hold) {
        SEND_STRING(SS_LALT(SS_LCTL(SS_LSFT("p"))) "k");
      } else if (tap_count == 1 && is_hold) {
        ret_selection.mode = 2;
      }

      break;

    case KEY_12:
      if (tap_count == 1 && !is_hold) {
        SEND_STRING(SS_LALT(SS_LCTL(SS_LSFT("p"))) "h");
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
        SEND_STRING("zs");
      } else if (tap_count == 2) {
        SEND_STRING("zt");
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
        SEND_STRING("qs");
      }
      break;

    case KEY_4:
      if (tap_count == 1 && !is_hold) {
        SEND_STRING("zz");
      } else if (tap_count == 1 && is_hold) {
        SEND_STRING(SS_LALT(SS_LCTL(SS_LSFT("s"))));
        tap_code(KC_ESC);
        ret_selection.mode = 0;
      }
      break;

    case KEY_5:
      if (tap_count == 1 && !is_hold) {
        SEND_STRING("gff");
      }
      if (tap_count == 2 && !is_hold) {
        SEND_STRING("gfc");
      }
      break;

    case KEY_6:
      if (tap_count == 1 && !is_hold) {
        SEND_STRING("gt");
      }
      if (tap_count == 2 && !is_hold) {
        SEND_STRING("gz");
      }
      break;

    case KEY_7:
      if (tap_count == 1 && !is_hold) {
        SEND_STRING("gn");
      }
      if (tap_count == 2 && !is_hold) {
        SEND_STRING("kx");
      }
      break;

    case KEY_8:
      if (tap_count == 1 && !is_hold) {
        SEND_STRING("gx");
      }
      if (tap_count == 2 && !is_hold) {
        SEND_STRING("gi");
      }
      break;

    case KEY_9:
      if (tap_count == 1 && !is_hold) {
        SEND_STRING("gm");
      }
      if (tap_count == 2 && !is_hold) {
        SEND_STRING("gl");
      }
      break;

    case KEY_10:
      if (tap_count == 1 && !is_hold) {
        SEND_STRING("ga");
      }
      if (tap_count == 2 && !is_hold) {
        SEND_STRING("g3a");
      }
      break;

    case KEY_11:
      if (tap_count == 1 && !is_hold) {
        SEND_STRING("gc");
      }
      if (tap_count == 2 && !is_hold) {
        SEND_STRING("g3c");
      }
      break;

    case KEY_12:
      if (tap_count == 1 && !is_hold) {
        SEND_STRING("gr");
      }
      if (tap_count == 2 && !is_hold) {
        SEND_STRING("gs");
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


bool handler_encoder_freecad(uint8_t index, bool clockwise) {

  if (clockwise) {
    tap_code(KC_UP);
  } else {
    tap_code(KC_DOWN);
  }

  return false;
}

bool handler_oled_freecad(current_selection_t current_selection) {

  oled_write_P(PSTR(APP_NAME_FREECAD), false);

  if (current_selection.mode == 0) {
    /* Part Design and Views */
    oled_write_P(PSTR(" - P.Design\n\n"), false);

    oled_write_P(PSTR("ALL   "), false);
    oled_write_P(PSTR("FIT   "), false);
    oled_write_P(PSTR("WRF   "), false);
    oled_write_P(PSTR("TTR  \n"), false);

    oled_write_P(PSTR("F/C   "), false);
    oled_write_P(PSTR("BDY   "), false);
    oled_write_P(PSTR("BND   "), false);
    oled_write_P(PSTR("SKT   \n"), false);

    oled_write_P(PSTR("PAD   "), false);
    oled_write_P(PSTR("REV   "), false);
    oled_write_P(PSTR("PKT   "), false);
    oled_write_P(PSTR("HOL   "), false);
  }
  if (current_selection.mode == 1) {
    /* Sketcher */
    oled_write_P(PSTR(" - Sketcher\n\n"), false);

    oled_write_P(PSTR("S/O   "), false);
    oled_write_P(PSTR("      "), false);
    oled_write_P(PSTR("SEC   "), false);
    oled_write_P(PSTR("VSP  \n"), false);

    oled_write_P(PSTR("F/C   "), false);
    oled_write_P(PSTR("T/S   "), false);
    oled_write_P(PSTR("CON   "), false);
    oled_write_P(PSTR("EXT   \n"), false);

    oled_write_P(PSTR("P/L   "), false);
    oled_write_P(PSTR("ARC   "), false);
    oled_write_P(PSTR("CIR   "), false);
    oled_write_P(PSTR("REC   "), false);
  }

  return false;
}
