#include "buffer.h"

#include <stdio.h>

void buffer_init(buffer_t *buffer, char *data, size_t size) {
    buffer->buffer = data;
    buffer->size = size;
    buffer->index = 0;
    buffer->written = 0;
}

int buffer_read_buffer(buffer_t *buffer, char *data, size_t size) {
    int i;
    int start_index = buffer->index;

    if (buffer->written - buffer->index < size) {
        return 1;
    }

    for (i = 0; i < size; i++) {
        data[i] = buffer->buffer[buffer->index++];
    }

    return 0;
}

int buffer_write_buffer(buffer_t *buffer, const char *data, size_t size) {
    int i;
    int start_index = buffer->written;
    
    if (buffer->size - buffer->written < size) {
        return 1;
    }

    for (i = 0; i < size; i++) {
        buffer->buffer[buffer->written++] = data[i];
    }

    return 0;
}

int buffer_read_uint32(buffer_t *buffer, uint32_t *data) {
    if (buffer->written - buffer->index < sizeof(uint32_t)) {
        return 1;
    }
   
    *data = buffer->buffer[buffer->index++] & 0xff;
    *data |= (buffer->buffer[buffer->index++] & 0xff) << 8;
    *data |= (buffer->buffer[buffer->index++] & 0xff) << 16;
    *data |= (buffer->buffer[buffer->index++] & 0xff) << 24;
    return 0;
}

int buffer_write_uint32(buffer_t *buffer, uint32_t data) {
    if (buffer->size - buffer->written < sizeof(uint32_t)) {
        return 1;
    }
    
    buffer->buffer[buffer->written++] = data & 0xff;
    buffer->buffer[buffer->written++] = (data >> 8) & 0xff;
    buffer->buffer[buffer->written++] = (data >> 16) & 0xff;
    buffer->buffer[buffer->written++] = (data >> 24) & 0xff;
    return 0;
}

int buffer_read_uint16(buffer_t *buffer, uint16_t *data) {
    if (buffer->written - buffer->index < sizeof(uint16_t)) {
        return 1;
    }
   
    *data = buffer->buffer[buffer->index++] & 0xff;
    *data |= (buffer->buffer[buffer->index++] & 0xff) << 8;
    return 0;
}

int buffer_write_uint16(buffer_t *buffer, uint16_t data) {
    if (buffer->size - buffer->written < sizeof(uint16_t)) {
        return 1;
    }
    
    buffer->buffer[buffer->written++] = data & 0xff;
    buffer->buffer[buffer->written++] = (data >> 8) & 0xff;
    return 0;
}

int buffer_read_uint8(buffer_t *buffer, uint8_t *data) {
    if (buffer->written - buffer->index < sizeof(uint8_t)) {
        return 1;
    }
   
    *data = buffer->buffer[buffer->index++] & 0xff;
    return 0;
}

int buffer_write_uint8(buffer_t *buffer, uint8_t data) {
    if (buffer->size - buffer->written < sizeof(uint8_t)) {
        return 1;
    }
    
    buffer->buffer[buffer->written++] = data & 0xff;
    return 0;
}

int buffer_read_int32(buffer_t *buffer, int32_t *data) {
    if (buffer->written - buffer->index < sizeof(int32_t)) {
        return 1;
    }
   
    *data = buffer->buffer[buffer->index++] & 0xff;
    *data |= (buffer->buffer[buffer->index++] & 0xff) << 8;
    *data |= (buffer->buffer[buffer->index++] & 0xff) << 16;
    *data |= (buffer->buffer[buffer->index++] & 0xff) << 24;
    return 0;
}

int buffer_write_int32(buffer_t *buffer, int32_t data) {
    if (buffer->size - buffer->written < sizeof(int32_t)) {
        return 1;
    }
    
    buffer->buffer[buffer->written++] = data & 0xff;
    buffer->buffer[buffer->written++] = (data >> 8) & 0xff;
    buffer->buffer[buffer->written++] = (data >> 16) & 0xff;
    buffer->buffer[buffer->written++] = (data >> 24) & 0xff;
    return 0;
}

int buffer_read_int16(buffer_t *buffer, int16_t *data) {
    if (buffer->written - buffer->index < sizeof(int16_t)) {
        return 1;
    }
   
    *data = buffer->buffer[buffer->index++] & 0xff;
    *data |= (buffer->buffer[buffer->index++] & 0xff) << 8;
    return 0;
}

int buffer_write_int16(buffer_t *buffer, int16_t data) {
    if (buffer->size - buffer->written < sizeof(int16_t)) {
        return 1;
    }
    
    buffer->buffer[buffer->written++] = data & 0xff;
    buffer->buffer[buffer->written++] = (data >> 8) & 0xff;
    return 0;
}

int buffer_read_int8(buffer_t *buffer, int8_t *data) {
    if (buffer->written - buffer->index < sizeof(int8_t)) {
        return 1;
    }
   
    *data = buffer->buffer[buffer->index++] & 0xff;
    return 0;
}

int buffer_write_int8(buffer_t *buffer, int8_t data) {
    if (buffer->size - buffer->written < sizeof(int8_t)) {
        return 1;
    }
    
    buffer->buffer[buffer->written++] = data & 0xff;
    return 0;
}
