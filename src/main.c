#include "../inc/functions.h"
/*Условие ИЗ№1:
 * Составить программу построчной фильтрации текста, вводимого пользователем.
 * Суть фильтра — отбор строк, содержащих HTML-тег с заданным значением атрибута src.
 * Фильтр должен быть реализован как функция, принимающая на вход указатель на вектор строк,
 * их количество и указатель на результирующую структуру.
 * На выход функция должна возвращать количество строк в результирующей структуре.
 * Результат обработки выводится на экран.
 */


int main() {
  int vector_size = VectorSizeInput();
  if (vector_size < 1)
	return -1;

  char **input_vector = VectorInput(vector_size);
  if (input_vector == NULL) {
	printf("Memory for input vector of strings cannot be allocated");
	return -1;
  }

  char **output_vector = (char **) malloc(BUFFER_SIZE * sizeof(char *));
  if (output_vector == NULL) {
    printf("Memory for output vector of strings cannot be allocated");
    return -1;
  }
  int output_vector_size = 0;


  int quant_strings_with_src_atr = FilterHTMLString(input_vector, vector_size, output_vector, 0);
  if (quant_strings_with_src_atr < 1)
	printf("There's no strings with SRC attributes \n");
  else
	printf("Quantity of strings with SRC attributes = %d", quant_strings_with_src_atr);

  ClearAllocatedMemory(input_vector, vector_size);
  ClearAllocatedMemory(output_vector, output_vector_size);

  return 0;
}
