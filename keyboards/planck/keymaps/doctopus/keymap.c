/* Copyright 2015-2020 Doctopus
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
 * You should have received a controlsopy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.

 //Inherited from chormanski keymap
 */

#include QMK_KEYBOARD_H
#include "muse.h"

enum planck_layers {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _LOWER,
  _RAISE,
  _NUMPAD,
  _FUNCT,
  _PLOVER,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  NUMPAD,
  FUNCT,
  PLOVER,
  EXT_PLV
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

//Tap Dance Declarations
enum {
  TEsc = 0,
  BkEq,
  BRC,
  ColQt,
  TabEsc,
  CtlTsk
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Tilde, twice for Escape
  [TEsc] = ACTION_TAP_DANCE_DOUBLE(KC_GRV, KC_ESC),

  //Tap once for Backspace twice for Equal
  [BkEq] = ACTION_TAP_DANCE_DOUBLE(KC_BSPC, KC_EQL),

  //Tap once for [, twice for ]
  [BRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),

  //Tap once for Backspace, twice for "
  [ColQt] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_QUOT),

  //Tap once for Tab, twice for Esc
  [TabEsc] = ACTION_TAP_DANCE_DOUBLE(KC_TAB, KC_ESC),

  //Tap once for Ctrl, twice for Ctl+Alt+Del
  [CtlTsk] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, LALT(LCTL(KC_DEL))),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*===========================================================================================*/
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |TabEsc|   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |  ;'  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Numpad|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |CtlTsk|  Alt | Cmd  |CmdDel|Low-Bk| Space|Space |Hi-Del| Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
/* Base layer (Qwerty) Work in Progress...
 *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 *                 │⇥ Esc│  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  ←  │
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 *  Tap for Esc -- │⌃ Sym│  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;' │  ⌃  │ -- Tap for Enter
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 *    Tap for ( -- │  ⇧  │  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │  ⇧  │ -- Tap for )
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 *    Tap for [ -- │ GUI │Hyper│  ⌥  │  ⌘  │  ↓  │Space│ Nav │  ↑  │  ⌘  │  ⌥  │Hyper│ GUI │ -- Tap for ]
 *                 └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
 *                         /         Tap for Backspace __/                       /
 *    Tap for ] [ --------'-----------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid( \
	TD(TabEsc),KC_Q,		KC_W,		KC_E,		KC_R,		 KC_T,	  KC_Y,	 KC_U,	KC_I,		 KC_O,		KC_P,		  KC_BSPC,   \
	KC_TAB,	   KC_A,		KC_S,		KC_D,		KC_F,		 KC_G,	  KC_H,	 KC_J,	KC_K,		 KC_L,		TD(ColQt),KC_ENT, \
	KC_LSFT,	 KC_Z,		KC_X,		KC_C,		KC_V,		 KC_B,	  KC_N,	 KC_M,	KC_COMM, KC_DOT,	KC_SLSH,	TG(_NUMPAD), \
	TD(CtlTsk),KC_LALT, KC_LGUI,LGUI_T(KC_DEL), LT(LOWER,KC_BSPC),KC_SPC,KC_SPC,LT(RAISE,KC_DEL),	KC_LEFT,	KC_DOWN,	KC_UP,		KC_RGHT  \
),

/*===========================================================================================*/
/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |TabEsc|   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  |Bksp "|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Numpad|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |Alt   | GUI  | GUI  |Low-Bk| Space|Space |Hi-Del| Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
/* Base layer (Colemak) Work in progress...
 *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 *                 │     │  Q  │  W  │  F  │  P  │  G  │  J  │  L  │  U  │  Y  │  ;  │     │
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 *                 │     │  A  │  R  │  S  │  T  │  D  │  H  │  N  │  E  │  I  │  O  │     │
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 *                 │     │  Z  │  X  │  C  │  V  │  B  │  K  │  M  │  ,  │  .  │  /  │     │
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 *                 │     │     │     │     │     │     │     │     │     │     │     │     │
 *                 └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
 */
