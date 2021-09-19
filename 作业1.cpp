#include <iostream>
#include <string.h> 
#include <stdlib.h>
//�Ȱ���Ŀ�����йؼ���Ū���� 
using namespace std;

struct KeyWord
{
	char keyword[32];
	int  count;
};

KeyWord KeyWordTable[] =
{
	{"auto",0},{"break",0},{"case",0},{"char",0},{"const",0},{"continue",0},{"default",0},{"do",0},{"double",0},{"else",0},{"enum",0},{"extern",0},
	{"float", 0}, {"for", 0},{"foto",0},{"if", 0},{"int", 0},{"long",0},{"register",0},{"return",0},{"short",0},{"signed",0},{"sizeof",0},{"static",0},
	{"struct",0},{"switch",0},{"typedef",0},{"union",0},{"unsigned",0},{"void",0},{"volatile",0},{"while", 0}
};

// ���ڹؼ�������˳�������㷨 
int SeqSearch(KeyWord *tab, int n, char *word) 
{
	int i;
	for(i = 0;i < n;i++,tab++)
	{
		if(strcmp(tab->keyword,word)==0)
			return i;
	}
	return -1;
}
// ��ȡ����ĸ��������ĸ/���ֿ�ͷ�ĵ���
int GetWord (ifstream& fin, char w[])
{
	char c;
	int  i = 0;

	// ��������ĸ���� 
	while ( fin.get(c) && !isalpha(c))
		;

	// ���ļ�ĩβ����0 
	if (fin.eof())
		return 0;

	// ��¼���ʵĵ�һ����ĸ 
	w[i++] = c;

	// �ռ���ĸ�����֣���null��β 
	while (fin.get(c) && (isalpha(c) || isdigit(c)))
		w[i++] = c;
	w[i] = '\0';

	return  1;              // ����1�ͳɹ� 
}
