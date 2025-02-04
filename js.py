#!/usr/bin/env python3
import sys
from os import system
ls='rs'
system('mkdir -p '+ls)
system('cp 5.html '+ls)
system('cp sv.wasm '+ls)
system('cp sv*js '+ls)
system('cp sv.data '+ls)
system('cp ss.js '+ls)
system('cp dp.html '+ls)
system('cp pc.mp4 '+ls)
system('cp kc.mp4 '+ls)
system('cp cm.svg '+ls)
system('cp libv86.js '+ls)
system('cp v86.wasm '+ls)
system('cp seabios.bin '+ls)
system('cp linux4.iso '+ls)
system('cp tkps.js '+ls)
system('cp kv.ttf '+ls)
system('cp suncalc.js '+ls)
system('mkdir -p '+ls+'/node_modules')
system('cp -r node_modules/xterm-pty '+ls+'/node_modules')
