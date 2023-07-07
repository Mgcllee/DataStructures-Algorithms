# AlgorithmTraining
personal algorithm training
1. Container에 담긴 중복 없는 숫자들을 n(n>=2)개만큼 더한 수의 개수를 파악하는데 아직 어려움이 있음

# [07.03] Programmers
  1. Container에 담긴 중복 없는 숫자들을 n(n>=2)개만큼 더한 수의 개수를 파악하는데 아직 어려움이 있음
  2. 소수 판별 여부는 시간복잡도가 O(nlong(n))인 "에라토스테네스의 채"를 사용하는 것이  모든 약수를 구하는 방법보다<br/>
    더 효율적이라고 판단함.

#[07.05] Programmers
  1. 실패율(2019카카오 코테)에서 일부 채점 결과가 실패하였으나, 오류가 발생하는 테스트 케이스를 찾지 못함.
  2. 테스트 케이스에서는 값이 int에 전부 수용되는 값을 넣었지만 채점에서는 int의 범위 이상의 값 때문에<br/>
    문제가 발생하는 것이라고 예상.

#[07.06] Programmers
  1. Algorithm.h에서 std::sort() Function이 아닌 std::stable_sort() Function을 사용하여 문제해결
  2. 안정 정렬((1, d), (2, b), (2, c), (3, a)에서(2, b), (2, c)는 변경되지 않는 정렬)을 사용함. 

#[07.07] Programmers
  1. vector<int>::iterator를 사용하는데 out_of_range 문제를 해결하지 못함.
  2. vector의 안정적인 사용과 접근을 위해서 out_of_range를 방지할 수 있는 방법을 연구할 필요가 있음.
