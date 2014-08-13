#include "Record.hpp"
#include "Logger.hpp"

struct Record::Impl {
	std::stringstream s_;
	Logger* logger_;
};

Record::Record(Logger* lg)
	: impl_(new Impl) 
{
	impl_->logger_  = lg;
}

Record::Record(Record&& o) : impl_(std::move(o.impl_))
{}

Record::~Record() {
	if (impl_->logger_) {
		impl_->logger_->PushRecord(*this);
	}
}

std::stringstream& Record::Stream() {
	return impl_->s_;
}

const std::stringstream& Record::Stream() const {
	return static_cast<const std::stringstream&>((const_cast<Record*>(this))->Stream());
}

std::ostream& operator<<(std::ostream& os, const Record& obj)
{
  os<<obj.Stream().str();
  return os;
}