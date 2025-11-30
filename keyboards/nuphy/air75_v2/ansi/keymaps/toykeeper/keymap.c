/* ToyKeeper's Nuphy Air75 v2 QMK keymap
 * Copyright 2025 Selene ToyKeeper
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include QMK_KEYBOARD_H

#include "toykeeper.h"

#define MY_LAYOUT LAYOUT_ansi_84

// wrap base layers to avoid the need to keep several copies in sync
#define MY_LAYOUT_wrapper(...) MY_LAYOUT(__VA_ARGS__)
#define MY_LAYOUT_base_wrapper(...) MY_LAYOUT_base(__VA_ARGS__)
#define MY_LAYOUT_base(                             K01, K02, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, \
      K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, \
        K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A \
  ) MY_LAYOUT_wrapper( \
    KC_ESC , KC_MYCM, KC_WSCH, KC_F13 , KC_F14 , KC_F15 , KC_F16 , KC_F17 , KC_F18 , KC_F19 , KC_F20 , KC_F21 , KC_F22 , KC_VOLD, KC_VOLU, TK_STAR, \
    QK_GESC, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , K01    , K02    ,       KC_BSLS,    KC_HOME, \
    KC_TAB ,    K11    , K12    , K13    , K14    , K15    , K16    , K17    , K18    , K19    , K1A    , K1B    , K1C    ,    KC_BSPC,    KC_PGUP, \
    TK_LCTL,       K21    , K22    , K23    , K24    , K25    , K26    , K27    , K28    , K29    , K2A    , K2B    ,          KC_ENT ,    KC_PGDN, \
    SC_LSPO,          K31    , K32    , K33    , K34    , K35    , K36    , K37    , K38    , K39    , K3A    ,     SC_RSPC,      KC_UP  , KC_END , \
    TK_MOON,  TK_LGUI,  TK_LALT,                          KC_SPC ,                            TK_RCTL, TK_RALT, TK_RGUI, KC_LEFT, KC_DOWN, KC_RGHT  \
    )

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* empty, copy/paste and fill in the blanks
[L_EMPTY] = MY_LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______,    _______,
    _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______,    _______,
    _______,       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,    _______,
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______,      _______, _______,
    _______,  _______,  _______,                          _______,                            _______, _______, _______, _______, _______, _______
    ), */

// base layers: qwerty, dvorak, undvorak, colemak-dh-tk
[L_QWERTY  ] = MY_LAYOUT_base_wrapper(__QWERTY__),
[L_DVORAK  ] = MY_LAYOUT_base_wrapper(__DVORAK__),
[L_UNDVORAK] = MY_LAYOUT_base_wrapper(__UNDVORAK__),
[L_COLEMAK ] = MY_LAYOUT_base_wrapper(__COLEMAK_DH_TK__),

// Number Pad(s)
[L_NUMPAD] = MY_LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______,    _______,
    _______,    _______, _______, _______, _______, _______, _______, KC_7   , KC_8   , KC_9   , _______, _______, _______,    _______,    _______,
    _______,       _______, _______, _______, _______, _______, _______, KC_4   , KC_5   , KC_6   , _______, _______,          _______,    _______,
    _______,          _______, _______, _______, _______, _______, KC_0   , KC_1   , KC_2   , KC_3   , _______,     _______,      _______, _______,
    _______,  _______,  _______,                          _______,                            _______, _______, _______, _______, _______, _______
    ),

// F-Lock (upper left corner, toggle F1-F12 row behavior)
[L_FLCK] = MY_LAYOUT(
    _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______,    _______,
    _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______,    _______,
    _______,       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,    _______,
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______,      _______, _______,
    _______,  _______,  _______,                          _______,                            _______, _______, _______, _______, _______, _______
    ),

// Mouse (lower right corner)
[L_MOUSE] = MY_LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______,    _______,
    _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______,    KC_WH_U,
    _______,       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_BTN3,    KC_WH_D,
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     KC_BTN1,      KC_MS_U, KC_BTN2,
    _______,  _______,  _______,                          _______,                            _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R
    ),

// Fn1 / Moon (lower left corner)
[L_FN1] = MY_LAYOUT(
 TG(L_FLCK), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    TK_SESC, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,       TK_BSTG,    _______,
    KC_MPLY,    KC_MNXT, KC_MPRV, TK_ANY , _______, _______, _______, KC_WH_U, KC_MS_U, KC_WH_D, _______, _______, _______,    _______,    KC_WH_U,
    _______,       DM_PLY2, DM_REC2, _______, _______, _______, KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_R, _______,          KC_BTN3,    KC_WH_D,
    KC_BTN3,          DM_PLY1, DM_REC1, _______, _______, _______, TK_WARP, KC_BTN1, KC_BTN3, KC_BTN2, _______,     KC_BTN1,      KC_MS_U, KC_BTN2,
    _______,  _______,  _______,                          KC_DEL ,                            _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R
    ),

