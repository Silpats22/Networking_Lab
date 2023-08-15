#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<string.h>
#include<unistd.h>
#define SA struct sockaddr
#define PORT 1024
int main()
{
        int sockfd, connfd,len,num,rem;
        struct sockaddr_in servaddr,cli;
        sockfd=socket(AF_INET,SOCK_STREAM,0);
        if(sockfd==-1){
                printf("Socket creation failed...\n");
        }
        else{
                printf("Socket created successfully...\n");
        }
        bzero(&servaddr,sizeof(servaddr));
        servaddr.sin_family=AF_INET;
        servaddr.sin_addr.s_addr=INADDR_ANY;
        servaddr.sin_port=htons(PORT);
        if((bind(sockfd,(SA*)&servaddr,sizeof(servaddr)))!=0){
                printf("Socket bind failed...\n");
        }
        else{
                printf("Socket binded successfully...\n");
        }
        if((listen(sockfd,5))!=0){
                printf("Socket listen failed...\n");
        }
        else{
                printf("Socket listening...\n");
        }
        len=sizeof(cli);
        connfd=accept(sockfd,(SA*)&cli,&len);
        if(connfd<0){
                printf("Sever accept failed...\n");
        }
        else{
                printf("Server accept client...\n");
        }
        read(connfd,&num,sizeof(num));
        printf("%d\n",num);
        printf("Number after reversal : \n");
        while(num>0)
        {
                rem=num%10;
                num=num/10;
                printf("%d",rem);
        }
        close(sockfd);
}
