#include "student.h"


student *eliminare_restantieri(student *vector, int *dimensiune)
{
	for (int i = 0; i < *dimensiune; i++)
	{
		int x = 0;
		while (x < 5 && vector[i].note[x] >= 5)
			x++;
		if (x < 5)
		{
			for (int j = i; j < *dimensiune - 1; j++)
				vector[j] = vector[j + 1];
			(*dimensiune)-=1;
			i--;
		}
	}
	vector=(student*)realloc(vector, sizeof(student)*(*dimensiune));
	return vector;
	/*TODO: Care este complexitatea pentru secventa de stergere a elementelor din vector cu realocare de memorie?
			Complexitatea este O(dimensiune^2) fiind vorba de un for in interiorul unui alt for.*/
}