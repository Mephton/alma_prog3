


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

		double x = lowerbound*(1.0 + 10e-10);
		if (x > upperbound){
			break;
		}
	}
	std::cout.precision(50);
	std::cout << lowerbound << "  " << upperbound << " -> " << f(mid) << "\n";
}

int main(){

	binary_search_f(17);
	int keks;
	std::cin >> keks;

}