#include <bits/stdc++.h> 
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024
using namespace std;

int main()
{
	// 读取文件 
   	char buff[MAX_LINE];
   	int i;
   	FILE *fp=fopen("text.txt","r");
   	int len;
   	if(fp==NULL) {
    	printf(" Open file Error !\n");
    	exit(0);
   	}

	int n=0;
	while( !feof(fp) ){
	    buff[n] = fgetc(fp);
	    n++;
	}
	int row=1; // 行号，从1开始，一共12行 
	for(i=0;i<n;i++){
	    cout << buff[i];
	    if(buff[i]=='\n')
			row++; 
	}
	return 0;
}

