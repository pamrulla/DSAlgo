#pragma once
#include "base.hpp"

namespace DSAlgo {
	template<typename T>
	class _DSALGO_API ListElement {
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

	template<typename T>
	class _DSALGO_API list {
	private:
		ListElement<T>* head;
		ListElement<T>* tail;
	public:
		list() : head(nullptr), tail(nullptr) {}

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
			while (curr->next != nullptr) {
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
		const ListElement<T>* findAtIndex(size_t index) {
			auto* temp = head;
			while (temp && index > 0) {
				--index;
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
			if (head->getNext() == nullptr) {
				tail = head;
			}
			delete temp;
		}

	};
}
