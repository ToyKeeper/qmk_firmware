ToyKeeper's Nuphy Air75 v2 Layout
=================================

A relatively straightforward 75% layout with some extras.


## At A Glance

This is the layout internally, showing all the functions for each key:
![TK Air75 v2](https://toykeeper.net/keyboard/qmk/tk-air75v2.png)

This layout diagram can be edited [here](https://www.keyboard-layout-editor.com/#/gists/ab4bb8663c39104a248fe585cc217b3e).


## Core Features

Most of the features are shared by all my keymaps.  Check my
[user dir](../../../../../../users/toykeeper)
for the details.

Everything below is specific to this particular model of hardware.


## Hardware-Specific Notes

Things which differ from other models:

  * RGB Side LEDs
    * This hardware has two strips of LEDS near the top of the keyboard, one on
      the left side and one on the right side.  Each strip has 6 RGB LEDs
      underneath, but they're beneath a frosted optic which blurs the lights
      together.
    * The right side LEDs are near the power switch, so they're used to show if
      the power is on and how full the battery is.  The more full it gets, the
      taller the display, and the more of the rainbow it covers.  From empty to
      full, it goes red, yellow, green, cyan, blue, purple.  Red is at the
      bottom, with purple at the top.
    * The left side LEDs are near the charging port, so they're used to show
      charging status and how full the battery is.  Colors are the same, but
      red is at the top and purple is at the bottom.
    * The side LED power displays change in brightness depending on whether the
      device is currently plugged in, and whether it's actively charging.
    * The vendor's side LED functions sometimes override the power displays,
      like when it wants to indicate something about wireless status.

  * F1-F12 row
    * The user can choose whether the F1-F12 row emits normal keycodes or more
      fancy keycodes.  The default is "fancy" keycodes, but they can change
      this by pressing the F-Lock key.

  * Dipswitch (FIXME)
    * Two core layouts can be saved for easy access with the dipswitch.  Each
      dipswitch position is treat as a "save slot".  Any time the user changes
      the core layout via a hotkey, it is saved to the current slot.  Then it
      can be activated later simply by flipping the switch to that position.
      (Currently broken, so the layer-select dipswitch is disabled)


## Known Issues

  * The dipswitches don't use standard QMK APIs, so my usual dipswitch handler
    doesn't work.  I'm undecided about whether to fix this, because it's not
    very important.

  * MouseKeys are nearly unusable in wireless mode, for unknown reasons.  They
    trigger way too many times in a single keypress, and when held, they send
    events way too fast.  Hoping to fix this, because it's important to be able
    to use the mouse in wireless mode.


## More Pics


