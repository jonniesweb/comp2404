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

#ifndef POINT_H
#define POINT_H

#include <iostream>
#include "Types.h"



//----------------------------------------------------------------------------//
// Classes                                                                    //
//----------------------------------------------------------------------------//

////////////////////////////////////////////////////////////////////////////////
/// <summary> Represents a point with components X and Y. </summary>

class Point
{
public:
	// Constants
	static const Point		Zero;	// Point ( 0,  0);
	static const Point		North;	// Point ( 0, -1);
	static const Point		East;	// Point (-1,  0);
	static const Point		South;	// Point ( 0,  1);
	static const Point		West;	// Point ( 1,  0);

public:
	// Constructors
	Point					(void);
	Point					(int32 x, int32 y);
	explicit Point			(int32 value);

	Point					(const Point& point);
	void operator =			(const Point& point);
	virtual ~Point			(void);

public:
	// Properties
	int32 X;
	int32 Y;
};



//----------------------------------------------------------------------------//
// Operators                                                            Point //
//----------------------------------------------------------------------------//

std::ostream& operator << (std::ostream& stream, const Point& point);

Point& operator += (Point& point1, const Point& point2);
Point& operator -= (Point& point1, const Point& point2);
Point& operator *= (Point& point1, const Point& point2);
Point& operator /= (Point& point1, const Point& point2);

Point& operator += (Point& point1, int32 point2);
Point& operator -= (Point& point1, int32 point2);
Point& operator *= (Point& point1, int32 point2);
Point& operator /= (Point& point1, int32 point2);

Point operator + (const Point& point1, const Point& point2);
Point operator - (const Point& point1, const Point& point2);
Point operator * (const Point& point1, const Point& point2);
Point operator / (const Point& point1, const Point& point2);

Point operator + (const Point& point, int32 value);
Point operator - (const Point& point, int32 value);
Point operator * (const Point& point, int32 value);
Point operator / (const Point& point, int32 value);

Point operator + (int32 value, const Point& point);
Point operator - (int32 value, const Point& point);
Point operator * (int32 value, const Point& point);
Point operator / (int32 value, const Point& point);

bool operator == (const Point& point1, const Point& point2);
bool operator != (const Point& point1, const Point& point2);
bool operator <  (const Point& point1, const Point& point2);
bool operator <= (const Point& point1, const Point& point2);
bool operator >  (const Point& point1, const Point& point2);
bool operator >= (const Point& point1, const Point& point2);

Point operator - (const Point& point);

Point& operator ++ (Point& point);
Point& operator -- (Point& point);
Point  operator ++ (Point& point, int);
Point  operator -- (Point& point, int);

#endif // POINT_H
