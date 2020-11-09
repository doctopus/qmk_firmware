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
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.

 //Inherited from chormanski keymap
 */

#include QMK_KEYBOARD_H

enum planck_layers {
  _QWERTY,
  _COLEMAK,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NUMPAD,
  _FUNCT,
  _SYMB,
  _MUSIC
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  FUNCT
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
 * |Symbol|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |  ;'  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Numpad|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Ctrl | Alt  |Comand|Low-Bk| Space|Space |Hi-Del| Left | Down |  Up  |Right |
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
	TD(TabEsc),	KC_Q,		KC_W,		KC_E,		KC_R,		 KC_T,	  KC_Y,	 KC_U,	KC_I,		 KC_O,		KC_P,		  KC_BSPC,   \
	OSL(_SYMB),	KC_A,		KC_S,		KC_D,		KC_F,		 KC_G,	  KC_H,	 KC_J,	KC_K,		 KC_L,		TD(ColQt),KC_ENT, \
	KC_LSFT,	  KC_Z,		KC_X,		KC_C,		KC_V,		 KC_B,	  KC_N,	 KC_M,	KC_COMM, KC_DOT,	KC_SLSH,	TG(_NUMPAD), \
	TD(CtlTsk), KC_LCTL,KC_LALT,KC_LGUI,LT(LOWER,KC_BSPC),KC_SPC,KC_SPC,LT(RAISE,KC_DEL),	KC_LEFT,	KC_DOWN,	KC_UP,		KC_RGHT  \
),
/*===========================================================================================*/
/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |TabEsc|   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  |Bksp "|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Numpad|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |Symbol| Alt  | Bksp |Low-Bk| Space|Space |Hi-Del| Left | Down |  Up  |Right |
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
	KC_ESC,		KC_A,		KC_R,		KC_S,		KC_T,		KC_D,	KC_H,	KC_N,	KC_E,		KC_I,		KC_O,		KC_ENT,   \
	KC_LSFT,	KC_Z,		KC_X,		KC_C,		KC_V,		KC_B,	KC_K,	KC_M,	KC_COMM,	KC_DOT,		KC_SLSH,	TG(_NUMPAD), \
	KC_LCTL, OSL(_SYMB),	KC_LALT,	KC_BSPC,	LT(LOWER, KC_BSPC),	KC_SPC,	KC_SPC,	LT(RAISE, KC_DEL),	KC_LEFT,	KC_DOWN,	KC_UP,		KC_RGHT \
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
 * |      |      |      |      |      | Bksp   Bksp |      | Next | Vol- | Vol+ | Play |
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
    _______, _______, _______, _______, _______, KC_BSPC, KC_BSPC, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY
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
 * |      |      |      |      |      |  Del    Del |      | Next | Vol- | Vol+ | Play |
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
    _______, _______, _______, _______, _______, KC_DEL,  KC_DEL, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),


/*===========================================================================================*/
/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * | Reset|      |      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|      |      |      |
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
    RESET  , _______,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK,  _______, _______, _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),

/*===========================================================================================*/
/* Numpad & Mouse
 * ,-----------------------------------------------------------------------------------.
 * |M-Clic| ACL0 |L-clck|  Up  |R-clck|Scrl U|   *  |   +  |   7  |   8  |   9  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | ACL1 | Left | Down |Right |Scrl D|   /  |   -  |   4  |   5  |   6  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |NumLk | ACL2 | VOLU | PREV |PAUSE | NEXT |   =  |   =  |   1  |   2  |   3  | Back |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Symbol| VOLD | MUTE | Bksp |      |      | Del  |   0  |   0  |   .  |      |
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
	KC_BTN3,	KC_ACL0,	KC_BTN1,	KC_MS_U,	KC_BTN2,	KC_WH_U,	KC_ASTR,	KC_PLUS,	KC_7,		KC_8,		KC_9,		KC_BSPC, \
	_______,	KC_ACL1,	KC_MS_L,	KC_MS_D,	KC_MS_R,	KC_WH_D,	KC_SLSH,	KC_MINS,	KC_4,		KC_5,		KC_6,		KC_ENT, \
	KC_NLCK,	KC_ACL2,	KC_VOLU,	KC_MPRV,	KC_MPLY,	KC_MNXT,	KC_EQL,		KC_EQL,		KC_1,		KC_2,		KC_3,		_______, \
	_______,	OSL(_SYMB),	KC_VOLD,KC_MUTE,	KC_BSPC,	KC_SPC,		KC_SPC,		KC_DEL,		KC_0,		KC_0,		KC_DOT,		_______ \
),

/*===========================================================================================*/
/* Function
 * ,-----------------------------------------------------------------------------------.
 * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Symbol|      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
/* Symbol layer Work in progress...
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
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, \
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, \
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______  \
),
/*===========================================================================================*/

/* Symbol
 * ,-----------------------------------------------------------------------------------.
 * |QWERTY|   |  |  +   |  <   |  >   |  #   |   ~  |   (  |   )  |   \  |   :  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |COLMAK|   !  |  -   |  =   |  %   |  @   |   _  |   {  |   }  |   /  |   ?  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |MUSIC |   *  |  &   |  /   |  $   |  ^   |   |  |   [  |   ]  |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  FN  |      |      |      |      |      |      |      |      |      |      |Reset |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMB] = LAYOUT_planck_grid( \
	TO(_QWERTY),	KC_PIPE,	KC_PLUS,		KC_LABK,		KC_RABK,	KC_HASH,	KC_TILD,	KC_LPRN,	KC_RPRN,	KC_BSLS,	KC_COLN,	_______, \
	TO(_COLEMAK),	KC_EXLM,	KC_MINS,		KC_EQL,			KC_PERC,	KC_AT,		KC_UNDS,	KC_LCBR,	KC_RCBR,	KC_SLSH,	KC_QUES,	_______, \
	TO(_MUSIC),		KC_ASTR,	KC_AMPR,		KC_SLSH,		KC_DLR,		KC_CIRC,	KC_PIPE,	KC_LBRC,	KC_RBRC,	_______,	_______,	_______, \
	FUNCT,			_______,	_______,		_______,		_______,	_______,	_______,	_______,	_______,	_______,	_______,	RESET  \
),

/*===========================================================================================*/
/* Music
 * ,-----------------------------------------------------------------------------------.
 * |QWERTY|      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |COLMAK|      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      | MOD  | TOG  |
 * `-----------------------------------------------------------------------------------'
 */
[_MUSIC] = LAYOUT_planck_grid( \
	TO(_QWERTY),	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO, \
	TO(_COLEMAK),	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO, \
	KC_NO,			KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO, \
	KC_NO,			KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	MU_MOD,	MU_TOG \
)
/*===========================================================================================*/

};

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
	case FUNCT:
			if (record->event.pressed) {
				layer_off(_SYMB);
				layer_on(_FUNCT);
			}
			return false;
			break;
	}
	return true;
};
