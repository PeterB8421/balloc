#include <iostream>
#include <cstdint>

#include <balloc.h>


int main(int argc, const char * argv[]) {

    std::uint8_t * byte = balloc();

    {
        std::uint8_t & ref = *byte;

        for (ref = 'a'; ref <= 'z'; ++ref) {
            std::cout << "Current value: " << (*byte) << std::endl;
        }
    }

    std::free(byte);
}

