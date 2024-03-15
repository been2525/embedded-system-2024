#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
	int data;
	struct NODE* next;
}node;

typedef struct
{
	node *head;
}headNode;

headNode* createHeadNode(void)
{
	node* head = (node*)malloc(sizeof(node));
	head -> next = NULL;
}

void pre_addNode(node* pnode, int _data)									//전위삽입
{
	node* newNode = (node*)malloc(sizeof(node)); 
	newNode -> data = _data;
	newNode->next = pnode->next;
	pnode->next = newNode;
	
}
void rear_addNode(node* pnode, int _data)									//후윕삽입
{
	node* newNode = (node*)malloc(sizeof(node));
	newNode -> data = _data;
	newNode->next = NULL;
	node*curr=pnode;
	while(curr -> next != NULL)
	{
		curr  = curr -> next;
	}
	curr -> next = newNode;
}
void showNode(node* pnode)					//출력함수
{
	node * show = pnode->next;
	int i = 1;
	while( show != NULL)
	{
		printf("%d번째 값 : %d\n", i ,show->data);
		show = show -> next;
		i++;
	}
}
void allFreeNode(node* pnode)
{
	node* curr = pnode -> next ;
	while(curr != NULL)
	{
		node* del = curr;
		curr = curr -> next;
		free(del);
		printf("동적할당해제\n");
	}
	pnode -> next = NULL;
	printf("%d, %d\n", pnode -> next, curr);
	free(pnode);
}

void main()
{
	node* head = (node*)malloc(sizeof(node));
	head -> next = NULL;

	pre_addNode(head, 10);						// 첫번째 노드로 삽입
	pre_addNode(head, 20);
	pre_addNode(head, 30);
	
	rear_addNode(head, 10);
	rear_addNode(head, 20);
	rear_addNode(head, 30);

	showNode(head);




	node* curr = head->next;
	while(curr != NULL)
	{
		printf("%d\n", curr->data);
		curr = curr->next;
	}
//	curr = head -> next;
//	node* del;
	// head -> next = null;내가 만든  코딩대로 할려면 null  값을 넣어줘야함
/*
	while(curr != NULL)
	{
		del = curr;
		curr = curr->next;
		free(del);
		printf("동적할당해제\n");
	}
	free(head); // head를 해제시키는것 head도 동적할당 했기 때문이다.
	*/
	/*
	curr = head->next;
	while(curr!= NULL)
	{
		head->next = curr->next;
		free(curr);
		curr = head->next;
	}
	*/
	allFreeNode(head);
}

