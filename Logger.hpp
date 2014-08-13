#pragma once
#include <memory>
#include "Record.hpp"

class Logger {
public: 
	Logger();
	~Logger();
 Record OpenRecord();
 void PushRecord(const Record& record);
 //AttributeCollection& GetAttributes();
 //void AddAtribute(const std::string& tag, AttributePtr att);
private:
	struct Impl;
	typedef std::unique_ptr<Impl> ImplPtr;
	ImplPtr impl_;
};
