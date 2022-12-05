//Main.c
/************************************************************************************************
���ϸ�Ī: Main.c
��    ��: �̺а˻�Ʈ�� �׽�Ʈ �ó�����.
�� �� ��: �ӴٴϿ�
�ۼ�����: 2022/06/27
*************************************************************************************************/
#include "BinarySearchTree.h"
#include <stdio.h>
#pragma warning (disable:4996)

int CompareKeys(void* one, void* other);

int main(int argc, char* argv[]) {
	BinaryTree binaryTree;
	BinaryNode* node;
	Long key;
	Long ret;
	Long(*keys);
	Long count;
	Long i;

	//�����.
	Create(&binaryTree);
	//�����Ѵ�.
	printf("***********************************Insert***********************************\n");
	key = 100;
	node = Insert(&binaryTree, &key, sizeof(Long), CompareKeys);
	GetAt(&binaryTree, node, &ret, sizeof(Long));
	printf(" %d ", ret);
	key = 50;
	node = Insert(&binaryTree, &key, sizeof(Long), CompareKeys);
	GetAt(&binaryTree, node, &ret, sizeof(Long));
	printf(" %d ", ret);
	key = 20;
	node = Insert(&binaryTree, &key, sizeof(Long), CompareKeys);
	GetAt(&binaryTree, node, &ret, sizeof(Long));
	printf(" %d ", ret);
	key = 70;
	node = Insert(&binaryTree, &key, sizeof(Long), CompareKeys);
	GetAt(&binaryTree, node, &ret, sizeof(Long));
	printf(" %d ", ret);
	key = 60;
	node = Insert(&binaryTree, &key, sizeof(Long), CompareKeys);
	GetAt(&binaryTree, node, &ret, sizeof(Long));
	printf(" %d ", ret);
	key = 90;
	node = Insert(&binaryTree, &key, sizeof(Long), CompareKeys);
	GetAt(&binaryTree, node, &ret, sizeof(Long));
	printf(" %d ", ret);
	key = 65;
	node = Insert(&binaryTree, &key, sizeof(Long), CompareKeys);
	GetAt(&binaryTree, node, &ret, sizeof(Long));
	printf(" %d ", ret);
	key = 200;
	node = Insert(&binaryTree, &key, sizeof(Long), CompareKeys);
	GetAt(&binaryTree, node, &ret, sizeof(Long));
	printf(" %d ", ret);
	key = 150;
	node = Insert(&binaryTree, &key, sizeof(Long), CompareKeys);
	GetAt(&binaryTree, node, &ret, sizeof(Long));
	printf(" %d ", ret);
	printf("\n");
	//ã�´�.
	printf("************************************Find************************************\n");
	key = 65;
	node = Search(&binaryTree, &key, sizeof(Long), CompareKeys);
	GetAt(&binaryTree, node, &ret, sizeof(Long));
	printf(" %d\n", ret);
	//���ǵ��� �Ű����´�.
	printf("**********************************MakeKeys**********************************\n");
	MakeKeys(&binaryTree, &keys, &count, sizeof(Long));
	i = 0;
	while (i < count) {
		printf(" %d ", keys[i]);
		i++;
	}
	printf("\nBalance : %d\n", binaryTree.balance);
	printf("\n");
	//��� �����.
	printf("********************************DeleteAllItems*******************************\n");
	DeleteAllItems(&binaryTree);
	printf("length : %d\n", binaryTree.length);
	printf("Balance : %d\n", binaryTree.balance);
	//Ʈ���� �����.
	printf("**********************************MakeTree**********************************\n");
	MakeTree(&binaryTree, keys, count, sizeof(Long));
	if (keys != NULL) {
		free(keys);
	}
	printf("length : %d\n", binaryTree.length);
	printf("Balance : %d\n", binaryTree.balance);
	//ã�´�.
	printf("************************************Find************************************\n");
	key = 65;
	node = Search(&binaryTree, &key, sizeof(Long), CompareKeys);
	GetAt(&binaryTree, node, &ret, sizeof(Long));
	printf(" %d\n", ret);
	//�����Ѵ�.
	printf("***********************************Delete***********************************\n");
	key = 70;
	node = Delete(&binaryTree, &key, sizeof(Long), CompareKeys);
	if (node == NULL) {
		printf("70  ==> Deleted!\n");
	}
	key = 200;
	node = Delete(&binaryTree, &key, sizeof(Long), CompareKeys);
	if (node == NULL) {
		printf("200 ==> Deleted!\n");
	}
	key = 50;
	node = Delete(&binaryTree, &key, sizeof(Long), CompareKeys);
	if (node == NULL) {
		printf("50  ==> Deleted!\n");
	}
	key = 20;
	node = Delete(&binaryTree, &key, sizeof(Long), CompareKeys);
	if (node == NULL) {
		printf("20  ==> Deleted!\n");
	}
	key = 60;
	node = Delete(&binaryTree, &key, sizeof(Long), CompareKeys);
	if (node == NULL) {
		printf("60  ==> Deleted!\n");
	}
	key = 90;
	node = Delete(&binaryTree, &key, sizeof(Long), CompareKeys);
	if (node == NULL) {
		printf("90  ==> Deleted!\n");
	}
	key = 100;
	node = Delete(&binaryTree, &key, sizeof(Long), CompareKeys);
	if (node == NULL) {
		printf("100 ==> Deleted!\n");
	}
	key = 65;
	node = Delete(&binaryTree, &key, sizeof(Long), CompareKeys);
	if (node == NULL) {
		printf("65  ==> Deleted!\n");
	}
	key = 150;
	node = Delete(&binaryTree, &key, sizeof(Long), CompareKeys);
	if (node == NULL) {
		printf("150 ==> Deleted!\n");
	}
	printf("length : %d\n", binaryTree.length);
	printf("Balance : %d\n", binaryTree.balance);
	//�����Ѵ�.
	printf("***********************************Insert***********************************\n");
	key = 90;
	node = Insert(&binaryTree, &key, sizeof(Long), CompareKeys);
	GetAt(&binaryTree, node, &ret, sizeof(Long));
	printf(" %d\n", ret);
	printf("Balance : %d\n", binaryTree.balance);
	key = 60;
	node = Insert(&binaryTree, &key, sizeof(Long), CompareKeys);
	GetAt(&binaryTree, node, &ret, sizeof(Long));
	printf(" %d\n", ret);
	printf("Balance : %d\n", binaryTree.balance);
	key = 150;
	node = Insert(&binaryTree, &key, sizeof(Long), CompareKeys);
	GetAt(&binaryTree, node, &ret, sizeof(Long));
	printf(" %d\n", ret);
	printf("Balance : %d\n", binaryTree.balance);
	key = 65;
	node = Insert(&binaryTree, &key, sizeof(Long), CompareKeys);
	GetAt(&binaryTree, node, &ret, sizeof(Long));
	printf(" %d\n", ret);
	printf("Balance : %d\n", binaryTree.balance);
	key = 210;
	node = Insert(&binaryTree, &key, sizeof(Long), CompareKeys);
	GetAt(&binaryTree, node, &ret, sizeof(Long));
	printf(" %d\n", ret);
	printf("Balance : %d\n", binaryTree.balance);
	key = 200;
	node = Insert(&binaryTree, &key, sizeof(Long), CompareKeys);
	GetAt(&binaryTree, node, &ret, sizeof(Long));
	printf(" %d\n", ret);
	printf("Balance : %d\n", binaryTree.balance);
	key = 170;
	node = Insert(&binaryTree, &key, sizeof(Long), CompareKeys);
	GetAt(&binaryTree, node, &ret, sizeof(Long));
	printf(" %d\n", ret);
	printf("Balance : %d\n", binaryTree.balance);
	key = 160;
	node = Insert(&binaryTree, &key, sizeof(Long), CompareKeys);
	GetAt(&binaryTree, node, &ret, sizeof(Long));
	printf(" %d\n", ret);
	printf("Balance : %d\n", binaryTree.balance);
	//������ �����.
	printf("********************************MakeBalance*********************************\n");
	MakeBalance(&binaryTree, sizeof(Long));
	printf("Balance : %d\n", binaryTree.balance);

	//���ش�.
	Destroy(&binaryTree);

	return 0;
}

int CompareKeys(void* one, void* other) {
	Long* one_ = (Long*)one;
	Long* other_ = (Long*)other;
	Long ret;

	if (*one_ > *other_) {
		ret = 1;
	}
	else if (*one_ == *other_) {
		ret = 0;
	}
	else if (*one_ < *other_) {
		ret = -1;
	}
	return ret;
}