#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include "tournament.h"

Team * newTeam(char * name, Player * players)
{
//function for the new team with
//the arguments of name and players
	Team *t = malloc(sizeof(Team));	
	t->name = name;
	t->players = players;
	t->delete=deleteTeam;
	return t;
}

Player * draftPlayers(char * filename, int team, int noofplayers)
{
//function for the new team with
//the arguments of filename, team and noofplayers

  Player *p = malloc(sizeof(Player) * 32);
  char *p1;
  char oneline[150];
  int linecount = 0;
  int no_of_players=0;
  int team_no;
  FILE * fptr;
  fptr = fopen(filename,"r");
  for (;;)
            {

                fgets(oneline,150,fptr);
                p1 = strtok (oneline,",:");
                //opening file players.dat and accessing the details
                 while (p1!= NULL)
            {  linecount = linecount + 1;
               if (linecount == 1)
             { team_no = atoi(p1);
                 if (team_no  == team)
                 {p[no_of_players].team = team;
                 }
             }
             if (linecount == 2)
             {//team_no = atoi(p1);
             if (team_no == team)
                 {p[no_of_players].first = p1;
                 }
             
             }
             if (linecount == 3)
             {//team_no = atoi(p1);
             if (team_no == team)
                 {p[no_of_players].last = p1;
                  }
            // if (linecount == 3)
             //{if (team_no == team)}
             
             }
             if (linecount == 4)
             {//team_no = atoi(p1);
             if (team_no == team)
                 {p[no_of_players].number = atoi(p1);
                 }
             

             //{if (team_no == team)}
             }
             if (linecount == 5)
             {//team_no = atoi(p1);
             if (team_no == team)
                 {p[no_of_players].offensive = atoi(p1);
                 }
             }
             if (linecount == 6)
             {//team_no = atoi(p1);
                 if (team_no == team)
                 {p[no_of_players].defensive = atoi(p1);
                     no_of_players = no_of_players + 1;
                 }
 	         linecount = 0;
             }
             p1 = strtok (NULL, ",:");
 	 }
                if (feof( fptr )) break;
            }
            fclose(fptr);
     return p;
}


Team * play(Team * t1, Team * t2)
{
int temp,team1=10, team2=9, team3=5;
temp=team1;
team1=team2;
team3=team2;
team3=temp;
}


void deleteTeam(Team * t1)
{
free(t1->players);
//deleting the players and freeing the space 
free(t1);
//deleting the team and freeing the space 

}

Team * game(Team * t1, Team * t2)
{
  
   if ( (t1 == NULL) && (t2 == NULL))
   {
   return NULL;
   };
   
   int x;
   int team1_def = 0;
   int team1_off = 0;
   int team2_def = 0;
   int team2_off = 0;
   int team1_score = 0;
   int team2_score = 0;
   int team1_strike = 0;
   int team2_strike = 0;
   int team1_defense = 0;
   int team2_defense = 0;
   int h=10;
   for (x=0;x<h;x++)
   {
   team1_def = team1_def + t1->players[x].defensive;
   //total defense strength is being calculated of team1
   team2_def = team2_def + t2->players[x].defensive;
   //total defense strength is being calculated of team2
   team1_off = team1_off + t1->players[x].offensive;
   //total offense strength is being calculated of team 1
   team2_off = team2_off + t2->players[x].offensive;
   //total offense strength is being calculated of team 2
   };
   int y;
   
  for (y=0;y<h;y++)
   {
   //team1_strike = rand(); 
   //team2_strike = rand();
   //team1_defense = rand();
   //team2_defense = rand();
   
   team1_strike = rand()%team1_off; 
   team2_strike = rand()%team2_off;
   team1_defense = rand()%team1_def;
   team2_defense = rand()%team2_def;
   
   
   if (team2_strike > team1_defense)
   {team2_score = team2_score + 1;
   };
   
   
   if (team1_strike > team2_defense)
   {team1_score = team1_score + 1;
   };
   
   }; 
   if (team1_score >  team2_score)
   {
   return t1; // team1's score is greater than team 2
   }
   else 
   if (team2_score > team1_score)
   {
   return t2;// team2's score is greater than team 1
   }
   else 
   if (team1_score == team2_score)   // team1's score is equal to team 2
   {if ((team1_def + team1_off) > (team2_def  + team2_off))
   {return t1;}
   else
   {return t2;}
}   
};
Team * tournament(Team **league, int noofteams)
{  
    //int k = 0;
    //int n = noofteams;
    
    int teamcount = noofteams;
    int teamcount1 = noofteams-1;
    Team *group, *a1,*a2,*a3,*a4,*a5,*a6,*a7;  
    /*Team *a1; 
    Team *a2; 
    Team *a3; 
    Team *a4; 
    Team *a5; 
    Team *a6; 
    Team *a7;*/
    while(noofteams>1)
    {
    if(noofteams%2!=0)
    {
    printf("Team is not a Power of 2");
    //checking if the no of teams is a power of 2 or not
    return NULL;
    break;
    }
    noofteams=noofteams/2;
    }
    
    int val;
    if  (teamcount  >= 8)
    {
    val = teamcount / 8;
    }
  // printf("\n No.of Teams are : %d \n",val);
   if (teamcount == 2)
   {
    a1 =  game(league[0], league[1]);
    return a1;
   }
   if (teamcount == 4)
   {
    a1 =  game(league[0], league[1]);
    a2 =  game(league[2], league[3]);
    a3 =  game(a1,a2);
    return a3;
   }
   if (teamcount >= 8)
   {
   for (int k=0;k<val;k++)
    {
        if (k==0)
        {
            teamcount = teamcount - 1;
            a1 =  game(league[teamcount1-teamcount], league[teamcount]);
            teamcount = teamcount - 1;
	          a2 =  game(league[teamcount1-teamcount], league[teamcount]);
	          teamcount = teamcount -1;
    	      a3 =  game(league[teamcount1-teamcount], league[teamcount]);
	          teamcount = teamcount -1;
            a4 =  game(league[teamcount1-teamcount], league[teamcount]);
            a5 = game(a1,a2);
            a6 = game(a3,a4);
             group = game(a5,a6);
           // return group;


        }
        if (k > 0)
        {
            teamcount = teamcount - 1;
            a1 =  game(league[teamcount1-teamcount], league[teamcount]);
            teamcount = teamcount - 1;
            a2 =  game(league[teamcount1-teamcount], league[teamcount]);
            teamcount = teamcount -1;
            a3 =  game(league[teamcount1-teamcount], league[teamcount]);
            teamcount = teamcount -1;
            a4 =  game(league[teamcount1-teamcount], league[teamcount]);
            a5 = game(a1,a2);
            a6 = game(a3,a4);
            a7 = game(a5,a6);
	         group = game(a7,group);
   // return group;
        
        }

    }
   // return group;
    }
    return group;
}
// try ka code
int cnt_players()
{ int teamcount=8;
int x=0;
for (int i=0; i<teamcount;i++){
teamcount++;
x= teamcount-1;
//printf("teams are %d", teamcount);
}
}
