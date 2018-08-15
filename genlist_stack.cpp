//The code is taken from 
//Data Structures and Algorithms in C++, 2nd Edition
//Michael T. Goodrich, Roberto Tamassia, David M. Mount
//I implemented this code to learn data structures
//I added my own comments and main program

//Templated stack implementation based on a LinkedList


#include <iostream>
using namespace std;
//i inserted implementation of generic linked list here
template<typename E> 
class TLinkedList; //we declared a class and now we make that a friend to our first class

template<typename E>//we now create templated list
class TNode {
private:
	E elem; //type of an element is now E
	TNode<E>* next; 
	friend class TLinkedList<E>;
};


template <typename E>
class TLinkedList {
	public:
		TLinkedList(); //constractor
		~TLinkedList(); //destractor
		bool empty() const; //to check if list empty
		void removeFront(); //remove front
		void addFront(const E& e); //add element of type E
		const E& front() const; //return front element 
	private:
		TNode<E>* head;  //head of the list, pointer to node

		TNode<E>* cursor;

};
//function defenitions here:
template <typename E>        //this is a constructor
TLinkedList<E>::TLinkedList()
: head(NULL){}

template <typename E> //destructor
TLinkedList<E>::~TLinkedList()
{while(!empty()) //put condition inside while
	removeFront();}

template <typename E>
bool TLinkedList<E>::empty() const //empty?
   {return head==NULL;}

template <typename E>
void TLinkedList<E>::removeFront() //remove front
{
	//we want to remove the first element
	TNode<E>* old;
	old=head;
	head=old->next;
 delete old;
}

template <typename E>
void TLinkedList<E>::addFront(const E& e) //add front elem
{
	TNode<E>* a=new TNode<E>; //allocation for a new element

	a->elem=e;
	a->next=head;
	head=a;

}
template <typename E> 
const E& TLinkedList<E>::front() const
	{ return head->elem; }
//implement stack using generic linked list
typedef string Elem; //we now do not implement a truly generuc stack
					//for the sake of saving some space
					//we will use Elem of type string in this example
					//the task of producing a truly generic list is left as an 
					//exercise

class LinkedStack{
public:
	LinkedStack();      //constructor
	int size() const;   //number of items in the stack
	bool empty() const; //check if stack is empty
	const Elem& top() const; //throw(StackEmpty);  //return a reference to the top element
												//and then it also throws error thing
												//if stack is empty there is no top element?
	void push(const Elem& e);	//push element onto stack 
								//insert element to the top of the stack
	void pop(); //throw(StackEmpty); //pop the stack
								  //remove the top element from the stack
								  //if stack is empty then error occurs 

	void print(); //prints the stack
private:
	TLinkedList<Elem> S; //now S private linked list of type Elem
	int n; //number of elements in the stack


};
//now let's define an arror condition
//for throw
//RuntimeExeption inherits all the data and member functions in Stack Empty
//in addition RuntimeExeption also can have its own memmbers
//we have a general class for this runtime Exception
//taken from section 2.4 
//generic Exeption class

/*
class RuntimeException {
// generic run-time exception
	private:
	string errorMsg; //we have avariable type string
	public:
	RuntimeException(const string& err) {errorMsg = err;} //constructor
											    //errorMsg=whatever our input is
	string getMessage() const{return errorMsg;}
};
//we now write class StackEmpty
//stack empty has evrything RuntimeExeption has + its own memebers
//I guess having generic RuntimeException helps us write a class way faster 
class StackEmpty: public RuntimeExeption{
public:
	//constructor+its definition here
	StackEmpty(const string& err):RuntimeException(err){}    
	//this is a constructor for class Stack 
	//this constructor has an input value err	
	//now Runtime exception is filled with err message 
};    
*/
//function definitions
//constructor. we dont define destructor cause we realy on destructor of a generic linked list
LinkedStack::LinkedStack()
:S(), n(0){}

int LinkedStack::size() const{
	return n;}

bool LinkedStack::empty() const{
	return n==0;
}
//we now want to get a front element
const Elem& LinkedStack::top() const{ //throw(StackEmpty){
	//if (empty()) throw StackEmpty("Top of empty stack"); //argiment is passed to the constructor
	return S.front();} //return head->elem

//we want to add elements to the stack
void LinkedStack::push(const Elem& e){
	++n;
	S.addFront(e);
}

void LinkedStack::pop(){ //throw(StackEmpty){
	//if (empty()) throw StackEmpty("Pop from empty stack");
	--n;
	S.removeFront();
}

void LinkedStack::print()
{
	//print stack elements without deleting
	S.front(); //cursor points to front
	
}
//matching paranthesis in html 
//application of a stack
//matching paranthesis and grouping symbols in arithmetic expressions
//left and right symbols must match up
int main(){
	LinkedStack stack; //we now creared a stack
	//we have pop push front 
	string sum;
	stack.push(5);
	cout<<stack.top()<<endl;
	stack.push(3);
	cout<<stack.top()<<endl;
	stack.pop();
	cout<<stack.top()<<endl;
	return 0;
}







