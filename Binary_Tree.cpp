
//Data Structures and Algorithms in C++, 2nd Edition

//Michael T. Goodrich, Roberto Tamassia, David M. Mount





#include <iostream>
#include <vector>
#include<list>
using namespace std;

//we code position for a binary tree
typedef int Elem;
//class Binary tree
class LinkedBinaryTree{
	protected:		
	struct Node{ //this is just a node of a tree
	Elem elt;//this is element value
	Node* par; //parent
	Node* left; //pointer to left child
	Node* right; //pointer to right child
	Node(): elt(), par(NULL), left(NULL), right(NULL){}
	};

	public:
		//we now write a generic class position
		class Position{
			private:
			Node* v; //we now have node v declared
			public:
		//v now points to the same box as input v
			Position(Node* _v=NULL) //constructor of position
			:v(_v){}
			Elem& operator*() //so now we get element using *operator
			{return v->elt;} //whever we use *v we return elem
			Position left() const //get left child
			{return Position(v->left); }
			Position right() const //get right child
			{return Position(v->right);}

			Position parent() const //get parent
			{ return Position(v->par);}

			bool isRoot() const //root of a tree
			{return v->par==NULL;} //v->parent does not have any parents then it's root

			bool isExternal() const //an external node
			{
			return (v->left==NULL&&v->right==NULL);}

			friend class LinkedBinaryTree; //we give the class binary tree
						//access to position
		};
	//list<object> myList
	//this is a list of Positions 
		typedef std::list<Position> PositionList; //list of positions

	public:
		LinkedBinaryTree(); //constructor
		int size() const; 
		bool empty() const;
		Position root() const; //return type is position, we return root position
		PositionList positions() const; //list of nodes
		void preorder (Node* v, PositionList& pl) const;
		void addRoot();
		//we use this whrn we want to expand external node and make it internal
		void expandExternal(const Position& p);
		Position removeAboveExternal(const Position& p);
	private:
		Node* _root; //pointer to the root
		int n; //number of nodes/
	};

//We have also included a declaration of the class
//PositionList, as an STL list of positions

LinkedBinaryTree::LinkedBinaryTree() //constructor. root points to null and size is 0
: _root(NULL), n(0){}

int LinkedBinaryTree::size() const{
	return n;}

bool LinkedBinaryTree::empty() const{
	return size()==empty();
}
//return type is position
LinkedBinaryTree::Position LinkedBinaryTree::root() const
{return Position(_root);} //constructor 

void LinkedBinaryTree::addRoot(){ //we add root, size becomes 1
	n=1;
	_root=new Node;}
//p was external now it will become external by creating two external nodes
//error will occur if p is an internal node.
//we create two new nodes
//we add two cheilder,left and right
void LinkedBinaryTree::expandExternal(const Position& p){
	Node* v=p.v; //v now points to the same as p's node
				//v has a pointer left, pointer right, pointer parent
	v->left=new Node;
	v->right=new Node;
	v->left->par=v;
	v->right->par=v;
	n=n+2;
}
//we delete the node at which p points to
//we delete its parent as well
LinkedBinaryTree::Position LinkedBinaryTree::removeAboveExternal(const Position& p){
	Node* w=p.v; //now w points to the same node as position points to
	Node* v=w->par; //we now have to pointers to nodes we want to delete
	//removal of w and its parent may result in another child becoming a parent
	//we just want to have a pointer called sib to the node which left
	Node* sib;
	if (w==v->left){
		sib=v->left;}
	else{
		sib=v->right;}
	if (v==_root){
		_root=sib; //now that left sib becomes root
		sib->par=NULL;}
	else{ //if v is not root
		Node* gpar=v->par; //we now connect nodes with each other
		if (v==gpar->left){
			gpar->left=sib;}
		else {
			gpar->right=sib;
			sib->par=gpar;}		}
	delete w;
	delete v;
	return Position(sib);}



//PositionList (return type) is define inside a class LinkedBinaryTree
LinkedBinaryTree::PositionList LinkedBinaryTree::positions() const{
	PositionList pl; //we created a list which contains positions//"nodes"
	//traversal is here	
	preorder(_root,pl);
	return PositionList(pl);}



//it is just a list of elements
void LinkedBinaryTree::preorder(Node* v, PositionList& pl) const{
	pl.push_back(Position(v)); //we add a node v into the list
	if (v->left != NULL) //we visit left children first
		preorder(v->left, pl);
		
	if (v->right!=NULL)
		preorder(v->right, pl); }




int main(){

LinkedBinaryTree T;



T.addRoot(); //now a node for a root was created 

//We go to T, we go to root (root is a node) from that we navigate to node 'left' elt=3

//position is initialized with root

//T.root ->returns position root
*(T.root())= 3;

cout<<*(T.root())<<endl;

T.expandExternal(T.root()); //we created left and right child



//position points to root; position points to left
*(T.root().left())=4;
cout<<*(T.root().left())<<endl;
//T.root.elt=1;
*(T.root().right())=6;

T.expandExternal(T.root().left()); 

T.expandExternal(T.root().left());

*(T.root().left().left())=10;

T.positions(); //Position List is returned




cout<<T.size()<<endl;









return 0;

}
