EE_BIN = main.elf
EE_OBJS = main.o
EE_FLATBIN = main.bin
EE_DBGINFOFLAGS = 
EE_CFLAGS = --builtin
EE_OPTFLAGS = -O0
EE_LINKFILE = stage0.link
EE_LDFLAGS = -Wl,--image-base,0x7f00000 -ffreestanding -nostartfiles -z max-page-size=16

all: $(EE_FLATBIN)

clean:
	rm -f $(EE_BIN) $(EE_OBJS) $(EE_FLATBIN) out.o


include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.eeglobal
$(EE_FLATBIN): $(EE_BIN)
	mips64r5900el-ps2-elf-ld --entry __start --nostdlib $(EE_OBJS) -o out.o --image-base 0x7f00000 -z max-page-size=16 -Tstage0.link
	mips64r5900el-ps2-elf-objcopy out.o -R .mdebug.abiN32 -R .reginfo -R .comment -R .MIPS.abiflags -R .comment -R .pdr -R .gnu.attributes out.o

	mips64r5900el-ps2-elf-objcopy out.o  -O binary main.bin 