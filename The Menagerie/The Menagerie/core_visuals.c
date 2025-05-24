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

int printg(double duration, const char* format, ...)
{
    va_list args;
    va_start(args, format);

    char buffer[256];
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);

    int skip_delay = 0;

    for (int i = 0; buffer[i] != '\0'; i++)
    {
        if (_kbhit())
        {
            int key = _getch();
            if (key == 13)  // Enter
            {
				hold_seconds(0.05); // short delay before skipping
                skip_delay = 1;
            }
            else if (key == 27) // Escape
            {
                return -1;
            }
        }

        printf("%c", buffer[i]);
		fflush(stdout);// immediately flush the output buffer

        if (!skip_delay)
        {
            hold_seconds(duration);
        }
    }
    return 0;
}