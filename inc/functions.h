//
// Created by ekaterina on 07.03.2020.
//

#ifndef TP_IZ_1__FUNCTIONS_H_
#define TP_IZ_1__FUNCTIONS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 1024

int FilterHTMLString(char **input_vector, int vector_size, char **output_vector, int *output_vector_size);
char **VectorInput(int vector_size);
int VectorSizeInput();
void ClearAllocatedMemory(char **vector, int vector_size);
void CopyString(char **output_vector, char *input_string, int *output_vector_size);

#endif //TP_IZ_1__FUNCTIONS_H_
