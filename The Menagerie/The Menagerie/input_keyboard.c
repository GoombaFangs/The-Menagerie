#include "input_keyboard.h"

void print_options_menu(int selected, const char* menu_list[], int amount)
{
	clear_console();
	printf("\n");
	for (int i = 0; i < amount; i++)
	{
		printf("\n");
		if (i == selected)
			printf("              > %s\n", menu_list[i]);
		else
			printf("                %s\n", menu_list[i]);
		printf("\n");
	}
}

int input(const char* menu_list[], int amount)
{
    int default_option = 0;

    print_options_menu(default_option, menu_list, amount);

    while (1)
    {
        int keyboard_input = _getch();
        if (keyboard_input == 0 || keyboard_input == 224)
        {
            keyboard_input = _getch();

            switch (keyboard_input)
            {
            case 72: // Up
                if (default_option > 0)
                    default_option--;
                break;

            case 80: // Down
                if (default_option < amount - 1)
                    default_option++;
                break;

            case 13: // Enter
                clear_console();
                return default_option;
            }

            print_options_menu(default_option, menu_list, amount);
        }
    }
}