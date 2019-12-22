#ifndef __BUFFER_H__
#define __BUFFER_H__

#include <stdint.h>
#include <stddef.h>

typedef struct buffer_t {
    char *buffer;
    size_t size, written, index;
} buffer_t;

/* Init the buffer.
The caller owns the memory pointed to by "data". The lifetime of the memory
should persist across the lifetime of the buffer.
*/
void buffer_init(buffer_t *buffer, char *data, size_t size);

/* Read a buffer from the buffer.
The result is written to the memory pointed to by "data.
If there isn't enough data in the buffer to read the whole buffer, 1 is returned.
Otherwise, 0 is returned
*/
int buffer_read_buffer(buffer_t *buffer, char *data, size_t size);

/* Write a buffer to the buffer.
If there isn't enough data in the buffer to write thw whole buffer, 1 is returned.
Otherwise, 0 is returned.
*/
int buffer_write_buffer(buffer_t *buffer, const char *data, size_t size);

/* Read an uint32_t from the buffer.
The result is written to the memory pointed to by "data.
If there isn't enough data in the buffer to read an uint32, 1 is returned.
Otherwise, 0 is returned
*/
int buffer_read_uint32(buffer_t *buffer, uint32_t *data);

/* Write an uint32_t to the buffer.
If there isn't enough data in the buffer to write an uint32, 1 is returned.
Otherwise, 0 is returned.
*/
int buffer_write_uint32(buffer_t *buffer, uint32_t data);

/* Read an uint16_t from the buffer.
The result is written to the memory pointed to by "data.
If there isn't enough data in the buffer to read an uint16, 1 is returned.
Otherwise, 0 is returned
*/
int buffer_read_uint16(buffer_t *buffer, uint16_t *data);

/* Write an uint16_t to the buffer.
If there isn't enough data in the buffer to write an uint16, 1 is returned.
Otherwise, 0 is returned.
*/
int buffer_write_uint16(buffer_t *buffer, uint16_t data);

/* Read an uint8_t from the buffer.
The result is written to the memory pointed to by "data.
If there isn't enough data in the buffer to read an uint8, 1 is returned.
Otherwise, 0 is returned
*/
int buffer_read_uint8(buffer_t *buffer, uint8_t *data);

/* Write an uint8_t to the buffer.
If there isn't enough data in the buffer to write an uint8, 1 is returned.
Otherwise, 0 is returned.
*/
int buffer_write_uint8(buffer_t *buffer, uint8_t data);

/* Read an int32_t from the buffer.
The result is written to the memory pointed to by "data.
If there isn't enough data in the buffer to read an int32, 1 is returned.
Otherwise, 0 is returned
*/
int buffer_read_int32(buffer_t *buffer, int32_t *data);

/* Write an int32_t to the buffer.
If there isn't enough data in the buffer to write an int32, 1 is returned.
Otherwise, 0 is returned.
*/
int buffer_write_int32(buffer_t *buffer, int32_t data);

/* Read an int16_t from the buffer.
The result is written to the memory pointed to by "data.
If there isn't enough data in the buffer to read an int16, 1 is returned.
Otherwise, 0 is returned
*/
int buffer_read_int16(buffer_t *buffer, int16_t *data);

/* Write an int16_t to the buffer.
If there isn't enough data in the buffer to write an int16, 1 is returned.
Otherwise, 0 is returned.
*/
int buffer_write_int16(buffer_t *buffer, int16_t data);

/* Read an int8_t from the buffer.
The result is written to the memory pointed to by "data.
If there isn't enough data in the buffer to read an int8, 1 is returned.
Otherwise, 0 is returned
*/
int buffer_read_int8(buffer_t *buffer, int8_t *data);

/* Write an int8_t to the buffer.
If there isn't enough data in the buffer to write an int8, 1 is returned.
Otherwise, 0 is returned.
*/
int buffer_write_int8(buffer_t *buffer, int8_t data);


#endif // __BUFFER_H__
