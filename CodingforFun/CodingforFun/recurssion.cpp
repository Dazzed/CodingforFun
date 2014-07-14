#include "recurssion.h"
#include <list>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

list<int> Q;
void PrintQueue(list<int>& myQ);
void printmysubsets(int input[], int size, int subsetdepth, int index)
{
	if(subsetdepth == 0)
	{
		PrintQueue(Q);
		return; 
	}
	for (int i = index; i < (size - subsetdepth) + 1; i++)
	{		
		Q.push_back(input[i]);
		printmysubsets(input, size, subsetdepth-1, i+1);
		Q.pop_back();
	}
}
vector<set<int>> subsets(set<int> myset, int index)
{
	vector<set<int>> res;
	set<int> temp;
	// index is the index in the set. set doesn't change the order of elements once stored. 

	if ( index == myset.size())
	{
		// work backword 
		res.push_back(temp);
	}
	else
	{
		// add the returned set to result plus append the item located at index at the returned
		// set and add those subsets
		// ex. 
		// subset of {0, 1} = {}, {0}, {1}, {0,1} 
		// subset of {0, 1, 2} = {}, {0}, {1}, {0,1}, {2}, {0,2}, {1,2}, {0,1,2}

		vector<set<int>> prevset = subsets(myset, index + 1);
		res.insert(res.end(), prevset.begin(), prevset.end());
		set<int>::iterator it = myset.begin();
		advance(it, index);
		int item = *(it);
		for (vector<set<int>>::iterator it1 = prevset.begin(); it1 != prevset.end(); it1++)
		{
			temp = *it1;
			temp.insert(item);
			res.push_back(temp);
		}
	}
	return res;
}


void PrintQueue(list<int>& myQ);
void paths(int x, int y,int input[][3], int n)
{
	if (x >= n || y >= n)
		return;
	Q.push_back(input[x][y]);

	if (x == n-1 && y == n-1)
	{
		PrintQueue(Q);
	}
	 
	if (x < n)
	{
		paths (x + 1, y, input, n);
	}
	if ( y < n)
	{
		paths (x, y + 1, input, n);
	}

	Q.pop_back();
}

void PrintVectorofSet(vector<set<int>> input)
{
	for (vector<set<int>>::iterator it = input.begin(); it != input.end(); it++)
	{
		set<int> temp = *it;
		cout<<"{ ";
		for (set<int>::iterator it1 = temp.begin(); it1 != temp.end(); it1++)
		{
			cout<<*it1<<",";
		}
		cout<<" }"<<endl;
	}
}

void PrintQueue(list<int>& myQ)
{
	for(list<int>::iterator it = myQ.begin(); it !=myQ.end(); it++)
	{
		cout<<*it;
		cout<<"->";
	}
	cout<<endl;
}

typedef unsigned long long int MyInt;

MyInt fibbs(int n)
{
	MyInt prev = 1; // fibbs(1)
	MyInt prevprev = 0; // fibbs(0)
	MyInt cur;

	if (n == 0)
		return prevprev;
	else if (n == 1)
		return prev;
	else
	{
		for (int i = 2; i <=n; i++)
		{
			cur = prev + prevprev;
			prevprev = prev;
			prev = cur;
		}
	}
	return cur;
}


// given 2n people pair em in groups of two so total n pair in a group
// print all n pairs

// so example
// input {1, 2}
// output { 1,2 }

// input {1 , 2 , 3 , 4 }
// output {{1,2} {3, 4}} {{1,3} {2,4}} {{1,4}{2,3}}

// input {1, 2, 3, 4, 5, 6} = 15 group

// pesudo code
//
// if input is just two numbers then we could pair them and display them.
// if input is four numbers we can pair first number with second, then first with third
// and then first with five and other pair is just remaining two numbers

// expanding upon the idea
// use a vector of pairs to keep track of a valid combination
// we print this valid combination when we are down to last pair

// we pair every number with one of the remaining numbers in the set
// then recurively keep trying to do the same until we are down to two numbers

vector<pair<int, int>> group;

int countlines = 0;

void grouptwos(int A[], int index, int size)
{
	for (int i = index + 1; i < size; i++)
	{
		swap(A[index + 1], A[i]);
		group.push_back(make_pair(A[index], A[index + 1]));
		if (size - index == 2)
		{
			cout<<++countlines<<"  {";
			for(unsigned j = 0; j < group.size(); j++)
			{
				cout<<"{"<<group[j].first<<", "<<group[j].second<<"} ";
			}
			cout<<"}"<<endl;
			group.pop_back();
			return;
		}
		grouptwos(A, index + 2, size);
		group.pop_back();		
	}
}

