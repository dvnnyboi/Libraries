//Main.c
/************************************************************************************************
���ϸ�Ī: Main.c
��    ��: ���Ḯ��Ʈ ���̺귯�� �׽�Ʈ�ó�����
�� �� ��: �ӴٴϿ�
�ۼ�����: 2022/06/14
*************************************************************************************************/
#include "LinkedList.h"
#include <stdio.h>
#pragma warning (disable:4996)

//�Լ��������� ������ ���� �Լ�: ����
int Compare(void* one, void* other);

//main�Լ� ����
int main(int argc, char* argv[]) {
	LinkedList linkedList;
	Node* index;
	Node* (*indexes);
	Long object;
	Long key;
	Long count;
	Long ret;
	Long i;

	//�����.
	printf("***************Create*************\n");
	Create(&linkedList);
	//�Ǿտ��� �߰��Ѵ�.
	printf("**********AppendFromHead**********\n");
	object = 300;
	index = AppendFromHead(&linkedList, &object, sizeof(Long));
	GetAt(&linkedList, index, &ret, sizeof(Long));
	printf("%d\n", ret);
	//�Ǿտ��� �߰��Ѵ�.
	object = 100;
	index = AppendFromHead(&linkedList, &object, sizeof(Long));
	GetAt(&linkedList, index, &ret, sizeof(Long));
	printf("%d\n", ret);
	//�ǵڿ��� �߰��Ѵ�.
	printf("**********AppendFromTail**********\n");
	object = 500;
	index = AppendFromTail(&linkedList, &object, sizeof(Long));
	GetAt(&linkedList, index, &ret, sizeof(Long));
	printf("%d\n", ret);
	//�������� �̵��Ѵ�.
	printf("*************Previous*************\n");
	index = Previous(&linkedList);
	GetAt(&linkedList, index, &ret, sizeof(Long));
	printf("%d\n", ret);
	//�տ� �����Ѵ�.
	printf("***********InsertBefore***********\n");
	object = 200;
	index = InsertBefore(&linkedList, index, &object, sizeof(Long));
	GetAt(&linkedList, index, &ret, sizeof(Long));
	printf("%d\n", ret);
	//�������� �̵��Ѵ�.
	printf("***************Next***************\n");
	index = Next(&linkedList);
	GetAt(&linkedList, index, &ret, sizeof(Long));
	printf("%d\n", ret);
	//�ڿ� �����Ѵ�.
	printf("***********InsertAfter************\n");
	object = 400;
	index = InsertAfter(&linkedList, index, &object, sizeof(Long));
	GetAt(&linkedList, index, &ret, sizeof(Long));
	printf("%d\n", ret);
	//ó������ �̵��Ѵ�.
	printf("***************First**************\n");
	index = First(&linkedList);
	GetAt(&linkedList, index, &ret, sizeof(Long));
	printf("%d\n", ret);
	//�������� �̵��Ѵ�.
	printf("***************Next***************\n");
	index = Next(&linkedList);
	GetAt(&linkedList, index, &ret, sizeof(Long));
	printf("%d\n", ret);
	//�������� �̵��Ѵ�.
	printf("***************Next***************\n");
	index = Next(&linkedList);
	GetAt(&linkedList, index, &ret, sizeof(Long));
	printf("%d\n", ret);
	//���������� �̵��Ѵ�.
	printf("***************Last***************\n");
	index = Last(&linkedList);
	GetAt(&linkedList, index, &ret, sizeof(Long));
	printf("%d\n", ret);
	//�������� �̵��Ѵ�.
	printf("*************Previous*************\n");
	index = Previous(&linkedList);
	GetAt(&linkedList, index, &ret, sizeof(Long));
	printf("%d\n", ret);
	//�������� �̵��Ѵ�.
	printf("*************Previous*************\n");
	index = Previous(&linkedList);
	GetAt(&linkedList, index, &ret, sizeof(Long));
	printf("%d\n", ret);
	//�ǵڿ��� �߰��Ѵ�.
	printf("**********AppendFromTail**********\n");
	object = 200;
	index = AppendFromTail(&linkedList, &object, sizeof(Long));
	GetAt(&linkedList, index, &ret, sizeof(Long));
	printf("%d\n", ret);
	//�ߺ��� �������� �����˻��� �Ѵ�.
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
	//�̵��Ѵ�.
	printf("***************Move***************\n");
	index = Move(&linkedList, indexes[0]);
	GetAt(&linkedList, index, &ret, sizeof(Long));
	printf("%d\n", ret);
	if (indexes != NULL) {
		free(indexes);
	}
	//�����Ѵ�.
	printf("**************Delete**************\n");
	index = Delete(&linkedList, index);
	if (index == NULL) {
		printf("DELETED!\n");
	}
	//�ߺ��� ���� ���� �����˻�.
	printf("*******LinearSearchUnique*********\n");
	key = 200;
	index = LinearSearchUnique(&linkedList, &key, Compare);
	GetAt(&linkedList, index, &ret, sizeof(Long));
	printf("%d\n", ret);
	//�Ǿտ��� �����Ѵ�.
	printf("**********DeleteFromHead**********\n");
	index = DeleteFromHead(&linkedList);
	if (index == NULL) {
		printf("DELETED!\n");
	}
	//�ǵڿ��� �����Ѵ�.
	printf("**********DeleteFromTail**********\n");
	index = DeleteFromTail(&linkedList);
	if (index == NULL) {
		printf("DELETED!\n");
	}
	//���ش�.
	printf("*************Destroy**************\n");
	Destroy(&linkedList);

	return 0;
}
//�Լ� �������� ������ ���� �Լ�: ����
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