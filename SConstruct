e=Environment(COMPILATIONDB_USE_ABSPATH=True,CCFLAGS='-O2 -Wall')
e.ParseConfig('pkg-config --cflags --libs x11 sdl2')
e.Tool('compilation_db')
e.CompilationDatabase()
e.Program('sv',Glob('*.cpp'))
