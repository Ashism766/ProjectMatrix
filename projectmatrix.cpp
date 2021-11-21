#include<iostream>
#include<stdlib.h>
using namespace std;

		
class matrix
{
private:
	
public:


int** invmatrix(int**A,int size)
{
	int **M=transmatrix(adjmatrix(A,size),size,size);
	int a=det(M,size);
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			M[i][j]/=a;
		}
	}
	return M;
}

int **create2Darray(int row,int col)
{
	int**M=(int**)malloc(col*sizeof(int*));
	for(int i=0;i<col;i++)
	{
		int *temp=new int[row];
		M[i]=temp;
	}
	return M;
}

int det(int **A,int size){
	if (size==2)
	{
		return(A[0][0]*A[0][1]-A[1][0]*A[1][1]);
	}
	else if (size==3){
		return( A[0][0]*(A[1][1]*A[2][2]-A[1][2]*A[2][1])- A[0][1]*(A[1][0]*A[2][2]-A[1][2]*A[2][0])+A[0][2]*( A[1][0]*A[2][1]-A[1][1]*A[2][0]));
	}
	else if(size==4)
	{
		int a=(A[0][0]*A[1][1]-A[0][1]*A[1][0])*(A[2][2]*A[3][3]-A[2][3]*A[3][2]);
		int a2=-1*(A[0][0]*A[1][2]-A[0][2]*A[1][0])*(A[2][1]*A[3][3]-A[2][3]*A[3][1]);
		int a3=(A[0][0]*A[1][3]-A[0][3]*A[1][0])*(A[2][1]*A[3][2]-A[2][2]*A[3][1]);
		int b=-1*(A[0][1]*A[1][3]-A[0][3]*A[1][1])*(A[2][0]*A[3][2]-A[2][2]*A[3][0]);
		int c=(A[0][1]*A[1][2]-A[0][2]*A[1][1])*(A[2][0]*A[3][3]-A[2][3]*A[3][0]);
		int d=(A[0][2]*A[1][3]-A[0][3]*A[1][2])*(A[2][0]*A[3][1]-A[2][1]*A[3][0]);
		return(a+a2+a3+b+c+d);
	}
  }


void PrintMatrix(int **A,int row, int col)
{
	for(int i=0;i<row;++i)
	{
		for (int j=0;j<col;++j)
		{
			cout<<A[i][j]<<" ";
		}
		cout<<"\n";
	}
	return;
}



int **transmatrix(int **A,int row,int col){
	int** B=create2Darray(col,row);
	for(int i=0;i<row;++i)
	{
		for(int j=0;j<col;j++)
		{
			B[j][i]=A[i][j];
		}
	}
	return B;
}

int **matrix_input(int **A,int row,int col)
{
		cout<<"Please enter the matrix element row wise: \n";
	for(int i=0;i<row;i++)
	{	
		for(int j=0;j<col;j++)
		{
			cin>>A[i][j];
		}
	}
	return A;
}


int **cofac_matrix(int **A,int size)
{
	int **N=create2Darray(size,size);
	int p=0,q=0;
	for(int i=0;i<size;++i){
		for(int j=0;j<size;++j)
		{
			int **M=create2Darray(size-1,size-1);
			
			int temp;
			if((i+j)%2==0)temp=1;
			else temp=-1;
			
			for(int k=0;k<size;k++)
			{
				for(int l=0;l<size;l++)
				{
					if((k!=i)||(l!=j))M[p][q]=A[j][k];
					q++;
				}
				p++;
			}
			N[i][j]=det(M,size-1)*temp;
			delete(M);
		}
	}
	return N;
}


int** minor_matrix(int **A,int size)
{
	int **N=create2Darray(size,size);
	int p=0,q=0;
	for(int i=0;i<size;++i){
		for(int j=0;j<size;++j)
		{
			int **M=create2Darray(size-1,size-1);
			
			
			for(int k=0;k<size;k++)
			{
				for(int l=0;l<size;l++)
				{
					if((k!=i)||(l!=j))M[p][q]=A[j][k];
					q++;
				}
				p++;
			}
			N[i][j]=det(M,size-1);
			delete(M);
		}
	}
	return N;
}




int**adjmatrix(int **A,int size)
{
	if(size==2)
	{
		int **M=create2Darray(2,2);
		M[0][0]=A[1][1];
		M[1][1]=A[0][0];
		M[0][1]=-1*A[0][1];
		M[1][0]=-1*A[1][0];
		return M;
	}
	else {
		int **M=cofac_matrix(A,size);
		M=transmatrix(M,size,size);
		return M;
	}
		
	
}




};

int main()
{
	while(true){
		int x,row,col;
		cout<<"please enter row and column number of matrix: \n";
		cin>>row>>col;
		
		matrix Mx;
		int **A=Mx.create2Darray(row,col);
		A=Mx.matrix_input(A,row,col);
		Mx.PrintMatrix(A,row,col);
		cout<<Mx.det(A,row)<<endl;
		

	
	
}
	return 0;
}





