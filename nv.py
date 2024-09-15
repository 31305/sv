#!/usr/bin/env python3
import librosa
import sys
import os
import numpy
from matplotlib import pyplot
import matplotlib
os.system('mkdir -p /tmp/nvtsl/')
def nk(pn,dn):
    p,pg=librosa.load(pn)
    d,dg=librosa.load(dn)
    pl=librosa.feature.mfcc(y=p,sr=pg)
    dl=librosa.feature.mfcc(y=d,sr=dg)
    n,l=librosa.sequence.dtw(X=pl,Y=dl,band_rad=1)
    c=pyplot.figure(figsize=(16,8))
    pyplot.subplot(2,1,1)
    librosa.display.waveshow(p,sr=pg)
    pyplot.title('p')
    pt=pyplot.gca()
    pyplot.subplot(2,1,2)
    librosa.display.waveshow(d,sr=dg)
    pyplot.title('d')
    dt=pyplot.gca()
    pyplot.tight_layout()
    vkc=c.transFigure.inverted()
    rs=[]
    bs=numpy.int16(numpy.round(numpy.linspace(0,l.shape[0]-1,30)))
    for pb,db in l[bs]*512/pg:
        ps=vkc.transform(pt.transData.transform([pb,0]))
        ds=vkc.transform(dt.transData.transform([db,0]))
        rs.append(matplotlib.lines.Line2D((ps[0],ds[0]),(ps[1],ds[1]),transform=c.transFigure,color='r'))
    c.lines=rs
    pyplot.tight_layout()
    pyplot.show()
    return l
if __name__=="__main__":
    nk(sys.argv[1],sys.argv[2])
