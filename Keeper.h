#ifndef _KEEPER_H_
#define _KEEPER_H_

#include "AEROFLOT.h"
#include "string.h"

class Keeper {
public:
	enum {
		COUNT = 7
	};

	Keeper();
	~Keeper();

	void operator+=(const AEROFLOT &AER);
	void remove(int dec);

	void print(const String &s);

	friend std::ostream& operator<<(std::ostream& os, const Keeper &kpr);
	friend std::istream& operator>>(std::istream& is, Keeper &kpr);

	int GetSize() const { return size; }

private:
	AEROFLOT *mas;
	int size;
};

#endif