#include QMK_KEYBOARD_H
//Inherited from chormanski keymap
enum preonic_layers {
  _QWERTY,
  _COLEMAK,
  _FUNCT,
  _NUMPAD,
  _SYMB,
  _MUSIC
};

enum preonic_keycodes {
  FUNCT
};

//Tap Dance Declarations
enum {
  TEsc = 0,
  ColQot,
  BRC,
  BkMin,
  CtlTsk
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Tilde, twice for Escape
  [TEsc] = ACTION_TAP_DANCE_DOUBLE(KC_GRV, KC_ESC),

  //Tap once for Backspace twice for Equal
  [ColQot] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_QUOT),

  //Tap once for [, twice for ]
  [BRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),

  //Tap once for Backspace, twice for Minus
  [BkMin] = ACTION_TAP_DANCE_DOUBLE(KC_BSPC, KC_MINS),

  //Tap once for Ctrl, twice for Ctl+Alt+Del
  [CtlTsk] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, LALT(LCTL(KC_DEL)))

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | `Esc |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  [ ] |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |  ;"  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Numpad|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Ctrl | Alt  |CmdDel| Bksp | Space|Space |  Del | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid( \
	TD(TEsc),	KC_1,		KC_2,		KC_3,		KC_4,		KC_5,	KC_6,	KC_7,	KC_8,		KC_9,		KC_0,		KC_BSPC,  \
	KC_TAB,		KC_Q,		KC_W,		KC_E,		KC_R,		KC_T,	KC_Y,	KC_U,	KC_I,		KC_O,		KC_P,		TD(BRC),   \
	KC_LCTL,	KC_A,		KC_S,		KC_D,		KC_F,		KC_G,	KC_H,	KC_J,	KC_K,		KC_L,		TD(ColQot),	KC_ENT, \
	KC_LSFT,	KC_Z,		KC_X,		KC_C,		KC_V,		KC_B,	KC_N,	KC_M,	KC_COMM,	KC_DOT,		KC_SLSH,	TT(_NUMPAD), \
	TD(CtlTsk), KC_LCTL,	KC_LALT,CMD_T(KC_DEL),	KC_BSPC,	KC_SPC,	KC_SPC,	KC_DEL,	KC_LEFT,	KC_DOWN,	KC_UP,		KC_RGHT  \
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | `Esc |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  |  [ ] |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Numpad|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |Symbol| Alt  | Bksp | Bksp | Space|Space |  Del | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_preonic_grid( \
	TD(TEsc),	KC_1,		KC_2,		KC_3,		KC_4,		KC_5,	KC_6,	KC_7,	KC_8,		KC_9,		KC_0,		KC_BSPC,  \
	KC_TAB,		KC_Q,		KC_W,		KC_F,		KC_P,		KC_G,	KC_J,	KC_L,	KC_U,		KC_Y,		TD(ColQot),	TD(BRC), \
	KC_ESC,		KC_A,		KC_R,		KC_S,		KC_T,		KC_D,	KC_H,	KC_N,	KC_E,		KC_I,		KC_O,		KC_QUOT,   \
	KC_LSFT,	KC_Z,		KC_X,		KC_C,		KC_V,		KC_B,	KC_K,	KC_M,	KC_COMM,	KC_DOT,		KC_SLSH,	TG(_NUMPAD), \
	KC_LCTL, OSL(_SYMB),	KC_LALT,	KC_BSPC,	KC_BSPC,	KC_SPC,	KC_SPC,	KC_DEL,	KC_LEFT,	KC_DOWN,	KC_UP,		KC_RGHT \
),


