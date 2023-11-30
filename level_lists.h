#include <stdio.h>
#include <stdlib.h>
#include "level_cells.h"

#ifndef LEVEL_LISTS_H
#define LEVEL_LISTS_H


typedef struct s_d_list {
    int nb_level;
    t_d_cell **head;
}t_d_list;

/*
typedef struct s_contact_list {
    t_contact *head[4];
} t_contact_list;
*/

t_d_list *createEmptyList(int nblvl);
void insertCelltoHead(t_d_list *list, t_d_cell *cell);
void displayList(t_d_list mylist, int level);
void displayLevels(t_d_list mylist);
void insertCellInList(t_d_list *mylist);
int searchForValue0(t_d_list *mylist, int val);
int searchForValue1(t_d_list *mylist, int val) ;

#endif
