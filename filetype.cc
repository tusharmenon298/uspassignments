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
		cout<<endl<<"File Type=\t";
		if(S_ISREG(fp))
			cout<<"Regular file ";
		else if(S_ISDIR(fp))
			cout<<"Directory file ";
		else if(S_ISCHR(fp))
			cout<<"Character Special file ";
		else if(S_ISBLK(fp))
			cout<<"Block Special file ";
		else if(S_ISFIFO(fp))
			cout<<"Pipe or FIFO ";
		else if(S_ISLNK(fp))
			cout<<"Symbolic Link ";
		else if(S_ISSOCK(fp))
			cout<<"Socket ";
		else
			cout<<"Can't determine ";
		cout<<endl;
	}
	else
		cout<<"Unable to locate file"<<endl<<"Check if file exists or the path is right"<<endl;
	return 0;
}
