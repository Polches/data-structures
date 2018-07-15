/******************************************************
  Heap.h -- Declarations for Basic Heap-of-Pair-of-Ints Class

  Stores pairs <element,priority> of ints.
  Supports O(log n) insertion, O(1) peeking at min priority and element 
  with min priority, and O(log n) extraction of element with min priority.
*******************************************************/
using namespace std;

class Heap{

public:
   // Constructors and Destructor
   // New empty Heap with default capacity.
   Heap();  
   // New empty Heap with capacity c.
   Heap(int c); 
   // New Heap with size s, consisting of pairs <Pi,Ei> where, 
   // for 0 <= i < s, Pi is Priorities[i] and Ei is value Elements[i].  
   // Capacity is s + c, where c is the "spare capacity" argument.
   // Requires: Priorities and Elements are of size at least s. 
   Heap( const int * Priorities, const int * Elements, int s, int c); 

   // New Heap with combined contents the two Heap arguments. 
   // Size of the new Heap is the sum of the sizes of argument Heaps.
   // Capacity of the new Heap is its size plus the "spare capacity" c.
   Heap( const Heap & Heap1, const Heap & Heap2, int c ); 

   // Destructor.
   ~Heap(); 

   // Accessors
   bool empty() const {return hSize == 0;}; // True iff Heap is empty.
   int size() const { return hSize ;} ; // Current size of Heap.
   int capacity() const { return hCapacity ;} ; // Current capacity.
   int peekMin() const { return A[0].element ;} // Peek at minimum priority element.
   												//minimum priority element is the first element
   int peekMinPriority() const { return A[0].priority ;} // Peek at minimum priority.

   // Modifiers
   void insert( int element, int priority ); // Insert the pair <element,priority>.
   int extractMin(); // Remove and return the highest (minimum) priority element.

   					//remove root cause root has the lowest priority.

private:
   class Pair{
      public:
        int element ;
        int priority ;
   };

   Pair* A ; // Array containing heap contents.
   int hCapacity ; // Max number of elements (= size of A).
   int hSize ; // Current number of elements.

   // Repairs ordering invariant after adding leaf at A[i].
   void trickleUp(int i);

   // Repairs ordering invariant for sub-tree rooted at index i,
   //   when A[i] may be have larger priority than one of its children,
   //   but the subtrees of its children are heaps.
   void trickleDown(int i);

   // Establishes ordering invariant for entire array contents.
   void heapify(); //(Same as "make_heap" in lectures.)

   // Useful for implementing trickle up and down
   void swap(int i,int j);


//my changes
 //public:
//void print();
private:
	//extra functions
   int leftchild(int i);
   int rightchild(int i);
   int parent(int i);

   bool isLeft(int i);
   bool isRight(int i);
   
};

/*
void Heap::print(){
	for (int i=0; i<hSize; i++)
	{
		cout<<A[i].element<<" "<<A[i].priority<<endl;}
	cout<<endl;}
*/

Heap::Heap(){
   hCapacity = 10 ; //max number of elements 
   A = new Pair[hCapacity]; //it's an array A of size capacity which contains pairs as their elements 
   hSize = 0 ; //curent number of elements 
}

Heap::Heap(int c){ // New empty Heap with capacity c.
   // Complete this.
	hCapacity=c;
	A=new Pair[hCapacity]; //an array of pairs of size capacity on Heap
	hSize=0; //curent number of elements
}

// New Heap with capacity c+s, with s elements, consisting of pairs <Pi,Vi> where 
//  Pi is Priorities[i], Ei is value Elements[i], for 0 <= i < s.
Heap::Heap( const int * Priorities, const int * Elements, int s, int c){ 
   // Complete this.
	hCapacity=c+s;
	A=new Pair[hCapacity]; //aray A of Pair elements of hCapacity
	hSize=s;
	for (int i=0; i<hSize; i++){ //s is the number of elements
		A[i].priority=Priorities[i];
		A[i].element=Elements[i];}
	heapify();

}


// New Heap with combined contents and of the two given heaps.
Heap::Heap( const Heap & Heap1, const Heap & Heap2, int c ){ 
   hCapacity = Heap1.hSize + Heap2.hSize + c ;
   // Complete this.
   hSize=Heap1.hSize+Heap2.hSize;
   //cout<<"size of heap 3 is "<<hSize<<endl;
   A = new Pair[hCapacity];
   //we have two heaps and we want to merge them into one heap
   for (int i=0; i<Heap1.hSize; i++){
   		//cout<<" element of Heap 1 is "<< Heap1.A[i].element<<endl;
   		A[i].priority=Heap1.A[i].priority;
   		A[i].element=Heap1.A[i].element;}

   	int k=0;
   	for (int j=Heap1.hSize; j<hSize; j++){
   		//cout<<"element of Heap 2 is "<<Heap2.A[k].element<<endl; 
   		A[j].priority=Heap2.A[k].priority;
   		A[j].element=Heap2.A[k].element;
   		if (k<Heap2.hSize)
   			{k++;}
   		  }

   	heapify();

}

