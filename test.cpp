#include "Logger.hpp"

#define LOG(lg) lg.OpenRecord().Stream() 

int main() {
	Logger l;
	LOG(l)<<"Hello, "<<"test! "<<"Data: "<<1024;
	l.OpenRecord().Stream()<<"Hello, "<<"test! "<<"Data: "<<1024;
	l.OpenRecord().Stream()<<"Hello, "<<"test! "<<"Data: "<<1024;
	l.OpenRecord().Stream()<<"Hello, "<<"test! "<<"Data: "<<1024;
	return 0;
}