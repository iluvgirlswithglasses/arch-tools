#!/bin/bash
shc -f ./dev/$1.sh
rm ./dev/$1.sh.x.c
mv ./dev/$1.sh.x ./$1