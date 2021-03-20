/* Copyright Doctopus: github.com/doctopus */
#include QMK_KEYBOARD_H
extern keymap_config_t keymap_config;

//Tap Dance Declarations
enum {
  TEsc = 0,
  MinPls,
  ColQt,
  BRC
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Tab, twice for Escape
  [TEsc] = ACTION_TAP_DANCE_DOUBLE(KC_TAB, KC_ESC),

  //Tap once for (-_), twice for +
  [MinPls] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_PLUS),

  //Tap once for ;, twice for "
  [ColQt] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_QUOT),

  //Tap once for [, twice for ]
  [BRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC)

};

#define QWERTY M(0)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* ========================================================================================
// 0: Qwerty Layer

   * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────────┐
   * │TabEsc│  Q   │  W   │  E   │  R   │  T   │  Y   │  U   │  I   │  O   │  P   │ BackSpace│  
   * ├──────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────────┤
   * │Tab(L1)│  A   │  S   │  D   │  F   │  G   │  H   │  J   │  K   │  L   │ ; "  │Enter(L2)│
   * ├───────┴──┬───┴──┬───┴──┬───┴──┬───┴──┬───┴──┬───┴──┬───┴──┬───┴──┬───┴──┬───┴──┬──────┤
   * │ LSHFT    │  Z   │  X   │  C   │  V   │  B   │  N   │  M   │  ,   │  .   │  Up  │Slash │
   * ├─────────┬┴──────┴┬─────┴─┬────┴──────┴──┬───┴──────┴────┬─┴──────│──────│──────│──────┤
   * │ LCTRL   │  LALT  │Cmd/Del│   BackSpace  │     Space     │  MO(3) │ Left │ Down │Right │
   * └─────────┴────────┴───────┴──────────────┴───────────────┴────────┴──────┴──────┴──────┘
   */
	// [0] = KEYMAP( /* Qwerty */
  [0] = LAYOUT_arrow( /* Qwerty */
    TD(TEsc),     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    LT(1,KC_TAB),KC_A,   KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    TD(ColQt), LT(2, KC_ENT),
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_SLSH,
    KC_LCTL,    KC_LALT, CMD_T(KC_DEL),       LT(2, KC_BSPC),  KC_SPC,          TT(3),   KC_LEFT, KC_DOWN, KC_RGHT
  ),


