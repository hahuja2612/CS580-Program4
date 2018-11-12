#include<stdio.h>
#include<stdlib.h>

#ifndef TOURNAMENT_H
#define TOURNAMENT_H
typedef struct Player
{
    int offensive;
    int defensive;
    int number;
    int team;
    char *first;
    char *last;
       
} Player;

typedef struct Team
{
    char *name;
    Player *players;
	void (*delete)(struct Team *);
} Team;

void  deleteTeam(Team * t1);

Player * draftPlayers(char * filename, int team, int num_players);
Team * newTeam(char * name, Player * players);
Team * game(Team * t1, Team * t2);
//Team * tournament(Team **league,int noofteams);

#endif 
