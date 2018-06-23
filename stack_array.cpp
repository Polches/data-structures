#include <iostream>
using namespace std;


template <typename E>
class ArrayStack{
	enum {DEF_CAPACITY=100};
public:
	ArrayStack(int cap=DEF_CAPACITY); //CONSTRUCTOR FROM CAPACITY
	~ArrayStack();

	int size() const; //number of items in the stack

	bool empty() const; //if the stack is empty

	const E& top() const; //return top element

	void push(const E& e); //push element onto the stack

	void pop(); //pop the stack delete an element from the stack


//To keep the code simple, we have omitted the
//standard housekeeping utilities, such as a destructor, an assignment operator, and a
//copy constructor. We leave their implementations as an exercise.
	//i implemented destructor but not copy constructor and not assing,ent operator


private:
	E* S; //array of stack elements
	int capacity; //number of elements in an array
	int t;  //t gives index of thr top element in array S
			//t is the number of elements

};


template <typename E>
ArrayStack<E>::ArrayStack(int cap)
: S(new E[cap]), capacity(cap), t(-1){} //constructor using capasity
//we initialize t to -1 and use this value for t to identify when stack is empty 

template <typename E>
ArrayStack<E>::~ArrayStack()
{
	 delete S; //we just delete an array S 
}


template <typename E>
bool ArrayStack<E>::empty() const{
return (t<0); }

template <typename E>
int ArrayStack<E>::size() const
{return (t+1);} //so if size if 0 then -1+1 is 0

template <typename E>
const E& ArrayStack<E>::top() const{  //we retern element at index t
	return S[t]; //hmmm
}

template <typename E>
void ArrayStack<E>::push(const E& e){ 
	t=t+1; //we increment index 
	S[t]=e; //add element
}


template <typename E>
void ArrayStack<E>::pop(){ //remove element??
	t=t-1;
}



int main()
{


	ArrayStack<int> A; //default capacity is now 100

	A.push(1);
	A.push(2);
	A.push(3);
	A.push(4);

	cout<<A.top()<<endl; //should be 4

		A.pop(); //decrement index t
		cout<<A.top()<<endl; //shoulb be 3

	//and then we add a new element it will add than element instead of the place
		//of the last element becasue we decremented index

		A.push(100);

	cout<<A.top()<<endl; //should be 100
	return 0;
}