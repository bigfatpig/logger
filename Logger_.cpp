/*#include <iostream>
#include <sstream>
#include <memory>
#include <string>
#include <map>
using namespace std;

class Logger;

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


class Record {
public:
	~Record();
	Record(Logger* lg);
	Record(Record&& o) :  logger_(o.logger_) {
		o.logger_ = nullptr;
	}
	std::stringstream& Stream();
private:
	std::stringstream s_;
	Logger* logger_; 
};

std::ostream& operator<<(std::ostream& os, Record& obj)
{
  os<<obj.Stream().str();
  return os;
}

//////////////////////////////////////////////////////////////
// Logger
class Logger {
public: 
 Record OpenRecord() {
 	return Record(this);
 }
 AttributeCollection& GetAttributes() {
 	return collection_;
 }
 void PushRecord(Record& record) {
 	//push to sink
 	std::cout<<record<<std::endl;
 }

 void AddAtribute(const std::string& tag, AttributePtr att) {
 	collection_[tag] = att;
 }

private:
	AttributeCollection collection_;
};

//////////////////////////////////////////////////////////////
// Record impl
Record::Record(Logger* lg) : logger_(lg) {
		if (logger_) {
			AttributeCollection& coll = logger_->GetAttributes();
			for(auto v : coll) {
				s_<<v;
			}
		
	}

Record::~Record() {
	if (logger_) {
		logger_->PushRecord(*this);
	}
}

	std::stringstream& Record::Stream() {
		return s_;
	}


template<typename T>
AttributePtr* MakeAttribute(const std::string& tag, T value) {
	return make_shared<AttributeImpl<T>>(value);
}


template<typename T>
class Visitor {
public:
	template<typename K>
	void Visit(K* o) {
		static_cast<T*>(this)->Process(o);
	}
};

class VisitorImpl : public Visitor<VisitorImpl> {
public:
	template<typename T>
	void Process(T* o) {
		std::cout<<o->val<<std::endl;
	}
};

template<typename T, typename V>
class Entity {
public:
	Entity(T v) : val(v) {}
	void Accept(Visitor<V>* v) {
		v->Visit(this);
	}
	T val;
};

#include <vector>
int main() {
	Logger l;
	l.AddAtribute("date", make_shared<AttributeImpl<std::string>>("today"));
	l.AddAtribute("pid", make_shared<AttributeImpl<int>>(500));
	l.AddAtribute("pi", make_shared<AttributeImpl<double>>(3.14));
	l.OpenRecord().Stream()<<"data "<<"test "<<"string"<<"!";
	l.OpenRecord().Stream()<<"data "<<"test "<<"string"<<"!";
	l.OpenRecord().Stream()<<"data "<<"test "<<"string"<<"!";
	
	VisitorImpl v;
	Entity<std::string, VisitorImpl> se("hello");
	Entity<int, VisitorImpl> ie(500);
	se.Accept(&v);
	ie.Accept(&v);
	return 0;
}*/