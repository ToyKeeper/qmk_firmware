/* ToyKeeper's Nuphy Air75 v2 QMK keymap
 * Copyright 2025 Selene ToyKeeper
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// TODO:
// - try jincao1's fork
//   - LINK_TO: link timeout toggle between short and long (saved in eeprom)
//   + KB_SLP: sleep timeout toggle between short and long (this boot only)
//   S DB_TOGG: toggle QMK Debug Mode
//   - led_power_handle() needs to allow my indicators
//   - add tenths + ones display for battery level
//   * fix or disable the dipswitch (fixed)
// * fix mousekeys going WAY too fast in wireless mode (jincao1's fork fixed it)
// * fix build-info key dropping keystrokes in wireless mode
// * tap Moon for left click
// * chord VOLD+VOLU = MUTE
// * RF_DFU
// ? KC_BRID, KC_BRIU
// * LNK_BLE1, LNK_BLE2, LNK_BLE3, LNK_RF
// ? LNK_USB
// F RGB_TEST (tried it, but it didn't seem to work)
// * BAT_NUM, BAT_SHOW (and replaced them with my own version)
// * KC_MUTE, KC_VOLD, KC_VOLU
// * DEV_RESET
// * SLEEP_MODE
// * SIDE_MOD, SIDE_VAD, SIDE_VAI, SIDE_HUI, SIDE_SPD, SIDE_SPI
//   (I just want these off, maybe no key mappings needed?)
//   (side lights are nice for battery and wireless status, but annoying otherwise)
//   (turns out the keys are needed at least on first boot, to switch side RGB to "off" mode)

#include QMK_KEYBOARD_H
#include "user_kb.h"
#include "mcu_pwr.h"

#include "toykeeper.h"

// override my usual shared config
#undef TK_STAR
#define TK_STAR  LT(L_FN2,KC_PRINT_SCREEN)

#define MY_LAYOUT LAYOUT_75_ansi

// wrap base layers to avoid the need to keep several copies in sync
#define MY_LAYOUT_wrapper(...) MY_LAYOUT(__VA_ARGS__)
#define MY_LAYOUT_base_wrapper(...) MY_LAYOUT_base(__VA_ARGS__)
#define MY_LAYOUT_base(                             K01, K02, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, \
      K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, \
        K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A \
  ) MY_LAYOUT_wrapper( \
    KC_ESC , KC_MYCM, KC_WSCH, KC_F13 , KC_F14 , KC_F15 , KC_F16 , KC_F17 , KC_F18 , KC_F19 , KC_F20 , KC_F21 , KC_F22 , KC_VOLD, KC_VOLU, TK_STAR, \
    KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , K01    , K02    ,       KC_BSLS,    KC_HOME, \
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
    _______, _______, _______, _______, _______, _______, _______, KC_NUM , KC_PAST, TK_LPAR, TK_RPAR, _______, _______,       _______,    _______,
    _______,    _______, _______, _______, _______, _______, _______, KC_P7  , KC_P8  , KC_P9  , KC_PAST, KC_PSLS, KC_PEQL,    _______,    _______,
    _______,       _______, _______, _______, _______, _______, KC_PDOT, KC_P4  , KC_P5  , KC_P6  , KC_PPLS, KC_PMNS,          KC_PENT,    _______,
    _______,          _______, _______, _______, _______, _______, KC_P0  , KC_P1  , KC_P2  , KC_P3  , KC_PSLS,     _______,      _______, _______,
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
    _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,       TK_BSTG,    _______,
    KC_MPLY,    KC_MNXT, KC_MPRV, TK_ANY , _______, _______, _______, KC_WH_U, KC_MS_U, KC_WH_D, _______, _______, _______,    KC_DEL ,    KC_WH_U,
    _______,       DM_REC1, DM_REC2, _______, _______, _______, KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_R, _______,          KC_BTN3,    KC_WH_D,
    KC_BTN3,          DM_PLY1, DM_PLY2, _______, _______, _______, TK_WARP, KC_BTN1, KC_BTN3, KC_BTN2, _______,     KC_BTN1,      KC_MS_U, KC_BTN2,
    _______,  KC_BTN1,  KC_BTN2,                          KC_DEL ,                            _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R
    ),

// Fn2 / Star (upper right corner)
[L_FN2] = MY_LAYOUT(
    QK_BOOT, KC_BRID, KC_BRIU, _______, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_INS , TK_SINS, _______,
    LNK_RF , LNK_BLE1,LNK_BLE2,LNK_BLE3,RF_DFU , KC_F15 , KC_F16 , KC_F17 , KC_F18 , KC_F19 , KC_F20 , KC_F21 , KC_F22 ,       KC_DEL ,    KC_F14 ,
    TK_INFO,    _______, _______, _______,DEV_RESET,_______, _______, _______, _______, _______, _______, _______, _______,    TK_BNOW,    KC_F13 ,
    KC_CAPS,       RGB_HUI, RGB_SAI, RGB_VAI, _______, TK_IUUI, _______, SIDE_HUI,SIDE_VAD,SIDE_VAI, _______, BAT_SHOW,        TK_BAT ,    KC_WSCH,
    TK_DF_3,          RGB_MOD, RGB_SPI, _______, _______, _______, NK_TOGG, SIDE_MOD,SIDE_SPI,KB_SLP , SLEEP_MODE,   _______,     KC_PGUP, KC_MYCM,
    TK_DF_0,  TK_DF_1,  TK_DF_2,                          TK_RGBT,                            KC_APP , _______, _______, KC_HOME, KC_PGDN, KC_END
    ),

};

const uint8_t layer_indicator_colors[][6] = {
    // l, x,y, r,g,b
    { L_NUMPAD  , 9,5, 255, 16,  0 },
    { L_MOUSE   ,14,3, 255,200,200 },  // (weird matrix position, doesn't match physical layout)
    { L_FN1     , 0,5, 255,200,200 },
    { L_FN2     ,14,0, 255,255, 30 },  // (weird matrix position, doesn't match physical layout)
    { 0         , 0,0,   0,  0,  0 },  // stop
};

const uint8_t mod_indicator_coords[][3] = {
    // mod, x, y
    { 1,  0,4, },  // L Shift
    { 1, 13,4, },  // R Shift
    { 2,  0,3, },  // L Ctrl
    { 2,  9,5, },  // R Ctrl
    { 3,  2,5, },  // L Alt
    { 3, 10,5, },  // R Alt
    { 4,  1,5, },  // L GUI
    { 4, 14,3, },  // R GUI  (weird matrix position, doesn't match physical layout)
    { 0,  0,0, },  // stop
};

const uint16_t PROGMEM backslash_equal[] = {KC_BSLS, KC_EQL, COMBO_END};
const uint16_t PROGMEM vol_up_down[] = {KC_VOLU, KC_VOLD, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(backslash_equal, TK_SINS),  // paste even if my fingers are off by one column
    COMBO(vol_up_down, KC_MUTE),  // volume up+down = mute
};


/* jincao1's original layers
// layer Mac
[0] = LAYOUT_75_ansi(
    KC_ESC,     KC_BRID,   KC_BRIU,     KC_MCTL,   MAC_SEARCH, MAC_VOICE,   MAC_DND,   KC_MPRV,    KC_MPLY,     KC_MNXT,   KC_MUTE,    KC_VOLD,    KC_VOLU,     MAC_PRTA,   KC_INS,     KC_DEL,
    KC_GRV,     KC_1,      KC_2,        KC_3,      KC_4,       KC_5,        KC_6,      KC_7,       KC_8,        KC_9,      KC_0,       KC_MINS,    KC_EQL,                  KC_BSPC,    KC_PGUP,
    KC_TAB,     KC_Q,      KC_W,        KC_E,      KC_R,       KC_T,        KC_Y,      KC_U,       KC_I,        KC_O,      KC_P,       KC_LBRC,    KC_RBRC,                 KC_BSLS,    KC_PGDN,
    KC_CAPS,    KC_A,      KC_S,        KC_D,      KC_F,       KC_G,        KC_H,      KC_J,       KC_K,        KC_L,      KC_SCLN,    KC_QUOT,                             KC_ENT,     KC_HOME,
    KC_LSFT,               KC_Z,        KC_X,      KC_C,       KC_V,        KC_B,      KC_N,       KC_M,        KC_COMM,   KC_DOT,     KC_SLSH,                 KC_RSFT,    KC_UP,      KC_END,
    KC_LCTL,    KC_LALT,   KC_LGUI,                                         KC_SPC,                             KC_RGUI,   MO(1),      KC_RCTL,                 KC_LEFT,    KC_DOWN,    KC_RGHT),

// layer Mac Fn
[1] = LAYOUT_75_ansi(
    _______,    KC_F1,      KC_F2,      KC_F3,     KC_F4,      KC_F5,       KC_F6,     KC_F7,      KC_F8,       KC_F9,     KC_F10,     KC_F11,     KC_F12,      SYS_PRT,    _______,    _______,
    _______,    LNK_BLE1,   LNK_BLE2,   LNK_BLE3,  LNK_RF,     _______,     _______,   _______,    _______,     _______,   _______,    _______,	   _______,                 _______,    _______,
    _______,    _______,    _______,    _______,   _______,    _______,     _______,   _______,    _______,     _______,   _______,    DEV_RESET,  _______,                 BAT_SHOW,   _______,
    _______,    _______,    _______,    _______,   _______,    _______,     _______,   _______,    _______,     _______,   _______,    _______,                             _______,    _______,
    _______,                _______,    _______,   _______,    _______,     BAT_NUM,   _______,    MO(4),       RGB_SPD,   RGB_SPI,    _______,                 _______,    _______,    _______,
    _______,    _______,    _______,                                        _______,                            _______,   MO(1),      _______,                 RM_NEXT,    _______,    RM_HUEU),

// layer win
[2] = LAYOUT_75_ansi(
    KC_ESC,     KC_F1,     KC_F2,       KC_F3,     KC_F4,      KC_F5,       KC_F6,     KC_F7,      KC_F8,       KC_F9,     KC_F10,     KC_F11,     KC_F12,      KC_PSCR,    KC_INS,     KC_DEL,
    KC_GRV,     KC_1,      KC_2,        KC_3,      KC_4,       KC_5,        KC_6,      KC_7,       KC_8,        KC_9,      KC_0,       KC_MINS,    KC_EQL,                  KC_BSPC,    KC_PGUP,
    KC_TAB,     KC_Q,      KC_W,        KC_E,      KC_R,       KC_T,        KC_Y,      KC_U,       KC_I,        KC_O,      KC_P,       KC_LBRC,    KC_RBRC,                 KC_BSLS,    KC_PGDN,
    KC_CAPS,    KC_A,      KC_S,        KC_D,      KC_F,       KC_G,        KC_H,      KC_J,       KC_K,        KC_L,      KC_SCLN,    KC_QUOT,                             KC_ENT,     KC_HOME,
    KC_LSFT,               KC_Z,        KC_X,      KC_C,       KC_V,        KC_B,      KC_N,       KC_M,        KC_COMM,   KC_DOT,     KC_SLSH,                 KC_RSFT,    KC_UP,      KC_END,
    KC_LCTL,    KC_LGUI,   KC_LALT,                                         KC_SPC,                             KC_RALT,   MO(3),      KC_RCTL,                 KC_LEFT,    KC_DOWN,    KC_RGHT),

// layer win Fn
[3] = LAYOUT_75_ansi(
    _______,    KC_BRID,    KC_BRIU,    KC_CALC,   _______,    _______,     _______,   KC_MPRV,    KC_MPLY,     KC_MNXT,   KC_MUTE,    KC_VOLD,    KC_VOLU,     _______,    _______,    _______,
    _______,    LNK_BLE1,   LNK_BLE2,   LNK_BLE3,  LNK_RF,     _______,     _______,   _______,    _______,     _______,   _______,    _______,	   _______,                 _______,    _______,
    _______,    _______,    _______,    _______,   _______,    _______,     _______,   _______,    _______,     _______,   _______,    DEV_RESET,  _______,                 BAT_SHOW,   _______,
    _______,    _______,    _______,    _______,   _______,    _______,     _______,   _______,    _______,     _______,   _______,    _______,                             _______,    _______,
    _______,                _______,    _______,   _______,    _______,     BAT_NUM,   _______,    MO(4),       RGB_SPD,   RGB_SPI,    _______,                 _______,    _______,    _______,
    _______,    _______,    _______,                                        _______,                            _______,   MO(3),      _______,                 RM_NEXT,    _______,    RM_HUEU),

// layer 4
[4] = LAYOUT_75_ansi(
    _______,    RM_VALD,    RM_VALU,    _______,   _______,    _______,     _______,   _______,    _______,     _______,   _______,    _______,     _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,   _______,    _______,     _______,   _______,    _______,     _______,   _______,    _______,     _______,                _______,    _______,
    _______,    _______,    _______,    _______,   _______,    _______,     _______,   _______,    _______,     _______,   _______,    _______,     SLEEP_MODE,             _______,    _______, 
    _______,    _______,    KB_SLP,     DB_TOGG,   _______,    _______,     _______,   _______,    _______,     _______,   _______,    _______,                             _______,    _______,
    _______,                LINK_TO,    _______,   RGB_TEST,   _______,     _______,   _______,    _______,     SIDE_SPD,  SIDE_SPI,   _______,                 _______,    SIDE_VAI,   _______,
    _______,    _______,    _______,                                        _______,                            _______,   MO(4),      _______,                 SIDE_MOD,	SIDE_VAD,   SIDE_HUI)
};
*/

