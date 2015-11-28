#!/bin/sh

# This one-liner only could run on macosx. Maybe.

while true; do banner -w 100 HappyBirthday | sed -e 's/ /_/g' | while read l; do printf $l; for i in $(seq `echo $l | wc -c | xargs -I{} echo '100 - ' {} | bc`); do printf "_"; done; sleep 0.01; echo ""; done; done
