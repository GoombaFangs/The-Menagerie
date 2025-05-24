#ifndef SAVE_LOAD_DATA_H
#define SAVE_LOAD_DATA_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

int save_data(const char* filename, const void* data, size_t element_size, size_t count);
int load_data(const char* filename, void* data, size_t element_size, size_t count);

#endif
