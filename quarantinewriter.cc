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
	int f;
	char a[]="We are quarantined since one month";
	char b[]="We are not sure when lockdown will be released";
	f=open("f1.txt",O_WRONLY|O_CREAT,777);
	if(f<0)
	{
		cout<<"Error"<<endl;
		return 1;
	}
	cout<<"Writing first line"<<endl;
	write(f,a,35);
	cout<<"Moving 50 bytes forward and writing second line"<<endl;
	lseek(f,50,SEEK_CUR);
	write(f,b,50);
	close(f);
	return 0;
}
