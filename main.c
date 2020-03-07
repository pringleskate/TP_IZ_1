#include "functions.h"
/*Условие ИЗ№1:
 * Составить программу построчной фильтрации текста, вводимого пользователем.
 * Суть фильтра — отбор строк, содержащих HTML-тег с заданным значением атрибута src.
 * Фильтр должен быть реализован как функция, принимающая на вход указатель на вектор строк,
 * их количество и указатель на результирующую структуру.
 * На выход функция должна возвращать количество строк в результирующей структуре.
 * Результат обработки выводится на экран.
 */

//СДЕЛАТЬ ПРОВЕРКИ НА ОШИБКИ СТАНДАРТНЫЕ ФУНКЦИИ
//спросить, надо ли делать копирование в результирующую структуру


int main() {
  int vector_size = VectorSizeInput();
  if (vector_size < 1)
	return 0;

  char **input_vector = VectorInput(vector_size);
  if (input_vector == NULL) {
	printf("Memory for vector of strings cannot be allocated");
	return 0;
  }

  int quant_strings_with_src_atr = FilterHTMLString(input_vector, vector_size);
  if (quant_strings_with_src_atr < 1)
	printf("There's no strings with SRC attributes \n");
  else
	printf("Quantity of strings with SRC attributes = %d", quant_strings_with_src_atr);

  ClearAllocatedMemory(input_vector, vector_size);
  return 0;
}
