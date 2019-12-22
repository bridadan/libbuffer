#include "buffer.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test_buffer_uint32() {
    buffer_t buffer;
    int result, i;
    uint32_t read_value;
    const size_t size = 4;
    const uint32_t VALUE = 0xDEADBEEF;
    const char EXPECTED_DATA[] = { 0xEF, 0xBE, 0xAD, 0xDE };
    char data[size];

    buffer_init(&buffer, data, size);
    result = buffer_write_uint32(&buffer, VALUE);
    assert(!result);
    
    for (i = 0; i < 4; i++) {
        assert(data[i] == EXPECTED_DATA[i]);
    }

    result = buffer_read_uint32(&buffer, &read_value);
    assert(!result);
    assert(read_value == VALUE);

    result = buffer_read_uint32(&buffer, &read_value);
    assert(result == 1);
}


int main() {
    test_buffer_uint32();
    printf("All tests passed\r\n");
    return 0;
}
