import Vector;
import <iostream>;
import <string>;
#include <Windows.h>;

int main() {
	SetConsoleOutputCP(1251);

	Vector<int> vec_int;
	Vector<std::string> vec_string;
	vec_int.add(5);
	vec_int.add(5);
	vec_int.add(6);
	vec_int.add(7);
	vec_int.add(0);
	vec_int.add(3);
	vec_int.add(2);
	std::cout << "Элементы (int): ";
	vec_int.display(std::cout);
	vec_int.sort();
	//std::cout << "Элементы (int): ";
	vec_int.display(std::cout);
	std::cout<<'\n' << vec_int.max_value();
	std::cout<<'\n' << vec_int.min_value()<<'\n';

	vec_int.remove_by_value(5);
	vec_int.display(std::cout);	
	vec_int.add(5);
	vec_int.display(std::cout);
	vec_int.replace_all(5, 10);
	vec_int.display(std::cout);
	vec_int.add(10);
	vec_int.add(10);
	vec_int.add(10);
	vec_int.display(std::cout);
	vec_int.remove_consecutive_duplicates();
	vec_int.add_to_start(3);
	vec_int.display(std::cout);
	vec_int.load_from_file("input.txt");
	std::ofstream outfile("output.txt");
	vec_int.add(22);
	vec_int.display(outfile);

}