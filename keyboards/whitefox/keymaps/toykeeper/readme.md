ToyKeeper's Whitefox Layout
===========================

A relatively straightforward 65% "truefox" layout with some extras.

## At A Glance

This is how the layout looks with all layers combined into a single image:
![TK Whitefox](http://toykeeper.net/keyboard/qmk/full/tk-whitefox-2021-05-18.png)

This layout diagram can be edited [here](http://www.keyboard-layout-editor.com/#/gists/25056bbe508ab0bb45d8e9688c23a478).


## Core Keymaps

  * Qwerty
  * Dvorak
  * Un-dvorak (when connected to a computer which maps qwerty to dvorak
    in software, this makes it map back to qwerty again)

Between these three, it's possible to get both qwerty and dvorak, regardless of
which the host computer is configured for.  To switch layouts, hold Fn2 in the
upper-right corner and press one of these keys to select a layout:

  * Tab: Qwerty (qwerty on a qwerty host, or dvorak on a dvorak host)
  * Q: Un-dvorak (qwerty on a dvorak host)
  * Fn1: Dvorak (dvorak on a qwerty host)

Which one to press depends on how the host computer has the keys mapped.  I
normally have the host set up to convert qwerty to dvorak so I can type dvorak
on regular qwerty keyboards...  so the "qwerty" layer is actually dvorak, and
switching it back to qwerty requires the un-dvorak layer.  But for a normal
qwerty host, the qwerty layer would be qwerty, and the dvorak layer would be
dvorak.

Details of note:

  * The CapsLock key is Left Control.
  * Shift keys are Space Cadet style, so they produce parens when tapped.
  * Fn1 and Fn2 keys are in opposite corners, lower-left and upper-right.
  * Backspace and Backslash are swapped by default, but can be un-swapped.
  * The Esc key doubles as ` and ~
    * Tap normally for Esc
    * Shift+Esc for ~
    * Left GUI + Esc for `
    * Fn1+Esc produces a Shift-Esc event (handy for Chrome task manager)


## Extras

The Fn1 layer has a few interesting keys...

* Shift-Escape (for Chrome's task manager)
* F1-F12 keys
* Next / Prev / Play keys for media control
* Dynamic macro record/playback keys (2 sets, alpha / beta)
* Mouse buttons in lower left (helpful when using a touchpad), including a
  quick middle button for paste in X11
* Mouse movement/wheel/button keys on the right hand
* More mouse keys over the arrow region, for one-handed mousing
* Configure whether Backspace and Backslash are swapped

The Fn2 layer has some interesting stuff too...

* Lightning: Reset/reflash key for firmware updates
* F1-F12 along top row
* Insert and Shift+Insert keys (the latter is for pasting into terminals)
* Arrows replaced by common PageUp/PageDn/Home/End keys
* Three app launch keys on the right side
* Delete instead of Backspace
* Mouse keys on the left hand
* CapsLock, just in case
* Controls for switching the alpha layout between qwerty, dvorak, and un-dvorak ("QWERTY!")
* Right GUI and Menu keys


## Known Issues

Would like to overload Fn2 as Home, but I haven't found a way to
do that which doesn't cause timing issues when using it as Fn.  Similar story
for Fn1...  would like to make it lockable so the user can use mouse keys
without having to hold a Fn key, but TT(layer) causes timing issues when using
it momentary style.  So it uses regular momentary Fn keys instead.  They're not
as fancy, but they're not as fragile either.


## Changes

*2021-05-15*

* Merged in keymap changes from my nk65 layout.

*2021-04-22*

* Initial version.

