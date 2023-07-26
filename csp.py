#!/usr/bin/env python3
import math
dtnt=0
for k in range(760,1080):
    ntk=1
    ntks=0
    for pk in range(28,33):
        km=(k%(pk*8))/k
        if km<ntk:
            ntk=km
            ntks=pk
    print(k,ntks,ntk,math.floor(k/(ntks*8)))
    if ntk>dtnt:
        dtnt=ntk
print("\n"+str(dtnt))
