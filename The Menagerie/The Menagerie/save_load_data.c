#include "save_load_data.h"

int save_data(const char* filename, const void* data, size_t element_size, size_t count) {
    FILE* file = fopen(filename, "wb");
    if (!file) 
    {
        return 0;
    }
    size_t written = fwrite(data, element_size, count, file);
    fclose(file);
    return (written == count);
}

int load_data (const char* filename, void* data, size_t element_size, size_t count)
{
    FILE* file = fopen(filename, "rb");
    if (!file) 
    {
        return 0;
    }
    size_t read = fread(data, element_size, count, file);
    fclose(file);
    return (read == count);
}
