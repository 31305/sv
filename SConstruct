import os
import subprocess
import urllib.request
import shutil
e=Environment(COMPILATIONDB_USE_ABSPATH=True,CCFLAGS=['-g','-Wall'],CXXFLAGS=['--std=c++20'],LIBS='pthread')
e.AppendENVPath('PATH',os.environ.get('PATH'))
js=type(ARGUMENTS.get('js'))==str
cp=type(ARGUMENTS.get('cp'))==str
if cp:
    import mesonbuild.mesonmain
ss=['sv.cpp','Log.cpp','libtmt/tmt.c']
if js:
    os.environ['EMSCRIPTEN_ROOT']=os.path.dirname(subprocess.run(['which', 'emcc'],stdout=subprocess.PIPE).stdout.decode('utf-8'))
    e.Tool('emscripten',toolpath=[os.environ['EMSCRIPTEN_TOOL_PATH']])
    e.Append(CCFLAGS=['-sUSE_SDL=2','-sUSE_SDL_IMAGE=2','-sUSE_SDL_TTF=2','-MJs.o.json']+(['-Icairo/src','-Icairo/tp/src','-DCP'] if cp else []))
    e.Append(LINKFLAGS=['-sAUDIO_WORKLET=1','-sWASM_WORKERS=1','-sEXPORTED_RUNTIME_METHODS=ccall,stringToNewUTF8,FS','-sWASM=1','-O3','-sUSE_SDL=2','-sUSE_SDL_IMAGE=2','-sUSE_SDL_TTF=2','-s','-pthread','--js-library=./tkps.js','--use-preload-plugins','--preload-file=ls','--preload-file=nstp','--preload-file=kv.ttf','-sPTHREAD_POOL_SIZE=4','-sEXPORTED_FUNCTIONS=_main,_malloc,_free'])
    st=e.Object('st.cpp')
    if cp:e.Depends(st,'cairo')
    ss+=[st]
    if cp:ss+=['cairo/tp/src/libcairo.a','cairo/tp/subprojects/pixman/pixman/libpixman-1.a']
else:
    e.ParseConfig('pkg-config --cflags --libs x11 sdl2 SDL2_image SDL2_ttf'+(' cairo' if cp else ''))
    e.Append(CCFLAGS=['-DKG']+(['-DCP'] if cp else []))
    e.Tool('compilation_db')
    e.CompilationDatabase()
    ss+=['st.cpp']
sv=e.Program('sv',ss)
def f(target,source,env):
    l=open('s.o.json','r').read()
    open('compile_commands.json','w').write('['+l[0:len(l)-2]+']')
if 0:e.Depends(sv,'pmc.jpg')
if js:
    AddPostAction('sv.o',f)
e.Command('sc.bmp','sc.png',"convert $SOURCE $TARGET")
e.Command('sc.png','ck.py',"python3 $SOURCE")
if False:e.Command('vcm.ico','cm.ico','convert $SOURCE -scale 300% $TARGET')
def pd(block_num, block_size, total_size):
    print(round(block_num*block_size/total_size,2),end="\r")
def hk(target,source,env):
    cks='1.18.0'
    urllib.request.urlretrieve("https://www.cairographics.org/releases/cairo-"+cks+".tar.xz","cairo.tar.xz",pd)
def cksk(target,source,env):
    os.system('tar xvf cairo.tar.xz')
    os.system('mv cairo-* cairo')
    mesonbuild.mesonmain.run(['setup','cairo','cairo/tp','--cross-file','jt']+'-Dbuildtype=release -Ddwrite=disabled -Dfontconfig=disabled -Dfreetype=disabled -Dglib=disabled -Dpng=disabled -Dquartz=disabled -Dspectre=disabled -Dsymbol-lookup=disabled -Dtee=disabled -Dtests=disabled -Dxcb=disabled -Dxlib=disabled -Dxlib-xcb=disabled -Dzlib=disabled -Ddefault_library=static'.split(),'meson')
    mesonbuild.mesonmain.run(["compile","-C",'cairo/tp'],"meson")
if js and cp:
    e.Command('cairo','cairo.tar.xz',cksk)
    e.Command('cairo.tar.xz',None,hk)
