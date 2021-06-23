#include <stdio.h>
#include <stdlib.h>

#include <balloc.h>


int main(int argc, const char * argv[]) {

    uint8_t * byte = balloc();
    *byte = 'a';

    for (*byte = 'a'; *byte <= 'z'; ++(*byte)) {
        printf("Current value: %c\n", *byte);
    }

    free(byte);

    return 0;
}

