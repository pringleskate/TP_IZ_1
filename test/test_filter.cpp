//
// Created by ekaterina on 08.03.2020.
//


#include "gtest/gtest.h"
#
extern "C"
{
  #include "../inc/functions.h"
}

void initialize_vector(char **vector, char *str, int index);

TEST(testMainFunc, test1)
{
  int strings_number = 5;
  char *str_1 = "<meta property=\"og:image\" content=\"https://habr.com/share/publication/119090/f2d391ff659358c5e9f21975122e9797/?vector=1\" />";
  char *str_2 = "<meta property=\"og:image:width\" content=\"1200\"/>";
  char *str_3 = "<link rel=\"image_src\" href=\"https://habr.com/share/publication/119090/f2d391ff659358c5e9f21975122e9797/?vector=1\" />";
  char *str_4 = "<script src=\"https://dr.habracdn.net/habrcom/javascripts/1583480262/libs/jquery-1.8.3.min.js\"></script>";
  char *str_5 = "<script async src=\"https://cdn.onthe.io/io.js/Tn4LrERWU1qX\"></script>";

  int strings_sizes[5];
  strings_sizes[0] = strlen(str_1);
  strings_sizes[1] = strlen(str_2);
  strings_sizes[2] = strlen(str_3);
  strings_sizes[3] = strlen(str_4);
  strings_sizes[4] = strlen(str_5);

  char **vector = (char **)malloc(strings_number * sizeof(char *));
  for (int i = 0; i < strings_number; i++) {
    vector[i] = (char *)malloc((strings_sizes[i] + 1) * sizeof(char));
  }

  initialize_vector(vector, str_1, 0);
  initialize_vector(vector, str_2, 1);
  initialize_vector(vector, str_3, 2);
  initialize_vector(vector, str_4, 3);
  initialize_vector(vector, str_5, 4);

  int expected_return = 2;
  int test_return = FilterHTMLString(vector, strings_number);
  ASSERT_EQ(expected_return, test_return);
}


TEST(testMainFunc, test2)
{
  int strings_number = 5;
  char *str_1 = "<meta charset=\"utf-8\">";
  char *str_2 = "char *str_2 = \"\";";
  char *str_3 = "<!-- Bootstrap core CSS -->";
  char *str_4 = "<link href=\"static/css/bootstrap.min.css\" rel=\"stylesheet\">";
  char *str_5 = "<script src=\"\" ></script>";

  int strings_sizes[5];
  strings_sizes[0] = strlen(str_1);
  strings_sizes[1] = strlen(str_2);
  strings_sizes[2] = strlen(str_3);
  strings_sizes[3] = strlen(str_4);
  strings_sizes[4] = strlen(str_5);

  char **vector = (char **)malloc(strings_number * sizeof(char *));
  for (int i = 0; i < strings_number; i++) {
    vector[i] = (char *)malloc((strings_sizes[i] + 1) * sizeof(char));
  }

  initialize_vector(vector, str_1, 0);
  initialize_vector(vector, str_2, 1);
  initialize_vector(vector, str_3, 2);
  initialize_vector(vector, str_4, 3);
  initialize_vector(vector, str_5, 4);

  int expected_return = 0;
  int test_return = FilterHTMLString(vector, strings_number);
  ASSERT_EQ(expected_return, test_return);
}

TEST(testMainFunc, test3)
{
  int strings_number = 3;
  char *str_1 = "";
  char *str_2 = "";
  char *str_3 = "";

  int strings_sizes[5];
  strings_sizes[0] = strlen(str_1);
  strings_sizes[1] = strlen(str_2);
  strings_sizes[2] = strlen(str_3);


  char **vector = (char **)malloc(strings_number * sizeof(char *));
  for (int i = 0; i < strings_number; i++) {
    vector[i] = (char *)malloc((strings_sizes[i] + 1) * sizeof(char));
  }

  initialize_vector(vector, str_1, 0);
  initialize_vector(vector, str_2, 1);
  initialize_vector(vector, str_3, 2);

  int expected_return = 0;
  int test_return = FilterHTMLString(vector, strings_number);
  ASSERT_EQ(expected_return, test_return);
}

void initialize_vector(char **vector, char *str, int index) {
  for (int j = 0; j < strlen(str); j++)
    vector[index][j] = str[j];
}
