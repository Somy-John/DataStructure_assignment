#include <iostream>

using namespace std;

class bst_node
{
public:
	string name;
	string s_id;
	double score;
	bst_node *left, *right;
	void set_data(string id, string n, double s);
};
void bst_node::set_data(string id, string n, double s)
{
	s_id = id;
	name = n;
	score = s;
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
	void delete_node(string tid);
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
		if (p->s_id == t.s_id)
		{
			cout << "Insertion Failed : the Key " << t.s_id << " already exists." << endl;
			return;
		}
		if (p->s_id < t.s_id)
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
	cout << p->s_id << " : " << p->name << " : " << p->score << "\n";
	inorder_print(p->right);
}
void bst_tree::show_inorder() //left -> root -> right
{
	inorder_print(root);
}
bst_node bst_tree::search(string tid)
{
	bst_node *p;
	p = root;
	if (root == NULL)
	{
		bst_node tmp;
		tmp.set_data("00000000", "None", -1);
		cout << "The key " << tid << " does not exist.\n";
		return tmp;
	}
	while (1)
	{
		if (p->s_id == tid)
			return (*p);
		if (p->s_id < tid)
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
void bst_tree::delete_node(string tid)
{
	bst_node *p, *parent;
	int which = 0; // 1이 왼쪽 2가 오른쪽
	p = root;
	if (root == NULL)
	{
		cout << "The key " << tid << " does not exist.\n";
		return;
	}
	if(root->s_id == tid){
		root = NULL;
		return;
	}
	while (1)
	{
		if (p->s_id == tid)
			if (p->left == NULL && p->right == NULL)
			{
				if (which==1){
					parent->left = NULL;
					return;
				}
				else{
					parent->right = NULL;
					return;
				}
			}
			else if(p->left==NULL || p->right == NULL){
				if (which==1){
					parent->left = p;
					return;
				}
				else{
					parent->right = NULL;
					return;
				}
			}
		if (p->s_id < tid)
		{
			if (p->right == NULL)
			{
			}
			else
			{
				which = 2;
				parent = p;
				p = p->right;
			}
		}
		else
		{
			if (p->left == NULL)
			{
			}
			else
			{
				which = 1;
				parent = p;
				p = p->left;
			}
		}
	}
}

int main()
{
	bst_node temp;
	bst_tree t1;
	temp.set_data("21900013", "Kim", 6.5);
	t1.insert_node(temp);
	temp.set_data("21900136", "Lee", 8.8);
	t1.insert_node(temp);
	temp.set_data("21900333", "Park", 9.2);
	t1.insert_node(temp);
	temp.set_data("21800442", "Choi", 7.1);
	t1.insert_node(temp);
	temp.set_data("21900375", "Ryu", 5.4);
	t1.insert_node(temp);
	temp.set_data("21700248", "Cho", 6.3);
	t1.insert_node(temp);

	cout << "\n\n Node List : inorder sequence \n";
	t1.show_inorder();
	t1.delete_node("21800442");
	t1.show_inorder();

	string s_key = "21800442";
	temp = t1.search(s_key);

	cout << "\n -- " << s_key << "'s record ---" << endl;
	cout << " Student ID   : " << temp.s_id << endl;
	cout << " Student Name : " << temp.name << endl;
	cout << " Score        : " << temp.score << endl;

	return 0;
}