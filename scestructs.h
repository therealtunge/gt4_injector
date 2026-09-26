#pragma once

struct sce_stat
{
	unsigned int st_mode;
	unsigned int st_size;
	unsigned char st_ctime[8];
	unsigned char st_atime[8];
	unsigned char st_mtime[8];
	unsigned int st_hisize;
	unsigned int st_private[6];
};
typedef struct
{
	unsigned char Resv2,Sec,Min,Hour;
	unsigned char Day,Month;
	unsigned short Year;
} sceMcStDateTime;

typedef struct
{
	sceMcStDateTime _Create;
	sceMcStDateTime _Modify;
	unsigned int FileSizeByte;
	unsigned short AttrFile;
	unsigned short Reserve1;
	unsigned int Reserve2;
	unsigned int PdaAplNo;
	unsigned char EntryName[32];
} sceMcTblGetDir __attribute__((aligned (64)));

#define SCE_RDONLY      0x0001
#define SCE_WRONLY      0x0002
#define SCE_RDWR        0x0003
#define SCE_NBLOCK      0x0010  /* Non-Blocking I/O */
#define SCE_APPEND      0x0100  /* append (writes guaranteed at the end) */
#define SCE_CREAT       0x0200  /* open with file create */
#define SCE_TRUNC       0x0400  /* open with truncation */
#define SCE_EXCL        0x0800  /* exclusive create */
#define SCE_NOBUF       0x4000  /* no device buffer and console interrupt */
#define SCE_NOWAIT      0x8000  /* asyncronous i/o */

#define SCE_SEEK_SET 0
#define SCE_SEEK_CUR 1
#define SCE_SEEK_END 2



#define ADDR_sceOpen 0x5DF338
#define ADDR_sceClose 0x5DF5C8
#define ADDR_sceRead 0x5DF980
#define ADDR_sceGetStat 0x5E0F20
#define ADDR_sceStdioConvertError 0x5E5AF0
#define ADDR_sceLSeek 0x5DF740

#define ADDR_PlaystationX_LockFileName 0x467060
#define ADDR_PlayStationX_UnlockFileName 0x467080


char* (*PlaystationX_LockFileName)(unsigned int nameHandle) = (void*)ADDR_PlaystationX_LockFileName;
void (*PlayStationX_UnlockFileName)(unsigned int nameHandle) = (void*)ADDR_PlayStationX_UnlockFileName;

static int (*sceOpen)(const char* name, int flags) = (void*)ADDR_sceOpen;
static int (*sceClose)(int fd) = (void*)ADDR_sceClose;
static int (*sceRead)(int fd, void* buf, int count) = (void*)ADDR_sceRead;
static int (*sceLSeek)(int fd, int offset, int whence) = (void*)ADDR_sceLSeek;
static int (*sceGetStat)(const char* name, struct sce_stat *buf) = (void*)ADDR_sceGetStat;
static int (*sceStdioConvertError)(int func, int ioerror) = (void*)ADDR_sceStdioConvertError;