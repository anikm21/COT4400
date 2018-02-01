#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int b; //number of robots
int n; //number of stacks
int k; //max robots per stack

int robo(int **matrix, int rob, int stacks, int max);
int main(int argc, char *argv[])
{	
	if(argc!=3)
	{
		cout<<"Wrong amount of parameters specified"<<"\n";
		return 1;
	}
	
	ifstream infile; //declarations of input and output files
	ofstream outfile;
	int num;
	
	infile.open(argv[1]); //opening files
	outfile.open(argv[2]);
	
	if (!(infile.is_open())) //check to make sure both are open
	{
		cout << "Could not open input.txt" << endl;
		return -1;
	}
	if (!(outfile.is_open()))
	{
		cout << "Could not open output.txt" << endl;
		return -2;
	}
	
	infile >> num; //grabs the number of iterations
	
	for (int i = 0; i < num; i++) //loop through each iteration
	{		
		//read row and column from input.txt
		infile >> b;
		infile >> n;
		infile >> k;

		int **matrix = new int*[n + 1]; //dynamically allocate 2d array for each iteration
		for (int i = 0; i <= n; ++i)
		{
			matrix[i] = new int[b + 1];
		}

		for (int i = 0; i <= b; i++)
		{
			for (int j = 0; j <= n; j++)
			{
				matrix[i][j] = -1; //initialize every value to -1 (means hasnt been set)
			}
		}
		
		robo(matrix, b, n, k); //call function
		
		outfile << matrix[b][n]<<"\n";
		
		delete matrix; 
	}
	return 0;
}


int robo(int **matrix, int rob, int stacks, int max)
{
	if (rob < 0 || stacks < 0) //out of bounds and ignore
		return 0;
	if (matrix[rob][stacks] != -1) //value already reached
	{
		return matrix[rob][stacks];
	}

	if (rob == 0) //base case b=0
	{
		matrix[rob][stacks] = 1;
		return matrix[rob][stacks];
	}
	
	if (stacks == 0)
	{
		matrix[rob][stacks] = 0;
		return matrix[rob][stacks];
	}
	
	if (rob > (stacks * max))
	{
		matrix[rob][stacks] = 0;
		return matrix[rob][stacks];
	}
	if (stacks == 1)
	{
		matrix[rob][stacks] = 1;
		if (rob > (stacks * max))
			matrix[rob][stacks] = 0;
			}
	
	
	if ((rob > (stacks * max))) //not enough volume
	{
		matrix[rob][stacks] = 0;
		
	}

	int temp = 0;
	for (int i = 0; i <= max; i++)//i<=k
	{
		temp += robo(matrix, rob - i, stacks - 1, max); //recursive call
	}
	matrix[rob][stacks] = temp;

	return matrix[rob][stacks];
}