#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
int n, m, k;
int numofthreads;
int **matrix1, **matrix2, **ans;
int region;
void *runner(void *arg)
{
  int tid = *(int *)arg;
  int start = tid * m / numofthreads;
  int end = (tid + 1) * (m) / numofthreads;
  for (int o = start; o < end; o++)
  { 
    for (int z = 0; z < k; z++)
    {
     
      for (int i = 0; i < n; i++)
      {
        ans[o][z]  += matrix1[o][i] * matrix2[i][z];
       
      }
      
   
    }
  }
}
int main(int argc, char **argv)
{
  m = atoi(argv[1]);
  n = atoi(argv[1]);
  k = atoi(argv[1]);
  numofthreads = atoi(argv[2]);
  int *values = (int *)malloc(m * n * sizeof(int));

  matrix1 = (int **)malloc(m * sizeof(int *));

  for (int i = 0; i < m; ++i)
  {
    matrix1[i] = &values[i * n];
  }
  int *values1 = (int *)malloc(n * k * sizeof(int));

  matrix2 = (int **)malloc(n * sizeof(int *));

  for (int i = 0; i < n; ++i)
  {
    matrix2[i] = &values1[i * k];
  }
  int *values2 = (int *)malloc(n * k * sizeof(int));

  ans = (int **)malloc(n * sizeof(int *));

  for (int i = 0; i < n; ++i)
  {
    ans[i] = &values2[i * k];
  }

  if (argc != 3)
  {
    printf("error");
    return 1;
  }
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < k; j++)
    {
      ans[i][j] = 0;
    }
  }

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      matrix1[i][j] = rand() % 100 + 1;
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < k; j++)
    {
      matrix2[i][j] = rand() % 100 + 1;
    }
  }

  pthread_t threads[numofthreads];
  clock_t start_time = clock();
  region = m / numofthreads;

  for (int i = 0; i < numofthreads; i++)
  {
    int *tid;
    tid = (int *)malloc(sizeof(int));
    *tid = i;

    pthread_create(&threads[i], NULL, runner, (void *)tid);
    
  }
    
  for (int i = 0; i < numofthreads; i++)
  {
    pthread_join(threads[i], NULL);
  }
  clock_t end_time = clock();
  double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
  printf("Elapsed time: %f seconds\n", elapsed_time);
  return 0;
}