[_COLEMAK] = LAYOUT_planck_grid( \
	TD(TEsc),	KC_Q,		KC_W,		KC_F,		KC_P,		KC_G,	KC_J,	KC_L,	KC_U,		KC_Y,		KC_SCLN,	TD(BkEq), \
	KC_TAB,		KC_A,		KC_R,		KC_S,		KC_T,		KC_D,	KC_H,	KC_N,	KC_E,		KC_I,		KC_O,		KC_ENT,   \
	KC_LSFT,	KC_Z,		KC_X,		KC_C,		KC_V,		KC_B,	KC_K,	KC_M,	KC_COMM,	KC_DOT,		KC_SLSH,	TG(_NUMPAD), \
	_______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______ \
),

/*===========================================================================================*/
/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_planck_grid(
    KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
    KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH,
    KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT ,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),

/*===========================================================================================*/
/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | Bksp   Bksp |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
/* Directional navigation layer
 *
 *          Large movements -----/```````````````````\   /```````````````````\----- Vim-style arrow keys
 *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 *                 │     │     │     │     │     │     │     │     │     │     │     │     │
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 *                 │     │     │Home │PgUp │PgDn │ End │  ←  │  ↓  │  ↑  │  →  │     │     │
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 *                 │     │     │ ⌘ ← │ ⌘ ↑ │ ⌘ ↓ │ ⌘ → │ ⌥ ← │ ⌥ ↓ │ ⌥ ↑ │ ⌥ → │     │     │
 *                 ├─────┼─────┼─────┼─────┼─────┼─────╆━━━━━╅─────┼─────┼─────┼─────┼─────┤
 *                 │     │     │     │     │     │Lead ┃     ┃     │     │     │     │     │
 *                 └─────┴─────┴─────┴─────┴─────┴─────┺━━━━━┹─────┴─────┴─────┴─────┴─────┘
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______,
    _______, _______, _______, _______, _______, KC_BSPC, KC_BSPC, _______,    _______,    _______, _______, _______
),

/*===========================================================================================*/
/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |  Del    Del |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
/* Numeric layer Work on progress...
 *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 *  Application -- │ ⌘-` │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │ F7  │ F8  │ F9  │ F10 │  #  │
 *       window    ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 *     switcher    │     │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │     │
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 *                 │     │  -  │  =  │  `  │  \  │  :  │ndash│mdash│  ,  │  .  │  /  │     │
 *                 ├─────┼─────┼─────┼─────╆━━━━━╅─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 *                 │     │     │     │     ┃     ┃     │     │     │     │     │     │     │
 *                 └─────┴─────┴─────┴─────┺━━━━━┹─────┴─────┴─────┴─────┴─────┴─────┴─────┘
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
    _______, _______, _______, _______, _______, KC_DEL,  KC_DEL,  _______, _______, _______, _______, _______
),

/*===========================================================================================*/
/* Numpad & Mouse
 * ,-----------------------------------------------------------------------------------.
 * |      |L-clck|  Up  |R-clck|Scrl U|      |   =  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Left | Down | Right|Scrl D|      |   *  |   4  |   5  |   6  |   +  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |   /  |   1  |   2  |   3  |   -  | Back |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
/* GUI (window management/mouse/media controls) layer. Work in progress...
 *
 *         Mouse keys -----/```````````````````\               /```````````````````\----- Window manager
 *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 *                 │     │Ms B2│Ms Up│Ms B1│Ms WD│     │     │Prev │ NW  │  N  │ NE  │     │
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 *                 │     │Ms L │Ms Dn│Ms R │Ms WU│     │     │Full │  W  │Centr│  E  │     │
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 *                 │     │Undo │ Cut │Copy │Paste│     │     │Next │ SW  │  S  │ SE  │     │
 *                 ┢━━━━━╅─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────╆━━━━━┪
 *                 ┃     ┃Prev │Play │Next │Brig-│Sleep│Wake │Brig+│Mute │Vol- │Vol+ ┃     ┃
 *                 ┗━━━━━┹─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┺━━━━━┛
 *                         \___ Media ___/   \___ Screen/sleep __/   \___ Volume __/
 */
[_NUMPAD] = LAYOUT_planck_grid( \
  _______,  KC_BTN1,  KC_MS_U,  KC_BTN2,  KC_WH_U,  _______,  KC_EQL, KC_7,   KC_8,   KC_9,  KC_0,    KC_BSPC, \
  _______,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_WH_D,  _______,  KC_ASTR,  KC_4,   KC_5,   KC_6,  KC_PLUS, KC_ENT, \
  _______,  _______,  _______,  _______,  _______,  _______,  KC_SLSH,    KC_1,   KC_2,   KC_3,  KC_MINS, _______, \
  _______,  _______,  _______,  _______,  LT(LOWER,KC_BSPC),KC_SPC,KC_SPC,LT(RAISE,KC_DEL),  _______,_______,_______,_______ \
),

