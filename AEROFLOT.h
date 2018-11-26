#ifndef _AEROFLOT_H_
#define _AEROFLOT_H_

#include "exceptions.h"

class AEROFLOT {
public:
	AEROFLOT();
	AEROFLOT(String& n, size_t nm, String &t);
	AEROFLOT(AEROFLOT &AER);
	~AEROFLOT() {};

	AEROFLOT& operator=(const AEROFLOT& AER);

	friend void move(AEROFLOT &AER1, AEROFLOT &AER2);

	void SetName(const String& s);
	void SetNum(size_t nm);
	void SetType(const String& s);

	const String& GetName() const;
	size_t GetNum() const;
	const String& GetType() const;

	void print();

	friend std::istream& operator>>(std::istream &is, AEROFLOT &AER);
	friend std::ostream& operator<<(std::ostream &os, const AEROFLOT &AER);
private:
	String name;
	size_t num;
	String type;
};

#endif