/*
**  a4.cpp
**  Assignment 4, CMPT-225
**
**  Reads a sequence of integers (in the range of int's) from standard in;
**  It is interpreted as two lists, separated by a single 0
**/
#include <iostream>
#include "a2_h.h"


using namespace std;

int main(){
	

    HeapPriorityQueue<int, int> P1;
    HeapPriorityQueue<int, int> P2;

     int x;
     bool List2 = false; 
     //cout << "list 1:" << endl;

     cin >> x ;
     //P1.insert(x);


     while( !cin.eof() ){

        if (List2==false && x!=0)
        {
            P1.insert(x);
        }
        
        if (List2==true && x!=0)
        {
            P2.insert(x);
        }



        if( x == 0 ){
            List2 = true ;
            //cout << "\nlist 2:\n" ;

            //P2.insert(x);
        }else{
            //cout << x << " " ;
        }
        cin >> x ;

     }
     //cout << endl;

     cout<<"301269789 "<<"pbychkov "<<"Polina Bychkova"<<endl;
     
if (P1.size()==0)
     {
        cout<<"None"<<endl;
     }

else{

        while(P1.size()!=0)
         {

        
        if (P2.size()==0 && P1.size()!=0)
        {
            cout<<P1.max()<<endl;
            break;
        }

            //case 1
          if (P1.max()>P2.max())
          {
            cout<<P1.max()<<endl;
            //cout<<"we are here"<<endl;
            break;
          }



          if (P1.max()==P2.max())
             {
                //cout<<"we are in equal"<<endl;
                P1.removeMax(); //i only remove element in list 1
             }


          if (P1.max()<P2.max())
             {
                P2.removeMax(); //I remove max elem of P2
             }
    
          //if p1 is empty then we print nothing 
        if (P1.size()==0)
        {
            //cout<<"We are inside this"<<endl;
            cout<<"None"<<endl;
            break;}

      
        }

}

    
     return 0;
 }