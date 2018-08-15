//The code is taken from 
//Data Structures and Algorithms in C++, 2nd Edition
//Michael T. Goodrich, Roberto Tamassia, David M. Mount
//I implemented this code to lear data structures
//I added my own comments and main program

#include <cstdlib>
#include <iostream>
using namespace std;

typedef string Elem;
class DNode{
    
    Elem elem;
    DNode* next;
    DNode* prev;
    friend class DLinkedList;
   };
   
class DLinkedList{
    public:
    
    DLinkedList(); //constructor
    ~DLinkedList();//destructor
    bool empty() const; //check if list is empty
    const Elem& front() const; //element followed head
    const Elem& back() const; //element at trailer
    
    void addFront(const Elem& e); //add after head
    void addBack(const Elem& e);  //add before trail
    void removeFront();  //add after head
    void removeBack(); //remove before trail
    void printlist();
    
    private:
        DNode* header;
        DNode* trailer;
    protected: //local utilities
        void add(DNode* v, const Elem& e); //insert new node before node v
        void remove(DNode* v); //remove node v
    };
    
    
    DLinkedList::DLinkedList(){
        header=new DNode;  //we created a whole box called header
        trailer=new DNode; //we created a whole box called trailer
        header->next=trailer;
        trailer->prev=header;

    }
    
    DLinkedList::~DLinkedList(){
        while(!empty()) removeFront(); //we now delete elements inside the list
        delete header; //delete header box
        delete trailer; //delete trailer box
    }
    
    bool DLinkedList::empty() const{ //the list is empty of head->next=trailer;
        return (header->next==trailer);}
        
    const Elem& DLinkedList::front() const{
        return header->next->elem;}
    
    const Elem& DLinkedList::back() const{
        return trailer->prev->elem;}
        
        
    //insert a new node before node v
    void DLinkedList::add(DNode* v, const Elem& e){
        DNode* u=new DNode; //we created a new node
        u->elem=e;  //we put element inside a ned node

        //we now want to put new node before given node v
        //we need to unlink next and pointers and then link them together
        u->next=v->next; //link u in between v
        u->prev=v; //we now inserted the node
        v->next = u;
        u->next->prev = u;   //we now say that v->prev->next
                                 //points to a new node
        }
        
    
    void DLinkedList::addFront(const Elem& e){
        add(header,e);

       // cout<<"New element is inserted into the list before head" <<endl;


        } //we insert a new node before a node header->next
                             // to the front of the list
        
    void DLinkedList::addBack(const Elem& e){
        add(trailer->prev,e);} //we insert a new node before node called trailer
        
    
    //we want to remove node v
    void DLinkedList::remove(DNode* v){
        //before we delete we want to unlink pointers fron the node \
        //and then we delete it 

        DNode* u=v->prev;
        DNode* w=v->next; 

        u->next=w;
        w->prev=u;   //unlink pointers from v
        
        delete v;    
    }
    
    
    void DLinkedList::removeFront(){

        remove(header->next);}
        
    void DLinkedList::removeBack(){
        remove(trailer->prev);}

    void DLinkedList::printlist(){
        DNode* a = header;

        while(a != trailer){
            cout << a->elem << " ";
            a = a->next;
        }
        cout << endl;
    }


int main(){

    DLinkedList list;

    string q="smth";

    list.addFront("this");

    list.addFront("is");

    list.addFront("a");

    list.addFront("cat");

    list.printlist();

    list.addBack("This");
    list.addBack("is");
    list.addBack("the");
    list.addBack("addback");
    list.removeBack();
    list.removeBack();
    list.removeFront();
    list.removeFront();
    list.printlist();

    // list.removeBack(); 

    // cout << "-------------" <<endl;

    //REMOVE FRONT DOES NOT WORK!
 //   list.removeFront();


/*
    while(!q.empty())  
    {
        getline(cin,q);
        list.addFront(q); //add to the back of the list
        list.addBack(q);

    }
    

  */      
        

        



    return 0;
}
