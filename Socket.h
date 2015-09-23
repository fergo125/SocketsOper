#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <exception>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>



class Socket
{
	private:
		int numeroSocket;
		
	public:
		Socket();
		Socket(int n);
		Socket(char c, bool b = false);
		~Socket();
		Socket * Accept();
		int Connect(char * host, int port);
		int Read(char * text, int len);
		int Write(char * text, int len);
		int Shutdown( int i);
		int Listen(int queue);
		int Bind(int queue);
		int Close();
};
