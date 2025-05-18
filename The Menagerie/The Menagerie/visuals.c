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