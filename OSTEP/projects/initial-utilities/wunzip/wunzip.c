#include <stdio.h>
#include <stdlib.h>

//USE fwrite() buffering instead of using realloc
void unzip(int n, char c){
    for (int i = 0; i<n; i++)
        fwrite(&c, sizeof(c), 1, stdout);
}

void process_file(FILE* file){
    int n;
    char c;

    while(fread(&n, sizeof(int), 1, file) == 1){
        fread(&c, sizeof(char), 1, file);
        unzip(n, c);
    }

}


int main(int argc, char* argv[]){
    if (argc < 2){
        printf("wunzip: file1 [file2 ...]\n");
        exit(1);
    }


    for (int i = 1; i < argc; i++){
        FILE* fptr = fopen(argv[i], "rb");
        if (!fptr){
            printf("wunzip: cannot open file\n");
            exit(1);
        }
        process_file(fptr);
        fclose(fptr);
    }
}
