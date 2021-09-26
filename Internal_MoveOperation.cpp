#include<iostream>

#include <iostream>
class Resource
{
public:
	Resource()
	{
		std::cout << "Resource Acquired\n";
	}
	~Resource()
	{
		std::cout << "Resource Destroyed\n";
	}
};
class Auto_ptr
{
private:
	Resource* m_ptr;
public:
	Auto_ptr(Resource* ptr1) : m_ptr(ptr1)
	{

	}

	~Auto_ptr()
	{
		delete m_ptr;
	}

	Auto_ptr(Auto_ptr& a)
	{
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr;
	}

	Auto_ptr& operator=(Auto_ptr& a) // note: not const
	{
		if (&a == this)
			return *this;

		delete m_ptr; // make sure we deallocate any pointer the destination is already holding first
		m_ptr = a.m_ptr; // then transfer our dumb pointer from the source to the local object
		a.m_ptr = nullptr; // make sure the source no longer owns the pointer
		return *this;
	}
};

int main()
{
	//Resource *res = new Resource(); // Not Required
	Auto_ptr obj(new Resource());
	return 0;
}