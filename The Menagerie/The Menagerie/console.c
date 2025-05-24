#define _CRT_SECURE_NO_WARNINGS
#include "console.h"

static HANDLE active_console = NULL;

int is_not_cmd()
{
    DWORD pid = GetCurrentProcessId();
    DWORD ppid = 0;

    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    PROCESSENTRY32 pe = { sizeof(PROCESSENTRY32) };

    if (Process32First(snapshot, &pe)) {
        do {
            if (pe.th32ProcessID == pid) {
                ppid = pe.th32ParentProcessID;
                break;
            }
        } while (Process32Next(snapshot, &pe));
    }
    CloseHandle(snapshot);

    if (ppid == 0) return 0;

    HANDLE hParent = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, ppid);
    if (!hParent) return 0;

    TCHAR parent_name[MAX_PATH];
    GetModuleBaseName(hParent, NULL, parent_name, MAX_PATH);
    CloseHandle(hParent);

    return _tcsicmp(parent_name, _T("cmd.exe")) != 0;
}

void relaunch_in_cmd_if_needed()
{
    if (is_not_cmd())
    {
        TCHAR exe_path[MAX_PATH];
        GetModuleFileName(NULL, exe_path, MAX_PATH);

        TCHAR command[MAX_PATH + 50];
        _stprintf_s(command, MAX_PATH + 50, _T("cmd.exe /c \"%s\""), exe_path);

        STARTUPINFO si = { sizeof(si) };
        PROCESS_INFORMATION pi;

        if (CreateProcess(NULL, command, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
        {
            CloseHandle(pi.hProcess);
            CloseHandle(pi.hThread);
        }

        exit(0);
    }
}

void print_current_console_info()
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE)
    {
        fprintf(stderr, "Error: Could not get standard output handle.\n");
        return;
    }

    CONSOLE_SCREEN_BUFFER_INFO screen_info;
    if (!GetConsoleScreenBufferInfo(hOut, &screen_info))
    {
        fprintf(stderr, "Error: Could not get console screen buffer info.\n");
        return;
    }

    int columns = screen_info.srWindow.Right - screen_info.srWindow.Left + 1;
    int rows = screen_info.srWindow.Bottom - screen_info.srWindow.Top + 1;
    printf("Console Window Size: %d columns x %d rows\n", columns, rows);

    CONSOLE_FONT_INFOEX font_info = { 0 };
    font_info.cbSize = sizeof(font_info);

    if (!GetCurrentConsoleFontEx(hOut, FALSE, &font_info))
    {
        fprintf(stderr, "Error: Could not get console font info.\n");
        return;
    }

    wprintf(L"Console Font: %s\n", font_info.FaceName);
    printf("Font Size: %d x %d\n", font_info.dwFontSize.X, font_info.dwFontSize.Y);
}

void set_active_console(HANDLE h)
{
    active_console = h;
}

void set_console_size(int columns, int rows)
{
    if (columns < 20 || rows < 10)
    {
        printf("Invalid console size requested. Setting default size 80x25.\n");
        columns = 80;
        rows = 25;
    }

    char command[64];
    sprintf_s(command, sizeof(command), "mode con: cols=%d lines=%d", columns, rows);
    int result = system(command);
    if (result != 0)
    {
        fprintf(stderr, "Warning: Failed to set console size using system command.\n");
    }
}

void set_console_font_size(int width, int height)
{
    if (width < 4 || height < 4)
    {
        printf("Invalid font size requested. Setting default font size 8x16.\n");
        width = 8;
        height = 16;
    }

    CONSOLE_FONT_INFOEX font_info = { 0 };
    font_info.cbSize = sizeof(font_info);
    font_info.dwFontSize.X = width;
    font_info.dwFontSize.Y = height;
    font_info.FontFamily = FF_DONTCARE;
    font_info.FontWeight = FW_NORMAL;
    wcscpy_s(font_info.FaceName, LF_FACESIZE, L"Consolas");

    HANDLE hOut = active_console != NULL ? active_console : GetStdHandle(STD_OUTPUT_HANDLE);
    if (!SetCurrentConsoleFontEx(hOut, FALSE, &font_info))
    {
        DWORD err = GetLastError();
        fprintf(stderr, "Warning: Failed to set console font size (error code %lu). Trying fallback size.\n", err);
        font_info.dwFontSize.X = 8;
        font_info.dwFontSize.Y = 16;
        SetCurrentConsoleFontEx(hOut, FALSE, &font_info);
    }
}

void console_manager()
{
    relaunch_in_cmd_if_needed();
    set_console_size(110, 40);
    set_console_font_size(7, 14);
    print_current_console_info();
}
