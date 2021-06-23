#include <stdlib.h>

#include "balloc.h"


uint8_t * balloc() {
    return (uint8_t*)malloc(sizeof(uint8_t));
}

