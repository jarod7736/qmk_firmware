#include "MiniVan20191107010537.h"
enum custom_keycodes {
M_IME = SAFE_RANGE
};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
if (record->event.pressed) {
switch(keycode) {
case M_IME:
SEND_STRING(SS_DOWN(X_LSHIFT)SS_DOWN(X_LALT));
return false;
}
}
else {
switch(keycode) {
case M_IME:
SEND_STRING(SS_UP(X_LSHIFT)SS_UP(X_LALT));
return false;
}
}
return true;
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = KEYMAP(KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, LT(1, KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, LT(1, KC_QUOT), KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, MO(2), KC_LCTL, MO(2), KC_LGUI, KC_NO, KC_ENT, KC_SPC, KC_RALT, KC_RSFT, KC_NO, TG(3)),
[1] = KEYMAP(KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, KC_TRNS, KC_BSLS, KC_QUOT, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_DOWN, KC_UP, KC_LEFT, KC_RIGHT, KC_TRNS, KC_TRNS, KC_ESC, BL_STEP, KC_PSCR, KC_TRNS, KC_TRNS, KC_TRNS, KC_MSTP, KC_MPLY, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, RESET),
[2] = KEYMAP(KC_TILD, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS, KC_ESC, KC_PIPE, KC_DQT, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_4, KC_5, KC_6, KC_VOLU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0, KC_1, KC_2, KC_3, KC_VOLD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS),
[3] = KEYMAP(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_TRNS, KC_ESC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F5, KC_F6, KC_F7, KC_F8, KC_TRNS, KC_LSFT, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_TRNS, KC_LALT, KC_B, KC_NO, KC_SPC, KC_C, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS),
};
void matrix_init_user(void) {
rgblight_init();
};
void rgblight_init_leds(void) {
process_indicator_update(layer_state, host_keyboard_leds());
};
void led_set_user(uint8_t usb_led) {
process_indicator_update(layer_state, usb_led);
};
uint32_t layer_state_set_user(uint32_t state) {
process_indicator_update(state, host_keyboard_leds());
return state;
};
void process_indicator_update(uint32_t state, uint8_t usb_led) {
LED_TYPE indicators[3] = {
{.r = 0, .g = 0, .b = 0},
{.r = 0, .g = 0, .b = 0},
{.r = 0, .g = 0, .b = 0}
};
uint8_t indexes[3] = {
0,
1,
2
};
indicators[0].r = 218;
indicators[0].g = 23;
indicators[0].b = 180;
if (state & (1<<3)){
indicators[0].r = 215;
indicators[0].g = 30;
indicators[0].b = 125;
}
if (state & (1<<3)){
indicators[1].r = 32;
indicators[1].g = 104;
indicators[1].b = 255;
}
if (state & (1<<3)){
indicators[2].r = 10;
indicators[2].g = 255;
indicators[2].b = 125;
}
rgblight_setrgb_many(indicators, indexes, 3);
};
