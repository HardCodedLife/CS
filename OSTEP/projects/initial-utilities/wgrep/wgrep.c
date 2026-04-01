#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool helper_search(char haystack[], char needle[]){
    // Better approach
    return strstr(haystack, needle);

    /*
    while(*target){
        char* tmp = term;
        char* tg = target;
        while(*tmp == *tg && *tmp != '\0'){
            tmp++;
            tg++;
        }
        if (*tmp == '\0')
            return true;
        target++;
    }
    return false;
    */
}

void helper_file_search(FILE* fptr, char needle[]){
    char* buffer = NULL;
    size_t size;
    while(getline(&buffer, &size, fptr) != -1)
        if(helper_search(buffer, needle))
            printf("%s", buffer);

    free(buffer);
}


int main(int argc, char* argv[]){
    if(argc < 2){
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }
    else if(argc == 2){
        char buffer[512];
        while(fgets(buffer, 512, stdin)){
            if(helper_search(buffer, argv[1]))
                printf("%s", buffer);
        }
    }

    for(int i=2; i < argc; i++){
        FILE* fptr = fopen(argv[i], "r");
        if(!fptr){
            printf("wgrep: cannot open file\n");
            exit(1);
        }
        helper_file_search(fptr, argv[1]);
    }

    return 0;
}
