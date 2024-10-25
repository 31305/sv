#!/usr/bin/env python3
import cairo
import os
def sn(sn,k):
    return str(k)
def pk():
    ls=[]
    msn=''
    tsn='/tmp/d/p'
    cspn='30'
    gn=1.0
    os.system('mkdir -p '+tsn)
    tk=0
    for k in range(0,len(ls)):
        ss=0
        for pk in range(0,ls[k][0]):
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
pk()
