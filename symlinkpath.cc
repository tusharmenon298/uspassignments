#define _POSIX
#define _POSIX_C_SOURCE 199309L
#include <iostream>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
using namespace std;
int main(int argc,char* argv[])
{
	char buf[15],n;
	if(argc<3)
	{
		cout<<"Error,Less arguments"<<endl;
		return 1;
	}
	else
	{
		int fd;
		fd=symlink(argv[1],argv[2]);
		if(fd==-1){
			cout<<"Files not linked"<<endl;
			return 1;
		}
		else
		{
			cout<<("Two files are linked....")<<endl;
			cout<<"Original pathname of the file to which "<<argv[2]<<" is referring to is:"<<endl;
			n=readlink(argv[2],buf,15);
			if(n==-1)
				cout<<"Cannot get the original pathname..."<<endl;
			else
				cout<<buf<<endl;
		}
	}
	return 0;
}

