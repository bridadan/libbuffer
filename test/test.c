#include "buffer.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test_buffer_buffer() {
    write_buffer_t write_buffer;
    read_buffer_t read_buffer;
    int result, i;
    const size_t size = 7;
    const uint32_t VALUE = 0xDEADBEEF;
    const char EXPECTED_DATA[] = { 0, 1, 2, 3, 4, 5, 6 };
    char data[size];
    char read_data[size];

    buffer_write_init(&write_buffer, data, size);
    result = buffer_write_buffer(&write_buffer, EXPECTED_DATA, size);
    assert(!result);
    
    for (i = 0; i < size; i++) {
        assert(data[i] == EXPECTED_DATA[i]);
    }

    buffer_read_init(&read_buffer, data, size);
    result = buffer_read_buffer(&read_buffer, read_data, size);
    assert(!result);
    
    for (i = 0; i < size; i++) {
        assert(read_data[i] == EXPECTED_DATA[i]);
    }

    result = buffer_read_buffer(&read_buffer, read_data, size);
    assert(result == 1);
}

void test_buffer_uint32() {
    write_buffer_t write_buffer;
    read_buffer_t read_buffer;
    int result, i;
    uint32_t read_value;
    const size_t size = sizeof(uint32_t);
    const uint32_t VALUE = 0xDEADBEEF;
    const char EXPECTED_DATA[] = { 0xEF, 0xBE, 0xAD, 0xDE };
    char data[size];

    buffer_write_init(&write_buffer, data, size);
    result = buffer_write_uint32(&write_buffer, VALUE);
    assert(!result);
    
    for (i = 0; i < size; i++) {
        assert(data[i] == EXPECTED_DATA[i]);
    }

    buffer_read_init(&read_buffer, data, size);
    result = buffer_read_uint32(&read_buffer, &read_value);
    assert(!result);
    assert(read_value == VALUE);

    result = buffer_read_uint32(&read_buffer, &read_value);
    assert(result == 1);
}

void test_buffer_uint16() {
    write_buffer_t write_buffer;
    read_buffer_t read_buffer;
    int result, i;
    uint16_t read_value;
    const size_t size = sizeof(uint16_t);
    const uint16_t VALUE = 0xBEEF;
    const char EXPECTED_DATA[] = { 0xEF, 0xBE };
    char data[size];

    buffer_write_init(&write_buffer, data, size);
    result = buffer_write_uint16(&write_buffer, VALUE);
    assert(!result);
    
    for (i = 0; i < size; i++) {
        assert(data[i] == EXPECTED_DATA[i]);
    }

    buffer_read_init(&read_buffer, data, size);
    result = buffer_read_uint16(&read_buffer, &read_value);
    assert(!result);
    assert(read_value == VALUE);

    result = buffer_read_uint16(&read_buffer, &read_value);
    assert(result == 1);
}

void test_buffer_uint8() {
    write_buffer_t write_buffer;
    read_buffer_t read_buffer;
    int result, i;
    uint8_t read_value;
    const size_t size = sizeof(uint8_t);
    const uint8_t VALUE = 0xBE;
    const char EXPECTED_DATA[] = { 0xBE };
    char data[size];

    buffer_write_init(&write_buffer, data, size);
    result = buffer_write_uint8(&write_buffer, VALUE);
    assert(!result);
    
    for (i = 0; i < size; i++) {
        assert(data[i] == EXPECTED_DATA[i]);
    }

    buffer_read_init(&read_buffer, data, size);
    result = buffer_read_uint8(&read_buffer, &read_value);
    assert(!result);
    assert(read_value == VALUE);

    result = buffer_read_uint8(&read_buffer, &read_value);
    assert(result == 1);
}

void test_buffer_int32() {
    write_buffer_t write_buffer;
    read_buffer_t read_buffer;
    int result, i;
    int32_t read_value;
    const size_t size = sizeof(int32_t);
    const int32_t VALUE = 0xDEADBEEF;
    const char EXPECTED_DATA[] = { 0xEF, 0xBE, 0xAD, 0xDE };
    char data[size];

    buffer_write_init(&write_buffer, data, size);
    result = buffer_write_int32(&write_buffer, VALUE);
    assert(!result);
    
    for (i = 0; i < size; i++) {
        assert(data[i] == EXPECTED_DATA[i]);
    }

    buffer_read_init(&read_buffer, data, size);
    result = buffer_read_int32(&read_buffer, &read_value);
    assert(!result);
    assert(read_value == VALUE);

    result = buffer_read_int32(&read_buffer, &read_value);
    assert(result == 1);
}

void test_buffer_int16() {
    write_buffer_t write_buffer;
    read_buffer_t read_buffer;
    int result, i;
    int16_t read_value;
    const size_t size = sizeof(int16_t);
    const int16_t VALUE = 0xBEEF;
    const char EXPECTED_DATA[] = { 0xEF, 0xBE };
    char data[size];

    buffer_write_init(&write_buffer, data, size);
    result = buffer_write_int16(&write_buffer, VALUE);
    assert(!result);
    
    for (i = 0; i < size; i++) {
        assert(data[i] == EXPECTED_DATA[i]);
    }

    buffer_read_init(&read_buffer, data, size);
    result = buffer_read_int16(&read_buffer, &read_value);
    assert(!result);
    assert(read_value == VALUE);

    result = buffer_read_int16(&read_buffer, &read_value);
    assert(result == 1);
}

void test_buffer_int8() {
    write_buffer_t write_buffer;
    read_buffer_t read_buffer;
    int result, i;
    int8_t read_value;
    const size_t size = sizeof(int8_t);
    const int8_t VALUE = 0xBE;
    const char EXPECTED_DATA[] = { 0xBE };
    char data[size];

    buffer_write_init(&write_buffer, data, size);
    result = buffer_write_int8(&write_buffer, VALUE);
    assert(!result);
    
    for (i = 0; i < size; i++) {
        assert(data[i] == EXPECTED_DATA[i]);
    }

    buffer_read_init(&read_buffer, data, size);
    result = buffer_read_int8(&read_buffer, &read_value);
    assert(!result);
    assert(read_value == VALUE);

    result = buffer_read_int8(&read_buffer, &read_value);
    assert(result == 1);
}

int main() {
    test_buffer_buffer();
    test_buffer_uint32();
    test_buffer_uint16();
    test_buffer_uint8();
    test_buffer_int32();
    test_buffer_int16();
    test_buffer_int8();
    printf("All tests passed\r\n");
    return 0;
}
