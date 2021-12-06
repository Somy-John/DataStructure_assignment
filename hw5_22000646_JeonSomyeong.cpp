#include <iostream>

// Parenthesis check

/*
1. 괄호가 더 많을 때
2. 괄호가 더 적을 때
3. 괄호 짝이 안맞을 때 (개수는 같으나 종류가 다름)

1. 여는 괄호 ( { [ 를 스택에 넣는다.
2. 하나씩 빼면서 닫는 괄호랑 비교한다.
*/

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

mystack pushOpen(string input){
   mystack openstack;
   openstack.creat_stack(input.size());
   openstack.init();
   string openP = "[{(";
   char tmp;
   for(int i=0;i<input.size();i++){
      tmp = input[i];
      if(openP.find(tmp)!=-1){
         openstack.push(tmp);
      }
   }
   return openstack;
}

string pushClose(string input){
   string modifiedClose;
   string closeP = ")}]";
   char tmp;
   for(int i=0;i<input.size();i++){
      tmp = input[i];
      if(closeP.find(tmp)!=-1){
         if(tmp==')') tmp='(';
         else if(tmp=='}') tmp='{';
         else if(tmp==']') tmp='[';
         modifiedClose.append(1,tmp);
      }
   }
   return modifiedClose;
}

string check(mystack openStack,string modifiedClose){
   string rst;
   char tmp;
   int i,j,pin=0;
   for(i=0;i<modifiedClose.size();i++){
      tmp = modifiedClose[i];
      if(openStack.stack_empty()){
         rst = "Error:  An extra parenthesis, \'";
         for(j=i;j<modifiedClose.size();j++){
            tmp = modifiedClose[j];
            if(tmp=='(') rst+=")";
            else if(tmp=='{') rst+="}";
            else if(tmp=='[') rst+="]";
         }
         rst+="\' is found.\n";
         break;
      }
      else if(openStack.getTop()==modifiedClose[i]) openStack.pop();
      else if(openStack.getTop()!=modifiedClose[i]){
         tmp = openStack.getTop();
         rst = "Error: mis-matched parethesis,";
         if(tmp=='(') rst+="\')\'";
         else if(tmp=='{') rst+="\'}\'";
         else if(tmp=='[') rst+="\']\'";
         rst+=" is expected.\n";
         pin=1;
         break;
      }
   }
   if(!openStack.stack_empty()&&i!=modifiedClose.size()&&pin==0){
      rst = "Error:  An extra parenthesis, \'";
      while(!openStack.stack_empty()){
         rst.append(1,openStack.pop());
         rst.append(1,' ');
      }
      rst += "\' is found.\n";
   }
   else if(!openStack.stack_empty()&&pin==0) rst = "It's a normal expression\n";
   return rst;
}

int main(){
   int i,x;
   string input, rst;
   cout<<"검사할 수식을 입력하시오 : "; 
   cin>>input;
   rst = check(pushOpen(input),pushClose(input));
   cout<<rst;
   return 0;
}