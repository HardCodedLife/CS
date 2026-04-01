#include <stdio.h>
#include <stdlib.h>

void concatenate_file(char filename[]){
    FILE* fptr = fopen(filename, "r");
    if(fptr == NULL){
        // Add this line to pass the tests
        printf("wcat: cannot open file\n");
        exit(1);
    }
    // Using fgets with buffer is more efficient than fgetc
    char buffer[512];
    while(fgets(buffer, sizeof(buffer), fptr))
        printf("%s", buffer);

    fclose(fptr);
}

int main(int argc, char* argv[]){
    if(argc < 2){
        // Need to comment out to pass the tests.
        /*
        char buffer [1000];

        while(1){
            fgets(buffer,1000,stdin);
            printf("%s", buffer);
        }
        */
        return 0;
    }

    int file_index = 1;
    while(file_index < argc)
        concatenate_file(argv[file_index++]);
    
    return 0;

}
