
//The code is taken from 
//Data Structures and Algorithms in C++, 2nd Edition
//Michael T. Goodrich, Roberto Tamassia, David M. Mount
//I implemented this code to learn data structures
//I added my own comments and main program



#include <iostream>
using namespace std;
//circular linked list does not have head or tail
//special node marked as CURSOR
// we have an element called back, and the next element followed immidiattly
// called front
//we dont immplement a templated curcular list here
//and instead we just use a typedef

typedef string Elem;

class CNode{

	Elem el;
	CNode* next;

	friend class CircleList;
};


class CircleList
{
	public:
		CircleList(); //constructor
		~CircleList(); //destructor
		bool empty() const;// to check if list is empty

		const Elem& front() const; //return element at cursor

		const Elem& back() const; //element which is next to cursor

		void advance(); //move cursor

		void add(const Elem& e); //add element

		void remove(); //remove a node after cursor???

	private:
		CNode* cursor; //we now have a cursor which is a pointer to the node
};


CircleList::CircleList() //constructor
: cursor(NULL){ }

//we now need to write destructor
CircleList::~CircleList()
{
	while(!empty())
	{
		remove();
	}
}


//NOW LET'S WRITE EMPTY FUNCTION
bool CircleList::empty() const
{
	return (cursor==NULL);
}


//return element at the cursor which is back
const Elem& CircleList::back() const
{
	return cursor->el;
}


//return element folowing the cursor i.e next node after the node pointed by the cursor
const Elem& CircleList::front() const
{
	return cursor->next->el;
}

//we now see that cursor points to the "last" element we call back, and
//cursor->next points to the front element 
//advance-move cursor
void CircleList::advance()
{
	cursor=cursor->next; //cursor now points to cursor next
}
//we delete the front element
//we add the front element
//here is how to add
void CircleList::add(const Elem& e)
{
	//we want to add an element to the front
	//allocation
	CNode* a=new CNode;
	a->el=e; //now we have e insode a new box

	if (cursor==NULL)//then this is the first elememnt we add
	{		
		a->next=a; //the element now points to itself ie no NULL
		cursor=a;
	}
	else
	{
		//there one or more elements ie list is non empty
		a->next=cursor->next; //a->next now pints to the second elem in the list
							//recall that cursor still points to the old front node
		cursor->next=a; //cursor->next points to the front aded element only now
	}
}
//we want to remove node after cursor ie front node
void CircleList::remove()
{
	CNode* old;// we created a new pointer called old

	old=cursor->next; //old now is a pointer to the next node after cursor front

	if (old==cursor) //then there is just one element in the list
		cursor=NULL; //we now have an empty list

	else
		cursor->next=old->next;//now cursor next point to a node
								//after front, we can delete front 
	delete old;
}

int main()
{

CircleList list; //list is now a pointer to a class CircleList
//add element
//string B="SMTH";
//string A="smth";
//list->add(B);
//list->add(A);
//now we aded elements and I want to print the first element
//cout<<list->front();


list.add("one"); //one
list.add("two"); //two,one*

list.add("three");//three, two,one*

list.advance();// two,one, three*
list.advance();//one,three,two*


//it should print one
cout<<list.front();
//that's correct!

//if we did not use advance 
//then we would get three as an output: the last element we aded to the list 





	return 0;
}
