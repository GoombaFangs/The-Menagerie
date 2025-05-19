#include "input_keyboard.h"

#define FRAME_WIDTH 13

void print_options_menu(int selected, const char* menu_list[], int amount)
{
    clear_console();

    printf("    Press Up or Down arrow and Enter to confirm:\n\n\n");

    for (int i = 0; i < amount; i++)
    {
        const char* text = menu_list[i];
        int len = strlen(text);
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
            }
        }
        else if (keyboard_input == 13) // Enter
        {
            clear_console();
            return default_option;
        }
            print_options_menu(default_option, menu_list, amount);
    }
}