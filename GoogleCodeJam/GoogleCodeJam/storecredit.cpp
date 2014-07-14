#include<iostream>
#include<fstream>
#include<conio.h>

#include<unordered_map>

using namespace std;

int storecredit(int argc, char** argv)
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
	int cost;
	int totalitems;
	int item;
	int desiredvalue;
	
	unordered_map<int,int> pricetolocation;
	unordered_map<int, int>::iterator element;

	input>>testcases;
	for (int i = 0 ; i < testcases; i++)
	{
		input>>cost;
		input>>totalitems;
		input>>item; // first item insert into location		

		pricetolocation.insert(make_pair(item, 1));
		bool isFound = false;
		for (int j = 1; j < totalitems; j++ )
		{
			input>>item;
			desiredvalue = cost - item;
			if (!isFound)
			{
				if ((element = pricetolocation.find(desiredvalue)) != pricetolocation.end())
				{
					// we found the result!
					output<<"Case #"<<i+1<<": "<<element->second<<" "<<j+1<<endl;					
					pricetolocation.clear();
					isFound = true;
				}
				else
				{
					pricetolocation.insert(make_pair(item, j+1));
				}
			}
		}
	}
	return 1;
}