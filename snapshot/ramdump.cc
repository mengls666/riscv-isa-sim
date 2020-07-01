#include "snapshot.h"
bool sim_t::ramdump(char * path) 
{
    ofstream out;
    char c = '$';
    out.open(path,ios::in|ios::out|ios::binary);
    for(auto &mem:mems) 
    {
        out.write((char*)&mem->first,sizeof(mem->first)); //base address
        size_t size = mem->second::size();
        out.write((char*)&size,sizeof(size_t));
        out.write((char *)mem->contents(),size);
        out.write((char* )&c,sizeof(char));
    }
    return true;
}
std::vector<std::pair<reg_t, mem_t*>> getmem(char * path) 
{
    std::vector<std::pair<reg_t, mem_t*>> res;
    ifstream in(path,ios::in|ios::out|ios::binary);
    char c;
    while(!in.eof()) 
    {
        reg_t base;
        in.read((char *)&base,sizeof(reg_t));
        size_t size;
        in.read((char *)&size,sizeof(size_t));
        char * data = (char*)calloc(1, size);
        in.read(data,size);
        in.read((char *)&c,sizeof(char));
        if(c != '$') {
            fprintf(stderr, "Illegal ramdump file:%s\n", path);
            res = std::vector<std::pair<reg_t, mem_t*>>();
            return res;
        }
    }
    return res;
}