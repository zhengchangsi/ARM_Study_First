#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include </usr/include/x86_64-linux-gnu/sys/types.h>
#include </usr/include/x86_64-linux-gnu/sys/socket.h>
#include </usr/include/x86_64-linux-gnu/sys/un.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc,char *argv[])
{
	if(argc < 2)
	{
		perror("argment count error");
		exit(1);
	}
	int serverid;//domain
	struct hostent *myhost;
	struct sockaddr_in myaddr;
	myaddr.sin_family = AF_INET;
	myhost = gethostbyname(argv[1]);
	if(!myhost)
	{
		perror("gethost error");
		exit(1);
	}
	myaddr.sin_addr = *((struct in_addr *)(myhost->h_addr));
	myaddr.sin_port = htons(8080);
	char buf[100];
	
	//create socket
	serverid = socket(AF_INET,SOCK_DGRAM,0);
	if(serverid == -1)
	{
		perror("socket error!\n");
		exit(1);
	}
	//read
	sendto(serverid,"hello zcs",9,0,(struct sockaddr*)&myaddr,sizeof(myaddr));
	printf("send success\n");
	//close
	close(serverid);	
	return 0;

}
