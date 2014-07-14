#include<iostream>
#include<fstream>
#include<string>

using namespace std;

string mapping[] = {
	"2",
	"22",
	"222",
	"3",
	"33",
	"333",
	"4",
	"44",
	"444",
	"5",
	"55",
	"555",
	"6",
	"66",
	"666",
	"7",
	"77",
	"777",
	"7777",
	"8",
	"88",
	"888",
	"9",
	"99",
	"999",
	"9999",
	"0"
};

string T9Spelling(string line)
{
	char prev = '!'; 
	string output ="";
	int index;
	for (int i = 0; i < line.length(); i++)
	{
		char inputchar = line[i];
		if ( inputchar == ' ')
			inputchar = 'z' + 1;

		index = inputchar - 'a';
		if (prev == mapping[index][0])
			output += " ";
		prev = mapping[index][0];

		output += mapping[index];
	}
	return output;
}
int printT9spellings(int argc, char** argv)
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
		output<<"Case #"<<i+1<<": "<<T9Spelling(line)<<endl; 

	}
	return 1;
}