#include "input_keyboard.h"

#define FRAME_WIDTH 14
#define VISIBLE_ALIENS 1

void print_text_options(int selected, const char* menu_list[], int amount, int console)
{
    static int stop_holding = 1;
    for (int i = 0; i < amount; i++)
    {
        const char* text = menu_list[i];
        int len = (int)strlen(text);
        int padding_total = FRAME_WIDTH - len;
        int padding_left = padding_total / 2;
        int padding_right = padding_total - padding_left;

        if (i == selected)
        {
            printf("             ");
            if (console == 3) printf("              ");
            for (int j = 0; j < FRAME_WIDTH + 2; j++) printf("-");
            printf("\n");
            if (console == 3) printf("       Destination:       |");
			else printf("            |");
     
            for (int j = 0; j < padding_left; j++) printf(" ");

            printf(" %s ", text);

            for (int j = 0; j < padding_right; j++) printf(" ");
            printf("|\n");

            printf("             ");
            if (console == 3) printf("              ");
            for (int j = 0; j < FRAME_WIDTH + 2; j++) printf("-");
            printf("\n");
        }
        else
        {
            printf("\n");
            if (console == 3) printf("              ");
            printf("                %s\n", text);
            printf("\n");
        }
        printf("\n");

        if (stop_holding == 1)
        {
            hold_seconds(0.2); // Add a small delay for better visual effect
        }

        if (i + 1 == amount)
        {
           
			stop_holding = 0;
            if (strcmp(text, "  Exit   ") != 0 && strcmp(text, "  Back   ") != 0)
            {
                printf("\n\n                                                                   Choose a planet to explore..\n");
            } 
        }
        else
        {
           
        }
    }
}

int input_text(const char* menu_list[], int amount, int console_style, char* planet_terrain)// console 0 to reset console
{
    int selected = 0;
	switch (console_style)
	{
	case 0:  reset_console();// default style
		break;
	case 1:  reset_console(); print_planet_menu(planet_terrain); // planet terrain style
		break;
	case 2:  reset_console(); print_captain_seat();// space windows style 
		break;
	case 3:  reset_console(); stars(); // stars style
		break;
    case 4:  reset_console(); print_ship_log(); printf("\n"); // ship log style
		break;
    }

    print_text_options(selected, menu_list, amount , console_style);

    while (1)
    {
        int key = _getch();
        if (key == 0 || key == 224) key = _getch();

        if (key == 72 && selected > 0)//up
        {
            selected--;
        }
        else if (key == 80 && selected < amount - 1)//down
        {
            selected++;
        }
        else if (key == 13)//enter
        {
            reset_console();
            return selected;
        }
        else if (key == 27)//escape
        {
            reset_console();
            return -1;
        }

        switch (console_style)
        {
        case 0:  reset_console(); // default style
            break;
        case 1:  reset_console(); print_planet_menu(planet_terrain);  // planet terrain style
            break;
        case 2:  reset_console(); print_captain_seat(); // space windows style 
            break;
        case 3:  reset_console(); stars();   // stars style
            break;
        case 4:  reset_console(); print_ship_log(); printf("\n"); // ship log style
            break;
        }

        print_text_options(selected, menu_list, amount, console_style);
    }
}

int input_zoo(Zoo* zoo)
{
    if (zoo->count <= 0)
    {
        printf("The zoo is empty.\n");
        hold_seconds(2);
        return -1;
    }

    int selected = 0;
    print_zoo_aliens(zoo->list, zoo->count, selected, 1);

    while (1)
    {
        int key = _getch();
        if (key == 0 || key == 224)
        {
            key = _getch();
        }

        if (key == 72 && selected > 0) // UP
        {
            selected--;
        }
        else if (key == 80 && selected < zoo->count - 1) // DOWN
        {
            selected++;
        }
        else if (key == 13 || key == 27) // ENTER or ESC
        {
            return -1;
        }

        print_zoo_aliens(zoo->list, zoo->count, selected, 1);
    }
}

int input_aliens(char* planet_terrain, Alien* aliens, int count)
{
    int selected = 0;
    print_alien_options(aliens, count, selected, VISIBLE_ALIENS);

    while (1)
    {
        int key = _getch();
        if (key == 0 || key == 224)
        {
            key = _getch();
        }

        if (key == 72 && selected > 0) // UP
        {
            selected--;
        }
        else if (key == 80 && selected < count - 1) // DOWN
        {
            selected++;
        }
        else if (key == 13) // ENTER
        {
            reset_console();
            return selected; 
        }
        else if (key == 27) // ESC
        {
            const char* list[] = { "  Continue  ", "  Exit   " };
            int selected = input_text(list, 2, 1, planet_terrain);//1 planet terrain style
            if (selected != 0)
            {
                return -1;
            }
        }
        print_alien_options(aliens, count, selected, VISIBLE_ALIENS);
    }
}

int get_alpha_input(char* inputBuffer, int bufferSize)
{
    int bufferIndex = 0;
    int key;

    while (1)
    {
        key = _getch();

        if (key == 0 || key == 224) // Arrow key or special key
        {
            (void)_getch(); // Consume the next byte (arrow key code)
            putchar('\a'); // Beep sound
            continue; // Ignore
        }

        if (key == '\r') // Enter
        {
            if (bufferIndex > 0)  
            {
                inputBuffer[bufferIndex] = '\0';
                break;
            }
            else
            {
                putchar('\a'); // Beep sound
            }
        }

        if ((key >= 'A' && key <= 'Z') ||
            (key >= 'a' && key <= 'z'))
        {
            if (bufferIndex < bufferSize - 1)
            {
                inputBuffer[bufferIndex++] = key;
                putchar(key);
            }
        }
        else if (key == '\b' && bufferIndex > 0) // Backspace
        {
            bufferIndex--;
            printf("\b \b"); // Remove the last character from the console
        }
        else if (key == 27) // Escape Key
        {
            return -1;
        }
        else
        {
            putchar('\a'); // Beep sound
        }
    }
	return 0;
}