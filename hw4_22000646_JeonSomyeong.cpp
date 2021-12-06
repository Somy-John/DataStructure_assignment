#include <iostream>

//infix to postfix

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
   if(top==-1) return 1;
   else return 0;
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

string infixToPostfix(string infix){
   string postfix,Operator="*/%+-",P2="*/%",P1="+-";
   postfix.resize(infix.size()+1);
   mystack s;
   char tmp;
   int i;
   s.creat_stack(infix.size()+1);
   s.init();
   s.push('$');
   for(i=0;i<infix.size();i++){
      tmp = infix[i];
      if(tmp=='(') s.push(tmp);
      else if(tmp==')'){
         for(;;){
            if(s.getTop()=='(') break;
            else{
               postfix.append(1,s.pop());
            }
         }
        s.pop();
      }
      else if(Operator.find(tmp)!=-1){
         while(1){
            if(P2.find(tmp)!=-1){
               if(P2.find(s.getTop())!=-1) postfix.append(1,s.pop());
               else break;
            }
            else if(P1.find(s.getTop()!=-1)){
               if(P2.find(s.getTop())!=-1) postfix.append(1,s.pop());
               else if(P1.find(s.getTop())!=-1) postfix.append(1,s.pop());
               else break;
            }
            else break;
         }
         s.push(tmp);
      }
      else if(Operator.find(tmp)==-1) postfix.append(1,tmp);
   }
   while(1){
     if(s.getTop()=='$') break;
     postfix.append(1,s.pop());
   }
   return postfix;
}

int main(){
   int i,x;
   string infix,postfix;
   cout<<"수식을 입력하시오 : "; 
   cin>>infix;
   postfix = infixToPostfix(infix);
   cout<<"infix : "<<infix<<"\n";
   cout<<"postfix : "<<postfix;
   return 0;
}