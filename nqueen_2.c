#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum { false, true } bool;
void printTable(char **Table,int n);


void printTable(char **Table,int n)
{
	printf("\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(!Table[i][j])
				printf(". ");
			else
				printf("%c ",(Table[i][j]));
		}
		printf("\n");
	}
	printf("\n");
}
int Counts =0;
bool checkqueen(int x, int y, char **table,int n)
{
    for (int i = 0; i < y; i++)
        if (table[i][x]=='Q' )
            return false;

	for(int i=x-1,j=y-1; i>=0&&j>=0 ; i--,j--)
		if (table[j][i]=='Q' )
            return false;

    for (int i = x+1, j = y-1; j >= 0 && i < n; i++, j--)
        if (table[j][i]=='Q' )
            return false;
    return true;
}

void nqueen(int line, int n,char**Table,char ***output)
{

    if(line>=n){
        for (int i = 0; i < n; i++)
            memcpy(output[Counts][i], Table[i], n+1 );
        Counts++;
        return;

    }
    for (int list=0; list<n; list++) {
        Table[line][list]='Q';
        if (checkqueen(list, line,Table,n))
            nqueen(line+1,n,Table,output);

        Table[line][list]='.';


    }

}


void freeTable(char **Table,int n)
{
    for(int i=0;i<n;i++)
        free(Table[i]);
    free(Table);
}
char ***solveNQueens(int n, int *returnSize, int** returnColumnSizes){

    int Arraysize[16]={0,1,0,0,2,10,4,40,92,352,724,2680,14200,73712,365596,2279184};
    Counts=0;
    printf("----solveNQueens--- %d \n",n);
    *returnSize = Arraysize[n];

    printf("*returnSize = %d\n",*returnSize);
    *returnColumnSizes = malloc(Arraysize[n] * sizeof(int));
    for (int i = 0; i < Arraysize[n]; i++)
        (*returnColumnSizes)[i] = n;

    char ***output = malloc(sizeof(char**)*Arraysize[n]);

    for(int i =0;i<Arraysize[n];i++){
        output[i] = malloc(sizeof(char*)*n);
        for(int j =0;j<n;j++)
            output[i][j] = malloc(sizeof(char)*(n+1));
    }
    char **Table = malloc(sizeof(char*)*n);

    for (int i = 0; i < n; i++) {
        Table[i] = malloc((n+1 ) * sizeof(char));
        for (int j = 0; j < n; j++)
            Table[i][j] = '.';
        Table[i][n] = '\0';
    }

    nqueen(0,n,Table,output);

    freeTable(Table,n);



	return output;
}
int main(){
	int n = 8;
	int anssize =0;
	int * returnsize = &anssize ;
	int *returnColumnSizes;

	char ***p = solveNQueens(n,returnsize,&returnColumnSizes);

    printf(" ----- %d-queen -----\n",n);
    printf("Count = %d\n",anssize);
    for(int i =0;i<anssize;i++)
		printTable(p[i],n);

    printf("Count = %d\n",anssize);
	printf(" ----- ------------- -----\n");
	return 0;
}


