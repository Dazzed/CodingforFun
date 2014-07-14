#include<iostream>
#include<fstream>

using namespace std;

double besttime(double C, double F, double X)
{
	double curresult;
	double newresult;
	double cost = 0; 
	double rate = 2;
	
	double farmcost = C/rate;
	curresult = X/rate;
	if (curresult < farmcost)
		return curresult;

	while(true)
	{		
		cost += farmcost;
		rate += F;
		newresult = cost + X/rate;
		if (newresult >= curresult)
			break;
		else
			curresult = newresult;

		farmcost = C/rate; 
	}
	return curresult;
}

int printcookieclicklogic(int argc, char** argv) 
{
	if (argc != 2)
	{
		cout<<"supply file name plz"<<endl;
		return 0;
	}

	ifstream input(argv[1]);
	ofstream output("output");
	if (!input) 
	{
		cout<<"can't open file:"<<argv[1]<<endl;
		return 0;
	}

	int testcases;
	double C;
	double F;
	double X;
	
	input>>testcases;
	for ( int i = 0 ; i < testcases; i++)
	{
		input>>C;
		input>>F;
		input>>X;
		output.precision(7);
		output<<"Case #"<<i+1<<": "<<besttime(C, F, X)<<endl;
	}
}