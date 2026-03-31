#include <stdio.h>
#include <unistd.h> // standard symbolic constants and types; function: write, close 
#include <assert.h> // verify program assertion; function: assert
#include <fcntl.h> // file control options; function: open; const: O_WRONLY, O_CREAT, O_TRUNC
#include <sys/types.h> // data types
#include <sys/stat.h> // data returned by the stat() function; const: S_IRWXU

int main(int argc, char* argv[]){
    int fd = open("/tmp/file", O_WRONLY|O_CREAT|O_TRUNC,S_IRWXU);
    assert(fd > -1);
    int rc = write(fd, "hello world\n", 12);
    assert(rc == 12);
    close(fd);
    return 0;
}
