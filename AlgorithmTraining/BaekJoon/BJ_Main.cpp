#include <iostream>
#include <vector>

std::vector<std::vector<int>> memvec;
int M, N;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int MemoDFS(int** arr, int x, int y)
{
	if (x == M - 1 && y == N - 1) return 1;
	if (memvec[x][y] != -1) return memvec[x][y];


	memvec[x][y] = 0;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;

		if (arr[x][y] > arr[nx][ny]) {
			memvec[x][y] += MemoDFS(arr, nx, ny);
		}
	}

	return memvec[x][y];
}

int main() 
{
	std::cin >> M >> N;
	int** arr = new int* [M];
	std::vector<int> buf;
	buf.assign(N, -1);
	memvec.assign(M, buf);

	for (int i = 0; i < M; ++i) {
		arr[i] = new int[N];
		for (int j = 0; j < N; ++j) {
			std::cin >> arr[i][j];
			memvec[i][j] = -1;
		}
	}

	std::cout << MemoDFS(arr, 0, 0);
	return 0;
}