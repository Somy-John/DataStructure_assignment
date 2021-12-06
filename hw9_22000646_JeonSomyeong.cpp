#include <iostream>

using namespace std;

class node
{ //도서정보를 담는 클레스
public:
   string s_title;
   int npages;
   int price;
   node *link;
   void set_data(string name, int pages, int price)
   {
      this->s_title = name;
      this->npages = pages;
      this->price = price;
   }
};

class my_queue
{
   node *front, *rear;
public:
   my_queue();
   void insert_q(node t);
   node delete_q();
   bool q_empty();
};

my_queue::my_queue()
{
   front=NULL;
   rear=NULL;
}
void my_queue::insert_q(node t)
{
   node *n;
   n = new node;
   (*n) = t;
   if(!rear){
      front = n;
      rear = n;
      n->link=NULL; //처음 만드는 놈이면 링크는 널값으로
   }
   else{
      n->link = front; //서큘러 큐이므로 마지막 노드의 링크는 프런트를 가리킴
      rear->link = n;
      rear = n;
   }
}
   
node my_queue::delete_q()
{
   node temp;
   node *tmp;
   tmp = front;
   temp = *front;
   if(tmp->link==front){
      front = NULL;
      rear =NULL;
   }
   else{
      front = front->link;
      rear->link = front->link; // 맨 마지막 노드가 가리키고 있던 노드가 지워졌으므로 링크 변경해줌
   }
   delete tmp;
   return temp;
}

bool my_queue::q_empty()
{
   if (!front) return true;
   else return false;
}
int main()
{
   my_queue a;
   node tmp;

   tmp.set_data("C++ Programming", 534, 35000);
   a.insert_q(tmp);
   tmp.set_data("Data Structure", 621, 42000);
   a.insert_q(tmp);
   tmp.set_data("JAVA Programming", 485, 38000);
   a.insert_q(tmp);
   tmp.set_data("Logic Design", 532, 44000);
   a.insert_q(tmp);
   tmp.set_data("OSSL", 1, -1);
   a.insert_q(tmp);
   while (!a.q_empty())
   {
      tmp = a.delete_q();
      cout << tmp.s_title << " : " << tmp.npages << " : " << tmp.price << "\n";
   }
   return 0;
}