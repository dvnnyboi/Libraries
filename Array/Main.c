//Main.c
/************************************************************************************************
���ϸ�Ī: Main.c
��    ��: �迭���̺귯�� �׽�Ʈ�ó�����
�� �� ��: �ӴٴϿ�
�ۼ�����: 2022/05/13
*************************************************************************************************/
#include "Array.h"
#include <stdio.h>
#include <memory.h>
#pragma warning (disable:4996)

//�Լ������� �Ű������� ���� �Լ�
int Compare(void* one, void* other);

//main �Լ� ����
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

	//�迭�� �����.
	Create(&array, 4, sizeof(Long));
	//�迭�� �׸��� �����Ѵ�.
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
	//�ߺ��������� �����˻��� �Ѵ�.
	key = 1;
	index = LinearSearchUnique(&array, &key, sizeof(Long), Compare);
	GetAt(&array, index, &ret, sizeof(Long));
	printf(" %d \n", ret);
	//�ǵڿ��� �߰��Ѵ�.
	object = 8;
	index = AppendFromRear(&array, &object, sizeof(Long));
	i = 0;
	while (i <= index) {
		GetAt(&array, i, &ret, sizeof(Long));
		printf(" %d ", ret);
		i++;
	}
	printf("\n");
	//�ߺ��������� �����˻��� �Ѵ�.
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
	//�ǵڿ��� �����.
	index = DeleteFromRear(&array, sizeof(Long));
	if (index == -1) {
		printf("Deleted!\n");
	}
	//�����Ѵ�.
	object = 6;
	Insert(&array, 2, &object, sizeof(Long));
	i = 0;
	while (i < array.length) {
		GetAt(&array, i, &ret, sizeof(Long));
		printf(" %d ", ret);
		i++;
	}
	printf("\n");
	//���������� �Ѵ�.
	SelectionSort(&array, sizeof(Long), Compare);
	i = 0;
	while (i < array.length) {
		GetAt(&array, i, &ret, sizeof(Long));
		printf(" %d ", ret);
		i++;
	}
	printf("\n");
	//�ߺ��������� �̺а˻��� �Ѵ�.
	key = 7;
	index = BinarySearchUnique(&array, &key, sizeof(Long), Compare);
	GetAt(&array, index, &ret, sizeof(Long));
	printf(" %d \n", ret);
	//�Ǿտ� �߰��Ѵ�.
	object = 9;
	AppendFromFront(&array, &object, sizeof(Long));
	i = 0;
	while (i < array.length) {
		GetAt(&array, i, &ret, sizeof(Long));
		printf(" %d ", ret);
		i++;
	}
	printf("\n");
	//��ģ��.
	object = 6;
	index = Modify(&array, 1, &object, sizeof(Long));
	i = 0;
	while (i < array.length) {
		GetAt(&array, i, &ret, sizeof(Long));
		printf(" %d ", ret);
		i++;
	}
	printf("\n");
	//���������� �Ѵ�.
	BubbleSort(&array, sizeof(Long), Compare);
	i = 0;
	while (i < array.length) {
		GetAt(&array, i, &ret, sizeof(Long));
		printf(" %d ", ret);
		i++;
	}
	printf("\n");
	//�ߺ� �������� �̺а˻��� �Ѵ�.
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
	//�о�´�.
	GetAt(&array, 3, &ret, sizeof(Long));
	printf(" %d \n", ret);
	//��� �����.
	Clear(&array);
	//�迭�� �����.
	Create(&one, 3, sizeof(Long));
	//�׸��� �����Ѵ�.
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
	//�����.
	index = Delete(&one, 1, sizeof(Long));
	if (index == -1) {
		printf("Deleted!\n");
	}
	//�׸��� �����Ѵ�.
	object = 2;
	Store(&one, 1, &object, sizeof(Long));
	i = 0;
	while (i < one.length) {
		GetAt(&one, i, &ret, sizeof(Long));
		printf(" %d ", ret);
		i++;
	}
	printf("\n");
	//�ǵڿ� �׸��� �߰��Ѵ�.
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
	//�Ǿտ��� �����.
	index = DeleteFromFront(&one, sizeof(Long));
	if (index == -1) {
		printf("Deleted!\n");
	}
	//���������� �Ѵ�.
	InsertionSort(&one, sizeof(Long), Compare);
	i = 0;
	while (i < one.length) {
		GetAt(&one, i, &ret, sizeof(Long));
		printf(" %d ", ret);
		i++;
	}
	printf("\n");
	//�迭�� �����.
	Create(&other, 4, sizeof(Long));
	//�׸��� �����Ѵ�.
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
	//�����Ѵ�.
	Merge(&array, &one, &other, sizeof(Long), Compare);
	i = 0;
	while (i < array.length) {
		GetAt(&array, i, &ret, sizeof(Long));
		printf(" %d ", ret);
		i++;
	}
	printf("\n");

	//�迭�� ���ش�
	Destroy(&array);
	Destroy(&one);
	Destroy(&other);

	return 0;
}
//�Լ������� �Ű������� ���� �Լ�
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