/* ========================================================================================
// L1: Layer 1

   * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────────┐
   * │  Esc │  1   │  2   │  3   │  4   │  5   │  6   │  7   │  8   │  9   │  0   │Backspace │  
   * ├──────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────────┤
   * │       │      │      │      │  =   │  *   │  =+  │  4   │  5   │  6   │  .   │Enter(L2)│
   * ├───────┴──┬───┴──┬───┴──┬───┴──┬───┴──┬───┴──┬───┴──┬───┴──┬───┴──┬───┴──┬───┴──┬──────┤
   * │          │      │      │      │  =   │  /   │  -_  │  1   │  2   │  3   │  Up  │ -_ + │
   * ├─────────┬┴──────┴┬─────┴─┬────┴──────┴──┬───┴──────┴────┬─┴──────│──────│──────│──────┤
   * │         │        │       │   BackSpace  │     Space     │        │ Left │ Down │Right │
   * └─────────┴────────┴───────┴──────────────┴───────────────┴────────┴──────┴──────┴──────┘
   */
	// [1] = KEYMAP( /* LAYER 1 */
  [1] = LAYOUT_arrow( /* LAYER 1 */
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, _______, _______, _______, KC_EQL,  KC_ASTR, KC_EQL,    KC_4,    KC_5,    KC_6,    TD(BRC),  KC_ENT,
    _______, _______, _______, _______,  KC_EQL,   KC_SLSH,  KC_MINS, KC_1,    KC_2,    KC_3,    KC_UP,TD(MinPls),
    _______, _______, _______,               _______,  _______,                 _______, KC_LEFT, KC_DOWN, KC_RGHT
  ),


  /* ========================================================================================
  // L2: Layer 2

   * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────────┐
   * │ `Esc │  !   │  @   │  #   │  $   │  %   │  ^   │  &   │  *   │  (   │  )   │  Delete  │  
   * ├──────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────────┤
   * │ Mo(1) │  \   │  '   │  -   │  =   │      │      │      │      │   [  │   ]  │Enter(L2)│
   * ├───────┴──┬───┴──┬───┴──┬───┴──┬───┴──┬───┴──┬───┴──┬───┴──┬───┴──┬───┴──┬───┴──┬──────┤
   * │          │      │      │      │      │      │      │      │      │      │  Up  │Slash │
   * ├─────────┬┴──────┴┬─────┴─┬────┴──────┴──┬───┴──────┴────┬─┴──────│──────│──────│──────┤
   * │         │        │       │   BackSpace  │     Space     │ MO(L3) │ Left │ Down │Right │
   * └─────────┴────────┴───────┴──────────────┴───────────────┴────────┴──────┴──────┴──────┘
   */
	// [2] = KEYMAP( /* LAYER 2 */
  [2] = LAYOUT_arrow( /* LAYER 2 */
    KC_TAB,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
    _______, KC_BSLS, KC_QUOT, KC_MINS, KC_EQL,  _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______,                   KC_BSPC,  KC_SPC,          _______, _______, _______, _______
  ),


  /* ========================================================================================
  // L3: Layer 3

   * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────────┐
   * │Reset │QWERTY│      │      │      │      │      │  7   │  8   │  9   │  0   │   Delete │  
   * ├──────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────────┤
   * │       │   "  │   |  │  _   │  +   │      │      │  4   │  5   │  6   │   ;  │Enter(L2)│
   * ├───────┴──┬───┴──┬───┴──┬───┴──┬───┴──┬───┴──┬───┴──┬───┴──┬───┴──┬───┴──┬───┴──┬──────┤
   * │          │      │      │      │      │      │  0   │  1   │  2   │  3   │  Up  │Slash │
   * ├─────────┬┴──────┴┬─────┴─┬────┴──────┴──┬───┴──────┴────┬─┴──────│──────│──────│──────┤
   * │ LCTRL   │ Tog(L1)│  LALT │   BackSpace  │     Space     │  MO(3) │ Left │ Down │Right │
   * └─────────┴────────┴───────┴──────────────┴───────────────┴────────┴──────┴──────┴──────┘
   */
	// [3] = KEYMAP( /* LAYER 3 */
  [3] = LAYOUT_arrow( /* LAYER 3 */
    RESET,   QWERTY,  _______, _______, _______, _______, _______, KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
    _______, KC_SCLN, KC_QUOT, KC_UNDS, KC_PLUS, _______, _______, KC_4,    KC_5,  KC_6,  KC_DOT, _______,
    _______, _______, _______, _______, _______, _______, KC_0,    KC_1,    KC_2,    KC_3,   _______, _______,
    _______, _______, _______,                   _______, _______,         _______, _______, _______, _______
  )
};


//RGB Codes
// void matrix_init_user(void) {
// 	rgblight_setrgb(0x00, 0xFF, 0x00); //Green
// }
//May remove the above two lines of code, does not affect anyway.*/

uint32_t layer_state_set_user(uint32_t state) {
#ifdef RGBLIGHT_ENABLE

    switch (biton32(state)) {
    case 1:
        rgblight_setrgb(0x80, 0xFF, 0x00); //Chartreuse https://github.com/qmk/qmk_firmware/blob/master/quantum/rgblight_list.h
        break;
    case 2:
        rgblight_setrgb(0x00, 0xFF, 0x80); //Spring green
        break;
    case 3:
        rgblight_setrgb(0x7A, 0x00, 0xFF); //Purple
        break;
    default: //  for any other layers, or the default layer
        rgblight_setrgb (0x00,  0x00, 0x00); //Black
        break;
    }
#endif    
    return state;
}