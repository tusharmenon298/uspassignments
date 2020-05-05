#define _POSIX
#define _POSIX_C_SOURCE 199309L
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/types.h>
int main(int argc,char *argv[])
{
	int n,fd,n1;
	char buf[10],c[2]=" ";
	if(argc<3)
		perror("Required number of filenames not provided...");
	else
	{
		n=symlink(argv[1],argv[2]);
		if(n!=-1)
		{
			printf("%s and %s are linked...\n",argv[1],argv[2]);
			printf("The original pathname of %s is: ",argv[2]);
			n1=readlink(argv[2],buf,10);
			printf("%s\n",buf);
			printf("Reading the contents of original file: \n");
			fd=open(buf,O_RDONLY);
			if(fd==-1)
				perror("File cannot be opened for reading...");
			else
			{
				while(read(fd,c,1)>0)
				printf("%s",c);
			}
		}
		else
			perror("Files are not linked...");
	}
}
