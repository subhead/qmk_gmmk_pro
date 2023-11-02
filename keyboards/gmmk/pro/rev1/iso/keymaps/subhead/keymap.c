/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>
   Copyright 2022 subhead @subhead
  

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "sendstring_german.h"
#include "rgb_matrix_map.h"
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

// LAYERS
enum custom_user_layers {
    _BASE,
    _UTIL,
    _RGB,
    _MACRO
};

// KEYCODES
enum custom_keycodes {
  __PLACEHOLDER__ = SAFE_RANGE,   // Placeholder dont know why needed otherwise it wont work
  KC_TOGGM,                       // Toggles gaming mode on and off (hightligh of WASD and some other gaming related keys)
  TOG_WINLCK,                      // Toggles Winkey lock on and off
  KC_TEST,                        // Playeholder function
  KC_FDG1,                        // fdg domain suffix
  KC_3D_AR,                       // 3dpb auto reply text
  TOG_ARROW,                      // Toggles highlight of arrow keys
  ST_CBRACK,                      // curly brackets
  ST_ABRACK,                      // angual brackets
  ST_SBRACK,                      // square brackets
  ST_DBSLASH,                     // double backslash
  ST_DSLASH,                      // double slash
  ST_RBRACK,                      // round brackets
  EMO_SHRUG,
  EMO_CONFUSE,
  EMO_TEARS,
  EMO_NERVOUS,
  EMO_JOY,
  EMO_SAD,
  EMO_FLYSAFE,
  KC_RF4ASHIFT,                   // russian fishing 4 auto shifter
  KC_CF24,                        // custom f24 key
  FOO
};
// some key combos
#define KC_COPY LCTL(KC_C)
#define KC_CUT LCTL(KC_X)
#define KC_PASTE LCTL(KC_V)
#define KC_RF4ASHIFT LSFT(LALT(KC_NUBS))

// GLOBALS
#ifdef GAMING_MODE
  static bool is_gaming_mode = true;
#endif

//static bool is_gaming_mode_led_on = false;
#ifdef ARROW_MODE
  static bool is_arrow_mode   = true;
  static uint8_t arrow_keys[] = {94, 80, 98, 96};
#endif

#ifdef RGB_MATRIX_ENABLE
  static uint8_t l_base_functions[]   = {LED_V, LED_ESC, LED_F1, LED_1, LED_Q, LED_F2, LED_2, LED_W, LED_S, LED_X, LED_F3, LED_F4, LED_F5, LED_F6, LED_N, LED_F7, LED_F8, LED_F9, LED_F10, LED_F11, LED_F12, LED_L2, LED_L5, 94, 95, 96, 98};
  static uint8_t l_util_functions[]   = {LED_ESC, LED_F, LED_LWIN, LED_L4};
  static uint8_t l_macro_functions[]  = {LED_ESC, LED_R, LED_F};
#endif

// toggles
static bool rf4_ashift_toggle = false;
//static bool f24_toggle        = false;

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]                          PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "        #        Enter             PgDn
//      Sh_L     /        Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the RESET key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backspace. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    //
    // This keyboard defaults to 6KRO instead of NKRO for compatibility reasons (some KVMs and BIOSes are incompatible with NKRO).
    // Since this is, among other things, a "gaming" keyboard, a key combination to enable NKRO on the fly is provided for convenience.
    // Press Fn+N to toggle between 6KRO and NKRO. This setting is persisted to the EEPROM and thus persists between restarts.
    [_BASE] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,          KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,                   KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,           KC_PGDN,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(_UTIL), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    // function layer with the most used hotkeys/functions
    [_UTIL] = LAYOUT(
        QK_BOOT, KC_MYCM, KC_WHOM, KC_CALC, KC_MSEL, _______, _______, _______, _______, KC_F19, KC_MPRV, KC_MNXT, KC_MPLY, KC_INS,          _______,
        _______, RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, ST_DBSLASH, _______, _______,            _______,
        _______, _______, RGB_VAI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
        _______, _______, RGB_VAD, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,          _______,
        QK_LEAD, _______, _______, RGB_HUI, _______, _______, _______, NK_TOGG, _______, _______, _______, _______,          KC_RF4ASHIFT, RGB_MOD, _______,
        _______, _______, _______,                            _______,                            MO(_RGB), _______, _______, RGB_SPD, RGB_RMOD, RGB_SPI
    ),
    // configuration layer to access toggles etc
    [_RGB] = LAYOUT(
        QK_BOOT,   KC_CF24,  KC_F23, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   TOG_ARROW,
        _______, _______, _______, _______, KC_FDG1, KC_TOGGM, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_F19, _______, _______, _______,          _______, _______, _______,
        _______, TOG_WINLCK, _______,                            _______,                            _______, _______, MO(_MACRO), _______, _______, _______
    ),
    // work layer with txt shotcuts etc
    [_MACRO] = LAYOUT(
        QK_BOOT,     KC_CF24,  KC_F23, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, EMO_SHRUG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______,
        _______, _______, _______, _______, KC_3D_AR, _______, _______, _______, _______, _______, _______, _______, _______,                   TOG_ARROW,
        _______, _______, _______, _______, KC_FDG1, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),


};
// clang-format on

