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
            reset_console();
            int choice = zoo_remove_alien_menu(zoo, zoo_count, selected);

            if (choice == 0)
            { // Remove
                remove_alien_from_zoo(selected);
                if (zoo_count == 0) return -1;
                if (selected >= zoo_count) selected = zoo_count - 1;
            }
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

void remove_alien_from_zoo(int index)
{
    if (index < 0 || index >= zoo_count) return;
    for (int i = index; i < zoo_count - 1; i++)
    {
        zoo[i] = zoo[i + 1];
    }
    zoo_count--;
    if (zoo_count > 0 && zoo_count < zoo_capacity / 4)
    {
        int new_capacity = zoo_capacity / 2;
        if (new_capacity < 4) new_capacity = 4;
        Alien* new_zoo = realloc(zoo, new_capacity * sizeof(Alien));
        if (new_zoo)
        {
            zoo = new_zoo;
            zoo_capacity = new_capacity;
        }
    }
    save_data("zoo_capacity.txt", get_zoo_capacity_ptr(), sizeof(int), 1);
    save_data("zoo_count.txt", get_zoo_count_ptr(), sizeof(int), 1);
    save_data("zoo_array.txt", get_zoo(), sizeof(Alien), get_zoo_count());
} 
int zoo_remove_alien_menu(Alien* aliens, int count, int selected) {
    const char* options[] = { "  Remove  ", "  Cancel  " };
    // 5 = custom style for remove menu, or you can use 4 for ship log style
    int menu_selected = input_text(options, 2, 4, ""); // 4 = ship log style

    reset_console();
    return menu_selected; // 0 = Remove, 1 = Cancel
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
