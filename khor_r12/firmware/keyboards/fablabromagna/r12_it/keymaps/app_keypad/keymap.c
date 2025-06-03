// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later


/* Application multimode 
 *
 * 2025 ivan.tarozzi@fablabromagna.org
 *
 * How to add an application keymap :
 *
 * 1. define a new enum item in application_ids
 * 2. add a new c file containing the app handler (see freecad_handler.c ad example)
 * 3. add the handler prototype to keys_definitions.h 
 * 4. add a new item to the applications[] array
 * 5. assign encoder actions in encoder_update_user() 
 * 6. print to OLED for each app mode in oled_task_user()
 *
 *
 * Usage:
 * - long-press the encoder switch to enter the app selection mode
 * - select the desired application keymap with encoder rotation
 * - confirm with long-press encoder switch
 * - alternate app mode are usually called long-pressing the buttons 9-12 (but you can define other methods in your handler file)
 * 
*/ 

#include QMK_KEYBOARD_H
#include "print.h"

#include "keys_definitions.h"

/*************************
 * APPLICATIONS MANAGEMENT
 **************************/
enum application_ids {
    _APP_DEFAULT,
    _APP_FREECAD,
    _APP_OBS,
    _APP_INKSCAPE
};


typedef struct {
    uint8_t appid;
    uint8_t  modes;
    char *display_name;  // max 10 chars
    return_selection_t (*handler)(uint8_t appid, uint8_t mode,uint8_t key_id, uint8_t tap_count, bool is_hold);
} application_t;


application_t applications[] = {
    {_APP_DEFAULT, 1, "DEFAULT", NULL},
    {_APP_FREECAD, 2, "FreeCAD", handle_keypad_freecad},
    {_APP_OBS, 1, "OBS", NULL},
    {_APP_INKSCAPE, 1, "INKSCAPE", NULL}
};


typedef struct {
    bool selecting_app;
    uint8_t appid;
    uint8_t  mode;
} current_selection_t;

current_selection_t current_selection = {
    .selecting_app = false,
    .appid = _APP_DEFAULT,
    .mode = 0
};

/*************************
 * TAP DANCE MANAGEMENT
 **************************/

// Enum for tap dance actions
enum tap_dance_keys {
    TD_KEY_1,
    TD_KEY_2,
    TD_KEY_3,
    TD_KEY_4,
    TD_KEY_5,
    TD_KEY_6,
    TD_KEY_7,
    TD_KEY_8,
    TD_KEY_9,
    TD_KEY_10,
    TD_KEY_11,
    TD_KEY_12,
    TD_KEY_ENCODER
};

// Tap dance states
enum tap_dance_states {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
};

// Function to determine tap dance state
uint8_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted || !state->pressed) return TD_DOUBLE_TAP;
        else return TD_DOUBLE_HOLD;
    } else if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    }
    return TD_UNKNOWN;
}


void handle_keypad_action(uint8_t key_id, uint8_t tap_count, bool is_hold);

// Your custom handler function - use macro to generate all callbacks
#define GENERATE_TD_CALLBACK(key_name, key_id) \
    void td_##key_name##_finished(tap_dance_state_t *state, void *user_data) { \
        uint8_t tap_state = cur_dance(state); \
        switch (tap_state) { \
            case TD_SINGLE_TAP: handle_keypad_action(key_id, 1, false); break; \
            case TD_SINGLE_HOLD: handle_keypad_action(key_id, 1, true); break; \
            case TD_DOUBLE_TAP: handle_keypad_action(key_id, 2, false); break; \
            case TD_DOUBLE_HOLD: handle_keypad_action(key_id, 2, true); break; \
            case TD_TRIPLE_TAP: handle_keypad_action(key_id, 3, false); break; \
            case TD_TRIPLE_HOLD: handle_keypad_action(key_id, 3, true); break; \
        } \
    }

