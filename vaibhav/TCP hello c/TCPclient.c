/*TE-B 
ROLL NO: 05
Write a program using TCP socket for wierd network for following:
say hello to each other.(client side)*/

#include<stdio.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<string.h>
#include<stdlib.h>

#define MAX 80
#define PORT 43454
#define SA struct sockaddr

void func(int sockfd)
{
	int operater,no1,no2;
	for(;;)
	{
		printf("Enter the operation to be performed : \n1.Addition\n2.Subtraction\n.Division");
		scanf("%d", operator);
		printf("Enter the first operand:");
		scanf("%d", no1);
		printf("Enter the second operand:");
		scanf("%d", no2);

		write(sockfd,operator,sizeof(operator));
		bzero(buff,sizeof(buff));
		read(sockfd,buff,sizeof(buff));
		printf("From Server : %s",buff);
		if((strncmp(buff,"exit",4))==0)
		{
			printf("Client Exit...\n");
			break;
		}
	}
}

int main()
{
int sockfd,connfd;
struct sockaddr_in servaddr,cli;

sockfd=socket(AF_INET,SOCK_STREAM,0);

if(sockfd==-1)
{
	printf("socket creation failed...\n");
	exit(0);
}
else
	printf("Socket successfully created..\n");

	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	servaddr.sin_port=htons(PORT);

	if(connect(sockfd,(SA *)&servaddr,sizeof(servaddr))!=0)
	{
		printf("connection with the server failed...\n");
		exit(0);
	}
	else
	printf("connected to the server..\n");
		func(sockfd);
		close(sockfd);
}



/*OUTPUT:

res@res-HP-280-G2-MT-Legacy:~/Desktop/FINAL /assignment 7/Chat_server$ ./a.outSocket successfully created..
connected to the server..
Enter the string : hello
From Server : hello!!!
Enter the string : 

*/

