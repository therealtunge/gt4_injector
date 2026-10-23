#include "filedevice.h"
#include "scestructs.h"
#include <stddef.h>

#define ADDR_PlayStation2_FileDeviceRo_openStream 0x6D9694
#define ADDR_PlayStation2_FileDeviceRo2_GetFileEntry 0x6D96E4
#define ADDR_PlayStation2_FileDeviceRo2_readStat 0x6D96CC
#define ADDR_PDISTD_FileDevice_readStream 0x6D96A4
#define ADDR_PlayStation2_FileDeviceRo_rawReadStream 0x466288
#define ADDR_PlayStation2_FileDeviceRo_closeStream 0x6D968C
#define ADDR_PlayStation2_FileDeviceRo2_IOControlStream 0x4665C0
#define ADDR_PlayStation2_FileDeviceRo_pipe 0x466CB0
#define ADDR_PDISTD_FileInternalStream_ioctl 0x464CD0
#define ADDR_PDISTD_FileInternalStream_getDevice 0x464D28
#define ADDR_sceStdioConvertError 0x5E5AF0
#define ADDR_PageManager_GetEntryForFile 0x4613C0
#define ADDR_PlaystationX_LockFileName 0x467060
#define ADDR_PlayStationX_UnlockFileName 0x467080
#define ADDR_strcmp 0x510F40
#define ADDR_sceGetStat 0x5E0F20
#define ADDR_sprintf 0x50F1D8
#define ADDR_sceRead 0x5DF980
#define ADDR_UnitArenaBase_free 0x5285B0
#define ADDR_UnitArenaBase_allocate 0x528580
#define ADDR_sceOpen 0x5DF338
#define ADDR_sceClose 0x5DF5C8
#define ADDR_PDISTD_FileDevice_setExpander 0x462FD0
#define ADDR_PDISTD_FileDevice_removeExpander 0x463020
#define ADDR_print 0x50F120

#define SCE_RDONLY      0x0001
void (*_print)(const char* format, ...) = (void*)ADDR_print;

char* (*PlaystationX_LockFileName)(unsigned int nameHandle) = (void*)ADDR_PlaystationX_LockFileName;
void (*PlayStationX_UnlockFileName)(unsigned int nameHandle) = (void*)ADDR_PlayStationX_UnlockFileName;
int (*__strcmp)(const char* left, const char* right) = (void*)ADDR_strcmp;
int (*sceGetStat)(const char* name, struct sce_stat *buf) = (void*)ADDR_sceGetStat;
void (*PageManager_GetEntryForFile)(VolumeEntryTypeInfo* retEntry, PageManager* manager, char* fileName) = (void*)ADDR_PageManager_GetEntryForFile;
int (*sceStdioConvertError)(int func, int ioerror) = (void*)ADDR_sceStdioConvertError;
int HOOK_HostFs__PlayStation2_FileDeviceRo_rawReadStream(FileDeviceRo* device, FileInternalStream *stream, MemorySpace* memSpace);
void (*PDISTD_FileDevice_setExpander)(void* device, FileInternalStream *stream) = (void*)ADDR_PDISTD_FileDevice_setExpander;
void (*PDISTD_FileDevice_removeExpander)(void* device, FileInternalStream *stream) = (void*)ADDR_PDISTD_FileDevice_removeExpander;
int HandleHostFsOpen(FileDeviceRo* device, FileInternalStream* stream, char* fileName, FileObject* fileObj);
void* (*UnitArenaBase_allocate)(UnitArena* ptr) = (void*)ADDR_UnitArenaBase_allocate;
int (*sceRead)(int fd, void* buf, int count) = (void*)ADDR_sceRead;
void* (*UnitArenaBase_free)(void*, UnitArena* ptr) = (void*)ADDR_UnitArenaBase_free;
int (*sceOpen)(const char* name, int flags) = (void*)ADDR_sceOpen;
int (*sceClose)(int fd) = (void*)ADDR_sceClose;
static const char HOST_DIR[] = "vol_extract";
void (*_sprintf)(char* dest, const char* format, ...) = (void*)ADDR_sprintf;

