#include QMK_KEYBOARD_H

enum layer_number {
    _MAC = 0,
    _FN,
    _ADJ
};

enum custom_keycodes {
  MAC = SAFE_RANGE,
  FN,
  ADJ
};

//Milan Added
//Tap Dance Declarations
enum {
  BslsQt = 0,
  CtlCap,
  LbrPls,
  RbrMns
};
//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for (\), twice for (')
  [BslsQt] = ACTION_TAP_DANCE_DOUBLE(KC_BSLS, KC_QUOT),

  //Tap once for Control twice for Capslock
  [CtlCap] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_CAPS),

  //Tap once for [, twice for +
  [LbrPls] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_PPLS),

  // Tap once for ], twice for -
  [RbrMns] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_PMNS)
};

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
/* Mac
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |   1  |   2  |   3  |   4  |   5  |  -   |           |  =   |   6  |   7  |   8  |   9  |   0  |  Bksp  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  | [(+) |           | ](-) |   Y  |   U  |   I  |   O  |   P  |  \(')  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Caps   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |  Enter |
 * |--------+------+------+------+------+------|  *   |           |  /   |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  Up  | RShift |
 * `--------+------+------+---------------------------'           `---------------------------+------+------+--------'
 *   | Ctrl |  Alt |  Gui |                                                                   | Left | Down |Right |
 *   `--------------------'                                                                   `--------------------'
 *                                        ,-------------.       ,--------------.
 *                                        |      |      |       |      |       |  
 *                                      |Bksp/Adj|Bspc/FN|      |Space |  Del  |
 *                                        |      |      |       |      |       | 
 *                                        `-------------'       `--------------'
 */
    [_MAC] = LAYOUT(
	KC_ESC,  KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_MINS,       KC_EQL,    KC_6,   KC_7,   KC_8,   KC_9,   KC_0,    KC_BSPC,
	KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   TD(LbrPls),    TD(RbrMns),KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,    TD(BslsQt),
	TD(CtlCap),KC_A, KC_S,   KC_D,   KC_F,   KC_G,                             KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN, KC_ENT, 
	KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_PAST,       KC_SLSH,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_UP,   KC_RSFT,
	KC_LCTL, KC_LALT,KC_LGUI,                                                                        KC_LEFT,KC_DOWN, KC_RGHT,
                                   LT(ADJ, KC_BSPC), LT(FN, KC_BSPC),            KC_SPC, KC_DEL,
                                   LT(ADJ, KC_BSPC), LT(FN, KC_BSPC),            KC_SPC, KC_DEL
    ),

/* FN
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | RESET  |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | MAC    |      |      |      |      |      |      |           |      |      | PgDn |  Up  | PgUp | Print|  Home  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      | Left | Down | Right|Insert|  End   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Shift  |      |      |      |      |      |      |           |      | Play | Mute | Vol- | Vol+ | Last |  Next  |
 * `--------+------+------+---------------------------'           `---------------------------+------+------+--------'
 *   |      |      |GuiCtl|                                                                   |GuiCtl|      |      |
 *   `--------------------'                                                                   `--------------------'
 *                                        ,-------------.       ,--------------.
 *                                        |      |      |       |      |       |  
 *                                        |      |      |       |      |       | 
 *                                        |      |      |       |      |       | 
 *                                        `-------------'       `--------------'
 */
    [_FN] = LAYOUT(
  RESET,   XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  MAC,     XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, KC_PGDN, KC_UP,   KC_PGUP, KC_PSCR, KC_HOME,
  XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,                     XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_INS,  KC_END, 
  _______, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,   XXXXXXX, XXXXXXX, KC_MPLY, KC_MUTE, KC_VOLD, KC_VOLU, KC_MRWD, KC_MFFD,
  XXXXXXX, XXXXXXX,_______,                                                                             _______, XXXXXXX, XXXXXXX,
                                                XXXXXXX,   _______, XXXXXXX, XXXXXXX,
                                                XXXXXXX,   _______, XXXXXXX, XXXXXXX
    ),

/* ADJ
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Reset |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |Nlock |  =   |  /   |  *   |  -   |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  F6  |  F7  |  F8  |  F9  |  F10 |      |           |      |  7   |  8   |  9   |  +   |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |  F11 |  F12 |------|           |------|  4   |  5   |  6   | Enter|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |  1   |  2   |  3   | Space|      |        |
 * `--------+------+------+---------------------------'           `---------------------------+------+------+--------'
 *   |      |      |      |                                                                   |  0   |  .   |      |
 *   `--------------------'                                                                   `--------------------'
 *                                        ,-------------.       ,--------------.
 *                                        |      |      |       |      |       |  
 *                                        |      |      |       |      |       | 
 *                                        |      |      |       |      |       | 
 *                                        `-------------'       `--------------'
 */
    [_ADJ] = LAYOUT(
  RESET,   KC_F1,   KC_F2,  KC_F3,   KC_F4,   KC_F5,   XXXXXXX, KC_NLCK, KC_PEQL, KC_PSLS, KC_PAST, KC_PMNS, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_F6,   KC_F7,   KC_F8,  KC_F9,   KC_F10,  XXXXXXX, XXXXXXX, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, KC_F11,  KC_F12,                    KC_P4,   KC_P5,   KC_P6,   KC_PENT, XXXXXXX, XXXXXXX, 
  XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P1,   KC_P2,   KC_P3,   KC_SPC,  XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX,XXXXXXX,                                                                         KC_P0,   KC_PDOT, XXXXXXX,
                                              XXXXXXX, XXXXXXX, _______, XXXXXXX,
                                              XXXXXXX, XXXXXXX, _______, XXXXXXX
    )
};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   switch (keycode) {
    case MAC:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_MAC);
      }
      return false;
      break;
    case FN:
      if (record->event.pressed) {
        layer_on(_FN);
      } else {
        layer_off(_FN);
      }
      return false;
      break;
    case ADJ:
        if (record->event.pressed) {
          layer_on(_ADJ);
        } else {
          layer_off(_ADJ);
        }
        return false;
        break;
  }
  return true;
}

void led_set_user(uint8_t usb_led) {

}