// Fn2 / Star (upper right corner)
[L_FN2] = MY_LAYOUT(
    QK_BOOT, KC_BRID, KC_BRIU, _______, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_INS , TK_SINS, _______,
    LNK_RF , LNK_BLE1,LNK_BLE2,LNK_BLE3,KC_F14 , KC_F15 , KC_F16 , KC_F17 , KC_F18 , KC_F19 , KC_F20 , KC_F21 , KC_F22 ,       KC_DEL ,    KC_MYCM ,
    TK_INFO,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    KC_DEL ,    KC_WSCH,
    KC_CAPS,       RGB_HUI, RGB_SAI, RGB_VAI, _______, TK_IUUI, _______, _______, _______, _______, _______, _______,          BAT_NUM,    KC_F13 ,
    TK_DF_3,          RGB_MOD, RGB_SPI, _______, _______, _______, NK_TOGG, _______, _______, _______, _______,     _______,      KC_PGUP, KC_F14 ,
    TK_DF_0,  TK_DF_1,  TK_DF_2,                          RGB_TOG,                            KC_APP , _______, _______, KC_HOME, KC_PGDN, KC_END
    ),

// TODO:
// - tap Moon for left click
// - chord VOLD+VOLU = MUTE
// - RF_DFU
// * KC_BRID, KC_BRIU
// * LNK_BLE1, LNK_BLE2, LNK_BLE3, LNK_RF
// - LNK_USB
// - RGB_TEST
// + BAT_NUM, BAT_SHOW
// * KC_MUTE, KC_VOLD, KC_VOLU
// - DEV_RESET, SLEEP_MODE
// ? SIDE_MOD, SIDE_VAD, SIDE_VAI, SIDE_HUI, SIDE_SPD, SIDE_SPI
//   (I may just want these off, no key mappings needed?)
//   (side lights are nice for battery and wireless status, but annoying otherwise)

};

const uint8_t layer_indicator_colors[][6] = {
    // l, x,y, r,g,b
    { L_NUMPAD  ,10,5, 192,  0,  0 },
    { L_MOUSE   ,12,5, 255,200,200 },
    { L_FN1     , 0,5, 255,200,200 },
    { L_FN2     ,15,0, 255,255, 30 },
    { 0         , 0,0,   0,  0,  0 },  // stop
};

const uint8_t mod_indicator_coords[][3] = {
    // mod, x, y
    { 1, 0, 4, },  // L Shift
    { 1,13, 4, },  // R Shift
    { 2, 0, 3, },  // L Ctrl
    { 2,10, 5, },  // R Ctrl
    { 3, 2, 5, },  // L Alt
    { 3,11, 5, },  // R Alt
    { 4, 1, 5, },  // L GUI
    { 4,12, 5, },  // R GUI
    { 0, 0, 0, },  // stop
};

