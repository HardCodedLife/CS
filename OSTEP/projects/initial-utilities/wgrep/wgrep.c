#include <stdlib.h>

int main(int argc, char* argv[]){
    if(argc < 2){
        printf("wgrep: searchterm [file...]\n");
        exit(1);
    }
    return 0;
}
