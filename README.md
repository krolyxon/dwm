# My build of dwm (dynamic window manager)

## Patches applied
1. [xrdb](https://dwm.suckless.org/patches/xrdb/) patch for .Xresources support.
2. [fullgaps](https://dwm.suckless.org/patches/fullgaps/) patch for adding gaps between windows.
3. [scratchpad](https://dwm.suckless.org/patches/scratchpad/) patch for scratchpad
4. [bar height](https://dwm.suckless.org/patches/bar_height/) for changing bar's height
5. [pertag](https://dwm.suckless.org/patches/pertag/) for layout for each tag.
6. [layoutscroll](https://dwm.suckless.org/patches/layoutscroll/) for scrolling through layouts with ``mod+shift+tab``
7. [swallow](https://dwm.suckless.org/patches/swallow/) patch for swallowing windows (have reversed the patch right now.)

### MAKE SURE TO INSTALL ``libxft-bgra`` OR DWM WILL CRASH

## Keybinds
|keybinds|what it does|
|:-------|:-----------|
|``mod+enter``|open terminal(st)|
|``mod+shift+enter``|open scratchpad(st)|
|``mod+r``|open dmenu|
|``mod+shift+x``|kill window|
|``mod+Tab``|cycle through windows|
|``mod+b``|toggle statusbar|
|``mod+F5``|xrdb|
|``mod+h/l``|resize windows horizontally|
|``mod+f``|move the focused window to master|
|``mod+shift+r``|toggle window floating|
|``mod+t``|tile layout(default)|
|``mod+m``|monacle layout|
|``mod+e``|spiral layout|
|``mod+n``|dwindle layout|
|``mod+space``|floating mode|
|``mod+(+/-/=)``|increase/decrease/reset gaps|
|``mod+shit+q``|quit dwm|
