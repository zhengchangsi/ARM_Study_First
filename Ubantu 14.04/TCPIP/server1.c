#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include </usr/include/x86_64-linux-gnu/sys/types.h>
#include </usr/include/x86_64-linux-gnu/sys/socket.h>
#include </usr/include/x86_64-linux-gnu/sys/un.h>

int main()
{
	int serverid,clientid;//domain
	struct sockaddr_un myaddr;
	struct sockaddr_un clientaddr;
	myaddr.sun_family = AF_UNIX;
	strcpy(myaddr.sun_path,"zcssocketfile");
	int clientaddr_len = sizeof(clientaddr);
	
	//create socket
	serverid = socket(AF_UNIX,SOCK_STREAM,0);
	if(serverid == -1)
	{
		perror("socket error!\n");
		exit(1);
	}
	//bind
	if(bind(serverid,(struct sockaddr *)&myaddr,sizeof(myaddr)) == -1)
	{
		perror("Bind error!\n");
		exit(1);
	}
	//listen
	if(listen(serverid,20) == -1)
	{
		perror("Listen error!\n");
		exit(1);
	}
	printf("listening...\n");
	//accept
	clientid = accept(serverid,(struct sockaddr *)&clientaddr,&clientaddr_len);
	if(clientid == -1)
	{
		perror("accept error!\n");
		exit(1);
	}
	//op
	write(clientid,"Hello zcs",9);
	printf("write success\n");
	//close
	close(clientid);
	close(serverid);
	
	return 0;

}
