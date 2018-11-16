#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int m,n,o,p,i,j,k,l;
int a_nonzero;
int b_nonzero;
int row,col,value;
 
int m_counter = 1;
int a[MAX][MAX],b[MAX][MAX],c[MAX][MAX];

void mread(int);
void mwrite(); 
void mmult();
void mtranspose(); 
/* 
(a) mread. Read in a sparse matrix.
(b) mwrite. Write out the contents of a sparse matrix.
(c) mmult. Create the sparse matrix d = a * b.
(d) mtranspose. Create the sparse matrix b = aT.
*/ 

int main()
{
	//無聊把視窗換個顏色 
	system("title 資料結構Assignment 4 By姜丹尼爾");
	system("color 9F");
	//無聊把視窗換個顏色
	
	mread(1);
	mread(2);
	mtranspose();
	mmult();
	//mwrite()	
    
}
  
  	
void mread(int counter)
{
if(counter==1)
  	{
  	printf("輸入Matrix A:\n"); 
   	scanf("%d%d%d",&m,&n,&a_nonzero);
   	 	a[m][n]={0};
   		for(i=0;i<a_nonzero;i++)
   		{
   		scanf(" %d%d%d",&row,&col,&value);
   		a[row][col] = value;
		}
  	}

if(counter==2)
  	{
	printf("輸入Matrix B:\n"); 
	scanf(" %d%d%d",&o,&p,&b_nonzero);
		b[o][p]={0};
   		for(i=0;i<b_nonzero;i++)
   		{
   		scanf(" %d%d%d",&row,&col,&value);
   		b[row][col] = value;
		}
  	}
}
  
void mtranspose()
{
printf("b transpose:\n");
printf("numRows = %d, numCols = %d\n",p,o);
printf("The matrix by row, column and value:\n");
for(i=0;i<p;i++)
{
   	for(j=0;j<o;j++)
   	{
     	if(b[j][i]!=0)
		{
		printf("%d %d %d",i,j,b[j][i]);
		printf("\n");
		}
  	}
}
}


void mmult()
{
	for(i=0;i<m;i++)
    {
      for(j=0;j<o;j++)
      {
        for(k=0;k<n;k++)
        {  
		c[i][j]+=a[i][k]*b[j][k];
		}
      }
    }
    printf("\n\na * b transpose:\n");
	printf("numRows = %d, numCols = %d\n",m,o);
	printf("The matrix by row, column and value:\n");
	for(i=0;i<m;i++)
    {
      for(j=0;j<o;j++)
      { 
      if(c[i][j]!=0)
      	{
      	printf("%d %d %d",i,j,c[i][j]);
      	printf("\n");
	  	}
	  }
    }
}

  
