#ifndef CONSOLE_H
#define CONSOLE_H

#include <windows.h>
#include <tlhelp32.h>
#include <psapi.h>
#include <tchar.h>
#include <stdio.h>

#include "visuals_folder.h"

int is_windows_terminal();
int is_powershell_parent();
void relaunch_in_cmd_if_needed();
void print_current_console_info();
void set_active_console(HANDLE h);
void set_console_size(int columns, int rows);
void set_console_font_size(int width, int height);
void console_manager();

#endif

