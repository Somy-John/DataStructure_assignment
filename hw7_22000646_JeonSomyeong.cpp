#include <iostream>
#define Q_SIZE 100

using namespace std;

class element
{ //도서정보를 담는 클레스
public:
   string s_title;
   int npages;
   int price;
   void set_data(string name, int pages, int price);
};
void element::set_data(string name, int pages, int price){
  this->s_title = name;
  this->npages = pages;
  this->price = price;
}
class my_queue
{
   element q[Q_SIZE];
   int front, rear;

public:
   my_queue();
   void insert_q(element input);
   element delete_q(); //delete 사용은 유의 bool queue_full();
   bool empty();
   bool queue_full();
};

my_queue::my_queue()
{
   front = 0;
   rear = 0;
}
void my_queue::insert_q(element input)
{
   if (!queue_full())
   {
      q[rear] = input;
      rear = (rear + 1) % Q_SIZE;
   }
   // else part 구현 가능
}
bool my_queue::queue_full()
{
   if ((rear + 1) % Q_SIZE == front)
      return true;
   else
      return false;
}
bool my_queue::empty()
{
   if (rear == front)
      return true;
   else
      return false;
}
element my_queue::delete_q()
{
   element tmp;
   if (!empty())
   {
      tmp = q[front];
      front = (front + 1) % Q_SIZE;
      return (tmp);
   }
   else return tmp;
}

int main()
{
   my_queue a;
   element tmp;

   tmp.set_data("C++ Programming", 534, 35000);
   a.insert_q(tmp);
   tmp.set_data("Data Structure", 621, 42000);
   a.insert_q(tmp);
   tmp.set_data("JAVA Programming", 485, 38000);
   a.insert_q(tmp);
   tmp.set_data("Logic Design", 532, 44000);
   a.insert_q(tmp);
   while (!a.empty())
   {
      tmp = a.delete_q();
      cout << tmp.s_title << " : " << tmp.npages << " : " << tmp.price << "\n";
   }
   return 0;
}