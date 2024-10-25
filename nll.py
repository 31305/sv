#!/usr/bin/env python3
import cairo
import os
import math
def sn(sn,k):
    return sn+str(k).zfill(4)+'.png'
def pk():
    ls=[]
    sls=bytearray(0)
    msn=''
    tsn='/tmp/d/p'
    cspn='30'
    gn=1.0
    ck=0.5
    os.system('mkdir -p '+tsn)
    tk=0
    pk=0
    for k in range(0,len(ls)):
        ss=0
        while pk<ls[k][0]:
            nc=cairo.ImageSurface.create_from_png(sn(msn,pk))
            if ss==0:
                ss=min(cspn*gn,ls[k][0]-pk)
                bm=1.0/ss
                cp=cairo.ImageSurface(cairo.Format.RGB24,nc.get_width(),nc.get_height())
                cps=cairo.Context(cp)
            cps.set_source_surface(nc)
            cps.paint_with_alpha(bm)
            ss-=1
            if ss==0:
                cp.write_to_png(sn(tsn,tk))
                tk+=1
            pk+=1
        sls+=bytearray(int(tk*44100/cspn)*4-len(sls))
        os.system('echo '+' '.join([str(l) for l in ls[k][1]])+' | ./sv 6 > /tmp/nssl')
        vs=open('/tmp/nssl',rb).read()
        sls+=vs
        ss=math.ceil(len(vs)/4/44100/ck)*ck*cspn
        nc=cairo.ImageSurface.create_from_png(sn(msn,pk))
        for ppk in range(0,ss):
            nc.write_to_png(sn(tsk,tk))
            tk+=1
        sls+=bytearray(int(tk*44100/cspn)*4-len(sls))
pk()
