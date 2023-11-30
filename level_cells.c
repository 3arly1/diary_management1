#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "level_cells.h"


t_d_cell *createCell(int value, int nblvl) {
    t_d_cell *newcell = (t_d_cell*) malloc(sizeof(t_d_cell));
    newcell->nb_level = nblvl;
    newcell->next = malloc((unsigned long) newcell->nb_level*sizeof(t_d_cell*));
    newcell->value = value;
    for (int i = 0; i < newcell->nb_level; i++) {
        newcell->next[i] = malloc(sizeof(t_d_cell));
        newcell->next[i] = NULL;
    }
    return newcell;
}

/*
t_contact *createContact() {
    t_contact *newcontact;
    newcontact->nb_appointments = 0;
    newcontact->appointments = (APPOINTMENT*)malloc(newcontact->nb_appointments*sizeof(APPOINTMENT));
    printf("Enter the Surname and then the first name : ");
    newcontact->surname_firstname = scanString();
    for (int i = 0; i < 4; i++) {
        newcontact->next[i] = malloc(sizeof(t_contact));
        newcontact->next[i] = NULL;
    }
    return newcontact;
}

APPOINTMENT *createAppointment(t_contact *contact) {
    APPOINTMENT *newapp;
    int i = 0;
    char *duration;
    char *date;
    char *Slash;
    printf("Enter the date of the appointment (dd/mm/yyyy) : ");
    date = scanString();
    while (strlen(date) != 10) {
        printf("You haven't entered the date correctly, please enter the date again (dd/mm/yyyy) : ");
        date = scanString();
    }
    newapp->date.day = atoi(date);
    Slash = strchr(date, "/");
    strcpy(date, Slash+1);
    newapp->date.month = atoi(date);
    Slash = strchr(date, "/");
    strcpy(date, Slash);
    newapp->date.year = atoi(date);
    printf("Enter the duration of the appointment (hh/mm) : ");
    duration = scanString();
    while (strlen(duration) != 5) {
        printf("You haven't entered the duration correctly, please enter the duration again (hh/mm) : ");
        duration = scanString();
    }
    newapp->length.hour = atoi(duration);
    Slash = strchr(duration, "/");
    strcpy(duration, Slash+1);
    newapp->length.minute = duration;
    printf("Enter the time at which you want your appointment (hh/mm) : ");
}
*/