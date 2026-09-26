EE_BIN = main.elf
EE_OBJS = mainasm.o main.o
EE_FLATBIN = main.bin
EE_LIBS = -lc -ldebug
EE_DBGINFOFLAGS = 
EE_CFLAGS = --builtin -g0 #-fPIE -fPIC
EE_OPTFLAGS = -O3
EE_LINKFILE = stage0.link
EE_LDFLAGS = -Wl,--image-base,0x07F00000 -ffreestanding -nostartfiles

all: $(EE_FLATBIN)

clean:
	rm -f $(EE_BIN) $(EE_OBJS) $(EE_FLATBIN) out.o


include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.eeglobal
$(EE_FLATBIN): $(EE_BIN)
#	-Tstage0.link
	mips64r5900el-ps2-elf-ld --entry __start --nostdlib $(EE_OBJS) -o out.o --image-base 0x07F00000
	mips64r5900el-ps2-elf-objcopy out.o -R .mdebug.abiN32 -R .reginfo -R .comment -R .MIPS.abiflags -R .comment -R .pdr -R .gnu.attributes out.o

	mips64r5900el-ps2-elf-objcopy out.o  -O binary main.bin 
# -fPIE -shared
#	rm main.elf
#	mips64r5900el-ps2-elf-objcopy -v main.elf1 -O binary main.bin
#	mips64r5900el-ps2-elf-gcc $(EE_LDFLAGS) main.o -o main.bin -Wl,-b,binary $(EE_LIBS)