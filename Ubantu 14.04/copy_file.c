#include <stdio.h>
#include </usr/include/x86_64-linux-gnu/sys/types.h>
#include </usr/include/x86_64-linux-gnu/sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
	int in,out;
	char c;
	//open file
	in = open ("file.in",O_RDONLY,0666);
	out = open("file.out",O_WRONLY|O_CREAT,0666);
	//read file
	while(read(in,&c,1))
	//write
		write(out,&c,1);
	//close
	close(in);
	close(out);
	return 0;
}
