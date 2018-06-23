#include <iostream>
using namespace std;

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
//return memory on stack??





int main()
{
	return 0;
}

