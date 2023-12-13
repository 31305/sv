import os
import subprocess
import mesonbuild.mesonmain
import urllib.request
import shutil
e=Environment(COMPILATIONDB_USE_ABSPATH=True,CCFLAGS=['-g','-Wall','--std=c++20'],LIBS='pthread')
e.AppendENVPath('PATH',os.environ.get('PATH'))
js=type(ARGUMENTS.get('js'))==str
ss=['sv.cpp','Log.cpp']
if js:
    os.environ['EMSCRIPTEN_ROOT']=os.path.dirname(subprocess.run(['which', 'emcc'],stdout=subprocess.PIPE).stdout.decode('utf-8'))
    e.Tool('emscripten',toolpath=[os.environ['EMSCRIPTEN_TOOL_PATH']])
    e.Append(CCFLAGS=['-sUSE_SDL=2','-MJs.o.json','-Icairo/src','-Icairo/tp/src'])
    e.Append(LINKFLAGS=['--preload-file=sc.bmp','-sAUDIO_WORKLET=1','-sWASM_WORKERS=1','-sEXPORTED_RUNTIME_METHODS=ccall','-sWASM=1','-O3','-sUSE_SDL=2','-pthread'])
    st=e.Object('st.cpp')
    e.Depends(st,'cairo')
    ss+=[st,'cairo/tp/src/libcairo.a','cairo/tp/subprojects/pixman/pixman/libpixman-1.a']
else:
    e.ParseConfig('pkg-config --cflags --libs x11 sdl2 cairo')
    e.Append(CCFLAGS=['-DKG'])
    e.Tool('compilation_db')
    e.CompilationDatabase()
    ss+=['st.cpp']
sv=e.Program('sv',ss)
def f(target,source,env):
    l=open('s.o.json','r').read()
    open('compile_commands.json','w').write('['+l[0:len(l)-2]+']')
e.Depends(sv,'sc.bmp')
if js:
    AddPostAction('sv.o',f)
e.Command('sc.bmp','sc.png',"convert $SOURCE $TARGET")
e.Command('sc.png','ck.py',"python3 $SOURCE")
if False:e.Command('vcm.ico','cm.ico','convert $SOURCE -scale 300% $TARGET')
def pd(block_num, block_size, total_size):
    print(round(block_num * block_size / total_size *100,2), end="\r")
def hk(target,source,env):
    cks='1.18.0'
    urllib.request.urlretrieve("https://www.cairographics.org/releases/cairo-"+cks+".tar.xz","cairo.tar.xz",pd)
def cksk(target,source,env):
    os.system('tar xvf cairo.tar.xz')
    os.system('mv cairo-* cairo')
    mesonbuild.mesonmain.run(['setup','cairo','cairo/tp','--cross-file','jt']+'-Dbuildtype=release -Ddwrite=disabled -Dfontconfig=disabled -Dfreetype=disabled -Dglib=disabled -Dpng=disabled -Dquartz=disabled -Dspectre=disabled -Dsymbol-lookup=disabled -Dtee=disabled -Dtests=disabled -Dxcb=disabled -Dxlib=disabled -Dxlib-xcb=disabled -Dzlib=disabled -Ddefault_library=static'.split(),'meson')
    mesonbuild.mesonmain.run(["compile","-C",'cairo/tp'],"meson")
if js:
    e.Command('cairo','cairo.tar.xz',cksk)
    e.Command('cairo.tar.xz',None,hk)
