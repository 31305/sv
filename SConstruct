import os
import subprocess
e=Environment(COMPILATIONDB_USE_ABSPATH=True,CCFLAGS=['-g','-Wall'],LIBS='pthread')
js=type(ARGUMENTS.get('js'))==str
if js:
    os.environ['EMSCRIPTEN_ROOT']=os.path.dirname(subprocess.run(['which', 'emcc'],stdout=subprocess.PIPE).stdout.decode('utf-8'))
    e.Tool('emscripten',toolpath=[os.environ['EMSCRIPTEN_TOOL_PATH']])
    e.Append(CCFLAGS=['-sUSE_SDL=2','-MJs.o.json'])
    e.Append(LINKFLAGS=['-sAUDIO_WORKLET=1','-sWASM_WORKERS=1','-sEXPORTED_RUNTIME_METHODS=ccall','-sWASM=1','-O3','-sUSE_SDL=2','-pthread'])
else:
    e.ParseConfig('pkg-config --cflags --libs x11 sdl2')
    e.Append(CCFLAGS=['-DKG'])
    e.Tool('compilation_db')
    e.CompilationDatabase()
sv=e.Program('sv',['sv.cpp','Log.cpp','st.cpp'])
def f(target,source,env):
    l=open('s.o.json','r').read()
    open('compile_commands.json','w').write('['+l[0:len(l)-2]+']')
if js:
    AddPostAction('sv.o',f)
