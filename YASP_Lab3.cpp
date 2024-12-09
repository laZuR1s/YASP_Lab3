import Vector;
import <iostream>;
import <string>;
#include <Windows.h>;
void main_menu_output();

void main_menu();
int vector_menu();

template<typename T>
T validated_input();

int main() {
	SetConsoleOutputCP(1251);

	int choice;
	int vector_choice;
	do {
		vector_choice = vector_menu();
		switch (vector_choice)
		{
		case 1:
		{
			Vector<int> vec;
			std::cout << "Пустой int vector создан!\n";
			break;
		}
		case 2:
		{
			Vector<std::string> vec;
			std::cout << "Пустой string vector создан!\n";
			break;
		}

		}
	} while (vector_choice != 4);



	//Vector<int> vec_int;
	//Vector<std::string> vec_string;
	//vec_int.add(5);
	//vec_int.add(5);
	//vec_int.add(6);
	//vec_int.add(7);
	//vec_int.add(0);
	//vec_int.add(3);
	//vec_int.add(2);
	//std::cout << "Элементы (int): ";
	//vec_int.display(std::cout);
	//vec_int.sort();
	////std::cout << "Элементы (int): ";
	//vec_int.display(std::cout);
	//std::cout<<'\n' << vec_int.max_value();
	//std::cout<<'\n' << vec_int.min_value()<<'\n';

	//vec_int.remove_by_value(5);
	//vec_int.display(std::cout);	
	//vec_int.add(5);
	//vec_int.display(std::cout);
	//vec_int.replace_all(5, 10);
	//vec_int.display(std::cout);
	//vec_int.add(10);
	//vec_int.add(10);
	//vec_int.add(10);
	//vec_int.display(std::cout);
	//vec_int.remove_consecutive_duplicates();
	//vec_int.add_to_start(3);
	//vec_int.display(std::cout);
	//vec_int.load_from_file("input.txt");
	//std::ofstream outfile("output.txt");
	//vec_int.add(22);
	//vec_int.display(outfile);

}

template<typename T>
T validated_input() {
	T data;

	while (true) {
		std::cin >> data;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail());
			std::cout << "Ошибка ввода!\n";
		}
		else {
			return data;
		}
	}
}

void main_menu_output()
{
	std::cout << "\n\n\nМеню\n";
	std::cout << "\n-----------------------------------------------------\n";
	std::cout << "1. Инициализация списка из файла\n";
	std::cout << "2. Добавить элемент в начало списка\n";
	std::cout << "3. Добавить элемент в конец списка\n";
	std::cout << "4. Напечатать список \n";
	std::cout << "5. Сохранить список в файл\n";
	std::cout << "6. Проверка на пустоту\n";
	std::cout << "7. Поиск наибольшего значения\n";
	std::cout << "8. Удаление одного элемента списка по значению\n";
	std::cout << "9. Изменение всех элементов с данным значением на новое\n";
	std::cout << "10. Удаление из списка совпадающих подряд идущих значений\n";
	std::cout << "11. Выход\n";
	std::cout << "-----------------------------------------------------\n";
}

void main_menu()
{
	int choice;
	do {
		main_menu_output();
		do {
			std::cout << "\nВведите пункт меню: ";
			choice = validated_input<int>();
		} while (!(choice >= 0 && choice <= 11));
		std::cin.ignore(std::cin.rdbuf()->in_avail());

		switch (choice)
		{
		case 1: { break; }
		case 1: { break; }
		case 1: { break; }
		case 1: { break; }
		case 1: { break; }
		case 1: { break; }
		case 1: { break; }
		case 1: { break; }
		case 1: { break; }
		case 1: { break; }
		}



	}while(choice!=11)


}

int vector_menu()
{
	std::cout << "\n\n\nВыберите тип вектора\n";
	std::cout << "\n-----------------------------------------------------\n";
	std::cout << "1. Работа с вектором int\n";
	std::cout << "2. Работа с вектором string\n";
	std::cout << "3. Работа с вектором элементов класса\n";
	std::cout << "3. Просмотреть методы Vector\n";
	std::cout << "4. Выход\n";
	std::cout << "-----------------------------------------------------\n";
	int choice;
	do {
		std::cout << "\nВведите пункт меню: ";
		choice = validated_input<int>();
	} while (!(choice >= 0 && choice <= 5));
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	return choice;
}
