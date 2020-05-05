#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
int main(int argc, char *argv[])
{	
	
	int d1,d2,n;
	char buffer[10];
	d1=open(argv[1],O_RDONLY);
	if(d1==-1)
	{
		printf("%s doesn't exist \n",argv[1]);
	}
	else
	{
		d2=open(argv[2],O_WRONLY|O_CREAT,777);
		lseek(d2,0,SEEK_SET);
		while((n=read(d1,buffer,10))>0)
		{	
			write(d2,buffer,n);
		}
		printf("Contents of %s has been moved to %s \n",argv[1],argv[2]);
	}
	close(d1);
	close(d2);
	unlink(argv[1]);
	return(0);
}
