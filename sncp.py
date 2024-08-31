import numpy
gs=[[-2,0],[2,0],[-1,-3]]
cs=[[-0.5,-1]]
def sg(s,d,l):
    p=numpy.array(s)
    d=numpy.array(d)
    p=p+l*(d-p)/numpy.linalg.norm(d-p)
    return p.tolist()
def ss(pp,pd,dp,dd):
    pp=numpy.array(pp)
    pd=numpy.array(pd)
    dp=numpy.array(dp)
    dd=numpy.array(dd)
    pds=pd-pp
    s=numpy.array([pds[1],-pds[0]])
    s=s/numpy.linalg.norm(s)
    return (dp+numpy.dot(pd-dp,s)*(dd-dp)/numpy.dot(dd-dp,s)).tolist()
cs+=[sg(cs[0],gs[0],0.5)]
cs+=[sg(cs[0],gs[2],0.6)]
cs+=[ss(cs[1],gs[2],cs[2],gs[0])]
cs+=[sg(cs[3],gs[1],0.7)]
cs+=[ss(cs[1],gs[1],cs[4],gs[2])]
cs+=[ss(cs[5],gs[0],cs[0],gs[1])]
cs+=[ss(cs[4],gs[0],cs[2],gs[1])]
cs+=[ss(cs[6],gs[2],cs[2],gs[1])]
print(cs)

    
     
