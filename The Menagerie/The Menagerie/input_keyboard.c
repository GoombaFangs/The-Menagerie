#include "input_keyboard.h"

#define FRAME_WIDTH 13
#define VISIBLE_ALIENS 1

void print_text_options(int selected, const char* menu_list[], int amount)
{
    //printf("Press Up or Down arrow ,  Enter to confirm , Escape to go back\n\n");

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
            for (int j = 0; j < FRAME_WIDTH + 2; j++) printf("-");
            printf("\n");

            printf("            |");
            for (int j = 0; j < padding_left; j++) printf(" ");
            printf(" %s ", text);
            for (int j = 0; j < padding_right; j++) printf(" ");
            printf("|\n");

            printf("             ");
            for (int j = 0; j < FRAME_WIDTH + 2; j++) printf("-");
            printf("\n");
        }
        else
        {
            printf("\n");
            printf("                %s\n", text);
            printf("\n");
        }
        printf("\n");
        if (i + 1 == amount)
        {
            if (strcmp(text, "  Exit   ") != 0)
            {
                printf("\n\n     Choose a planet to explore..\n");
            }
        }
    }
}

int input_text(const char* menu_list[], int amount, int console, char* planet_terrain)// console 0 to reset console
{
    int selected = 0;
	switch (console)
	{
	case 0:  reset_console();
		break;
	case 1:  reset_console(); print_planet_menu(planet_terrain);
		break;
	case 2:  reset_console(); print_space_windows();
		break;
	case 3:  reset_console(); stars();
		break;
    }

    print_text_options(selected, menu_list, amount);

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

        switch (console)
        {
        case 0:  reset_console();
            break;
        case 1:  reset_console(); print_planet_menu(planet_terrain);
            break;
        case 2:  reset_console(); print_space_windows();
            break;
        case 3:  reset_console(); stars();
            break;
        }

        print_text_options(selected, menu_list, amount);
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
            return selected + 1; 
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