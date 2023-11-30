#include <stdio.h>
#include <stdlib.h>

#ifndef LEVEL_CELLS_H
#define LEVEL_CELLS_H

typedef struct s_d_cell {
    int value;
    int nb_level;
    struct s_d_cell **next;
}t_d_cell;

/*
typedef struct s_DATE {
    int day;
    int month;
    int year;
} DATE;

typedef struct s_TIME {
    int hour;
    int minute;
} TIME, DURATION;

typedef struct s_contact {
    int nb_appointments;
    char *surname_firstname;
    APPOINTMENT *appointments;
    struct s_contact *next[4];
} t_contact;

typedef struct s_appointment {
    DATE date;
    TIME time;
    DURATION length;
    char *purpose; 
    struct s_appointment *next;
} APPOINTMENT;

t_contact *createContact();
APPOINTMENT *createAppointment(t_contact *);
*/

t_d_cell *createCell(int value, int nblvl);

/*
 * "value" is the value to be put in the cell
 * "nblvl" is the number of levels this cell should contain
 * this function returns a pointer to the newly created cell.
 */

#endif
