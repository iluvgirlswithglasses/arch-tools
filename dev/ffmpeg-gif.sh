#!/bin/bash

ffmpeg -i "$1" -vf "fps=25,scale=$2:-1:flags=lanczos,split[s0][s1];[s0]palettegen[p];[s1][p]paletteuse" -loop 0 o.gif
