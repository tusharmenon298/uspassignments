#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L
#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<iostream>
#include<fcntl.h>
using namespace std;
int main()
{
	char *buff=(char *)calloc(100,sizeof(char));
	int f,n;
	
	f=open("f1.txt",O_RDONLY|O_CREAT);
	cout<<"Printing first 10 bytes"<<endl;
	read(f,buff,10);
	cout<<buff<<endl;
	lseek(f,9,SEEK_CUR);
	cout<<"Printing from the 20th byte"<<endl;
	while((n=read(f,buff,100))>0)
		cout<<buff;
	cout<<endl;
	return 0;
}
	
	
