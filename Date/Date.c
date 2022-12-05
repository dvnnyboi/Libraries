//Date.c
/************************************************************************************************
���ϸ�Ī: Date.c
��    ��: ��¥ Ŭ���� ����
�� �� ��: �ӴٴϿ�
�ۼ�����: 2022/07/28
*************************************************************************************************/
#include "Date.h"
#include <time.h>
#include <stdio.h>
#pragma warning (disable:4996)

/************************************************************************************************
��    Ī: Create
��    ��: ��¥�� �����.
��    ��: ��¥
��    ��: ����
*************************************************************************************************/
void Create(Date* date) {
	date->year = 1900;
	date->month = JAN;
	date->day = 1;
	date->weekDay = MON;
	date->Today = Today;
	date->Yesterday = Yesterday;
	date->Tomorrow = Tomorrow;
	date->PreviousDate = PreviousDate;
	date->NextDate = NextDate;
	date->IsEqual = IsEqual;
	date->IsNotEqual = IsNotEqual;
	date->IsLesserThan = IsLesserThan;
	date->IsGreaterThan = IsGreaterThan;
}
/************************************************************************************************
��    Ī: Today
��    ��: ���� ��¥�� ���Ѵ�.
��    ��: ����
��    ��: ��¥
*************************************************************************************************/
Date Today(Date* date) {
	time_t timer;
	struct tm* today;
	Date today_;

	Create(&today_);
	time(&timer);
	today = localtime(&timer);
	today_.year = today->tm_year + 1900;
	today_.month = (Month)(today->tm_mon + 1);
	today_.day = today->tm_mday;
	today_.weekDay = (WeekDay)(today->tm_wday);

	Destroy(&today_);
	return today_;
}
/************************************************************************************************
��    Ī: Yesterday
��    ��: ���� ��¥�� ���Ѵ�.
��    ��: ����
��    ��: ��¥
*************************************************************************************************/
Date Yesterday(Date* date) {
	struct tm yesterday = { 0, };
	Date yesterday_;

	Create(&yesterday_);
	yesterday.tm_year = date->year - 1900;
	yesterday.tm_mon = date->month - 1;
	yesterday.tm_mday = date->day - 1;
	mktime(&yesterday);
	yesterday_.year = yesterday.tm_year + 1900;
	yesterday_.month = (Month)(yesterday.tm_mon + 1);
	yesterday_.day = yesterday.tm_mday;
	yesterday_.weekDay = (WeekDay)(yesterday.tm_wday);

	Destroy(&yesterday_);
	return yesterday_;
}
/************************************************************************************************
��    Ī: Tomorrow
��    ��: ���� ��¥�� ���Ѵ�.
��    ��: ����
��    ��: ��¥
*************************************************************************************************/
Date Tomorrow(Date* date) {
	struct tm tomorrow = { 0, };
	Date tomorrow_;

	Create(&tomorrow_);
	tomorrow.tm_year = date->year - 1900;
	tomorrow.tm_mon = date->month - 1;
	tomorrow.tm_mday = date->day + 1;
	mktime(&tomorrow);
	tomorrow_.year = tomorrow.tm_year + 1900;
	tomorrow_.month = (Month)(tomorrow.tm_mon + 1);
	tomorrow_.day = tomorrow.tm_mday;
	tomorrow_.weekDay = (WeekDay)(tomorrow.tm_wday);

	Destroy(&tomorrow_);
	return tomorrow_;
}
/************************************************************************************************
��    Ī: PreviousDate
��    ��: ��ĥ ���� ��¥�� ���Ѵ�.
��    ��: �� ��
��    ��: ��¥
*************************************************************************************************/
Date PreviousDate(Date* date, int days) {
	struct tm previousDate = { 0, };
	Date previousDate_;

	Create(&previousDate_);
	previousDate.tm_year = date->year - 1900;
	previousDate.tm_mon = date->month - 1;
	previousDate.tm_mday = date->day - days;
	mktime(&previousDate);
	previousDate_.year = previousDate.tm_year + 1900;
	previousDate_.month = (Month)(previousDate.tm_mon + 1);
	previousDate_.day = previousDate.tm_mday;
	previousDate_.weekDay = (WeekDay)(previousDate.tm_wday);

	Destroy(&previousDate_);
	return previousDate_;
}
/************************************************************************************************
��    Ī: NextDate
��    ��: ��ĥ ���� ��¥�� ���Ѵ�.
��    ��: �� ��
��    ��: ��¥
*************************************************************************************************/
Date NextDate(Date* date, int days) {
	struct tm nextDate = { 0, };
	Date nextDate_;

	Create(&nextDate_);
	nextDate.tm_year = date->year - 1900;
	nextDate.tm_mon = date->month - 1;
	nextDate.tm_mday = date->day + days;
	mktime(&nextDate);
	nextDate_.year = nextDate.tm_year + 1900;
	nextDate_.month = (Month)(nextDate.tm_mon + 1);
	nextDate_.day = nextDate.tm_mday;
	nextDate_.weekDay = (WeekDay)(nextDate.tm_wday);

	Destroy(&nextDate_);
	return nextDate_;
}
/************************************************************************************************
��    Ī: IsEqual
��    ��: ���� ��¥���� Ȯ���Ѵ�.
��    ��: ��¥
��    ��: Ȯ�� ���
*************************************************************************************************/
Boolean IsEqual(Date* date, Date* other) {
	Boolean ret = FALSE;

	if (date->day == other->day && date->month == other->month && date->year == other->year) {
		ret = TRUE;
	}
	return ret;
}
/************************************************************************************************
��    Ī: IsNotEqual
��    ��: �ٸ� ��¥���� Ȯ���Ѵ�.
��    ��: ��¥
��    ��: Ȯ�� ���
*************************************************************************************************/
Boolean IsNotEqual(Date* date, Date* other) {
	Boolean ret = FALSE;

	if (date->day != other->day || date->month != other->month || date->year != other->year) {
		ret = TRUE;
	}
	return ret;
}
/************************************************************************************************
��    Ī: IsLesserThan
��    ��: ���� ��¥���� Ȯ���Ѵ�.
��    ��: ��¥
��    ��: Ȯ�� ���
*************************************************************************************************/
Boolean IsLesserThan(Date* date, Date* other) {
	Boolean ret = FALSE;

	if (date->year < other->year) {
		ret = TRUE;
	}
	else if (date->year == other->year && date->month < other->month) {
		ret = TRUE;
	}
	else if (date->year == other->year && date->month == other->month && date->day < other->day) {
		ret = TRUE;
	}
	return ret;
}
/************************************************************************************************
��    Ī: IsGreaterThan
��    ��: ���� ��¥���� Ȯ���Ѵ�.
��    ��: ��¥
��    ��: Ȯ�� ���
*************************************************************************************************/
Boolean IsGreaterThan(Date* date, Date* other) {
	Boolean ret = FALSE;

	if (date->year > other->year) {
		ret = TRUE;
	}
	else if (date->year == other->year && date->month > other->month) {
		ret = TRUE;
	}
	else if (date->year == other->year && date->month == other->month && date->day > other->day) {
		ret = TRUE;
	}
	return ret;
}
/************************************************************************************************
��    Ī: Destroy
��    ��: ��¥�� ���ش�.
��    ��: ��¥
��    ��: ����
*************************************************************************************************/
void Destroy(Date* date) {}


