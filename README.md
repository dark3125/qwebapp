QWebApp
=======

Fast and slick customizable minimalistic web browser used for making desktop launchers for web apps. Works on Linux, Windoze and Mac OS X.


What you need
=============
* Qt 5
* GNU GCC G++ (or MinGW GCC G++ for Windows) or any other compiler that works with this code
* GNU Make (or MinGW Make for Windows)
* Few seconds

Compiling on Linux
==================

    mkdir build
    cd build
    qmake ..
    make

Compiling on Mac OS X
=====================

    mkdir build
    cd build
    qmake -spec macx-g++ ..
    make

Compiling on Windows
====================

    md build
    cd build
    qmake ..
    make

Using QWebApp
=============
QWebApp accepts a total of 12 options, all of which can be listed with the `--help` option. The basic syntax 
is:

    qwebapp [options] URL

The options are pretty straightforward. All of them have at least two forms (the short one and the long 
one). Here they are:

`-h` | `--help` - Show help

`-v` | `--version` - Show program name and version

`-c` | `--controlbar` | `--ctlbar` | `--ctrlbar` - Enable control bar (history movement buttons and label)

`-l` | `--setlabel` | `--labeltext` | `--setlabeltext` <string> - Set label in control bar

`-t` | `--settitle` | `--titletext` | `--settitletext` <string> - Set window title

`-i` | `--icon` | `--seticon` <string> - Set window icon (from theme)

`-I` | `--fileicon` | `--setfileicon` <path> - Set window icon (from file [bitmap or vector])

`-x` | `--xsize` | `--sizex` <int> - Window width (in pixels)

`-y` | `--ysize` | `--sizey` <int> - Window height (in pixels)

`-C` | `--center` - Move window to the center of the desktop

`-X` | `--xpos` | `--posx` <int> - Window X coordinate on desktop (in pixels)

`-Y` | `--ypos` | `--posy` <int> - Window Y coordinate on desktop (in pixels)

Options `-C` and `-X` | `-Y` conflict with eachother. So does `-i` and `-I`. Setting the label has no effect 
without control bar.


Examples
========
Example invocation of QWebApp:

    qwebapp "http://google.pl" -t "Google" -I ~/google.png -x 400 -y 500 -C

Screenshot
==========
Here using QWebApp for a desktop-like YouTube experience:

![Example use case](https://cdn.mediacru.sh/MFbxRYy_uN7V.png)
