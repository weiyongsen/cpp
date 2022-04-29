#include "bits/stdc++.h"
using namespace std;

string signal_char = "+-*/:;,()[]{}";
string signal_comparison = "<>=!";

vector<string> key{"const","int","char","void",
"main","if","else","switch","case",
"default","while","for",
"scanf","printf","return"}; // 关键字列表

map<string,string> table = {
    {"标识符",	"IDENFR"},	
    {"else",	"ELSETK"},	
    {"-",	"MINU"},	
    {"=",	"ASSIGN"},
    {"整形常量",	"INTCON"},	
    {"switch",	"SWITCHTK"},	
    {"*",	"MULT"},	
    {";",	"SEMICN"},
    {"字符常量",	"CHARCON"},	
    {"case",	"CASETK"},	
    {"/",	"DIV"},	
    {",",	"COMMA"},
    {"字符串",	"STRCON"},	
    {"default",	"DEFAULTTK"},	
    {"<",	"LSS"},	
    {"(",	"LPARENT"},
    {"const",	"CONSTTK"},		
    {"while",	"WHILETK"},	
    {"<=",	"LEQ"},	
    {")",	"RPARENT"},
    {"int",	"INTTK"},	
    {"for",	"FORTK"},	
    {">",	"GRE"},	
    {"[",	"LBRACK"},
    {"char",	"CHARTK"},	
    {"scanf",	"SCANFTK"},	
    {">=",	"GEQ"},	
    {"]",	"RBRACK"},
    {"void",	"VOIDTK"},	
    {"printf",	"PRINTFTK"},	
    {"==",	"EQL"},	
    {"{",	"LBRACE"},
    {"main",	"MAINTK"},	
    {"return",	"RETURNTK"},	
    {"!=",	"NEQ"},	
    {"}",	"RBRACE"},
    {"if",	"IFTK"},	
    {"+",	"PLUS"},	
    {":",	"COLON"},
    {"!",   "非"},
};