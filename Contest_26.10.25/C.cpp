#include <iostream>
 
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	double d, a, o, ad, od;
	std::cin >> d >> a >> o >> ad >> od;
	std::cout.precision(8);
	if(o - d * od <= 0){
		std::cout << 100;
	}else if(a - d * ad <= 0){
		std::cout << 0;
	}else{
		std::cout << (a - d * ad) / ((a - d * ad) + (o - d * od)) * 100.0;
	}
}