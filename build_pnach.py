import os
import sys
f = open("main.bin", "rb")
a = f.read()
b = ""

print("you must be using GT4 OPB (NTSC-U) or GT4 Spec II to use gt4_injector!")
pcsx2_folder = input("where is your PCSX2 cheats folder? (press enter to auto-detect)")
is_spec2 = input("are you using GT4 Spec2? [y/n]")

if is_spec2 == "y":
	is_spec2 = True
elif is_spec2 == "n":
	is_spec2 = False
else:
	print("please enter y/n")
	sys.exit(1)

if pcsx2_folder == "":
	if sys.platform == "linux":
		pcsx2_folder = "~/.config/PCSX2/cheats"
	elif sys.platform == "win32":
		pcsx2_folder = "%APPDATA%/../Documents/PCSX2/cheats" # cursed
	else:
		print("cant auto-detect folder")
		sys.exit(1)

if is_spec2:
	filename = f"{pcsx2_folder}/SCUS-97436_646B2E29.pnach"
else:
	filename = f"{pcsx2_folder}/SCUS-97436_32A1C752.pnach"
try:
	os.remove(filename)
except:
	pass
d = open(filename, "a+")
for i in a:
	b += hex(i)[2:].zfill(2)
d.write(f"""
patch=0,EE,001001e8,bytes,0000fc0d
patch=0,EE,07F00000,bytes,{b}""")
f.close()
d.close()