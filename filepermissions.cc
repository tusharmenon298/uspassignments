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
		mode_t fp=s.st_mode;
		cout<<endl<<"File Permissions=\t";
		if(fp & R_OK)
			cout<<"read ";
		if(fp & W_OK)
			cout<<"write ";
		if(fp & X_OK)
			cout<<"execute ";
		cout<<endl;
	}
	else
		cout<<"Unable to locate file"<<endl<<"Check if file exists or the path is right"<<endl;
	return 0;
}
