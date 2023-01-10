smk=True
e=Environment(COMPILATIONDB_USE_ABSPATH=True,CCFLAGS='-g -Wall')
e.ParseConfig('pkg-config --cflags --libs x11 sdl2')
if smk:
    e.Append(CCFLAGS=' -DSMK',LINKFLAGS=' -L./LPCNet/.libs',LIBS='lpcnet',RPATH='./LPCNet/.libs')
e.Tool('compilation_db')
e.CompilationDatabase()
e.Program('sv',['sv.cpp','Log.cpp'])
