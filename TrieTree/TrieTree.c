#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 26

typedef struct TrieTree
{
	int isStr;
	struct TrieTree * next[N];
}Trie;

int a[] = {};

static int Search(char * str, Trie * root);

static int Insert(char * str, Trie * root);

static int Delete(char * str, Trie * root);

static int Fuzzys(char * str, Trie * root);

static int Visit(char * str, Trie * root, int count);

int main()
{
	Trie * root = (Trie *)malloc(sizeof(Trie));
	for (int i = 0; i < N; i++)
	{
		root->next[i] = NULL;
	}
	printf("%4d",Insert("liu",root));
	printf("%4d",Insert("liu",root));
	printf("%4d",Insert("liuruiyang",root));
	printf("%4d\n",Insert("liurui",root));
	printf("%4d",Search("liu",root));
	printf("%4d",Search("liuru",root));
	printf("%4d",Search("liuruiyang",root));
	printf("%4d\n",Search("liuruiya",root));
	// printf("%4d",Delete("liuruiyang",root));
	// printf("%4d",Delete("liuruiyang",root));
	// printf("%4d",Delete("liuruiy",root));
	// printf("%4d\n",Delete("liu",root));
	Fuzzys("liu",root);
	return 0;
}

int Insert(char * str, Trie * root)
{
	int len = strlen(str);
	Trie * temp = root;
	for (int i = 0; i < len; i++)
	{
		int index = str[i]-'a';
		if (temp->next[index] == NULL)
		{
			temp->next[index] = (Trie *)malloc(sizeof(Trie));
			temp = temp->next[index];
			temp->isStr = 0;
			for (int j = 0; j < N; j++)
			{
				temp->next[j] = NULL;
			}
		}
		else
		{
			temp = temp->next[index];
		}
	}
	if (temp->isStr == 1)
		return 0;
	temp->isStr = 1;
	return 1;
}

int Search(char * str, Trie * root)
{
	int len = strlen(str);
	Trie * temp = root;
	for (int i = 0; i < len; i++)
	{
		int index = str[i]-'a';
		if (temp->next[index])
			temp = temp->next[index];
		else
			return 0;
	}
	return temp->isStr;
}

int Delete(char * str, Trie * root)
{
	int len = strlen(str);
	Trie * temp = root;
	for (int i = 0; i < len; i++)
	{
		int index = str[i]-'a';
		if (temp->next[index])
			temp = temp->next[index];
		else
			return 0;
	}
	if (temp->isStr == 0)	return 0;
	temp->isStr = 0;
	return 1;
}

int Fuzzys(char * str, Trie * root)
{
	int len = strlen(str);
	Trie * temp = root;
	for (int i = 0; i < len; i++)
	{
		int index = str[i]-'a';
		if (temp->next[index])
			temp = temp->next[index];
		else
			return 0;
	}
	Trie * newr = temp;
	int count = 0;
	Visit(str,newr,count);
	return 0;
}

int Visit(char * str, Trie * root, int count)
{
	if (root->isStr == 1)
	{
		printf("%s",str);
		for (int i = 0; i < count; i++)
			printf("%c",a[i]+'a');
		printf("\n");
	}
	for (int i = 0; i < N; i++)
	{
		if (root->next[i] != NULL)
		{
			a[count] = i;
			Visit(str,root->next[i],count+1);
		}
	}
	return 0;
}
