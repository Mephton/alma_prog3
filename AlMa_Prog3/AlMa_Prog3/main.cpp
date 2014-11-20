


#include <iostream>
#include <limits>


double f(double x){
	return((1 + x)*log(1 + x) - x);
}

void binary_search_f(long double target){
	long double lowerbound=1e-5;
	long double upperbound=1e50;
	long double mid;

	while ((upperbound - lowerbound) > (1e-10) * lowerbound)
	{
		mid = lowerbound/2.0 + upperbound/2.0;

		if (f(mid) < target){
			lowerbound = mid;
		}
		else{
			upperbound = mid;
		}
	}

	std::cout.precision(50);
	std::cout << lowerbound << "  " << upperbound << " -> " << f(lowerbound / 2.0 + upperbound / 2.0) << "\n";
}

int main(){
	long double y;
	while (true){
		std::cin >> y;
		binary_search_f();
	}
}