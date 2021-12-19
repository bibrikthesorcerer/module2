#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void task_1(char* str)
{
   //==countin the number of words in str==//
   int count = 1;
   for (int i = 0; str[i] != '\0'; i++)
   {

      if (str[i] == ' ')
         count++;
   }
   int count_w = count;
   //==copying the first word==//
   char first_w[100] = { " " };

   for (int i = 0; str[i] != ' '; i++)
      first_w[i] = str[i];


   ///==copying the last word==///
   char last_w[100] = { " " };

   int count_l = 1;
   int j = 0;
   for (int i = 0; str[i] != '\0'; i++)
   {
      if (str[i] == ' ')
         count_l++;

      if ((count_l == count_w)&&(str[i]!= ' '))
      {
         last_w[j] = str[i];
         j++;
      }
   }


   //==making switched array==//?????
   count = 1;
   char str_new[100] = {" "};
   int k_l = 0;
   for (int j =0;((count == 1)&&(last_w[j] !='\0')); j++)
   { 
      str_new[k_l] = last_w[j];
      k_l++;
   }
   str_new[k_l] = ' ';
   k_l++;
   for (int i = 0; str[i] != '\0'; i++)
   {

      if ((count != 1) && (count != count_w))
      {
         str_new[k_l] = str[i];
         k_l++;
      }
      if (str[i] == ' ')
      { 
         count++;
      }   
   }

   //
   k_l = strlen(str_new);

   for (int j = 0; ((count == count_w) && (first_w[j] != '\0')); j++)
   {
      str_new[k_l] = first_w[j];
      k_l++;
   }

   str[0] = "\0";

   for (int i = 0; i < strlen(str_new); i++)
   {
      str[i] = str_new[i];
   }

}

struct EMPLOYEE
{
   char name[100];
   char surname[100];
   char patronymic[100];
   char sex[10];
   char position[100];
   int year_birth;
};

void task_2() 
{
   int n = 0;
   printf("Enter number of employees:\n");
   scanf_s("%d", &n);

   struct EMPLOYEE* array = (struct EMPLOYEE*)malloc(n * sizeof(struct EMPLOYEE));

   for (int i = 0; i < n; i++)
   {
      printf("Enter the name of the employee number %d:\n", i + 1);
      fscanf_s(stdin, "%s", array[i].name, 100);

      printf("Enter the surname of the employee number %d:\n", i + 1);
      fscanf_s(stdin, "%s", array[i].surname, 100);

      printf("Enter the patronymic of the employee number %d:\n", i + 1);
      fscanf_s(stdin, "%s", array[i].patronymic, 100);

      printf("Enter sex of the employee number %d:\n", i + 1);
      fscanf_s(stdin, "%s", array[i].sex, 10);

      printf("Enter position of the employee number %d:\n", i + 1);
      fscanf_s(stdin, "%s", array[i].position, 100);

      printf("Enter the year of birth of the employee number %d:\n", i + 1);
      scanf_s("%d", &array[i].year_birth);
   }

   printf("List of employyes who are engineers and senior citizens:\n");

   for (int i = 0; i < n; i++)
   {
      if (strcmp(array[i].position,"engineer")==0)
      {
         if ((strcmp(array[i].sex,"female")==0)&&(2021 - array[i].year_birth >= 60))
         {
            printf("%s ", array[i].name);
            printf("%s ", array[i].surname);
            printf("%s ", array[i].patronymic);
            printf("%s ", array[i].sex);
            printf("%s ", array[i].position);
            printf("%d ", array[i].year_birth);
            printf("\n");

         }
         if ((strcmp(array[i].sex,"male")==0)&&(2021 - array[i].year_birth >= 65))
         {
            printf("%s ", array[i].name);
            printf("%s ", array[i].surname);
            printf("%s ", array[i].patronymic);
            printf("%s ", array[i].sex);
            printf("%s ", array[i].position);
            printf("%d ", array[i].year_birth);
            printf("\n");

         }

      }
   }


}


int main()
{
   char str[100] = {"today i have ate at the white table"};
   //==task1==//
   //task_1(str);
   //printf("%s\n", str);
   //========//

   //==task2==//
   task_2();
   //=========//
   return 0;
}



//struct STUDENT
//{
//   char name[100];
//   char surname[100];
//   int group;
//   int marks[4];
//};
//
//
//
//int second()
//{
//   int n = 0;
//   printf("Enter number of students:\n");
//   scanf_s("%d", &n);
//
//   struct STUDENT* array = (struct STUDENT*)malloc(n * sizeof(struct STUDENT));
//
//   for (int i = 0; i < n; i++)
//   {
//      printf("Enter the surname of the student number %d:\n", i + 1);
//      fscanf_s(stdin, "%s", array[i].surname, 100);
//
//      printf("Enter the initials of the student number %d:\n", i + 1);
//      fscanf_s(stdin, "%s", array[i].name, 100);
//
//
//      printf("Enter number of group for the student number %d:\n", i + 1);
//      scanf_s("%d", &array[i].group);
//
//      printf("Enter marks of the student number %d:\n", i + 1);
//      for (int j = 0; j < 4; j++)
//      {
//         scanf_s("%d", &array[i].marks[j]);
//      }
//
//   }
//
//
//   float* compare_marks = (float*)malloc(n * sizeof(float));
//
//
//
//   for (int i = 0; i < n; i++)
//   {
//      float average = 0;
//      for (int j = 0; j < 4; j++)
//         average += array[i].marks[j];
//      average /= 4;
//
//      compare_marks[i] = average;
//
//      printf("Average mark of student %s %s from group %d is %f\n", array[i].surname, array[i].name, array[i].group, average);
//   }
//
//
//
//
//   printf("List of students with marks 4-5 only:\n");
//   for (int i = 0; i < n; i++)
//   {
//      int flag = 1;
//
//      for (int j = 0; j < 4; j++)
//      {
//         if (array[i].marks[j] != 4 && array[i].marks[j] != 5)
//            flag = 0;
//      }
//
//      if (flag)
//         printf("%s %s, group %d\n", array[i].surname, array[i].name, array[i].group);
//   }
//
//
//   float max = 7;
//   float min = -3;
//   int beststud = 0;
//   int worststud = 0;
//
//   for (int i = 0; i < n; i++)
//   {
//      if (max < compare_marks[i])
//      {
//         max = compare_marks[i];
//         beststud = i;
//      }
//      if (min > compare_marks[i])
//      {
//         min = compare_marks[i];
//         worststud = i;
//      }
//   }
//
//   printf("Best student is %s %s, from group %d. Worst student is %s %s, from group %d.", array[beststud].surname, array[beststud].name, array[beststud].group, array[worststud].surname, array[worststud].name, array[worststud].group);
//}