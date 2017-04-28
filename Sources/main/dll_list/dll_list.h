#ifndef _DLL_LIST_H_ 
#define _DLL_LIST_H_ 

const int kMaxData = 11;

typedef struct __node {
	int data_;
	struct __node *prev_;
	struct __node *next_;
} Node;

void _insertData(Node* new_node, Node* prev, Node* next);
void insertHeadData(Node* new_node, Node* head);
void insertTailData(Node* new_node, Node* head);
void _remove(Node* target);
void removeHead(Node* head);
void removeTail(Node* head);
Node* findTarget(Node* head, int data);
Node* findMidNode(Node* head);
void display(Node* head);

#endif //_DLL_LIST_H_ 