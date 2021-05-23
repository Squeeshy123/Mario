import os


vsproj = 0
if 'vsproj' in ARGUMENTS:
    vsproj = bool(ARGUMENTS['vsproj'])

env = Environment()

env.Append(CPPPATH=['C:\\Users\\finnm\\Desktop\\CSCWork\\Libraries\\SDL\\include', '.\\src\\'])
env.Append(LIBPATH=['C:\\Users\\finnm\\Desktop\\CSCWork\\Libraries\\SDL\\lib'])
env.Append(LIBS=['SDL2', 'SDL2main', 'SDL2_image'])

env.Append(CXXVERSION='99')

walk = os.walk('.\\src')

cpps  = []
heads = []

for root, dirs, files in walk:
    path = root#.replace('\\', '\\\\')
    for f in files:
        if f.endswith(".cpp"):
            cpps.append(path + "\\" + f)
        elif f.endswith(".h") or f.endswith(".hpp"):
            heads.append(path + "\\" + f)
            
prog = env.Program(target='Mario', source=cpps)


if vsproj == 1:
    '''for i in range(len(cpps)-1):
        cpps[i] = cpps[i][2:]
    for i in range(len(cpps)-1):
        cpps[i] = cpps[i][2:]'''
    env.MSVSProject(target = "Mario" +  env['MSVSPROJECTSUFFIX'], srcs = cpps, incs = heads, buildtarget = prog, variant='Debug')
    print("Creating VS Project...")

print(cpps)
print(heads)