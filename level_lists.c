#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "level_lists.h"
#include "level_cells.h"


t_d_list *createEmptyList(int maxlvl) {
    t_d_list *newlist = (t_d_list*)malloc(sizeof(t_d_list));
    newlist->nb_level = maxlvl;
    newlist->head = (t_d_cell**)malloc((unsigned long) newlist->nb_level*sizeof(t_d_cell*));
    for (int i = 0; i < newlist->nb_level; i++) {
        newlist->head[i] = NULL;
    }
    return newlist;
}

void insertCelltoHead(t_d_list *list, t_d_cell *cell) {
    if (cell->nb_level > list->nb_level) {
        cell->nb_level = list->nb_level;
    }
    for (int i = 0; i < list->nb_level; i++) {
        list->head[i] = cell;
    }
}

void displayList(t_d_list mylist, int level){
    t_d_cell* tmp;
    tmp = mylist.head[level];
    printf("[list head_%d @-]-->", level);
    while (tmp != NULL){
        printf("[ %d|@-]-->", tmp->value);
        tmp = tmp->next[level];
    }
    printf(" NULL\n");
}

void displayLevels(t_d_list mylist) {
    for (int i = 0; i < mylist.nb_level; i++) {
        displayList(mylist, i);
    }
}

// In this function, we insert values in a list (like asked in PART 2 of the project, therefore, the cell we give as parameter is not used because the values are just 2^n - 1)
void insertCellInList(t_d_list *mylist) {
    t_d_cell *cell;
    int nb = 2, a = 2;
    // Here, this loop allows to put 2 to the power n
    for (int i = 0; i < mylist->nb_level-1; i++) {
        nb = nb*2;
    }
    int levels[nb];
    for (int i = 0; i < nb; i++) {
        levels[i] = 0;
    }
    for (int i = 0; i < mylist->nb_level-1; i++) {
        for (int j = 1; j < nb+1; j++) {
            if (j % a == 0) {
                levels[j-1] +=1;
            }
        }
        a = a*2;
    }
    t_d_cell *tmp;
    for (int i = nb; i+1 > 0; i--) {
        cell = createCell(i, mylist->nb_level);
        for (int j = 0; j < mylist->nb_level; j++) {
            tmp = mylist->head[j];
            if (mylist->head[j] == NULL && levels[i] >= j) {
                mylist->head[j] = cell;
            }
            else if (levels[i] >= j && mylist->head[j] != NULL) {
                cell->next[j] = mylist->head[j];
                mylist->head[j] = cell;
            }   
        }
    }
}


int searchForValue0(t_d_list *mylist, int val) {
    t_d_cell *tmp = mylist->head[0];
    int n = 0;
    while (tmp != NULL && tmp->value != val) {
        tmp = tmp->next[0];
        n += 1;
    }
    if (tmp == NULL) {
        return 999;
    }
    else {
        return n;
    }
}
/*
int searchForValue1(t_d_list *mylist, int val) {
    int n = 0;
    for (int i = mylist->nb_level-1; i > -1; i--) {
        t_d_cell *tmp;
        tmp = mylist->head[i];
        while (tmp != NULL && tmp->value != val) {
            tmp = tmp->next[i];
            n += 1;
        }
        if (tmp != NULL) {
            if (tmp->value == val) {
                return n;
            }
        }
    }
    return 999;
}
*/

int searchForValue1(t_d_list *mylist, int val) {
    if (val >= pow(2, mylist->nb_level)) {
        return 1;
    }
    int n = 0, i =mylist->nb_level-1;
    t_d_cell *tmp;
    tmp = mylist->head[i];
    while (tmp != NULL && tmp->value != val) {
        if (tmp->value > val) {
            i--;
            n++;
            tmp = mylist->head[i];
        }
        else if(tmp->next[i] == NULL){
            i--;
            n++;
        }
        else if (tmp->next[i] != NULL && tmp->next[i]->value > val){
            i--;
            n++;
            //tmp = tmp->next[i];
        }
        else{
            tmp = tmp->next[i];
            n++;
        }
    }
    if (tmp != NULL) {
        if (tmp->value == val) {
            return n;
        }
    }
    free(tmp);
    return 999;
}