void keyboard_post_init_user(void) {
  #ifdef DEBUG_ENABLE
    // Customise these values to desired behaviour
    debug_enable=true;
    //debug_matrix=true;
    debug_keyboard=true;
    //debug_mouse=true;
  #endif
}

// leader key
#ifdef LEADER_ENABLE
void leader_end_user(void) {
    if (leader_sequence_one_key(KC_7)) {
      SEND_STRING(STR_DOUBLE_SLASHES);
    } else if (leader_sequence_one_key(KC_8)) {
      // double round brackets
      SEND_STRING(STR_ROUND_BRACKETS);
    } else if (leader_sequence_two_keys(KC_8, KC_8)) {
      // double round brackets
      SEND_STRING(STR_SQUARE_BRACKETS);
    } else if (leader_sequence_two_keys(KC_B, KC_T)) {
      // browser reopen last closed tab
      SEND_STRING(SS_LCTL(SS_LSFT("t")));
    } else if (leader_sequence_two_keys(KC_F, KC_D)) {
      // fdg domain
      SEND_STRING(STR_FDG_DOMAIN);
    }
}
#endif

// START ROTARY KNOB
// ripped from: https://github.com/ForsakenRei/qmk_gmmk_pro/blob/main/gmmk/pro/ansi/keymaps/shigure/keymap.c
#ifdef ENCODER_ENABLE // Encoder Functionality
bool encoder_update_user(uint8_t index, bool clockwise)
{ 
  uint8_t mods_state = get_mods();
  if (clockwise) {
    if (mods_state & MOD_BIT(KC_LCTL)) { // if holding Left Ctrl, scroll up and down
      unregister_mods(MOD_BIT(KC_LCTL));
      register_code(KC_PGDN);
      register_mods(MOD_BIT(KC_LCTL));
    }
    else if (mods_state & MOD_BIT(KC_LSFT)) { // if you are holding L shift, scroll left and right
      tap_code16(KC_WH_R);
    }
    else if (mods_state & MOD_BIT(KC_LALT)) { // if holding Left Alt, tab throu open browser tabs
      //tap_code(KC_MEDIA_NEXT_TRACK);
      tap_code16(C(KC_TAB));
    }
    else {
      tap_code(KC_VOLU); // Otherwise it just changes volume
    }
  }
  else {
    if (mods_state & MOD_BIT(KC_LCTL))  {
      unregister_mods(MOD_BIT(KC_LCTL));
      register_code(KC_PGUP);
      register_mods(MOD_BIT(KC_LCTL));
    } 
    else if (mods_state & MOD_BIT(KC_LSFT)) {
      tap_code16(KC_WH_L);
    }
    else if (mods_state & MOD_BIT(KC_LALT)) {
      //tap_code(KC_MEDIA_PREV_TRACK);
      tap_code16(S(C(KC_TAB)));
    }
    else {
      tap_code(KC_VOLD);
    }
  }
  return false;
}
#endif
// END ROTARY KNOB


