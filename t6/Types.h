////////////////////////////////////////////////////////////////////////////////
// -------------------------------------------------------------------------- //
//                                                                            //
//   Authors: David Krutsko                                                   //
//   Project: COMP 2404 W13                                                   //
//                                                                            //
// -------------------------------------------------------------------------- //
////////////////////////////////////////////////////////////////////////////////

//----------------------------------------------------------------------------//
// Prefaces                                                                   //
//----------------------------------------------------------------------------//

#ifndef TYPES_H
#define TYPES_H



//----------------------------------------------------------------------------//
// Keywords                                                                   //
//----------------------------------------------------------------------------//

#ifndef NULL
#define NULL 0
#endif

#ifndef elif
#define elif else if
#endif

#define DEBUG 1
#define C_LOG_FILE "debugOut"



//----------------------------------------------------------------------------//
// Types                                                                      //
//----------------------------------------------------------------------------//

typedef signed char			int8;		// Signed  8-bit integer
typedef signed short		int16;		// Signed 16-bit integer
typedef signed int			int32;		// Signed 32-bit integer
typedef signed long long	int64;		// Signed 64-bit integer

typedef unsigned char		uint8;		// Unsigned  8-bit integer
typedef unsigned short		uint16;		// Unsigned 16-bit integer
typedef unsigned int		uint32;		// Unsigned 32-bit integer
typedef unsigned long long	uint64;		// Unsigned 64-bit integer

#endif // TYPES_H
