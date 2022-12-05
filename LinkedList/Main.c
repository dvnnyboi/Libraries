//Main.c
/************************************************************************************************
파일명칭: Main.c
기    능: 연결리스트 라이브러리 테스트시나리오
작 성 자: 임다니엘
작성일자: 2022/06/14
*************************************************************************************************/
#include "LinkedList.h"
#include <stdio.h>
#pragma warning (disable:4996)

//함수포인터형 변수로 사용될 함수: 선언
int Compare(void* one, void* other);

//main함수 정의
int main(int argc, char* argv[]) {
	LinkedList linkedList;
	Node* index;
	Node* (*indexes);
	Long object;
	Long key;
	Long count;
	Long ret;
	Long i;

	//만든다.
	printf("***************Create*************\n");
	Create(&linkedList);
	//맨앞에서 추가한다.
	printf("**********AppendFromHead**********\n");
	object = 300;
	index = AppendFromHead(&linkedList, &object, sizeof(Long));
	GetAt(&linkedList, index, &ret, sizeof(Long));
	printf("%d\n", ret);
	//맨앞에서 추가한다.
	object = 100;
	index = AppendFromHead(&linkedList, &object, sizeof(Long));
	GetAt(&linkedList, index, &ret, sizeof(Long));
	printf("%d\n", ret);
	//맨뒤에서 추가한다.
	printf("**********AppendFromTail**********\n");
	object = 500;
	index = AppendFromTail(&linkedList, &object, sizeof(Long));
	GetAt(&linkedList, index, &ret, sizeof(Long));
	printf("%d\n", ret);
	//이전으로 이동한다.
	printf("*************Previous*************\n");
	index = Previous(&linkedList);
	GetAt(&linkedList, index, &ret, sizeof(Long));
	printf("%d\n", ret);
	//앞에 삽입한다.
	printf("***********InsertBefore***********\n");
	object = 200;
	index = InsertBefore(&linkedList, index, &object, sizeof(Long));
	GetAt(&linkedList, index, &ret, sizeof(Long));
	printf("%d\n", ret);
	//다음으로 이동한다.
	printf("***************Next***************\n");
	index = Next(&linkedList);
	GetAt(&linkedList, index, &ret, sizeof(Long));
	printf("%d\n", ret);
	//뒤에 삽입한다.
	printf("***********InsertAfter************\n");
	object = 400;
	index = InsertAfter(&linkedList, index, &object, sizeof(Long));
	GetAt(&linkedList, index, &ret, sizeof(Long));
	printf("%d\n", ret);
	//처음으로 이동한다.
	printf("***************First**************\n");
	index = First(&linkedList);
	GetAt(&linkedList, index, &ret, sizeof(Long));
	printf("%d\n", ret);
	//다음으로 이동한다.
	printf("***************Next***************\n");
	index = Next(&linkedList);
	GetAt(&linkedList, index, &ret, sizeof(Long));
	printf("%d\n", ret);
	//다음으로 이동한다.
	printf("***************Next***************\n");
	index = Next(&linkedList);
	GetAt(&linkedList, index, &ret, sizeof(Long));
	printf("%d\n", ret);
	//마지막으로 이동한다.
	printf("***************Last***************\n");
	index = Last(&linkedList);
	GetAt(&linkedList, index, &ret, sizeof(Long));
	printf("%d\n", ret);
	//이전으로 이동한다.
	printf("*************Previous*************\n");
	index = Previous(&linkedList);
	GetAt(&linkedList, index, &ret, sizeof(Long));
	printf("%d\n", ret);
	//이전으로 이동한다.
	printf("*************Previous*************\n");
	index = Previous(&linkedList);
	GetAt(&linkedList, index, &ret, sizeof(Long));
	printf("%d\n", ret);
	//맨뒤에서 추가한다.
	printf("**********AppendFromTail**********\n");
	object = 200;
	index = AppendFromTail(&linkedList, &object, sizeof(Long));
	GetAt(&linkedList, index, &ret, sizeof(Long));
	printf("%d\n", ret);
	//중복이 있을때의 선형검색을 한다.
	printf("******LinearSearchDuplicate*******\n");
	key = 200;
	LinearSearchDuplicate(&linkedList, &key, &indexes, &count, Compare);
	i = 0;
	while (i < count) {
		GetAt(&linkedList, indexes[i], &ret, sizeof(Long));
		printf("%d    ", ret);
		i++;
	}
	printf("\n");
	//이동한다.
	printf("***************Move***************\n");
	index = Move(&linkedList, indexes[0]);
	GetAt(&linkedList, index, &ret, sizeof(Long));
	printf("%d\n", ret);
	if (indexes != NULL) {
		free(indexes);
	}
	//삭제한다.
	printf("**************Delete**************\n");
	index = Delete(&linkedList, index);
	if (index == NULL) {
		printf("DELETED!\n");
	}
	//중복이 없을 때의 선형검색.
	printf("*******LinearSearchUnique*********\n");
	key = 200;
	index = LinearSearchUnique(&linkedList, &key, Compare);
	GetAt(&linkedList, index, &ret, sizeof(Long));
	printf("%d\n", ret);
	//맨앞에서 삭제한다.
	printf("**********DeleteFromHead**********\n");
	index = DeleteFromHead(&linkedList);
	if (index == NULL) {
		printf("DELETED!\n");
	}
	//맨뒤에서 삭제한다.
	printf("**********DeleteFromTail**********\n");
	index = DeleteFromTail(&linkedList);
	if (index == NULL) {
		printf("DELETED!\n");
	}
	//없앤다.
	printf("*************Destroy**************\n");
	Destroy(&linkedList);

	return 0;
}
//함수 포인터형 변수로 사용될 함수: 정의
int Compare(void* one, void* other) {
	Long* one_ = (Long*)one;
	Long* other_ = (Long*)other;
	Long ret;

	if (*one_ < *other_) {
		ret = -1;
	}
	else if (*one_ == *other_) {
		ret = 0;
	}
	else if (*one_ > *other_) {
		ret = 1;
	}

	return ret;
}