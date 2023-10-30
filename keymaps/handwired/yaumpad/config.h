// Copyright 2023 subhead (@subhead)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID 0xFEED
#define PRODUCT_ID 0x0000
#define DEVICE_VER 0x0001
#define MANUFACTURER subhead
#define PRODUCT yaumpad
#define DESCRIPTION A custom yet another useless macropad
#define MATRIX_ROWS 4
#define MATRIX_COLS 4
#define MATRIX_ROW_PINS { GP4, GP5, GP8, GP9 }
#define MATRIX_COL_PINS { GP10, GP19, GP20, GP18 }

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT


#ifdef CONSOLE_ENABLE
    #define CONSOLE_ENABLED
    #define DEBUG_ENABLE
#endif


// IDLE timeouts configuration
#ifdef IDLE_TIMEOUT_ENABLE
    // default timeout minutes
    #define TIMEOUT_THRESHOLD_DEFAULT 15
    // upper limits (2 hours and 10 minutes -- no rgb indicators above this value)
    #define TIMEOUT_THRESHOLD_MAX 140
#endif


#ifdef LEADER_ENABLE
    #define LEADER_PER_KEY_TIMING
    #define LEADER_TIMEOUT 800
#endif

// tapping toggle set to two taps
#define TAPPING_TOGGLE 3
// Tapping this number of times holds the key until tapped once again.
#define ONESHOT_TAP_TOGGLE 5
// Time (in ms) before the one shot key is released
#define ONESHOT_TIMEOUT 5000

// Emoticon Support
#define EMOTICON_ENABLE

#ifdef ENCODER_ENABLE
	#define ENCODERS_PAD_A { D7 }
	#define ENCODERS_PAD_B { E6 }
#endif