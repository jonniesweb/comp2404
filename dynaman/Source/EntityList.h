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

#ifndef ENTITY_LIST_H
#define ENTITY_LIST_H

class Entity;

#include "Types.h"

//----------------------------------------------------------------------------//
// Classes                                                                    //
//----------------------------------------------------------------------------//

////////////////////////////////////////////////////////////////////////////////
/// <summary> Represents a doubly linked list of entity pointer types. </summary>

class EntityList {
public:
	//----------------------------------------------------------------------------//
	// Types                                                                      //
	//----------------------------------------------------------------------------//

	////////////////////////////////////////////////////////////////////////////////
	/// <summary> Represents a single node within the list. </summary>

	class Node {
		friend class EntityList;

	private:
		//----------------------------------------------------------------------------//
		// Constructors                                                               //
		//----------------------------------------------------------------------------//

		////////////////////////////////////////////////////////////////////////////////
		/// <summary> Creates a new EntityList Node containing value. </summary>
		/// <param name="value"> The value to contain in this Node. </param>
		/// <param name="list" > The EntityList this Node belongs to. </param>

		Node(const Entity* value, EntityList* list);

	public:
		//----------------------------------------------------------------------------//
		// Functions                                                                  //
		//----------------------------------------------------------------------------//

		////////////////////////////////////////////////////////////////////////////////
		/// <summary> Gets the pointer to the previous Node in the EntityList. </summary>

		Node* Prev(void) const;

		////////////////////////////////////////////////////////////////////////////////
		/// <summary> Gets the pointer to the next Node in the EntityList. </summary>

		Node* Next(void) const;

		////////////////////////////////////////////////////////////////////////////////
		/// <summary> Gets the pointer to the list this Node belongs to. </summary>

		EntityList* List(void) const;

	public:
		//----------------------------------------------------------------------------//
		// Properties                                                                 //
		//----------------------------------------------------------------------------//

		// Properties
		Entity* Value;		// Entity pointer

	private:
		//----------------------------------------------------------------------------//
		// Fields                                                                     //
		//----------------------------------------------------------------------------//

		Node* mPrev;		// Prev node
		Node* mNext;		// Next node
		EntityList* mList;		// List this node belongs to
	};

public:
	//----------------------------------------------------------------------------//
	// Constructors                                                               //
	//----------------------------------------------------------------------------//

	////////////////////////////////////////////////////////////////////////////////
	/// <summary> Creates a new EntityList that is empty. </summary>

	EntityList(void);

	////////////////////////////////////////////////////////////////////////////////
	/// <summary> Destroys this list, removing all nodes and making it empty. </summary>
	/// <remarks> Does not delete any externally allocated dynamic memory. </remarks>
	/// <runtime> Nodes are removed linearly starting at the front; O(Count). </runtime>

	~EntityList(void);

	////////////////////////////////////////////////////////////////////////////////
	/// <summary> Creates a deep copy of the specified list. </summary>
	/// <param name="list"> Other list to copy the data from. </param>
	/// <remarks> Copying is done through the copy constructor. </remarks>
	/// <runtime> Nodes are copied linearly; O(list::Count). </runtime>

	EntityList(const EntityList& list);

public:
	//----------------------------------------------------------------------------//
	// Functions                                                                  //
	//----------------------------------------------------------------------------//

	////////////////////////////////////////////////////////////////////////////////
	/// <summary> Adds the specified value at the start of this EntityList. </summary>
	/// <param name="value"> The value to add at the start of this EntityList. </param>
	/// <returns> The newly created EntityList Node containing value. </returns>
	/// <runtime> This function performs in constant time; O(1). </runtime>

	Node* AddFront(const Entity* value);

	////////////////////////////////////////////////////////////////////////////////
	/// <summary> Adds the specified value at the end of this EntityList. </summary>
	/// <param name="value"> The value to add at the end of this EntityList. </param>
	/// <returns> The newly created EntityList Node containing value. </returns>
	/// <runtime> This function performs in constant time; O(1). </runtime>

	Node* AddBack(const Entity* value);

	////////////////////////////////////////////////////////////////////////////////
	/// <summary> Adds the specified value before the existing Node. </summary>
	/// <param name="node" > The Node before which to insert a new value. </param>
	/// <param name="value"> The value to add to this EntityList. </param>
	/// <returns> The newly created EntityList Node containing value.
	/// 		  NULL if the specified node is not part of this list. </returns>
	/// <runtime> This function performs in constant time; O(1). </runtime>

