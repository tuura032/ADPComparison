// Create a program that compares Harris top 164 to ESPN top 164 players
// Return the difference in rank of players
// Sort the difference

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIST_SIZE 164

#include "structfantasy.h"

// Store Player name and their rank
playerrank harris[LIST_SIZE];
playerrank espn[LIST_SIZE];
node value[LIST_SIZE];
node *head = NULL;
node *trav = NULL;
int c;
int max;
int min;
int n;

//TODO ability to enter rank files at command line
int main(void)
{
    // Initialize variables
    int temprank = 0;
    char lastname[20];
    char lastname2[20];


    // open harris ranks, ESPN Ranks, and new files
    FILE *fph = fopen("harrisranks.txt", "r");
        if (!fph)
            return 1;
    FILE *fpe = fopen("ESPNRanks.txt", "r");
        if (!fpe)
            return 2;
    FILE *fpo = fopen("ordered.csv", "w");
        if (!fpo)
            return 3;

    // Load data into structs
    for (int i = 0; i < LIST_SIZE; i++)
    {
        temprank++;
        fscanf(fph, "%s", lastname);
        {
            strcpy(harris[i].name, lastname);
            strcpy(value[i].name, harris[i].name);
            harris[i].rank = temprank;
        }
        fscanf(fpe, "%s", lastname2);
        {
            strcpy(espn[i].name, lastname2);
            espn[i].rank = temprank;
        }
        if(feof(fph))
            break;
    }
    fclose(fph);
    fclose(fpe);

    // Compare Harris ranks to ESPN Ranks to find DIF (difference in ranks)
    for (int k = 0; k < LIST_SIZE; k++)
    {
        int x = harris[k].rank;

        for (int j = 0; j < (LIST_SIZE); j++)
        {
            if (strcmp(harris[k].name, espn[j].name) == 0)
            {
                int y = espn[j].rank;
                int dif = (y-x);
                    value[k].rank = dif;
                break;
            }
            if (j == (LIST_SIZE-1))
            {
                // TODO make struct unranked to store these players
                value[k].rank = 88 + 1 + c;
                c++;
            }
        }
    }

    // Find MIN + Max Differentials
    for (int d = 0; d < LIST_SIZE; d++)
    {
        if (value[d].rank > max && value[d].rank < 80)
        {
            max = value[d].rank;
        }
        if (value[d].rank < min)
        {
            min = value[d].rank;
            //TODO Create char *playermin = value[d].name;
        }
    }
    printf("MAX: %d\n", max);
    printf("MIN: %d\n", min);

    n=min;
    //TODO Replace "DWatson" with char *playermin
    // Make a linked list in order of rank differential
    for (int j = 0; j < LIST_SIZE; j++)
    {
        for (int i = 0; i < LIST_SIZE; i++)
        {
            //check if differential is equal to min
            if (value[i].rank == n)
            {
                if (strcmp(value[i].name, "DWatson") == 0)
                {
                    head = &value[i];
                }
                else
                {
                    value[i].next = head;
                    head = &value[i];
                }
            }
        }
        n++;
    }


    // Print Relevant data to csv doc
    trav = head;
    while (trav->rank > 88)
    {
        fprintf(fpo, "Unranked in ESPN, %s\n", trav->name);
        trav = trav->next;
    }
    fprintf(fpo, "\n// OUT ON AN ISLAND (> 50 spots) //\n");
    while (trav->rank > 50)
    {
            fprintf(fpo, "%d,%s\n", trav->rank, trav->name);
            trav = trav->next;
    }
    fprintf(fpo, "\n// LIKELY TO APPEAR YOUR FANTASY ROSTER (20 - 50 spots) //\n");
    while (trav->rank > 20)
    {
        fprintf(fpo, "%d,%s\n", trav->rank, trav->name);
        trav = trav->next;
    }
    fprintf(fpo, "\n// 1-2 ROUNDS HIGHER ON (10 - 20 spots)//\n");
    while (trav->rank > 10)
    {
        fprintf(fpo, "%d,%s\n", trav->rank, trav->name);
        trav = trav->next;
    }
    fprintf(fpo, "\n// 1 ROUND HIGHER ON (5 - 10 spots)//\n");
    while (trav->rank > 5)
    {
        fprintf(fpo, "%d,%s\n", trav->rank, trav->name);
        trav = trav->next;
    }
    fprintf(fpo, "\n// A FEW SPOTS HIGHER ON (1 - 5) //\n");
    while (trav->rank > 0)
    {
        fprintf(fpo, "%d,%s\n", trav->rank, trav->name);
        trav = trav->next;
    }
    fprintf(fpo, "\n// AGREE //\n");
    while (trav->rank == 0)
    {
        fprintf(fpo, "%d,%s\n", trav->rank, trav->name);
        trav = trav->next;
    }
    fprintf(fpo, "\n// A FEW SPOTS LOWER ON (1 - 5) //\n");
    while (trav->rank > -5)
    {
        fprintf(fpo, "%d,%s\n", trav->rank, trav->name);
        trav = trav->next;
    }
    fprintf(fpo, "\n// 1 ROUND LOWER ON (5 - 10 spots) //\n");
    while (trav->rank > -10)
    {
        fprintf(fpo, "%d,%s\n", trav->rank, trav->name);
        trav = trav->next;
    }
    fprintf(fpo, "\n// 1-2 ROUNDS LOWER ON (10 - 20 spots) //\n");
    while (trav->rank > -20)
    {
        fprintf(fpo, "%d,%s\n", trav->rank, trav->name);
        trav = trav->next;
    }
    fprintf(fpo, "\n// PROBABLY NOT DRAFTING (> 20 spots) //\n");
    while (trav->next != NULL)
    {
        fprintf(fpo, "%d,%s\n", trav->rank, trav->name);
        trav = trav->next;
    }
    fclose(fpo);
}
