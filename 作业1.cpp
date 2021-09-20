#include <iostream>
#include <fstream>
#include <string.h>     // must include if string functions used
#include <ctype.h>      // provides isalpha and isdigit
#include <stdlib.h>
using namespace std;
#include<windows.h>
#include<winbase.h>
#define MaxSize 50
// declare the word structure
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

// the sequential search algorithm on the array of keywords
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

// extract a word beginning with a letter and possibly
// other letters/digits
int GetWord (ifstream& fin, char w[])
{
	char c;
	int  i = 0;

	// skip non-alphabetic input
	while ( fin.get(c) && !isalpha(c))
		;

	// return 0 (Failure) on end of file
	if (fin.eof())
		return 0;

	// record 1st letter of the word    
	w[i++] = c;

	// collect letters and digits and NULL terminate string
	while (fin.get(c) && (isalpha(c) || isdigit(c)))
		w[i++] = c;
	w[i] = '\0';

	return  1;              // return 1 (Success)
}


int main(int argc, char *argv[])
{

	if(argc < 2)
	{
		cerr<<"Input parameter error"<<endl;
		exit (1);
	}
	int op = atoi(argv[2]);
	// declare the table size and initialize its value
	
	const int NKEYWORDS = sizeof(KeyWordTable)/sizeof(KeyWord);
	int totalNum = 0;
	int switchNum = 0;
	int nif_elseNum = 0;
	int nif_elseifNum =0;
	int nCnt = 0;
	int nCnt1 =0;
	bool bflag = false;
	int n;
	char word[MaxSize];
	ifstream fin;
	bool bSwitch = false;
	char pCase[256]={0};
	// open file with error checking    
	DWORD m =::GetTickCount(); //获取毫秒级数目
	fin.open(argv[1],ios::in );
	if (!fin)
	{
		cerr << "Could not open file 'key.cpp'" << endl;
		exit (1);
	}
	int nCount = 0;
	int nCaseNum = 0;
	 
	// extract words until end of file
	while (GetWord(fin, word))
	{
		// if a match in keyword table, increment count
		if ((n = SeqSearch(KeyWordTable,NKEYWORDS,word)) != -1)
		{
			if(strcmp(word,"switch") == 0)
			{
				switchNum ++;
				nCount ++;
				bSwitch = true;
				
			}
			if(bSwitch == true)
			{
				if(strcmp(word,"case") == 0)
					nCaseNum++;
			}
			if(strcmp(word,"default") == 0)
			{
				char p[256]={0};
				sprintf(p,"%d",nCaseNum);
				strcat(p," ");
				strcat(pCase,p);

				nCaseNum = 0;
				bSwitch = false;
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
	
    switch (op)
	{
	case 1:
		cout << "total num:"<<totalNum<<endl;
		break;
	case 2:
		cout << "total num:"<<totalNum<<endl;
		cout << "switch num:"<<switchNum<<endl;
		cout << "case num:"<<pCase<<endl;
		break;
	case 3:
		cout << "total num:"<<totalNum<<endl;
		cout << "switch num:"<<switchNum<<endl;
		cout << "case num:"<<pCase<<endl;
		cout<<"if-else:"<<nif_elseNum<<endl;
		break;
	case 4:
		cout << "total num:"<<totalNum<<endl;
		cout << "switch num:"<<switchNum<<endl;
		cout << "case num:"<<pCase<<endl;
		cout<<"if-else:"<<nif_elseNum<<endl;
		cout<<"if -elseif-else num:"<<nif_elseifNum<<endl;
		break;
	default:
		break;
	}
	DWORD e=::GetTickCount(); //获取毫秒级数目 　　
	int se = e-m; // se为毫秒 　　
	cout<<"总耗耗时："<<se<<"毫秒"<<endl;
	fin.close();


	return 0;
}
