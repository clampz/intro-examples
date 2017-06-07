/* clampz cant code but doesnt screw with mitigation, everything's enabled ;) */
/* gcc -m32 -z relro -z now -fPIE -pie -fstack-protector-all -o bears bears.c */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

struct polar {
    char name[16];
    unsigned int name_len;
    void (* print_me)(char *, int);
    unsigned long long int molecules_of_vitamin_a;
    unsigned int humans_killed;
};

struct grizzly {
    char name[16];
    unsigned int name_len;
    unsigned int months_hibernated;
    char location[8];
    unsigned int age;
};

void secret_admin_shell() {
    system("/bin/bash");
}

void edit_polar(struct polar *polie) {
    printf("Enter your name name (length is limited by length of old name for security!!): ");
    fflush(stdout);
    read(0, polie->name, strlen(polie->name));
}

void print_white_bear(char *bear_name, int humans_killed) {
    printf("%s has killed %d people\n", bear_name, humans_killed);
}

void print_brownish_bear(char *bear_name, int months_hibernated) {
    printf("%s has hibernated %d months\n", bear_name, months_hibernated);
}

void print_menu() {
    printf("== Menu ========================\n"
    "1. Make grizzly\n"
    "2. Make polar\n"
    "3. Delete grizzly\n"
    "4. Delete polar\n"
    "5. Print grizzly months hibernated\n"
    "6. Print polar humans killed\n"
    "7. Edit polar\n"
    "8. Exit\n");
}

int main() {
    struct polar *agnis = NULL;
    struct grizzly *fred = NULL;
    char y_or_n;
    unsigned int randfd;
    unsigned int option = 0;

    while (1) {
        print_menu();

        /* get menu option */
        printf("Which do you want to do? ");
        scanf("%u", &option);
        getc(stdin);

        if (option == 1) {
            if (fred != NULL) {
                printf("You already have a grizzly, would you like to rename it instead? (y/n) ");
                y_or_n = getc(stdin);
                if (y_or_n == 'n') {
                    continue;
                }
                printf("K, whats your grizzly's new name? ");
                fflush(stdout);
                read(0, fred->name, fred->name_len);
                continue;
            }
            fred = malloc(sizeof(struct grizzly));
            printf("K your grizzly is at 0x%08x\n", (unsigned int) fred);

            printf("Where is your grizzly at? ");
            fgets(fred->location, 8, stdin);
            fred->location[strcspn(fred->location, "\n")] = 0;

            printf("How old is your grizzly? ");
            scanf("%u", &fred->age);
            getc(stdin);

            printf("How many months has your grizzly hibernated? ");
            scanf("%u", &fred->months_hibernated);
            getc(stdin);

            while (fred->name_len <= 0 || fred->name_len > 16) {
                printf("How many characters is your grizzlys name? (must be less than 17) ");
                scanf("%u", &fred->name_len);
            }
            printf("What's your grizzlys name? ");
            fflush(stdout);
            read(0, fred->name, fred->name_len);
        } else if (option == 2) {
            if (agnis != NULL) {
                printf("You already have a polar, would you like to rename it instead? (y/n) ");
                y_or_n = getc(stdin);
                getc(stdin);
                if (y_or_n == 'n') {
                    continue;
                }
                printf("K, what's your polars new name? ");
                fflush(stdout);
                read(0, agnis->name, agnis->name_len);
                continue;
            }
            agnis = malloc(sizeof(struct polar));
            printf("K your polar is at 0x%08x\n", (unsigned int) agnis);

            agnis->print_me = &print_white_bear;

            printf("Whoa, how many humans has that polar killed? ");
            scanf("%u", &agnis->humans_killed);

            randfd = open("/dev/random", O_RDONLY);
            read(randfd, &agnis->molecules_of_vitamin_a, sizeof(long long int));
            close(randfd);

            while (agnis->name_len <= 0 || agnis->name_len > 16) {
                printf("How many characters is your polars name? (must be less than 17) ");
                scanf("%u", &agnis->name_len);
            }
            printf("What's your polars name? ");
            fflush(stdout);
            read(0, agnis->name, agnis->name_len);
        } else if (option == 3) {
            if (fred != NULL) {
                free(fred);
                printf("Deleted grizz\n");
            } else {
                printf("You haven't made a grizzly\n");
            }
        } else if (option == 4) {
            if (agnis != NULL) {
                free(agnis);
                printf("Deleted polar\n");
            } else {
                printf("You haven't made a polar\n");
            }
        } else if (option == 5) {
            if (fred != NULL) {
                print_brownish_bear(fred->name, fred->months_hibernated);
            } else {
                printf("You haven't made a grizzly\n");
            }
        } else if (option == 6) {
            if (agnis != NULL) {
                agnis->print_me(agnis->name, agnis->humans_killed);
            } else {
                printf("You haven't made a polar\n");
            }
        } else if (option == 7) {
            if (agnis != NULL) {
                edit_polar(agnis);
            } else {
                printf("You haven't made a polar\n");
            }
        } else if (option == 8) {
            printf("K laterz\n");
            exit(0);
        } else {
            printf("wat?\n");
        }
        option = 0;
    }
    printf("dope stuff yo! howd you get here?\n");
    return 0;
}
