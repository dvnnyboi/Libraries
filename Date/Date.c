//Date.c
/************************************************************************************************
파일명칭: Date.c
기    능: 날짜 클래스 정의
작 성 자: 임다니엘
작성일자: 2022/07/28
*************************************************************************************************/
#include "Date.h"
#include <time.h>
#include <stdio.h>
#pragma warning (disable:4996)

/************************************************************************************************
명    칭: Create
기    능: 날짜를 만든다.
입    력: 날짜
출    력: 없음
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
명    칭: Today
기    능: 오늘 날짜를 구한다.
입    력: 없음
출    력: 날짜
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
명    칭: Yesterday
기    능: 어제 날짜를 구한다.
입    력: 없음
출    력: 날짜
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
명    칭: Tomorrow
기    능: 내일 날짜를 구한다.
입    력: 없음
출    력: 날짜
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
명    칭: PreviousDate
기    능: 며칠 전의 날짜를 구한다.
입    력: 일 수
출    력: 날짜
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
명    칭: NextDate
기    능: 며칠 뒤의 날짜를 구한다.
입    력: 일 수
출    력: 날짜
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
명    칭: IsEqual
기    능: 같은 날짜인지 확인한다.
입    력: 날짜
출    력: 확인 결과
*************************************************************************************************/
Boolean IsEqual(Date* date, Date* other) {
	Boolean ret = FALSE;

	if (date->day == other->day && date->month == other->month && date->year == other->year) {
		ret = TRUE;
	}
	return ret;
}
/************************************************************************************************
명    칭: IsNotEqual
기    능: 다른 날짜인지 확인한다.
입    력: 날짜
출    력: 확인 결과
*************************************************************************************************/
Boolean IsNotEqual(Date* date, Date* other) {
	Boolean ret = FALSE;

	if (date->day != other->day || date->month != other->month || date->year != other->year) {
		ret = TRUE;
	}
	return ret;
}
/************************************************************************************************
명    칭: IsLesserThan
기    능: 이전 날짜인지 확인한다.
입    력: 날짜
출    력: 확인 결과
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
명    칭: IsGreaterThan
기    능: 이후 날짜인지 확인한다.
입    력: 날짜
출    력: 확인 결과
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
명    칭: Destroy
기    능: 날짜를 없앤다.
입    력: 날짜
출    력: 없음
*************************************************************************************************/
void Destroy(Date* date) {}


//테스트 시나리오
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

	//1. 날짜를 만든다.
	Create(&date);
	Create(&today);
	Create(&yesterday);
	Create(&tomorrow);
	Create(&threeDaysLater);
	Create(&twoDaysEarlier);
	Create(&fiveDaysEarlier);
	//2. 오늘 날짜를 구한다.
	today = date.Today(&date);
	printf("**********\n");
	printf("TODAY\n");
	printf("%4d-%2d-%2d\n", today.year, today.month, today.day);
	//3. 어제 날짜를 구한다.
	yesterday = today.Yesterday(&today);
	printf("**********\n");
	printf("YESTERDAY\n");
	printf("%4d-%2d-%2d\n", yesterday.year, yesterday.month, yesterday.day);
	//4. 내일 날짜를 구한다.
	tomorrow = today.Tomorrow(&today);
	printf("**********\n");
	printf("TOMORROW\n");
	printf("%4d-%2d-%2d\n", tomorrow.year, tomorrow.month, tomorrow.day);
	//5. 오늘부터 3일 뒤 날짜를 구한다.
	threeDaysLater = today.NextDate(&today, 3);
	printf("**********\n");
	printf("3 DAYS LATER\n");
	printf("%4d-%2d-%2d\n", threeDaysLater.year, threeDaysLater.month, threeDaysLater.day);
	//6. 2일 전 날짜를 구한다.
	twoDaysEarlier = threeDaysLater.PreviousDate(&threeDaysLater, 2);
	printf("**********\n");
	printf("2 DAYS EARLIER\n");
	printf("%4d-%2d-%2d\n", twoDaysEarlier.year, twoDaysEarlier.month, twoDaysEarlier.day);
	//7. 어제와 다른날짜인지 확인한다.
	boolean = twoDaysEarlier.IsNotEqual(&twoDaysEarlier, &yesterday);
	printf("    **********\n");
	printf("    EQUALS YESTERDAY?\n");
	if (boolean == TRUE) {
		printf("    NOT EQUAL\n");
	}
	//8. 내일과 같은 날짜인지 확인한다.
	boolean = twoDaysEarlier.IsEqual(&twoDaysEarlier, &tomorrow);
	printf("    **********\n");
	printf("    EQUALS TOMORROW?\n");
	if (boolean == TRUE) {
		printf("    EQUAL\n");
	}
	//9. 어제보다 이후인지 확인한다.
	boolean = twoDaysEarlier.IsGreaterThan(&twoDaysEarlier, &yesterday);
	printf("    **********\n");
	printf("    LATER THAN YESTERDAY?\n");
	if (boolean == TRUE) {
		printf("    LATER\n");
	}
	//10. 5일 전 날짜를 구한다.
	fiveDaysEarlier = threeDaysLater.PreviousDate(&threeDaysLater, 5);
	printf("**********\n");
	printf("5 DAYS EARLIER\n");
	printf("%4d-%2d-%2d\n", fiveDaysEarlier.year, fiveDaysEarlier.month, fiveDaysEarlier.day);
	//11. 어제보다 이전인지 확인한다.
	boolean = fiveDaysEarlier.IsLesserThan(&fiveDaysEarlier, &yesterday);
	printf("    **********\n");
	printf("    EARLIER THAN YESTERDAY?\n");
	if (boolean == TRUE) {
		printf("    EARLIER\n");
	}
	//오늘부터 5일 뒤 날짜를 구한다.
	fiveDaysLater = today.NextDate(&today, 5);
	printf("**********\n");
	printf("5 DAYS LATER\n");
	printf("%4d-%2d-%2d\n", fiveDaysLater.year, fiveDaysLater.month, fiveDaysLater.day);

	//12. 날짜를 없앤다.
	Destroy(&date);
	Destroy(&today);
	Destroy(&yesterday);
	Destroy(&tomorrow);
	Destroy(&threeDaysLater);
	Destroy(&twoDaysEarlier);
	Destroy(&fiveDaysEarlier);

	return 0;
}