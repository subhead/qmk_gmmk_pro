# QMK Firmware for GMMK Pro ISO DE with custom key mapping and knob functions

This is a custom GMMK Pro configuration for the QMK firmware.

# Features
- VIA Support
- Rotary Knob Support
- Added INSERT to FN+PrntScrn
- Move RESET to FN+ESC
- CAPS Lock RGB indicator. Side LED and Caps Lock key are blinking red when enabled
- Highlight all mapped FN keys when FN is pressed
- Pressing FN+ALTGR+WIN disables the windows key and highlights the windows key red
- Enabling the Windows Keys also turns the gaming lighting mode on (WASD highlighted)
- Added GAMING_MODE_ENABLE to config.h for enabling/disabling gaming mode
- Highlight all LED red when entering the flashing mode (FN+ESC)

# TODO
- Add toggle for game mode for on the fly enabling/disabling
- Add NumPad
- Add NumPadLock
- move mediakey to another fn+ combo
- add macro recorder
- cleanup code/move code to userspace
- own startup rgb effect
- fix led mapping



# Available Keycodes
| Keycode		| Function			|
| ------------- | -----------------:|
| FN+F1			| My Computer		|
| FN+F2			| Something			|
| FN+F3			| Calculator		|
| FN+F4			| Media Player		|
| FN+F5			| 					|
| FN+F6			| 					|
| FN+F7			| 					|
| FN+F8			| 					|
| FN+F9			| Prv Track			|
| FN+F10		| Next Track		|
| FN+F11		| Play/Stop			|
| FN+F12		| Insert			|
| FN+PrntScrn	| Toggle RGB on/off	|
| FN+Q			| Something			|
| FN+S			| Something			|
| FN+X			| Something			|
| FN+V			| Something			|
| FN+#			| Something			|
| FN+ESC		| Reset/Bootloader	|
| FN+1			| Something			|
| FN+2			| Something			|
| FN+UP			| Something			|
| FN+DOWN		| Something			|
| FN+LEFT		| Something			|
| FN+RIGHT		| Something			|

| Keycode		| Function			|
| ------------- | -----------------:|
| FN+ALT+WIN	| Something			|
| FN+ALT+F		| Something			|
| FN+ALT+F		| Something			|
| FN+ALT+G		| Something			|
| FN+ALT+PGUP	| Something			|
| FN+ALT+ESC	| Reset/Bootloader	|

| Keycode			| Function						|
| -----------------	| -----------------------------:|
| FN+ALT+STRG+1		| Something						|
| FN+ALT+STRG+R		| Something						|
| FN+ALT+STRG+F		| Something						|
| FN+ALT+STRG+PGUP	| Something						|
| FN+ALT+STRG+ESC	| Reset/Bootloader				|

##### H5 Leader Key (FN+LSHIFT+KEYSEQUENCE) Macros
| Keycode			| Function						|
| -----------------	| -----------------------------:|
| FN+SHIFT+br		| Browser open last closed tab	|
| FN+SHIFT+7		| Type double slashes			|
| FN+SHIFT+8		| Type double parenthesis		|