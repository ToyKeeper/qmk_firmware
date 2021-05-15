/*
Copyright 2021 Selene ToyKeeper

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // qwerty
    [0] = LAYOUT_65_ansi_blocker_split_bs(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_GRV, MO(3),
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC, KC_PGUP,
        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_PGDN,
        KC_LSPO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSPC, KC_UP, KC_END,
        MO(2), KC_LGUI, KC_LALT, KC_SPC, KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
        ),

    // dvorak
    [1] = LAYOUT_65_ansi_blocker_split_bs(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_LBRC, KC_RBRC, KC_BSLS, KC_GRV, MO(3),
        KC_TAB, KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, KC_SLSH, KC_EQL, KC_BSPC, KC_PGUP,
        KC_LCTL, KC_A, KC_O, KC_E, KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, KC_S, KC_MINS, KC_ENT, KC_PGDN,
        KC_LSPO, KC_SCLN, KC_Q, KC_J, KC_K, KC_X, KC_B, KC_M, KC_W, KC_V, KC_Z, KC_RSPC, KC_UP, KC_END,
        MO(2), KC_LGUI, KC_LALT, KC_SPC, KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
        ),

    // Fn1
    [2] = LAYOUT_65_ansi_blocker_split_bs(
        KC_EJCT, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_TRNS, KC_NO,
        KC_MNXT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_WH_U, KC_MS_U, KC_WH_D, KC_NO, KC_NO, KC_NO, KC_DEL, KC_WSCH,
        KC_MPRV, DM_PLY2, DM_REC2, KC_NO, KC_NO, KC_NO, KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_R, KC_NO, KC_TRNS, KC_CALC,
        KC_BTN3, DM_PLY1, DM_REC1, KC_NO, KC_NO, KC_NO, KC_BTN1, KC_BTN1, KC_BTN3, KC_BTN2, KC_NO, KC_TRNS, KC_PGUP, KC_MYCM,
        KC_TRNS, KC_BTN1, KC_BTN2, KC_MPLY, KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_END
        ),

    // Fn2
    [3] = LAYOUT_65_ansi_blocker_split_bs(
        RESET, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_INS, LSFT(KC_INS), KC_TRNS,
        DF(1), DF(0), KC_WH_U, KC_MS_U, KC_WH_D, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_DEL, KC_WSCH,
        KC_CAPS, KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_R, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_CALC,
        KC_TRNS, KC_NO, KC_BTN1, KC_BTN3, KC_BTN2, KC_NO, NK_TOGG, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_PGUP, KC_MYCM,
        KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_RGUI, KC_APP, KC_HOME, KC_PGDN, KC_END
        )
};

