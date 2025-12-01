#include <stdio.h>
int main(){
    int matrix1[10][10],matrix2[10][10];
    int s1[100][3], s2[100][3], sum[100][3], tr[100][3];

    int rows, cols, v1 = 0, v2 = 0;

    printf("Enter the no of rows and columns of the matrices:\n");
    scanf("%d %d",&rows,&cols);

    printf("Enter elements\n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            scanf("%d",&matrix1[i][j]);
            if(matrix1[i][j]!=0){
                v1+=1;
            }
        }
    }

    printf("Enter elements\n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            scanf("%d",&matrix2[i][j]);
            if(matrix2[i][j]!=0){
                v2+=1;
            }
        }
    }

    printf("sparse representation of first matrix:\n");
    s1[0][0] = rows;
    s1[0][1] = cols;
    s1[0][2] = v1;

    int k = 1;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if (matrix1[i][j]!=0){
                s1[k][0] = i;
                s1[k][1] = j;
                s1[k][2] = matrix1[i][j];
                k++;
            }
        }
    }

  
    int l=1;
    s2[0][0] = rows;
    s2[0][1] = cols;
    s2[0][2] = v2;

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if (matrix2[i][j]!=0){
                s2[l][0] = i;
                s2[l][1] = j;
                s2[l][2] = matrix2[i][j];
                l++;
            }
        }
    }

    printf("rows\tcols\tnon-zero elements\n");
    for(int i=0;i<v1+1;i++){
        for(int j=0;j<3;j++){
            printf("%d\t",s1[i][j]);
        }
        printf("\n");
    }
  printf("sparse representation of second matrix:\n");
    printf("rows\tcols\tnon-zero elements\n");
    for(int i=0;i<v2+1;i++){
        for(int j=0;j<3;j++){
            printf("%d\t",s2[i][j]);
        }
        printf("\n");
    }

    printf("\nSum matrix:\n");
    int i=1,j=1,m=1;
    sum[0][0]=rows;
    sum[0][1]=cols;

    while(i <= v1 && j <= v2){
        if (s1[i][0] < s2[j][0] || (s1[i][0]==s2[j][0] && s1[i][1] < s2[j][1])){
            sum[m][0] = s1[i][0];
            sum[m][1] = s1[i][1];
            sum[m][2] = s1[i][2];
            i++; m++;
        }
        else if (s1[i][0] > s2[j][0] || (s1[i][0]==s2[j][0] && s1[i][1] > s2[j][1])){
            sum[m][0] = s2[j][0];
            sum[m][1] = s2[j][1];
            sum[m][2] = s2[j][2];
            j++; m++;
        }
        else{
            sum[m][0] = s1[i][0];
            sum[m][1] = s1[i][1];
            sum[m][2] = s1[i][2] + s2[j][2];
            i++; j++; m++;
        }
    }

    while (i <= v1){
        sum[m][0] = s1[i][0];
        sum[m][1] = s1[i][1];
        sum[m][2] = s1[i][2];
        i++; m++;
    }

    while (j <= v2){
        sum[m][0] = s2[j][0];
        sum[m][1] = s2[j][1];
        sum[m][2] = s2[j][2];
        j++; m++;
    }

    sum[0][2] = m - 1;

    printf("rows\tcols\tnon-zero elements\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<3;j++){
            printf("%d\t",sum[i][j]);
        }
        printf("\n");
    }

    printf("\nTranspose matrix:\n");
    tr[0][0] = sum[0][1];
    tr[0][1] = sum[0][0];
    tr[0][2] = sum[0][2];

    int n = 1;
    for(int i=0;i<3;i++){
        for(int j=0;j<m;j++){
            if(sum[j][1] == i){
                tr[n][0] = sum[j][1];
                tr[n][1] = sum[j][0];
                tr[n][2] = sum[j][2];
                n++;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            printf("%d\t ",tr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
