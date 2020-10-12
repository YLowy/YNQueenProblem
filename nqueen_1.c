#include <stdio.h>
#include <stdlib.h>
typedef enum { false, true } bool;
int Counts =0;
void printTable(char **Table,int n);

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

void nqueen(int line, int n,char**Table)
{
    int list;
	for (list=0; list<n; list++) {
        if (checkqueen(list, line,Table,n)) { 
            Table[line][list]='Q';
            if(line == n-1){
            	
            	Counts++;
            	printf("(%d)\n",Counts);
    			printTable(Table,n);
				Table[line][list]=0x00;
            	return;
			}
            nqueen(line+1,n,Table);
			Table[line][list]=0x00;
        }
    }
}
void printTable(char **Table,int n)
{
	printf("\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(!Table[i][j])
				printf("+ ");
			else
				printf("%c ",(Table[i][j]));
		}
		printf("\n");
	}
	printf("\n");
}
int main(){
	
	int n = 8;
	printf(" ----- %d-queen -----\n",n);
	char **Table = malloc(sizeof(char*)*n);
	for(int i=0;i<n;i++)
    	Table[i] = calloc(n,sizeof(char));
    
	nqueen(0,n,Table);

	printf("Count = %d\n",Counts);
	return 0;
} 


