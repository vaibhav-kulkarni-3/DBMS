#include<iostream>
using namespace std;

int main()
{
	int data[10];
	int recdata[10],e1,e2,e3,errpos;
	cout<<"\nEnter Message code : ";
	cin>>data[2];
	cin>>data[4];
	cin>>data[5];
	cin>>data[6];
	data[0] = data[2]^data[4]^data[6];
	data[1] = data[2]^data[5]^data[6];
	data[3] = data[4]^data[5]^data[6];
	cout<<"\nHamming Code Generated : ";
	for(int i=0;i < 7;i++)
	{
		cout<<data[i];
	}
	
	cout<<"\nEnter received bits : ";
	for(int i=0;i<7;i++)
	{
		cin>>recdata[i];
	}
	e3 = recdata[3]^recdata[4]^recdata[5]^recdata[6];
	e2 = recdata[1]^recdata[2]^recdata[5]^recdata[6];
	e1 = recdata[0]^recdata[2]^recdata[4]^recdata[6];

	errpos = e3*4+e2*2+e1;
	cout<<errpos;
	if(recdata[errpos-1] == 1)
	{
		cout<<"\nError is present at position : "<<errpos;
	}
	else
	{
		cout<<"\nError is not present";
	}
	cout<<"\nCorrected Hamming Code is : ";
	if(recdata[errpos-1] == 1)
	{
		recdata[errpos-1] = 0;
	}
	else
	{
		recdata[errpos-1] = 1;
	}
	
	for(int i=0;i < 7;i++)
	{
		cout<<recdata[i];
	}
	return(0);
}

/*
Enter Message code : 1
1
1
0

Hamming Code Generated : 0010110
Enter received bits : 1
0
1
0
1
1
0
1
Error is present at position : 1
Corrected Hamming Code is : 0010110
*/
