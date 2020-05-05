#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L
#include<unistd.h>
#include<stdio.h>
int main(int argc, char *argv[])
{	
	char str[100];
	char *a=argv[1],*b=argv[2];
	if(argc!=3)
	{
		printf("Usage: %s <src_file><dest_file>\n",argv[0]);
		return 0;
	}
	if(link(argv[1],argv[2])==-1)
	{
		printf("Error Occurred \n");
		return 1;
	}
	printf("Files have been linked\nInode number of linked files\n");
	sprintf(str,"ls -i %s %s\n",a,b);
	system(str);
	return 0;
}

