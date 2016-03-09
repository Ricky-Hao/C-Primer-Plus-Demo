#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node
{
	char word[30];
	struct node *left;
	struct node *right;
	int occur;
};

struct tree
{
	struct node *root;
	int size;
};

void seek(struct node *node, struct node *temp, struct tree *tree);
char menu();
void print_tree(struct node *node);
void find_tree(struct node *node);
struct node * seek2(struct node *node, char word[]);

int main(int argc, char *argv[])
{
	struct tree tree;
	struct node *node;
	struct node *temp;
	char ch;

	tree.root = NULL;
	tree.size = 0;

	char fname[40];
	FILE *fp;

	if ((fp = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Could not open %s.\n", argv[1]);
		exit(1);
	}


	while (feof(fp) == 0)
	{
		temp = (struct node *)malloc(sizeof(struct node));

		if (temp == NULL)
		{
			fprintf(stderr, "Could not malloc node.\n");
			exit(2);
		}

		int t = 0;
		for (t = 0, ch = getc(fp); isalpha(ch) && ch != '\0'; t++)
		{
			temp->word[t] = ch;
			ch = getc(fp);
		}
		temp->word[t] = '\0';
		if (temp->word[0] == '\0')
			continue;
		temp->left = NULL;
		temp->right = NULL;
		temp->occur = 1;

		if (tree.root == NULL)
		{
			tree.root = temp;
			tree.size++;
		}
		else
		{
			seek(tree.root, temp, &tree);
		}
	}

	if (tree.root == NULL)
		puts("No data.\n");
	else
	{
		while (1)
		{
			switch (menu())
			{
			case 'a':print_tree(tree.root); break;
			case 'b':find_tree(tree.root); break;
			case 'q':exit(0);
			}
		}
	}
	fclose(fp);
	return 0;
}

void seek(struct node *node, struct node *temp, struct tree *tree)
{
	if (strcmp(node->word, temp->word)>0 && node->left != NULL)
		seek(node->left, temp, tree);
	else if (strcmp(node->word, temp->word)<0 && node->right != NULL)
		seek(node->right, temp, tree);
	else if (strcmp(node->word, temp->word)>0 && node->left == NULL)
	{
		node->left = temp;
		tree->size++;
	}
	else if (strcmp(node->word, temp->word)<0 && node->right == NULL)
	{
		node->right = temp;
		tree->size++;
	}
	else
	{
		node->occur++;
	}
}

char menu()
{
	char ch = 0;
	puts("Please choose a choice:");
	puts("a) list all the words	");
	puts("b) enter a word and report it's occur");
	puts("q) quit");

	ch = getchar();
	while (getchar() != '\n')
		continue;
	while (strchr("abq", ch) == NULL)
	{
		puts("Wrong enter!");
		puts("Please enter a correct choice:");
		ch = getchar();
		while (getchar() != '\n')
			continue;
	}
	return ch;
}

void print_tree(struct node *node)
{
	if (node->left != NULL)
		print_tree(node->left);
	printf("%-30s %d\n", node->word, node->occur);
	if (node->right != NULL)
		print_tree(node->right);
}

void find_tree(struct node *node)
{
	puts("Please enter a word:");
	char word[40];
	scanf("%s", word);

	while (getchar() != '\n')
		continue;

	struct node *temp;
	temp = seek2(node, word);
	if (temp == NULL)
		printf("The word is not in the article.\n");
	else
		printf("%-30s %d\n", temp->word, temp->occur);

}

struct node * seek2(struct node *node, char word[])
{
	if (strcmp(node->word, word)>0 && node->left != NULL)
		seek2(node->left, word);
	else if (strcmp(node->word, word)<0 && node->right != NULL)
		seek2(node->right, word);
	else if (strcmp(node->word, word)>0 && node->left == NULL)
	{
		return NULL;
	}
	else if (strcmp(node->word, word)<0 && node->right == NULL)
	{
		return NULL;
	}
	else
	{
		return node;
	}
}