#include <iostream>
#include <stdio.h>
using namespace std;

int main(){

	int a, b;

	a = scanf("%i");


	char operation;
	while (true){
		cin >> a >> operation >> b;

		switch (operation)
		{
		case '+':
			cout << a + b;
			break;
		case '-':
			cout << a - b;
			break;
		case '*':
			cout << a * b;
			break;
		case '/':
			cout << (float)a / (float)b;
			break;
		case '^':
			cout << pow(a,b);
			break;
		default:
			break;
		}

		cout << "\n";
	}
	return 0;
}