//Life is a Mid
//Amid of Love
/* Adjust the misplaced two nodes to make a BST
Create a Binary tree of integers with given data.
In that Binary tree, two nodes are misplaced, swap those two nodes to make in BST.
You must have to traverse the tree only once ( touch each node only once)
test case : 
input : 5 3 1 0 2 0 0 6 0 0 8 4 0 7 0 0 9 0 0    ( 0 for Null node)
output( in order) : 1 2 3 4 5 6 7 8 9 */
#include<iostream>
using namespace std;

typedef struct btnode{
	struct btnode *lchild;
	int data;
	struct btnode *rchild;
	btnode(int k){
		data = k;
		lchild = NULL;
		rchild = NULL;
	}
} *btptr;

void createBT(btptr &T, int n){
	if(T==NULL) T = new btnode(n);
	cin>>n;
	if(n!=0) createBT(T->lchild, n);
	cin>>n;
	if(n!=0) createBT(T->rchild, n);
}

void correctBST(btptr T, btptr &E1, btptr &E2, int min, int max){
	if(E1!=NULL && E2!=NULL){
		int temp = E1->data;
		E1->data = E2->data;
		E2->data = temp;
	}else if(T!=NULL){
		if(min>T->data || T->data>max){
			if(E1==NULL) E1 = T;
			else E2 = T;
		}
		correctBST(T->lchild, E1, E2, min, T->data-1);
		correctBST(T->rchild, E1, E2, T->data+1, max);
	}
}

void printInorder(btptr T){
	if(T!=NULL){
		printInorder(T->lchild);
		cout<<T->data<<" ";
		printInorder(T->rchild);
	}
}

int main(){
	btptr T = NULL;
	btptr E1 = NULL, E2 = NULL;
	int n;
	cin>>n;
	createBT(T, n);
	correctBST(T, E1, E2, INT_MIN, INT_MAX);
	printInorder(T);
}
