#include <stdio.h>
#include <wm.h>
#include <string.h>

int main(int argc, char** argv){
    if(argc > 1 && (strcmp(argv[1], "debug") == 0)){
        init_bspwm(DEBUG);
        return 0;
    }
    init_bspwm(NORMAL);
    return 0;
}