	Node* AddBefore(Node* node, const Entity* value);

	////////////////////////////////////////////////////////////////////////////////
	/// <summary> Adds the specified value after the existing Node. </summary>
	/// <param name="node" > The Node after which to insert a new value. </param>
	/// <param name="value"> The value to add to this EntityList. </param>
	/// <returns> The newly created EntityList Node containing value.
	/// 		  NULL if the specified node is not part of this list. </returns>
	/// <runtime> This function performs in constant time; O(1). </runtime>

	Node* AddAfter(Node* node, const Entity* value);

	////////////////////////////////////////////////////////////////////////////////
	/// <summary> Determines whether a value is inside this EntityList. </summary>
	/// <param name="value"> The value to locate inside this EntityList. </param>
	/// <returns> True if value has been found, false otherwise. </returns>
	/// <remarks> Comparison is done through the equals (==) operator. </remarks>
	/// <runtime> The EntityList is searched forward starting at the front.
	/// 		  This function performs a linear search; O(Count). </runtime>

	bool Contains(const Entity* value) const;

	////////////////////////////////////////////////////////////////////////////////
	/// <summary> Finds the first Node that contains the specified value. </summary>
	/// <param name="value"> The value to locate inside this EntityList. </param>
	/// <returns> The first Node that contains the value, NULL otherwise. </returns>
	/// <remarks> Comparison is done through the equals (==) operator. </remarks>
	/// <runtime> The EntityList is searched forward starting at the front.
	/// 		  This function performs a linear search; O(Count). </runtime>

	Node* FindFirst(const Entity* value) const;

	////////////////////////////////////////////////////////////////////////////////
	/// <summary> Finds the last Node that contains the specified value. </summary>
	/// <param name="value"> The value to locate inside this EntityList. </param>
	/// <returns> The last Node that contains the value, NULL otherwise. </returns>
	/// <remarks> Comparison is done through the equals (==) operator. </remarks>
	/// <runtime> The EntityList is searched backward starting at the back.
	/// 		  This function performs a linear search; O(Count). </runtime>

	Node* FindLast(const Entity* value) const;

	////////////////////////////////////////////////////////////////////////////////
	/// <summary> Removes the specified Node from this EntityList. </summary>
	/// <param name="node"> The Node to remove from this EntityList. </param>
	/// <returns> Whether or not the node was successfully removed.
	/// 		  False if the node is not part of this list. </returns>
	/// <remarks> Does not delete any externally allocated memory. </remarks>
	/// <runtime> This function performs in constant time; O(1). </runtime>

	bool Remove(Node* node);

	////////////////////////////////////////////////////////////////////////////////
	/// <summary> Removes the Node at the start of this EntityList. </summary>
	/// <returns> Whether or not the node was successfully removed.
	/// 		  Does not delete any externally allocated memory. </returns>
	/// <runtime> This function performs in constant time; O(1). </runtime>

	bool RemoveFront(void);

	////////////////////////////////////////////////////////////////////////////////
	/// <summary> Removes the Node at the end of this EntityList. </summary>
	/// <returns> Whether or not the node was successfully removed.
	/// 		  Does not delete any externally allocated memory. </returns>
	/// <runtime> This function performs in constant time; O(1). </runtime>

	bool RemoveBack(void);

	////////////////////////////////////////////////////////////////////////////////
	/// <summary> Removes the first occurrence of the specified value. </summary>
	/// <param name="value"> The value to remove from this EntityList. </param>
	/// <returns> Whether or not the node was successfully removed. </returns>
	/// <remarks> Comparison is done through the equals (==) operator.
	/// 		  Does not delete any externally allocated memory. </remarks>
	/// <runtime> The EntityList is searched forward starting at the front.
	/// 		  This function performs a linear search; O(Count). </runtime>

	bool RemoveFirst(const Entity* value);

	////////////////////////////////////////////////////////////////////////////////
	/// <summary> Removes the last occurrence of the specified value. </summary>
	/// <param name="value"> The value to remove from this EntityList. </param>
	/// <returns> Whether or not the node was successfully removed. </returns>
	/// <remarks> Comparison is done through the equals (==) operator.
	/// 		  Does not delete any externally allocated memory. </remarks>
	/// <runtime> The EntityList is searched backward starting at the back.
	/// 		  This function performs a linear search; O(Count). </runtime>

