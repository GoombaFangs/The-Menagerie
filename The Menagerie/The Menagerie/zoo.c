#include "zoo.h"

static Alien* zoo = NULL;
static int zoo_count = 0;
static int zoo_capacity = 0;

void add_alien_to_zoo(Alien alien) 
{
    if (zoo_count == zoo_capacity) 
    {
        zoo_capacity = (zoo_capacity == 0) ? 4 : zoo_capacity * 2;
        zoo = realloc(zoo, zoo_capacity * sizeof(Alien));
        if (!zoo) 
        {
            printf("Failed to allocate memory for the zoo.\n");
            exit(1);
        }
    }
    zoo[zoo_count++] = alien;
}

int display_zoo() //modified ver of input_aliens
{
    int selected = 0;
    print_zoo_aliens(zoo, zoo_count, selected, 1);

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
        else if (key == 80 && selected < zoo_count - 1) // DOWN
        {
            selected++;
        }
		// Commented out selection by ENTER key MAYBE ADD REMOVE ALIEN OPTION
        /*
        else if (key == 13) // ENTER
        {
            reset_console();
            return selected;
        }
        */
        else if (key == 27) // ESC
        {
            return -1;
        }
        print_zoo_aliens(zoo, zoo_count, selected, 1);
    }
}

void print_zoo_aliens(Alien* aliens, int count, int selected, int visible_count) 
{

    reset_console();
    printf("Press Up or Down arrow , Escape to go back to main menu\n\n");
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
        alien_card(aliens, i);
    }

    if (start + visible_count < count)
    {
        printf("           %d aliens below press down to show\n", (count - start - 1));
    }

    // Print the currently selected alien number (1-based) and total count
    if (count > 0)
        printf("\n\n\n\n  Currently viewing Alien #%d out of %d", selected + 1, count);
    else
        printf("\n\n\n\n  No aliens in the zoo.");
}

