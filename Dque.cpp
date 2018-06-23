#include <cstdlib>
#include <iostream>
using namespace std;

typedef int Elem;
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
        u->next=v; //link u in between v
        u->prev=v->prev; //we now inserted the node
        v->prev->next=v->prev=u;    //we now say that v->prev->next
                                  //points to a new node
        }
        
    
    void DLinkedList::addFront(const Elem& e){
        add(header->next,e);
        //cout<<"New element is inserted into the list before head" <<endl;


        } //we insert a new node before a node header->next
                             // to the front of the list
        
    void DLinkedList::addBack(const Elem& e){
        add(trailer,e);} //we insert a new node before node called trailer
        
    
    //we want to remove node v
    void DLinkedList::remove(DNode* v){
        //before we delete we want to unlink pointers fron the node \
        //and then we delete it 
        DNode* u=v->prev;
        DNode* w=v->next;        
        u->next=w;
        w->prev=u;   //unlink pointers from v
        delete v;  }


    
    void DLinkedList::removeFront(){
        remove(header->next);}
        
    void DLinkedList::removeBack(){
        remove(trailer->prev);}



//we now define Deque
    class LinkedDeque{
    public:
        LinkedDeque();
        int size() const;

        bool empty() const;

        //we have to the front and back elements in a d-que
        const Elem& front() const;
        const Elem& back() const;


        //we can insert element to the front and backj
        void insertFront(const Elem& e);
        void insertBack(const Elem& e);

       void removeFront();
       void removeBack();

    private:
        DLinkedList D;
        int n; 
    };


    LinkedDeque::LinkedDeque()
    : n(0), D(){}
        //we avoid destructor and we rely on a destructor of D
    int LinkedDeque::size() const
    {
        return n;}

    bool LinkedDeque::empty() const{
        return n==0;}

    void LinkedDeque::insertFront(const Elem& e){
        D.addFront(e);
        n++;}

    void LinkedDeque::insertBack(const Elem& e){
        D.addBack(e);
        n++;}





    void LinkedDeque::removeFront(){
        D.removeFront();
        n--;}






    void LinkedDeque::removeBack(){
        D.removeBack();
        n--;}

    const Elem& LinkedDeque::front() const
    {
        return D.front();}

    const Elem& LinkedDeque::back() const
    {
        return D.back();}



int main(){


LinkedDeque d;


DLinkedList list;


list.addFront(4);
list.addFront(5);
list.addFront(6);


list.removeBack();

//remove FRONT DOES NOT WORK
//list.removeFront();






d.insertFront(2);

d.insertFront(3);

d.insertFront(4);

d.insertFront(5);

d.removeBack();

cout<<d.back()<<endl;

//d.removeFront();
//d.removeFront();

//cout<<d.front()<<endl;







    return 0;
}