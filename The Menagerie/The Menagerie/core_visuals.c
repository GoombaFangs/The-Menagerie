#include "core_visuals.h"

void reset_console()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

inline void printg(double duration, const char* format, ...)
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

void scroll_to_line(int position)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if (GetConsoleScreenBufferInfo(hConsole, &csbi))
    {
        SMALL_RECT window = csbi.srWindow;
        SHORT height = window.Bottom - window.Top;

        SHORT max_top = csbi.dwSize.Y - height - 1;
        if (position > max_top)
            position = max_top;
        if (position < 0)
            position = 0;

        SMALL_RECT new_window = {
            .Left = window.Left,
            .Top = position,
            .Right = window.Right,
            .Bottom = position + height
        };

        SetConsoleWindowInfo(hConsole, TRUE, &new_window);
    }
}