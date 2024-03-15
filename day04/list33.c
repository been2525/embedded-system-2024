#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
	int data;
	struct NODE* next;
}node;

typedef struct
{
	node* head;
}headNode;

headNode* createHeadNode(void)
{
	headNode* newhead = (headNode*)malloc(sizeof(headNode));
	newhead -> head = NULL;		//헤드노드 초기화
	return newhead;	
}

void pre_addNode(headNode* pnode, int _data)								
{
	node* newNode = (node*)malloc(sizeof(node)); 
	newNode -> data = _data;
	newNode->next = pnode-> head;
	pnode->head = newNode;
}
void rear_addNode(headNode* pnode, int _data)
{
	node* newNode = (node*)malloc(sizeof(node));
	newNode -> data = _data;
	newNode -> next = NULL;
	node*curr = pnode -> head;
	while(curr -> next != NULL)
	{
		curr = curr -> next;
	}
	curr -> next = newNode;
}
void showNode(headNode* pnode)
{
	node * show = pnode -> head;
	int i = 1;
	while(show != NULL)
	{
		printf("%d번째값 : %d\n", i, show -> data);
		show = show -> next;
		i++;
	}	
}
void allFreeNode(headNode * pnode)
{
	node* curr = pnode -> head;
	while(curr != NULL)
	{
		node* del = curr;
		curr = curr -> next;
		free(del);
		printf("동적할당해제\n");
	}
	pnode -> head = NULL;
	printf("%d, %d\n", pnode -> head, curr);
	free(pnode);
}

void main()
{
	headNode* newhead = createHeadNode();
	pre_addNode(newhead, 10);						// 첫번째 노드로 삽입
	pre_addNode(newhead, 20);
	pre_addNode(newhead, 30);

	rear_addNode(newhead, 10);
	rear_addNode(newhead, 20);
	rear_addNode(newhead, 30);

	showNode(newhead);

	node* curr = newhead -> head;

	while(curr != NULL)
	{
		printf("%d\n", curr -> data);
		curr = curr -> next;
	}

	allFreeNode(newhead);
}
