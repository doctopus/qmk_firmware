/* Copyright 2018 Carlos Filoteo
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#define LT3_TAB LT(3, KC_TAB)

//Tap Dance Declarations
enum {
  TabEsc = 0,
  ColQt,
  CtlTsk
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Tab, twice for Esc
  [TabEsc] = ACTION_TAP_DANCE_DOUBLE(KC_TAB, KC_ESC),

  //Tap once for Backspace, twice for "
  [ColQt] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_QUOT),

  //Tap once for Ctrl, twice for Ctl+Alt+Del
  [CtlTsk] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, LALT(LCTL(KC_DEL)))
  };


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*===========================================================================================*/
  /* Base Layer
   * ,-------------------------------------------------------------------------.
   * |TabEsc|  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |Bspace|
   * |-------------------------------------------------------------------------+
   * |Tab/L3|  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;' | Enter|
   * |-------------------------------------------------------------------------+
   * | Shift |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  Up  |  / |
   * |-------------------------------------------------------------------------+
   * | CtlTsk| Ctrl | Alt | GUI |  L2  |   Space   |  L1  | L3| Left|Down|Right|
   * `-------------------------------------------------------------------------'
   */

LAYOUT(
  TD(TabEsc),KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_BSPC,
  LT3_TAB,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,  TD(ColQt), KC_ENT,
  KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,  KC_SLSH,
  TD(CtlTsk),KC_LCTL, KC_LALT, KC_LGUI,  LT(2,KC_BSPC),  KC_SPC,    LT(1,KC_DEL),  MO(3),   KC_LEFT, KC_DOWN, KC_RGHT
),

/*===========================================================================================*/
  /* Layer 1 Numbers
   * ,-------------------------------------------------------------------------.
   * | ` ~ |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  | Backsp|
   * |-------------------------------------------------------------------------+
   * |   -  |  =  |  [  |  ]  |  \  |     |     |  4  |  5  |  6  |  ;' |   =  |
   * |-------------------------------------------------------------------------+
   * |       |     |     |     |     |     |     |  1  |  2  |  3  | Up  |  /  |
   * |-------------------------------------------------------------------------+
   * |     |      |     |    |L2/Bsp|          | L1/Del| L3  | Left| Down|Right|
   * `-------------------------------------------------------------------------'
   */

LAYOUT( /* Right */
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,   KC_8,  KC_9,  KC_0,    _______,
  KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,  KC_ASTR,  KC_PLUS, KC_4,   KC_5,   KC_6, _______, KC_EQL,
  _______,  _______, _______, _______, _______, KC_SLSH,  KC_MINS,  KC_1,    KC_2,   KC_3, _______, _______,
  _______, _______,  _______, _______,  _______,   _______,      _______, _______,  _______, _______, _______
),

/*===========================================================================================*/
  /* Layer 2 Symbols
   * ,-------------------------------------------------------------------------.
   * |   ~  |  !  |  @  |  #  |  $  |  %  |  ^  |  &  |  *  |  (  |  )  |Delete|
   * |-------------------------------------------------------------------------+
   * |      |     |     |     |     |     |     |  _  |  +  |  { |  }  |   |   |
   * |-------------------------------------------------------------------------+
   * |       | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | PgUp|     |
   * |-------------------------------------------------------------------------+
   * |     |     |     |Capsl|      |          |       |     | Home| PgDn| End |
   * `-------------------------------------------------------------------------'
   */

LAYOUT( /* Left */
  RESET,  KC_EXCLAIM,  KC_AT,  KC_HASH,  KC_DOLLAR, KC_PERCENT, KC_CIRCUMFLEX, KC_AMPERSAND, KC_ASTERISK, KC_LEFT_PAREN, KC_RIGHT_PAREN, KC_DELETE,
  _______, _______, _______, _______, _______, _______, _______, KC_UNDERSCORE, KC_PLUS, KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE, KC_PIPE,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_PGUP,  _______,
  _______, _______, _______, KC_CAPS, _______,     _______,      _______, _______, KC_HOME, KC_PGDN, KC_END
),

/*===========================================================================================*/
  /* FN Layer 3
   * ,-------------------------------------------------------------------------.
   * |RESET| RGB |Mode+|Mode-|Static|Breth|Rnbow|Swirl|Knight|Xmas |SttGrd|RGBt|
   * |-------------------------------------------------------------------------+
   * |      | Hue+| Hue-| Sat+| Sat-|    |      |     |     |     |     |      |
   * |-------------------------------------------------------------------------+
   * |       |Brit+|Brit-|     |     |     |     |     |     |L-Clk|MousU|R-Clk|
   * |-------------------------------------------------------------------------+
   * |     |     |     |     |      |          |       |     |MousL|MousD|MousR|
   * `-------------------------------------------------------------------------'
   */

LAYOUT( /* Tab */
  RESET,  RGB_TOG, RGB_MOD, RGB_RMOD, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T,
  _______, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, _______, _______, _______, _______, _______, _______, _______,
  _______, RGB_VAD, RGB_VAI, _______, _______, _______, _______, _______, _______, KC_BTN1, KC_MS_U, KC_BTN2,
  _______, _______, _______, _______, _______,     _______,      _______, _______, KC_MS_L, KC_MS_D, KC_MS_R
),
};
