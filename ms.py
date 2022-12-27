#!/usr/bin/env python3
import pyworld
import struct
import math
import numpy
from os import system
lv=open('/tmp/lv','rb').read()
lv=struct.unpack('d'*math.floor(len(lv)/8),lv)
f,s,a=pyworld.wav2world(numpy.array(lv),44100)
ct=0
dk=10
def ctm(s):
    ct=0
    for k in range(0,len(s)):
        for pk in range(dk,len(s[k])):
            if abs(s[k][pk])>ct:
                ct=abs(s[k][pk])
    return ct
ct=ctm(s)
ns=1e10
nk=0
nsk=0
for md in numpy.arange(10,20,0.5):
    system('MD='+str(md)+' ./sv 4')
    v=open('/tmp/v','rb').read()
    v=struct.unpack('d'*math.floor(len(v)/8),v)
    f2,s2,a2=pyworld.wav2world(numpy.array(v),44100)
    ct2=ctm(s2)
    mk=math.floor(len(f2)/2)
    ts=1e10
    sk=0
    for k in range(0,len(s)):
        t=0
        for pk in range(dk,len(s[k])):
            t+=abs(s[k][pk]/ct-s2[mk][pk]/ct2)
        if t<ts:
            ts=t
            sk=k
        print(str(math.floor(t))+' ',end='')
    print()
    if ts<ns:
        ns=ts
        nk=md
        nsk=sk
print(nk,nsk/len(s))
