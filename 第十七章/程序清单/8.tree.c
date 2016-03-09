//tree.c -- 树类型的支持函数
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "8.tree.h"

//局部树数据类型


//局部函数的原型
static Node *MakeNode(const Item *pi);
static bool ToLeft(const Item *i1, const Item *i2);
static bool ToRight(const Item *i1, const Item *i2);
static void AddNode(Node *new_node, Node *root);
static void InOrder(const Node *root, void(*pfun)(Item item));
static void DeleteNode(Node **ptr);
static void DeleteAllNodes(Node *ptr);
static void InOrderItem(const Item *item, void(*pfun)(Item item));

//函数定义
void InitializeTree(Tree *ptree)
{
	ptree->root = NULL;
	ptree->size = 0;
};

bool TreeIsEmpty(const Tree *ptree)
{
	if (ptree->root == NULL)
		return true;
	else
		return false;
};

bool TreeIsFull(const Tree *ptree)
{
	if (ptree->size == MAXITEMS)
		return true;
	else
		return false;
};

int TreeItemCount(const Tree *ptree)
{
	return ptree->size;
}

bool AddItem(const Item *pi, Tree *ptree)
{
	Node *new_node;
	Item *item;
	Node *temp;

	if (TreeIsFull(ptree))
	{
		fprintf(stderr, "Tree is full.\n");
		return false;
	}
	if (SeekItem(pi, ptree).child != NULL)
	{
		temp = SeekItem(pi, ptree).child;
		item = temp->item;
		while (item->next != NULL)
			item = item->next;
		item->next = pi;
		ptree->size++;
		return true;
	}
	new_node = MakeNode(pi);
	if (new_node == NULL)
	{
		fprintf(stderr, "Couldn't create node\n");
		return false;
	}

	ptree->size++;

	if (ptree->root == NULL)
		ptree->root = new_node;
	else
		AddNode(new_node, ptree->root);
	return true;
}

bool InTree(const Item *pi, const Tree *ptree)
{
	return (SeekItem(pi, ptree).child == NULL) ? false : true;
}

bool DeleteItem(const Item *pi, Tree *ptree)
{
	Item *temp_1;
	Node *temp;
	Item *item;
	Pair look;

	look = SeekItem(pi, ptree);
	item = look.child->item;
	temp_1 = item;

	while (strcmp(pi->petkind, item->petkind) != 0 && item->next != NULL)
	{
		temp_1 = item;
		item = item->next;
	}

	if (strcmp(pi->petkind, item->petkind) == 0)
	{
		if (item->next != NULL&&item == look.child->item)
		{
			look.child->item = item->next;
			free(item);
			ptree->size--;
			return true;
		}
		else if (item->next != NULL)
		{
			temp_1->next = item->next;
			free(item);
			ptree->size--;
			return true;
		}
		else if (item == look.child->item)
		{
			if (look.parent == NULL)
			{
				for (temp = look.child->left; temp->right != NULL; temp = temp->right)
					continue;
				temp->right = look.child->right;
				ptree->root = look.child->left;
				free(look.child);
				ptree->size--;
				return true;
			}
			else if (look.child->left != NULL&&look.child->right == NULL)
			{
				if (look.parent->left == look.child)
					look.parent->left = look.child->left;
				else
					look.parent->right = look.child->left;
				free(look.child);
				ptree->size--;
				return true;
			}
			else if (look.child->left == NULL&&look.child->right != NULL)
			{
				if (look.parent->left == look.child)
					look.parent->left = look.child->right;
				else
					look.parent->right = look.child->right;
				free(look.child);
				ptree->size--;
				return true;
			}
			else if (look.child->left != NULL&&look.child->right != NULL)
			{
				for (temp = look.child->left; temp->right != NULL; temp = temp->right)
					continue;
				temp->right = look.child->right;
				if (look.parent->left == look.child)
					look.parent->left = look.child->left;
				else
					look.parent->right = look.child->left;
				free(look.child);
				ptree->size--;
				return true;
			}
			else
			{
				free(look.child);
				ptree->size--;
				return true;
			}
		}
	}
	else
		return false;
}
void Traverse(const Tree *ptree, void(*pfun)(Item item))
{
	if (ptree != NULL)
		InOrder(ptree->root, pfun);
}

