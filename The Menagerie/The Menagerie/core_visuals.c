#include "core_visuals.h"

void clear_console()
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

void scroll_to_top() 
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    COORD prev_pos = { 0, 0 };

    if (GetConsoleScreenBufferInfo(hConsole, &csbi)) 
    {
        prev_pos = csbi.dwCursorPosition;
    }

    COORD top = { 0, 0 };
    SetConsoleCursorPosition(hConsole, top);

}