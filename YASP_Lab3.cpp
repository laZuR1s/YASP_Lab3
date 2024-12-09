import Vector;
import Angle;

import <iostream>;
import <string>;
#include <Windows.h>;

template<typename X>
void main_menu_output(Vector<X>& vector);

template<typename X>
void main_menu(Vector<X>& vector);
int vector_menu();

template<typename T>
T validated_input();

template <typename value_type>
value_type input_value();

template <>
int input_value<int>();

template <>
std::string input_value<std::string>();

template <>
Angle input_value<Angle>();


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
			main_menu(vec);
			break;
		}
		case 2:
		{
			Vector<std::string> vec;
			std::cout << "Пустой string vector создан!\n";
			main_menu(vec);
			break;
		}
		case 3:
		{
			Vector<Angle> vec;
			std::cout << "Пустой Angle vector создан!\n";
			main_menu(vec);
			break;
		}

		}
	} while (vector_choice != 4);


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

template<typename X>
void main_menu_output(Vector<X>& vector)
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
	std::cout << "8. Поиск наименьшего значения\n";
	std::cout << "9. Удаление одного элемента списка по значению\n";
	std::cout << "10. Изменение всех элементов с данным значением на новое\n";
	std::cout << "11. Удаление из списка совпадающих подряд идущих значений\n";
	std::cout << "12. Выход\n";
	std::cout << "-----------------------------------------------------\n";
}

template<typename X>
void main_menu(Vector<X>& vector)
{
	int choice;
	do {
		main_menu_output(vector);
		do {
			std::cout << "\nВведите пункт меню: ";
			choice = validated_input<int>();
		} while (!(choice >= 0 && choice <= 12));
		std::cin.ignore(std::cin.rdbuf()->in_avail());

		switch (choice)
		{
		case 1: { 
			std::string filename;
			std::cout << "\nВведите имя файла:";
			std::cin >> filename;
			std::ifstream file(filename);
			vector.load_from_file(filename);
			break; }
		case 2:{
			X value=input_value<X>();
			vector.add_to_start(value);
			break; }
		case 3: { 
			std::cout << "\nВведите элемент, который хотите добавить: ";
			X value = input_value<X>();
			vector.add(value);
			break; }
		case 4: { 
			vector.display(std::cout);
				break; }
		case 5: { 
			std::string filename;
			std::cout << "\nВведите имя файла:";
			std::cin >> filename;
			std::ofstream file(filename);
			vector.display(file);
			break; }
		case 6: { 
			if (vector.is_empty())
				std::cout << "\nСписок пуст!\n";
			else
				std::cout << "\nСписок не пуст!\n";
			break; }
		case 7: { 
			std::cout << "\nНаибольшее значение: " << vector.max_value();
			break; }
		case 8: { 
			std::cout << "\nНаименьшее значение: " << vector.min_value();

			break; }
		case 9: { 
			X value = input_value<X>();
			vector.remove_by_value(value);
			break; }
		case 10: { 
			X value = input_value<X>();
			X change_value = input_value<X>();
			vector.replace_all(value, change_value);
			break; }
		case 11: { 
			vector.remove_consecutive_duplicates();
			break; }
		}



	} while (choice != 12);


}

int vector_menu()
{
	std::cout << "\n\n\nВыберите тип вектора\n";
	std::cout << "\n-----------------------------------------------------\n";
	std::cout << "1. Работа с вектором int\n";
	std::cout << "2. Работа с вектором string\n";
	std::cout << "3. Работа с вектором элементов класса\n";
	std::cout << "4. Выход\n";
	std::cout << "-----------------------------------------------------\n";
	int choice;
	do {
		std::cout << "\nВведите пункт меню: ";
		choice = validated_input<int>();
	} while (!(choice >= 0 && choice <= 4));
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	return choice;
}

template <typename value_type>
value_type input_value()
{
	return value_type{};
}

template <>
int input_value<int>()
{
	int value{};
	std::cout << "Введите значение (целое число): ";
	while (!(std::cin >> value))
	{
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cout << "Ошибка ввода! Попробуйте снова: ";
	}
	return value;
}

template <>
std::string input_value<std::string>()
{
	std::string value{};
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::cout << "Введите значение (строка): ";
	std::getline(std::cin, value);
	return value;
}

template <>
Angle input_value<Angle>()
{
	int degrees = input_value<int>();
	int minutes = input_value<int>();
	std::string name{};
	std::cout << "Введите имя угла: ";
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::getline(std::cin, name);
	if (degrees == 0 && minutes < 0)
	{
		minutes = -minutes;
		return Angle(0, 21600 - static_cast<unsigned int>(minutes), name);
	}
	return Angle(degrees, static_cast<unsigned int>(std::abs(minutes)), name);
}