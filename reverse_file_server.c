#include<stdio.h>
#include<stdlib.h>
#include<netdb.h>
#include<netinet/in.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#define MAX 80
#define SA struct sockaddr
#define PORT 1024
int main()
{
        struct sockaddr_in servaddr, cli;
        int sockfd, connfd,len,number;
        char buff[MAX];
        sockfd=socket(AF_INET,SOCK_STREAM,0);
        if(sockfd==-1){
                printf("Socket creation failed...\n");
        }
        else{
                printf("Socket created successfully...\n");
        }
        bzero(&servaddr,sizeof(servaddr));
        servaddr.sin_family=AF_INET;
        servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
        servaddr.sin_port=htons(PORT);
        if((bind(sockfd,(SA*)&servaddr,sizeof(servaddr)))!=0){
                printf("Socket bind failed...\n");
        }
        else{
                printf("Socket binded...\n");
        }
        if((listen(sockfd,5))!=0)
        {
                printf("Socket listen failed...\n");
        }
        else{
                printf("Socket listening...\n");
        }
        len=sizeof(cli);
        connfd=accept(sockfd,(SA*)&cli,&len);
        if(connfd<0){
                printf("Connection failed..\n");
        }
        else{
                printf("Connection successful...\n");
        }
        read(connfd,buff,sizeof(buff));
        number=strlen(buff);
        printf("\n%s\n",buff);
        printf("Number of characters in the file : %d\n",number);
        int i;
        for(i=number;i>=0;i--)
        {
                printf("%c",buff[i]);
        }
        close(sockfd);
}
