/*
** EPITECH PROJECT, 2024
** Panoramix
** File description:
** Panoramix Main File
*/
#include "../libs/panoramix.h"

parameters_t parameters;

void start_fight(void)
{
    start_pot();
    start_druid();
    start_villagers();
    end_villagers();
}

void check_parameters(void)
{
    if (parameters.nb_villagers <= 0 || parameters.pot_size < 0 ||
        parameters.nb_fights < 0 || parameters.nb_refills < 0) {
        fprintf(stderr,
            "USAGE: <nb_villagers> <pot_size>"
            "<nb_fights> <nb_refills>\n");
        fprintf(stderr, "Values must be > 0.\n");
        exit(84);
    }
}

void parse_arguments(int argc, char *argv[])
{
    if (argc != 5) {
        fprintf(stderr,
            "USAGE: <nb_villagers> <pot_size>"
            "<nb_fights> <nb_refills>\n");
        exit(84);
    } else {
        parameters.nb_villagers = atoi(argv[1]);
        parameters.pot_size = atoi(argv[2]);
        parameters.nb_fights = atoi(argv[3]);
        parameters.nb_refills = atoi(argv[4]);
        check_parameters();
    }
}

int main(int argc, char *argv[])
{
    parse_arguments(argc, argv);
    start_fight();
    return 0;
}
