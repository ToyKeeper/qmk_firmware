/* Core alpha keymap layout definitions
 * Copyright 2021-2025 Selene ToyKeeper
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#pragma once

///// core alpha/punc keymaps, for use in macros /////

#define __QWERTY__      __QWERTY_0__, __QWERTY_1__, __QWERTY_2__, __QWERTY_3__
#define __QWERTY_0__                                                                                          KC_MINS, KC_EQL
#define __QWERTY_1__    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,   KC_RBRC
#define __QWERTY_2__      KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT
#define __QWERTY_3__         KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

#define __DVORAK__      __DVORAK_0__, __DVORAK_1__, __DVORAK_2__, __DVORAK_3__
#define __DVORAK_0__                                                                                          KC_LBRC, KC_RBRC
#define __DVORAK_1__    KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,   KC_EQL
#define __DVORAK_2__      KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS
#define __DVORAK_3__         KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z

#define __UNDVORAK__    __UNDVORAK_0__, __UNDVORAK_1__, __UNDVORAK_2__, __UNDVORAK_3__
#define __UNDVORAK_0__                                                                                        KC_QUOT, KC_RBRC
#define __UNDVORAK_1__  KC_X,    KC_COMM, KC_D,    KC_O,    KC_K,    KC_T,    KC_F,    KC_G,    KC_S,    KC_R,    KC_MINS,   KC_EQL
#define __UNDVORAK_2__    KC_A,    KC_SCLN, KC_H,    KC_Y,    KC_U,    KC_J,    KC_C,    KC_V,    KC_P,    KC_Z,    KC_Q
#define __UNDVORAK_3__       KC_SLSH, KC_B,    KC_I,    KC_DOT,  KC_N,    KC_L,    KC_M,    KC_W,    KC_E,    KC_LBRC

#define __COLEMAK_DH_TK__    __COLEMAK_DH_TK_0__, __COLEMAK_DH_TK_1__, __COLEMAK_DH_TK_2__, __COLEMAK_DH_TK_3__
#define __COLEMAK_DH_TK_0__                                                                                      KC_SCLN,   KC_EQL
#define __COLEMAK_DH_TK_1__  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, KC_LBRC,   KC_RBRC
#define __COLEMAK_DH_TK_2__    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_MINS
#define __COLEMAK_DH_TK_3__       KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH

