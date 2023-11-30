#include <stdio.h>
#include <stdio.h>
#include <math.h>

#include "level_lists.h"
#include "level_cells.h"
#include "timer.h"


int main() {
    t_d_list *mylist;
    int nblvl = 7;
    FILE *log_file = fopen("log.txt", "w"); 
    char format[] = "%d\t%s\t%s\n" ;
    char *time_lvl0;
    char *time_all_levels;
    for (nblvl = 7; nblvl < 15; nblvl++) {
        printf("Timer for level %d\n", nblvl);
        mylist = createEmptyList(nblvl);
        insertCellInList(mylist);
        startTimer();
        for (int j = 0; j < 10; j++) {
            for (int i = 0; i < pow(2, nblvl); i++) {
                searchForValue0(mylist, i);
            }
        }
        stopTimer();
        time_lvl0 = getTimeAsString();
        displayTime();
        startTimer();
        for (int j = 0; j < 10; j++) {
            for (int i =1; i < pow(2,nblvl); i++) {
                searchForValue1(mylist, i);
            }
        }
        stopTimer();
        time_all_levels = getTimeAsString(); 
        fprintf(log_file,format,nblvl,time_lvl0, time_all_levels);
        displayTime();
        printf("\n");
        free(time_lvl0);
        free(time_all_levels);
    }
    fclose(log_file);
    return 0;
}