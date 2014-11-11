


#include <iostream>
#include <limits>


double f(double x){
	return((1 + x)*log(1 + x) - x);
}

void binary_search_f(long double target){
	long double lowerbound=1e-5;
	long double upperbound=1e50;
	int iterations = 2000;

	long double mid;


	//std::cout.precision(std::numeric_limits< long double >::digits10);

	std::cout.precision(50);


	for (int c = 0; c <= iterations; c++){
		mid = lowerbound/2.0 + upperbound/2.0;

		if (f(mid) < target){
			lowerbound = mid;
		}
		else{
			upperbound = mid;
		}


		if (c % 200 == 0){
			std::cout << lowerbound << "  " << upperbound << " -> " << f(mid) << "\n";
		}
	}

}

int main(){
	binary_search_f(10.0);
	int keks;
	std::cin >> keks;

}