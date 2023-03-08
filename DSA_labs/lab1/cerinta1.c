#include "student.h"

int nr_restante(student stud)
{
	int nr = 0;
	for (int i = 0; i < 5; i++)
		if (stud.note[i] < 5)
			nr++;
	return nr;
}

double medie(student stud)
{
	double ma = 0;
	for (int i = 0; i < 5; i++)
		ma += stud.note[i];
	ma /= 5.0;
	return ma;
}

void alocare_memorie(student **vector, int dimensiune)
{
	*vector = (student *)calloc(dimensiune, sizeof(student));
}

void citire_fisier(student *vector, int dimensiune, FILE *input)
{
	char s[30];
	for (int i = 0; i < dimensiune; i++)
	{
		fscanf(input, "%s", s);
		vector[i].nume = (char *)malloc(strlen(s) * sizeof(char));
		strcpy(vector[i].nume, s);

		fscanf(input, "%s", s);
		vector[i].prenume = (char *)malloc(strlen(s) * sizeof(char));
		strcpy(vector[i].prenume, s);

		fscanf(input, "%s", vector[i].id);

		for (int j = 0; j < 5; j++)
			fscanf(input, "%lf", &vector[i].note[j]);
	}
}

void afisare_fisier(student *vector, int dimensiune)
{
	for (int i = 0; i < dimensiune; i++)
	{
		printf("\nNume: %s \nPrenume: %s \nID: %s \nNote: ", vector[i].nume, vector[i].prenume, vector[i].id);
		for (int j = 0; j < 5; j++)
			printf("%lf; ", vector[i].note[j]);
		printf("\n");
	}
}


void swap(student *first_stud, student *second_stud)
{
	student aux;
	aux = *first_stud;
	*first_stud = *second_stud;
	*second_stud = aux;
}


void sortare_vector(student *vector, int dimensiune)
{
	for (int i = 0; i < dimensiune; i++)
		for (int j = i + 1; j < dimensiune; j++)
			if (medie(vector[i]) > medie(vector[j]))
				swap(&vector[i], &vector[j]);
}