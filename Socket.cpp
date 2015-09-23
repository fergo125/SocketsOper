#include "Socket.h"

Socket::Socket(){
	numeroSocket= socket(PF_INET,SOCK_STREAM,0);
}

Socket::Socket(int n){
	numeroSocket= n;
}

Socket::Socket(char c, bool b){
	numeroSocket= b?socket(PF_INET,SOCK_STREAM,AF_INET6):socket(PF_INET,SOCK_STREAM,AF_INET);
}

Socket::~Socket(){
	close(numeroSocket);
}

int Socket::Read(char * text, int len){
	return read(numeroSocket,text,len);
	
}
int Socket::Write(char * text, int len){
	return write(numeroSocket,text,len);
	
}
int Socket::Shutdown(int i){

	return shutdown(numeroSocket,i);
}

int Socket::Close(){
	return close(numeroSocket);
}
	
int Socket::Connect(char* host, int port){
	struct sockaddr_in host_addr;
    host_addr.sin_family = AF_INET;
	inet_aton( host,  &host_addr.sin_addr );
	host_addr.sin_port = htons( port );
	int len = sizeof( host_addr );
	return connect( numeroSocket, (sockaddr *) & host_addr, len );
}

int Socket::Listen(int queue){
	return 	listen(numeroSocket,queue);
}
int Socket::Bind(int port){
	struct sockaddr_in server_addr;
	server_addr.sin_family = PF_INET;
	server_addr.sin_addr.s_addr = htonl( INADDR_ANY );
	server_addr.sin_port = htons( port );
	int len = sizeof( server_addr );
	int b = bind( numeroSocket, (const sockaddr *) & server_addr, len );
	if(-1 == b){
		//perror("No funca el bind");
		//exit(0);
	}
	return b;
}
Socket * Socket::Accept(){
	sockaddr addr;
	socklen_t len = sizeof(addr);
	int s = accept(numeroSocket, &addr,&len);
	if( s == -1){
		//perror("No funca el accept");
		//exit(0);
	}
	return new Socket(s);
	}
