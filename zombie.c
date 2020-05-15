#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int id;
    id=fork();

    if(id>0)
    {
        printf("Parent will sleep\n");
        sleep(10);
    }
    if(id==0)
        printf("I am child\n");
	exit(0);
}
