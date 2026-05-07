#include "RingBuffer.h"

bool RingBuffer::has_space(size_t count)
{
    return (16384 - (write_pos.load() - read_pos.load())) >= count;
}

bool RingBuffer::write(const float *data, size_t count)
{
    if (!has_space(count)) {
        return false;
    }
    for (int i = 0; i < count; ++i) {
        buffer[write_pos & 16383] = data[i];
        ++write_pos;
    }
    return true;
}

bool RingBuffer::read(float *dest, size_t count)
{
    if (write_pos.load() - read_pos.load() < count)
    {
        return false;
    }
    for (int i = 0; i < count; ++i)
    {
        dest[i] = buffer[read_pos & 16383];
        ++read_pos;
    }
    return true;
}