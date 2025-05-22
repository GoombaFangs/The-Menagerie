#include "input_keyboard.h"

#define FRAME_WIDTH 13
#define VISIBLE_ALIENS 1

void print_text_options(int selected, const char* menu_list[], int amount)
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
        if (i + 1 == amount)
        {
            if (strcmp(text, "  Exit   ") != 0)
            {
                printf("\n\n     Choose a planet to explore..\n");
            }
        }
    }
}

int input_text(const char* menu_list[], int amount)
{
    int selected = 0;
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

        print_text_options(selected, menu_list, amount);
    }
}

void print_alien_options(Alien* aliens, int count, int selected, int visible_count)
{
    reset_console();
    printf("\n\n");

    int start = 0;
    if (count > visible_count)
    {
        if (selected < visible_count / 2)
            start = 0;
        else if (selected > count - (visible_count + 1) / 2)
            start = count - visible_count;
        else
            start = selected - visible_count / 2;
    }

    if (start > 0)
    {
        printf("           %d aliens above press up to show\n\n", start);
    }

    for (int i = start; i < start + visible_count && i < count; i++)
    {
        printf("+--------- Alien %d ---------+\n", i + 1);
        printf("                                    +----------------------------+\n");
        printf("                                    | Species  : %-15s |\n", aliens[i].species);
        printf("                                    | Sex      : %-15c |\n", aliens[i].sex);
        printf("                                    | Age      : %-15d |\n", aliens[i].age);
        printf("                                    | Size     : %-15s |\n", aliens[i].size);
        printf("                                    | Diet     : %-15s |\n", aliens[i].diet);
        printf("                                    | Nickname : %-15s |\n", aliens[i].nickname[0] ? aliens[i].nickname : "(none)");
        printf("                                    +----------------------------+\n");
        print_alien_art(&aliens[i], i);
        //if (i == selected)
        //    printf("                         <<< SELECTED >>>\n");
        printf("+----------------------------+\n\n");
    }

    if (start + visible_count < count)
    {
        printf("           %d aliens below press down to show\n", (count - start - 1));
    } 
}


int input_aliens(Alien* aliens, int count)
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
            reset_console();
            return -1;
        }

        print_alien_options(aliens, count, selected, VISIBLE_ALIENS);
    }
}