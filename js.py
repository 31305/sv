#!/usr/bin/env python3
import sys
from os import system
if len(sys.argv)<2:
    print('!')
else:
    system('cp 5.html '+sys.argv[1]+'/index.html')
    system('cp sv.wasm '+sys.argv[1])
    system('cp sv*js '+sys.argv[1])
    system('cp sks.js '+sys.argv[1])
