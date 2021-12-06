#include <iostream>

using namespace std;

class mystack{
   private:
      int top, MaxSize, *stack;
   public:
      void creat_stack(int size);
      void init();
      bool stack_empty();
      void push(int num);
      int pop();
}; 

void mystack::creat_stack(int size){
  stack = new int[size];
}

void mystack::init(){
   top = -1;  
}

bool mystack::stack_empty(){
   if(top==-1) return 1;
   else return 0;
}

void mystack::push(int num){
   stack[++top] = num;
}

int mystack::pop(){
  if(stack_empty()) cout << "Empty!\n";
  else return stack[top--];
  return 0;
}


int main(){
   mystack  s1;
   
   int list[5] = { 32, 123, 27, 131, 242 }, i, x;

   s1.creat_stack(5);
   s1.init();

   for (i = 0; i < 5; i++ )
      if (list[i]> 100) s1.push( list[i] );
   while ( ! s1.stack_empty( )){
      x = s1.pop( );
      cout << x << endl ; 
   }
   return 0;
}