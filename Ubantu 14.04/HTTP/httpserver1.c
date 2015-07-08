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
	int server_fd,client_fd;
	struct sockaddr_in myaddr;
	struct sockaddr_in clientaddr;
	myaddr.sin_family = AF_INET;
	myaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	myaddr.sin_port = htons(80);

	int client_len;
	char content[] = "<html><h1>hello zcs</h1></html>";
	
	server_fd = socket(AF_INET,SOCK_STREAM,0);
	if(server_fd == -1)
		perror("socket error!\n");
	if(bind(server_fd,(struct sockaddr *)&myaddr,sizeof(myaddr)) == -1)
		perror("bind error\n");
	if(listen(server_fd,20) == -1)
		perror("listen error\n");
	while(1)
	{
		client_fd = accept(server_fd,(struct sockaddr*)&clientaddr,&client_len);
		if(client_fd == -1)	
			perror("client error\n");
		printf("accept \n");
		send(client_fd,content,sizeof(content),0);
		close(client_fd);
	}
	close(server_fd);

}
