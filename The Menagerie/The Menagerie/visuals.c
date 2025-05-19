#include "visuals.h"

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

COORD scroll_to_top() 
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

    return prev_pos;
}

void scroll_to_up(int rows)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD current_pos = scroll_to_top();

    int new_y = current_pos.Y - rows;
    if (new_y < 0) 
    {
        new_y = 0;
    }

    COORD new_pos = { 0, new_y };
    SetConsoleCursorPosition(hConsole, new_pos);
}

void scroll_to_down(int rows)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    // get current buffer info
    if (GetConsoleScreenBufferInfo(hConsole, &csbi)) 
    {
        COORD current_pos = scroll_to_top();

        int buffer_height = csbi.dwSize.Y;

        // calculate new Y, clamped to buffer height
        int new_y = current_pos.Y + rows;
        if (new_y >= buffer_height) 
        {
            new_y = buffer_height - 1;
        }

        COORD new_pos = { 0, new_y };
        SetConsoleCursorPosition(hConsole, new_pos);
    }
}