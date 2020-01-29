#pragma once
#include <iostream>
#include <vector>

namespace DSAlgo {
	template<typename T=int>
	class Node {
	private:
		T data;
		Node<T>* left;
		Node<T>* right;
	public:
		Node(T value) : data(value), left(nullptr), right(nullptr) {}
		
		void setData(T value) {
			data = value;
		}

		const T& getData() const {
			return data;
		}

		void setLeft(Node<T>* node) {
			left = node;
		}

		Node<T>* getLeft() {
			return left;
		}

		void setRight(Node<T>* node) {
			right = node;
		}

		Node<T>* getRight() {
			return right;
		}
	};

	template<typename T=int>
	class bst {
	private:
		Node<T>* root;

		Node<T>* _insert(Node<T>* curr, T data) {
			if (curr == nullptr) {
				return new Node<T>(data);
			}
			if (data <= curr->getData()) {
				curr->setLeft(_insert(curr->getLeft(), data));
			}
			else {
				curr->setRight(_insert(curr->getRight(), data));
			}
			return curr;
		}

		void _delete(Node<T>* curr) {
			if (curr == nullptr) {
				return;
			}
			_delete(curr->getLeft());
			_delete(curr->getRight());
			delete curr;
		}

		void _inorder(std::vector<T>& out_vec, Node<T>* curr) {
			if (curr == nullptr) {
				return;
			}
			_inorder(out_vec, curr->getLeft());
			out_vec.push_back(curr->getData());
			_inorder(out_vec, curr->getRight());
		}

		void _preorder(std::vector<T>& out_vec, Node<T>* curr) {
			if (curr == nullptr) {
				return;
			}
			out_vec.push_back(curr->getData());
			_preorder(out_vec, curr->getLeft());
			_preorder(out_vec, curr->getRight());
		}

		void _postorder(std::vector<T>& out_vec, Node<T>* curr) {
			if (curr == nullptr) {
				return;
			}
			_postorder(out_vec, curr->getLeft());
			_postorder(out_vec, curr->getRight());
			out_vec.push_back(curr->getData());
		}

		size_t _getHeight(Node<T>* curr) {
			if (curr == nullptr) {
				return 0;
			}
			size_t leftCount = _getHeight(curr->getLeft());
			size_t rightCount = _getHeight(curr->getRight());

			return (leftCount > rightCount ? leftCount : rightCount) + 1;
		}

		T _getMax(Node<T>* curr) {
			if (curr->getRight() == nullptr) {
				return curr->getData();
			}
			_getMax(curr->getRight());
		}
		
		T _getMin(Node<T>* curr) {
			if (curr->getLeft() == nullptr) {
				return curr->getData();
			}
			_getMin(curr->getLeft());
		}

	public:
		bst() : root(nullptr) {}
		~bst() {
			_delete(root);
		}

		void insert(T data) {
			root = _insert(root, data);
		}

		void inorder(std::vector<T>& out_vec) {
			out_vec.clear();
			_inorder(out_vec, root);
		}

		void preorder(std::vector<T>& out_vec) {
			out_vec.clear();
			_preorder(out_vec, root);
		}

		void postorder(std::vector<T>& out_vec) {
			out_vec.clear();
			_postorder(out_vec, root);
		}

		size_t getHeight() {
			return _getHeight(root);
		}

		T getMax() {
			return _getMax(root);
		}

		T getMin() {
			return _getMin(root);
		}

		//TODO heapify
		//TODO unbalanced to balanced
	};
}
