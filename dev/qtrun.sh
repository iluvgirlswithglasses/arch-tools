#!/bin/bash

function run {
  if ! pgrep $1 ;
  then
    $@&
  fi
}

export QT_QPA_PLATFORMTHEME='qt5ct'
run $1

