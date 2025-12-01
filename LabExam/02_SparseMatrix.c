
#include <stdio.h>
int main(){
    int matrix1[10][10],matrix2[10][10],sparsematrix2[100][3],sparsematrix1[100][3],summatrix[100][3];
    int rows, cols, noofnonzeroelements1 = 0, noofnonzeroelements2 = 0;
    printf("Enter the no of rows and columns of fthe matrices:\n");
    scanf("%d%d",&rows,&cols);
    printf("Enter elements\n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            scanf("%d",&matrix1[i][j]);
            if(matrix1[i][j]!=0){
                noofnonzeroelements1+=1;
            }
        }
    }
    printf("Enter elements\n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            scanf("%d",&matrix2[i][j]);
            if(matrix2[i][j]!=0){
                noofnonzeroelements2+=1;
            }
        }
    }
    printf("sparse representation of first matrix:\n");
    sparsematrix1[0][0] = rows;
    sparsematrix1[0][1] = cols;
    sparsematrix1[0][2] = noofnonzeroelements1;
    int k = 1;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if (matrix1[i][j]!=0){
                sparsematrix1[k][0] = i;
                sparsematrix1[k][1] = j;
                sparsematrix1[k][2] = matrix1[i][j];
                k++;
            }
        }
    }
    printf("sparse representation of second matrix:\n");
    int l=1;
    sparsematrix2[0][0] = rows;
    sparsematrix2[0][1] = cols;
    sparsematrix2[0][2] = noofnonzeroelements2;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if (matrix2[i][j]!=0){
                sparsematrix2[l][0] = i;
                sparsematrix2[l][1] = j;
                sparsematrix2[l][2] = matrix2[i][j];
                l++;
            }
        }
    }
    printf("rows\tcols\tnon-zero elements\n");
    for(int i=0;i<noofnonzeroelements1+1;i++){
        for(int j=0;j<3;j++){
            printf("%d\t",sparsematrix1[i][j]);
        }
        printf("\n");
    }
    printf("rows\tcols\tnon-zero elements\n");
    for(int i=0;i<noofnonzeroelements2+1;i++){
        for(int j=0;j<3;j++){
            printf("%d\t",sparsematrix2[i][j]);
        }
        printf("\n");
    }
    printf("\nSum matrix:\n");
    int i=1,j=1,m=1;
    summatrix[0][0]=rows;
    summatrix[0][1]=cols;
    while(i <=noofnonzeroelements1 && j<=noofnonzeroelements2){
        if (sparsematrix1[i][0]<sparsematrix2[j][0]||(sparsematrix1[i][0]==sparsematrix2[j][0]&& sparsematrix1[i][1]<sparsematrix2[j][1])){
            summatrix[m][0]=sparsematrix1[i][0];
            summatrix[m][1]=sparsematrix1[i][1];
            summatrix[m][2]=sparsematrix1[i][2];
            i++,m++;
        }
        else if(sparsematrix1[i][0]>sparsematrix2[j][0]||(sparsematrix1[i][0]==sparsematrix2[j][0]&&sparsematrix1[i][1]>sparsematrix2[j][1])){
            summatrix[m][0]=sparsematrix2[j][0];
            summatrix[m][1]=sparsematrix2[j][1];
            summatrix[m][2]=sparsematrix2[j][2];
            j++,m++;
        }
        else{
            summatrix[m][0]=sparsematrix1[i][0];
            summatrix[m][1]=sparsematrix1[i][1];
            summatrix[m][2]=sparsematrix1[i][2]+sparsematrix2[j][2];
            i++,m++,j++;
        }
    }
    while (i<=noofnonzeroelements1){
        summatrix[m][0]=sparsematrix1[i][0];
        summatrix[m][1]=sparsematrix1[i][1];
        summatrix[m][2]=sparsematrix1[i][2];
        i++,m++;
    }
    while (j<=noofnonzeroelements2){
        summatrix[m][0]=sparsematrix2[j][0];
        summatrix[m][1]=sparsematrix2[j][1];
        summatrix[m][2]=sparsematrix2[j][2];
        j++,m++;
    }
    summatrix[0][2]=m-1;
    printf("rows\tcols\tnon-zero elements\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<3;j++){
            printf("%d\t",summatrix[i][j]);
        }
        printf("\n");
    }
    printf("\nTranspose matrix:\n");
    int transpose[100][3];
    transpose[0][0]=summatrix[0][1];
    transpose[0][1]=summatrix[0][0];
    transpose[0][2]=summatrix[0][2];
    int n=1;
    for(int i=0;i<3;i++){
        for (int j=0;j<m;j++){
            if (summatrix[j][1]==i){
                transpose[n][0] = summatrix[j][1]; 
                transpose[n][1] = summatrix[j][0];  
                transpose[n][2] = summatrix[j][2];
                n++;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            printf("%d\t ",transpose[i][j]);
        }
        printf("\n");
    }
    return 0;
}
