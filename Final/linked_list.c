#include <stdio.h>
#include <malloc.h>
#define MAX 100
typedef struct {
	char name[12];
	int kor;
	int eng;
	int math;
}Student;
Student stu[MAX];
int count = 0, num;

void loadFile() {
	FILE* fp = fopen("students.dat", "rb");
	Student s;
	if (fp == NULL) {
		printf("파일 열기 실패\n");
		return 1;
	}

	while (fread(&s, sizeof(Student), 1, fp)) {
		printf("%s %d %d %d\n",
			s.name, s.kor, s.eng, s.math);
	}
	fclose(fp);
}
void writeFile() {
	FILE* p_file = fopen("students.dat", "wb");
	if (p_file == NULL) {
		printf("파일 저장 실패\n");
		return;
	}
	fwrite(stu, sizeof(Student), count, p_file);
	printf("저장완료\n");
}
int AddFriend(Student* p_friend, int count) {

	if (count < MAX) {
		p_friend = p_friend + count;
		printf("\n새로운 친구 정보를 입력하세요\n");
		printf("1. 이름 : ");
		scanf_s("%s", p_friend->name, sizeof(p_friend->name));
		printf("2. 국어점수 : ");
		scanf_s("%d", &p_friend->kor);
		printf("3. 영어점수 : ");
		scanf_s("%d", &p_friend->eng);
		printf("4. 수학점수 : ");
		scanf_s("%d", &p_friend->math);
		count++;
		printf("입력을 완료했습니다.\n\n");
		return 1;
	}
	else {
		printf("최대 인원을 초과하여 입력을 할 수 없습니다. \n");
		printf("최대 %d명까지만 관리 가능합니다.\n\n", MAX);
	}
	return 0;
}
void showGrade() {
	int total;
	float avg;

	printf("\n이름\t국어\t영어\t수학\t총점\t평균\n");
	printf("---------------------------------------------\n");

	for (int i = 0; i < count; i++) {
		total = stu[i].kor +
			stu[i].eng +
			stu[i].math;

		avg = total / 3.0f;

		printf("%s\t%d\t%d\t%d\t%d\t%.2f\n",
			stu[i].name,
			stu[i].kor,
			stu[i].eng,
			stu[i].math,
			total,
			avg);
	}
}
int main() {


	while (1) {
		printf("		[ 메뉴 ]		\n");
		printf("========================\n");
		printf("1. .dat 파일에서 데이터 읽기\n");
		printf("2. 추가 학생 정보 입력\n");
		printf("3. .dat 파일 저장\n");
		printf("4. 성적 확인 (평균계산)\n");
		printf("5. 종료\n");
		printf("========================\n");
		printf("번호 선택 : ");
		scanf_s("%d", &num);

		if (num == 1) {
			loadFile();
		}
		else if (num == 2) {
			if (2 == AddFriend(stu, count)) count++;
		}
		else if (num == 3) {
			writeFile();
		}
		else if (num == 4) {
			showGrade();
		}
		else if (num == 5) {
			break;
		}
		else {
			printf("1~5 번호만 선택할 수 있습니다!!\n\n");
		}
	}
}