template <class T>
class MyQueue {
	stack<T> one;
	stack<T> two;
public:
	
	void enqueue(T val) { one.push_back(val); }
	T dequeue() 
	{
		T res;
		if (two.empty())
		{
			while(!one.empty())
			{
				two.push(one.top());
				one.pop();
			}
		}
		res = two.top();
		two.pop(); // handle the empty stack case on your own.
		return res;
	}
};

// real^2 = (guess + error)^2
// real^2 = guess^2 + 2*guess*error + error^2
// e
// real^2-guess^2 = error(2*guess + error)
// error = (real^2-guess^2)/2guess; 
// new guess
// guess + error = (real^2 - guess^2)/2guess
// x1 = 1/2(n/x0 + x0)
double mysqrt(double n)
{

	// first find the closest integar to it

	double curguess = -1;
	while (++curguess <= n)
	{
		if (curguess*curguess >= n)
		{
			break;
		}
	}


	if ( curguess*curguess != n)
	{
		curguess--;
		double error; 
		double newguess = curguess;
		do
		{
			curguess = newguess;			
			error = (n/curguess - curguess)/2;
			newguess = error + curguess;
		}while (error > 0.0001);
	}
	return curguess;
}



// {1, 2, -5, 10, 0, - 15, -1, 3, -4}
// maximize 10 - (-17)) = 27

// let's consider a pointer that moves through the set which breaks set into two
// regions - left and right which are subsets

// for each of these subsets we want to consider max and min values
// and then use the ones that give best possible diff

// following structure keeps track of max and min for a given subset
struct elem {
	int maxsum;
	int minsum;
	int min;
	int max;

	elem() : maxsum(0), minsum(0), min(0), max(0) {}
	elem& operator = (int a) { maxsum = a; minsum = a; min = a; max = a; return *this; }
	elem& operator + (int a) { maxsum+=a; if (maxsum < 0) maxsum = 0; if (maxsum > max) max = maxsum;
	                           minsum+=a; if (minsum > 0) minsum = 0; if(minsum < min) min = minsum; return *this; }
};

int maxdiffinsubsets(int A[], int size)
{
	elem *DA1 = new elem [size - 1];
	elem* DA2 = new elem [size - 1];
	int i;
	int bestdiff = 0;

	// create a dynamic array that stores min and max of all possible subsets
	DA1[0] = A[0];
	for (i = 1; i < size - 1; i++)
	{
		DA1[i] = DA1[i-1] + A[i]; 
	}

	// this second array is the counter part to the first one so for example
	// for a set {1, 2, -1 } if DA1 got {1} covered, DA2 will cover {2, -1}

	DA2[size-1] = A[size-1];
	for (i = size - 2; i >= 0; i--)
	{
		DA2[i] = DA2[i + 1] + A[i];
	}

	// find the best combination
	for (i = 0; i < size - 1; i++)
	{
		int temp = max(DA1[i].max - DA2[i].min, DA2[i].max - DA1[i].min);
		if (temp > bestdiff)
			bestdiff = temp;
	}

	return bestdiff;
}

// find max sum of numbers from set where max sum is maximized and you can't pick adjesant 
// numbers

// ex. {1, -10, 20,50} 
// ans: 1+ 50 = 51;
// well with one answer's one,
// with two the answer is greater of two
// with three the answer is 1, sum of 1 and 3 or 2

int maxsumrecinternal(int A[], int size, int index)
{
	if (index >= size)
		return 0;

	int first = A[index];
	int second = 0;

	if (index + 2 < size)
	{
		first += maxsumrecinternal(A, size, index + 2);
		if ( first < A[index] )
			first = A[index];
	}

	if (index + 1 < size)
	{
		second = maxsumrecinternal(A, size, index + 1);
	}

	return max(first, second);
}
		
	

int maxsumrec(int A[], int size)
{
	return maxsumrecinternal(A, size, 0);
}

int maxsum (int A[], int size)
{
	if (size == 0)
		return 0;
	
	if (size == 1)
		return A[0];

	int *DA = new int [size];

	DA[0] = A[0];
	DA[1] = max(A[0], A[1]);

	for (int i = 2; i < size; i++)
	{
		DA[i] = max(max(A[i], DA[i-2] + A[i]), DA[i-1]); 
	}

	int res = DA[size - 1];
	
	delete [] DA;

	return res;
}