void HostFs_InstallHooks();
void __start() {
	HostFs_InstallHooks();
	__asm__ volatile (
		"j 0x1001fc;\t\n"
	);
	return;
}


char *strrchr (char *s, int c)
{
	char *rtnval = 0;

	do {
		if (*s == c)
			rtnval = (char*) s;
	} while (*s++);
	return (rtnval);
}

char *get_filename_ext(char *filename) {
	char *dot = strrchr(filename, '.');
	if(!dot || dot == filename) return NULL;
	return dot + 1;
}

bool starts_with(char *restrict string, char* prefix)
{
	while(*prefix)
	{
		if(*prefix++ != *string++)
			return false;
	}

	return true;
}

bool IsStreamedFile(char* fileName)
{
	if (starts_with(fileName, "carsound/"))
		return true;

	char* ext = get_filename_ext(fileName);
	return ext != NULL && (!__strcmp(ext, "ins") || !__strcmp(ext, "ads") || !__strcmp(ext, "sqt") || !__strcmp(ext, "es") || !__strcmp(ext, "pss"));
}
void MAKE_JMP(unsigned int addr, void* func)
{
	*(int*)addr = (0x08000000 | (((unsigned int)(func) & 0x0FFFFFFC) >> 2));
}

void PATCH_INT(unsigned int addr, int data)
{
	*(int*)(addr) = data;
}

void NOP(unsigned int addr)
{
	PATCH_INT(addr, 0);
}

void HOOK(unsigned int func_start_addr, void* func)
{
	MAKE_JMP(func_start_addr, func);
	NOP(func_start_addr + 4); // Avoid cases where branch delay slot screw the stack up
}

void HOOK_FUNC_ADDR(void* func_start_addr, void* func)
{
	*((int*)func_start_addr) = (int)func;
}

int HOOK_HostFs__PDISTD_FileDevice_readStream(FileDevice* device, FileInternalStream* stream, MemorySpace* memSpace, int expand)
{
	char* fileName = PlaystationX_LockFileName(stream->FileObject->FileNameHandle);
	bool isStreamedFile = IsStreamedFile(fileName);

#if HOSTFS_PRINT && PRINT_HOSTFS_READS
	_print("FileDeviceRo::readStream: %s\n", fileName);
#endif

	PlayStationX_UnlockFileName(stream->FileObject->FileNameHandle);

	int ret = 0;

	// Read from vol, fix hook
	if (isStreamedFile)
	{
		*(int*)ADDR_PlayStation2_FileDeviceRo_rawReadStream = 0x27BDFFB0;
		*((int*)ADDR_PlayStation2_FileDeviceRo_rawReadStream + 1) = 0xFFB70038;
	}

	if (expand)
	{
		ret = device->VTable->rawReadStream(device, stream, memSpace);
	}
	else
	{
		
		ret = device->VTable->rawReadStream(device, stream, memSpace);
	}

	HOOK(ADDR_PlayStation2_FileDeviceRo_rawReadStream, HOOK_HostFs__PlayStation2_FileDeviceRo_rawReadStream);

	return ret;
}

