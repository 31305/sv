import os
import subprocess
nk=Builder(action='sh ck.sh < $SOURCE > $TARGET')
e=Environment(BUILDERS={'nl':nk},COMPILATIONDB_USE_ABSPATH=True,CCFLAGS=['-g','-Wall'],LIBS='pthread')
js=type(ARGUMENTS.get('js'))==str
ss=['sv.cpp','Log.cpp']
if js:
    os.environ['EMSCRIPTEN_ROOT']=os.path.dirname(subprocess.run(['which', 'emcc'],stdout=subprocess.PIPE).stdout.decode('utf-8'))
    e.Tool('emscripten',toolpath=[os.environ['EMSCRIPTEN_TOOL_PATH']])
    e.Append(CCFLAGS=['-sUSE_SDL=2','-MJs.o.json'])
    e.Append(LINKFLAGS=['--preload-file=sc.bmp','-sAUDIO_WORKLET=1','-sWASM_WORKERS=1','-sEXPORTED_RUNTIME_METHODS=ccall','-sWASM=1','-O3','-sUSE_SDL=2','-pthread'])
    ss+=['st.cpp']
else:
    e.ParseConfig('pkg-config --cflags --libs x11 sdl2')
    e.Append(CCFLAGS=['-DKG'])
    e.Tool('compilation_db')
    e.CompilationDatabase()
sv=e.Program('sv',ss)
def f(target,source,env):
    l=open('s.o.json','r').read()
    open('compile_commands.json','w').write('['+l[0:len(l)-2]+']')
if js:
    AddPostAction('sv.o',f)
    e.Depends(sv,'sc.bmp')
    e.Depends(sv,'vcm.ico')
e.Command('sc.bmp','sc.png',"convert $SOURCE $TARGET")
e.Command('sc.png','ck.sh',"sh $SOURCE")
e.Command('vcm.ico','cm.ico','convert $SOURCE -resize 48x48 $TARGET')
