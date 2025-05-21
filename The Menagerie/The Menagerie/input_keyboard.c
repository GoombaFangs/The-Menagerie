#include "input_keyboard.h"

#define FRAME_WIDTH 13

void print_style_1(int selected, const char* menu_list[], int amount)
{
    reset_console();
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

    if (amount > 6)
        scroll_to_line(selected > 5 ? 17 : 0);
}

void print_style_2(Alien* aliens, int count, int selected)
{
    reset_console();
    switch (selected)
    {
    case 1: card1_details(aliens, count);
        break;
    case 2: card2_details(aliens, count);
        break;
    case 3: card3_details(aliens, count);
        break;
    case 4: card4_details(aliens, count);
        break;
    }
    scroll_to_line(0);   
}

int input_menu(const char* menu_list[], int amount)
{
    int selected = 0;
    print_style_1(selected, menu_list, amount);

    while (1)
    {
        int key = _getch();
        if (key == 0 || key == 224) key = _getch();

        if (key == 72 && selected > 0)
            selected--;
        else if (key == 80 && selected < amount - 1)
            selected++;
        else if (key == 13)
        {
            reset_console();
            return selected;
        }
        else if (key == 27)
        {
            reset_console();
            return -1;
        }

        print_style_1(selected, menu_list, amount);
    }
}

int input_aliens(Alien* aliens, int count)
{
    int selected = on_card_start(aliens, count);
    scroll_to_line(0);
    print_style_2(aliens, count, selected);

    while (1)
    {
        int key = _getch();
        if (key == 0 || key == 224) key = _getch();

        if (key == 72 && selected > 1) selected--;
        else if (key == 80 && selected < 4) selected++;
        else if (key == 13)
        {
            reset_console();
            return selected;
        }
        else if (key == 27)
        {
            reset_console();
            return -1;
        }

        print_style_2(aliens, count, selected);
    }
}