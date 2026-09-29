#include "hostfs.h"
#include <stddef.h>

#define plugin_entry_addr 0x68a480


void HostFs_InstallHooks();

void (*plugin_entry)() = (void*)plugin_entry_addr;
void __start()
{
	HostFs_InstallHooks();
	plugin_entry();
}
