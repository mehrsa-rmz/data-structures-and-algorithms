#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>


#include "bst.h"

#define READ_MODE "r+"
#define APPEND_MODE "a+"

/**
 * @brief 
 * @param filename 
 * @param mode 
 * @return FILE* 
 */
FILE *openFile(const char *filename, const char *mode);

/**
 * @brief 
 * 
 * @param argument 
 * @return true or false
 */
bool isNull(void *argument);


/**
 * @brief 
 * 
 * @param argument 
 * @return true or false
 */
bool isNotNull(void *argument);

