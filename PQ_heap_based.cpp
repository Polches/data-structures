#include <iostream>
#include <vector>
#include<list>
using namespace std;


//heap is a complete binary tree
//this is a heap based priority Queue
//here we make sure that we insert and remove elements so that
//we still satisfy the property of a heap. 


template <typename E> 
class VectorCompleteTree{

public:
	
	private:
	vector<E> V; //we use a vector for a tree content

	public: 
	//typedef allows to create new names for types such as int ...
	//type definition
	//we now have pasition which means type vector<E>::iterator
	typedef typename vector<E>::iterator Position; 
	protected:

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
	{return pos(2*idx(p)+1);} //

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
	{V.pop_back();}

	void swap(const Position& p, const Position& q)
	{E e=*q;
	*q=*p;
	*p=e;}

};



template <typename E, typename C>
	
	class HeapPriorityQueue{
	public:
		int size() const; //size of priority que

		bool empty() const; 

		//we need make that after insert we do swapping
		//to maintain heap property
		void insert (const E& e); //insert element into PQ


		const E& min();

		//we remove minimum then we remove root
		void removeMin();  //remove minimum

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
const E& HeapPriorityQueue<E,C>::min(){
	//We have a complete binary tree
	//minimum element here is root of a tree
	return *(T.root());}

template <typename E, typename C>
void HeapPriorityQueue<E,C>::insert(const E& e){
	T.addLast(e); //we now add e as last elemenet to a vector

	Position v=T.last();  //v now points to the last node

	while(!T.isRoot(v)){//while we did not reach root
		Position u=T.parent(v); //u points to parent of v

		if (!(*v<*u)) //if v's element is less than its parent element we have to swap
			{break;}
		T.swap(u,v); //we swap element node with its parent
		v=u;} //after we swap v now points to u 

	}



//we want to remove minimum element
//dont we remove root?
template <typename E, typename C>
void HeapPriorityQueue<E,C>::removeMin(){
	if (T.size()==1){ //we only have element 
		T.removeLast();} //we remove it 
	else{

		Position u=T.root(); //u now points to root

		T.swap(u, T.last()); //we swap last elem with the root

		T.removeLast(); //we removed root
		//now we to make sure that we have a right order
		//inside a complete binary tree

		while(T.hasLeft(u)) //remember u points to root
		{
			Position v=T.left(u);//v points to a left child of u(root)

			//right is less then left
			if (T.hasRight(u) && (*(T.right(u))<*v))
				v=T.right(u); //v now is a smaller child
			if (*v<*u){
				T.swap(u,v); //we swap with smallest child
				u=v;}
			else break;	} //if root has alredy the smallest node
							//then we break
		}
};



int main(){
	HeapPriorityQueue<int, int> P;

	//error with operator isLess
	P.insert(10);

	P.insert(11);

	P.insert(1);
	P.removeMin();

	//P.insert(2);

	//P.insert(3);

	return 0;
}

