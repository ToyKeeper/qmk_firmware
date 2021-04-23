// config.h for ToyKeeper's Whitefox layout

// QMK tap-hold behavior doesn't work well for quick actions, so try to fix it
// Example 1:
//   - tapping term is 200ms
//   - two keys next to each other are;
//     - Fn/Home: LT(3,KC_HOME)
//     - Tilde/Paste: KC_GRV on base layer, LSFT(KC_INS) on layer 3
//   - quickly press and release both in under 200ms:
//     - press Fn
//     - press Tilde
//     - release both keys; order can vary
//   - desired result: Paste (Shift+Insert)
//   - actual result: varies
//     - Sometimes does a Paste as desired
//     - Sometimes types Grave and then Home
//     - Sometimes types Home and then Grave
//     - Sometimes does a Paste and Home
// Example 2:
//   - one key is Fn (TT(2)) and another is Space
//   - in layer 2, the Space is Play
//   - quickly (in less than 200ms) press Fn and Space to toggle music
//     - press Fn
//     - press Space
//     - release both keys, in arbitrary order
//   - desired result: the Play key event is pressed and released once
//   - actual result:
//     - Sometimes presses/releases Play once, as expected.
//     - Sometimes inserts a Space.
//     - Sometimes presses Play and releases Space, so the Play key sticks.
//       (and music stutters)
//
// So try to avoid that without losing the ability to overload mod/layer keys.
//
// meh, the docs say permissive hold is the answer,
// but it doesn't seem to help at all  :(
//#define PERMISSIVE_HOLD
//#define IGNORE_MOD_TAP_INTERRUPT
//
// this works, but causes other issues:
// - TT(layer) doesn't work
// - Space Cadet shift keys don't work
// - can't press+release an overloaded key without sending the "tap" version
//#define RETRO_TAPPING
#undef  TAPPING_TERM
//#define TAPPING_TERM 1  // default 200
// meh, use MO(layer) instead of the fancy stuff,
// and set a longer tap time so Space Cadet can work
#define TAPPING_TERM 150  // default 200

///// make the mouse more usable /////
// Delay between pressing a movement key and cursor movement
#undef  MOUSEKEY_DELAY
#define MOUSEKEY_DELAY	250  // default 300
// Time between cursor movements in milliseconds
#undef  MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL	16  // default 50
// Step size
#undef  MOUSEKEY_MOVE_DELTA
#define MOUSEKEY_MOVE_DELTA	2  // default 5
// Maximum cursor speed at which acceleration stops
#undef  MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED	32  // default 10
// Time until maximum cursor speed is reached
#undef  MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX	50  // default 20
// Delay between pressing a wheel key and wheel movement
#undef  MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY	250  // default 300
// Time between wheel movements
#undef  MOUSEKEY_WHEEL_INTERVAL
#define MOUSEKEY_WHEEL_INTERVAL	40  // default 100
// Maximum number of scroll steps per scroll action
#undef  MOUSEKEY_WHEEL_MAX_SPEED
#define MOUSEKEY_WHEEL_MAX_SPEED	8  // default 8
// Time until maximum scroll speed is reached
#undef  MOUSEKEY_WHEEL_TIME_TO_MAX
#define MOUSEKEY_WHEEL_TIME_TO_MAX	64  // default 40
