#pragma once

#undef PRODUCT_ID
#define PRODUCT_ID      0x8847

#undef DEVICE_VER
#define DEVICE_VER      0x0001

#undef MANUFACTURER
#define MANUFACTURER    TheVan Keyboards

#undef PRODUCT
#define PRODUCT         MiniVan

#undef DESCRIPTION
#define DESCRIPTION     Hotswap MiniVan 40%

#define BACKLIGHT_LEVELS  1
#define BACKLIGHT_PIN B7
#define USB_MAX_POWER_CONSUMPTION 100
#define DEBOUNCING_DELAY  5
#define TAPPING_TERM      175
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)
#define RGB_DI_PIN D0
#define RGBLED_NUM 3
#define RGBLIGHT_CUSTOM_LED_INIT
#define RGBLIGHT_SLEEP

#define TAPPING_TOGGLE 1
