ToyKeeper's Nuphy Air75 v2 Layout
=================================

A relatively straightforward 75% layout with some extras.


## At A Glance

This is the layout internally, showing all the functions for each key:
![TK Air75 v2](https://toykeeper.net/keyboard/qmk/tk-air75v2.png)

This layout diagram can be edited [here](http://www.keyboard-layout-editor.com/#/gists/FIXME).


## Core Features

Most of the features are shared by all my keymaps.  Check my
[user dir](../../../../../../users/toykeeper)
for the details.

Everything below is specific to this particular model of hardware.


## Hardware-Specific Notes

Things which differ from other models:

  * F1-F12 row
    * The user can choose whether the F1-F12 row emits normal keycodes or more
      fancy keycodes.  The default is "fancy" keycodes, but they can change
      this by pressing the F-Lock key.

  * Dipswitch (FIXME)
    * Two core layouts can be saved for easy access with the dipswitch.  Each
      dipswitch position is treat as a "save slot".  Any time the user changes
      the core layout via a hotkey, it is saved to the current slot.  Then it
      can be activated later simply by flipping the switch to that position.


## Known Issues

  * The dipswitches don't use standard QMK APIs, so my usual dipswitch handler
    doesn't work.


## More Pics


