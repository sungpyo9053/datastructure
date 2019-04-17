#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "SLL_header.h"
#include "SLL_ADT.cpp"
// #include "SLL_ADT.cpp"

using namespace std;

int main()
{
	ifstream inStream;
	inStream.open("input.txt");  // data1 파일 open

	List lp;					// 리스트1 관리구조체
	createList(&lp);			// 리스트1 관리구조체 생성
	
	char grade,name;			// 성적과 이름을 받을 변수 선언
	char major[10];				// 전공을 받을 변수 선언
	int ID;						// 학번을 받을 변수 선언

	for (int i = 0; i < 8; i++)	// data1 파일에 있는 데이터 갯수만큼
	{
		inStream >> name >> ID >> major >> grade;   // 데이터 받아와서 각 변수에 저장
		AddLast(&lp, name, ID, major, grade);		// 저장된 변수에 있는 데이터를 새노드에 저장
	}
	inStream.close();			// 입력 스트림 종료
	
	cout << "*************** 문제 1 ****************" << endl;
	sortList(&lp);				// list1 정렬(이름 : 오름차순)
	displayList(&lp);			// list1 출력
	cout << "***************************************" << endl << endl;
	cout << "*************** 문제 2 ****************" << endl;
	displayList2(&lp,'A');		// list1 안에서 성적이 A 인 학생들 출력
	cout << "***************************************" << endl << endl;
	
	List lp2;						// 리스트2 관리구조체
	createList(&lp2);				// 리스트2 관리구조체 생성
	inStream.open("input2.txt");	// data2 파일 open

	for (int i = 0; i < 3; i++)		// data2 파일에 있는 데이터 갯수만큼
	{
		inStream >> name >> ID >> major >> grade;	// 데이터 받아와서 각 변수에 저장
		AddLast(&lp2, name, ID, major, grade);		// 저장된 변수에 있는 데이터를 새노드에 저장
	}

	inStream.close();		// 입력 스트림 종료
	cout << "*************** 문제 3 ****************" << endl;
	combineList(&lp, &lp2);			// list1 과 list2 병합
	displayList3(&lp,"CS");			// list1 에서 전공이 "CS" 인 학생들 출력
	cout << "***************************************" << endl;
	
	destroyList(&lp);		// list1 해제
	
	return 0;
}
