/* ToyKeeper's Nuphy Air75 v2 QMK keymap
 * Copyright 2025 Selene ToyKeeper
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// TODO:
// * try jincao1's fork
//   - LINK_TO: link timeout toggle between short and long (saved in eeprom)
//   + KB_SLP: sleep timeout toggle between short and long (this boot only)
//   S DB_TOGG: toggle QMK Debug Mode
//   - led_power_handle() needs to allow my indicators
//   - add tenths + ones display for battery level
//   * fix or disable the dipswitch (fixed)
//   F figure out how to get actual battery voltage, and display that
//     (it seems the proprietary RF chip measures battery voltage,
//      and doesn't share that info with QMK ... it only shares a "percent")
//   - enter sleep mode sooner by default
//   * fade the top LED in the side strip along with battery level
//     (for higher display resolution and smoother animations)
//   * reduce brightness of Moon/Star layers, and maybe others
//     (to reduce battery use)
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
    KC_CAPS,       RGB_HUI, RGB_SAI, RGB_VAI, _______, TK_IUUI, _______, SIDE_HUI,SIDE_VAD,SIDE_VAI, _______, _______,         TK_BAT ,    KC_WSCH,
    TK_DF_3,          RGB_MOD, RGB_SPI, _______, _______, _______, NK_TOGG, SIDE_MOD,SIDE_SPI,KB_SLP , SLEEP_MODE,   _______,     KC_PGUP, KC_MYCM,
    TK_DF_0,  TK_DF_1,  TK_DF_2,                          TK_RGBT,                            KC_APP , _______, _______, KC_HOME, KC_PGDN, KC_END
    ),

};

// highlight color for each layer while active
// (would use the defaults, but they're a bit bright on this board,
//  so I dimmed it to reduce battery use)
const uint8_t layer_colors[][3] = {
    [L_QWERTY  ] = {  0,  0,  0},
    [L_DVORAK  ] = {  0,  0,  0},
    [L_UNDVORAK] = {  0,  0,  0},
    [L_COLEMAK ] = {  0,  0,  0},
    #ifdef USE_NUMPAD
    [L_NUMPAD  ] = {128,  0,  0},
    #endif
    #ifdef HAS_F_ROW
    [L_FLCK    ] = { 50, 10,  0},  // yellow
    #endif
    [L_MOUSE   ] = {128,  0,  8},  // bubble gum pink
    [L_FN1     ] = {128,  0, 40},  // neon purple-ish
    [L_FN2     ] = {  0, 30, 15},  // teal
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


// import these from vendor's keyboard code
extern DEV_INFO_STRUCT dev_info;
uint8_t bat_px = 100;
void side_rgb_set_color(int index, uint8_t red, uint8_t green, uint8_t blue);

bool update_bat_pct_user(uint8_t bat_percent) {
    uint8_t plugged_in = !(!(dev_info.rf_charge & 0x01));
    uint8_t charging_now = !(!(dev_info.rf_charge & 0x02));
    // percent value is either 0 or 100 when plugged in,
    // and both are useless... so don't update it
    if (plugged_in) {
        if (charging_now) {
            // do a "filling up" animation
            bat_px = (bat_px + 1) % 100;
        } else {
            bat_px = 100;
        }
    } else {
        bat_px = bat_percent;
    }
    nuphy_indicators_user();
    return true;  // allow kb bat_pct stuff to run too
}

// divide value but don't reduce it below 1 if it wasn't already
// result = value * (current - bottom) / (top - bottom)
uint8_t dim(uint8_t value, uint8_t current, uint8_t top, uint8_t bottom) {
    uint8_t min = !(!(value));  // don't reduce non-zero inputs to zero
    value = (uint16_t)value * (current - bottom) / (top - bottom);
    return value ? value : min;
}

// show battery and charge state on side LEDs and number keys
void nuphy_indicators_user(void) {
    // display battery status on number keys and side LEDs
    static uint8_t bat_percent = 0;
    //bat_percent = dev_info.rf_battery;
    bat_percent = bat_px;
    uint8_t plugged_in = !(!(dev_info.rf_charge & 0x01));
    uint8_t charging_now = !(!(dev_info.rf_charge & 0x02));
    uint8_t bat_colors[][3] = {
        // r,   g,   b
        { 255,   0,   0 },  // 0-9
        { 255,  20,   0 },  // 10-19
        { 255,  60,   0 },  // 20-29
        { 255, 128,   0 },  // 30-39
        {   0, 255,   0 },  // 40-49
        {   0, 255,  96 },  // 50-59
        {   0, 255, 255 },  // 60-69
        {   0,  96, 255 },  // 70-79
        {   0,   0, 255 },  // 80-89
        { 255,   0,  80 },  // 90-100
    };
    uint8_t bat_fkey[][4] = {
        // px, key,  color
        //{   0,  0,  0 },  // Esc
        {  10,  1,  0 },  // F1
        {  20,  2,  1 },  // F2
        {  30,  3,  2 },  // F3
        {  40,  4,  3 },  // F4
        {  50,  5,  4 },  // F5
        {  60,  6,  5 },  // F6
        {  70,  7,  6 },  // F7
        {  80,  8,  7 },  // F8
        {  90,  9,  8 },  // F9
        { 100, 10,  9 },  // F10
    };
    uint8_t bat_numkey[][5] = {
        // px, key,  color
        {  1, 29,  0 },  // 1
        {  2, 28,  1 },  // 2
        {  3, 27,  2 },  // 3
        {  4, 26,  3 },  // 4
        {  5, 25,  4 },  // 5
        {  6, 24,  5 },  // 6
        {  7, 23,  6 },  // 7
        {  8, 22,  7 },  // 8
        {  9, 21,  8 },  // 9
        {  0, 20,  9 },  // 0
    };
    // ensure RGB is on when needed
    if (tk_bat_momentary || user_config.bat_show) {
        // TODO: test this
        pwr_rgb_led_on();
    }

    // display battery percent on F1-F10 keys (tens digit) and 0-9 keys (ones digit)
    // while the user is holding the TK_BNOW key
    if (tk_bat_momentary) {
        uint8_t ones = bat_percent % 10;
        uint8_t px, key, color, r, g, b;
        // Esc + F1-F10 row for tens digit
        for (uint8_t i=0; i<10; i++) {
            px    = bat_fkey[i][0];
            key   = bat_fkey[i][1];
            color = bat_fkey[i][2];
            r     = bat_colors[color][0];
            g     = bat_colors[color][1];
            b     = bat_colors[color][2];
            if (bat_percent >= px) rgb_matrix_set_color(key, r, g, b);
            else rgb_matrix_set_color(key, 0, 0, 0);
        }
        // 1-0 row for ones digit
        for (uint8_t i=0; i<10; i++) {
            px    = bat_numkey[i][0];
            key   = bat_numkey[i][1];
            color = bat_numkey[i][2];
            r     = bat_colors[color][0];
            g     = bat_colors[color][1];
            b     = bat_colors[color][2];
            if (ones == px) rgb_matrix_set_color(key, r, g, b);
            else rgb_matrix_set_color(key, 0, 0, 0);
        }
    }
    // side LEDs are 2 sets of 6, numbered 0 to 11
    // and they go from bottom left to top left, then top right to bottom right
    // 0 to 5 on the left going up, then 6 to 11 on the right going down
    #define NUM_SIDE_LEDS  6
    // reduce brightness of side LEDs by this many powers of two:
    #define RS_DIM  (5 - plugged_in - charging_now - tk_bat_momentary)  // brighter while plugged in and charging
    #define LS_DIM  (3 - (2*charging_now))
    if (user_config.bat_show) {
        // kb driver ">> 2"s these, so usable values go from 4 to 255, plus 0
        // values 1,2,3 become 0
        // (but it seems like values 4-7 don't actually light up, so maybe 8 is the true minimum?)
        uint8_t side_bat[][4] = {
            // px,  r, g, b
            { 1,  255,   0,   0},  // low bat: red
            {17,  255, 128,   0},  // orange or yellow
            {33,    0, 255,   0},  // green
            {50,    0, 255, 255},  // cyan
            {67,    0,   0, 255},  // blue
            {83,  255,   0,  64},  // full bat: purple (mostly red, since it blends with blue LED next to it)
            {101, 255, 255, 255},  // should never light up; used only for next_px
        };
        for (uint8_t led = 0; led < NUM_SIDE_LEDS; led ++) {
            uint8_t left = 5 - led;  // top to bottom rainbow
            uint8_t right = 11 - led;  // bottom to top rainbow
            uint8_t px = side_bat[led][0];
            uint8_t next_px = side_bat[led+1][0];
            uint8_t r = side_bat[led][1];
            uint8_t g = side_bat[led][2];
            uint8_t b = side_bat[led][3];
            if (bat_percent >= px) {
                // dim the final active LED based on how full it is
                if (bat_percent < next_px) {
                    r = dim(r, bat_percent, next_px, px);
                    g = dim(g, bat_percent, next_px, px);
                    b = dim(b, bat_percent, next_px, px);
                }
                // right side: bottom=red, top=blue/purple (battery fullness)
                side_rgb_set_color(right, r >> RS_DIM, g >> RS_DIM, b >> RS_DIM);
                // left side: top=red, bottom=blue/purple (incoming power)
                if (plugged_in) {
                    side_rgb_set_color(left, r >> LS_DIM, g >> LS_DIM, b >> LS_DIM);
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

