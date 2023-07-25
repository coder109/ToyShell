#ifndef __UTILS_H__
#define __UTILS_H__

#pragma once

#include <stdio.h>

void* SafeMalloc(size_t malloc_size);

void* SafeRealloc(void* pointer, size_t malloc_size);

#endif
