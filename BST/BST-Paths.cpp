//The path to success is to take massive, determined action.
/* Binary Search Tree – Paths
Create a binary tree with given input data.
Print all the following types of Paths.
Input data: 5 8 3 4 1 9 6 7 2 -1
Output Paths:
1. All paths - Root to leaf : 5 3 1 2 
                              5 3 4 
                              5 8 6 7
                  	          5 8 9
2. Leftmost path :   5 3 1 2
3. Rightmost path : 5 8 9 
4. Maximum sum path:  5 8 6 7
5. Minimum sum path : 5 3 1 2
6. Path with sum s = 22  :  5 8 9
7. Path with maximum even numbers : 5 8 6 7
8.  Path with maximum odd numbers : 5 3 1 2 */
#include<iostream>
#include<sstream>
#include<string>
using namespace std;

typedef struct bstnode{
	struct bstnode *lchild;
	int data;
	struct bstnode *rchild;
	bstnode(int k){
		lchild = NULL;
		rchild = NULL;
		data = k;
	}
} *bstptr;

void insert(bstptr &T, int k){
	if(T==NULL){
		T = new bstnode(k);
	}else{
		if(k<T->data){
			insert(T->lchild, k);
		}else{
			insert(T->rchild, k);
		}
	}
}

void printAllPaths(bstptr T, string s){
	if(T!=NULL){
		ostringstream temp;
		temp<<T->data;
		s = s + temp.str() + " ";
		printAllPaths(T->lchild, s);
		printAllPaths(T->rchild, s);
		if(T->lchild==NULL && T->rchild==NULL) cout<<s<<"\n";
	}
}

void printLeftmostPath(bstptr T){
	if(T!=NULL){
		cout<<T->data<<" ";
		if(T->lchild!=NULL){
			printLeftmostPath(T->lchild);
		}else if(T->rchild!=NULL){
			printLeftmostPath(T->rchild);
		}
	}
}

void printRightmostPath(bstptr T){
	if(T!=NULL){
		cout<<T->data<<" ";
		if(T->rchild!=NULL){
			printRightmostPath(T->rchild);
		}else if(T->lchild!=NULL){
			printRightmostPath(T->rchild);
		}
	}
}

void printMaxSumPath(bstptr T, string *smax, string s, int var, int *max){
	if(T!=NULL){
		ostringstream temp;
		temp<<T->data;
		var+=T->data;
		s = s + temp.str() + " ";
		printMaxSumPath(T->lchild, smax, s, var, max);
		printMaxSumPath(T->rchild, smax, s, var, max);
		if(T->lchild==NULL && T->rchild==NULL && var>*max){
			*smax = s;
			*max = var;
		}
	}
}

void printMinSumPath(bstptr T, string *smin, string s, int var, int *min){
	if(T!=NULL){
		ostringstream temp;
		temp<<T->data;
		var+=T->data;
		s = s + temp.str() + " ";
		printMinSumPath(T->lchild, smin, s, var, min);
		printMinSumPath(T->rchild, smin, s, var, min);
		if(T->lchild==NULL && T->rchild==NULL && var<*min){
			*smin = s;
			*min = var;
		}
	}
}

void printPathUsingSum(bstptr T, int var, int sum, string s){
	if(T!=NULL){
		ostringstream temp;
		temp<<T->data;
		var += T->data;
		s = s + temp.str() + " ";
		printPathUsingSum(T->lchild, var, sum, s);
		printPathUsingSum(T->rchild, var, sum, s);
		if(T->lchild==NULL && T->rchild==NULL && var==sum) cout<<s;
	}
}

void printMaxEvenNumsPath(bstptr T, int var, int *min, string s, string *smin){
	if(T!=NULL){
		T->data%2==0?var++:var;
		ostringstream temp;
		temp<<T->data;
		s = s + temp.str() + " ";
		printMaxEvenNumsPath(T->lchild, var, min, s, smin);
		printMaxEvenNumsPath(T->rchild, var, min, s, smin);
		if(T->lchild==NULL && T->rchild==NULL && var>*min){
			*min = var;
			*smin = s;
		}
	}
}

void printMaxOddNumsPath(bstptr T, int var, int *min, string s, string *smin){
	if(T!=NULL){
		T->data%2==0?var:var++;
		ostringstream temp;
		temp<<T->data;
		s = s + temp.str() + " ";
		printMaxOddNumsPath(T->lchild, var, min, s, smin);
		printMaxOddNumsPath(T->rchild, var, min, s, smin);
		if(T->lchild==NULL && T->rchild==NULL && var>*min){
			*min = var;
			*smin = s;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	bstptr T = NULL;
	while(n>0){
		insert(T, n);
		cin>>n;
	}
	cout<<"\n";
	printAllPaths(T, ""); cout<<"\n";
	printLeftmostPath(T); cout<<"\n\n";
	printRightmostPath(T); cout<<"\n\n";
	string s = "";
	string *stemp = &s;
	n = INT_MIN;
	int *itemp = &n;
	printMaxSumPath(T, stemp, "", 0, itemp);
	cout<<*stemp<<"\n\n";
	s = "";
	n = INT_MAX;
	printMinSumPath(T, stemp, "", 0, itemp);
	cout<<*stemp<<"\n\n";
	printPathUsingSum(T, 0, 22, ""); cout<<"\n\n";
	s = "";
	n = INT_MIN;
	printMaxEvenNumsPath(T, 0, itemp, "", stemp);
	cout<<*stemp<<"\n\n";
	s = "";
	n = INT_MIN;
	printMaxOddNumsPath(T, 0, itemp, "", stemp);
	cout<<*stemp;
}
