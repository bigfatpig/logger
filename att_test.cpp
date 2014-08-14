/*class Attribute {
	public:
		struct Impl
		{	
			virtual ~Impl(){}
			virtual AttributeValue GetValue() = 0;
		};
		Impl* m_impl;
		Attribute(Impl* i) : m_impl(i) {}
};

class AttributeValue {
public:
	struct Impl : public Attribute::Impl
		{	
			virtual ~Impl(){}
			AttributeValue GetValue() {
				AttributeValue(this);
			}
		};
		Impl* m_impl;
		AttributeValue(Impl* i) {std::swap(i, m_impl);}
		AttributeValue() : m_impl(nullptr) {}
}

template <typename T>
class AttributeValueImpl : public AttributeValue::Impl {
public:
	T value;
}*/

class Attribute {
	public:
		struct Impl
		{	
			virtual ~Impl(){}
			virtual AttributeValue* GetValue() = 0;
		};
		Impl* m_impl;
		Attribute(Impl* i) : m_impl(i) {}
		AttributeValue GetValue() {
			return m_impl->GetValue();
		}
};

/*
template<typename T>
class Callback {
	void operator()(T val) = 0;
}
*/

class Dispatcher {
public:
	template<typename T>
	void operator()(T val) {std::cout<<std::typeid(T)<<std::endl;};
	/*
	template<typename T>
	Callback<T> GetCallback() {return Callback<T>();}
	*/
};

class AttributeValue {
public:
	struct Impl : public Attribute::Impl
		{	
			virtual ~Impl(){}
			// factory
			AttributeValue GetValue() {
				return AttributeValue(this);
			}
			virtual void Dispatch() = 0;
		};
	private:
		Impl* m_impl;
	public:
		void Dispatch(Dispatcher* d) {
			m_impl.Dispatch(d);
		}
		AttributeValue(Impl* i) {std::swap(i, m_impl);}
}

template <typename T>
class AttributeValueImpl : public AttributeValue::Impl {
public:
	T Get() { return value; }
	void Dispatch(Dispatcher* d) {
		// impl of dispatch
		//Callback<T> c = d->GetCallback<T>();
		//c(value);
		d(value);
	} 

	T value;
}

template<typename T>
Attribute GetAttribute(T value) {
	return Attribute(new AttributeValueImpl<T>(value));
}

int main() {
	auto a1 = GetAttribute(3);
	auto a2 = GetAttribute("string val");

	return 0;
}