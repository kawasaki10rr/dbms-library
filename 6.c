#include <stdio.h>
#define INF 999
#define MAX 100

int main(){
    int n, choice;
    int mat[MAX][MAX];
    printf("Enter number of vertices : ");
    scanf("%d",&n);

    printf("Choose any one: \n1. Floyd's algorithm \n2.Warshalls algorithm\n Enter choice : ");
    scanf("%d",&choice);


    if (choice == 1)
        printf("Enter adjacency matrix : (999 for INF)\n");
    else    
        printf("Enter transitive matrix (using 0 & 1)\n");
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d",&mat[i][j]);
        }
    }

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(choice == 1 ){
                    if(mat[i][k] + mat[k][j] < mat[i][j]) mat[i][j] = mat[i][k] + mat[k][j];
                }
                else {
                    mat[i][j] = mat[i][j] || (mat[i][k] && mat[k][j]);
                }
            }
        }
    }

    if(choice == 1){
        printf("all pair shortest path : \n");
    }
    else{
        printf("Transitive closure matric : \n");
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if (choice == 1 && mat[i][j] == INF)
                printf("INF ");
            else    
                printf("%3d",mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}

/*0 3 999 7
8 0 2 999
5 999 0 1
2 999 999 0

1 1 0 0
0 1 1 0
0 0 1 1
0 0 0 1
*/