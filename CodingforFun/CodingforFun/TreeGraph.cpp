#include "mydef.h"

// decide if tree is balanced

template<class T>
int maxdepth(TreeNode<T>* root) {
	if(root == null)
		return 0; 
	return 1 + fmax(maxdepth(root->left), maxdepth(root->right));
}

template<class T>
int mindepth(TreeNode<T>* root) {
	if(root == null)
		return 0; 
	return 1 + fmin(maxdepth(root->left), maxdepth(root->right));
}

// return if balanced tree

bool isBalancedTree(TreeNode<T>* root) {
	if ( maxdepth(root)-mindepth(root) <=1 ) 
		return true;
	return false;
}


// check if two nodes are connected in graph using BFS then next do the same using DFS
// BFS = traverse in a

template<class T> 
bool IsTreeNodeConnected(Graph<T> S, GraphNode<T> one, GraphNode<T> two)
{
	stack<GraphNode<T>*> queue;

	for(GraphNode<T> s : S.GraphNodes) {
		s.nodeState = unvisited;
	}

	one.nodeState = visiting;
	queue.push(&one);
	
	while(!queue.empty()) {
		GraphNode<T>* cur = queue.top();
		queue.pop();
		for (GraphNode<T>* x : cur->adjacent) {
			if (x->nodeState == unvisited) {
				if (x == &two)
					return true;
				else {
					x->nodeState = visiting;
					queue.push(x);
				}
			}
			x->nodeState = visited;
		}
	}

	return false;
}

// given a sorted array make a binary tree with minimal height

template<class T>
TreeNode* MakeBSTfromArray(T array[], int first, int end)
{
	if ( end < first)
		return null;

	int mid = (first+end)/2;   // ex size = 5 mid = 2  size = 6 mid = 3

	TreeNode* left = MakeBSTfromArray(T, first, mid-1);
	TreeNode* right = MakeBSTfromArray(T, mid+1, end); 

	TreeNode* n = new TreeNode(array, left, right);
	return n;
}


// given BST, return array of sets containing nodes at each depth
template<class T>
vector<list<BST<T>>> arrayofsets(BST<T> root)
{
	vector<list<BST<T>>> result;
	list<BST<T>> cur;
	cur.push_back(root);
	result.push_back(cur);
	cur.clear();
	int level = 0;
	while(true)
	{
		for( BST<T> e : result[level])
		{
			if(e.left != null)
				cur.push_back(e.left);
			if(e.right != null)
				cur.push_back(e.right);
		}
		if (cur.empty())
			break;
		result.push_back(cur);
		cur.clear();
		level++;
	}
	return result;
}

// Given BST return next node of a node
//
// 1, 12, 30, 44, 50, 61 , 71
//
//          44
//      12      61
//    1   30  50   71
//           45 55 


// Return the next Node of a given node is BST
// if right node, left most child of right node
//  if 
// parent

template<class T>
BST<T>* LeftMostNode(BST<T>* node) 
{
	if (node == null)
		return null; 
	BST<T>* myNode = node;
	
	while(myNode->left) {
		myNode = myNode->left;
	}
	return myNode;
}

template<class T>
BST<T>* NextValueinBST(BST<T>* node)
{
	if (node != null) {
		BST<T> * p; 
		if (node->parent == null || node->right != null) {
			return LeftMostNode(node->right);
		}
		while((p = node->parent) != null ) {
			if (p->left == node)
				return p;
			e = p;
		}
	}
	return null;
}

// find first common ancestor
//
//          1
//      2        3
//   4     5  6     7
// 8   9 10

 // {100, 180, 260, 310, 40, 535, 695}

int maxprofit(int input[], int count)
{
	int res = 0;
	int min = input[0];
	int max = input[0];

	for( int i = 0; i < count; i++) {
		if (input[i] > max)
			max = input[i];
		else if(input[i] < min)
		{
			res+=(max-min);
			min = max = input[i];
		}
	}
	return res; 
}

struct TNode {
	int val;
	TNode* left;
	TNode* right;
};

// Given a Binary Tree return vector of list such that at position i in vector, it contains list node at deapth i in the binary tree

vector<list<TNode*>> TreetoList(TNode* root)
{
	vector<list<TNode*>> lists;
	list<TNode*> templist;
	templist.push_back(root);
	lists.push_back(templist);


	int i = 0;
	while (true)
	{
		templist.clear();
		for ( list<TNode*>::iterator it = lists[i].begin(); it != lists[i].end(); it++)
		{
			TNode* node = *it;
			if (node->left)
				templist.push_back(node->left);
			if (node->right)
				templist.push_back(node->right);
		}
		i++;
		if (!templist.empty())
			lists.push_back(templist);
		else
			break;
	}

	return lists;
		
}