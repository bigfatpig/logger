#pragma once
#include <memory>
#include <sstream>

class Logger;

class Record {
public:
	Record(Logger* lg);
	Record(Record&& o);
	~Record();
	std::stringstream& Stream();
	const std::stringstream& Stream() const;
private:
	struct Impl;
	typedef std::unique_ptr<Impl> ImplPtr; 
	ImplPtr impl_;
};

std::ostream& operator<<(std::ostream& os, const Record& obj);