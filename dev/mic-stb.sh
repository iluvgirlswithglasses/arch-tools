#!/bin/bash
VAL=19660;

if [[ $# -ne 1 ]]
then
	echo "Applying default fixed value: 30%";
else
	VAL=$(( $1 * 65536 / 100 ));
	echo "Applying fixed value: $1%";
fi

echo "Press Ctrl+C to exit";

while sleep 0.05; do 
	pacmd set-source-volume alsa_input.pci-0000_00_1f.3.analog-stereo $VAL; 
done