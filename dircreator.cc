#define _POSIX
#define _POSIX_C_SOURCE 199309L
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <iostream>
using namespace std;
typedef struct dirent Dirent;
int main( int argc, char* argv[])
{
	DIR* f;
	Dirent* d;
	
	if(argc<3){
		cout<<"Not enough arguments"<<endl;
		return 1;
	}
	
	
	if( (mkdir(argv[1],S_IRWXU|S_IRWXG|S_IROTH|S_IWOTH|S_IXOTH)) != -1){
		cout<<"Created Directory"<<endl;
	}
	else
	{
		cout<<"failed"<<endl;
		return 1;
	}
	
	f=opendir(argv[2]);
	if(f==NULL){
		cout<<"Directory not available"<<endl;
		return 1;
	}
	cout<<"Contents of home are"<<endl;
	while(d=readdir(f))
		cout<<d->d_name<<"\t";
	cout<<endl;
	
			
	return 0;
}
