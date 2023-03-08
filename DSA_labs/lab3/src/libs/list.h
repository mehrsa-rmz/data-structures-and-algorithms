#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node
{
	int data;
	struct node *next;
} node;

typedef struct child
{
	char *name;
	int number;
	struct child *next;

} childNode;

/**
 * @brief Functie ce creaza un nod prin alocare dinamica 
 * si returneaza pointerul nodului creat. 
 * 
 * @param data - informatia nodului respectiv
 * @param next - adresa urmatorului nod
 * @return node* nou nod creat
 */
node *makeNode(int data, node *next);

/**
 * @brief Functie ce afiseaza toate elementele unei liste
 *  
 * @param head - capul listei de afisat
 */
void print(node *head);

/**
 * @brief Functie ce returneaza o lista nou creata cu ajutorul
 * datelor citite din fisier-ul file primit ca parametru
 * 
 * Hint:
 *      * folositi-va de metoda makeNode pentru a crea lista
 * 
 * @param file - fisierul ce trebuie citit
 * @return node* 
 */
node *makeList(FILE *file);

/**
 * @brief 
 * 
 * @param list 
 * @return node* the head of the list
 */
node *removeDuplicates(node *list);

/**
 * @brief 
 * 
 * @param number 
 * @param name 
 * @param next 
 * @return childNode* 
 */
childNode *makeChildNode(int number, const char *name, childNode *next);

/**
 * @brief 
 * 
 * @param file 
 * @return childNode* 
 */
childNode *makeCircularList(FILE *file);

/**
 * @brief 
 * 
 * @param head 
 * @param p 
 * @return childNode* 
 */
childNode *playJosephGame(childNode *head, int p);