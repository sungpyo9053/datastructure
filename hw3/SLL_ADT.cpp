#include "SLL_header.h"

using namespace std;

/*--------------------------------------------------------------------------------------
Function name : createList - 리스트 관리 구조체을 생성함
Parameters : List*
Returns	 : true(리스트 관리 구조체 생성시),false(생성 실패시)
--------------------------------------------------------------------------------------*/
bool createList(List *lp)
{
	if (lp == NULL)			// 리스트 관리구조체 생성 실패시
	{
		return false;
	}  // 안전장치
	
	lp->head = new Node;	// 새로운 노드를 동적 할당하여 그곳에 관리구조체의 head 
                                     
	
	if (lp->head == NULL)	// head 노드를 가리키는 노드 생성 실패시
	{
		return false;
	}  // 안전장치

	lp->tail = new Node;	// 새로운 노드를 동적 할당하여 그곳에 관리구조체의 tail 
                                    //  포인터로 가리킴
	if (lp->tail == NULL)	// tail 노드를 가리키는 노드 생성 실패시
	{
		delete lp->head;
		return false;
	}  // 안전장치

	lp->head->next = lp->tail;  // head 노드의 next 값을 tail노드를 가리킴
	lp->tail->next = lp->tail;  // tail 노드의 next 값을 tail노드를 가리켜 tail 노드에서 
                                        // 순환하도록 만듬
	lp->size = 0;				// 연결리스트크기 0으로 초기화

	return true;				// 리스트 생성 성공시 true 리턴 
}
/*--------------------------------------------------------------------------------------
Function name : AddLast - 리스트 끝부분(tail 노드) 앞에부터 리스트 연결
Parameters : List* , char, int, char[] ,char
Returns	: true(노드 추가 성공),false(노드 추가 실패)
--------------------------------------------------------------------------------------*/
bool AddLast(List *lp,char name,int ID, char major[10],char grade)
{
	Node *newNode;			// 새로운 노드 생성을 위한 Node 포인터변수
	Node *curP;			// 현재 노드의 위치를 표현하기 위한 temp 변수
	
	if (lp == NULL)
	{
		return false;
	} //안전장치

	newNode = new Node;		// 새로운 노드 동적할당
	curP = lp->head;		// current point는 헤드 노드의 주소값으로 초기화

	if (newNode != NULL){	// 새로운 노드가 제대로 추가됬을시
		while (1)		// tail 노드의 앞 노드까지 currnet point를 옮김
		{
			if (curP->next != lp->tail)
			{
				curP = curP->next;
			}
			else { break; }
		} 
		
		newNode->name = name;  
		newNode->ID = ID;
		strcpy(newNode->major,major);
		newNode->grade = grade;

		newNode->next = lp->tail;		// 새로운 노드의 next 값을 tail노드로 연결
		curP->next = newNode;		// 새로운 노드 추가전에 있던 tail 
                                                   // 노드 앞 노드를 새로운 노드에 연결
		++lp->size;		// 새로운 노드가 추가되었으니 리스트 size를 up

		return true;		// 새로운 노드가 제대로 추가됬을때
	}
	else		
	{
		return false;
	}

}








/*--------------------------------------------------------------------------------------
Function name : sortList - 리스트를 name 값으로 오름차순으로 정렬
Parameters : List*
Returns	 : 없음
--------------------------------------------------------------------------------------*/
void sortList(List *lp)
{
	Node* cp = lp->head->next;	// current pointer
	Node* tp;			// temp pointer
	
	char tempName,tempGrade;		// swap 해주기 위한 임시변수
	int tempID;			// swap 해주기 위한 임시변수
	char tempMajor[10];		// swap 해주기 위한 임시변수

	if (lp == NULL)
	{
		return;
	}	// 안전장치

	while (cp->next != lp->tail)	// current pointer 가 tail노드 직전까지
	{
		tp = cp->next;
		
		while (tp != lp->tail) // tp가 tail node에 있으면 반복문 종료
		{
			if (cp->name > tp->name)	// current 노드의 name값이 temp 노드 
						// name값보다 클때 swap
			{
				tempName = cp->name;
				tempGrade = cp->grade;
				tempID = cp->ID;
				strcpy(tempMajor, cp->major);
				cp->name = tp->name;
				cp->grade = tp->grade;
				cp->ID = tp->ID;
				strcpy(cp->major, tp->major);
				tp->name = tempName;
				tp->grade = tempGrade;
				tp->ID = tempID;
				strcpy(tp->major, tempMajor);    // 데이터	swap 완료
			}
			tp = tp->next;
		}
		cp = cp->next;
	}
	return;
}








