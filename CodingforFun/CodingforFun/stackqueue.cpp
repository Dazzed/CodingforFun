#include "mydef.h"

template<class T>
void ThreeStack<T>::push(int stacknum, T val)
{
	if(freeindex.empty())
		return; 

	int newindex = freeindex.pop_front();
	previndex = stackindex[stacknum];
	stackindex[stacknum] = newindex; 
	StackNode<T> newStacknode(val, previndex);
	buffer[newindex] = newStackNode;
}

// make sure to use isempty before poping
template<class T>
T ThreeStack<T>::pop(int stacknum)
{
	int curindex = stackindex[stacknum];
	int newindex = buffer[curindex].prev;
	stackindex[stacknum] = newindex;
	freeindex.push_back(curindex);
	return buffer[curindex].value;
}

template<class T>
void MyStack<T>::push(T val)
{
	mystack.push_back(val);
	if (val < minstack[minstack.size()-1])
		minstack.push_back(val);
}

template<class T>
T MyStack<T>::pop()
{
	T retval = mystack.pop_back();
	if (retval == minstack[minstack.size()-1])
		minstack.pop_back();
	return retval;
}

template<class T>
T MyStack<T>::min()
{
	return minstack[minstack.size()-1];
}

// tower of hanoi

//
//  1              1
//  2              2
//  3              3
//  4              4
//  A B C        A B C

//  STEP2                         STEP1
//  goal move 1,2,3 to C            move 1 to B
//  move 4 to B                   move 2 to C
//  move 1, 2,3  back to B           move 1 to C

//  STEP3
//  move 1 to A
//  move 2 to B
//  move 1 back to B

#include<stack>

int factorial(int n)
{
	return n * factorial(n- 1);
}
void TowerofHanoi(int depth, stack<int>& src, stack<int>& dest, stack<int>& buff)
{
	if (depth == 1)
	{
		dest.push(src.top()); 
		src.pop();
	}
	else
	{
		TowerofHanoi(depth-1, src, buff, dest);
		dest.push(src.top());
		src.pop();
		TowerofHanoi(depth-1, buff, dest, src);
	}
}

template<class T>
class MyQueue {
	stack<T> primary;
	stack<T> dump; 

public:
	MyQueue(); 
	void push(T val);
	T top();
	void pop();
};

template<class T>
void MyQueue<T>::push(T val)
{
	primary.push(val);
}

template<class T>
T MyQueue<T>::top()
{	 
	if (dump.empty())
	{
		while(!primary.empty())
		{
			dump.push(primary.top());
			primary.pop();
		}
	}
	return dump.top();
}

// given a set of number return all possible subsets of size n where n < m, m is the size of set

//{1, 2, 3, 4, 5, 6} n = 3 -> {1,2, 3 } {1,2,4 } {1, 2, 5} {1,3,4} {1,3 5} {1,4,5}, 

//
//  vector<int> subset;
//  getsubset(S, subsetlen)
//    arraylen = S.len;
//    if (subsetlen == 0)
//       print subset
//       return; 
//    for i = 0; i =< (arraylen - subsetlen); i++
//      subset.push(S[i]);
//      getsubset(S+1, subsetlen-1)
//      subset.pop();
//   

/// Question:
//  sort a stack in assending order
//  1                                                                 1
//  2   ->   2      ->   1        ->        1    ->    2       ->     2
//  3        3   1       3   2          3   2          1   3          3 


template<class T>
void sortmystack(stack<T>& input)
{
	stack<T> temp;
	while(!input.empty()) {
		temp.push(input.top());
		input.pop();
	}

	T val;
	while(!temp.empty()) {
		val = temp.top();
		while(!input.empty() && input.top > val) {
			temp.push(input.top());
			input.pop();
		}
		input.push(val);
	}	
}