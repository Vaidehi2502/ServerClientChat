#include<iostream>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<cstring>
using namespace std;

int main(){

    int sock = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);

    connect(sock, (struct sockaddr*)&server, sizeof(server));

    char buffer[100];

    while (true) {
        cout << "Client: ";
        cin.getline(buffer, 100);

        send(sock ,buffer, strlen(buffer), 0);

        if(strcmp(buffer, "Bye")==0){
            cout<<"Chat ended.\n";
            break;
        }
        memset(buffer, 0, sizeof(buffer));
        read(sock, buffer, 100);
        cout<<"Server: "<<buffer<<endl;
    }

    close(sock);
    return 0;
    
}