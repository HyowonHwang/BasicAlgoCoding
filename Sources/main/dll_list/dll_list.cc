#include <iostream>
#include "dll_list.h"

void _insertData(Node* new_node, Node* prev, Node* next) {
	prev->next_ = new_node;
	new_node->prev_ = prev;
	next->prev_ = new_node;
	new_node->next_ = next;
}

void insertHeadData(Node* new_node, Node* head) {
	_insertData(new_node, head, head->next_);
}

void insertTailData(Node* new_node, Node* head) {
	_insertData(new_node, head->prev_, head);
}

void _remove(Node* target) {
	target->prev_->next_ = target->next_;
	target->next_->prev_ = target->prev_;
}

void removeHead(Node* head) {
	_remove(head->next_);
}
void removeTail(Node* head) {
	_remove(head->prev_);
}

Node* findTarget(Node* head, int data) {
	Node* cursor = head->next_;
	for (cursor = head->next_; cursor != head; cursor = cursor->next_) {
		if (cursor->data_ == data)
			return cursor;
	}
	return nullptr;
}

Node* findMidNode(Node* head) {
	Node* normalRunner = head->next_;
	Node* fastRunner = head->next_;

	while (fastRunner->next_ != head && 
		fastRunner->next_->next_ != head) {

		normalRunner = normalRunner->next_;
		fastRunner = fastRunner->next_->next_;
	}
	return normalRunner;
}

void display(Node* head) {
	Node* cursor;
	std::cout << "[HEAD]";
	for (cursor = head->next_; cursor != head; cursor = cursor->next_) {
		std::cout << "->[" << cursor->data_ << "]";
	}
	std::cout << std::endl;
}

