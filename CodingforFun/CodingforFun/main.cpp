#include<iostream>
#include"mydef.h"

using namespace std;

// globals
const unsigned int TEST_SIZE = 50;

// turn all elements of rows and columns zero, if an element
// is encountered to be zero

// runtime would be O(mn) 
// memory requirement would be O(m+n)
template<size_t rownum, size_t colnum>
void TurnZeros(int (&Table)[rownum][colnum])
{
	int rows[rownum];
	int rowentries = 0;
	int columns[colnum];
	int columnentries = 0;

	for (int i = 0; i < rownum; i++) {
		for (int j = 0; j < colnum; j++) {
			if (Table[i][j] == 0) {
				rows[rowentries++] = i;
				columns[columnentries++] = j;
			}
		}
	}
	 
	for (int i = 0; i < rowentries; i++) {
		for (int j = 0; j < colnum; j++)
		Table[rows[i]][j] = 0;
	}

	for (int i = 0; i < columnentries; i++) {
		for (int j = 0; j < rownum; j++)
			Table[j][columns[i]] = 0;
	}
}

int main(int argc, char** argv)
{
	// remove duplicate test
	//
	char* teststringone = new char[TEST_SIZE];
	char* teststringtwo = new char[TEST_SIZE];
	
	strcpy(teststringone, "aabd");
	strcpy(teststringtwo, "abad");

	removeduplicate(teststringone, strlen(teststringone));
	removeduplicate(teststringtwo, strlen(teststringtwo));

	// rotate an image
	char Tbl[][5] = {
		{ 'a', 'b', 'c', 'd', 'e', },
		{ 'f', 'g', 'h', 'i', 'j', },
		{ 'k', 'l', 'm', 'n', 'o', },
		{ 'p', 'q', 'r', 's', 't', },
		{ 'u', 'v', 'w', 'x', 'y', }
	};

	rotateimage(Tbl, 5);

	int Tbl1 [][4] = {
		{ 1, 2, 3, 4 },
		{ 4, 5, 0, 1 },
		{ 1, 5, 1, 5 }
	};
	
	TurnZeros(Tbl1);

	stack<int> a;
	stack<int> b;
	stack<int> c;

	a.push(8);
	a.push(7);
	a.push(6);
	a.push(5);
	a.push(4);
	a.push(3);
	a.push(2);
	a.push(1); 

	TowerofHanoi(8, a, b, c);
	return 0;
}

