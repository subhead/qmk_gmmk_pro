/* Copyright 2021 Jonavin Eng
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

#pragma once

// TT set to two taps
#define TAPPING_TOGGLE 3

#define ONESHOT_TAP_TOGGLE 5  /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 5000  /* Time (in ms) before the one shot key is released */

// Emoticon Support
#define EMOTICON_ENABLE

#ifdef LEADER_ENABLE
    #define LEADER_PER_KEY_TIMING
    #define LEADER_TIMEOUT 800
#endif

// RGB Matrix configuration
#ifdef RGB_MATRIX_ENABLE
    // RGB startup effect
    #define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_CYCLE_OUT_IN
        // number of milliseconds to wait until turning off RGB automatically
    #define RGB_DISABLE_TIMEOUT 300000 // 300 seconds / 5 min
    // start fading out before getting disabled
    // fading out is timed (depending on the rgb_matrix_config.speed) to have finished before reaching RGB_DISABLE_TIMEOUT
    #define RGB_DISABLE_WITH_FADE_OUT
    #define RGB_DISABLE_WHEN_USB_SUSPENDED
    // number of milliseconds to wait until activating RGB idle effects
    #define RGB_IDLE_TIMEOUT 4500 // 4.5 seconds
    // activate breathe effect when idle
    #define RGB_IDLE_BREATHE
    // fade in when we have been suspended
    #define RGB_FADE_IN
    // highlight WASD keys
    #define GAMING_MODE
    // highlight arrow keys
    #define ARROW_MODE
#endif

// IDLE timeouts configuration
#ifdef IDLE_TIMEOUT_ENABLE
    // default timeout minutes
    #define TIMEOUT_THRESHOLD_DEFAULT 15
    // upper limits (2 hours and 10 minutes -- no rgb indicators above this value)
    #define TIMEOUT_THRESHOLD_MAX 140
#endif

#ifdef CONSOLE_ENABLE
    #define CONSOLE_ENABLED
    #define DEBUG_ENABLE
#endif

