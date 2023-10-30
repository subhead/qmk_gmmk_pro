// Copyright 2023 subhead (@subhead)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once


#define USB_POLLING_INTERVAL_MS 1

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

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U
#define SERIAL_USART_FULL_DUPLEX

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
	#define ENCODERS_PAD_A { GP6 }
	#define ENCODERS_PAD_B { GP7 }
#endif