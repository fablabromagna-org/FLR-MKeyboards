#ifndef KEYDEF_H_
#define KEYDEF_H_



 // Define key IDs for 4x3 keypad + encoder switch
enum keypad_keys {
    KEY_1 = 1,
    KEY_2,
    KEY_3,
    KEY_4,
    KEY_5,
    KEY_6,
    KEY_7,
    KEY_8,
    KEY_9,
    KEY_10,  
    KEY_11,
    KEY_12,
    KEY_ENCODER
};


typedef struct {
    uint8_t appid;
    uint8_t  mode;
} return_selection_t;


typedef struct {
    bool selecting_app;
    uint8_t appid;
    uint8_t  mode;
} current_selection_t;


#define APP_NAME_DEFAULT "DEFAULT"
return_selection_t handler_keypad_default(uint8_t appid, uint8_t mode,uint8_t key_id, uint8_t tap_count, bool is_hold);
bool handler_encoder_default(uint8_t index, bool clockwise);
bool handler_oled_default(current_selection_t current_selection);


#define APP_NAME_FREECAD "FreeCAD"
return_selection_t handler_keypad_freecad(uint8_t appid, uint8_t mode,uint8_t key_id, uint8_t tap_count, bool is_hold);
bool handler_encoder_freecad(uint8_t index, bool clockwise);
bool handler_oled_freecad(current_selection_t current_selection);


#define APP_NAME_MIDI "MIDI"
return_selection_t handler_keypad_midi(uint8_t appid, uint8_t mode,uint8_t key_id, uint8_t tap_count, bool is_hold);
bool handler_encoder_midi(uint8_t index, bool clockwise);
bool handler_oled_midi(current_selection_t current_selection);




#endif