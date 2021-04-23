ToyKeeper's Whitefox Layout
===========================

A relatively straightforward 65% "truefox" layout with some extras.

I often have to use muggle keyboards, can't use nice custom ones all the time,
so I try to keep my layout reasonably similar to common models so I won't trip
over muscle memory all the time when I go back and forth.

For example, most keyboards don't have dvorak built in, so I usually map that
in the host OS instead of doing it in the keyboard firmware.  The dvorak mode
here is mostly for the times when I connect to a computer which hasn't already
been remapped in software.

* Standard Truefox / Happy Hacking layout...
  * Backspace area split into two keys: backslash/pipe and tilde/grave
  * Backspace on qwerty row instead of backslash
  * Escape where tilde/grave normally is
* CapsLock is Control
* Space Cadet Shift keys double as ( and ) keys
* Right edge is Fn2, PageUp, PageDn, End, RightArrow.  Because I press End more
  than Home.
  (many 65% layouts use Delete, Home, PageUp, PageDn, RightArrow)
* Ctrl next to arrows, since I use Ctrl-Arrows a lot to change desktops.
* Can switch between qwerty and dvorak.  Qwerty is default, even though I only
  really use dvorak... because I usually remap that in software.  Also because
  it's easier for non-enthusiasts.
* Fn1 and Fn2 keys in lower left and upper right corners.

The Fn layers provide some extras.  Both layers share some things in common...

* F1-F12 along top row
* Arrows replaced by common PageUp/PageDn/Home/End keys
* Three app launch keys on the right side
* Delete instead of Backspace

Things exclusive to the Fn1 layer are...

* Mouse keys on the right hand
* Mouse buttons on the left hand, for quick easy X11 paste
* Media player controls -- play/pause, next, prev
* Eject instead of Escape
* Two sets of macro record/playback keys

Fn2 exclusive functions are...

* A quick easy way to press Shift+Insert (for pasting text into a terminal)
* Left-handed mouse keys (might remove later)
* Access to a few more keys not included in other layers:
  * Insert
  * CapsLock key, in case you ever need it
  * Right GUI and Menu keys
  * Reset / reflash firmware key
* Configure keyboard settings:
  * Switch main layer between qwerty and dvorak
  * Toggle NKRO
  * Some keys are reserved for lighting controls, but aren't used in this
    layout because my Whitefox has no LEDs
  * Also leaves room for configuring features on other similar keyboards...
    like on a Massdrop Alt I'll add keys to swap BackSpace and BackSlash

## Layout Images

Qwerty layer:
![Qwerty layer](http://toykeeper.net/keyboard/qmk/tk-whitefox.2021-04-23a.l0.png)

Dvorak layer:
![Dvorak layer](http://toykeeper.net/keyboard/qmk/tk-whitefox.2021-04-23a.l1.png)

Fn1 layer:
![Fn1 layer](http://toykeeper.net/keyboard/qmk/tk-whitefox.2021-04-23a.l2.png)

Fn2 layer:
![Fn2 layer](http://toykeeper.net/keyboard/qmk/tk-whitefox.2021-04-23a.l3.png)

## Known Issues

Would like to overload Fn2 as Home, but I haven't found a way to do that which
doesn't cause timing issues when using it as Fn.  Similar story for Fn1...
would like to make it lockable so the user can use mouse keys without having to
hold a Fn key, but TT(layer) causes timing issues when using it momentary
style.  So it uses regular momentary Fn keys instead.  They're not as fancy,
but they're not as fragile either.

## Changes

*2021-04-22*

* Initial version.
