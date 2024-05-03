#include <iostream>

int N;
int DP[16][1 << 16];	//: [현재 도시 위치][방문했던 도시를 비트마크로]
int cost_map[16][16];	//: (N x N) 형식 비용 표

int TSP(int curr, int visited)		// curr: 시작위치, visited: bit로 표현한 방문기록
{
	if (visited == ((1 << N) - 1))	// 모든 도시 방문 완료.
	{
		if (0 == cost_map[curr][0])	// 현위치에서 0번으로 돌아갈 수 없음.
			return 2e9;
		else
			return cost_map[curr][0];// 돌아갈 수 있음.
	}
	
	if (false != DP[curr][visited])	// 이미 방문함.
		return DP[curr][visited];

	DP[curr][visited] = 2e9;	// 첫 방문이므로 최소비용 비교를 위해 최댓값 초기화.

	// bit masking을 사용해 0번부터 N - 1번 노드까지
	// 현재 위치랑 연결되어 있는지 확인
	for (int bit_mask = 0; bit_mask < N; ++bit_mask)
	{
		int next = 1 << bit_mask;

		// 연결(curr->bit_mask)이 안됨 || 이미 방문 했었음.
		if ((0 == cost_map[curr][bit_mask]) || (0 < (visited & next)))
			continue;

		// 현재 노드에서 visited에 비트로 작성된 도시 방문 중 최소값
		DP[curr][visited] = std::min(DP[curr][visited], TSP(bit_mask, visited | next) + cost_map[curr][bit_mask]);
	}
	return DP[curr][visited];
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> N;

	for (int start = 0, cost; start < N; ++start)
	{
		for (int end = 0; end < N; ++end)
		{
			std::cin >> cost;
			cost_map[start][end] = cost;
		}
	}

	printf("%d", TSP(0, 1));
	return 0;
}