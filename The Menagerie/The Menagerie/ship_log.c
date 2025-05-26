#include "ship_log.h"

#define VISITS_PER_PAGE 5// for planet log

// for alien log
#define NUM_TYPES 7
#define VARIANTS_PER_TYPE 10
#define ALIENS_PER_PAGE 2

void planet_log()
{
    int selected = 0;
    int current_page = 0;

    while (1)
    {
        reset_console();
        print_small_window();

        if (num_visited_planets == 0)
        {
            printf("\n                                     No planets visited yet.\n");
        }
        else
        {
            int total_pages = (num_visited_planets + VISITS_PER_PAGE - 1) / VISITS_PER_PAGE;
            if (current_page >= total_pages)
                current_page = total_pages - 1;

            int start = current_page * VISITS_PER_PAGE;
            int end = start + VISITS_PER_PAGE;
            if (end > num_visited_planets) end = num_visited_planets;

            printf("\n                              [<]/[>] Page | [Enter]/[Esc] Exit\n\n");
            printf("                     Shiplog Update: %d planets explored on your journey.\n", num_visited_planets);
            printf("\n\n     Planet Log (Page %d/%d)\n\n", current_page + 1, total_pages);

            for (int i = start; i < end; ++i)
            {
                PlanetVisit visit = visited_planets[i];
                printf("      %2d. Planet: %s | Terrain: %s | Distance: %.1f ly\n",
                    i + 1, visit.planet.name, visit.planet.terrain, visit.planet.distance / 4);
                printf("                       Alien: %s | Type: %s\n\n",
                    visit.alien.nickname[0] ? visit.alien.nickname : "[NO NAME]",
                    get_alien_type_name(visit.alien.type));
            }
        }

        int key = _getch();
        if (key == 0 || key == 224) key = _getch();

        if (key == 75 && current_page > 0) // LEFT
            current_page--;
        else if (key == 77 && (current_page + 1) * VISITS_PER_PAGE < num_visited_planets) // RIGHT
            current_page++;
        else if (key == 13 || key == 27) // ENTER or ESC
            break;
    }
}


void alien_log(const Zoo* zoo)
{

    int selected_type = 0;
    int current_page = 0;

    while (1)
    {
        reset_console();

        AlienType type = (AlienType)selected_type;
        const char* type_name = get_alien_type_name(type);

        // Count how many aliens were found
        int found_count = 0;
        for (int v = 0; v < VARIANTS_PER_TYPE; ++v)
        {
            Alien dummy;
            if (find_alien_in_zoo(zoo, type, v, &dummy))
                found_count++;
        }

        int total_pages = (VARIANTS_PER_TYPE + ALIENS_PER_PAGE - 1) / ALIENS_PER_PAGE;
        if (current_page >= total_pages)
            current_page = total_pages - 1;

        print_small_window();
        printf("\n                       [^]/[v] Category | [<]/[>] Page | [Enter/Esc] Exit\n\n");
        pirnt_alien_type_title(type);
        printf("\n                                       [%d/%d collected]   \n", found_count, VARIANTS_PER_TYPE);

        int start_variant = current_page * ALIENS_PER_PAGE;
        int end_variant = start_variant + ALIENS_PER_PAGE;
        if (end_variant > VARIANTS_PER_TYPE)
            end_variant = VARIANTS_PER_TYPE;

        for (int v = start_variant; v < end_variant; ++v)
        {
            Alien found;
            if (find_alien_in_zoo(zoo, type, v, &found))
            {
                printf("Alien %s-%d: [%s]\n\n", type_name, v + 1, found.nickname);
                print_alien_art(&found, v);
            }
            else
            {
                printf("Alien %s-%d: [UNKNOWN]\n\n", type_name, v + 1);
                print_species_art("unknown", 0);
            }
            printf("\n");
        }

        int missing = VARIANTS_PER_TYPE - found_count;
        if (missing == 0)
        {
            printf("All aliens collected in this category!\n\n");
        }

        printf("\n  Page %d/%d\n", current_page + 1, total_pages);

        int key = _getch();
        if (key == 0 || key == 224) key = _getch();

        if (key == 72 && selected_type > 0) // UP
        {
            selected_type--;
            current_page = 0;
        }
        else if (key == 80 && selected_type < NUM_TYPES - 1) // DOWN
        {
            selected_type++;
            current_page = 0;
        }
        else if (key == 75 && current_page > 0)// LEFT
        {
            current_page--;
        }
        else if (key == 77 && current_page < total_pages - 1) // RIGHT
        {
            current_page++;
        }
        else if (key == 27 || key == 13)  // ESC or ENTER
        {
            break;
        }
    }
}