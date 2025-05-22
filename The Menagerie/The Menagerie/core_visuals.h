#ifndef CORE_VISUALS_H
#define CORE_VISUALS_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

int hold_seconds(double second);
void reset_console();
int printg(double duration, const char* format, ...);
void set_active_console(HANDLE h);
void set_console_size(int columns, int rows);
void set_console_font_size(int width, int height);

#endif