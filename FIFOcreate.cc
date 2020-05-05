//Program to create FIFO file
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	int id=mkfifo(argv[1],S_IFIFO|0666);
	if(id==0)
		cout<<"FIFO created"<<endl;
	else{
		cout<<"Failed to create FIFO"<<endl;
		return 1;
	}
	return 0;
}
