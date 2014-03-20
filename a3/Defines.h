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


typedef enum UpdateType { DB_ADD, DB_DELETE, DB_RETRIEVE, DB_ACK } UpdateType;


#endif /* DEFINES_H_ */