/* Function
 * ,-----------------------------------------------------------------------------------.
 * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNCT] = LAYOUT_preonic_grid( \
	KC_F11,		KC_F1,		KC_F2,		KC_F3,		KC_F4,		KC_F5,		KC_F6,		KC_F7,		KC_F8,		KC_F9,		KC_F10,		KC_F12,  \
	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______, \
	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______, \
	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______, \
	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______  \
),

/* Numpad & Mouse
 * ,-----------------------------------------------------------------------------------.
 * |   `  |      |      |M-clic|      |      | NumLk|   7  |   8  |   9  |  0   |Bksp- |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | ACL0 |L-clck|  Up  |R-clck|Scrl U|   *  |   4  |   5  |   6  |  +   |  :   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | ACL1 | Left | Down |Right |Scrl D|   /  |   1  |   2  |   3  |  -   | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | ACL2 | VOLU | PREV |PAUSE | NEXT |   =  |   0  |   .  |   *  |  /   | Back |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Symbol|      | VOLD | MUTE | Bksp | Space|Space | Del  | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT_preonic_grid( \
	KC_GRV,		_______,	_______,	KC_BTN3,	_______,	_______,	KC_NLCK,	_______,	_______,	_______,	_______,	TD(BkMin), \
	_______,	KC_ACL0,	KC_BTN1,	KC_MS_U,	KC_BTN2,	KC_WH_U,	KC_ASTR,	KC_4,		KC_5,		KC_6,		KC_PLUS,    KC_COLN, \
	_______,	KC_ACL1,	KC_MS_L,	KC_MS_D,	KC_MS_R,	KC_WH_D,	KC_SLSH,	KC_1,		KC_2,		KC_3,		KC_MINS,    KC_ENT, \
	_______,	KC_ACL2,	KC_VOLU,	KC_MPRV,	KC_MPLY,	KC_MNXT,	KC_EQL,		KC_0,		KC_DOT,		KC_ASTR,    KC_SLSH,    _______, \
	OSL(_SYMB),	_______,	KC_VOLD,	KC_MUTE,	KC_BSPC,	KC_SPC,		KC_SPC,		KC_DEL,		_______,	_______,	_______,	_______ \
),

/* Symbol
 * ,-----------------------------------------------------------------------------------.
 * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |QWERTY|   |  |  +   |  <   |  >   |  #   |   ~  |   (  |   )  |   \  |   :  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |COLMAK|   !  |  -   |  =   |  %   |  @   |   _  |   {  |   }  |   /  |   ?  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |MUSIC |   *  |  &   |  /   |  $   |  ^   |   |  |   [  |   ]  |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  FN  |      |      |      |      |      |      |      |      |      |Reset |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMB] = LAYOUT_preonic_grid( \
	KC_F11,			KC_F1,		KC_F2,			KC_F3,			KC_F4,		KC_F5,		KC_F6,		KC_F7,		KC_F8,		KC_F9,		KC_F10,		KC_F12,  \
	TO(_QWERTY),	KC_PIPE,	KC_PLUS,		KC_LABK,		KC_RABK,	KC_HASH,	KC_TILD,	KC_LPRN,	KC_RPRN,	KC_BSLS,	KC_COLN,	_______, \
	TO(_COLEMAK),	KC_EXLM,	KC_MINS,		KC_EQL,			KC_PERC,	KC_AT,		KC_UNDS,	KC_LCBR,	KC_RCBR,	KC_SLSH,	KC_QUES,	_______, \
	TO(_MUSIC),		KC_ASTR,	KC_AMPR,		KC_SLSH,		KC_DLR,		KC_CIRC,	KC_PIPE,	KC_LBRC,	KC_RBRC,	_______,	_______,	_______, \
	_______,		FUNCT,	    _______,		_______,		_______,	_______,	_______,	_______,	_______,	_______,	_______,	RESET  \
),

/* Music
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |QWERTY|      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |COLMAK|      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      | MOD  | TOG  |
 * `-----------------------------------------------------------------------------------'
 */
[_MUSIC] = LAYOUT_preonic_grid( \
	KC_NO,			KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO, \
	TO(_QWERTY),	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO, \
	TO(_COLEMAK),	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO, \
	KC_NO,			KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO, \
	KC_NO,			KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	MU_MOD,	MU_TOG \
)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
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
