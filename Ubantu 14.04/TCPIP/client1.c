#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include </usr/include/x86_64-linux-gnu/sys/types.h>
#include </usr/include/x86_64-linux-gnu/sys/socket.h>
#include </usr/include/x86_64-linux-gnu/sys/un.h>

int main()
{
	int serverid;//domain
	struct sockaddr_un myaddr;
	myaddr.sun_family = AF_UNIX;
	strcpy(myaddr.sun_path,"zcssocketfile");
	char buf[100];
	
	//create socket
	serverid = socket(AF_UNIX,SOCK_STREAM,0);
	if(serverid == -1)
	{
		perror("socket error!\n");
		exit(1);
	}
	//conneect
	if(connect(serverid,(struct sockaddr *)&myaddr,sizeof(myaddr)) == -1)
	{
		perror("connect error\n");
		exit(1);
	}
	//read
	read(serverid,buf,100);
	printf("get message:%s\n",buf);
	//close
	close(serverid);
	
	return 0;

}
