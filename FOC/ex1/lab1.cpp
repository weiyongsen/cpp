#include <bits/stdc++.h>

using namespace std;

vector<string> name;
vector<string> syms;

void printAns(){
	for (int i = 0; i < name.size(); i++){
		cout << syms[i] << " " << name[i] << endl;
	}// for
}// printAns

bool isDigit(char c){
	return c >= '0' && c <= '9';
}// isdigit

bool isInAlphabet(char c){
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z' || c == '_'); 
}// isInAlphabet


int main(){
	
	string inputs = "";
	char c;
	
	// get the input symbols
	while (c = getchar()){
		if (c == '?')
			break;
		inputs += c;
	}// while
	
	int index = 0;
	int size = inputs.size();
	
	while (index < size){

		// 特殊字符 
		switch (inputs[index]){
			case '-':
				syms.push_back("MINU");
				name.push_back("-");
				break;
			case '*':
				syms.push_back("MULT");
				name.push_back("*");
				break;
			case '/':
				syms.push_back("DIV");
				name.push_back("/");
				break;
			case '+':
				syms.push_back("PLUS");
				name.push_back("+");
				break;
			case ';':
				syms.push_back("SEMICN");
				name.push_back(";");
				break;
			case ',':
				syms.push_back("COMMA");
				name.push_back(",");
				break;
			case '(':
				syms.push_back("LPARENT");
				name.push_back("(");
				break;
			case ')':
				syms.push_back("RPARENT");
				name.push_back(")");
				break;
			case '[':
				syms.push_back("LBRACK");
				name.push_back("[");
				break;
			case ']':
				syms.push_back("RBRACK");
				name.push_back("]");
				break;
			case '{':
				syms.push_back("LBRACE");
				name.push_back("{");
				break;
			case '}':
				syms.push_back("RBRACE");
				name.push_back("}");
				break;
			case ':':
				syms.push_back("COLON");
				name.push_back(":");
				break;
		}
		
		// = and ==
		if (inputs[index] == '='){
			if (inputs[index] == size || inputs[index + 1] != '='){
				syms.push_back("ASSIGN");
				name.push_back("=");
			}
			else if (inputs[index + 1] == '='){
				index += 2;
				syms.push_back("EQL");
				name.push_back("==");
				continue;
			}
		}
		
		// < and <=
		if (inputs[index] == '<'){
			if (inputs[index] == size || inputs[index + 1] != '='){
				syms.push_back("LSS");
				name.push_back("<");
			}
			else if (inputs[index + 1] == '='){
				index += 2;
				syms.push_back("LEQ");
				name.push_back("<=");
				continue;
			}
		}
		
		// > and >=
		if (inputs[index] == '>'){
			if (inputs[index] == size || inputs[index + 1] != '='){
				syms.push_back("GRE");
				name.push_back(">");
			}
			else if (inputs[index + 1] == '='){
				index += 2;
				syms.push_back("GEQ");
				name.push_back(">=");
				continue;
			}
		}
		
		// !=
		if (inputs[index] == '!'){
			if (inputs[index + 1] == '='){
				index += 2;
				syms.push_back("NEQ");
				name.push_back("!=");
				continue;
			}
		}
		
		// numbers
		if (isDigit(inputs[index])){
			string digits = "";
			
			while (isDigit(inputs[index])){
				digits += inputs[index];
				index++;
			}
			index--;
			
			syms.push_back("INTCON");
			name.push_back(digits);
		}
		
		// charcon
		if (inputs[index] == '\''){
			index++;
			string cahrcon = "";
			while (inputs[index] != '\''){
				cahrcon += inputs[index];
				index++;
			}
			syms.push_back("CARHCON");
			name.push_back(cahrcon);
		}
		
		// strcon
		if (inputs[index] == '\"'){
			index++;
			string strcon = "";
			while (inputs[index] != '\"'){
				strcon += inputs[index];
				index++;
			}
			syms.push_back("STRCON");
			name.push_back(strcon);
		}
		
		// identifier
		if (isInAlphabet(inputs[index])){
			string chars = "";
			
			while (isInAlphabet(inputs[index]) || isDigit(inputs[index])){
				chars += inputs[index];
				index++;
			}
			index--;
			
			// is token
			if (chars == "const" || chars == "coNst"){
				syms.push_back("CONSTTK");
				name.push_back(chars);
			}
			else if (chars == "int"){
				syms.push_back("INTTK");
				name.push_back(chars);
			}	
			else if (chars == "char"){
				syms.push_back("CHARTK");
				name.push_back(chars);
			}	
			else if (chars == "void"){
				syms.push_back("VOIDTK");
				name.push_back(chars);
			}	
			else if (chars == "main"){
				syms.push_back("MAINTK");
				name.push_back("main");
			}	
			else if (chars == "if"){
				syms.push_back("IFTK");
				name.push_back(chars);
			}	
			else if (chars == "else"){
				syms.push_back("ELSETK");
				name.push_back(chars);
			}	
			else if (chars == "switch"){
				syms.push_back("SWITCHTK");
				name.push_back(chars);
			}	
			else if (chars == "case"){
				syms.push_back("CASETK");
				name.push_back(chars);
			}	
			else if (chars == "default"){
				syms.push_back("DEFAULTTK");
				name.push_back(chars);
			}	
			else if (chars == "while"){
				syms.push_back("WHILETK");
				name.push_back(chars);
			}	
			else if (chars == "for"){
				syms.push_back("FORTK");
				name.push_back(chars);
			}	
			else if (chars == "scanf"){
				syms.push_back("SCANFTK");
				name.push_back(chars);
			}	
			else if (chars == "printf"){
				syms.push_back("PRINTFTK");
				name.push_back(chars);
			}	
			else if (chars == "return"){
				syms.push_back("RETURNTK");
				name.push_back(chars);
			}	
			else{
				syms.push_back("IDENFR");
				name.push_back(chars);
			}
			
		}
		
		index++;
	}// while
		
	printAns();
    return 0;
}// main

