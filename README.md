# My build of dwm (dynamic window manager)

## Patches applied
1. [xrdb](https://dwm.suckless.org/patches/xrdb/) patch for .Xresources support.
2. [fullgaps](https://dwm.suckless.org/patches/fullgaps/) patch for adding gaps between windows.
3. [scratchpad](https://dwm.suckless.org/patches/scratchpad/) patch for scratchpad
4. [bar height](https://dwm.suckless.org/patches/bar_height/) for changing bar's height
5. [pertag](https://dwm.suckless.org/patches/pertag/) for layout for each tag.
6. [layoutscroll](https://dwm.suckless.org/patches/layoutscroll/) for scrolling through layouts with <kbd>mod+shift+tab</kbd>
7. [swallow](https://dwm.suckless.org/patches/swallow/) patch for swallowing windows (have reversed the patch right now.)

## Keybinds
| keybinds                    | what they do                      |
|-----------------------------|-----------------------------------|
| <kbd>mod+enter</kbd>        | open terminal(st)                 |
| <kbd>mod+shift+enter</kbd>  | open scratchpad(st)               |
| <kbd>mod+r</kbd>            | open dmenu                        |
| <kbd>mod+shift+x</kbd>      | kill window                       |
| <kbd>mod+Tab</kbd>          | cycle through windows             |
| <kbd>mod+b</kbd>            | toggle statusbar                  |
| <kbd>mod+p</kbd>            | mpc toggle                        |
| <kbd>mod+comma</kbd>        | mpc seek -10                      |
| <kbd>mod+period</kbd>       | mpc seek +10                      |
| <kbd>mod+shift+period</kbd> | mpc prev                          |
| <kbd>mod+shift+period</kbd> | mpc next                          |
| <kbd>mod+F5</kbd>           | xrdb                              |
| <kbd>mod+h/l</kbd>          | resize windows horizontally       |
| <kbd>mod+space</kbd>        | move the focused window to master |
| <kbd>mod+f</kbd>            | toggle window fullscreen          |
| <kbd>mod+shift+r</kbd>      | toggle window floating            |
| <kbd>mod+t</kbd>            | tile layout(default)              |
| <kbd>mod+shift+u</kbd>      | monacle layout                    |
| <kbd>mod+y</kbd>            | spiral layout                     |
| <kbd>mod+shift+y</kbd>      | dwindle layout                    |
| <kbd>mod+shift+f</kbd>      | floating mode                     |
| <kbd>mod+(+/-/=)</kbd>      | increase/decrease/reset gaps      |
| <kbd>mod+shit+q</kbd>       | quit dwm                          |
