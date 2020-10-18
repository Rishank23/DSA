//Life is a Mid
//Amid of Love
/* Binary Search Tree – Create from Postorder  
Create a binary tree with given input data of post order traversal of it.
You must have to create with LRD . Not just reverse reading of  input.
Then print all levels line by line.
Input data:  2 1 4 3 7 6 9 8 5 -1
Output level line by line :
5
3 8
1 4 6 9
2 7 */
#include<iostream>
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
bstptr nextLine = new bstnode(-1);

struct stack{
	private:
		int top, elements[50], size;
	public:
		stack(){
			top = -1;
			size = 50;
		}
		void push(int x){
			if(isFull()) cout<<"stack is full\n";
			else elements[++top] = x;
		}
		int pop(){
			if(isEmpty()) cout<<"stack is empty\n";
			else return elements[top--];
		}
		int peek(){
			if(isEmpty()) cout<<"stack is empty\n";
			else return elements[top];
		}
		bool isEmpty(){
			return top==-1;
		}
		bool isFull(){
			return top==size-1;
		}
};

struct queue{
	private:
		int r, f, capacity, count;
		bstptr T[50];
	public:
		queue(){
			r = f = count = 0;
			capacity = 50;
		}
		void enqueue(bstptr TT){
			if(isFull()) cout<<"queue is full\n";
			else{
				count++;
				T[f++] = TT;
				f = f%capacity;
			}
		}
		bstptr dequeue(){
			if(isEmpty()) cout<<"queue is empty\n";
			else{
				count--;
				r = r%capacity;
				return T[r++];
			}
		}
		bstptr peek(){
			if(isEmpty()) cout<<"queue is empty\n";
			else{
				r = r%capacity;
				return T[r];
			}
		}
		bool isEmpty(){
			return count==0;
		}
		bool isFull(){
			return count==capacity;
		}
};

void createBSTfromLDR(bstptr &T, int k){
	if(T==NULL) T = new bstnode(k);
	else{
		if(k<T->data){
			createBSTfromLDR(T->lchild, k);
		}else{
			createBSTfromLDR(T->rchild, k);
		}
	}
}

void printBST(bstptr T, queue q){
	if(T!=NULL){
		if(T->data!=-1) cout<<T->data<<" ";
		if(T->lchild!=NULL) q.enqueue(T->lchild);
		if(T->rchild!=NULL) q.enqueue(T->rchild);
		if(!q.isEmpty() && q.peek()==nextLine){
			cout<<"\n";
			q.enqueue(q.dequeue());
		}
		if(!q.isEmpty())printBST(q.dequeue(), q);
	}
}

int main(){
	stack s;
	queue q;
	int n;
	cin>>n;
	while(n>0){
		s.push(n);
		cin>>n;
	}
	bstptr T = NULL;
	while(!s.isEmpty()){
		createBSTfromLDR(T, s.pop());
	}
	q.enqueue(nextLine);
	printBST(T, q);
}