//
// Statement: Given a set of even numbers, group any two and create possible combination
//            print all possible groups
//            ex. {1, 2} -> {1, 2}  1 to 1
//            ex. {1,2,3,4} -> {{1,2}, {3,4}} {{1,3}, {2, 4}}  {{1, 4 } {2, 3}}  4 to 3
//            ex. {1,2,3,4,5,6} -> {{1,2}{3,4}{5,6}} {{1,2}{
//            
//            solution: 
//            for 6 there would be 5 * 3 = 15 combinations 

void grouptwosinternal(int A[], int size, int index);
void setofgroupoftwos(int A[], int size)
{
	if ( size % 2 != 0 )
		return ; // error!
	
	grouptwosinternal(A, size, 0);
}

// logic: use index to move through the set
//        pair two elements for each lvl using loop
//        then recurively do the same
//        ex. {1, 2, 3, 4} 
//        pair 1 and 2 then call the function recurively 
//        pair 1 and 3 then call function recurively
//        so on

int global = 0;
void grouptwosinternal(int A[], int size, int index)
{
	for (int i = index + 1; i <= size - 1; i++)
	{
		swap(A[index + 1], A[i]);
		grouptwosinternal(A, size, index + 2); 
	}

	// print the arrangement
	if (index >= size)
	{
		
		cout<<++global<<"-{";
		for (int i = 0; i < size; i+=2)
		{
			cout<<"{"<<A[i]<<","<<A[i+1]<<"}";
		}
		cout <<"}"<<endl;
	}
}

// print all subsets of a set
// {0,1} - {}{0}{1}{0,1}}
//         0, 1, 2, 3
//         non, 0, 1, 0 and 1
//       - none, first second both 
// {0, 1, 2} - {}{0}{1}{2}{0,1}{0,2}{1,2}{0, 1, 2}
//             none    1,   2,    4,    3,  
//             0000,0001,0010, 0100, 0011,0101, 0110, 0111
// print all subsets of a set

void printsubsets(int A[], int size)
{
	int i = -1;
	int bits = 0;
	int pos = 0;
	int count = 0;
	int totalsets = pow(2, size);
	while(++i < totalsets)
	{
		bits = i;
		cout<<"{";
		while(bits)
		{
			if(bits & 0x01)
			{
				if (count++ != 0)
					cout<<", ";
				cout<<A[pos];
			}
			bits>>=1;
			pos++;
		}
		pos = 0;
		count = 0;
		cout<<"}"<<endl;
	}
}

// given a link list find if it is circular or straight if circular find the node where it loops

struct LNode {
	int val;
	LNode* next;
};

//
// 1-2-3-4-5-6
//       |   |
//       9-8-7
//
// suppose two runners x and y=2x
// loop distance to loop node = d
// when x and y meets distance covered
// by y = 2 * distance covered by x

void printmysubsets(int input[], int size, int subsetdepth, int index);
// possible strings

string res;
void possibletext(char* input)
{
	if (input == nullptr ||
		input[0] == '\0')
	{
		cout<<res<<endl;
		return;
	}

	// read first digit and print
	if (input[0] >='1' && input[0] <='9' && input[1] != '0')
	{
		int num = (input[0] - '0') - 1;
		res += ('a'+num);
		possibletext(input+1);
		res.pop_back();
	}

	// handle the special case where two digits can be combined
	if (input[0] == '1' ||
		(input[0] == '2' && input[1] >= '1' && input[1] <='6'))
	{
		int num = (input[0]-'0')*10 + (input[1]-'0') - 1;
		res += (char)('a'+num);
		possibletext(input+2);
		res.pop_back();
	}
}

//
// 12---------------------991
//       32------161
//            92-------------------1093
//
// the goal is to add up the interactions only once
// suppose we divide up all possible intervals 
// ex 12 - 32, 32 - 92, 92 - 161 etc
// and check for given array intervals if atleast two includes the test interval
// then we take the test interval distance
int fraudFeet(int spanCount, int* start, int* end)
{
	int result = 0;
	set<int> uniquenumbers; 
	
	
	// create list of all potentional unique intervals
	for (int i = 0; i < spanCount; i++)
	{
		uniquenumbers.insert(start[i]);
		uniquenumbers.insert(end[i]);
	}	
	
	vector<int> uniquenums(uniquenumbers.begin(), uniquenumbers.end());
	sort(uniquenums.begin(), uniquenums.end());

	for (int i = 0; i < uniquenums.size()- 1; i ++)
	{
		int count = 0;
		for ( int j = 0; j < spanCount; j++)
		{
			// check if j th pair covers the small interval we are considering
			if (start[j] <= uniquenums[i] && end[j] >= uniquenums[i+1]) 
			{
				count++;
			}

			if (count == 2)
			{
				result += (uniquenums[i+1] - uniquenums[i]);
				break;
			}
		}
	}
	return result;	 
}
