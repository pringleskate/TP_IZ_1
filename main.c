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

int FilterHTMLString(char **string, int N);

int main() {
  int N = 2;
  char *string = "<img src=\"file.format\" alt=\"text\" />";

  unsigned long M = strlen(string);
  char **v = (char **)malloc(N * sizeof(char *)); //количество строк
  for (int i = 0; i < N; i++) { //столбцов
	v[i] = (char *)malloc((M + 1) * sizeof(char));
  }

  for (int i = 0; i < N; i++) {
	 for (int j = 0; j < M; j++) {
	   v[i][j] = string[j];
	 }
  }

  printf("quantity of strings with src attrs = %d",  FilterHTMLString(v, N));

  for (int i = 0; i < N; i++) {
	free(v[i]);
  }
  free(v);
  return 0;
}

int FilterHTMLString(char **string, int N) {

  int src_len = 3;
  int quantity_src_attributes = 0;

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


