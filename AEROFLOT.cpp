#include "AEROFLOT.h"

AEROFLOT::AEROFLOT() : num(0) {}
AEROFLOT::AEROFLOT(String& n, size_t nm, String &t) :
	name(n), num(nm), type(t) {}
AEROFLOT::AEROFLOT(AEROFLOT &AER) :
	name(AER.name), num(AER.num), type(AER.type) {}


AEROFLOT& AEROFLOT::operator=(const AEROFLOT& AER) {
	if (this != &AER) {
		name = AER.name;
		num = AER.num;
		type = AER.type;
	}

	return *this;
}

void move(AEROFLOT &AER1, AEROFLOT &AER2) {
	move(AER1.name, AER2.name);
	AER1.num = AER2.num;
	AER2.num = 0;
	move(AER1.type, AER2.type);
}

void AEROFLOT::SetName(const String& s) {
	name = s;
}
void AEROFLOT::SetNum(size_t nm) {
	num = nm;
}
void AEROFLOT::SetType(const String &t) {
	type = t;
}

const String& AEROFLOT::GetName() const  {
	return name;
}
size_t AEROFLOT::GetNum() const {
	return num;
}
const String& AEROFLOT::GetType() const  {
	return type;
}

void AEROFLOT::print() {
	int width = 20;
	std::cout.width(width);
	std::cout << "Пункт назначения: ";
	std::cout << name;
	std::cout << std::endl;

	std::cout.width(width);
	std::cout << "Номер рейса: ";
	std::cout << num;
	std::cout << std::endl;
}

std::istream& operator>>(std::istream &is, AEROFLOT &AER) {
	std::cout << "Введите название пункта назначения: ";
	is >> AER.name;

	std::cout << "Введите номер рейса: ";
	is >> AER.num;
	is.get();

	std::cout << "Введите тип самолёта: ";
	is >> AER.type;

	return is;
}
std::ostream& operator<<(std::ostream &os, const AEROFLOT &AER) {
	int width = 20;
	os.width(width);
	os << "Пункт назначения: ";
	os << AER.name;
	os << std::endl;

	os.width(width);
	os << "Номер рейса: ";
	os << AER.num;
	os << std::endl;

	os.width(width);
	os << "Тип самолёта: ";
	os << AER.type;
	os << std::endl;

	return os;
}