// Guessed function name
bool HOOK_HostFs__PlayStation2_FileDeviceRo2_GetFileEntry(FileDeviceRo2* device, FileStatus* status, char* fileName)
{
	if (IsStreamedFile(fileName))
	{
		VolumeEntryTypeInfo volFile = {0};

		PageManager* pageManager = &device->PageManager;
		PageManager_GetEntryForFile(&volFile, pageManager, fileName);

		if (volFile.Status >= 0)
		{
			status->Status = FileError_OK;
			status->Compressed = (volFile.EntryType >> 1) & 1;
			status->RealSize = volFile.RealSize;
			status->CompressedSize = volFile.CompressedSize;
			status->DataOffset = device->Ro.TocOffset
				   + *(int*)(pageManager->HeaderBuffer + 0x0C)
				   + volFile.PageOffset;

#if HOSTFS_PRINT
			_print("GetVolumeFileInfo: pageManager compressed=%d, real_size=%x, comp_size=%x, data_offset=%x\n", 
				status->Compressed, status->RealSize, status->CompressedSize, status->DataOffset);
#endif

			return true;
		}
	}
	else
	{
		char path[128];
		_sprintf(path, "host:%s/%s", HOST_DIR, fileName);

		struct sce_stat stat = {0};
		int res = sceGetStat(path, &stat);

		int err = 0;
		err = sceStdioConvertError(0, res);

#if HOSTFS_PRINT
		_print("FileDeviceRo::GetFileEntry: sceGetStat name=%s, err=%x, st_size=%x\n", path, err, stat.st_size);
#endif

		if (res >= 0)
		{ 
			status->Status = FileError_OK;
			status->Compressed = false;
			status->CompressedSize = stat.st_size;
			status->RealSize = stat.st_size;
			return true;
		}
	}

	return false;
}

int HOOK_HostFs__PlayStation2_FileDeviceRo_openStream(FileDeviceRo* device, FileInternalStream *stream)
{
	int res = -1;

	FileObject* fileObj = stream->FileObject;
	int fileMode = fileObj->FileMode;

	// Lock name handle
	char* fileName = PlaystationX_LockFileName(fileObj->FileNameHandle);

#if HOSTFS_PRINT
	_print("FileDeviceRo::openStream: name=%s, mode=%d\n", fileName, fileMode);
#endif

	if (fileMode != 3)
	{
		if (fileMode > 0)
		{

		}
		else
		{
			FileStatus status = {0};

			// Do NOT load these files from host, they need to be put into IOP memory using IRX RPC, pain to deal with
			if (IsStreamedFile(fileName))
			{
				device->Pipe.Base.VTable->readStat(&status, &device->Pipe.Base, fileObj);
				fileObj->Status = status;

				if (fileObj->Status.Status)
					goto err;

				res = device->Pipe.Base.VTable->getCdOffsetFromDataOffset(device, fileName, status.DataOffset, status.CompressedSize);
			}
			else
			{
				res = HandleHostFsOpen(device, stream, fileName, fileObj);
			}
		}

		if (res)
		{
			// Expanders are what processes a file after it's been read
			// i.e decompressor/inflator.
			// FileDeviceRo's expander check if the stream's file object is compressed before doing anything
			PDISTD_FileDevice_setExpander(device, stream);

			// This is required for files that we force read from CDVD
			UnitArena* unit = UnitArenaBase_allocate((UnitArena*)(0x885340));
			// Actual disc sector offset likely goes here - calculated from 0x466C00 (FileDeviceRo2::GetSectorOffsetOfFileName?)
			unit->field_0x00 = res; 
			unit->Offset = 0;
			unit->field_0x08 = 0;
			unit->field_0x0C = UnitArenaBase_allocate((UnitArena*)(0x885360));
			stream->State = unit;
		}
		else
		{
			stream->Status = FileError_NOTFOUND;
		}
	}
	else
	{
		res = 0;
	}

err:
	// Release name handle
	PlayStationX_UnlockFileName(fileObj->FileNameHandle);
	return res;
}

int HandleHostFsOpen(FileDeviceRo* device, FileInternalStream* stream, char* fileName, FileObject* fileObj)
{
	// Start opening
	FileStatus status = {0};

	device->Pipe.Base.VTable->readStat(&status, (FileDevice*)device, fileObj);
	fileObj->Status = status;

	if (fileObj->Status.Status == FileError_OK)
	{
		char pathToFile[128];
		_sprintf(pathToFile, "host:%s/%s", HOST_DIR, fileName);

		int fd = sceOpen(pathToFile, SCE_RDONLY);

#if HOSTFS_PRINT
		_print("HandleHostFsOpen: name=%s, fd=%d\n", fileName, fd);
#endif
		if (fd >= 0)
		{
			// Reuse data offset field as a file descriptor lol
			fileObj->Status.DataOffset = fd;
			return 1; // Good
		}
	}
	else
	{
#if HOSTFS_PRINT
		_print("HandleHostFsOpen: Failed, status isn't OK\n");
#endif
	}

	return 0;
}

