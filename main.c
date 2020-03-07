#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Условие ИЗ№1:
 * Составить программу построчной фильтрации текста, вводимого пользователем.
 * Суть фильтра — отбор строк, содержащих HTML-тег с заданным значением атрибута src.
 * Фильтр должен быть реализован как функция, принимающая на вход указатель на вектор строк,
 * их количество и указатель на результирующую структуру.
 * На выход функция должна возвращать количество строк в результирующей структуре.
 * Результат обработки выводится на экран.
 */



//СДЕЛАТЬ ПРОВЕРКИ НА ОШИБКИ СТАНДАРТНЫЕ ФУНКЦИИ
//и копирование в результирующую структуру

int FilterHTMLString(char **string, int N);
char **LinesInput(int strings_number);
int StringsNumberInput();

int main() {
  char *test_string = "<img src=\"file.format\" alt=\"text\" />"; //test_string

  int strings_number = StringsNumberInput();
  char **input = LinesInput(strings_number);
  printf("quantity of strings with src attrs = %d",  FilterHTMLString(input, strings_number));
 // int clear = clear_vector_memory();

  for (int i = 0; i < strings_number; i++) {
	//printf("string[%d] = %s\n", i, input[i]);
	free(input[i]);
  }
  free(input);


  return 0;
}

int StringsNumberInput() {
  int strings_number = 0;
  printf("Enter a number of strings you want to filter: ");
  scanf("%d\n", &strings_number);
  //printf("strings number = %d \n", strings_number);
  return strings_number;
}

char **LinesInput(int strings_number) {
  char **v = (char **)malloc(strings_number * sizeof(char *)); //количество строк;

  for (int i = 0; i < strings_number; i++){
	char *input_string = (char*)malloc(1024 * sizeof(char));
	fgets(input_string, 1024, stdin);
	unsigned long read_bytes = strlen(input_string);
	printf("read bytes = %lo\n", read_bytes);
	printf("input = %s\n", input_string);
	char *realloced_string = realloc(input_string, read_bytes);

	v[i] = (char *)malloc((read_bytes + 1) * sizeof(char));
//	v[i] = (char *)malloc((read_bytes) * sizeof(char));
	for (int j = 0; j < read_bytes; j++) {
	  v[i][j] = realloced_string[j];
	}

	free(realloced_string);
  }
  return v;
}


int FilterHTMLString(char **string, int N) {

  int src_len = 3;
  int quantity_src_attributes = 0;
  /*for (int i = 0; i < N; i++){
	printf("string[%d] = %s\n", i, string[i]);
	if (!string[i])
	  return -1;
  }
*/
  for (int i = 0; i < N; i++){
	int j = 0;
	while (string[i][j] != '\0'){
	  if ((int)(string[i][j] == 's') && ((int)string[i][j + 1] == 'r') && ((int)string[i][j + 2] == 'c')) {
		printf("string[%d %d] = %c\n", i, j, string[i][j]);
		printf("src\n");
		j += src_len;

		if (((int)string[i][j] == '=') && ((int)string[i][j + 1] == '"') && ((int)string[i][j + 2] != '"')) {
		  quantity_src_attributes++;
		  break;
		}
	  }
	  j++;
	}
  }
  return quantity_src_attributes;
}
