#ifndef CORE_VISUALS_H
#define CORE_VISUALS_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
#include <conio.h>
#include <windows.h>
#include "time.h"

void reset_console();
void printg(double duration, const char* format, ...);
void scroll_to_line(int position);

#endif