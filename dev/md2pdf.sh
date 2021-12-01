#!/bin/bash
pandoc --pdf-engine=xelatex "$1.md" -o "$1.pdf"