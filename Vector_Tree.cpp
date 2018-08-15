//The code is taken from 
//Data Structures and Algorithms in C++, 2nd Edition
//Michael T. Goodrich, Roberto Tamassia, David M. Mount
//I implemented this code to learn data structures
//I added my own comments and main program



#include <iostream>
#include <vector>
#include<list>
using namespace std;

//chapter 8
//heaps
//we will store elements in a binary tree
//heap is a binary tree 
//complete binary tree-binary tree in which all levels are filled except the last one
//in a last level nodes got added from left to right
//it has all the functions from binary tree plus two more functions
//add(e) remove()
//vector-based complete binary implementation
//nodes of T are stored in a vector A
//such that!
//index 1 is reserved for a root

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




int main(){


	VectorCompleteTree<int> T;
	T.addLast(1); 
			
	T.addLast(2);

	T.addLast(3);

	T.addLast(4);

	T.addLast(5);

	//root return position at index 1
	cout<<*(T.root())<<endl;
	
	cout<<*(T.left(T.root()))<<endl;

	cout<<*(T.right(T.root()))<<endl;

	cout<<*(T.left(T.left(T.root())))<<endl;

	cout<<*(T.right(T.left(T.root())))<<endl;


	return 0;
}


