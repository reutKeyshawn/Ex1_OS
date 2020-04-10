#include "hello_ariel.h"
#include <dlfcn.h>


int main(int argc, char const *argv[])
{

    void (*hello_ptr)();

    void *ariel_lib = dlopen("./lib_ariel.so", RTLD_NOW);
    hello_ptr = dlsym(ariel_lib, "hello");
    hello_ptr();
    dlclose(ariel_lib);
    
    return 0;
}
