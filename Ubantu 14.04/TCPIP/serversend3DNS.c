#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include </usr/include/x86_64-linux-gnu/sys/types.h>
#include </usr/include/x86_64-linux-gnu/sys/socket.h>
#include </usr/include/x86_64-linux-gnu/sys/un.h>
#include <arpa/inet.h>

int main()
{
	int serverid,clientid;//domain
	struct sockaddr_in myaddr;
	struct sockaddr_in clientaddr;
	myaddr.sin_family = AF_INET;
	myaddr.sin_addr.s_addr = htonl(INADDR_ANY);//any ip
	//strcpy(myaddr.sun_path,"zcssocketfile");
	myaddr.sin_port = htons(8080);//big duan and small duan
	int clientaddr_len = sizeof(clientaddr);
	
	//create socket
	serverid = socket(AF_INET,SOCK_STREAM,0);
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
	send(clientid,"Hello zcs",9,0);
	printf("write success\n");
	//close
	close(clientid);
	close(serverid);
	
	return 0;

}
