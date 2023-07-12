#!/usr/bin/env python3
import math
dtnt=0
for k in range(math.floor(760/8),math.floor(1080/8)):
    ntk=1
    ntks=0
    for pk in range(28,33):
        km=(k%pk)/k
        if km<ntk:
            ntk=km
            ntks=pk
    print(k,ntks,ntk)
    if ntk>dtnt:
        dtnt=ntk
print("\n"+str(dtnt))