/*===========================================================================================*/
/* Function
 * ,-----------------------------------------------------------------------------------.
 * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   |  |  +   |  <   |  >   |  #   |   ~  |   (  |   )  |   \  |   :  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   !  |  -   |  =   |  %   |  @   |   _  |   {  |   }  |   /  |   ?  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
/* Function layer Work in progress...
 *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 *                 │     │ F11 │ F12 │ F13 │ F14 │ F15 │ F16 │ F17 │ F18 │ F19 │ F20 │  #  │
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 *                 │     │  !  │  @  │  #  │  $  │  %  │  ^  │  &  │  *  │  {  │  }  │     │ \
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤  |-- Mostly shifted version
 *                 │     │  _  │  +  │  ~  │  |  │  :  │ndash│mdash│  ,  │  .  │  /  │     │ /    of lower layer
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────╆━━━━━╅─────┼─────┼─────┼─────┤
 *                 │     │     │     │     │     │  Delete   ┃     ┃     │     │     │     │
 *                 └─────┴─────┴─────┴─────┴─────┴─────┴─────┺━━━━━┹─────┴─────┴─────┴─────┘
 */
[_FUNCT] = LAYOUT_planck_grid( \
  KC_F11,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F12,  \
  _______,  KC_PIPE,  KC_PLUS,    KC_LABK,    KC_RABK,  KC_HASH,  KC_TILD,  KC_LPRN,  KC_RPRN,  KC_BSLS,  KC_COLN,  _______, \
  _______,  KC_EXLM,  KC_MINS,    KC_EQL,     KC_PERC,  KC_AT,    KC_UNDS,  KC_LCBR,  KC_RCBR,  KC_SLSH,  KC_QUES,  _______, \
  _______,  _______,  _______,  _______,  LT(LOWER,KC_BSPC),KC_SPC,KC_SPC,LT(RAISE,KC_DEL),  _______,  _______,  _______,  _______  \
),
/*===========================================================================================*/

/*===========================================================================================*/
/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_PLOVER] = LAYOUT_planck_grid(
    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   ,
    XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX
),



/*===========================================================================================*/
/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * | Reset|      |      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Functn|Plover|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
/* Keyboard settings layer Work in progress...
 *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 *     Firmware -- │     │Reset│Make │     │     │     │     │     │     │     │Vers │     │
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 *          RGB -- │Qwert│     │     │Mode-│Mode+│Hue -│Hue +│Sat -│Sat +│     │Play1│Rec 1│ -- Record/play macro 1
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 *        Audio -- │Colem│Voic-│Voic+│Mus +│Mus -│MIDI+│MIDI-│Aud +│Aud -│     │Play2│Rec 2│ -- Record/play macro 2
 *                 ├─────┼─────┼─────┼─────╆━━━━━╅─────┼─────╆━━━━━╅─────┼─────┼─────┼─────┤
 *                 │Steno│     │Swap │Norm ┃     ┃  Toggle   ┃     ┃Toggl│Brig-│Brig+│Stop │ -- Stop recording macro
 *                 └─────┴─────┴─────┴─────┺━━━━━┹─────┴─────┺━━━━━┹─────┴─────┴─────┴─────┘
 *                Swap GUI/Alt _/________/             \_____________\_ Backlight _/
 */
[_ADJUST] = LAYOUT_planck_grid(
    RESET  , _______, DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL,
    _______, MU_TOG,  MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK,  DVORAK,  FUNCT,  PLOVER,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)
/*===========================================================================================*/
};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
	case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
  case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
  case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
	case FUNCT:
			if (record->event.pressed) {
				set_single_persistent_default_layer(_FUNCT);
			}
			return false;
			break;
  case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
  case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);
      }
      return false;
      break;    
	}
	return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        register_code(KC_MS_WH_DOWN);
        unregister_code(KC_MS_WH_DOWN);
      #else
        register_code(KC_PGDN);
        unregister_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        register_code(KC_MS_WH_UP);
        unregister_code(KC_MS_WH_UP);
      #else
        register_code(KC_PGUP);
        unregister_code(KC_PGUP);
      #endif
    }
  }
}


void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}