// Generate all callback functions
GENERATE_TD_CALLBACK(key_1, KEY_1)
GENERATE_TD_CALLBACK(key_2, KEY_2)
GENERATE_TD_CALLBACK(key_3, KEY_3)
GENERATE_TD_CALLBACK(key_4, KEY_4)
GENERATE_TD_CALLBACK(key_5, KEY_5)
GENERATE_TD_CALLBACK(key_6, KEY_6)
GENERATE_TD_CALLBACK(key_7, KEY_7)
GENERATE_TD_CALLBACK(key_8, KEY_8)
GENERATE_TD_CALLBACK(key_9, KEY_9)
GENERATE_TD_CALLBACK(key_10, KEY_10)
GENERATE_TD_CALLBACK(key_11, KEY_11)
GENERATE_TD_CALLBACK(key_12, KEY_12)
GENERATE_TD_CALLBACK(key_encoder, KEY_ENCODER)



// Reset function for tap dance
void keypad_tap_dance_reset(tap_dance_state_t *state, void *user_data) {
    // Handle any cleanup needed when tap dance resets
    // For example, release held keys
    unregister_code(KC_LCTL); // Release any held modifiers
}

// macro to define tap dance actions
#define TD_ACTION(key_name) ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_##key_name##_finished, keypad_tap_dance_reset)


tap_dance_action_t tap_dance_actions[] = {
    [TD_KEY_1] = TD_ACTION(key_1),
    [TD_KEY_2] = TD_ACTION(key_2),
    [TD_KEY_3] = TD_ACTION(key_3),
    [TD_KEY_4] = TD_ACTION(key_4),
    [TD_KEY_5] = TD_ACTION(key_5),
    [TD_KEY_6] = TD_ACTION(key_6),
    [TD_KEY_7] = TD_ACTION(key_7),
    [TD_KEY_8] = TD_ACTION(key_8),
    [TD_KEY_9] = TD_ACTION(key_9),
    [TD_KEY_10] = TD_ACTION(key_10),
    [TD_KEY_11] = TD_ACTION(key_11),
    [TD_KEY_12] = TD_ACTION(key_12),
    [TD_KEY_ENCODER] = TD_ACTION(key_encoder),
};

// Optional: Configure tap dance timing
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD(TD_KEY_1):
        case TD(TD_KEY_2):
        case TD(TD_KEY_3):
        case TD(TD_KEY_4):
        case TD(TD_KEY_5):
        case TD(TD_KEY_6):
        case TD(TD_KEY_7):
        case TD(TD_KEY_8):
        case TD(TD_KEY_9):
        case TD(TD_KEY_10):
        case TD(TD_KEY_11):
        case TD(TD_KEY_12):
            return 500;  // 500ms for tap dance timing
        default:
            return TAPPING_TERM;
    }
}


/**************************
 * The tap dance generic handler, where the magic happens :)
 **************************/
void handle_keypad_action(uint8_t key_id, uint8_t tap_count, bool is_hold) {
    return_selection_t ret_value;
    uprintf("key_id: %d, tap_count: %d, is_hold: %d\n", key_id, tap_count, is_hold);
    
    if  (key_id == KEY_ENCODER && tap_count == 1 && is_hold) {
        oled_clear();
        current_selection.selecting_app = !current_selection.selecting_app;
    }
    else {
        // TODO: check applications id range
        if (applications[current_selection.appid].handler != NULL) {
            ret_value = applications[current_selection.appid].handler(current_selection.appid, current_selection.mode, key_id, tap_count, is_hold);
            current_selection.appid = ret_value.appid;
            current_selection.mode  = ret_value.mode;
        }
    }            
}


/*************************
 * LAYERS MANAGEMENT
 **************************/

// TODO: remove, obsolete
enum layer_names {
    _L1,
    _L2
};



    


