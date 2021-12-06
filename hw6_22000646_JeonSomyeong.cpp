#include <iostream>

// Palindrome check

using namespace std;

class mystack{
   private:
      int top, MaxSize;
      char *stack;
   public:
      void creat_stack(int size);
      void init();
      bool stack_empty();
      void push(char str);
      char pop();
      char getTop();
}; 

void mystack::creat_stack(int size){
  stack = new char[size];
}

void mystack::init(){
   top = -1;  
}

bool mystack::stack_empty(){
   if(top==-1) return true;
   else return false;
}

void mystack::push(char str){
   stack[++top] = str;
}

char mystack::pop(){
  if(stack_empty()) cout << "Empty!\n";
  else return stack[top--];
  return 0;
}

char mystack::getTop(){
   return stack[top];
}

mystack pushFront(string input,int count){
   mystack frontStack;
   frontStack.creat_stack(input.size());
   frontStack.init();
   for(int i=0;i<count;i++) frontStack.push(input[i]);
   return frontStack;
}

string pushBack(string input,int count){
   string modifiedBack;
   for(int i=input.size()-count;i<input.size();i++) modifiedBack.append(1,input[i]);
   return modifiedBack;
}

string check(mystack frontStack, string modifiedBack, int count){
   for(int i=0;i<count;i++){
      if(modifiedBack[i] == frontStack.getTop()) frontStack.pop();
   }
   if(frontStack.stack_empty()) return "Yes, it's a palindrome!!\n";
   else return "No, it's not a Palindrome!!\n";
}

int main(){
   int i,x;
   string input;
   cout<<"검사할 문자열을 입력하시오 : "; 
   cin>>input;
   cout<<check(pushFront(input,input.size()/2),pushBack(input,input.size()/2),input.size()/2);
   return 0;
}