//�׽�Ʈ �ó�����
int main(int argc, char* argv[]) {
	Date date;
	Date today;
	Date yesterday;
	Date tomorrow;
	Date threeDaysLater;
	Date twoDaysEarlier;
	Date fiveDaysEarlier;
	Date fiveDaysLater;
	Boolean boolean;

	//1. ��¥�� �����.
	Create(&date);
	Create(&today);
	Create(&yesterday);
	Create(&tomorrow);
	Create(&threeDaysLater);
	Create(&twoDaysEarlier);
	Create(&fiveDaysEarlier);
	//2. ���� ��¥�� ���Ѵ�.
	today = date.Today(&date);
	printf("**********\n");
	printf("TODAY\n");
	printf("%4d-%2d-%2d\n", today.year, today.month, today.day);
	//3. ���� ��¥�� ���Ѵ�.
	yesterday = today.Yesterday(&today);
	printf("**********\n");
	printf("YESTERDAY\n");
	printf("%4d-%2d-%2d\n", yesterday.year, yesterday.month, yesterday.day);
	//4. ���� ��¥�� ���Ѵ�.
	tomorrow = today.Tomorrow(&today);
	printf("**********\n");
	printf("TOMORROW\n");
	printf("%4d-%2d-%2d\n", tomorrow.year, tomorrow.month, tomorrow.day);
	//5. ���ú��� 3�� �� ��¥�� ���Ѵ�.
	threeDaysLater = today.NextDate(&today, 3);
	printf("**********\n");
	printf("3 DAYS LATER\n");
	printf("%4d-%2d-%2d\n", threeDaysLater.year, threeDaysLater.month, threeDaysLater.day);
	//6. 2�� �� ��¥�� ���Ѵ�.
	twoDaysEarlier = threeDaysLater.PreviousDate(&threeDaysLater, 2);
	printf("**********\n");
	printf("2 DAYS EARLIER\n");
	printf("%4d-%2d-%2d\n", twoDaysEarlier.year, twoDaysEarlier.month, twoDaysEarlier.day);
	//7. ������ �ٸ���¥���� Ȯ���Ѵ�.
	boolean = twoDaysEarlier.IsNotEqual(&twoDaysEarlier, &yesterday);
	printf("    **********\n");
	printf("    EQUALS YESTERDAY?\n");
	if (boolean == TRUE) {
		printf("    NOT EQUAL\n");
	}
	//8. ���ϰ� ���� ��¥���� Ȯ���Ѵ�.
	boolean = twoDaysEarlier.IsEqual(&twoDaysEarlier, &tomorrow);
	printf("    **********\n");
	printf("    EQUALS TOMORROW?\n");
	if (boolean == TRUE) {
		printf("    EQUAL\n");
	}
	//9. �������� �������� Ȯ���Ѵ�.
	boolean = twoDaysEarlier.IsGreaterThan(&twoDaysEarlier, &yesterday);
	printf("    **********\n");
	printf("    LATER THAN YESTERDAY?\n");
	if (boolean == TRUE) {
		printf("    LATER\n");
	}
	//10. 5�� �� ��¥�� ���Ѵ�.
	fiveDaysEarlier = threeDaysLater.PreviousDate(&threeDaysLater, 5);
	printf("**********\n");
	printf("5 DAYS EARLIER\n");
	printf("%4d-%2d-%2d\n", fiveDaysEarlier.year, fiveDaysEarlier.month, fiveDaysEarlier.day);
	//11. �������� �������� Ȯ���Ѵ�.
	boolean = fiveDaysEarlier.IsLesserThan(&fiveDaysEarlier, &yesterday);
	printf("    **********\n");
	printf("    EARLIER THAN YESTERDAY?\n");
	if (boolean == TRUE) {
		printf("    EARLIER\n");
	}
	//���ú��� 5�� �� ��¥�� ���Ѵ�.
	fiveDaysLater = today.NextDate(&today, 5);
	printf("**********\n");
	printf("5 DAYS LATER\n");
	printf("%4d-%2d-%2d\n", fiveDaysLater.year, fiveDaysLater.month, fiveDaysLater.day);

	//12. ��¥�� ���ش�.
	Destroy(&date);
	Destroy(&today);
	Destroy(&yesterday);
	Destroy(&tomorrow);
	Destroy(&threeDaysLater);
	Destroy(&twoDaysEarlier);
	Destroy(&fiveDaysEarlier);

	return 0;
}