#pragma once
#include <iostream>

namespace DSAlgo {
	template<typename T = int>
	class ListElement {
	private:
		ListElement* next;
		T data;
	public:
		ListElement(const T& value) : next(nullptr), data(value) {}

		ListElement* getNext() const { return next; }
		const T& value() const { return data; }
		void setNext(ListElement* elem) { next = elem; }
		void setValue(const T& value) { data = value; }
	};

	template<typename T = int>
	class list {
	private:
		ListElement<T>* head;
		ListElement<T>* tail;
	public:
		list() : head(nullptr), tail(nullptr) {}
		~list() { deleteList(); }

		void insertAtFront(const T& data) {
			ListElement<T>* elem = new ListElement<T>(data);
			if (head != nullptr) {
				elem->setNext(head);
			}
			else {
				tail = elem;
			}
			head = elem;
		}

		void insertAtEnd(const T& data) {
			ListElement<T>* curr = head;
			ListElement<T>* newElem = new ListElement<T>(data);
			if (curr == nullptr) {
				head = newElem;
				tail = newElem;
				return;
			}
			while (curr->getNext() != nullptr) {
				curr = curr->getNext();
			}
			curr->setNext(newElem);
			tail = newElem;
		}

		const ListElement<T>* find(T data) {
			ListElement<T>* temp = head;
			while (temp && temp->value() != data) {
				temp = temp->getNext();
			}
			return temp;
		}

		void deleteElement(ListElement<T>* elem) {
			if (elem == nullptr) {
				return;
			}
			ListElement<T>* temp = head;
			ListElement<T>* prev = nullptr;
			while (temp && temp != elem) {
				prev = temp;
				temp = temp->getNext();
			}

			if (temp == nullptr) {
				return;
			}

			if (prev != nullptr) {
				prev->setNext(temp->getNext());
				if (prev->getNext() == nullptr) {
					tail = prev;
				}
			}
			else {
				head = temp->getNext();
			}
			if (head->getNext() == nullptr) {
				tail = head;
			}
			delete temp;
		}

		void deleteList() {
			ListElement<T>* temp = head;
			while (temp) {
				head = temp->getNext();
				delete temp;
				temp = head;
			}
			head = nullptr;
			tail = nullptr;
		}

		size_t size() {
			size_t len = 0;
			auto* temp = head;
			while (temp) {
				len++;
				temp = temp->getNext();
			}
			return len;
		}

		//Index wise operations
		ListElement<T>* findAtIndex(size_t index) {
			auto* temp = head;
			if (index == 0) {
				return temp;
			}
			while (temp && --index > 0) {
				temp = temp->getNext();
			}
			return temp;
		}

		const ListElement<T>* findAtIndex(size_t index) const{
			auto* temp = head;
			if (index == 0) {
				return temp;
			}
			while (temp && --index > 0) {
				temp = temp->getNext();
			}
			return temp;
		}

		void deleteElemetAtIndex(size_t index) {
			ListElement<T>* temp = head;
			ListElement<T>* prev = nullptr;
			while (temp && index > 0) {
				prev = temp;
				temp = temp->getNext();
				--index;
			}

			if (temp == nullptr) {
				return;
			}

			if (prev != nullptr) {
				prev->setNext(temp->getNext());
				if (prev->getNext() == nullptr) {
					tail = prev;
				}
			}
			else {
				head = temp->getNext();
			}
			if (head != nullptr && head->getNext() == nullptr) {
				tail = head;
			}
			delete temp;
		}

		// Mth-to-Last Element of a Linked List
		/*
		PROBLEM Given a singly linked list, devise a time - and space - efficient algorithm
		to find the mth - to - last element of the list.Implement your algorithm, taking care
		to handle relevant error conditions.Define mth to last such that when m = 0 the
		last element of the list is returned.
		*/
		T mth_to_last_element(int m) {
			if (m < 0) {
				throw std::invalid_argument("Mth value should not be negative");
			}
			size_t len = size();
			if (m > len) {
				throw std::invalid_argument("Mth value should not be more than list size");
			}
			m = len - m;
			auto* res = findAtIndex(m);
			return res->value();
		}

		//Above method traverses list multiple times.
		//This proposed method traverses only once
		T mth_to_last_element_2(int m) {
			auto* current = head;
			auto* mBehind = head;
			if (m < 0) {
				throw std::invalid_argument("Mth value should not be negative");
			}
			if (head == nullptr) {
				throw std::out_of_range("List is empty");
			}
			for (auto i = 1; i < m; ++i) {
				if (current->getNext()) {
					current = current->getNext();
				}
				else {
					throw std::out_of_range("List is small");
				}
			}

			while (current->getNext()) {
				mBehind = mBehind->getNext();
				current = current->getNext();
			}
			return mBehind->value();
		}

		//Null or Cycle
		/*
			You are given a linked list with at least one node that is either nullterminated
			(acyclic), as shown in Figure 4-5, or ends in a cycle (cyclic),
			Write a function that takes a pointer to the head of a list and determines whether
			the list is cyclic or acyclic. Your function should return false if the list is acyclic
			and true if it is cyclic. You may not modify the list in any way.
		*/
		bool isCyclic() {
			if (head == nullptr || head->getNext() == nullptr) {
				return false;
			}
			auto* slow = head;
			auto* fast = head->getNext();
			while (fast->getNext() && fast->getNext()->getNext() && slow->getNext()) {
				fast = fast->getNext()->getNext();
				slow = slow->getNext();
				if (fast == slow) {
					return true;
				}
			}
			return false;
		}
	};
}
