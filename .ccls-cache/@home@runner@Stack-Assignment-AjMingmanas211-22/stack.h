#ifndef stack_h
#define  stack_h
#include "node.h"
#include <iomanip>
#include <iostream>
using namespace std;

/* In stack we have three main operations
    - connect
    - change top
    - change size
*/

class Stack{
private:
	 NodePtr top;
	int size;
public:
    Stack(NodePtr = NULL);
    ~Stack();
    int pop();
    void push(int); 
    void print();
    void pPrint();
    bool isEmpty();
    int get_size();
};
int Stack::get_size(){
  return size;
}
Stack::Stack(NodePtr t){
  if(t) {
    top=t;
    size=1;
  }
 else{
   top=NULL;
	 size=0;
   }
}
void Stack::push(int x){
   NodePtr newnode=new NODE(x);
  //1
  if (newnode) {
    newnode->set_next(top); //connect to previous top
    top = newnode; //3
    ++size; //4
}
 else cout<<"No memory left for new nodes"<<endl;
		 // Left missing for exercises…
}
int Stack::pop(){
 	   NodePtr t=top;
		int value;		
	 if(t)	{
    
     value=t->get_value();
     top=t->get_next();
	// Left missing for exercises
     delete t;
     --size;
      return value;
     }
    
		cout<<"Empty stack"<<endl;
   return 0;
	}
Stack::~Stack(){
   cout<<"Clearing all stacks"<<endl;
  	int i;
  NodePtr t=top;
/*for(i=0;i<size;i++){
  top=top->get_next();
  delete t;
  t =top;
  }*/
while(size>0) pop();
  // Left missing for exercises Done
}

void Stack::print() {
  NodePtr t = top;
  while (t != nullptr) {
    int value = t->get_value();
    cout <<"layer: "<< value << endl;
    t = t->get_next();
  }
  cout<<"-----------\n";
}

void Stack::pPrint() {
  NodePtr t = top;
  while (t != nullptr) {
    char value = t->get_value();
    cout << value << endl;
    t = t->get_next();
  }
  cout<<"-----------\n";
}

bool Stack::isEmpty(){
  NodePtr t = top;
  if(t) return false;
  else return true;
}


#endif