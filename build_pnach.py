import os
f = open("main.bin", "rb")
a = f.read()#
b = ""
try:
	os.remove("/home/behrad/Desktop/SCUS-97436_646B2E29.pnach")
except:
	pass
d = open("/home/behrad/Desktop/SCUS-97436_646B2E29.pnach", "a+")
for i in a:
	b += hex(i)[2:].zfill(2)
d.write(f"""
patch=0,EE,001001e8,bytes,0000fc0d
patch=0,EE,07F00000,bytes,{b}""") #291a0c20
f.close()
d.close()