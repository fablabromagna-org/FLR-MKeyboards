// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_names {
    _L1,
    _L2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Layout physical keys index
     *
     * ┌────┬────┬────┬────┐
     * │  0 │  1 │  2 │  3 │
     * ├────┼────┼────┼────┤
     * │  4 │  5 │  6 │  7 │
     * ├────┼────┼────┼────┼─────────────┐
     * │  8 │  9 │ 10 │ 11 │EncoderSwitch│
     * └────┴────┴────┴────┴─────────────┘
     */

    [_L1] = LAYOUT_numpad_3x4(
        KC_P7,   KC_P8,   KC_P9,   KC_P0,   MO(_L2),
        KC_P4,   KC_P5,   KC_P6,   KC_PDOT,
        KC_P1,   KC_P2,   KC_P3,   KC_PENT
    ),

    [_L2] = LAYOUT_numpad_3x4(
        KC_Q,   KC_W,   KC_E,   KC_R,   MO(_L2), 
        KC_A,   KC_S,   KC_D,   KC_F,
        KC_Z,   KC_X,   KC_C,   KC_V
    )


};



#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = {   ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [1] = {   ENCODER_CCW_CW(KC_DOWN, KC_UP)  }
};
#endif

#ifdef OLED_ENABLE


    oled_rotation_t oled_init_user(oled_rotation_t rotation) {
        return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    }



   bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _L1:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _L2:
            oled_write_P(PSTR("LAYER2\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("\nNUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("\nCAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("\nSCR ") : PSTR("    "), false);
    
    return false;
}
#endif
