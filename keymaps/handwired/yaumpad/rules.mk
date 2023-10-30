MCU = RP2040
BOOTLOADER = rp2040
LTO_ENABLE = no			# link time optimization -- achieves a smaller compiled size
IDLE_TIMEOUT_ENABLE = yes
VIA_ENABLE = yes			# via support
TAP_DANCE_ENABLE = no		# tab dance
LEADER_ENABLE = yes			# leader key support
UNICODE_ENABLE = yes		# unicode support
#UNICODEMAP_ENABLE = yes
CONSOLE_ENABLE = yes
COMMAND_ENABLE = yes
# PIO serial/WS2812 drivers must be used on RP2040
SERIAL_DRIVER = vendor
WS2812_DRIVER = vendor

# Audio currently doesn't work with the RP2040
AUDIO_ENABLE = no