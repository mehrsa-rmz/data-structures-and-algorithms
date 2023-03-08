#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct student {
	char *nume;
	char *prenume;
	char id[6];
	double note[5];
}student;

/* ----- Cerinta 1 -----*/

//---Prelucrarea informatiilor pentru un student---
int nr_restante(student stud);
double medie(student stud);

//---Instantierea & popularea vectorului de studenti---
void alocare_memorie(student **vector, int dimensiune);
void citire_fisier(student *vector, int dimensiune, FILE *input);
void afisare_fisier(student *v, int dim);

//--- Functiile comentate le puteti folosi ca sa introduceti date de la tastatura
//sau sa afisati date in terminal ---
//void populare_vector(student *vector, int dimensiune);
//void afisare_student(student stud);
//Observatie: implementarea lor nu se puncteaza in plus.

//---Sortarea vectorului de studenti---
void swap(student *first_std, student *second_stud);
void sortare_vector(student *vector, int dimensiune);

/* ----- Cerinta 2 -----*/
student* eliminare_restantieri(student *vector, int *dimensiune);


/* ----- Cerinta 3 -----*/
void realocare_memorie (student **vector, int dimensiune);
void adaugare_student (student *vector, int poz, int dimensiune, student stud);


