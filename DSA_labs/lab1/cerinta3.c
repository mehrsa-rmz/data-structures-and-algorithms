#include "student.h"


void realocare_memorie(student **vector, int dimensiune)
{
	*vector = (student *)realloc(*vector, sizeof(student) * dimensiune);
}


void adaugare_student(student *vector, int poz, int dimensiune, student stud)
{
	for(int i=dimensiune; i>poz; i--)
	vector[i]=vector[i-1];
	vector[poz]=stud;
	/*TODO: Care este complexitatea metodei folosite? 
			Complexitatea este O(dimensiune-poz+1).*/
}
