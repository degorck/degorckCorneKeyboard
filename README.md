# degorckCorneKeyboard
keymap for corne keyboard for degorck based on Soundmonster code
Generate json from C
qmk c2json -km degorck -kb crkbd/rev1 --no-cpp
qmk compile -kb crkbd/rev1 -km degorck
qmk flash -kb crkbd/rev1 -km degorck