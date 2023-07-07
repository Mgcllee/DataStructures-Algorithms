#include "SortFunctions.h"

template <typename T, typename seqCon>
void quickSeqSort(seqCon& con, T start, T end) {
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

    quickSeqSort(con, start, right - 1);
    quickSeqSort(con, right + 1, end);
}

template <typename T, typename seqCon>
void Combination(seqCon vec, seqCon comb, T r, T index, T depth, seqCon& result) {
    if (r == 0) {
        int sum = 0;
        for (int n : comb) {
            sum += n;
        }
        result.push_back(sum);
    }
    else if (depth == vec.size()) {
        return;
    }
    else {
        comb[index] = vec[depth];
        Combination(vec, comb, r - 1, index + 1, depth + 1, result);

        Combination(vec, comb, r, index, depth + 1, result);
    }
}
