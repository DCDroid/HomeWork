#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>

int first()
{
	std::string s;
	std::ifstream fin("in_1.txt");

	if (!fin.is_open()) {
		std::cout << "Open error" << std::endl;
		return ERROR_OPEN_FILES;
	}

	while (!(fin >> s).eof()) {
		std::cout << s << std::endl;
	}
	fin.close();

	return EXIT_SUCCESS;
}

int second()
{
	std::string s, sub_s;
	std::ifstream fin("in_2.txt");

	if (!fin.is_open()) {
		std::cout << "Open error" << std::endl;
		return ERROR_OPEN_FILES;
	}

	int* arr = nullptr;
	int size{};

	for (int i{}; fin >> s; i++) {
		if (i == 0) {
			size = atoi(s.c_str());
			arr = new int[size];
		}
		else if (i <= size) {
			arr[i-1] = atoi(s.c_str());
		}
	}
	
	for (int i{ size - 1 }; i >= 0; i--) std::cout << arr[i] << " ";

	delete[] arr;
	fin.close();

	return EXIT_SUCCESS;
}

int third()
{
	std::string s;
	std::ofstream fout("out_1.txt");

	if (!fout.is_open()) {
		std::cout << "Open error" << std::endl;
		return ERROR_OPEN_FILES;
	}

	int size{};

	std::cout << "Enter array size: ";
	std::cin >> size;
	int* arr = new int[size];

	for (int i{}; i < size; i++) {
		std::cout << "arr[" << i << "]= ";
		std::cin >> arr[i];
	}

	fout << size << "\n";

	for (int i{}; i < size; i++) {
		fout << arr[i] << " ";
	}

	delete[] arr;
	fout.close();

	return EXIT_SUCCESS;
}

int four()
{
	std::string s;
	std::ifstream fin("in_4.txt");

	if (!fin.is_open()) {
		std::cout << "Open error" << std::endl;
		return ERROR_OPEN_FILES;
	}

	int size_a{}, size_b{};

	int** arr = nullptr;

	for (int i{}, p{}, q{}; fin >> s; i++) {
		if (i == 0) {
			size_a = atoi(s.c_str());
		}
		else if (i == 1) {
			size_b = atoi(s.c_str());
			arr = new int* [size_a];
			for (int j{}; j < size_a; j++) {
				arr[j] = new int[size_b];
			}
		}
		else {
			if (p == size_a) {
				std::cout << "Size error" << std::endl;
				break;
			}
			arr[p][q] = atoi(s.c_str());
			q++;
			if (q == size_b) {
				q = 0;
				p++;

			}

		}
	}

	for (int i{}; i < size_a; i++) {
		for (int j{ size_b - 1 }; j >= 0; j--) {
			std::cout << arr[i][j] << " ";
		}
		std::cout << '\n';
	}

	for (int i{}; i < size_a; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	fin.close();

	return EXIT_SUCCESS;
}

int main()
{
	SetConsoleOutputCP(CP_UTF8);

	// first();
	// second();
	// third();
	four();

	return EXIT_SUCCESS;
}
