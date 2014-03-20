#ifndef CONNECTION_H
#define CONNECTION_H
#include <string>
using std::string;

/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                     *
 * Class:  Connection                                  *
 *                                                     *
 * Purpose:  Manage TCP/IP connection as a client      *
 *           or server                                 *
 *                                                     *
 * Interface:                                          *
 *                                                     *
 *  ctor     - initializes connection socket to zero   *
 *                                                     *
 *  dtor     - closes connection socket                *
 *                                                     *
 *  transmit - sends given string over socket          *
 *             - in:     string to be transmitted      *
 *             - return: value of good bit             *
 *                                                     *
 *  receive  - reads string over connection socket     *
 *             - out:    string received               *
 *             - return: value of good bit             *
 *                                                     *
 *  good     - getter for good bit                     *
 *             - return: value of good bit             *
 *                                                     *
 *  closeConn- closes the connection socket            *
 *                                                     *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * */

class Connection {
public:
	Connection();
	~Connection();
	bool transmit(string);
	bool receive(string&);
	bool good() const;
	void closeConn();

protected:
	int connSocket;
	bool goodBit;
	bool openSocket(int&);
};

/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                     *
 * Class:  ServerConnection                            *
 *                                                     *
 * Purpose:  Manage TCP/IP connection as a server      *
 *                                                     *
 * Interface:                                          *
 *                                                     *
 *  ctor - initializes listen socket to zero           *
 *                                                     *
 *  dtor - closes listen socket                        *
 *                                                     *
 *  open - sets up a listening socket to accept        *
 *         incoming connection requests                *
 *         - in:     port on which to listen           *
 *         - return: value of good bit                 *
 *         - side-effects:                             *
 *           - initializes listen socket               *
 *           - sets good bit to false in case of error *
 *                                                     *
 *  wait - blocks until connection request is received *
 *         - return: value of good bit                 *
 *         - side-effects:                             *
 *           - initializes connection socket           *
 *           - sets good bit to false in case of error *
 *                                                     *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * */

class ServerConnection: public Connection {
public:
	ServerConnection();
	~ServerConnection();
	bool open(int);
	bool wait();
private:
	int listenSocket;
};

/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                     *
 * Class:  ClientConnection                            *
 *                                                     *
 * Purpose:  Manage TCP/IP connection as a client      *
 *                                                     *
 * Interface:                                          *
 *                                                     *
 *  open - sets up connection to server                *
 *         - in:     IP address of server              *
 *         - in:     port where server is listening    *
 *         - return: value of good bit                 *
 *         - side-effects:                             *
 *           - initializes connection socket           *
 *           - establishes connection to server        *
 *           - sets good bit to false in case of error *
 *                                                     *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * */

class ClientConnection: public Connection {
public:
	bool open(string, int);
};

#endif
