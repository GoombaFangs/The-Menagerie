#include "core_visuals.h"

int hold_seconds(double second)
{
    clock_t start = clock();
    while (1)
    {
        if (_kbhit())
        {
            return 0;
        }

        clock_t end = clock();
        double seconds = ((double)(end - start)) / CLOCKS_PER_SEC;
        if (seconds >= second)
        {
            return 1;
        }
    }
}

void reset_console()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void printg(double duration, const char* format, ...)
{
    va_list args;
    va_start(args, format);

    char buffer[256]; // Temporary buffer to store the formatted string
    vsnprintf(buffer, sizeof(buffer), format, args); // Format the string
    va_end(args);

    for (int i = 0; buffer[i] != '\0'; i++)
    {
        printf("%c", buffer[i]);
        hold_seconds(duration);
    }
}

static HANDLE active_console = NULL;

void set_active_console(HANDLE h)
{
    active_console = h;
}

void set_console_size(int columns, int rows)
{
    char command[64];
    sprintf_s(command, sizeof(command), "mode con: cols=%d lines=%d", columns, rows);
    system(command);
}

void set_console_font_size(int width, int height)
{
    CONSOLE_FONT_INFOEX font_info = { 0 };
    font_info.cbSize = sizeof(font_info);
    font_info.dwFontSize.X = width;
    font_info.dwFontSize.Y = height;
    font_info.FontFamily = FF_DONTCARE;
    font_info.FontWeight = FW_NORMAL;
    wcscpy_s(font_info.FaceName, LF_FACESIZE, L"Consolas");

    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetCurrentConsoleFontEx(hOut, FALSE, &font_info);
}