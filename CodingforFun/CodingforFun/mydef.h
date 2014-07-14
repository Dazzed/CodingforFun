#ifndef _MYDEF
#define _MYDEF
#include<string>
using namespace std; 

void removeduplicate(char* input, int size);
void rotateimage(char Tbl[][5], int n);

template<size_t rownum, size_t colnum>
void TurnZeros(int (&Table)[rownum][colnum]);

template<class T>
struct Node {
	T data;
	Node<T>* next;
};

// Stack and Queue
#include <deque>
#include<list>

template<class T>
class ThreeStack {
private:
	template<class S>
	struct StackNode {
		S value;
		int prev; // prev node index
		StackNode(S val, int pre) { value = val; prev = pre; }
	};

	StackNode<T>* buffer;
	deque<int> freeindex;

	int stackindex[3];
public:
	// individual stack size
	ThreeStack(int size) {
		buffer = new StackNode<int>[size*3]; // continuous space for three stacks
		for (int i = 0; i < size; i++) {
			freeindex.push_back(i);
		}
		for (int i = 0; i < 3; i++) {
			stackindex[i] = -1;
		}
	}

	void push(int stacknum, T val);
	T pop(int stacknum);
	};

#include<vector>

template<class T>
class MyStack {
	vector<T> mystack;
	vector<T> minstack;
public:
	MyStack(int size = 100) { mystack.reserve(size); } 
	void push(T val); 
	T pop();
	T min();
};

#include<stack>
void TowerofHanoi(int depth, stack<int>& src, stack<int>& dest, stack<int>& buff);

#include<cmath>

template<class T>
struct TreeNode {
	T val;
	TreeNode<T> left;
	TreeNode<T> right;
};

#include<set>

enum GraphNodeState {
	unvisited,
	visiting,
	visited 
};

template<class T>
struct GraphNode {
	T val;
	GraphNodeState nodeState; 
	set<GraphNode*> adjacent;
};

template<class T>
struct Graph {
	set<GraphNode<T>> GraphNodes;
};

template<class T>
class BST {
	T val;
	BST<T>* left;
	BST<T>* right;
	BST<T>* parent;
public:
	BST() { parent = null; left = null; right = null  };
	// assign root value
	void assign(T val) {this.val = val; }
	// insert additional values
	void insert(T val) { BST<T> node = new BST<T>();
	                     if(val < this.val)
							this.left = node;
						 else
							 this.right = node;
					   };
};
#endif