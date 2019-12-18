#include <iostream>
#include "stack.hpp"

void DSAlgoTest::list::stack::push(int value)
{
	_list.insertAtFront(value);
}

void DSAlgoTest::list::stack::pop()
{
	_list.deleteElemetAtIndex(0);
}

int DSAlgoTest::list::stack::top()
{
	auto* elem = _list.findAtIndex(0);
	if (elem == nullptr) {
		throw std::out_of_range("Stack is empty");
	}
	return elem->value();
}

size_t DSAlgoTest::list::stack::size()
{
	return _list.size();
}
