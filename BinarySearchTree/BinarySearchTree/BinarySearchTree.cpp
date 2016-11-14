#include "stdafx.h"
#include <iostream>

using namespace std;

struct node
{
	int value;
	struct node* left;
	struct node* right;
};


class Camparable
{
public:
	Camparable();
	Camparable(int val);
	virtual ~Camparable();
	int get_value();
	void set_value(int new_value);
	int copare_to(const Camparable& rhs);
private:
	int value;
};

Camparable::Camparable()
{
	value = 1;
}

Camparable::Camparable(int val):value(val)
{

}

Camparable::~Camparable()
{

}

int Camparable::get_value()
{
	return value;
}

void Camparable::set_value(int new_value)
{
	value = new_value;
}

int Camparable::copare_to(const Camparable&  rhs)
{
	if (value > rhs.value)
	{
		return 1;
	}

	else if (value == rhs.value)
	{
		return 0;
	}

	else if (value < rhs.value)
	{
		return -1;
	}
}


template <typename T>
class Binary_Search_Tree : public Camparable
{
public:
	Binary_Search_Tree();
	virtual ~Binary_Search_Tree();
	void insert_integer(T value);
	void print_tree();
	bool check_value(int value);


	
private:
	node* my_root;
	void get_null(struct node* tree);
	void insert_integer_help(struct node** tree, T value);
	void print_tree_help(struct node* tree);
	bool check_value_help (struct node* tree, int value);
	void terminate_tree_help(struct  node* tree);
};

template <typename T>
Binary_Search_Tree<T>::Binary_Search_Tree():Camparable()
{
	my_root = NULL;
}

template <typename T>
Binary_Search_Tree<T>::~Binary_Search_Tree()
{
	terminate_tree_help(my_root);

	my_root = NULL;
}

template <typename T>
void Binary_Search_Tree<T>::get_null(struct node* tree)
{
	tree->left = NULL;
	tree->right = NULL;
}

template <typename T>
void Binary_Search_Tree<T>::terminate_tree_help(struct  node* tree)
{
	if (tree->left != NULL)
	{
		terminate_tree_help(tree->left);
	}

	if (tree->right != NULL)
	{
		terminate_tree_help(tree->right);
	}



	delete tree;
	tree = NULL;
}

template <typename T>
void Binary_Search_Tree<T>::insert_integer(T value)
{
	insert_integer_help(&my_root, value);
}

template <typename T>
void Binary_Search_Tree<T>::insert_integer_help(struct node** tree, T value)
{
	if (*tree == NULL)
	{
		node* tmp = new node;
		tmp->value = value;
		(*tree) = tmp;

		get_null(*tree);

	}

	else if (value < (*tree)->value)
	{
		if ((*tree)->left == NULL)
		{
			node* tmp = new node;
			tmp->value = value;
			(*tree)->left = tmp;
			get_null((*tree)->left);

		}
		else
		{
			insert_integer_help(&(*tree)->left, value);
		}
	}

	else if (value > (*tree)->value)
	{
		if ((*tree)->right == NULL)
		{
			node* tmp = new node;
			tmp->value = value;
			(*tree)->right = tmp;
			get_null((*tree)->right);
		}
		else
		{
			insert_integer_help(&(*tree)->right, value);
		}
	}
}

template <typename T>
void Binary_Search_Tree<T>::print_tree()
{
	print_tree_help(my_root);
}

template <typename T>
void Binary_Search_Tree<T>::print_tree_help(struct node* tree)
{

	if (tree->left != NULL)
	{
		print_tree_help(tree->left);
	}

	cout << tree->value << '\n';


	if (tree->right != NULL)
	{
		print_tree_help(tree->right);
	}
}

//TODO : bug01
template <typename T>
bool Binary_Search_Tree<T>::check_value(int value)
{
	bool b = check_value_help(my_root, value);
	return b;

}

template <typename T>
bool Binary_Search_Tree<T>::check_value_help(struct node* tree, int value)
{
	if (value == tree->value)
	{
		return true;
	}

	if (value < tree->value)
	{
		if (tree->left != NULL)
		{
			check_value_help(tree->left, value);
		}

		else if (tree->left == NULL)
		{
			return false;
		}
	}

	if (value > tree->value)
	{
		if (tree->right != NULL)
		{
			check_value_help(tree->right, value);
		}

		else if (tree->right == NULL)
		{
			return false;
		}
	}
}


//struct node* root = NULL;
//
//
//void insert_integer(struct node** tree, int value);
//void print_tree(struct node* tree);
//void terminate_tree(struct  node* tree);
//
//void terminate_tree_help(struct node*tree);
//void get_null(struct node* tree);


int main()
{
	//insert_integer(&root, 10);
	//insert_integer(&root, 8);
	//insert_integer(&root, 7);

	//print_tree(root);

	//terminate_tree(root);

	//insert_integer(&root, 10);
	//print_tree(root);


	Binary_Search_Tree<int> b1;
	b1.insert_integer(10);
	b1.insert_integer(11);
	b1.insert_integer(40);
	b1.insert_integer(70);
	b1.insert_integer(3);
	b1.insert_integer(9);
	b1.insert_integer(80);;
	b1.print_tree();

	bool a = b1.check_value(77);


	cout << a << endl;

	a = b1.check_value(10);


	cout << a << endl;

	Camparable co1(-8);

	cout << "we get " << co1.copare_to(b1) << " value" << endl;


	int exit;

	cin >> exit;


    return 0;
}


