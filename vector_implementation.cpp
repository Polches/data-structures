
//The code is taken from 
//Data Structures and Algorithms in C++, 2nd Edition
//Michael T. Goodrich, Roberto Tamassia, David M. Mount
//I implemented this code to learn data structures
//I added my own comments and main program




#include <iostream>
using namespace std;



//we can implement a vector using an array


//main functions
//at(i) return element at index i
//set(i,e) replace an element at index i with element e
//insert(i,e) insert a new element at insex i
//erase(i) remove from V an element at index i

//we can implement a vector using a fixed size array 
//we choose the size N to be large enougth 


//int at(int A[],int i)
//{
//	return A[i];
//}




//implementation of a vector, based on an array
typedef int Elem;

class ArrayVector{

public:

	//"standart housekeeping functions"
	//These consist of a copy constructor, an
	//assignment operator, and a destructor.
	ArrayVector(); //constructor

	int size() const; //number of elements

	bool empty();

	Elem& operator[](int i); //we also defined an operator [] to give us an index at i

	//gives element at index i it's safe
	Elem& at(int i); //i should include throw here


	void erase(int i); //remove element at index i

	void reserve(int N);

	void insert(int i, const Elem& e); //insert element at index i




private:
	int capacity; //current array size
	int n; //actual number of elements in a vector
	Elem* A; //pointer to an array storing elements
};


//"note that we do not make any storage allocation in a constructor"
ArrayVector::ArrayVector()
: A(NULL), capacity(0), n(0){}

int ArrayVector::size() const{
	return n; //number of elements inside a vector
}


bool ArrayVector::empty()
{return size()==n;}


//return element at index i
Elem& ArrayVector::operator[](int i)
{
	return A[i]; //returns an element at given index
}


Elem& ArrayVector::at(int i){ //element at given index 
							

		return A[i];
}


void ArrayVector::erase(int i){ //we shift elements to left on one position

	if (n==0){
		cout<<"No elements inside a vector"<<endl;
		return;}
	if (i>=n)
	{
		cout<<"you are beyond scope"<<endl;
		return;
	}
	
	int j=i+1; //j=1
	for ( j; j<n; j++) //from j=1 to j=2
		{A[j-1]=A[j];}   //a[0]=a[1] a[1]=a[2]
	n--;//we reduce the size of that array
}

//now we want to reserve some space
//N is a number of spots we want to reserve
void ArrayVector::reserve(int N){
	if (capacity>=N) //if we have enougth space then it's good
		return; 

	Elem* B=new Elem[N]; //B is a pointer to an array of N elements

	//we now have to copy the context
	for(int i=0; i<n;i++){
		B[i]=A[i];}

	if (A!=NULL) 
		delete []A; //we now deleted old array we have a new array

 	capacity=N;
 	A=B; //A now pints to B
	}


void ArrayVector::insert(int i, const Elem& e){
	if (n>=capacity){//if number of elements is equal to capacity we add more space


		if (capacity==0) //what we have by default at the begining 
			{reserve(1);}
		else
			{reserve(2*capacity);}
	}

		//we shift elements first and then we insert
	for (int j=n-1; j>=i; j--) 
		A[j+1]=A[j]; //move to the right

	A[i]=e; 
	n++;}




int main(){



	ArrayVector k;
	k.insert(0,6); 

	k.insert(0,5); //we have a vector (5,6)
	k.insert(0,4);


cout<<"Before I do erase operation"<<endl;
for (int i=0; i<k.size(); i++)
	cout<<k.at(i)<<" ";

	k.erase(2); //


cout<<"After I do erase operation"<<endl;


for (int i=0; i<k.size(); i++)
	cout<<k.at(i)<<endl;


	return 0;
}















