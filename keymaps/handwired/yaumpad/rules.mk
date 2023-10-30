# This file intentionally left blank
# MCU name
MCU = RP2040

# Bootloader selection
BOOTLOADER = rp2040
LTO_ENABLE = yes			# link time optimization -- achieves a smaller compiled size
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no       	# Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = yes        # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
ENCODER_ENABLE = yes
RGB_MATRIX_ENABLE = no
IDLE_TIMEOUT_ENABLE = yes
VIA_ENABLE = yes
TAP_DANCE_ENABLE = no
LEADER_ENABLE = yes
UNICODE_ENABLE = yes
#UNICODEMAP_ENABLE = yes
