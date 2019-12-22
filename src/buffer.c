#include "buffer.h"

#include <stdio.h>

void buffer_init(buffer_t *buffer, char *data, size_t size) {
    buffer->buffer = data;
    buffer->size = size;
    buffer->index = 0;
    buffer->written = 0;
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
    
    buffer->buffer[buffer->written++] = (char) (data & 0xff);
    buffer->buffer[buffer->written++] = (char) ((data >> 8) & 0xff);
    buffer->buffer[buffer->written++] = (char) ((data >> 16) & 0xff);
    buffer->buffer[buffer->written++] = (char) ((data >> 24) & 0xff);
    return 0;
}
