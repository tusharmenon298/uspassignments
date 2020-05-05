#include <fcntl.h>
#include <unistd.h>
#include <iostream>
using namespace std;

int main(int argc,char* argv[])
{
	int f;
	char buffer[250];
	struct flock fvar;
	if(argc!=2)
	{
		cout<<"Error"<<endl;
		return 1;
	}
	
	if( (f=open(argv[1],O_RDWR))==-1)
	{
		cout<<"error"<<endl;
		return 1;
	}
	
	fvar.l_type=F_WRLCK;
	fvar.l_whence=SEEK_END;
	fvar.l_start=SEEK_END-100;
	fvar.l_len=100;
	cout<<"Trying to lock"<<endl;
	if((fcntl(f,F_SETLK,&fvar))==-1)
	{
		fcntl(f,F_GETLK,&fvar);
		cout<<"Already locked by process having pid\t"<<fvar.l_pid<<endl;
		return 1;
	}
	cout<<"Locked file"<<endl;
	

	if((lseek(f,SEEK_END-50,SEEK_END))==-1)
	{
		cout<<"error"<<endl;
		return 1;
	}
	if((read(f,buffer,100))==-1)
	{
		cout<<"error"<<endl;
		return 1;
	}
	cout<<"File data"<<endl;
	cout<<buffer<<endl;
	cout<<"Releasing locks"<<endl;
	fvar.l_type=F_UNLCK;
	fvar.l_whence=SEEK_SET;
	fvar.l_start=0;
	fvar.l_len=0;
	if((fcntl(f,F_UNLCK,&fvar))==-1)
	{
		cout<<"Error"<<endl;
		return 1;
	}
	cout<<"Unlocked"<<endl;
	close(f);
	return 0;
}
