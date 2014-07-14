#include<set>
#include "mydef.h"

using namespace std;

//
// determine if all characters in a string are unique
// input - input string
// size - size of the intput string
// 
// returns true if all characters in the string are unique
// false otherwise
//

// runtime O(n) to go through the input array + lookup time in set which affects space complexity of set as well
// 
bool ischarsunique(char* input, int size)
{
	set<char> markentrytable;
	for (int i = 0; i < size; i++) {
		if(markentrytable.find(input[i]) != markentrytable.end()) {
			return false;
		} else {
			markentrytable.insert(input[i]);
		}
	}
	return true;
}

// reverse a string

// input - input string
// size - input size

// runtime: O(n) to go through string once half way
void reversestring(char* input, int size) 
{
	int start = 0;
	int end = size - 1;
	char temp; 
	while (start > end) {
		temp = input[start];
		input[start] = input[end];
		input[end] = temp;
		start++;
		end--;
	}
}

// remove duplicate characters

// ex.
// aabc
// abac

void removeduplicate(char* input, int size) 
{
	int insertcount = 0;
	int scancount = 0;
	set<char> scannedCharLookup;

	while(scancount < size)
	{
		if (scannedCharLookup.find(input[scancount]) == scannedCharLookup.end()) {
			scannedCharLookup.insert(input[scancount]);

			if (insertcount != scancount) {				
				input[insertcount] = input[scancount];
			}
			insertcount++;
			scancount++;
		} else {			
			scancount++;
		}
	}

	input[insertcount] = '\0';
}

// ANAGRAM

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

bool isanagram(char* first, int sFirst, char* second, int sSecond)
{
	if (sFirst != sSecond) {
		return false;
	}

	qsort(first, sFirst, sizeof(char), compare); 
	qsort(second, sSecond, sizeof(char), compare);

	for (int i = 0; i < sFirst; i++)
	{
		if (first[i] != second[i])
			return false;
	}
	return true;
}

// rotate square image by 90 degrees

// AAA        CBA
// BBB  --->  CBA  
// CCC        CBA

// 123        741   
// 456  -->   852   
// 789        963

// 12345        l gb6 1
// 6789a        m hc7 2
// bcdef  -->   n id8 3
// ghijk        o je9 4 
// lmnop        p kfa 5

// if n = 6 i need 0, 1,2 if n = 5 need 0, 1
// if (n%2== 0) maxdepthlevel = n/2 - 1 else
// maxdepthlevel = (n-1)/2 - 1;

// for level = 0; j < maxdepthlevel; level++
// for i = level to N-1-level 
//   temp = Tbl[level][i];
//   Tbl[level][i] = Tbl[n-1-level-i][level]
//   Tbl[n-1-level-i][level] = Tbl[n-1-level][n-1-level-i]
//   Tbl[n-1-level][n-1-level-i] = Tbl[i][n-1-level]
//   Tbl[i][n-1-level] = temp

void rotateimage(char Tbl[][5], int n)
{
	char temp;
	int maxdepthlevel;

	if (n%2 == 0)
		maxdepthlevel = n/2;
	else
		maxdepthlevel = (n-1)/2;

	for( int level = 0; level < maxdepthlevel; level++) {
		for (int i = level; i < n-1-level; i++) {
			temp = Tbl[level][i];
			Tbl[level][i] = Tbl[n-1-i][level];
			Tbl[n-1-i][level] = Tbl[n-1-level][n-1-i];
			Tbl[n-1-level][n-1-i] = Tbl[i][n-1-level];
			Tbl[i][n-1-level] = temp;
		}
	}
}