	bool RemoveLast(const Entity* value);

	////////////////////////////////////////////////////////////////////////////////
	/// <summary> Removes all occurrences of the specified value. </summary>
	/// <param name="value"> The value to remove from this EntityList. </param>
	/// <returns> The total number of Nodes that were removed. </returns>
	/// <remarks> Comparison is done through the equals (==) operator.
	/// 		  Does not delete any externally allocated memory. </remarks>
	/// <runtime> The EntityList is searched forward starting at the front.
	/// 		  This function performs a linear search; O(Count). </runtime>

	uint32 RemoveAll(const Entity* value);

	////////////////////////////////////////////////////////////////////////////////
	/// <summary> Removes all nodes from this EntityList, leaving it empty. </summary>
	/// <remarks> Does not delete any externally allocated dynamic memory. </remarks>
	/// <runtime> Nodes are removed linearly starting at the front; O(Count). </runtime>

	void Clear(void);

	////////////////////////////////////////////////////////////////////////////////
	/// <summary> Gets the pointer to the first Node in this EntityList. </summary>
	/// <runtime> Retrieving this value is done in constant time; O(1). </runtime>

	Node* Front(void) const;

	////////////////////////////////////////////////////////////////////////////////
	/// <summary> Gets the pointer to the last Node in this EntityList. </summary>
	/// <runtime> Retrieving this value is done in constant time; O(1). </runtime>

	Node* Back(void) const;

	////////////////////////////////////////////////////////////////////////////////
	/// <summary> Checks whether this EntityList is empty. </summary>
	/// <returns> Whether or not this EntityList is empty. </returns>
	/// <runtime> Retrieving this value is done in constant time; O(1). </runtime>

	bool IsEmpty(void) const;

	////////////////////////////////////////////////////////////////////////////////
	/// <summary> Gets the number of items contained in this EntityList. </summary>
	/// <runtime> Retrieving this value is done in constant time; O(1). </runtime>

	uint32 Count(void) const;

	////////////////////////////////////////////////////////////////////////////////
	/// <summary> Gets the number of occurrences of the specified value. </summary>
	/// <param name="value"> The value to count the occurrences of. </param>
	/// <returns> The total number of occurrences of the specified value. </returns>
	/// <remarks> Comparison is done through the equals (==) operator. </remarks>
	/// <runtime> The EntityList is searched forward starting at the front.
	/// 		  This function performs a linear search; O(Count). </runtime>

	uint32 Count(const Entity* value) const;

public:
	//----------------------------------------------------------------------------//
	// Operators                                                                  //
	//----------------------------------------------------------------------------//

	////////////////////////////////////////////////////////////////////////////////
	/// <summary> Returns a pointer to the Node at the specified index. </summary>
	/// <param name="index"> The zero based index of the node to return. </param>
	/// <returns> A pointer to the Node at the specified index. </returns>
	/// <runtime> The EntityList is searched forward starting at the front or
	/// 		  backward starting at the back depending on which is faster.
	/// 		  This function performs a linear search; O(Count). </runtime>

	Node* operator [](uint32 index) const;

	////////////////////////////////////////////////////////////////////////////////
	/// <summary> Checks whether this EntityList is equal to another. </summary>
	/// <param name="list"> The EntityList to compare this EntityList with. </param>
	/// <returns> Whether or not this EntityList is equal to another. </returns>
	/// <runtime> This function performs a linear comparison; O(Count). </runtime>

	bool operator ==(const EntityList& list) const;

	////////////////////////////////////////////////////////////////////////////////
	/// <summary> Checks whether this EntityList is not equal to another. </summary>
	/// <param name="list"> The EntityList to compare this EntityList with. </param>
	/// <returns> Whether or not this EntityList is not equal to another. </returns>
	/// <runtime> This function performs a linear comparison; O(Count). </runtime>

	bool operator !=(const EntityList& list) const;

private:
	//----------------------------------------------------------------------------//
	// Fields                                                                     //
	//----------------------------------------------------------------------------//

	Node* mHead;		// First node in this list
	Node* mTail;		// Last  node in this list
	uint32 mSize;		// Total number of items
};

#endif // ENTITY_LIST_H
