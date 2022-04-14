# MCU name
MCU = STM32F303

# Bootloader selection
BOOTLOADER = stm32-dfu

LTO_ENABLE = yes			# link time optimization -- achieves a smaller compiled size
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
ENCODER_ENABLE = yes
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = AW20216
IDLE_TIMEOUT_ENABLE = yes
VIA_ENABLE = no
TAP_DANCE_ENABLE = no
