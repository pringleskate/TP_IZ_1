#include <stdio.h>
#include <stdlib.h>

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
  int M = 5;

  char *string = "<img src=\"file.format\" alt=\"text\" />";
  char *string1 = "<img src=\"\" alt=\"text\" />";

  char **v = (char **)malloc(N * sizeof(char *));
  for (int i = 0; i < N; i++) {
	v[i] = (char *)malloc(M * sizeof(char));
  }

  for (int i = 0; i < N; i++) {
	for (int j = 0; j < M; j++) {
	  v[j] = string;
	  printf("%s %d %d\n", v[j], i, j);
	}
  }

  printf("quantity of strings with src attrs = %d",  FilterHTMLString(*v, N));
  return 0;
}


int FilterHTMLString(char **string, int N) {

  int src_len = 3;
  int quantity_src_attributes = 0;

  printf("string = %s \n", string);
  for (int j = 0; j < N; j++){
	int i = 0;
	while (string[i] != '\0') {
	  printf("%c i = %d\n", string[i], i);
	  if ((string[i] == 's') && (string[i + 1] == 'r') && (string[i + 2] == 'c')) {
		printf("src\n");
		i += src_len;

		if ((string[i] == '=') && (string[i + 1] == '"') && (string[i + 2] != '"')) {
		  quantity_src_attributes++;
		  break;
		}
	  }
	  i++;
	}
  }
  return quantity_src_attributes;
}