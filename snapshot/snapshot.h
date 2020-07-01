#ifndef SNAP_H
#define SNAP_H
#include "..\riscv\sim.h"
#include "..\riscv\device.h"
#include <fstream>
std::vector<std::pair<reg_t, mem_t*>> getmem(char * path);


#endif
