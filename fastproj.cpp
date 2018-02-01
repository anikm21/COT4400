#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

int binomial(int n, int k)//n choose k
{
	if(k==0)
	{
		return 1;
	}
	else
	{
		return(n*binomial(n-1,k-1))/k;
	}
}

int main(int argc, char *argv[])
{	
	if(argc!=3)
	{
		cout<<"Wrong amount of parameters specified"<<"\n";
		return 1;
	}
	
	ifstream infile; //declarations of input and output files
	ofstream outfile;
	int num=0;
	int binomiala=0;
	int binomialb=0;
	int total=0;
	int b=0;
	int n=0;
	int k=0;
	
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
		infile >> b;
		infile >> n;
		infile >> k;
		
		for(int j=0;j<n;j++)// apply a formula to the variables
		{
			total+=pow(-1.0,(double) j)*binomial(n,j)*binomial((n+b-1-j*(k+1)),(b-j));
		}
		outfile<<total<<"\n";
		total=0;
	}
}

