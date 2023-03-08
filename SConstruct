import os
import subprocess
e=Environment(COMPILATIONDB_USE_ABSPATH=True,CCFLAGS=['-g','-Wall'],LIBS='pthread')
js=type(ARGUMENTS.get('js'))==str
if js:
    os.environ['EMSCRIPTEN_ROOT']=os.path.dirname(subprocess.run(['which', 'emcc'],stdout=subprocess.PIPE).stdout.decode('utf-8'))
    e.Tool('emscripten',toolpath=[os.environ['EMSCRIPTEN_TOOL_PATH']])
    e.Append(CCFLAGS=['-sUSE_SDL=2','-MJcompile_commands.json'])
#    e.Append(CLAGS=['-sUSE_SDL=2'])
else:
    e.ParseConfig('pkg-config --cflags --libs x11 sdl2')
    e.Append(CCFLAGS=['-DKG'])
    e.Tool('compilation_db')
    e.CompilationDatabase()
print(e)
e.Program('sv',['sv.cpp','Log.cpp'])