// import these from vendor's keyboard code
extern DEV_INFO_STRUCT dev_info;
void side_rgb_set_color(int index, uint8_t red, uint8_t green, uint8_t blue);

// show battery and charge state on side LEDs and number keys
void nuphy_indicators_user(void) {
    // display battery status on number keys 1-0
    static uint8_t bat_percent = 0;
    bat_percent = dev_info.rf_battery;
    uint8_t plugged_in = !(!(dev_info.rf_charge & 0x01));
    uint8_t charging_now = !(dev_info.rf_charge & 0x02);
    uint8_t numkey_bat[][5] = {
        // px, key,  r,   g,   b
        {  1, 29,  255,   0,   0 },  // 1
        { 10, 28,  255, 128,   0 },  // 2
        { 20, 27,  255, 255,   0 },  // 3
        { 30, 26,  128, 255,   0 },  // 4
        { 40, 25,    0, 255,   0 },  // 5
        { 50, 24,    0, 255, 128 },  // 6
        { 60, 23,    0, 255, 255 },  // 7
        { 70, 22,    0, 128, 255 },  // 8
        { 80, 21,    0,   0, 255 },  // 9
        { 90, 20,  255,   0, 255 },  // 0
    };
    // ensure RGB is on when needed
    if (tk_bat_momentary || user_config.bat_show) {
        // TODO: test this
        pwr_rgb_led_on();
    }

    //if (f_bat_num_show) {
    if (tk_bat_momentary) {
        uint8_t px, key, r, g, b;
        for (uint8_t i=0; i<10; i++) {
            px  = numkey_bat[i][0];
            key = numkey_bat[i][1];
            r   = numkey_bat[i][2];
            g   = numkey_bat[i][3];
            b   = numkey_bat[i][4];
            if (bat_percent >= px) rgb_matrix_set_color(key, r, g, b);
        }
    }
    // side LEDs are 2 sets of 6, numbered 0 to 11
    // and they go from bottom left to top left, then top right to bottom right
    // 0 to 5 on the left going up, then 6 to 11 on the right going down
    #define NUM_SIDE_LEDS  6
    // reduce brightness of side LEDs by this many powers of two:
    #define RS_DIM  (3 - plugged_in - charging_now)  // brighter while plugged in and charging
    #define LS_DIM  (1 - (2*charging_now))
    if (user_config.bat_show) {
        uint8_t side_bat[NUM_SIDE_LEDS][4] = {
            // px,  r, g, b
            { 5,  63,  0,  0},
            {17,  63, 32,  0},
            {33,   0, 63,  0},
            {50,   0, 63, 63},
            {67,   0,  0, 63},
            {83,  63,  0, 32},
        };
        for (uint8_t led = 0; led < NUM_SIDE_LEDS; led ++) {
            uint8_t left = 5 - led;  // top to bottom rainbow
            uint8_t right = 11 - led;  // bottom to top rainbow
            uint8_t px = side_bat[led][0];
            if (bat_percent > px) {
                // right side: bottom=red, top=blue/purple (held charge)
                side_rgb_set_color(right,
                        side_bat[led][1] >> RS_DIM,
                        side_bat[led][2] >> RS_DIM,
                        side_bat[led][3] >> RS_DIM);
                // left side: top=red, bottom=blue/purple (incoming power)
                if (plugged_in) {
                    side_rgb_set_color(left,
                            side_bat[led][1] >> LS_DIM,
                            side_bat[led][2] >> LS_DIM,
                            side_bat[led][3] >> LS_DIM);
                } else {
                    // only light up while plugged in
                    side_rgb_set_color(left, 0, 0, 0);
                }
            } else {
                side_rgb_set_color(right, 0, 0, 0);
                side_rgb_set_color(left , 0, 0, 0);
            }
        }
    }
    else {  // if battery display disabled, turn off all side LEDs
        for (uint8_t led=0; led < (2*NUM_SIDE_LEDS); led ++) {
            side_rgb_set_color(led, 0, 0, 0);
        }
    }
}

