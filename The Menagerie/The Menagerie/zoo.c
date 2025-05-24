#include "zoo.h"
#include <stdio.h> // Needed for FILE operations

#define FRAME_WIDTH 13

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

void remove_alien_from_zoo(int index) {
    if (index < 0 || index >= zoo_count) return;
    for (int i = index; i < zoo_count - 1; i++) {
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
    save_zoo_to_file("zoo.txt");
}

void save_zoo_to_file(const char* filename)
{
    FILE* file = fopen(filename, "wb");
    if (!file) 
    {
        printf("Could not open file for writing.\n");
        return;
    }
    fwrite(&zoo_count, sizeof(int), 1, file);
    fwrite(zoo, sizeof(Alien), zoo_count, file);
    fclose(file);
}

void load_zoo_from_file(const char* filename)
{
    FILE* file = fopen(filename, "rb");
    if (!file) 
    {
        // File might not exist yet, that's OK
        return;
    }
    int count = 0;
    fread(&count, sizeof(int), 1, file);
    if (count > 0) {
        Alien* temp = malloc(count * sizeof(Alien));
        if (!temp) 
        {
            printf("Failed to allocate memory for loading zoo.\n");
            fclose(file);
            return;
        }
        fread(temp, sizeof(Alien), count, file);
        free(zoo);
        zoo = temp;
        zoo_count = count;
        zoo_capacity = count;
    }
    fclose(file);
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
        else if (key == 13) // ENTER
        {
            // Confirmation menu
            reset_console();
            printf("Are you sure you want to remove that alien?\n\n");
            int choice = zoo_remove_alien_menu(zoo, zoo_count, selected);

            if (choice == 0) 
            { // Remove
                remove_alien_from_zoo(selected);
                if (zoo_count == 0) return -1;
                if (selected >= zoo_count) selected = zoo_count - 1;
            }
            // If Cancel, do nothing (just return to zoo screen)
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

void print_zoo_menu_options(int selected, const char* menu_list[], int amount) {
    for (int i = 0; i < amount; i++) 
    {
        const char* text = menu_list[i];
        int len = (int)strlen(text);
        int padding_total = FRAME_WIDTH - len;
        int padding_left = padding_total / 2;
        int padding_right = padding_total - padding_left;

        if (i == selected) {
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
        } else {
            printf("\n");
            printf("                %s\n", text);
            printf("\n");
        }
        printf("\n");
    }
}

void print_alien_visual_and_info(Alien* aliens, int index)
{
    // Print the visual and info card side by side
    // Assume print_alien_art prints 8 lines of art (adjust as needed)
    // We'll print the info card line by line in parallel

    // Prepare info card lines
    char info_lines[8][80];
    snprintf(info_lines[0], 80, "+--------- Alien %d ---------+", index + 1);
    snprintf(info_lines[1], 80, "+----------------------------+");
    snprintf(info_lines[2], 80, "| Species  : %-15s |", get_alien_type_name(aliens[index].type));
    snprintf(info_lines[3], 80, "| Sex      : %-15c |", aliens[index].sex);
    snprintf(info_lines[4], 80, "| Age      : %-15d |", aliens[index].age);
    snprintf(info_lines[5], 80, "| Size     : %-15s |", aliens[index].size);
    snprintf(info_lines[6], 80, "| Diet     : %-15s |", aliens[index].diet);
    snprintf(info_lines[7], 80, "| Nickname : %-15s |", aliens[index].nickname[0] ? aliens[index].nickname : "(none)");

    // Print art and info card side by side
    for (int i = 0; i < 8; ++i) 
    {
        // Print art line (you need to implement get_alien_art_line)
        printf("    ");
        print_alien_art(& aliens[index], i); // This should print one line of the art
        printf("    %s\n", info_lines[i]);
    }
    // Print the bottom border of the info card
    printf("    ");
    print_alien_art(&aliens[index], 8); // Last line of art, if any
    printf("    +----------------------------+\n");
}

int zoo_remove_alien_menu(Alien* aliens, int count, int selected) {
    const char* options[] = { "Remove", "Cancel" };
    int menu_selected = 0;

    while (1) {
        reset_console();
        stars(); // Stars at the very top

        printf("\n\n");
        print_alien_visual_and_info(aliens, selected);

        // Print menu options below, centered
        printf("\n\n");
        print_zoo_menu_options(menu_selected, options, 2);

        // Handle input
        int key = _getch();
        if (key == 0 || key == 224) key = _getch();

        if (key == 72 && menu_selected > 0) // Up
            menu_selected--;
        else if (key == 80 && menu_selected < 1) // Down
            menu_selected++;
        else if (key == 13) // Enter
        {
            reset_console();
            return menu_selected; // 0 = Remove, 1 = Cancel
        }
        else if (key == 27) // Escape
        {
            reset_console();
            return 1; // Treat as Cancel
        }
    }
}