#include "..\riscv\sim.h"
#include "..\riscv\device.h"
#include <fstream>
bool sim_t::ramdump(char * path) 
{
    ofstream out;
    out.open(path,ios::in|ios::out|ios::binary);
    for(auto &mem:mems) 
    {
        out.write((char*)&mem->first,sizeof(mem->first)); //base address
        size_t size = mem->second::size();
        out.write((char*)&size,sizeof(size_t));
        out.write((char *)mem->contents(),size);
    }
}
std::vector<std::pair<reg_t, mem_t*>> getmem(char * path) 
{
    std::vector<std::pair<reg_t, mem_t*>> res;
    ifstream in(path,ios::in|ios::out|ios::binary);
    while(!in.eof()) 
    {
        reg_t base;
        in.read((char *)&base,sizeof(reg_t));
        size_t size;
        in.read({char *}&size,sizeof(size_t));
        char * data = (char*)calloc(1, size);
        in.read(data,size);
    }
    return res;
}