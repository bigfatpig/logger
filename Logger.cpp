#include "Logger.hpp"
#include <iostream>


 struct Logger::Impl {
 	//AttributeCollection collection_;
 	~Impl() = default;
 };

 Logger::Logger()
 	: impl_(new Impl) {}

	Logger::~Logger() {}

 Record Logger::OpenRecord() {
 	return Record(this);
 }

 void Logger::PushRecord(const Record& record) {
 	//push to sink
 	std::cout<< record <<std::endl;
 }

 /*

 class Attribute {
public:
	Attribute(){}
	~Attribute(){}
};

template<typename T>
class AttributeImpl : public Attribute {
public:
	typedef T value_type;
	AttributeImpl(T val) : value(val) {}
	T value;
};

typedef std::shared_ptr<Attribute> AttributePtr;
typedef std::map<std::string, AttributePtr> AttributeCollection;

 AttributeCollection& Logger::GetAttributes() {
 	return impl_->collection_;
 }

 void Logger::AddAtribute(const std::string& tag, AttributePtr att) {
 	impl_->collection_[tag] = att;
 }
 */
