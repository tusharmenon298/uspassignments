#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L
#include<unistd.h>
#include<sys/stat.h>
#include<stdio.h>
#include<iostream>
#include<fcntl.h>
using namespace std;
int main(int argc, char *argv[])
{
	struct stat s;
	cout<<endl<<"File path=\t"<<argv[1]<<endl;
	if(stat(argv[1],&s)==0)
	{
		cout<<"Number of links file "<<argv[1]<<" has is "<<s.st_nlink<<endl;
	}
	else
		cout<<"Unable to locate file"<<endl<<"Check if file exists or the path is right"<<endl;
	return 0;
}
