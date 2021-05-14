import os

build_dir = './build'

VariantDir(build_dir, '.\\', duplicate=0)

env = Environment()

def check_dirs_and_scan(directory, srcs, heads):
	folder = os.walk(directory)
	for dirs, root, files in folder:
		#print(dirs)
		if len(dirs) < -1:
			if d != '.' and d != '/' and d != '\\':
				print("Scanning: " + d)

				temp_folder = check_dirs_and_scan(d, srcs, heads)

				srcs.extend(temp_folder[0])
				heads.extend(temp_folder[1])
	
		for f in files:
			
			if f.endswith(".cpp"):
				srcs.append(dirs+ "/" + f)
				print(dirs+ "/" + f)	
			elif f.endswith(".h"):
				heads.append(dirs+ "/" + f)
				print(dirs+ "/" + f)
	return (srcs, heads)

is_vs = False

if 'vsproj' in ARGUMENTS:
	is_vs = bool(ARGUMENTS['vsproj'])



env.Append(CPPPATH=[".\\","A:\Desktop\Programming\Engine\Mogue\Extra\include"])
env.Append(LIBPATH=['A:\Desktop\Programming\Engine\Mogue\Extra\libs'])
env.Append(LIBS=['SDL2.lib', 'SDL2main.lib', 'SDL2_image.lib'])


Export('env')

subdirs = ['.\\src']
objs = []


for subdir in subdirs:
    if os.path.isfile('.\\%s\\SConscript' % subdir):
        print("\nReading from: " + '.\\%s\\SConscript' % subdir)
        o = env.SConscript('.\\%s\\SConscript' % subdir)
        env.Install(build_dir, o)
        objs.extend(o)

main = env.Object('.\\src\\Mario.cpp')
objs.extend(main)

prog = None


if len(objs) > 0:
	prog = env.Program("Mario", objs)
else:
	print("No files found!")


	

if is_vs == 1:
	sources = []
	headers = []

	scan = []

	scan.append(check_dirs_and_scan('./src', sources, headers))
	scan.append(check_dirs_and_scan('./Libs', sources, headers))

	sources = scan[0][0] + scan[1][0]
	headers = scan[0][1] + scan[1][1]
	
	env.MSVSProject(target = "Mario" +  env['MSVSPROJECTSUFFIX'], srcs = sources, incs = headers, buildtarget = prog, variant='Debug')
	
	print(sources)
	print("")
	print(headers)
	print("Successfully Created visual studio project")