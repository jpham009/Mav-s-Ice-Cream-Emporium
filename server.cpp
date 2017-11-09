#include "server.h"

Server::Server(string name, string phone, string id, double salary) : Person(name, phone, id, salary){}


string Server::type(){
	return "Server";
}



