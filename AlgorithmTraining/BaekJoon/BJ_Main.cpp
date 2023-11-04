#include <iostream>
using namespace std;

struct INFO
{
	int grade = 0;
	bool marked = false;
};

int st_cnt = 0, Jo_num = -1, dis = -1, week = 0;
INFO** grade = new INFO * [week];

void Input(int* happy_stack, int* happy_continue_stack, int* Max_happy_ctn_stack)
{
	cin >> st_cnt >> Jo_num >> dis >> week;
	for (int i = 0; i < week; ++i) grade[i] = new INFO[st_cnt];

	grade[0][0].marked = true;
	grade[0][Jo_num - 1].marked = true;

	if (Jo_num - 1 <= dis) {
		*happy_stack = 1;
		*happy_continue_stack = 1;
		*Max_happy_ctn_stack = 1;
	}

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
	bool goodGradePlus = grade[cur_week][left_index].grade >= 0;
	bool badGradePlus = grade[cur_week][right_index].grade >= 0;

	if (goodGradePlus && !badGradePlus) return;
	else if ((goodGradePlus && badGradePlus && (grade[cur_week][left_index].grade + 2 <= grade[cur_week][right_index].grade))
		|| (!goodGradePlus && badGradePlus)
		|| (!goodGradePlus && !badGradePlus && (grade[cur_week][left_index].grade + 4 <= grade[cur_week][right_index].grade))) {

		grade[cur_week][left_index].grade += 2;
		grade[cur_week][right_index].grade -= 2;

		INFO swap_buf;
		for (int i = cur_week; i < week - 1; ++i) {
			swap_buf = grade[cur_week][left_index];
			grade[cur_week][left_index] = grade[cur_week][right_index];
			grade[cur_week][right_index] = swap_buf;
		}
	}
}

void GradeJudge(int curr_week, int* prev_happy_week, int* happy_stack, int* happy_continue_stack, int* Max_happy_ctn_stack) {
	int sumDist = st_cnt;
	for (int find_st = 0; find_st < st_cnt; ++find_st) {
		if (grade[curr_week][find_st].marked) {
			grade[curr_week + 1][find_st].marked = true;
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
		if (*prev_happy_week == (curr_week - 1)) {
			*happy_continue_stack += 1;
		}
		else *happy_continue_stack = 1;

		if (*Max_happy_ctn_stack <= *happy_continue_stack) {
			*Max_happy_ctn_stack = *happy_continue_stack;
		}

		*prev_happy_week = curr_week;
		*happy_stack += 1;
	}
	else *happy_continue_stack = 0;
}
 
int main()
{
	int prev_happy_week = -1;
	int happy_stack = 0;
	int happy_ctn_stack = 0;
	int Max_happy_ctn_stack = 0;

	Input(&happy_stack, &happy_ctn_stack, &Max_happy_ctn_stack);

	for (int cur_week = 0; cur_week < week - 1; ++cur_week) {
		for (int cmp_num = 0; cmp_num < st_cnt - 1; ++cmp_num) {
			CompareAndSwap(cur_week, cmp_num, cmp_num + 1);
		}
		GradeJudge(cur_week, &prev_happy_week, &happy_stack, &happy_ctn_stack, &Max_happy_ctn_stack);
	}
	
	printf("%d %d", happy_stack, Max_happy_ctn_stack);
	return 0;
}
