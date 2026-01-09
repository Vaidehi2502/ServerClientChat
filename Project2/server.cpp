#include<iostream>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<cstring>
using namespace std;

int main(){
    int server_socket =  socket(AF_INET, SOCK_STREAM, 0);
    
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    bind(server_socket, (struct sockaddr*)&address, sizeof(address));
    listen(server_socket, 1);

    cout << "Server waiting...\n";

    int client_socket = accept(server_socket, NULL, NULL);
    
    char buffer[100];

    while(true){
        memset(buffer, 0, sizeof(buffer));

        read(client_socket, buffer,100);
        cout << "Client: " << buffer << endl;

        if(strcmp(buffer, "Bye") == 0){
            cout << "Chat ended.\n";
            break;
        }

        cout << "Server: ";
        cin.getline(buffer, 100);

        send(client_socket, buffer, strlen(buffer), 0);
    }
    close(client_socket);
    close(server_socket);
    return 0;
}