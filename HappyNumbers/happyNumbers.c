#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int sumDigits(int num);
void addToVector(int **vector, int *size, int res);
void printVector(int *valueVector, int size);
bool isValueInVector(int *vector, int size, int res);
void printVector(int *valueVector, int size);
bool checkHappiness(int num);

int main()
{
  int a, b;
  /*a = 1;
  b = 44;*/
  scanf("%d %d", &a, &b);

  int counter = 0;

  for (int i = a; i <= b; i++) 
  {
    if (checkHappiness(i)) counter++;
  }

  printf("%d\n", counter);

}

bool checkHappiness(int num) 
{  
    int *valueVector = NULL;  // vetor vazio
    int size = 0;             // tamanho atual do vetor
    int res = 0;  

    // operacao
    while(res != 1)
    {
      res = sumDigits(num); 

      if(isValueInVector(valueVector, size, res))
      {
        return false;
      }
      else
      {
        if(res == 0)
        { 
          return false; 
        }
        else
        {
          addToVector(&valueVector, &size, res);
          num = res;
        }
      }
      
    }

    return true;
}


int sumDigits(int num) 
{
  int sum = 0;
  int aux = 0;

  while (num != 0) // enquanto num for diferente de 0
  {
    //printf("num: %d\n", num);

    aux = num % 10;
    //printf("aux: %d\n", aux);

    sum += aux * aux ; // adiciona o ultimo digito ao quadrado na soma
    //printf("sum: %d\n", sum);

    num /= 10;       // remove o ultimo digito / divide por 10
    aux = 0;
  }

  return sum;
}

void addToVector(int **vector, int *size, int res) 
{    
  int *temp = (int *)realloc(*vector, (*size + 1) * sizeof(int));
  if (temp == NULL) 
  {
    //printf("falha: alocar memória.\n");
    free(*vector);  // libera qualquer memoria alocada previamente
    //exit(1);      // encerra o programa
  }

  *vector = temp;            // atualiza o ponteiro do vetor
  (*vector)[*size] = res;    // insere o novo valor
  (*size)++;                 // incrementa o tamanho do vetor
}

void printVector(int *valueVector, int size)
{
  for (int i = 0; i < size; i++) 
  {
    printf("valueVector[%d] = %d\n", i, valueVector[i]);
  }
}

bool isValueInVector(int *vector, int size, int res) 
{
  for (int i = 0; i < size; i++) 
  {
    if (vector[i] == res) 
    {
      return true; // Encontrou o valor no vetor
    }
  }
  
  return false; // Não encontrou o valor no vetor
}