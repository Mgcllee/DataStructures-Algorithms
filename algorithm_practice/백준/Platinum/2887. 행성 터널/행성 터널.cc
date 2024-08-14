#include <iostream>
#include <vector>
#include <algorithm>

#define SETTING std::ios::sync_with_stdio(false), std::cin.tie(0)

int N;
std::vector<std::pair<int, int>> planet_pos[3];
std::vector<std::pair<int, std::pair<int, int>>> kruskal_planet;
int* cost_table;

int Kruskal_getParent(int x)
{
	if (cost_table[x] == x) return x;
	return cost_table[x] = Kruskal_getParent(cost_table[x]);
}
void Kruskal_unionParent(int a, int b)
{
	a = Kruskal_getParent(a);
	b = Kruskal_getParent(b);

	if (a < b) cost_table[b] = a;
	else cost_table[a] = b;
}
int Kruskal_find(int a, int b)
 {
	a = Kruskal_getParent(a);
	b = Kruskal_getParent(b);

	if (a == b) return 1;
	else return 0;
}

void Kruskal_input()
{
	std::cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int x, y, z;
		std::cin >> x >> y >> z;

		planet_pos[0].push_back({ x, i });
		planet_pos[1].push_back({ y, i });
		planet_pos[2].push_back({ z, i });
	}

	std::sort(planet_pos[0].begin(), planet_pos[0].end());
	std::sort(planet_pos[1].begin(), planet_pos[1].end());
	std::sort(planet_pos[2].begin(), planet_pos[2].end());
	
	// 거리는 대각, 3차원 거리가 아니라 수직, 수평 거리이다.
	// (x, y, z 중 1개의 좌표값만 비교하므로 전부 알 필요가 없다.) 
	// == (한 행성은 x/y/z 평면에 대한 각각의 위치값(좌표)를 갖기 때문에 3개의 좌표를 소유함)
	for (int i = 1; i < N; ++i)
	{
		kruskal_planet.push_back({ std::abs(planet_pos[0][i - 1].first - planet_pos[0][i].first), {planet_pos[0][i - 1].second, planet_pos[0][i].second} });
		kruskal_planet.push_back({ std::abs(planet_pos[1][i - 1].first - planet_pos[1][i].first), {planet_pos[1][i - 1].second, planet_pos[1][i].second} });
		kruskal_planet.push_back({ std::abs(planet_pos[2][i - 1].first - planet_pos[2][i].first), {planet_pos[2][i - 1].second, planet_pos[2][i].second} });
	}
	std::sort(kruskal_planet.begin(), kruskal_planet.end());

	cost_table = new int[N + 1] {0};
	for (int i = 1; i <= N; ++i)
	{
		cost_table[i] = i;
	}
}
int Kruskal_solve()
{
	int sum = 0;
	for (int i = 0; i < kruskal_planet.size(); ++i)
	{
		if (false == Kruskal_find(kruskal_planet[i].second.first, kruskal_planet[i].second.second))
		{
			sum += kruskal_planet[i].first;
			Kruskal_unionParent(kruskal_planet[i].second.first, kruskal_planet[i].second.second);
		}
	}
	return sum;
}

int main() 
{
	Kruskal_input();
	printf("%d", Kruskal_solve());
	
	return  0;
}