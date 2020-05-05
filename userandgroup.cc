#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L
#include<unistd.h>
#include<pwd.h>
#include<grp.h>
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
		struct passwd *p=getpwuid(s.st_uid);
		struct group *g=getgrgid(s.st_gid);
		cout<<endl;
		cout<<"User id is \t"<<s.st_uid<<"\tUser name is \t"<<p->pw_name<<endl;
		cout<<"Group id is\t"<<s.st_gid<<"\tGroup name is\t"<<g->gr_name<<endl;
		cout<<endl;
	}
	else
		cout<<"Unable to locate file"<<endl<<"Check if file exists or the path is right"<<endl;
	return 0;
}
