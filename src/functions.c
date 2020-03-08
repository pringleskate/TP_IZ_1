//
// Created by ekaterina on 07.03.2020.
//

#include "../inc/functions.h"

char **VectorInput(int vector_size) {
  char **v = (char **) malloc(vector_size * sizeof(char *));
  if (v == NULL)
    return NULL;

  for (int i = 0; i < vector_size; i++) {
    char *input_string = (char *) malloc(1024 * sizeof(char));
    if (input_string == NULL) {
      ClearAllocatedMemory(v, vector_size);
      return NULL;
    }

     fgets(input_string, 1023, stdin);
     unsigned long read_bytes = strlen(input_string);
     printf("read_bytes = %lu\n", read_bytes);
     v[i] = realloc(input_string, read_bytes + 1);
     if (v[i] == NULL){
      // free(input_string);
       return NULL;
     }
     else
       printf("input [%d] = %s\n", i, v[i]);
   }

    return v;
  }


void ClearAllocatedMemory(char **vector, int vector_size) {
  for (int i = 0; i < vector_size; i++)
    free(vector[i]);
  free(vector);
}

int VectorSizeInput() {
  int strings_number = 0;
  printf("Enter a number of strings you want to filter: ");
  char get_strings_number[3], *end;

  fgets(get_strings_number, 3, stdin);
  strings_number = strtol(get_strings_number, &end, 10);
  memset(get_strings_number, 0, 3);
  printf("%d\n", strings_number);
  return strings_number;
}

int FilterHTMLString(char **input_vector, int vector_size) {
  int src_string_length = 3;
  int quant_strings_with_src_atr = 0;

  for (int i = 0; i < vector_size; i++) {
    int j = 0;
    while (input_vector[i][j] != '\0') {
      if ((int) (input_vector[i][j] == 's') && ((int) input_vector[i][j + 1] == 'r') && ((int) input_vector[i][j + 2] == 'c')) {
        j += src_string_length;

        if (((int) input_vector[i][j] == '=') && ((int) input_vector[i][j + 1] == '"') && ((int) input_vector[i][j + 2] != '"')) {
          quant_strings_with_src_atr++;
          break;
        }
      }
      j++;
    }
  }
  return quant_strings_with_src_atr;
}