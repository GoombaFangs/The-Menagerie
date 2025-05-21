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

void scroll_to_line(int position)
{
    if (active_console == NULL)
        active_console = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD pos = { 0, (SHORT)position };
    SetConsoleCursorPosition(active_console, pos);
}