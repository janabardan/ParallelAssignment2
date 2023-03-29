#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>


int n,m,k;
int main(int argc, char* argv[]){
     clock_t start_time = clock();
    m =  atoi(argv[1]);
    n = atoi(argv[2]);
    k = atoi(argv[3]);
    int matrix1 [m][n];
    int matrix2[n][k] ;
    int ans[m][k] ;
    for (int i =0;i<m;i++){
        for (int j =0;j<k;j++){
            ans[i][j]=0;
        }
    }

    for (int i =0;i<m;i++){
        for (int j =0;j<n;j++){
               matrix1[i][j]=rand()%100+1;
         
        }
        printf("ana hon");
    }
    for (int i =0;i<n;i++){
        for (int j =0;j<k;j++){
               matrix2[i][j]=rand()%100+1;
        }
    }
    printf("ok\n");
    for(int x = 0; x<m;x++){
        for(int z = 0; z<k;z++){
            int sum=0;
            for (int i =0;i<n;i++){
                ans[x][z]+=matrix1[x][i]*matrix2[i][z];
            }
        }
    }
    //  for (int i =0;i<m;i++){
    //     for (int j =0;j<k;j++){
    //           printf("%d ",ans[i][j]);
    //     }
    //     printf(" ");
    // }
    clock_t end_time = clock();
    double elapsed_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Elapsed time: %f seconds\n", elapsed_time);
    return 0;
}