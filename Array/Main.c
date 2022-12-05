//Main.c
/************************************************************************************************
파일명칭: Main.c
기    능: 배열라이브러리 테스트시나리오
작 성 자: 임다니엘
작성일자: 2022/05/13
*************************************************************************************************/
#include "Array.h"
#include <stdio.h>
#include <memory.h>
#pragma warning (disable:4996)

//함수포인터 매개변수로 사용될 함수
int Compare(void* one, void* other);

//main 함수 정의
int main(int argc, char* argv[]) {
	Array array;
	Array one;
	Array other;
	Long index;
	Long(*indexes);
	Long count;
	Long object;
	Long key;
	Long i;
	Long ret;

	//배열을 만든다.
	Create(&array, 4, sizeof(Long));
	//배열에 항목을 저장한다.
	object = 7;
	Store(&array, 0, &object, sizeof(Long));
	i = 0;
	while (i < array.length) {
		GetAt(&array, i, &ret, sizeof(Long));
		printf(" %d ", ret);
		i++;
	}
	printf("\n");
	object = 8;
	Store(&array, 1, &object, sizeof(Long));
	i = 0;
	while (i < array.length) {
		GetAt(&array, i, &ret, sizeof(Long));
		printf(" %d ", ret);
		i++;
	}
	printf("\n");
	object = 1;
	Store(&array, 2, &object, sizeof(Long));
	i = 0;
	while (i < array.length) {
		GetAt(&array, i, &ret, sizeof(Long));
		printf(" %d ", ret);
		i++;
	}
	printf("\n");
	object = 2;
	Store(&array, 3, &object, sizeof(Long));
	i = 0;
	while (i < array.length) {
		GetAt(&array, i, &ret, sizeof(Long));
		printf(" %d ", ret);
		i++;
	}
	printf("\n");
	//중복없을시의 선형검색을 한다.
	key = 1;
	index = LinearSearchUnique(&array, &key, sizeof(Long), Compare);
	GetAt(&array, index, &ret, sizeof(Long));
	printf(" %d \n", ret);
	//맨뒤에서 추가한다.
	object = 8;
	index = AppendFromRear(&array, &object, sizeof(Long));
	i = 0;
	while (i <= index) {
		GetAt(&array, i, &ret, sizeof(Long));
		printf(" %d ", ret);
		i++;
	}
	printf("\n");
	//중복있을때의 선형검색을 한다.
	key = 8;
	LinearSearchDuplicate(&array, &key, &indexes, &count, sizeof(Long), Compare);
	i = 0;
	while (i < count) {
		GetAt(&array, indexes[i], &ret, sizeof(Long));
		printf(" %d ", ret);
		i++;
	}
	printf("\n");
	if (indexes != NULL) {
		free(indexes);
	}
	//맨뒤에서 지운다.
	index = DeleteFromRear(&array, sizeof(Long));
	if (index == -1) {
		printf("Deleted!\n");
	}
	//삽입한다.
	object = 6;
	Insert(&array, 2, &object, sizeof(Long));
	i = 0;
	while (i < array.length) {
		GetAt(&array, i, &ret, sizeof(Long));
		printf(" %d ", ret);
		i++;
	}
	printf("\n");
	//선택정렬을 한다.
	SelectionSort(&array, sizeof(Long), Compare);
	i = 0;
	while (i < array.length) {
		GetAt(&array, i, &ret, sizeof(Long));
		printf(" %d ", ret);
		i++;
	}
	printf("\n");
	//중복없을때의 이분검색을 한다.
	key = 7;
	index = BinarySearchUnique(&array, &key, sizeof(Long), Compare);
	GetAt(&array, index, &ret, sizeof(Long));
	printf(" %d \n", ret);
	//맨앞에 추가한다.
	object = 9;
	AppendFromFront(&array, &object, sizeof(Long));
	i = 0;
	while (i < array.length) {
		GetAt(&array, i, &ret, sizeof(Long));
		printf(" %d ", ret);
		i++;
	}
	printf("\n");
	//고친다.
	object = 6;
	index = Modify(&array, 1, &object, sizeof(Long));
	i = 0;
	while (i < array.length) {
		GetAt(&array, i, &ret, sizeof(Long));
		printf(" %d ", ret);
		i++;
	}
	printf("\n");
	//버블정렬을 한다.
	BubbleSort(&array, sizeof(Long), Compare);
	i = 0;
	while (i < array.length) {
		GetAt(&array, i, &ret, sizeof(Long));
		printf(" %d ", ret);
		i++;
	}
	printf("\n");
	//중복 있을때의 이분검색을 한다.
	key = 6;
	BinarySearchDuplicate(&array, &key, &indexes, &count, sizeof(Long), Compare);
	i = 0;
	while (i < count) {
		GetAt(&array, indexes[i], &ret, sizeof(Long));
		printf(" %d ", ret);
		i++;
	}
	printf("\n");
	if (indexes != NULL) {
		free(indexes);
	}
	//읽어온다.
	GetAt(&array, 3, &ret, sizeof(Long));
	printf(" %d \n", ret);
	//모두 지운다.
	Clear(&array);
	//배열을 만든다.
	Create(&one, 3, sizeof(Long));
	//항목을 저장한다.
	object = 6;
	Store(&one, 0, &object, sizeof(Long));
	i = 0;
	while (i < one.length) {
		GetAt(&one, i, &ret, sizeof(Long));
		printf(" %d ", ret);
		i++;
	}
	printf("\n");
	object = 3;
	Store(&one, 1, &object, sizeof(Long));
	i = 0;
	while (i < one.length) {
		GetAt(&one, i, &ret, sizeof(Long));
		printf(" %d ", ret);
		i++;
	}
	printf("\n");
	//지운다.
	index = Delete(&one, 1, sizeof(Long));
	if (index == -1) {
		printf("Deleted!\n");
	}
	//항목을 저장한다.
	object = 2;
	Store(&one, 1, &object, sizeof(Long));
	i = 0;
	while (i < one.length) {
		GetAt(&one, i, &ret, sizeof(Long));
		printf(" %d ", ret);
		i++;
	}
	printf("\n");
	//맨뒤에 항목을 추가한다.
	object = 1;
	AppendFromRear(&one, &object, sizeof(Long));
	i = 0;
	while (i < one.length) {
		GetAt(&one, i, &ret, sizeof(Long));
		printf(" %d ", ret);
		i++;
	}
	printf("\n");
	object = 5;
	AppendFromRear(&one, &object, sizeof(Long));
	i = 0;
	while (i < one.length) {
		GetAt(&one, i, &ret, sizeof(Long));
		printf(" %d ", ret);
		i++;
	}
	printf("\n");
	//맨앞에서 지운다.
	index = DeleteFromFront(&one, sizeof(Long));
	if (index == -1) {
		printf("Deleted!\n");
	}
	//삽입정렬을 한다.
	InsertionSort(&one, sizeof(Long), Compare);
	i = 0;
	while (i < one.length) {
		GetAt(&one, i, &ret, sizeof(Long));
		printf(" %d ", ret);
		i++;
	}
	printf("\n");
	//배열을 만든다.
	Create(&other, 4, sizeof(Long));
	//항목을 저장한다.
	object = 1;
	Store(&other, 0, &object, sizeof(Long));
	i = 0;
	while (i < other.length) {
		GetAt(&other, i, &ret, sizeof(Long));
		printf(" %d ", ret);
		i++;
	}
	printf("\n");
	object = 2;
	Store(&other, 1, &object, sizeof(Long));
	i = 0;
	while (i < other.length) {
		GetAt(&other, i, &ret, sizeof(Long));
		printf(" %d ", ret);
		i++;
	}
	printf("\n");
	object = 2;
	Store(&other, 2, &object, sizeof(Long));
	i = 0;
	while (i < other.length) {
		GetAt(&other, i, &ret, sizeof(Long));
		printf(" %d ", ret);
		i++;
	}
	printf("\n");
	object = 3;
	Store(&other, 3, &object, sizeof(Long));
	i = 0;
	while (i < other.length) {
		GetAt(&other, i, &ret, sizeof(Long));
		printf(" %d ", ret);
		i++;
	}
	printf("\n");
	//병합한다.
	Merge(&array, &one, &other, sizeof(Long), Compare);
	i = 0;
	while (i < array.length) {
		GetAt(&array, i, &ret, sizeof(Long));
		printf(" %d ", ret);
		i++;
	}
	printf("\n");

	//배열을 없앤다
	Destroy(&array);
	Destroy(&one);
	Destroy(&other);

	return 0;
}
//함수포인터 매개변수로 사용될 함수
int Compare(void* one, void* other) {
	Long* one_ = (Long*)one;
	Long* other_ = (Long*)other;
	int ret;

	if (*one_ > *other_){
		ret = 1;
	}
	else if(*one_ == *other_){
		ret = 0;
	}
	else if(*one_ < *other_){
		ret = -1;
	}
	return ret;
}