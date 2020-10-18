//Be Fair in Exam
//To Fare Maximum
/* Find largest BST in given BT
Create a Binary tree with given data of integers.
Find the largest Binary Search Tree in the BT.
input :  27 18 15 9 0 0 0 22 12 8 0 0 0 45 32 0 0 72 0 0 36 25 0 0 63 54 0 0 0
output : In order of largest BST : 8 12 22 32 45 72 */
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

void printInorder(btptr T){
	if(T!=NULL){
		printInorder(T->lchild);
		cout<<T->data<<" ";
		printInorder(T->rchild);
	}
}

void checkBST(btptr T, int *length, int min, int max){
	if(T!=NULL && *length!=-1){
		(*length)++;
		if(T->data>max || T->data<min) *length = -1;
		checkBST(T->lchild, length, min, T->data-1);
		checkBST(T->rchild, length, T->data+1, max);
	}
}

void getMaxBST(btptr T, btptr &BST, int *max){
	if(T!=NULL){
		int n = 0;
		int *length = &n;
		checkBST(T, length, INT_MIN, INT_MAX);
		if(*length!=-1 && *length>*max){
			*max = *length;
			BST = T;
		}
		getMaxBST(T->lchild, BST, max);
		getMaxBST(T->rchild, BST, max); 
	}
}

int main(){
	btptr T = NULL;
	int n;
	cin>>n;
	createBT(T, n);
	n = 0;
	int *x = &n;
	getMaxBST(T, T, x);
	printInorder(T);
}