int HOOK_HostFs__PlayStation2_FileDeviceRo_rawReadStream(FileDeviceRo* device, FileInternalStream *stream, MemorySpace* memSpace)
{
	// Some notes: files read through hFileIO::read will read buffered 0x800 chunks.
	// This is the case for i.e projects/GT4Application.adc
	int toRead = memSpace->BufferSize;
	void* outputPtr = memSpace->BufferPtr;

	int currentOffset = stream->State->Offset;
	int fileLength = stream->FileObject->Status.RealSize;
	int rem = fileLength - currentOffset;

	if (toRead > rem)
		toRead = rem;

	int fd = stream->FileObject->Status.DataOffset;
	//sceLSeek(fd, currentOffset, SCE_SEEK_SET);

	int actuallyRead = sceRead(fd, outputPtr, toRead);

#if HOSTFS_PRINT && PRINT_HOSTFS_READS
	_print("FileDeviceRo::rawReadStream: fd=%d, req=%x, read=%x, offset=%x, data=%x\n", fd, toRead, actuallyRead, currentOffset, *(int*)outputPtr);
#endif

	// Update
	stream->State->Offset += actuallyRead;

	// Return number of bytes read. A few apis uses the return value
	return actuallyRead;
}

int HOOK_HostFs__PlayStation2_FileDeviceRo_closeStream(FileDeviceRo* device, FileInternalStream *stream)
{
	PDISTD_FileDevice_removeExpander(device, stream);
	if (stream->State)
	{
		if (stream->FileObject->FileMode == 1 && stream->State->field_0x08)
			 ((void(*)(int, void*, int))0x51B478)(stream->State->field_0x00, stream->State->field_0x0C, 0x40 - stream->State->field_0x08);
		((void(*)(int))0x51B4A8)(stream->State->field_0x00);
		UnitArenaBase_free((void*)0x885360, stream->State->field_0x0C);
		UnitArenaBase_free((void*)0x885340, stream->State);
		stream->State = NULL;
	}

#if HOSTFS_PRINT
		_print("FileDeviceRo::closeStream\n");
#endif

	if (stream->FileObject->Status.DataOffset == 0)
	{
		int res = sceClose(stream->FileObject->Status.DataOffset);
	}

	return 0;
}
void HostFs_InstallHooks()
{
	HOOK_FUNC_ADDR((void*)ADDR_PlayStation2_FileDeviceRo2_GetFileEntry, &HOOK_HostFs__PlayStation2_FileDeviceRo2_GetFileEntry);
	HOOK_FUNC_ADDR((void*)ADDR_PlayStation2_FileDeviceRo_openStream, &HOOK_HostFs__PlayStation2_FileDeviceRo_openStream);
	HOOK(ADDR_PlayStation2_FileDeviceRo_rawReadStream, HOOK_HostFs__PlayStation2_FileDeviceRo_rawReadStream);
	HOOK_FUNC_ADDR((void*)ADDR_PlayStation2_FileDeviceRo_closeStream, &HOOK_HostFs__PlayStation2_FileDeviceRo_closeStream);
	HOOK_FUNC_ADDR((void*)ADDR_PDISTD_FileDevice_readStream, &HOOK_HostFs__PDISTD_FileDevice_readStream);
	//HOOK(ADDR_PlayStation2_FileDeviceRo2_IOControlStream, HOOK_HostFs__PlayStation2_FileDeviceRo_IOControlStream);
	//HOOK(ADDR_PDISTD_FileInternalStream_ioctl, HOOK_HostFs__PDISTD_FileInternalStream_ioctl);
}
