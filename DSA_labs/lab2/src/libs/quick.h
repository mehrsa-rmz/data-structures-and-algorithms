#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// QuickSort
void swap(int *x, int *y);
int partition(int *arr, int low, int high);
void quicksort(int *arr, int low, int high);
