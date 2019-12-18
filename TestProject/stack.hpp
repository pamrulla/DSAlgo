#pragma once
#include "list.hpp"
/*PROBLEM Discuss the stack data structure. Implement a stack in C using either
 *a linked list or a dynamic array, and justify your decision. Design the interface to
 *your stack to be complete, consistent, and easy to use.
*/
namespace DSAlgoTest{
	namespace list {
		class stack {
		private:
			DSAlgo::list<> _list;

		public:
			stack() : _list() {}
			~stack() {
				_list.deleteList();
			}

			void push(int value);
			void pop();
			int top();
			size_t size();
		};
	}
}