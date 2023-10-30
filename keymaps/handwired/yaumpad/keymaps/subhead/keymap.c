// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "subhead.h"
#include "strings.c"
#include "private.c"

#ifdef CONSOLE_ENABLE
    /*
    print("string"): Print a simple string.
    uprintf("%s string", var): Print a formatted string
    dprint("string") Print a simple string, but only when debug mode is enabled
    dprintf("%s string", var): Print a formatted string, but only when debug mode is enabled
    */
    #include "print.h"
#endif

#define ARRAYSIZE(arr) sizeof(arr) / sizeof(arr[0])

// define layers
enum custom_user_layers {
    _BASE,
    _FN1,
    _FN2,
    _FN3
};

enum custom_keycodes {
    __PLACEHOLDER__ = SAFE_RANGE,
    KC_CF_MOD,
    KC_LAYER_RESET,
    FOO
}

// some key combos
#define KC_COPY LCTL(KC_C)
#define KC_CUT LCTL(KC_X)
#define KC_PASTE LCTL(KC_V)
#define KC_RF4ASHIFT LSFT(LALT(KC_NUBS))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │ 7 │ 8 │ 9 │   │
     * ├───┼───┼───┤ + │
     * │ 4 │ 5 │ 6 │   │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │   │
     * ├───┴───┼───┤Ent│
     * │   0   │ . │   │
     * └───────┴───┴───┘
     */
    [_BASE] = LAYOUT_numpad_4x4(
        KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        KC_P4,   KC_P5,   KC_P6,
        KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        KC_P0,            KC_PDOT
    )
};

void keyboard_post_init_user(void) {
  #ifdef DEBUG_ENABLE
    // Customise these values to desired behaviour
    debug_enable=true;
    //debug_matrix=true;
    debug_keyboard=true;
    //debug_mouse=true;
  #endif
}

void matrix_init_user(void) {
}


void matrix_scan_user(void) {
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // debug output
    #ifdef CONSOLE_ENABLED
        uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %u, time: %u, interrupt: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
    #endif

    switch (keycode) {
        // sending modifier keys + switch parameter
        // with that we can use a single Fkey and map 
        // additional features behind it
        case KC_CF_MOD:
            if(record->event.pressed) {
                register_code(KC_F19);     
            } else {
                unregister_code(KC_F19);
            }
            return false;
            break;

        // resetting the selected layer to the base layer
        case KC_LAYER_RESET:
            if (record->event.pressed) SEND_STRING(STR_DOUBLE_BSLASHES);
            else unregister_code16(keycode);
            return false;

        // Process all other keycodes normally
        default:
            return true;
    }
}

// encoder updates
bool encoder_update_user(uint8_t index, bool clockwise) {
    uint8_t mods_state = get_mods();
    
    if (clockwise) {
        tap_code(KC_PGDN);
    } else {
        tap_code(KC_PGUP);
    }

    return false;
}