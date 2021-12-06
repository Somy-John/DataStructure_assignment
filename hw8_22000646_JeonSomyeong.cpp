#include <iostream>
using namespace std;

class node
{
public:
   string name;
   double score;
   node *link;
   void set_data(string s, double n)
   {
      name = s;
      score = n;
   }
};

class my_list
{
   node *head, *tail;

public:
   my_list();
   void add_to_head(node t);
   void add_to_tail(node t);
   node delete_from_head();
   int num_nodes();
   bool list_empty();
   double score_sum();
   double get_score(string t_name);
   int remove_a_node(string t_name);
};
my_list::my_list()
{
   head = NULL;
   tail = NULL;
}
void my_list::add_to_head(node t)
{
   node *p;
   p = new node;
   (*p) = t;
   p->link = head;
   head = p;
   if (tail == NULL)
      tail = p; //테일이 널값이었으면 처음만드는것이므로 p를 가리키게 한다.
}
void my_list::add_to_tail(node t)
{
   node *p;
   p = new node;
   (*p) = t;
   p->link = NULL;
   if (tail != NULL)
      tail->link = p;
   else 
      head = p; //테일이 널값이었으면 처음만드는것이므로 head도 p를 가리키게 한다.
   tail = p;
}
node my_list::delete_from_head()
{
   node temp;
   node *t;
   t = head;
   temp = *head;
   head = head->link;
   delete t;
   if (head == NULL)
      tail = NULL;
   return temp;
}
int my_list::num_nodes()
{
   node *t;
   int count = 0;
   for (t = head; t != NULL; t = t->link)
      count++;
   return count;
}
bool my_list::list_empty()
{
   if (head == NULL)
      return true;
   else return false;
}
double my_list::score_sum()
{  
   node *ptr = head;
   double sum = 0.0;
   for(;;){
      sum += ptr->score;
      if(ptr->link == NULL) break;
      ptr = ptr->link;
   }
   return sum;
}
double my_list::get_score(string t_name)
{
   node *ptr = head;
   for(;;){
      if(t_name==ptr->name){
         return ptr->score;
      }
      if(ptr->link == NULL) break;
      ptr = ptr->link;
   }
   return 0.0;
}
int my_list::remove_a_node(string t_name)
{
   node *target=head, *prev=NULL;
   while(target!=NULL&&target->name!=t_name){
      prev = target;
      target = target->link;
   } // 찾거나 못찾고 끝나면 탈출
   if(target == NULL) return 0; // 못찾고 끝났었으면 0 리턴
   if(prev) prev -> link = target -> link;
   // 이전node가 NULL이 아니었으면(target이 첫 노드가아니었으면) 발동
   else head = target->link;
   // 타겟이 첫노드였으면, 해드를 타겟이 링크해둔 녀석으로 옮김
   if(head == NULL) tail = NULL;
   // 달랑 하나 남았던걸 지웠다면, 테일 = 널
   if(target == tail) tail = prev;
   // 끝노드를 삭제했다면 이전 노드를 테일로!
   delete target;
   return 1;
}

int main()
{
   my_list a;
   node tmp;
   tmp.set_data("Kim", 83.5);
   a.add_to_head(tmp);
   tmp.set_data("Lee", 78.2);
   a.add_to_head(tmp);                                      // head 위치로 2개의 원소 추가
   cout << a.num_nodes() << " : " << a.score_sum() << "\n"; // 1단계 점검
   tmp.set_data("Park", 91.3);
   a.add_to_tail(tmp);                                      // tail 위치로 1개의 원소 추가
   cout << a.num_nodes() << " : " << a.score_sum() << "\n"; //2단계 점검
   tmp = a.delete_from_head();
   cout << tmp.name << " is deleted.\n"; // 3단계 점검
   tmp.set_data("Choi", 85.1);
   a.add_to_tail(tmp);
   tmp.set_data("Ryu", 94.3);
   a.add_to_head(tmp); // 2개의 원소 추가
   cout << a.num_nodes() << " : " << a.score_sum() << "\n";
   cout << "Park’s score : " << a.get_score("Park") << "\n"; // 4단계 점검
   if (a.remove_a_node("Kim") == 1)
      cout << "Kim is deleted from the list. \n";           // 5단계 점검
   cout << a.num_nodes() << " : " << a.score_sum() << "\n"; // 최종 점검
   return 0;
}