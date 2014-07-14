#include<iostream>
#include<fstream>
#include<string>

using namespace std;

string& reverseword(string& line, int start, int end) 
{
	char temp;
	while(start<end)
	{
		temp = line[start];
		line[start] = line[end];
		line[end]=temp;
		start++;
		end--;
	}
	return line;
}

string reverseline(string line)
{
	string& reversestring = reverseword(line, 0, line.length()-1);
	int start = 0;
	int end = 0;
	while (end < (int)line.length())
	{
		if(reversestring[end]==' ')
		{
			reversestring = reverseword(line,start,end-1);			
			start = end + 1;
		}
		end++;
	}
	reverseword(line, start, end - 1);
	return line;
}

int printreverselines(int argc, char** argv)
{
	if (argc !=2)
	{
		cout<<"please provide filename"<<endl;
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
	string line;

	input>>testcases;
	getline(input, line);
	for (int i=0; i < testcases; i++)
	{
		getline(input, line);
		output<<"Case #"<<i+1<<": "<<reverseline(line)<<endl; 

	}
	return 1;
}