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
int main(int argc, char *argv[])
{

	if(argc < 2)
	{
		cerr<<"Input parameter error"<<endl;
		exit (1);
	}
	int op = atoi(argv[2]);
	const int MAXWORD = 50;             
    // r任何单词的最大大小 
	// 声明table大小并且初始化其值 
	const int NKEYWORDS = sizeof(KeyWordTable)/sizeof(KeyWord);
	int totalNum = 0;
	int switchNum = 0;
	int caseNum1 = 0;
	int caseNum2 = 0;
	int nif_elseNum = 0;
	int nif_elseifNum =0;
	int nCnt = 0;
	int nCnt1 =0;
	int flag = 0;
	bool bflag = false;
	int n;
	char word[MAXWORD];
	ifstream fin;    
	fin.open(argv[1],ios::in );
	if (!fin)
	{
		cerr << "Could not open file 'key.cpp'" << endl;
		exit (1);
	}

	// 提取单词直到文件结束 
	while (GetWord(fin, word))
	{
		// 如果关键字表中有匹配项，则递增计数 
		if ((n = SeqSearch(KeyWordTable,NKEYWORDS,word)) != -1)
		{
			if(strcmp(word,"switch") == 0)
			{
				flag ++;
			}
			if(flag == 1)
			{
				if(strcmp(word,"case") == 0)
					caseNum1++;
			}

			else
			{
				if(strcmp(word,"case") == 0)
					caseNum2++;
			}

			if(strcmp(word,"if") == 0)
			{
				nCnt ++;

			}
			if(nCnt == 2)
			{
				if(strcmp(word,"if") == 0)
				{
					bflag = true;
				}
			}else
			{
				if(bflag == true)
				{
					if(strcmp(word,"else") == 0)
					{
						nCnt1 ++;
					}
				}
			}
			if(nCnt1 ==2)
			{
				if(strcmp(word,"else") == 0)
				{
					nCnt1 = 0;
					nCnt = 0;
					nif_elseNum ++;
					nif_elseifNum++;
				}
			}
			//cout<<"word:"<<word<<endl;
			KeyWordTable[n].count++;
			totalNum ++;
		}
	}
		// 扫描关键字表并打印记录字段 
	for (n = 0; n < NKEYWORDS; n++)
	{
		if (KeyWordTable[n].count > 0)
		{

			//cout << KeyWordTable[n].count;
			//cout << "  " << KeyWordTable[n].keyword << endl;

			if(strcmp(KeyWordTable[n].keyword,"switch") == 0)
			{
				switchNum = KeyWordTable[n].count;
			}

		}
	}