/*--------------------------------------------------------------------------------------
Function name : displayList - 리스트를 순차적으로 출력
Parameters : List*
Returns	 : 없음
--------------------------------------------------------------------------------------*/
void displayList(List *lp)
{
	Node *tp;
	if (lp == NULL)
	{
		return;
	} // 안전장치
	
	tp = lp->head->next;	//head 포인터가 가리키는 값부터
	
	for (int i = 0; i<lp->size; i++)		// list의 size만큼
	{
		cout << tp->name << ' ' << tp->ID << ' ' << tp->major << ' ' << tp->grade << ' ' << endl;  // 데이터 출력
		tp = tp->next;	// 다음 노드 진행
	}
	return;
}

/*--------------------------------------------------------------------------------------
Function name : displayList2 - 주어진 Grade 값을 가지는 리스트를 순차적으로 출력(문제 2)
Parameters : List*, char grade(성적값)
Returns	 : 없음
--------------------------------------------------------------------------------------*/
void displayList2(List *lp,char grade)
{
	Node *tp;
	if (lp == NULL)
	{
		return;
	}
	tp = lp->head->next;	//head 포인터가 가리키는 값부터
	for (int i = 0; i<lp->size; i++)	
	{
		if (tp->grade == grade)		//grade 값이랑 노드의 grade 같이 같을때 출력
			cout << tp->name << ' ' << tp->ID << ' ' << tp->major << ' ' << tp->grade << ' ' << endl;
		tp = tp->next;
	}
	return;
}


/*--------------------------------------------------------------------------------------
Function name : displayList3 - 주어진 major 값을 가지는 리스트를 순차적으로 출력(문제 3)
Parameters : List*, char major[](전공)
Returns	 : 없음
--------------------------------------------------------------------------------------*/
void displayList3(List *lp, char major[])
{
	Node *tp;
	if (lp == NULL)
	{
		return;
	}
	tp = lp->head->next;	//head 포인터가 가리키는 값부터
	for (int i = 0; i<lp->size; i++)
	{
		if (strcmp(tp->major,major)==0)	//major 값이랑 노드의 grade 같이 같을때 출력
			cout << tp->name << ' ' << tp->ID << ' ' << tp->major << ' ' << tp->grade << ' ' << endl;
		tp = tp->next;
	}
	return;
}

/*--------------------------------------------------------------------------------------
Function name : combineList - list1 과 list2 를 병합 (문제 3)
Parameters : List*, List*
Returns	 : 없음
--------------------------------------------------------------------------------------*/
void combineList(List *lp, List *lp2)
{
	Node *temp = lp2->head->next;  // list 2의 head 포인터가 가리키는 노드지칭
	
	if (lp == NULL || lp2 == NULL)
		return; // 안전장치

	while (temp->next != lp2->tail)
	{	
		temp = temp->next;
	}				// lp2 에서 tail노드 직전 노드 탐색
	temp->next = lp->tail;	// lp2 에서 tail노드 직전 노드를 lp 의 tail노드에 연결
	
	temp = lp->head->next;		// lp 의 head 포인터가 가리키는 노드지칭
	
	while (temp->next != lp->tail)
	{
		temp = temp->next;
	}				// lp 에서 tail노드 직전 노드 탐색
	temp->next = lp2->head->next;	// lp에서 tail노드 직전 노드를 lp2의 head노드 다음 
                                          // 노드로 연결
	lp->size += lp2->size;		// lp의 size값과  lp2의 size 값을 합침

	delete lp2->head;		// lp2의 head 노드 해제
	delete lp2->tail;		// lp2 의 tail 노드 해제
	lp2->size = 0;		// lp2 의 size 값 초기화

	return;
}

/*--------------------------------------------------------------------------------------
Function name : destroyList - 리스트 해제함수
Parameters : List*
Returns	: 없음
--------------------------------------------------------------------------------------*/
void destroyList(List *lp)
{
	Node *destroyP;				//Destroy Point
	if (lp == NULL)
	{
		return;
	}
	while (lp->head->next != lp->tail)
	{
		destroyP = lp->head->next;	// destroy point는 항상 head 다음 노드
		lp->head->next = destroyP->next;	   
 // head 노드의 다음 포인터를 destroy point 다음의 노드를 가리킴
		delete destroyP;			// destroy point가 있는 노드 해제
		--lp->size;								// size -1
	}
	delete lp->tail;				// lp 의 head 노드 해제
	delete lp->head;				// lp 의 tail 노드 해제
	lp->size = 0;				// lp 의 size 초기화

	return;
}
