#include <iostream>
#include <vector>

using namespace std;


//Code is taken from
//Data Structures and Algorithms in C++, 2nd Edition
//Michael T. Goodrich, Roberto Tamassia, David M. Mount

//Changes I made:
//I modified the code so that I now have max heap instead of originally min heap
//I added extra functions such that 'print', 'print_pq', and 'give_elem'.


template <typename E> 
class VectorCompleteTree{

public:
	
	private:
	vector<E> V; //we use a vector for a tree content

	public: 
	//typedef allows to create new names for types such as int ...
	//type definition
	//we now have pasition which means type vector<E>::iterator
	typedef typename vector<E>::iterator Position; //we use build in iterator for vector



	
	//was private!
	public: 

		Position pos(int i) //position is an iterator of vector
			{return V.begin()+i;} //v.begin returns an iterator pointing to the first elem in a vector
		//input here is iterator 

		int idx(const Position& p) const//map position to an idex
			{return p-V.begin();} //this gives index of position p








public:
	VectorCompleteTree()
		:V(1){} 

	int size() const
	{return V.size()-1;}

	Position left(const Position& p) //return left child
	{return pos(2*idx(p));} //pos(index)


	Position right(const Position& p) //return right child
	{return pos(2*idx(p)+1);} //to navigate to right child

	Position parent(const Position& p) //get parent
	{return pos(idx(p)/2);}

	bool hasLeft(const Position& p) const{ //we determine that based on size
		return 2*idx(p)<=size();}

	bool hasRight(const Position& p) const{
		return 2*idx(p)+1<=size();	}

	bool isRoot(const Position& p) const{
		return idx(p)==1;}

	Position root(){ //return position
		return pos(1);} 
	Position last() 
	{return pos(size());}
	//push element back of the vector 
	void addLast(const E& e)
	{V.push_back(e);} 
	//remove element
	void removeLast()
	{

		V.pop_back();} //remove one last element

	void swap(const Position& p, const Position& q)
	{E e=*q;
	*q=*p;
	*p=e;}


	void print(){
		//I have a vector called v and I want to print its values
		//Position i;
		for (Position i=pos(1); i<V.end(); i++){
			cout<<*i<<endl;}
	}



};





template <typename E, typename C>
	
	class HeapPriorityQueue{
	public:
		int size() const; //size of priority que

		bool empty() const; 

		//we need make that after insert we do swapping
		//to maintain heap property
		void insert (const E& e); //insert element into PQ


		//const E& min();


		//my changes 
		const E& max();

		//we remove minimum then we remove root
		void removeMax();  //remove minimum


		void print_pq(){
			T.print();
		}

		//now I want to return an element at given index
		E& give_elem(int i)
		{
			//I have a tree which is based on a vector 
			return *(T.pos(i)); //i use function pos

		}

	private:
		VectorCompleteTree<E> T; //this is just a Tree implemented, based
								//on a vector 
		C isLess;
		typedef typename VectorCompleteTree<E>::Position Position;
	};





template <typename E, typename C>
	int HeapPriorityQueue<E,C>::size()const {
		return T.size();}

template <typename E, typename C>
bool HeapPriorityQueue<E,C>::empty() const{
	return size()==0;}

template <typename E, typename C>
const E& HeapPriorityQueue<E,C>::max(){
	//We have a complete binary tree
	//minimum element here is root of a tree
	return *(T.root());}



template <typename E, typename C>
void HeapPriorityQueue<E,C>::insert(const E& e){
	T.addLast(e); //we now add e as last elemenet to a vector

	Position v=T.last();  //v now points to the last node

	while(!T.isRoot(v)){//while we did not reach root
		Position u=T.parent(v); //u points to parent of v

		if (!(*v>*u)) //if v's element is less than its parent element we have to swap
			{break;}
		T.swap(u,v); //we swap element node with its parent
		v=u;} //after we swap v now points to u 

	}



//we want to remove minimum element
//dont we remove root?
template <typename E, typename C>
void HeapPriorityQueue<E,C>::removeMax(){
	if (T.size()==1){ //we only have element 
		T.removeLast();} //we remove it 




	else{

		Position u=T.root(); //u now points to root

		T.swap(u, T.last()); // max elem becomes last

		T.removeLast(); //we now remove last elem which is max



		while(T.hasLeft(u)){ //we are at root now


			Position v=T.left(u);//v points to a left child of root)

			//right is less then left
			if ( T.hasRight(u) && *(T.right(u))>*(v) )
				{ //we compare right child and left child of root
				v=T.right(u);} //v now points to a bigger child child


			if (*(v)>*(u)){ //we now compare values of the biggest child and a root
				T.swap(u,v); //we swap with biggest child
				u=v;

				} //now u points to that node we swaped with



			else break;	 //if root has alredy the smallest node
			}				//then we break
		}
};


