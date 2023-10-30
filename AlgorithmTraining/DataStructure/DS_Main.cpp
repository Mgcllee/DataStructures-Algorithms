#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <type_traits>

template<typename ... Args>
auto build_array(Args&&... args) -> std::array<typename std::common_type<Args...>::type, sizeof...(args)>
{
	using commonType = typename std::common_type<Args...>::type;
	return { std::forward<commonType>((Args&&)args)... };
}

template<class Container, class Index>
auto authAndAccess(Container& c, Index i) -> decltype(c[i]) {
	
	return c[i];
}

int main() {
	auto data = build_array(1, 0u, 'a', 3.2f, false);
	// for (auto i : data)	std::cout << i << " ";

	std::deque<int> d;
	std::cout <<
	authAndAccess(d, 5) = 10;
}
