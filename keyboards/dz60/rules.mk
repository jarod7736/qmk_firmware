# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes	# Virtual DIP switch configuration
MOUSEKEY_ENABLE = yes	# Mouse keys
EXTRAKEY_ENABLE = yes	# Audio control and System control
CONSOLE_ENABLE = no	# Console for debug
COMMAND_ENABLE = no    # Commands for debug and configuration
SLEEP_LED_ENABLE = no  # Breathing sleep LED during USB suspend
NKRO_ENABLE = yes		# USB Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BACKLIGHT_ENABLE = yes  # Enable keyboard backlight functionality
AUDIO_ENABLE = no
RGBLIGHT_ENABLE = yes
TAP_DANCE_ENABLE = yes # Enable tap dance behaviors

LAYOUTS = 60_ansi 60_ansi_arrow 60_ansi_split_bs_rshift 60_hhkb 60_iso 60_abnt2 60_tsangan_hhkb
