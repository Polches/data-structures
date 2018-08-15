//The code is taken from 
//Data Structures and Algorithms in C++, 2nd Edition
//Michael T. Goodrich, Roberto Tamassia, David M. Mount
//I implemented this code to learn data structures
//I added my own comments and main program


#include <iostream>
using namespace std;

//Question 5.9
//I need to write a queue
// queue is based on a Circular linked list
typedef int Elem;
class CNode{
	Elem el;
	CNode* next;
	friend class CircleList;

};

typedef int Elem;

class CircleList {

public:
	CircleList();
	~CircleList();
	bool empty() const;
	//add element to the front
	void add(const Elem& e);

	//delete element front element
	void remove();

	//get front element
	const Elem& front() const;

	const Elem& back() const;
	//get rear element
	void advance(); //we just advance that cursor

private:
	//we dont have a head but we have a cursor which points to rear
	//cursor->next points to front
	CNode* cursor;

};


CircleList::CircleList()
: cursor(NULL){}

//DESTRUCTOR 
CircleList::~CircleList(){
	while(!empty())
	{
		CircleList::remove();
	}
}

bool CircleList::empty() const{
	return cursor==NULL;
}

//remove front node
void CircleList::remove(){
	CNode* v;
	//we to remove front node
	v=cursor->next;
	//if there is just one elemnt
	if (v==cursor)
		cursor=NULL;
	else
		cursor->next=v->next;
	delete v;

}



void CircleList::add(const Elem& e){
	//WE CREATED A NEW NODE 
	CNode* a=new CNode;
	a->el=e;
	if (cursor==NULL){
		a->next=a;
		cursor=a;}	

	else{
		//we add to the front
		a->next=cursor->next;
		cursor->next=a;	}
}



void CircleList::advance()
{
	cursor=cursor->next; 
}

const Elem& CircleList::front() const{

	
	return cursor->next->el;
}

const Elem& CircleList::back() const{
	return cursor->el; 
}



/////NOW WE IMPLEMENT A QUEUE BASED ON A LIST
typedef int Elem;
class LinkedQueue{
//main functions
public:
	LinkedQueue();
	//we realy on a Clist destructor 
	int size();
	bool empty();
	const Elem& front1() const;
	
	void enqueue(const Elem& e);
	void dequeue();
private:
	int n;
	CircleList C;
};
//enque  //insert rear
//deque //delete front
//front()
//empty()
//size();
LinkedQueue::LinkedQueue()
:n(0), C(){} //we just created an object

bool LinkedQueue::empty(){
	return n==0;}
int LinkedQueue::size(){
	return n;}
const Elem& LinkedQueue::front1() const{
	//return front elem
	return C.front(); }


void LinkedQueue::enqueue(const Elem& e){
	//we add element to the front
	C.add(e);
	C.advance();
	n++;
}
//we remove front elem 
void LinkedQueue::dequeue(){
	C.remove();
	n--;
}





//some comment on implementing a stack using an array

//recall in q we want to insert objects to rera or front

//we have an array and we define three variables

//f,n,r 
//f is index of front elem
//r is an index of rear elem
//n is just curent number of elements in an array

//initialy we set n=0 and f=r=0 for an empty que

//when we deque (delete from front)
		//we decrement n--
		//f++ (we move front index to the right)
//when we enqueue (add elem to the rear)
		//n++
		//r++
//in this case it's easy to get out of scope

//we want index f and r to "wrap around" the end of Q
//we now see Q as a circular array

//that goes from Q(0 till Q[N-1] and then Q(0) again)
//
//
// to this we use modular operator which gives a remonder
// when we deque:
		// f=(f+1) mod N 
		//n=n-1

//then when we enqueue:
		//r=(r+1) mod N //this allows us to view this array as a circular array
		//n=n+1			//reminder will be an actual index of an array
						//let's say array size is 10.
						//r=10, we increment 10+1
						//then 11 mod 10=1 then we have index 1
						//we move around a circle 
//
//
//




//Application of ques

//we use queue in a breadth first tree traversal



int main(){
	LinkedQueue que;

	CircleList list;


	list.add(2);
	list.add(3);
	list.add(4);
	list.add(5);


	list.remove();
	que.enqueue(5); //we insert to the back 
	cout<<que.front1()<<endl; //5
	que.enqueue(3); //insert to the back
	cout<<que.front1()<<endl; //5
 	que.enqueue(6);
 	cout<<que.front1()<<endl; //5,3,6

 	que.dequeue();
 	cout<<que.front1()<<endl; //3

	cout<<que.size()<<endl;




	//que.dequeue();
	//int k=que.front1(); 
	//que.dequeue(); //3
	//cout<<que.front()<<endl;



	return 0; 
}