#ifdef RGB_MATRIX_ENABLE
// caps log flash side bars red, press fn and all mapped keys are highlighted red
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    static uint32_t cycle_led_timer = 0;
    static uint8_t  current_value   = 0;
    static uint8_t  left_side_leds[8] = {68, 71, 74, 77, 81, 84, 88, 92};
    static uint8_t  right_side_leds[8] = {69, 72, 75, 78, 82, 85, 89, 93};

    if (host_keyboard_led_state().caps_lock) {
      if (timer_elapsed32(cycle_led_timer) > 500) {
        current_value = current_value == 0 ? 255 : 0;
        cycle_led_timer = timer_read32();
      }

      HSV tempHSV = {.h = 0, .s = 255, .v = current_value};
      RGB tempRGB = hsv_to_rgb(tempHSV);

      for (uint8_t i = 0; i < sizeof(left_side_leds) / sizeof(left_side_leds[0]); i++) {
        rgb_matrix_set_color(left_side_leds[i], tempRGB.r, tempRGB.g, tempRGB.b);
        rgb_matrix_set_color(right_side_leds[i], tempRGB.r, tempRGB.g, tempRGB.b);
        RGB_MATRIX_INDICATOR_SET_COLOR(LED_CAPS, tempRGB.r, tempRGB.g, tempRGB.b);
      }
    }


    // arrow mode highlight arrow keys
    #ifdef ARROW_MODE
      if(is_arrow_mode) {
        for (uint8_t i = 0; i < sizeof(arrow_keys) / sizeof(arrow_keys[0]); i++) {
          rgb_matrix_set_color(arrow_keys[i], RGB_WHITE);
        }
      }
    #endif

    // Disable WIN Key and light them up also light up WASD gaming keys
    if (keymap_config.no_gui) {
      rgb_matrix_set_color(LED_LWIN, RGB_RED); //light up Win key when disabled

      #ifdef GAMING_MODE
        // highlight gaming keys only when gamingmode is enabled
        if(is_gaming_mode) {
          rgb_matrix_set_color(94, RGB_CHARTREUSE);
          rgb_matrix_set_color(80, RGB_CHARTREUSE);
          rgb_matrix_set_color(98, RGB_CHARTREUSE);
          rgb_matrix_set_color(96, RGB_CHARTREUSE);
          rgb_matrix_set_color(LED_W, RGB_CHARTREUSE); //light up gaming keys with WSAD higlighted
          rgb_matrix_set_color(LED_S, RGB_CHARTREUSE);
          rgb_matrix_set_color(LED_A, RGB_CHARTREUSE);
          rgb_matrix_set_color(LED_D, RGB_CHARTREUSE);
          rgb_matrix_set_color(LED_Q, RGB_ORANGE2);
          rgb_matrix_set_color(LED_E, RGB_ORANGE2);
          rgb_matrix_set_color(LED_R, RGB_ORANGE2);
          rgb_matrix_set_color(LED_TAB, RGB_ORANGE2);
          rgb_matrix_set_color(LED_CAPS, RGB_ORANGE2);
          rgb_matrix_set_color(LED_F, RGB_ORANGE2);
          rgb_matrix_set_color(LED_Z, RGB_ORANGE2);
          rgb_matrix_set_color(LED_X, RGB_ORANGE2);
          rgb_matrix_set_color(LED_C, RGB_ORANGE2);
          rgb_matrix_set_color(LED_V, RGB_ORANGE2);
          rgb_matrix_set_color(LED_SPC, RGB_ORANGE2);
          rgb_matrix_set_color(LED_LCTL, RGB_ORANGE2);
          rgb_matrix_set_color(LED_LSFT, RGB_ORANGE2);
          rgb_matrix_set_color(LED_LALT, RGB_ORANGE2);
        }
      #endif
    }

    // highlight fn keys
    // esc = 0, backspace = 86
  switch(get_highest_layer(layer_state)) {  // special handling per layer
    case 4:  //layer one
      break;
    // macro layer
    case 3:
      for (uint8_t i = 0; i < sizeof(l_macro_functions) / sizeof(l_macro_functions[0]); i++) {
            RGB_MATRIX_INDICATOR_SET_COLOR(l_macro_functions[i], 255, 0, 0);
        }
    break;
    // util layer
    case 2:
      for (uint8_t i = 0; i < sizeof(l_util_functions) / sizeof(l_util_functions[0]); i++) {
            RGB_MATRIX_INDICATOR_SET_COLOR(l_util_functions[i], 255, 0, 0);
        }
    break;
    // base layer
    case 1:
      for (uint8_t i = 0; i < sizeof(l_base_functions) / sizeof(l_base_functions[0]); i++) {
          RGB_MATRIX_INDICATOR_SET_COLOR(l_base_functions[i], 255, 0, 0);
      }
      break;
    default:
      break;
    break;
    }
  return false;
}
#endif // RGB_MATRIX_ENALBED


bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  #ifdef CONSOLE_ENABLED
    uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %u, time: %u, interrupt: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
  #endif 

  switch (keycode) {
    
    case KC_TEST:
      if(record->event.pressed) {
        #ifdef DEBUG_ENABLE
          print("test keycode");
        #endif
      }
      return false;
      break;
  
    // WinLock toggle
    case TOG_WINLCK:
      if (record->event.pressed) {
        keymap_config.no_gui = !keymap_config.no_gui;    
      }
      return false;
      break;

    
    // rf4 ashift toggle
    case KC_RF4ASHIFT:
      if (record->event.pressed) {
        if(rf4_ashift_toggle) {
          register_code(KC_LCTL);
          rf4_ashift_toggle = !rf4_ashift_toggle;
        } else {
          register_code(KC_LCTL);
          rf4_ashift_toggle = !rf4_ashift_toggle;
        }
      }
      return false;
      break;
      
    case KC_TOGGM:
      if (record->event.pressed) {
        is_gaming_mode = !is_gaming_mode;
      }
      return false;
      break;

    case KC_FDG1:
      if(record->event.pressed) SEND_STRING(STR_FDG_DOMAIN);
      else unregister_code16(keycode);
      return false;
      break;

    case TOG_ARROW:
      if (record->event.pressed) {
        is_arrow_mode = !is_arrow_mode;
      }
      return false;
      break;

    // 3dpb related hotkeys
    case KC_3D_AR:
      if(record->event.pressed) SEND_STRING(STR_3DPB_AUTOREPLY);
      else unregister_code16(keycode);
      return false;
      break;

    case RESET:  // when activating RESET mode for flashing
      if (record->event.pressed) {
          rgb_matrix_set_color_all(63, 0, 0);
          rgb_matrix_driver.flush();
      }
      return true;

    // brackets/slashes
    case ST_CBRACK:
      if (record->event.pressed) SEND_STRING(STR_CURLY_BRACKETS);
      else unregister_code16(keycode);
      return false;
    
    case ST_SBRACK:
      if (record->event.pressed) SEND_STRING(STR_SQUARE_BRACKETS);
      else unregister_code16(keycode);
      return false;

    case ST_ABRACK:
      if (record->event.pressed) SEND_STRING(STR_ANGLE_BRACKETS);
      else unregister_code16(keycode);
      return false;

    case ST_RBRACK:
      if (record->event.pressed) SEND_STRING(STR_ROUND_BRACKETS);
      else unregister_code16(keycode);
      return false;

    case ST_DSLASH:
      if (record->event.pressed) SEND_STRING(STR_DOUBLE_SLASHES);
      else unregister_code16(keycode);
      return false;

    case ST_DBSLASH:
      if (record->event.pressed) SEND_STRING(STR_DOUBLE_BSLASHES);
      else unregister_code16(keycode);
      return false;

    // f keys extension
    case KC_CF24:
      if(record->event.pressed) {
        register_code(KC_F24);     
      } else {
        unregister_code(KC_F24);
      }
      return false;
      break;



    // emoticons
    #ifdef EMOTICON_ENABLE
      case EMO_SHRUG:
        if (record->event.pressed) SEND_STRING(STR_EMO_SHRUG);
        else unregister_code16(keycode);
        return false;
      case EMO_CONFUSE:
        if (record->event.pressed) SEND_STRING(STR_EMO_CONFUSE);
        else unregister_code16(keycode);
        return false;
      case EMO_TEARS:
        if (record->event.pressed) SEND_STRING(STR_EMO_TEARS);
        else unregister_code16(keycode);
        return false;
      case EMO_NERVOUS:
        if (record->event.pressed) SEND_STRING(STR_EMO_NERVOUS);
        else unregister_code16(keycode);
        return false;
      case EMO_JOY:
        if (record->event.pressed) SEND_STRING(STR_EMO_JOY);
        else unregister_code16(keycode);
        return false;
      case EMO_SAD:
        if (record->event.pressed) SEND_STRING(STR_EMO_SAD);
        else unregister_code16(keycode);
        return false;
      case EMO_FLYSAFE:
        if (record->event.pressed) SEND_STRING(STR_EMO_FLYSAFE);
        else unregister_code16(keycode);
        return false;
    #endif // EMOTICON_ENABLE

    default:
      return true; // Process all other keycodes normally
  }
}
