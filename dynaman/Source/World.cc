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

#include "Point.h"
#include "World.h"

#include "Entity.h"
#include "Player.h"

#include "WorldBuilder.h"



//----------------------------------------------------------------------------//
// Constructors                                                         World //
//----------------------------------------------------------------------------//

////////////////////////////////////////////////////////////////////////////////

World::World (void)
{
	mWidth		= 0;
	mHeight		= 0;

	mTime		= 0;
	mDoomed		= false;

	mPlayer		= NULL;
	mStatic		= NULL;
	mDynamic	= NULL;
	mEnemies	= NULL;
}

////////////////////////////////////////////////////////////////////////////////

World::~World (void)
{
	Destroy();
}



//----------------------------------------------------------------------------//
// Functions                                                            World //
//----------------------------------------------------------------------------//

////////////////////////////////////////////////////////////////////////////////

void World::Create (uint32 width, uint32 height)
{
	// Destroy previous world
	this->Destroy();

	// Copy world dimensions
	mWidth  = width;
	mHeight = height;

	// Create the static entity array
	mStatic = new Entity** [mWidth];
	for (uint32 x = 0; x < mWidth; ++x)
	{
		mStatic[x] = new Entity* [mHeight];
		for (uint32 y = 0; y < mHeight; ++y)
			mStatic[x][y] = NULL;
	}

	// Create the dynamic entity list
	mDynamic = new EntityList();
	mEnemies = new EntityList();

	// Set initial world time
	mDoomed = false;
	SetTime (180000);
}

////////////////////////////////////////////////////////////////////////////////

void World::Destroy (void)
{
	// Return if the world is invalid
	if (!IsValid()) return;

	// Destroy the static entity array
	for (uint32 x = 0; x < mWidth; ++x)
	{
		for (uint32 y = 0; y < mHeight; ++y)
			if (mStatic[x][y] != NULL)
				delete mStatic[x][y];

		delete[] mStatic[x];
	}

	delete[] mStatic;

	EntityList::Node* node;
	EntityList::Node* temp;

	// Destroy the dynamic entity list
	node = mDynamic->Front();
	while (node != NULL)
	{
		temp = node;
		node = node->Next();

		delete temp->Value;
		mDynamic->Remove (temp);
	}

	// Destroy the enemies entity list
	node = mEnemies->Front();
	while (node != NULL)
	{
		temp = node;
		node = node->Next();

		delete temp->Value;
		mEnemies->Remove (temp);
	}

	delete mDynamic;
	delete mEnemies;

	// Reset fields
	mWidth  = 0;
	mHeight = 0;

	mStatic  = NULL;
	mDynamic = NULL;
}

////////////////////////////////////////////////////////////////////////////////

bool World::IsValid (void) const
{
	return mStatic != NULL;
}

////////////////////////////////////////////////////////////////////////////////

uint32 World::GetWidth (void) const
{
	return mWidth;
}

////////////////////////////////////////////////////////////////////////////////

uint32 World::GetHeight (void) const
{
	return mHeight;
}

////////////////////////////////////////////////////////////////////////////////

int32 World::GetTime (void) const
{
	return mTime;
}

////////////////////////////////////////////////////////////////////////////////

void World::SetTime (int32 time)
{
	if (time < 0)
		mTime = 0;
	else
		mTime = time;
}

////////////////////////////////////////////////////////////////////////////////

void World::AddTime (int32 time)
{
	SetTime (mTime + time);
}

////////////////////////////////////////////////////////////////////////////////

Player* World::GetPlayer (void) const
{
	return mPlayer;
}

////////////////////////////////////////////////////////////////////////////////

void World::SetPlayer (Player* player)
{
	mPlayer = player;
}

////////////////////////////////////////////////////////////////////////////////

Entity* World::GetStatic (const Point& pos) const
{
	return GetStatic (pos.X, pos.Y);
}

////////////////////////////////////////////////////////////////////////////////

Entity* World::GetStatic (int32 x, int32 y) const
{
	// Check position bounds
	if (!CheckBounds (x, y))
		return NULL;

	// Return the entity
	return mStatic[x][y];
}

////////////////////////////////////////////////////////////////////////////////

bool World::SetStatic (const Point& pos, Entity* entity)
{
	return SetStatic (pos.X, pos.Y, entity);
}

////////////////////////////////////////////////////////////////////////////////

bool World::SetStatic (int32 x, int32 y, Entity* entity)
{
	// Check position bounds
	if (!CheckBounds (x, y))
		return false;

	// Delete previous entity
	if (mStatic[x][y] != NULL)
		delete mStatic[x][y];

	// Set entity and position
	mStatic[x][y] = entity;
	entity->SetPosition (x, y);

	return true;
}

////////////////////////////////////////////////////////////////////////////////

EntityList* World::GetDynamic (void) const
{
	return mDynamic;
}

////////////////////////////////////////////////////////////////////////////////

EntityList* World::GetEnemies (void) const
{
	return mEnemies;
}

////////////////////////////////////////////////////////////////////////////////

bool World::CheckBounds (const Point& pos) const
{
	// Return if the world is invalid
	if (!IsValid()) return false;

	return pos.X >= 0 && pos.X < (int32) mWidth &&
		   pos.Y >= 0 && pos.Y < (int32) mHeight;
}

////////////////////////////////////////////////////////////////////////////////

bool World::CheckBounds (int32 x, int32 y) const
{
	// Return if the world is invalid
	if (!IsValid()) return false;

	return x >= 0 && x < (int32) mWidth &&
		   y >= 0 && y < (int32) mHeight;
}

////////////////////////////////////////////////////////////////////////////////

void World::Update (uint32 elapsed)
{
	// Return if the world is invalid
	if (!IsValid()) return;

	// Update the static entity array
	for (uint32 x = 0; x < mWidth; ++x)
		for (uint32 y = 0; y < mHeight; ++y)
			if (mStatic[x][y] != NULL)
			{
				// Update the current entity
				mStatic[x][y]->Update (elapsed);

				// Check if the entity is dead,
				// If so, go ahead and remove it
				if (!mStatic[x][y]->IsAlive())
				{
					delete mStatic[x][y];
					mStatic[x][y] = NULL;
				}
			}

	EntityList::Node* node;
	EntityList::Node* temp;

	// Update the dynamic entity list
	node = mDynamic->Front();
	while (node != NULL)
	{
		// Update the current entity
		node->Value->Update (elapsed);

		// Check if the entity is dead,
		// If so, go ahead and remove it
		if (!node->Value->IsAlive())
		{
			temp = node;
			node = node->Next();

			delete temp->Value;
			mDynamic->Remove (temp);
		}

		else node = node->Next();
	}

	// Update the enemies entity list
	node = mEnemies->Front();
	while (node != NULL)
	{
		// Update the current entity
		node->Value->Update (elapsed);

		// Check if the entity is dead,
		// If so, go ahead and remove it
		if (!node->Value->IsAlive())
		{
			temp = node;
			node = node->Next();

			delete temp->Value;
			mEnemies->Remove (temp);
		}

		else node = node->Next();
	}

	// Update player entity
	mPlayer->Update (elapsed);

	// Update world time
	SetTime (mTime - elapsed);

	// Check whether to unleash doom
	if (mTime <= 0 && !mDoomed)
	{
		mDoomed = true;
		WorldBuilder::AddSmoke (this, 5);
	}
}
