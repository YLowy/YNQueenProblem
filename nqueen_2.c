#include <stdio.h>
#include <stdlib.h>
int Arraysize[16]={0,1,0,0,2,10,4,40,92,352,724,2680,14200,73712,365596,2279184};
typedef enum { false, true } bool;
int Counts =0;
void printTable(char **Table,int n);
void clonetable(char **Table,char ***output, int n);
bool checkqueen(int x, int y, char **table,int n)
{
    for (int i = 0; i < y; i++)
        if (table[i][x] )
            return false;

	for(int i=x-1,j=y-1; i>=0&&j>=0 ; i--,j--)
		if (table[j][i] )
            return false;

    for (int i = x+1, j = y-1; j >= 0 && i < n; i++, j--)
        if (table[j][i] )
            return false;
    return true;
}

void nqueen(int line, int n,char**Table,char ***output)
{
    int list;
	for (list=0; list<n; list++) {
        if (checkqueen(list, line,Table,n)) {
            Table[line][list]='Q';
            if(line == n-1){



    			clonetable(Table,output,n);

            	Counts++;
            	//printf("(%d)\n",Counts);
    			//printTable(Table,n);


				Table[line][list]=0x00;
            	return;
			}
            nqueen(line+1,n,Table,output);
			Table[line][list]=0x00;
        }
    }
}
void clonetable(char **Table,char ***output, int n)
{
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!Table[i][j]){
                output[Counts][i][j] = '.';
            }
            else{

                output[Counts][i][j] = 'Q';
            }
        }
    }
}
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

void freeTable(char **Table,int n)
{
    for(int i=0;i<n;i++)
        free(Table[i]);
    free(Table);
}
char ***main(int n, int* returnSize, int** returnColumnSizes){
    n = 5;
    *returnSize = Arraysize[n];
    char ***output = malloc(sizeof(char**)*Arraysize[n]);

    for(int i =0;i<Arraysize[n];i++){
        output[i] = malloc(sizeof(char*)*n);
        for(int j =0;j<n;j++)
            output[i][j] = malloc(sizeof(char)*n);
    }

    printf(" ----- %d-queen -----\n",n);
    char **Table = malloc(sizeof(char*)*n);
    for(int i=0;i<n;i++)
        Table[i] = calloc(n,sizeof(char));

    nqueen(0,n,Table,output);

    printf("Count = %d\n",Counts);
    Counts=0;
    freeTable(Table,n);
    printf(" ----- ------------- -----\n");
    for(int i =0;i<Arraysize[n];i++)
        printTable(output[i],n);

	return 0;
}


