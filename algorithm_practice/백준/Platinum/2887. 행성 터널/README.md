# [Platinum V] 행성 터널 - 2887 

[문제 링크](https://www.acmicpc.net/problem/2887) 

### 성능 요약

메모리: 15108 KB, 시간: 240 ms

### 분류

그래프 이론, 최소 스패닝 트리, 정렬

### 제출 일자

2024년 4월 18일 14:43:56

### 문제 설명

<p>
	때는 2040년, 이민혁은 우주에 자신만의 왕국을 만들었다. 왕국은 N개의 행성으로 이루어져 있다. 민혁이는 이 행성을 효율적으로 지배하기 위해서 행성을 연결하는 터널을 만들려고 한다.</p>

<p>
	행성은 3차원 좌표위의 한 점으로 생각하면 된다. 두 행성 A(x<sub>A</sub>, y<sub>A</sub>, z<sub>A</sub>)와 B(x<sub>B</sub>, y<sub>B</sub>, z<sub>B</sub>)를 터널로 연결할 때 드는 비용은 min(|x<sub>A</sub>-x<sub>B</sub>|, |y<sub>A</sub>-y<sub>B</sub>|, |z<sub>A</sub>-z<sub>B</sub>|)이다.</p>

<p>
	민혁이는 터널을 총 N-1개 건설해서 모든 행성이 서로 연결되게 하려고 한다. 이때, 모든 행성을 터널로 연결하는데 필요한 최소 비용을 구하는 프로그램을 작성하시오.</p>

### 입력 

 <p>
	첫째 줄에 행성의 개수 N이 주어진다. (1 ≤ N ≤ 100,000) 다음 N개 줄에는 각 행성의 x, y, z좌표가 주어진다. 좌표는 -10<sup>9</sup>보다 크거나 같고, 10<sup>9</sup>보다 작거나 같은 정수이다. 한 위치에 행성이 두 개 이상 있는 경우는 없다. </p>

### 실패 이유 

 <p> 
	 
```cpp 
// sizeof(INFO) == 16
class INFO
{
public:
	INFO(int any_pos, int number) :
		_start(any_pos)
		, _planet_number(number)
		, _cost(0)
	{

	}
	INFO(int any_pos, int start, int end) :
		_cost(std::abs(planet_pos[any_pos][start - 1].get_cost() - planet_pos[any_pos][start].get_cost()))
		, _start(planet_pos[any_pos][start].get_number())
		, _end(planet_pos[any_pos][end].get_number())
	{

	}

	bool operator< (INFO& rhs)
	{
		if (_cost == 0)
		{
			return this->_start < rhs._start;
		}
		else return this->_cost < rhs._cost;
	}

	int get_cost() { return _cost; }
	int get_number() { return _planet_number; }
	int get_start() { return _start; }
	int get_end() { return _end; }
private:
	int _cost;
	int _start, _end;
	int _planet_number;
};
```

위의 코드를 행성 정보를 담는데 사용했습니다.  
INFO 객체 1개의 크기는 작지만 최대 100,000개의 행성이 생성될 수 있고  
객체가 여러 개 생성되므로 메모리 부족이 발생했습니다.  
따라서 가독성은 떨어지지만 최소한의 메모리를 사용하고자 std::pair를 사용하였습니다.
