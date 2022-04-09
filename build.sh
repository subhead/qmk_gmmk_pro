#!/usr/bin/env bash
set -x
cp -r /mnt/e/Dev/keyboards/qmk/keymaps/gmmk/pro/iso/keymaps/subhead /home/alex/qmk_firmware/keyboards/gmmk/pro/iso/keymaps
cp -r /mnt/e/Dev/keyboards/qmk/users/subhead /home/alex/qmk_firmware/users
cd /home/alex/qmk_firmware
pushd /home/alex/qmk_firmware
qmk clean
qmk compile
popd /home/alex/qmk_firmware
