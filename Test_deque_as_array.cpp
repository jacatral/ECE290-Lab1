#include <iostream>
#include <cassert>
#include "Deque_as_array.h"

int main() {
	std::cout << "Starting test run" << std::endl;
	// Create an deque of 10 ints
	Deque_as_array a;
	assert(a.capacity() == 10);
	assert(a.size() == 0);
	assert(a.empty() == true);
	// Fill by enqueuing the head
	for (int i = 0; i < 10; i++) {
		assert(a.size() == i);
		a.enqueue_head(i);
		assert(a.empty() == false);
		assert(a.head() == i);
	}
	assert(a.size() == 10);
	// Dequeue everything from the head
	for (int i = 9; i >= 0; i--) {
		assert(a.dequeue_head() == i);
		assert(a.size() == i);
	}
	assert(a.empty() == true);
	// Fill by enqueuing the tail
	for (int i = 0; i < 10; i++) {
		assert(a.size() == i);
		a.enqueue_tail(i);
		assert(a.empty() == false);
		assert(a.tail() == i);
	}
	assert(a.size() == 10);
	// Dequeue everything from the tail
	for (int i = 9; i >= 0; i--) {
		assert(a.dequeue_tail() == i);
		assert(a.size() == i);
	}
	assert(a.empty() == true);
	// Do a mix of both enqueuing
	for (int i = 0; i < 5; i++) {
		assert(a.size() == i);
		a.enqueue_head(i);
		assert(a.empty() == false);
		assert(a.head() == i);
	}
	for (int i = 5; i < 10; i++) {
		assert(a.size() == i);
		a.enqueue_tail(i);
		assert(a.empty() == false);
		assert(a.tail() == i);
	}
	// And then clear everything
	a.clear();
	assert(a.empty() == true);

	// Create an deque with inproper input (should default to a size 1 array)
	Deque_as_array b(-1);
	assert(b.capacity() == 1);
	assert(b.size() == 0);
	assert(b.empty() == true);
	// Test that we are working with only one element (both head & tail should point to it)
	b.enqueue_head(0);
	assert(b.size() == 1);
	assert(b.head() == 0);
	assert(b.head() == b.tail());
	assert(b.head() == b.dequeue_tail());
	// After the dequeue the content should be empty
	assert(b.empty() == true);
	// Reverse our queuing to confirm it works both ways
	b.enqueue_tail(1);
	assert(b.size() == 1);
	assert(b.tail() == 1);
	assert(b.head() == b.tail());
	assert(b.tail() == b.dequeue_head());
	b.enqueue_head(2);
	assert(b.tail() == 2);
	assert(b.size() == 1);
	assert(b.head() == b.tail());
	b.clear();
	assert(b.empty() == true);
	
	// Create a deque with proper input this time
	Deque_as_array c(5);
	assert(c.capacity() == 5);
	assert(c.size() == 0);
	assert(c.empty() == true);
	// Fill by enqueuing the head
	for (int i = 0; i < 5; i++) {
		assert(c.size() == i);
		c.enqueue_head(i);
		assert(c.empty() == false);
		assert(c.head() == i);
	}
	assert(c.size() == 5);
	// Dequeue everything from the head
	for (int i = 4; i >= 0; i--) {
		assert(c.dequeue_head() == i);
		assert(c.size() == i);
	}
	assert(c.empty() == true);
	// Fill by enqueuing the tail
	for (int i = 0; i < 5; i++) {
		assert(c.size() == i);
		c.enqueue_tail(i);
		assert(c.empty() == false);
		assert(c.tail() == i);
	}
	assert(c.size() == 5);
	// Dequeue everything from the tail
	for (int i = 4; i >= 0; i--) {
		assert(c.dequeue_tail() == i);
		assert(c.size() == i);
	}
	assert(c.empty() == true);
	// Do a mix of both enqueuing
	for (int i = 0; i < 2; i++) {
		assert(c.size() == i);
		c.enqueue_head(i);
		assert(c.empty() == false);
		assert(c.head() == i);
	}
	for (int i = 2; i < 5; i++) {
		assert(c.size() == i);
		c.enqueue_tail(i);
		assert(c.empty() == false);
		assert(c.tail() == i);
	}
	// And then clear everything
	c.clear();
	assert(c.empty() == true);

	// End of file
	std::cout << "Finished test run" << std::endl;
	return 0;
}
