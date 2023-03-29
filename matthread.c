#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
int n,m,k;
int **matrix1,**matrix2,**ans;
void *runner(void * arg){
    int tid = *(int*)arg;

    int sum=0;
    for(int z = 0; z<k;z++){
        sum=0;
        for (int i =0;i<n;i++){
            sum+=matrix1[tid][i]*matrix2[i][z];
        }
        ans[tid][z] = sum;
        sum=0;
    }
}
int main(int argc, char** argv)
{   
    clock_t start_time = clock();
    m =  atoi(argv[1]);
    n = atoi(argv[2]);
    k = atoi(argv[3]);
    int * values = (int*) malloc( m * n * sizeof(int) );

    matrix1 = (int**) malloc( m * sizeof(int*) );

 
  for (int i = 0; i < m; ++i) {
    matrix1[ i ] = &values[ i * n ];
  }
  int * values1 = (int*) malloc( n * k * sizeof(int) );

    matrix2 = (int**) malloc( n * sizeof(int*) );

 
  for (int i = 0; i < n; ++i) {
    matrix2[ i ] = &values1[ i * k ];
  }
  int * values2 = (int*) malloc( n * k * sizeof(int) );

    ans = (int**) malloc( n * sizeof(int*) );

 
  for (int i = 0; i < n; ++i) {
    ans[ i ] = &values2[ i * k ];
  }

    if (argc!=4){
        printf("error");
        return 1;
    }
    for (int i =0;i<m;i++){
        for (int j =0;j<k;j++){
            ans[i][j]=0;
        }
    }


    for (int i =0;i<m;i++){
        for (int j =0;j<n;j++){
              matrix1[i][j]= rand()%10000+1000;
         
        }
    }
    for (int i =0;i<n;i++){
        for (int j =0;j<k;j++){
               printf("%d ",matrix1[i][j]);
        }
        printf("\n");
    }
    for (int i =0;i<n;i++){
        for (int j =0;j<k;j++){
                 matrix2[i][j]= rand()%10000+1000;
        }
    }
    for (int i =0;i<n;i++){
        for (int j =0;j<k;j++){
               printf("%d ",matrix2[i][j]);
        }
        printf("\n");
    }
    pthread_t threads[m];
    for (int i = 0;i<m;i++){
        int *tid;
        tid = (int *) malloc( sizeof(int) );
        *tid = i;
        pthread_create(&threads[i],NULL, runner,(void *)tid);
    }
    for (int i = 0;i<m;i++){
        pthread_join(threads[i],NULL);
    }

    for (int i =0;i<n;i++){
        for (int j =0;j<k;j++){
               printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
    clock_t end_time = clock();
    double elapsed_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Elapsed time: %f seconds\n", elapsed_time);
        return 0;
}