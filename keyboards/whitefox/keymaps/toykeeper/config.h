// config.h for ToyKeeper's Whitefox layout

// meh, this doesn't seem to help at all  :(
#define PERMISSIVE_HOLD
//#define RETRO_TAPPING
#define IGNORE_MOD_TAP_INTERRUPT
#undef  TAPPING_TERM
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
