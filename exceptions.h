#ifndef _EXCEPTIONS_H_
#define _EXCEPTIONS_H_

#include "String.h"

class exceptions {
public:
	exceptions(const String& str);
	exceptions(String&& str);
	exceptions(const exceptions& e);
	exceptions(exceptions&& e);
	const String& what();
private:
	String mesg;
};

#endif
