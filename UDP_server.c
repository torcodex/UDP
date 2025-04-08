#include<stdio.h>
#include<stdlib.h>
#include<unistring.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h)
#include<arpa/inet.h>
int main(int argc,char **argv){
    int sockid,port=4455,n;
    char *ip="127.0.00.1";
    char buffer[1024];
    struct sockaddr_in server,client;
    socklen_t size;
    sockid = socket(AF_INET,SOCK_DGRAM,0);
    if(sockid<0){
        printf("Couldn't create socket");
        return -1;
    }
    printf("Socket created");
    
    memset(&server,'\0',sizeof(server));

    server.sin_family=AF_INET;
    server.sin_port=htons(port);
    server.sin_addr.s_addr=inet_addr(ip);
    n=bind(sockid,(struct sockaddr*)&server,sizeof(server));
    if(n<0){
        printf("Couldn't bind");
        return -1;
    }
    printf("bind done");

    bzero(buffer,1024);
    size=sizeof(client);
    recvfrom(sockid,buffer,1024,0,(struct sockaddr*)&clinet,size);
    printf("data receive: %s\n",buffer);

    bezro(buffer,1024);
    strcpy(buffer,"Hi there");

    sendto(sockid,buffer,1024,0,(struct sockaddr*)&client,sizeof(client));
    printf("Data send: %s\n",buffer);
    return 0;
}
