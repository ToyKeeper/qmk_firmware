/* ToyKeeper's shared keyboard functions header
 * Copyright 2021-2025 Selene ToyKeeper
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#pragma once

#include QMK_KEYBOARD_H
#include "version.h"  // for the TK_INFO key
#include "layouts.h"  // for qwerty/dvorak/colemak/etc layout definitions


///// things which can be defined in individual keymaps /////

// RGB Matrix?
//#define HAS_RGB

// Keychron switch on the back?
//#define HAS_DIPSWITCH

// enable numpad layer?
//#define USE_NUMPAD

// F1-F12 row?
//#define HAS_F_ROW

// Keychron Q65 has a column of extra keys on the left side
//#define HAS_XTRA_COLUMN

// has palm keys?  (Keyboardio Model01)
//#define USE_PALM

// If there's no physical key for mouselock, overload the GUI key (Whitefox)
//#define USE_RGUI_2TAP_MOUSELOCK

// Extend CapsWord's "word" characters for better compatibility on non-qwerty hosts?
//#define USE_CAPSWORD_KLUDGE

// don't include build info key
//#define DONT_USE_TK_INFO

// don't include "Any" key
//#define DONT_USE_ANY_KEY

// don't allow user to swap I and U keys on dvorak layer
//#define DONT_USE_TK_IUUI

// don't save any user config data (saves space)
//#define DONT_USE_EEPROM


// layers
enum {
    L_QWERTY = 0,
    L_DVORAK,
    L_UNDVORAK,
    L_COLEMAK,
    #ifdef USE_NUMPAD
    L_NUMPAD,
    #endif
    #ifdef HAS_F_ROW
    L_FLCK,   // toggle F1-F12 behavior (only used on 75% boards and bigger)
    #endif
    #ifdef USE_PALM  // palm Fn keys
    L_LPALM,  // left palm key
    L_RPALM,  // right palm key
    L_BOTH,   // both palm keys
    #else  // regular Fn keys
    L_MOUSE,  // lower right
    L_FN1,    // lower left
    L_FN2,    // upper right
    #endif
    #ifdef HAS_XTRA_COLUMN
    L_XC1,
    L_XC2,
    L_XC3,
    L_XC4,
    #endif
};
#define L_BOTTOM  (L_COLEMAK+1)  // lowest non-default layer
#define NUM_XC_LAYERS  4

enum my_keycodes {
    //TK_INFO = SAFE_RANGE,  // print build version / info
    TK_INFO = QK_USER,  // print build version / info
    // activate base layers like DF(N), and save them to the current switch slot
    TK_DF_0,  // qwerty
    TK_DF_1,  // dvorak
    TK_DF_2,  // undvorak
    TK_DF_3,  // colemak-dh traditional w/ TK mods
    // like base layers, but for the extra keys only
    TK_XC_0,  // Xtra Column mode 0
    TK_XC_1,  // Xtra Column mode 1
    TK_XC_2,  // Xtra Column mode 2
    TK_XC_3,  // Xtra Column mode 3
    TK_XC_4,  // Xtra Column mode 4
    // other custom keys
    TK_IUUI,  // toggle U/I swap on dvorak layer
    TK_ANY,   // the "Any" key, spits out random characters
    // toggle RGB Matrix effects on/off without disabling indicators
    TK_RGBT,  // RGB toggle
    // dynamic macros with forced layer-clear
    TK_REC1,
    TK_REC2,
    //TK_PLY1,
    //TK_PLY2,
    #ifdef IS_NUPHY_AIR75v2
    TK_BAT,   // show battery charge level on side LEDs
    TK_BNOW,  // show battery charge level on number keys
    #endif
};

#ifdef IS_NUPHY_AIR75v2
bool tk_bat_momentary;
void nuphy_indicators_user(void);
#endif

// custom keys which don't need a custom enum
#ifdef USE_PALM
// Keyboardio Model-01
#define TK_LPLM  MO(L_LPALM)
#define TK_RPLM  MO(L_RPALM)
#define TK_BOTH  MO(L_BOTH)
#define TK_MOON  TK_LPLM
#define TK_STAR  TK_RPLM
#define TK_VOID  TK_BOTH
#define TK_LGUI  MT(MOD_LGUI,_______)  // LGUI / oneshot(LALT) / hold(LALT)
#define TK_RGUI  MT(MOD_RGUI,_______)  // RGUI / oneshot(RALT) / hold(RALT)
#else
// 65% to 75% layouts
//#define TK_MOON  MT(L_FN1,L_FN1)  // hold / lock / clear L_FN1
#define TK_MOON  LT(L_FN1,KC_BTN1)
#define TK_STAR  LT(L_FN2,KC_HOME)
#define TK_MOUS  TT(L_MOUSE)
#define TK_FN1   TK_MOON
#define TK_FN2   TK_STAR
#define TK_HOME  TK_STAR
#ifdef OLD_QMK  // correct method didn't work until 2022-11-27 / QMK 19.0
#define TK_LGUI  LGUI_T(KC_1)          // LGUI / left click
#else
#define TK_LGUI  LGUI_T(KC_BTN1)       // LGUI / left click
#endif
#define TK_RGUI  MT(MOD_RGUI,_______)  // RGUI / MouseLock
#endif

#define TK_LCTL  LCTL_T(TK_WARP)       // LCTL / Warp
#define TK_RCTL  MT(MOD_RCTL,_______)  // RCTL / toggle(L_NUMPAD)
#define TK_LALT  LALT_T(KC_BSPC)       // LALT / Backspace
#define TK_RALT  RALT_T(TK_WARP)       // RALT / Warp
#define TK_SESC  S(KC_ESC)
#define TK_SINS  S(KC_INS)
#define TK_PLUS  S(KC_EQUAL)
#define TK_ASTR  S(KC_8)
#define TK_LPAR  S(KC_9)
#define TK_RPAR  S(KC_0)
#define TK_WARP  KC_F23  // mouse warp, handled by host OS
#define TK_BSTG  BS_TOGG
#ifndef BS_TOGG
#define BS_TOGG  _______  // don't break build on old versions
#endif
// TODO, maybe, someday: lockable control keys
#define TK_LCLK  KC_LCTL
#define TK_RCLK  KC_RCTL

// legacy mouse events from old QMK
#ifndef KC_MS_U
#define KC_MS_U  MS_UP
#define KC_MS_D  MS_DOWN
#define KC_MS_L  MS_LEFT
#define KC_MS_R  MS_RGHT
#define KC_WH_U  MS_WHLU
#define KC_WH_D  MS_WHLD
#define KC_WH_L  MS_WHLL
#define KC_WH_R  MS_WHLR
#define KC_BTN1  MS_BTN1
#define KC_BTN2  MS_BTN2
#define KC_BTN3  MS_BTN3
#define KC_BTN4  MS_BTN4
#define KC_BTN5  MS_BTN5
#define KC_BTN6  MS_BTN6
#define KC_BTN7  MS_BTN7
#define KC_BTN8  MS_BTN8
#define KC_BTN9  MS_BTN9
#endif

// legacy RGB controls from old QMK
#ifndef RGB_TOG
//#define RGB_TOG  RM_TOGG
#define RGB_TOG  TK_RGBT
#define RGB_MOD  RM_NEXT
#define RGB_MOU  RM_PREV
#define RGB_HUI  RM_HUEU
#define RGB_HUD  RM_HUED
#define RGB_SAI  RM_SATU
#define RGB_SAD  RM_SATD
#define RGB_VAI  RM_VALU
#define RGB_VAD  RM_VALD
#define RGB_SPI  RM_SPDU
#define RGB_SPD  RM_SPDD
#endif


#ifndef DONT_USE_EEPROM
// remember the user's preferred settings
typedef union {
    uint32_t raw;
    struct {
        #ifdef HAS_DIPSWITCH
            unsigned switch_off : 2;  // layer to use in "Mac" position (left / toward USB port)
            unsigned switch_on  : 2;  // layer to use in "Win" position (right / away from USB port)
        #endif
        #ifdef HAS_F_ROW
            unsigned f_lock     : 1;  // is F-Lock active?
        #endif
        #ifndef DONT_USE_TK_IUUI
            unsigned dvoriuk    : 1;  // swap U and I in dvorak layer?
        #endif
        #ifdef HAS_RGB
            unsigned rgb_enabled : 1;  // enable RGB matrix
        #endif
        #ifdef IS_NUPHY_AIR75v2
            unsigned bat_show   : 1;  // show battery status on side LEDs
        #endif
    };
} user_config_t;
//#define EECONFIG_USER_DATA_SIZE sizeof(user_config_t)

user_config_t user_config;
#endif  // ifndef DONT_USE_EEPROM