// Destructor
Heap::~Heap(){
   delete[] A; //we delete array A
}

// Modifiers
void Heap::insert(int element, int priority){
   A[hSize].element = element; //we insert element
   A[hSize].priority = priority; //we insert priority
   trickleUp(hSize); //does all the swapping to make sure that we have a right order 
   hSize ++; //then we increment size
}


bool Heap::isLeft(int i){
	return (i*2+1)<size(); //check this part
}

bool Heap::isRight(int i){
	return (i*2+2)<size(); //check this part
}

//return is index of left child
int Heap::leftchild(int i){
	if (isLeft(i)){
		return (i*2+1);} //i=0 then A[1]; i=1 then A[3].
	}
	

//return is index of right child
int Heap::rightchild(int i){
	
	if (isRight(i))
	{
	return (i*2+2);}//position of a left child
}


int Heap::parent(int i){
	return ((i-1)/2);
}

// Repairs the heap ordering invariant after adding a new element.
// Initial call should be trickleUp(hSize-1).
void Heap::trickleUp(int i){
   // Complete this.
	//cout<<"element we have is "<<A[i].element<<endl;
	if (A[i].priority<A[parent(i)].priority)
	{swap(i, parent(i));
	trickleUp(parent(i));}


	//commented non-recursive definition
	/*
	if (A[i].priority>A[parent(i)].priority){
		//cout<<"I am here "<<endl;
		return;	}

	while (i!=0){ //while we did not reach root

		if (A[i].priority>=A[parent(i)].priority)
		{break;}	

		//WE COMPARE THEN SWAP
		if (A[i].priority<A[parent(i)].priority)
		{swap(i,parent(i));}
		i=parent(i);} //current index i becomes index at parent 
		*/
}

void Heap::swap(int i, int j){
   Pair temp = A[i];
   A[i] = A[j];
   A[j] = temp ;
}

//Below functions are for root removal and for heap-order restoration
// Removes and returns the element with highest priority.
// (That is, the element associated with the minimum priority value.)
int Heap::extractMin(){
   // Complete this.
   	//we replace root with the last node

	int store_root=A[0].element;
	A[0].element=A[hSize-1].element; //root becomes last element
	A[0].priority=A[hSize-1].priority;
	hSize=hSize-1; //we decrement size, and therefore, we ignore the last node

	//cout<<"hSize is "<<hSize<<endl;
	//now we must make sure that we have a correct order
	trickleDown(0); //trickle down root
	//we should extract min element extract root
	//delete root return element at root
	return store_root; //returne remove root element 
}

// Repairs the heap ordering invariant after replacing the root.
// (extractMin() calls trickleDown(0)).
// (trickleDown(i) performs the repair on the subtree rooted a A[i].)
// (heapify() calls trickleDown(i) for i from (hSize/2)-1 down to 0.)
//error should be here
void Heap::trickleDown(int i){ //i is the root and we 'repair' that subtree
   // Complete this.
	//we go from top to bottom
	//size is one; only root then return 
if (isLeft(i)==false && isRight(i)==false)
	{return;}

if (isRight(i)==false && A[i].priority>A[leftchild(i)].priority){
	swap(i, leftchild(i));
	return;}

if (isRight(i)==false && A[i].priority<A[leftchild(i)].priority)
	{return;}

if(A[leftchild(i)].priority<=A[rightchild(i)].priority && isRight(i)==true){
	if (A[i].priority>A[leftchild(i)].priority){
		swap(i, leftchild(i));
		//cout<<"I am here"<<endl;
		trickleDown(leftchild(i));}
	else{
		return;}
}

if(A[leftchild(i)].priority>=A[rightchild(i)].priority && isRight(i)==true){
	if (A[i].priority>A[rightchild(i)].priority){
		swap(i, rightchild(i));
		trickleDown(rightchild(i));}
	else{
		return;}
}


//Commented non-recursive definition
/*
		//if there is no left child then there is nothing to swap with
	while(isLeft(i)) 
	{
			if (isRight(i)==false && A[i].priority>A[leftchild(i)].priority){ //no right child (only root and left child)
				swap(i, leftchild(i));
				return;
			}
				

			if (isRight(i)==false && A[i].priority<A[leftchild(i)].priority){
				return; //no need to swap
			}


		if (A[rightchild(i)].priority>=A[leftchild(i)].priority && isRight(i)){

			if (A[i].priority>A[leftchild(i)].priority){
				swap(i, leftchild(i));
				i=leftchild(i);}
			else
				return;}


		if (A[rightchild(i)].priority<A[leftchild(i)].priority && isRight(i)){
					if (A[i].priority>A[rightchild(i)].priority){
						swap(i, rightchild(i));
						i=rightchild(i);}
						else
							return;}
		}

	return;

	*/
}



// Turns A[0] .. A[size-1] into a heap.
void Heap::heapify(){
	//cout<<"we are inside heapify"<<endl;
   for( int i = (hSize/2)-1; i>=0 ; i-- ) //for i=1 till i= 
   	{ 	  
   	trickleDown(i);}
}

//Complete the implementations of all incompletely implemented functions.
