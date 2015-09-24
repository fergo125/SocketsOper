#include "Socket.h"
int main(int argc, char ** argv){
	Socket s;
	char buffer[512];
	s.Connect2( argv[1], 80 ); // Same port as server
	s.Write( argv[2], 512);		// Send first program argument to server
	s.Read( buffer , 500);		// Read the answer sent back from server
	printf( "%s \n", buffer );	// Print the string
}