void DeleteAll(Tree *ptree)
{
	if (ptree != NULL)
		DeleteAllNodes(ptree->root);
	ptree->root = NULL;
	ptree->size = 0;
}

//局部函数
static void InOrder(const Node *root, void(*pfun)(Item item))
{
	if (root != NULL)
	{
		InOrder(root->left, pfun);
		InOrderItem(root->item, pfun);
		InOrder(root->right, pfun);
	}
}

static void InOrderItem(const Item *item, void(*pfun)(Item item))
{
	while (item->next != NULL)
	{
		(*pfun)(*item);
		item = item->next;
	}
	(*pfun)(*item);
}

static void DeleteAllNodes(Node *root)
{
	Node *pright;
	Item *item;
	Item *temp;

	if (root != NULL)
	{
		pright = root->right;
		DeleteAllNodes(root->left);
		item = root->item;
		while (item->next != NULL)
		{
			temp = item->next;
			free(item);
			item = temp;
		}
		free(item);
		free(root);
		DeleteAllNodes(pright);
	}
}

static void AddNode(Node *new_node, Node *root)
{
	if (ToLeft(new_node->item, root->item))
	{
		if (root->left == NULL)
			root->left = new_node;
		else
			AddNode(new_node, root->left);
	}
	else if (ToRight(new_node->item, root->item))
	{
		if (root->right == NULL)
			root->right = new_node;
		else
			AddNode(new_node, root->right);
	}
	else
	{
		fprintf(stderr, "location error in AddNode()\n");
		exit(1);
	}
}

static bool ToLeft(const Item *i1, const Item *i2)
{
	int comp1;

	if ((comp1 = strcmp(i1->petname, i2->petname))<0)
		return true;
	else
		return false;
}

static bool ToRight(const Item *i1, const Item *i2)
{
	int comp1;

	if ((comp1 = strcmp(i1->petname, i2->petname))>0)
		return true;
	else
		return false;
}

static Node *MakeNode(const Item *pi)
{
	Node *new_node;

	new_node = (Node *)malloc(sizeof(Node));
	if (new_node != NULL)
	{
		new_node->item = pi;
		new_node->left = NULL;
		new_node->right = NULL;
	}
	return new_node;
}

Pair SeekItem(const Item *pi, const Tree *ptree)
{
	Pair look;
	look.parent = NULL;
	look.child = ptree->root;

	if (look.child == NULL)
		return look;
	while (look.child != NULL)
	{
		if (ToLeft(pi, look.child->item))
		{
			look.parent = look.child;
			look.child = look.child->left;
		}
		else if (ToRight(pi, look.child->item))
		{
			look.parent = look.child;
			look.child = look.child->right;
		}
		else
			break;
	}
	return look;
}

static void DeleteNode(Node **ptr)
{
	Node *temp;
	Item *item_temp;
	Item *item;
	if ((*ptr)->left == NULL)
	{
		item = (*ptr)->item;
		while (item->next != NULL)
		{
			item_temp = item;
			item = item->next;
			free(item_temp);
		}
		free(item);
		temp = *ptr;
		*ptr = (*ptr)->right;
		free(temp);
	}
	else if ((*ptr)->right == NULL)
	{
		item = (*ptr)->item;
		while (item->next != NULL)
		{
			item_temp = item;
			item = item->next;
			free(item_temp);
		}
		free(item);
		temp = *ptr;
		*ptr = (*ptr)->left;
		free(temp);
	}
	else
	{
		for (temp = (*ptr)->left; temp->right != NULL; temp = temp->right)
			continue;
		item = (*ptr)->item;
		while (item->next != NULL)
		{
			item_temp = item;
			item = item->next;
			free(item_temp);
		}
		free(item);
		temp->right = (*ptr)->right;
		temp = *ptr;
		*ptr = (*ptr)->left;
		free(temp);
	}
}
