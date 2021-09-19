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
