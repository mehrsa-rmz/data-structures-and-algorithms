#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>


#define TEST_FILE "../data/data.txt"
#define READ_MODE "r+"


FILE *openFile(const char *filename, const char *mode);
int *readArray(FILE *file, int *size);
void printArray(int *arr, int size);