//Excellence is being able to perform 
//at a high level over And over again.
//You can hit a half-court shot once. 
//That's just the luck of the draw.
//If you consistently Do it... that's excellence. 
/* Binary Search Tree – Levels  
Create a binary tree with given input data.
Print all the following level orders.
Input data: 5 8 3 4 1 9 6 7 2 -1
Output level orders :
1. Level order : 5 3 8 1 4 6 9 2 7
2. Reverse reversed level order: 7 2 9 6 4 1 8 3 5
3. Reverse level order : 2 7 1 4 6 9 3 8 5
4. Squirrel level order (clock-wise start): 5 8 3 1 4 6 9 7 2
5. Squirrel level order (anti-clock-wise start): 5 3 8 9 6 4 1 2 7
6. Alternate odd-level reversal level order : 5 8 3 1 4 6 9 7 2
7. Alternate even-level reversal level order: 5 3 8 9 6 4 1 2 7 */
#include<iostream>
using namespace std;

typedef struct bstnode{
	struct bstnode *lchild;
	int data;
	struct bstnode *rchild;
} *bstptr;

struct stack{
	private:
		int top, size;
		bstptr T[50];
	public:
		stack(){
			top = -1;
			size = 50;
		}
		void push(bstptr BT){
			if(!isFull()){
				T[++top] = BT;
			}
		}
		bstptr pop(){
			if(!isEmpty()){
				return T[top--];
			}
		}
		bstptr peek(){
			if(!isEmpty()){
				return T[top];
			}
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
		int f, r, count, capacity;
		bstptr T[50];
	public:
		queue(){
			f = r = count = 0;
			capacity = 50;
		}
		void enqueue(bstptr BT){
			if(!isFull()){
				T[r++] = BT;
				r = r%capacity;
				count++;
			}
		}
		bstptr dequeue(){
			if(!isEmpty()){
				f = f%capacity;
				count--;
				return T[f++];
			}
		}
		bstptr peek(){
			if(!isEmpty()){
				f = f%capacity;
				return T[f];
			}			
		}
		bool isEmpty(){
			return count==0;
		}
		bool isFull(){
			return count==capacity;
		}
};

void printStack(stack s){
	while(!s.isEmpty()){
		cout<<s.pop()->data<<" ";
	}
}

void insert(bstptr &T, int k){
	if(T==NULL){
		T = new(bstnode);
		T->lchild = NULL;
		T->rchild = NULL;
		T->data = k;
	}else{
		if(k<T->data){
			insert(T->lchild, k);
		}else{
			insert(T->rchild, k);
		}
	}
}

void printLevelOrder(bstptr T, queue q){
	if(T!=NULL){
		cout<<T->data<<" ";
		if(T->lchild!=NULL){
			q.enqueue(T->lchild);
		}
		if(T->rchild!=NULL){
			q.enqueue(T->rchild);
		}
		if(!q.isEmpty()){
			printLevelOrder(q.dequeue(), q);
		}
	}
}

void printReverseReversedLevelOrder(bstptr T, queue q, stack s){
	if(T!=NULL){
		s.push(T);
		if(T->lchild!=NULL){
			q.enqueue(T->lchild);
		}
		if(T->rchild!=NULL){
			q.enqueue(T->rchild);
		}
		if(!q.isEmpty()){
			printReverseReversedLevelOrder(q.dequeue(), q, s);
		}else{
			printStack(s);
		}
	}
}

void printReverseLevelOrder(bstptr T, queue q, stack s){
	if(T!=NULL){
		s.push(T);
		if(T->rchild!=NULL){
			q.enqueue(T->rchild);
		}
		if(T->lchild!=NULL){
			q.enqueue(T->lchild);
		}
		if(!q.isEmpty()){
			printReverseLevelOrder(q.dequeue(), q, s);
		}else{
			printStack(s);
		}
	}
}

void printSquirrelLevelOrderClockwise(bstptr T, queue q){
	if(T!=NULL && q.isEmpty()){
		cout<<T->data<<" ";
		if(T->rchild!=NULL){
			q.enqueue(T->rchild);
		}
		if(T->lchild!=NULL){
			q.enqueue(T->lchild);
		}
	}else if(!q.isEmpty()){
		stack s;
		while(!q.isEmpty()){
			if(q.peek()->rchild!=NULL){
				s.push(q.peek()->rchild);
			}
			if(q.peek()->lchild!=NULL){
				s.push(q.peek()->lchild);
			}
			cout<<q.dequeue()->data<<" ";
		}
		while(!s.isEmpty()){
			q.enqueue(s.pop());
		}
	}else if(q.isEmpty()){
		return;
	}
	printSquirrelLevelOrderClockwise(NULL, q);
}

void printSquirrelLevelOrderAnticlockwise(bstptr T, stack s){
	if(T!=NULL && s.isEmpty()){
		cout<<T->data<<" ";
		s.push(T->rchild);
		s.push(T->lchild);
	}else if(!s.isEmpty()){
		queue q;
		while(!s.isEmpty()){
			if(s.peek()->lchild!=NULL){
				q.enqueue(s.peek()->lchild);
			}
			if(s.peek()->rchild!=NULL){
				q.enqueue(s.peek()->rchild);
			}
			cout<<s.pop()->data<<" ";
		}
		while(!q.isEmpty()){
			s.push(q.dequeue());
		}
	}else if(s.isEmpty()){
		return;
	}
	printSquirrelLevelOrderAnticlockwise(NULL, s);
}

int main(){
	bstptr T = NULL;
	int n;
	cin>>n;
	while(n>0){
		insert(T, n);
		cin>>n;
	}
	queue q;
	stack s;
	printLevelOrder(T, q);
	cout<<"\n";
	printReverseReversedLevelOrder(T, q, s);
	cout<<"\n";
	printReverseLevelOrder(T, q, s);
	cout<<"\n";
	printSquirrelLevelOrderClockwise(T, q);
	cout<<"\n";
	printSquirrelLevelOrderAnticlockwise(T, s);
	cout<<"\n";
	printSquirrelLevelOrderClockwise(T, q);
	cout<<"\n";
	printSquirrelLevelOrderAnticlockwise(T, s);
	cout<<"\n";
}