/*************************
 * MAPS THE KEYS
 **************************/

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
        TD(TD_KEY_1), TD(TD_KEY_2),  TD(TD_KEY_3),  TD(TD_KEY_4), 
        TD(TD_KEY_5), TD(TD_KEY_6),  TD(TD_KEY_7),  TD(TD_KEY_8), 
        TD(TD_KEY_9), TD(TD_KEY_10), TD(TD_KEY_11), TD(TD_KEY_12), TD(TD_KEY_ENCODER)
    )
};



/*************************
 * ENCODER MANAGEMENT
 **************************/
 
// Encoder callback
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (current_selection.selecting_app) {
                if (clockwise) {
            
                    uint8_t app_nr = sizeof(applications) / sizeof(applications[0]);
                    if (current_selection.appid < app_nr-1) {
                        current_selection.appid++;
                    }
                }
                else {
                    if (current_selection.appid > 0) {
                        current_selection.appid--;
                    }
                }
           
        }
        else {
            switch (current_selection.appid) {
            case _APP_DEFAULT:
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;
            case _APP_FREECAD:
                if (clockwise) {
                    tap_code(KC_UP);
                } else {
                    tap_code(KC_DOWN);
                }

            default:
                break;
            }
        }
    } 
    return false;
}




/*************************
* OLED MANAGEMENT
**************************/
#ifdef OLED_ENABLE

//Rotate the display 180 degrees
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;  
}


char* oled_get_app_name(uint8_t appid) {
   // TODO: check applications id range
    return applications[appid].display_name;
}

bool oled_task_user(void) {

    if (current_selection.selecting_app) {
        
        oled_write_P(PSTR("SELECT: "), false);
        oled_write_P(PSTR(oled_get_app_name(current_selection.appid)), false);
        
    }
    else {

        oled_write_P(PSTR(oled_get_app_name(current_selection.appid)), false);

        // Submodes 
        if (current_selection.appid == _APP_FREECAD) {
            if (current_selection.mode == 0) {
                /* Part Design and Views */
                oled_write_P(PSTR(" - P.Design\n\n"), false);

                oled_write_P(PSTR("ALL   ") , false);
                oled_write_P(PSTR("FIT   ") , false);
                oled_write_P(PSTR("WRF   ") , false);
                oled_write_P( PSTR("TTR  \n") , false);

                oled_write_P(PSTR("F/C   ") , false);
                oled_write_P(PSTR("BDY   "), false);
                oled_write_P(PSTR("BND   ") , false);
                oled_write_P(PSTR("SKT   \n") , false);

                oled_write_P(PSTR("PAD   ") , false);
                oled_write_P(PSTR("REV   ") , false);
                oled_write_P(PSTR("PKT   ") , false);
                oled_write_P(PSTR("HOL   ") , false);
            }
            if (current_selection.mode == 1) {
                /* Sketcher */
                oled_write_P(PSTR(" - Sketcher\n\n"), false);

                oled_write_P(PSTR("S/O   ") , false);
                oled_write_P(PSTR("      ") , false);
                oled_write_P(PSTR("SEC   ") , false);
                oled_write_P( PSTR("VSP  \n") , false);

                oled_write_P(PSTR("F/C   ") , false);
                oled_write_P(PSTR("T/S   "), false);
                oled_write_P(PSTR("CON   ") , false);
                oled_write_P(PSTR("EXT   \n") , false);

                oled_write_P(PSTR("P/L   ") , false);
                oled_write_P(PSTR("ARC   ") , false);
                oled_write_P(PSTR("CIR   ") , false);
                oled_write_P(PSTR("REC   ") , false);
            }
        }

        
        // Host Keyboard LED Status
        // led_t led_state = host_keyboard_led_state();
        // oled_write_P(led_state.num_lock ? PSTR("\nNUM ") : PSTR("    "), false);
        // oled_write_P(led_state.caps_lock ? PSTR("\nCAP ") : PSTR("    "), false);
        // oled_write_P(led_state.scroll_lock ? PSTR("\nSCR ") : PSTR("    "), false);

    }
    return false;
}
#endif
