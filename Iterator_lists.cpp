#include <iostream>
using namespace std;


//section 6.2.1
// side notes:
			//"You can redefine or overload most of the built-in operators available in C++.""

			//We can redifine operators in c++!!!\
			//Overloaded operators are functions with special type
			//the keyword "operator" followed by the sybol we want to redefine
			//box operator+(const Box&);
			//it declares an addition operator that can be used to add two box objects
			//and return final box object
			//(object is an instance of a class. when class is defined no memory is allocated
			//but when we create an object/instantiate then memory is allocated

//now go to CH1.5 AND READ OPERATOR OVERLOADING LOL
//SERIUOSLY
//Overloading means ->define an operator which has the same name but whose affect
//depends on the type of their arguments
//
//oprators such as +, -, * can be overloaded.
//suppose we have two objects of the same class which we called Passenger,
//and we want to write an equality test for these objects.
//we can do that by overloading == operator

//which can be done like this:

/*
bool operator==(const Passenger& x, const Passenger& y)
{
	return x.name==y.name
		&& x.mealPref==y.mealPref
		&& x.isFreqFlier==y.isFreqFlyer;
	}

*/
//we now can use p1==p2 :)
//this definition is similar to function definition
//but in place of a function name we use "operator=="
//in general == is replaced by whatever we want to overload/redefine
//for binary operators we have two arguments and for unary operators we have one argument
//
//
//we can also define input and output operators
//
//Back to lists, iterators, position
//
//
// element() -> returns a reference to the element stored at this position

//we overload a dereference operator (*), so that given a position variable p,
//its associated element can be accessed by *p rather  then p.element()
//
//we now have *p (p is a position), instead of p.element() 



//we have an object, called an iterator. Iterator is an extension of a position
//
//It supports an ability to access a node's element 
// but it also provides an ability to navigate forwards (and possibly backwards)
//thru a container
//there are many ways we can define ADT for an iterator object
//
//for example we have an object p
//p is an object of class Iterator
//we could define an operation p.next()
//which returns an iterator that returns a node right after p
//hm we use ++ instead->it's a more elegant way of doing this
//for doubly linked lists we can move back so we can define -- operator
//we need smth to initialize iterator
//so we have begin and end;


//class declaration of NodeList
typedef int Elem;
//list of nodes
class NodeList{

	private:	
	//node for a doubly linked lists
	typedef int Elem;
	struct Node {
	Elem elem; 
	Node* prev;
	Node* next;};//struct for a Node

public:

	class Iterator{
	public:
		Elem& operator*(){
		return v->elem;} 
	bool operator==(const Iterator& p) const{
		return v==p.v;}
	bool operator!=(const Iterator& p) const{
		return v!=p.v;}
	Iterator& operator++(){ //return an iterator which points to the next position
		v=v->next;
		return *this;} //return p, p now points to the next node
	Iterator& operator--(){//return an iterator which points to an old position
		v=v->prev;
		return *this;}
	friend class NodeList; //now our class has acces to NodeList class 

	private:
		Node* v; //i have a pointer to a node
		Iterator(Node* u){ //this is a private constructor.only nodelist is allowed
		v=u;}					//to make these private iterations
						//so a user does not have acces to Iterator constructor
						//everything is done inside a class
	};




public:
	NodeList(); //constructor
	int size() const;
	bool empty() const; 
	//We want to set iterator to start position
	Iterator begin() const; 
	//output is class iterator
	Iterator end() const;
	void insertFront(const Elem& e);
	// insert at front
	void insertBack(const Elem& e);
	// insert at rear
	void insert(const Iterator& p, const Elem& e);
	//input is element itself and an object p of class iterator

	void eraseFront();
	// remove first
	void eraseBack();
	// remove last
	void erase(const Iterator& p);
	// remove p


private:
	int n; //number of items
	Node* head;
	Node* trailer;
};



NodeList::NodeList(){
	n=0;
	head=new Node; 
	head->elem =100;
	trailer=new Node;
	trailer->elem=0;

	head->next=trailer;
	trailer->prev=head;}


int NodeList::size() const{
	return n;} 
bool NodeList::empty() const
{return n==0;}

NodeList::Iterator NodeList::begin() const{
	return Iterator(head->next); //we initialized iterator to the first elem in the list
}

NodeList::Iterator NodeList::end() const{ 	//we initialized iterator to trailer
										// (not the last node with elem)
	return Iterator(trailer);} 

void NodeList::insert(const NodeList::Iterator& p, const Elem& e){
	//we insert e before p

	Node* w=p.v; //w points to trailer 



	Node* k=new Node; //we crated a node
	
	k->elem=e; //we put element inside that node
	
	k->next=w->next; //link in v before w
	w->next = k;
	//w->prev=k;
	k->prev=w; //link in v after u
	n++;}



void NodeList::insertFront(const Elem& e){
	insert(begin(),e);}

void NodeList::insertBack(const Elem& e){
	insert(end(),e);}

void NodeList::erase(const Iterator& p){//we remove p
	Node* v=p.v; //we delete node v
				//v now points to the same node as iterator
				//so we want to delete a node at iterator
	Node* w=v->next;
	Node* u=v->prev;
	//we now want to unlink the node before we delet it
	u->next=w;
	w->prev=u;
	delete v;
	--n;}

void NodeList::eraseFront(){
	erase(begin());}

void NodeList::eraseBack(){
	erase(--end());}




int main(){


	NodeList List;

	//List.insertBack(3);

	
	List.insertFront(1);
	cout<<*((List.begin()))<<endl;

	List.insertFront(2);
	List.insertFront(3);//3,2,1


	//cout<<*(++(List.begin()))<<endl;



	
	return 0;
}