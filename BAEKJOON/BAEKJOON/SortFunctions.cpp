#include "SortFunctions.h"

template <typename T, typename seqCon>
void quickSeqSort(seqCon& con, T start, T end, T cur) {
    if (start >= end)    return;

    int pivot = start;
    int left = pivot + 1;
    int right = end;
    int temp;

    while (left <= right) {
        while (left <= end && con[left] <= con[pivot]) {
            left++;
        }
        while (start < right && con[right] >= con[pivot]) {
            right--;
        }

        if (left > right) {
            temp = con[right];
            con[right] = con[pivot];
            con[pivot] = temp;
        }
        else {
            temp = con[right];
            con[right] = con[left];
            con[left] = temp;
        }
    }

    quickSeqSort(con, start, right - 1, cur);
    quickSeqSort(con, right + 1, end, cur);
}
