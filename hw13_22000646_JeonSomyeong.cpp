#include <iostream>

using namespace std;

class bst_node
{
public:
   string name;
   string p_num; //전화번호 (xxx-xxxx-xxxx)
   double b_day; //생일    (xx.xx)
   bst_node *left, *right;
   void set_data(string n, string pnum, double bday);
};
void bst_node::set_data(string n, string pnum, double bday)
{
   name = n;
   p_num = pnum;
   b_day = bday;
}
class bst_tree
{
   bst_node *root;
   int csize;

public:
   bst_tree();
   void insert_node(bst_node t);
   void show_inorder();
   bst_node search(string tid);
   bool isEmpty();
   void delete_node(bst_node d_node);
};

bst_tree::bst_tree()
{
   csize = 6;
   root = NULL;
}
void bst_tree::insert_node(bst_node t)
{

   bst_node *p;
   bst_node *tmp;
   tmp = new bst_node;
   *tmp = t;
   tmp->left = NULL;
   tmp->right = NULL;
   if (root == NULL)
   {
      root = tmp;
      return;
   }
   p = root;
   while (1)
   {
      if (p->name == t.name)
      {
         cout << "Insertion Failed : the Key " << t.b_day << " already exists." << endl;
         return;
      }
      if (p->b_day < t.b_day)
      {
         if (p->right == NULL)
         {
            p->right = tmp;
            return;
         }
         else
            p = p->right;
      }
      else
      {
         if (p->left == NULL)
         {
            p->left = tmp;
            return;
         }
         else
            p = p->left;
      }
   }
}

void inorder_print(bst_node *p)
{

   if (p == NULL)
      return;
   inorder_print(p->left);
   cout << p->name << " : " << p->b_day << " : " << p->p_num << "\n";
   inorder_print(p->right);
}
void bst_tree::show_inorder() //left -> root -> right
{
   inorder_print(root);
}
bst_node bst_tree::search(string sname)
{
   bst_node *p;
   p = root;
   if (root == NULL)
   {
      bst_node tmp;
      tmp.set_data("None", "000-0000-0000", -1);
      cout << "그런 이름 없음\n";
      return tmp;
   }
   while (1)
   {
      if (p->name == sname)
         return (*p);
      if (p->name < sname)
      {
         if (p->right == NULL)
         {
         }
         else
            p = p->right;
      }
      else
      {
         if (p->left == NULL)
         {
         }
         else
            p = p->left;
      }
   }
}
bool bst_tree::isEmpty()
{
   if (root == NULL)
      return true;
   else
      return false;
}
int selectMenu()
{
   int menu;
   cout << "1. 새로운 원소 추가\n";
   cout << "2. 원소 조회\n";
   cout << "3. 전체 목록 보기\n";
   cout << "0. 종료\n\n";
   cout << "명령 선택 : ";
   cin >> menu;
   return menu;
}
void creat(bst_tree *t1)
{
   bst_node temp;
   string name, p_num;
   double b_day;
   cout << "이름은?\n>> ";
   cin >> name;
   cout << "전화번호는? (xxx-xxxx-xxxx)\n>> ";
   cin >> p_num;
   cout << "생일은? (MM.DD)\n>> ";
   cin >> b_day;
   temp.set_data(name, p_num, b_day);
   t1->insert_node(temp);
}
void chatja(bst_tree t1){
   bst_node snode;
   string sname;
   cout << "검색할 이름은?\n>> ";
   cin >> sname;
   snode = t1.search(sname);
   cout << snode.name << " : " << snode.b_day << " : " << snode.p_num << "\n";
}

void delete_node(bst_node d_node){
   
}

int main()
{
   bst_tree t1;
   int menu;
   while (1)
   {
      menu = selectMenu();
      if (menu == 0)
         break;
      if (menu == 2 || menu == 3)
         if (t1.isEmpty())
            continue;
      if (menu == 1) creat(&t1);
      else if (menu == 2) chatja(t1);
      else if (menu == 3) t1.show_inorder();
   }
   return 0;
}