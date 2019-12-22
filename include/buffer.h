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

/* Read an uint32_t from the buffer.
The result is written to the memory pointed to by "data.
If there isn't enough data in buffer to read an uint32, 1 is returned.
Otherwise, 0 is returned.
*/
int buffer_read_uint32(buffer_t *buffer, uint32_t *data);

/* Write an uint32_t to the buffer.
If there isn't enough data in buffer to write an uint32, 1 is returned.
Otherwise, 0 is returned.
*/
int buffer_write_uint32(buffer_t *buffer, uint32_t data);


#endif // __BUFFER_H__
