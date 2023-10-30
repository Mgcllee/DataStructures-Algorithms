#include <iostream>
using namespace std;

struct INFO
{
	int grade = 0;
	bool marked = false;
};

int st_cnt = 0, Jo_num = -1, dis = -1, week = 0;
INFO** grade = new INFO * [week];

void Input()
{
	cin >> st_cnt >> Jo_num >> dis >> week;
	for (int i = 0; i < week; ++i) grade[i] = new INFO[st_cnt];

	grade[0][0].marked = grade[0][Jo_num - 1].marked = true;

	int grade_buffer;

	for (int i = 0; i < week - 1; ++i) {
		for (int gradeTime = 0; gradeTime < 2; ++gradeTime) {
			for (int j = 0; j < st_cnt; ++j) {
				cin >> grade_buffer;
				grade[i][j].grade += ((gradeTime == 0) ? grade_buffer : -grade_buffer);
			}
		}
	}
}
void CompareAndSwap(int cur_week, int left_index, int right_index)
{
	int goodGrade = grade[cur_week][left_index].grade;
	int badGrade = grade[cur_week][right_index].grade;
	bool goodGradePlus = goodGrade >= 0;
	bool badGradePlus = badGrade >= 0;

	if ((goodGradePlus && badGradePlus && (goodGrade + 2 <= badGrade))
		|| (!goodGradePlus && badGradePlus)
		|| (!goodGradePlus && !badGradePlus && (goodGrade + 4 <= badGrade))) {

		grade[cur_week][left_index].grade += 2;
		grade[cur_week][right_index].grade -= 2;

		INFO swap_buf = grade[cur_week][left_index];
		grade[cur_week][left_index] = grade[cur_week][right_index];
		grade[cur_week][right_index] = swap_buf;
	}
}

int main()
{
	Input();

	int prev_happy_week = -1;
	int happy_stack = 0;
	int happy_ctn_stack = 0;
	int Max_happy_ctn_stack = 0;

	for (int cur_week = 0; cur_week < week - 1; ++cur_week) {
		printf("\n========== prev ==========\n");
		for (int find_st = 0; find_st < st_cnt; ++find_st) {
			if (grade[cur_week][find_st].marked) {
				printf("(%d) ", find_st);
			}
			else printf("%d ", grade[cur_week][find_st].grade);
		}

		for (int cmp_num = 0; cmp_num < st_cnt - 1; ++cmp_num) {
			CompareAndSwap(cur_week, cmp_num, cmp_num + 1);
		}

		printf("\n========== next ==========\n");
		for (int find_st = 0; find_st < st_cnt; ++find_st) {
			if (grade[cur_week][find_st].marked) {
				printf("(%d) ", find_st);
			}
			else printf("%d ", grade[cur_week][find_st].grade);
		}
		printf("\n\n");

		int sumDist = st_cnt;
		for (int find_st = 0; find_st < st_cnt; ++find_st) {
			if (grade[cur_week][find_st].marked) {
				grade[cur_week + 1][find_st].marked = true;
				if (sumDist == st_cnt) {
					sumDist = -find_st;
				}
				else {
					sumDist += find_st;
					break;
				}
			}
		}

		if (sumDist <= dis) {
			if (prev_happy_week == (cur_week - 1)) {
				happy_ctn_stack += 1;
				if (Max_happy_ctn_stack < happy_ctn_stack) {
					Max_happy_ctn_stack = happy_ctn_stack;
				}
			}
			else happy_ctn_stack = 0;
			
			prev_happy_week = cur_week;
			happy_stack += 1;

			printf("Happy Week~~~!!!\n");
		}
		else happy_ctn_stack = 0;
	}

	printf("\n== Last Week ==\n\n");
	if (happy_ctn_stack > 0) {
		happy_ctn_stack += 1;
		if (Max_happy_ctn_stack < happy_ctn_stack) {
			Max_happy_ctn_stack = happy_ctn_stack;
		}

		happy_stack += 1;
		printf("Happy Week~~~!!!\n");
	}

	printf("%d %d", happy_stack, Max_happy_ctn_stack);

	return 0;
}