/* original Nuphy layers
// layer Mac
[0] = LAYOUT_ansi_84(
	KC_ESC, 	KC_BRID,  	KC_BRIU,  	MAC_TASK, 	MAC_SEARCH, MAC_VOICE,  MAC_DND,  	KC_MPRV,  	KC_MPLY,  	KC_MNXT, 	KC_MUTE, 	KC_VOLD, 	KC_VOLU, 	MAC_PRTA,	KC_INS,		KC_DEL,
	KC_GRV, 	KC_1,   	KC_2,   	KC_3,  		KC_4,   	KC_5,   	KC_6,   	KC_7,   	KC_8,   	KC_9,  		KC_0,   	KC_MINS,	KC_EQL, 				KC_BSPC,	KC_PGUP,
	KC_TAB, 	KC_Q,   	KC_W,   	KC_E,  		KC_R,   	KC_T,   	KC_Y,   	KC_U,   	KC_I,   	KC_O,  		KC_P,   	KC_LBRC,	KC_RBRC, 				KC_BSLS,	KC_PGDN,
	KC_CAPS,	KC_A,   	KC_S,   	KC_D,  		KC_F,   	KC_G,   	KC_H,   	KC_J,   	KC_K,   	KC_L,  		KC_SCLN,	KC_QUOT, 	 						KC_ENT,		KC_HOME,
	KC_LSFT,				KC_Z,   	KC_X,   	KC_C,  		KC_V,   	KC_B,   	KC_N,   	KC_M,   	KC_COMM,	KC_DOT,		KC_SLSH,				KC_RSFT,	KC_UP,		KC_END,
	KC_LCTL,	KC_LALT,	KC_LGUI,										KC_SPC, 							KC_RGUI,	MO(1),   	KC_RCTL,				KC_LEFT,	KC_DOWN,    KC_RGHT),

// layer Mac Fn
[1] = LAYOUT_ansi_84(
	_______, 	KC_F1,  	KC_F2,  	KC_F3, 		KC_F4,  	KC_F5,  	KC_F6,  	KC_F7,  	KC_F8,  	KC_F9, 		KC_F10, 	KC_F11, 	KC_F12, 	MAC_PRT,	_______,	_______,
	_______, 	LNK_BLE1,  	LNK_BLE2,  	LNK_BLE3,  	LNK_RF,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	_______,	_______, 				_______,	_______,
	_______, 	_______,   	_______,   	_______,  	_______,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	DEV_RESET,	SLEEP_MODE, 			BAT_SHOW,	_______,
	_______,	_______,   	_______,   	_______,  	_______,   	_______,   	_______,	_______,   	_______,   	_______,  	_______,	_______, 	 						_______,	_______,
	_______,				_______,   	_______,   	RGB_TEST,  	_______,   	BAT_NUM,   	_______,	MO(4), 		RGB_SPD,	RGB_SPI,	_______,				_______,	RGB_VAI,	_______,
	_______,	_______,	_______,										_______, 							_______,	MO(1),   	_______,				RGB_MOD,	RGB_VAD,    RGB_HUI),

// layer win
[2] = LAYOUT_ansi_84(
	KC_ESC, 	KC_F1,  	KC_F2,  	KC_F3, 		KC_F4,  	KC_F5,  	KC_F6,  	KC_F7,  	KC_F8,  	KC_F9, 		KC_F10, 	KC_F11, 	KC_F12, 	KC_PSCR,	KC_INS,		KC_DEL,
	KC_GRV, 	KC_1,   	KC_2,   	KC_3,  		KC_4,   	KC_5,   	KC_6,   	KC_7,   	KC_8,   	KC_9,  		KC_0,   	KC_MINS,	KC_EQL, 				KC_BSPC,	KC_PGUP,
	KC_TAB, 	KC_Q,   	KC_W,   	KC_E,  		KC_R,   	KC_T,   	KC_Y,   	KC_U,   	KC_I,   	KC_O,  		KC_P,   	KC_LBRC,	KC_RBRC, 				KC_BSLS,	KC_PGDN,
	KC_CAPS,	KC_A,   	KC_S,   	KC_D,  		KC_F,   	KC_G,   	KC_H,   	KC_J,   	KC_K,   	KC_L,  		KC_SCLN,	KC_QUOT, 	 						KC_ENT,		KC_HOME,
	KC_LSFT,				KC_Z,   	KC_X,   	KC_C,  		KC_V,   	KC_B,   	KC_N,   	KC_M,   	KC_COMM,	KC_DOT,		KC_SLSH,				KC_RSFT,	KC_UP,		KC_END,
	KC_LCTL,	KC_LGUI,	KC_LALT,										KC_SPC, 							KC_RALT,	MO(3),   	KC_RCTL,				KC_LEFT,	KC_DOWN,    KC_RGHT),

// layer win Fn
[3] = LAYOUT_ansi_84(
	_______, 	KC_BRID,   	KC_BRIU,    _______,  	_______,   	_______,   	_______,   	KC_MPRV,   	KC_MPLY,   	KC_MNXT,  	KC_MUTE, 	KC_VOLD, 	KC_VOLU,	_______,	_______,	_______,
	_______, 	LNK_BLE1,  	LNK_BLE2,  	LNK_BLE3,  	LNK_RF,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	_______,	_______, 				_______,	_______,
	_______, 	_______,   	_______,   	_______,  	_______,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	DEV_RESET,	SLEEP_MODE, 			BAT_SHOW,	_______,
	_______,	_______,   	_______,   	_______,  	_______,   	_______,   	_______,	_______,   	_______,   	_______,  	_______,	_______, 	 						_______,	_______,
	_______,				_______,   	_______,   	RGB_TEST,  	_______,   	BAT_NUM,   	_______,	MO(4), 		RGB_SPD,	RGB_SPI,	_______,				_______,	RGB_VAI,	_______,
	_______,	_______,	_______,										_______, 							_______,	MO(3),   	_______,				RGB_MOD,	RGB_VAD,    RGB_HUI),

// layer 4
[4] = LAYOUT_ansi_84(
	_______, 	_______,  	_______,  	_______, 	_______,  	_______,  	_______,  	_______,  	_______,  	_______, 	_______, 	_______, 	_______, 	_______,	_______,	_______,
	_______, 	_______,   	_______,   	_______,  	_______,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	_______,	_______, 				_______,	_______,
	_______, 	_______,   	_______,   	_______,  	_______,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	_______,	_______, 				_______,	_______,
	_______,	_______,   	_______,   	_______,  	_______,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,	_______, 	 						_______,	_______,
	_______,				_______,   	_______,   	_______,  	_______,   	_______,   	_______,   	_______,   	SIDE_SPD,	SIDE_SPI,	_______,				_______,	SIDE_VAI,	_______,
	_______,	_______,	_______,										_______, 							_______,	MO(4),   	_______,				SIDE_MOD,	SIDE_VAD,   SIDE_HUI)
};
*/

