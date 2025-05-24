#include "zoo.h"

static Alien* zoo = NULL;
static int zoo_count = 0;
static int zoo_capacity = 0;

void add_alien_to_zoo(Alien alien)
{
    if (zoo_count == zoo_capacity)
    {
        zoo_capacity = (zoo_capacity == 0) ? 4 : zoo_capacity * 2;

        Alien* temp = realloc(zoo, zoo_capacity * sizeof(Alien));
        if (!temp)
        {
            printf("Failed to allocate memory for the zoo.\n");
            exit(1);
        }
        zoo = temp;
    }

    zoo[zoo_count++] = alien;
}

int display_zoo()
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
        else if (key == 13) // ENTER
        {
           return -1;
        }
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
    printf("Key binding  :   [^] Up    [v] Down    [ESC]  Exit    [ Enter ]  Exit\n\n");
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
        printf("            [^]  %d\n\n", start);
    }

    for (int i = start; i < start + visible_count && i < count; i++)
    {
        alien_card(aliens, i);
    }

    if (start + visible_count < count)
    {
        printf("            [v]  %d\n", (count - start - 1));
    }

    if (count <= 0)
    {
        reset_console();
        printf(" No Aliens in the zoo.");
    }
}

int get_zoo_count(void)
{
    return zoo_count;
}
Alien* get_zoo(void)
{
    return zoo;
}
int get_zoo_capacity(void)
{
    return zoo_capacity;
}
void zoo_setter(Alien* new_zoo, int count, int capacity) {
    if (zoo) free(zoo);
    zoo = new_zoo;
    zoo_count = count;
    zoo_capacity = capacity;
}
int* get_zoo_count_ptr(void) { return &zoo_count; }
int* get_zoo_capacity_ptr(void) { return &zoo_capacity; }
