//Writes FIFO
#include <unistd.h>
#include <cstring>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	int f;
	char buf[20];
	f=open(argv[1],O_RDWR);
	if(f==-1)
	{
		cout<<"error"<<endl;
		return 1;
	}
	cout<<"Enter stuff to write in FIFO"<<endl;
	cin>>buf;
	write(f,buf,strlen(buf)+1);
	close(f);
	return 0;
}
