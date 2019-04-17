#ifndef SLL_Header_h
#define SLL_Header_h
#include <cstring>

struct Node
{
	char name;				// name 저장 변수
	int ID;					// ID 저장 변수
	char major[10];				// major 저장 변수
	char grade;				// grade 저장 변수
	Node *next;				// 다음 node 가리키는 node 포인터
};

struct  List{ 		/* 연결 리스트 관리 구조체 */
	Node *head;		/* head pointer (head node 가리킴) */
	Node *tail; 		/* tail pointer (tail node 가리킴) */
	int size;		/* 연결 리스트의 크기 - 실제 data node의 개수 */
};

bool createList(List *lp);
bool AddLast(List *lp, char name, int ID, char major[10], char grade);
void displayList(List *lp);
void displayList2(List *lp, char);
void displayList3(List *lp, char[]);
void sortList(List *lp);
void destroyList(List *lp);
void combineList(List *lp, List *lp2);

#endif