#ifndef __BUFFER_H__
#define __BUFFER_H__

#include <stdint.h>
#include <stddef.h>

typedef struct read_buffer_t {
    const char *buffer;
    size_t size, index;
} read_buffer_t;

typedef struct write_buffer_t {
    char *buffer;
    size_t size, index;
} write_buffer_t;

/* Init the buffer.
The caller owns the memory pointed to by "data". The lifetime of the memory
should persist across the lifetime of the buffer.
*/
void buffer_read_init(read_buffer_t *buffer, const char *data, size_t size);

/* Init the buffer.
The caller owns the memory pointed to by "data". The lifetime of the memory
should persist across the lifetime of the buffer.
*/
void buffer_write_init(write_buffer_t *buffer, char *data, size_t size);

/* Read a buffer from the buffer.
The result is written to the memory pointed to by "data.
If there isn't enough data in the buffer to read the whole buffer, 1 is returned.
Otherwise, 0 is returned
*/
int buffer_read_buffer(read_buffer_t *buffer, char *data, size_t size);

/* Write a buffer to the buffer.
If there isn't enough data in the buffer to write thw whole buffer, 1 is returned.
Otherwise, 0 is returned.
*/
int buffer_write_buffer(write_buffer_t *buffer, const char *data, size_t size);

/* Read an uint32_t from the buffer.
The result is written to the memory pointed to by "data.
If there isn't enough data in the buffer to read an uint32, 1 is returned.
Otherwise, 0 is returned
*/
int buffer_read_uint32(read_buffer_t *buffer, uint32_t *data);

/* Write an uint32_t to the buffer.
If there isn't enough data in the buffer to write an uint32, 1 is returned.
Otherwise, 0 is returned.
*/
int buffer_write_uint32(write_buffer_t *buffer, uint32_t data);

/* Read an uint16_t from the buffer.
The result is written to the memory pointed to by "data.
If there isn't enough data in the buffer to read an uint16, 1 is returned.
Otherwise, 0 is returned
*/
int buffer_read_uint16(read_buffer_t *buffer, uint16_t *data);

/* Write an uint16_t to the buffer.
If there isn't enough data in the buffer to write an uint16, 1 is returned.
Otherwise, 0 is returned.
*/
int buffer_write_uint16(write_buffer_t *buffer, uint16_t data);

/* Read an uint8_t from the buffer.
The result is written to the memory pointed to by "data.
If there isn't enough data in the buffer to read an uint8, 1 is returned.
Otherwise, 0 is returned
*/
int buffer_read_uint8(read_buffer_t *buffer, uint8_t *data);

/* Write an uint8_t to the buffer.
If there isn't enough data in the buffer to write an uint8, 1 is returned.
Otherwise, 0 is returned.
*/
int buffer_write_uint8(write_buffer_t *buffer, uint8_t data);

/* Read an int32_t from the buffer.
The result is written to the memory pointed to by "data.
If there isn't enough data in the buffer to read an int32, 1 is returned.
Otherwise, 0 is returned
*/
int buffer_read_int32(read_buffer_t *buffer, int32_t *data);

/* Write an int32_t to the buffer.
If there isn't enough data in the buffer to write an int32, 1 is returned.
Otherwise, 0 is returned.
*/
int buffer_write_int32(write_buffer_t *buffer, int32_t data);

/* Read an int16_t from the buffer.
The result is written to the memory pointed to by "data.
If there isn't enough data in the buffer to read an int16, 1 is returned.
Otherwise, 0 is returned
*/
int buffer_read_int16(read_buffer_t *buffer, int16_t *data);

/* Write an int16_t to the buffer.
If there isn't enough data in the buffer to write an int16, 1 is returned.
Otherwise, 0 is returned.
*/
int buffer_write_int16(write_buffer_t *buffer, int16_t data);

/* Read an int8_t from the buffer.
The result is written to the memory pointed to by "data.
If there isn't enough data in the buffer to read an int8, 1 is returned.
Otherwise, 0 is returned
*/
int buffer_read_int8(read_buffer_t *buffer, int8_t *data);

/* Write an int8_t to the buffer.
If there isn't enough data in the buffer to write an int8, 1 is returned.
Otherwise, 0 is returned.
*/
int buffer_write_int8(write_buffer_t *buffer, int8_t data);


#endif // __BUFFER_H__
