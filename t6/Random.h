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

#ifndef RANDOM_H
#define RANDOM_H

#include "Types.h"



//----------------------------------------------------------------------------//
// Classes                                                                    //
//----------------------------------------------------------------------------//

////////////////////////////////////////////////////////////////////////////////
/// <summary> Represents a pseudo-random number generator, a device that
/// 		  produces a sequence of numbers that meet certain statistical
/// 		  requirements for randomness. </summary>
///
/// <remarks> This class can be initialized with a seed value. If the same seed
/// 		  is used repeatedly, the same series of numbers will be generated.
/// 		  Generated numbers are chosen with equal probability from a finite
/// 		  set of numbers. The chosen numbers are not completely random because
/// 		  a definite mathematical algorithm is used to select them, but they
/// 		  are sufficiently random for practical purposes.
///
/// 		  The current implementation of the Random class is based on the
/// 		  WELL algorithm created by Francois Panneton, Pierre L'Ecuyer and
/// 		  Makoto Matsumoto. The implementation in this class has a period
/// 		  of 2^512 - 1 and passes the DIEHARD Tests. See here for more:
/// 		  www.iro.umontreal.ca/~panneton/WELLRNG.html.
///
/// 		  Pseudo-random values are generated using an optimized method
/// 		  created by Chris Lomont. This method is about forty percent
/// 		  faster than the reference. More information can be found here:
/// 		  www.lomont.org/Math/Papers/2008/Lomont_PRNG_2008.pdf. </remarks>

class Random
{
public:
	//----------------------------------------------------------------------------//
	// Constructors                                                               //
	//----------------------------------------------------------------------------//

	////////////////////////////////////////////////////////////////////////////////
	/// <summary> Creates a new instance of the Random class,
	/// 		  using a time-dependent seed value. </summary>
	///
	/// <remarks> The default seed value is derived from the system clock and has
	/// 		  finite resolution. As a result, different Random objects that are
	/// 		  created in close succession by a call to the default constructor
	/// 		  will have identical default seed values and, therefore, will
	/// 		  produce identical sets of random numbers. This problem can be
	/// 		  avoided by using a single Random object to generate all random
	/// 		  numbers. You can also work around it by modifying the seed value
	/// 		  returned by the system clock and then explicitly providing this
	/// 		  new seed value to the Random (uint32) constructor. </remarks>

	Random (void);

	////////////////////////////////////////////////////////////////////////////////
	/// <summary> Creates a new instance of the Random class,
	/// 		  using the specified seed value. </summary>
	/// <param name="seed"> A number used to calculate a starting value
	/// 					for the pseudo-random number sequence. </param>

	explicit Random (uint32 seed);

	////////////////////////////////////////////////////////////////////////////////
	/// <summary> Creates a copy of the specified Random class. </summary>
	/// <param name="point"> Random class to copy from. </param>

	Random (const Random& random);

	////////////////////////////////////////////////////////////////////////////////
	/// <summary> Creates a copy of the specified Random class. </summary>
	/// <param name="point"> Random class to copy from. </param>

	void operator = (const Random& random);

	////////////////////////////////////////////////////////////////////////////////
	/// <summary> Destroys this instance of the Random class. </summary>

	virtual ~Random (void);



public:
	//----------------------------------------------------------------------------//
	// Functions                                                                  //
	//----------------------------------------------------------------------------//

	////////////////////////////////////////////////////////////////////////////////
	/// <summary> Returns a pseudo-random unsigned 32-bit integer. </summary>

	virtual uint32 NextInt (void);

	////////////////////////////////////////////////////////////////////////////////
	/// <summary> Returns a pseudo-random unsigned 32-bit integer. </summary>
	/// <remarks> The resulting value is in the range [0, max). </remarks>

	virtual uint32 NextInt (uint32 max);

	////////////////////////////////////////////////////////////////////////////////
	/// <summary> Returns a pseudo-random boolean value. </summary>

	virtual bool NextBool (void);

	////////////////////////////////////////////////////////////////////////////////
	/// <summary> Returns a pseudo-random 64-bit real value. </summary>
	/// <remarks> The resulting value is in the range [0, 1]. </remarks>

	virtual double NextReal (void);

	////////////////////////////////////////////////////////////////////////////////
	/// <summary> Fills the specified buffer with random values. </summary>
	/// <param name="index">  The starting index of the buffer.  </param>
	/// <param name="length"> The length of the buffer to fill.  </param>

	virtual void NextBytes (uint8* buffer, uint32 index, uint32 length);

	////////////////////////////////////////////////////////////////////////////////
	/// <summary> Returns a global instance of the Random number generator. </summary>

	static Random* Instance (void);



protected:
	//----------------------------------------------------------------------------//
	// Fields                                                                     //
	//----------------------------------------------------------------------------//

	uint32 mIndex;		// Index of state
	uint32 mState[16];	// Generator state
};

#endif // RANDOM_H
