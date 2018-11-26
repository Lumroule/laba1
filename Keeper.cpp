#include "Keeper.h"
#include "string.h"

Keeper::Keeper() : size(0) {
	mas = new AEROFLOT[Keeper::COUNT];
}
Keeper::~Keeper() {
	delete[] mas;
}

void Keeper::operator+=(const AEROFLOT &AER) {
	int i, j;
	if (size == Keeper::COUNT)
		throw exceptions("������ AEROFLOT �����. ��������� ����� ������ ������.");
	for (i = 0; i < size; ++i) {
		if (AER.GetName() < mas[i].GetName())
			break;
	}
	if (size) {
		for (j = size - 1; j >= i; --j)
			move(mas[j + 1], mas[j]);
	}
	mas[i] = AER;
	++size;
}
void Keeper::remove(int dec) {
	int i;
	if (dec < 0 || dec >= size)
		throw exceptions("������ �������� �����.");
	for (i = dec; i < size; ++i)
		move(mas[i], mas[i + 1]);
	--size;
}

void Keeper::print(const String &s) {
	int j = 0;
	bool flag = true;
	for (int i = 0; i < size; ++i) {
		if (mas[i].GetType() == s) {
			std::cout << '(' << j++ + 1 << ')' << std::endl;
			mas[i].print();
			flag = false;
			std::cout << std::endl;
		};
	}
	if (flag)
		throw exceptions("��� �������� ������ ����.");
}

std::ostream& operator<<(std::ostream& os, const Keeper &kpr) {
	if (!kpr.size)
		os << "������ ������� ����." << std::endl;
	for (int i = 0; i < kpr.size; ++i) {
		os << '(' << i + 1 << ')' << std::endl;
		os << kpr.mas[i];
		os << std::endl;
	}

	return os;
}
std::istream& operator>>(std::istream& is, Keeper &kpr) {
	AEROFLOT AER;
	int N;
	std::cout << "������� �������� �������? ";
	is >> N;
	is.get();
	std::cout << std::endl;
	if (N > Keeper::COUNT || N <= 0)
		throw exceptions("��������� �������� �����.");
	for (int i = 0; i < N; ++i) {
		std::cout << '(' << i + 1 << ')' << std::endl;
		is >> AER;
		kpr += AER;
		std::cout << std::endl;
	}

	return is;
}