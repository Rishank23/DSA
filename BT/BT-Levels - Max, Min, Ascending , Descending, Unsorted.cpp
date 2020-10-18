//Quotes to  follow
//Codes  to  fulfill
/* BT-Levels - Max, Min, Ascending , Descending, Unsorted
Create a Binary Tree with given input data values of integers.
Implement the logic in  a Single function to print the following: 
Input  : 5 2 7 0 0 4 9 0 0 6 0 0 8 3 0 15 0 0 1 0 12 0 0
Output : 
1. Maximum of all levels : 15
2. Minimum of all levels  : 1
3. Ascending level numbers : 1 
4. Descending level numbers : 2
5. Unsorted level numbers : 3 */
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
btptr spl = new btnode(0);

struct queue{
	private:
		int r, f, capacity, count;
		btptr T[50];
	public:
		queue(){
			r = f = count = 0;
			capacity = 50;
		}
		void enqueue(btptr TT){
			if(isFull()) cout<<"queue is full\n";
			else{
				count++;
				T[f++] = TT;
				f = f%capacity;
			}
		}
		btptr dequeue(){
			if(isEmpty()) cout<<"queue is empty\n";
			else{
				count--;
				r = r%capacity;
				return T[r++];
			}
		}
		btptr peek(){
			if(isEmpty()) cout<<"queue is empty\n";
			else{
				r = r%capacity;
				return T[r];
			}
		}
		int getCount(){
			return count;
		}
		bool isEmpty(){
			return count==0;
		}
		bool isFull(){
			return count==capacity;
		}
};

void createBT(btptr &T, int n){
	if(T==NULL) T = new btnode(n);
	cin>>n;
	if(n!=0) createBT(T->lchild, n);
	cin>>n;
	if(n!=0) createBT(T->rchild, n);
}

void minOfAllLevels(btptr T, int *k){
	if(T!=NULL){
		if(T->data<*k) *k = T->data;
		minOfAllLevels(T->lchild, k);
		minOfAllLevels(T->rchild, k);
	}
}

void maxOfAllLevels(btptr T, int *k){
	if(T!=NULL){
		if(T->data>*k) *k = T->data;
		maxOfAllLevels(T->lchild, k);
		maxOfAllLevels(T->rchild, k);
	}
}

int checkOrder(queue q){
	if(q.getCount()==1) return -1;
	bool flagA = false, flagD = false;
	q.enqueue(q.dequeue());
	int a = q.peek()->data, b;
	q.enqueue(q.dequeue());
	while(q.peek()!=spl){
		b = q.peek()->data;
		q.enqueue(q.dequeue());
		if(a<b) flagA = true;
		else flagD = true;
		a = b;
	}
	if(flagA && flagD) return 0;
	else if(flagA) return 1;
	else if(flagD) return 2;
}

void ascendingOrderLevel(btptr T, queue q){
	if(T!=NULL && T!=spl){
		if(q.isEmpty()) q.enqueue(spl);
		if(T->lchild!=NULL) q.enqueue(T->lchild);
		if(T->rchild!=NULL) q.enqueue(T->rchild);
		if(q.peek()==spl){
			q.peek()->data++;
			if(checkOrder(q)==1){
				cout<<q.peek()->data<<" ";
			}
			q.enqueue(q.dequeue());
		}
		ascendingOrderLevel(q.dequeue(), q);
	}
}

void descendingOrderLevel(btptr T, queue q){
	if(T!=NULL && T!=spl){
		if(q.isEmpty()) q.enqueue(spl);
		if(T->lchild!=NULL) q.enqueue(T->lchild);
		if(T->rchild!=NULL) q.enqueue(T->rchild);
		if(q.peek()==spl){
			q.peek()->data++;
			if(checkOrder(q)==2){
				cout<<q.peek()->data<<" ";
			}
			q.enqueue(q.dequeue());
		}
		descendingOrderLevel(q.dequeue(), q);
	}
}

int main(){
	btptr T = NULL;
	queue q;
	int n;
	cin>>n;
	createBT(T, n);
	int t;
	int *ans = &t;
	t = INT_MAX;
	minOfAllLevels(T, ans);
	cout<<*ans<<"\n";
	t = INT_MIN;
	maxOfAllLevels(T, ans);
	cout<<*ans<<"\n";
	spl->data = 0;
	ascendingOrderLevel(T, q);
	cout<<"\n";
	spl->data = 0;
	while(!q.isEmpty()) q.dequeue();
	descendingOrderLevel(T, q);
	cout<<"\n";
}
