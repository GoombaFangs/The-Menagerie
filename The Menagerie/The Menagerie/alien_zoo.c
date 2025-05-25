#include "alien_zoo.h"

int add_alien_to_zoo(Zoo* zoo, Alien alien)
{
    if (zoo->count == zoo->capacity)
    {
        zoo->capacity = (zoo->capacity == 0) ? 4 : zoo->capacity * 2;

        Alien* temp = realloc(zoo->list, zoo->capacity * sizeof(Alien));
        if (!temp)
        {
            printf("Failed to allocate memory for the zoo.\n");
            exit(1);
        }
        zoo->list = temp;
    }

    zoo->list[zoo->count++] = alien;
    return zoo->count;
}

void print_zoo_aliens(Alien* aliens, int count, int selected, int visible_count) 
{
    reset_console();
	print_big_window();
    printf("\n                 Key binding  :   [^] Up    [v] Down    [Enter/Esc] Exit\n\n");
    printf("                          You have collected %d aliens in total!\n\n", count);

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
        return;
    }
}

bool find_alien_in_zoo(const Zoo* zoo, AlienType type, int variant, Alien* result)
{
    for (int i = 0; i < zoo->count; ++i)
    {
        if (zoo->list[i].type == type && zoo->list[i].art_variant == variant)
        {
            if (result)
                *result = zoo->list[i];
            return true;
        }
    }
    return false;
}

void free_zoo(Zoo* zoo)
{
    if (zoo->list != NULL)
    {
        free(zoo->list);
        zoo->list = NULL;
    }
    zoo->count = 0;
    zoo->capacity = 0;
}