#ifndef _STRING_H_
#define _STRING_H_

#include <iostream>
#include "string.h"
#include "function_String.h"

#define MAX_SIZE 2048

class String {
public:
	String();
	String(const char *str);
	String(const String &obj);
	String(String &&obj);
	~String();
	String& operator=(const char* str);
	String& operator=(const String &obj);
	String& operator=(String &&obj);

	friend bool operator==(const String &Obj1, const String &Obj2);

	friend bool operator<(const String &Obj1, const String &Obj2);

	friend void move(String &str1, String &str2);

	friend std::istream& operator>>(std::istream& is, String &Obj);
	friend std::ostream& operator<<(std::ostream& os, const String &Obj);

	void create(const char* str);
	void create(const char *str, int L, int R);
	void clear();
private:
	char* str;
	int len;
};

#endif