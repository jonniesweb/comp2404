/*
 * Defines.h
 *
 *  Created on: Mar 13, 2014
 *      Author: jon
 *
 *  Created this file to solve cyclic dependencies between Serializer and Storage
 */

#ifndef DEFINES_H_
#define DEFINES_H_

#define SERVER_PORT 60004

typedef enum UpdateType { DB_ADD, DB_DELETE, DB_RETRIEVE } UpdateType;


#endif /* DEFINES_H_ */
