#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L
#include<unistd.h>
#include<stdio.h>
#include<iostream>
#include<fcntl.h>
using namespace std;
int main(int argc, char *argv[])
{
	int d1,n;
	char buffer1[200],buffer2[200];
	d1=open(argv[1],O_RDWR|O_CREAT,777);
	cout<<"Enter contents to be added"<<endl;
	cin>>buffer1;
	write(d1,buffer1,200);
	close(d1);
	d1=open(argv[1],O_RDONLY);
	cout<<"contents of new file\t"<<argv[1]<<endl;
	while((n=read(d1,buffer2,200))>0)
	{
		cout<<buffer2;
	}
	cout<<endl;
	close(d1);
	return 0;
}
