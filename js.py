#!/usr/bin/env python3
import sys
from os import system
ls='rs'
system('mkdir -p '+ls)
system('cp 5.html '+ls+'/index.html')
system('cp sv.wasm '+ls)
system('cp sv*js '+ls)
system('cp sv.data '+ls)
system('cp dp.html '+ls)
system('cp pc.mp4 '+ls)
system('cp cm.svg '+ls)
