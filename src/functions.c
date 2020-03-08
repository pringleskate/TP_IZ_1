//
// Created by ekaterina on 07.03.2020.
//

#include "../inc/functions.h"

char **VectorInput(int vector_size) {
  char **v = (char **) malloc(vector_size * sizeof(char *));
  if (v) {
    for (int i = 0; i < vector_size; i++) {
      char *input_string = (char *) malloc(1024 * sizeof(char));
      if (input_string) {
        input_string = "<script async src=\"https://cdn.onthe.io/io.js/Tn4LrERWU1qX\"></script>";
        //fgets(input_string, 1024, stdin);
        unsigned long read_bytes = strlen(input_string);
        v[i] = realloc(input_string, read_bytes + 1);
      }
    }
  }
  return v;
}

void ClearAllocatedMemory(char **vector, int vector_size) {
  for (int i = 0; i < vector_size; i++) {
   // printf("string[%d] = %s\n", i, vector[i]);
    free(vector[i]);
  }
  free(vector);
}

int VectorSizeInput() {
  int strings_number = 0;
  printf("Enter a number of strings you want to filter: ");
  //scanf("%d\n", &strings_number);
  strings_number = 5;
  return strings_number;
}

int FilterHTMLString(char **input_vector, int vector_size) {
  int src_string_length = 3;
  int quant_strings_with_src_atr = 0;

  /*for (int i = 0; i < N; i++) {
	printf("string[%d] = %s\n", i, string[i]);
	if (!string[i])
	  return -1;
  }
*/
  for (int i = 0; i < vector_size; i++) {
    int j = 0;
    while (input_vector[i][j] != '\0') {
      if ((int) (input_vector[i][j] == 's') && ((int) input_vector[i][j + 1] == 'r') && ((int) input_vector[i][j + 2] == 'c')) {
       // printf("string[%d %d] = %c\n", i, j, input_vector[i][j]);
       // printf("src\n");
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
