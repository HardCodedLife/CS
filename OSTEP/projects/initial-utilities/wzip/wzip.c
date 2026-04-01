#include <stdio.h>
#include <stdlib.h>

struct Unit{
    int n;
    char c;
};

void zip(struct Unit** units, size_t* units_size, FILE* fptr){
    int index = *units_size;

    int c = fgetc(fptr);
    while(c != EOF){
        if (!index || c != (*units)[index-1].c){
            *units = (struct Unit*) realloc(*units, sizeof(struct Unit)*(index+1));
            (*units)[index].n = 1;
            (*units)[index].c = c;
            index++;
        }
        else
            (*units)[index-1].n++;

        c = fgetc(fptr);
    }
    *units_size = index;
}

int main(int argc, char** argv){
    if (argc < 2){
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }

    struct Unit* units = NULL;
    size_t units_size = 0;
    for (int i = 1; i<argc; i++){
        FILE* fptr = fopen(argv[i], "r");
        if (!fptr){
            printf("wzip: cannot open file\n");
            exit(1);
        }
        zip(&units, &units_size, fptr);
        fclose(fptr);
    }

    // Can't write struct Unit out directly, since it is an 8-byte object.
    // printf("Size of Unit: %ld\n", sizeof(struct Unit));

    for(int i=0; i<units_size; i++){
        // Seeing the output of units
        // printf("<type Unit> with n:%d, c:%c\n", units->n, units->c);
        fwrite(&units[i].n, sizeof(int), 1, stdout); 
        fwrite(&units[i].c, sizeof(char), 1, stdout);
    }
    free(units);
}
