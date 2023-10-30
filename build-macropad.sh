#!/usr/bin/env bash

set -x

rm -rf /home/alex/dev/keyboards/qmk/qmk_firmware/keyboards/keyboards/handwired/yaumpad/*
rm -rf /home/alex/dev/keyboards/qmk/qmk_firmware/users/subhead/*
cp -r /home/alex/dev/keyboards/qmk/keymaps/handwired/yaumpad /home/alex/dev/keyboards/qmk/qmk_firmware/keyboards/handwired/yaumpad
cp -r /home/alex/dev/keyboards/qmk/users/subhead /home/alex/dev/keyboards/qmk/qmk_firmware/users

cd /home/alex/dev/keyboards/qmk/qmk_firmware

#pushd /home/alex/dev/keyboards/qmk/qmk_firmware

qmk clean
qmk compile -j 2 -kb handwired/yaumpad -km default -e CONVERT_TO=promicro_rp2040

#popd
