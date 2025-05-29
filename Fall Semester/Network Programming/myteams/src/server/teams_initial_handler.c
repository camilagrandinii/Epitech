/*
** EPITECH PROJECT, 2024
** My Teams
** File description:
** Teams Handler File
*/
#include "../../libs/database.h"

team_t teams[MAX_TEAMS];

team_t *initialize_team(void)
{
    team_t *team = (team_t *)malloc(sizeof(team_t));

    if (team == NULL) {
        printf("Erro ao alocar memória para o time\n");
        exit(EXIT_FAILURE);
    }
    team->num_members = 0;
    for (int i = 0; i < MAX_USERS; i++) {
        team->members[i] = NULL;
    }
    return team;
}

void initialize_teams(void)
{
    int i = 0;

    for (i = 0; i < MAX_TEAMS; i++){
        teams[i] = *initialize_team();
    }
}

int find_empty_team(void)
{
    int i = 0;
    int comparison_result = 0;

    for (i = 0; i < MAX_TEAMS; i++){
        comparison_result = strcmp(teams[i].name, "");
        if (comparison_result == 0){
            return i;
        }
    }
    return -1;
}
