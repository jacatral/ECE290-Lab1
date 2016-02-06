#ifndef DEQUE_AS_ARRAY_H
#define DEQUE_AS_ARRAY_H

/******************************************
 * UW User ID:  jacatral
 * Submitted for ECE 250
 * Semester of Submission:  (Winter) 2016
 *
 * By submitting this file, I affirm that
 * I am the author of all modifications to
 * the provided  code.
 ******************************************/

// Added in for Visual Studio, remove for final submission
#include <algorithm>

#include "Exception.h"


class Deque_as_array {
	private:
		int array_size;
		int*array;
		int ihead;
		int itail;
		int count;

	public:
		Deque_as_array( int = 10 );
		~Deque_as_array();

		int head() const;
		int tail() const;
		int size() const;
		bool empty() const;
		int capacity() const;

		void enqueue_head( int const & );
		void enqueue_tail( int const & );
		int dequeue_head();
		int dequeue_tail();
		void clear();

	
};

 
Deque_as_array::Deque_as_array(int n) :
array_size(std::max(1, n)),
array(new int[array_size]),
// Set up initial values head&tail index when building the dequeue
ihead(1),
itail(0),
count( 0 ) {
	// empty
}

 
Deque_as_array::~Deque_as_array() {
	// * Simply delete the array to avoid memory leaks
	delete [] array;
}

 
int Deque_as_array::size() const {
	// * Use the count integer to keep check of the deque size
	return count;
}

 
int Deque_as_array::capacity() const {
	return array_size;
}

 
bool Deque_as_array::empty() const {
	// * If the count is still 0, then the deque is empty
	return (count == 0);
}

 
int Deque_as_array::head() const {
	// * The head has an internal pointer, but return an error if the deque is empty
	if (empty()) {
		throw underflow();
	}
	return (array[ihead]);     // This returns a default object
}

 
int Deque_as_array::tail() const {
	// * Similar case as with the head, we have a pointer to the end of the array
	// If the deque is empty, throw an underflow
	if (empty()) {
		throw underflow();
	}
	return (array[itail]);     // This returns a default object
}


void Deque_as_array::enqueue_head(int const &obj) {
	// * Avoid adding to the array if it has reached it capacity
	if (size() == capacity()) {
		throw overflow();
	}
	// To add to the start of the array, we'll move the head pointer back
	ihead--;
	if (ihead < 0) { // Avoid heading into the negatives as we step back
		ihead = ihead + capacity();
	}
	array[ihead] = obj;
	count++;
}


void Deque_as_array::enqueue_tail( int const &obj ) {
	// enter your implementation here
	// * Avoid adding to the array if it has reached it capacity
	if (size() == capacity()) {
		throw overflow();
	}
	// To add to the end of the array, we'll move the tail pointer ahead
	itail++;
	if (itail >= capacity()) {
		itail = itail - capacity();
	}
	array[itail] = obj;
	count++;
}

 
int Deque_as_array::dequeue_head() {
	// * Avoid removal if there is nothing to remove in the dequeue
	if (empty()) {
		throw underflow();
	}
	// Assuming we are returning the head element, we need to put it in a temporary variable
	int tmp = array[ihead];
	// When we remove the head element, lets just move the head pointer to what's in front of it
	ihead++;
	if (ihead >= capacity()) {
		ihead = ihead - capacity();
	}
	count--;
	return tmp;     // This returns a default object (0)
}

 
int Deque_as_array::dequeue_tail() {
	// * Avoid removal if there is nothing to remove in the dequeue
	if (empty()) {
		throw underflow();
	}
	// Assuming we are returning the tail element, we need to put it in a temporary variable
	int tmp = array[itail];
	// When we remove the tail element, lets just move the tail pointer to what's behind it
	itail--;
	if (itail < 0) { // Avoid heading into the negatives as we step back
		itail = itail + capacity();
	}
	count--;
	return tmp;     // This returns a default object (0)
}

 
void Deque_as_array::clear() {
	// * Simply reset the count and the head/tail location
	count = 0;
	ihead = 1;
	itail = 0;
}



// Is an error showing up in ece250.h or elsewhere?
// Did you forget a closing '}' ?

#endif
