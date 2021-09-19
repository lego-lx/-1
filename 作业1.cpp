#include <iostream>
#include <string.h> 
#include <stdlib.h>
//先把题目中所有关键字弄进来 
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

// 基于关键字数组顺序搜索算法 
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
// 提取以字母和其他字母/数字开头的单词
int GetWord (ifstream& fin, char w[])
{
	char c;
	int  i = 0;

	// 跳过非字母输入 
	while ( fin.get(c) && !isalpha(c))
		;

	// 在文件末尾返回0 
	if (fin.eof())
		return 0;

	// 记录单词的第一个字母 
	w[i++] = c;

	// 收集字母与数字，以null结尾 
	while (fin.get(c) && (isalpha(c) || isdigit(c)))
		w[i++] = c;
	w[i] = '\0';

	return  1;              // 返回1就成功 
}
