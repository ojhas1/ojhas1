#include<iostream>
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

	Auto_ptr()
	{

	}
	~Auto_ptr()
	{
		delete m_ptr;
	}

	Auto_ptr(Auto_ptr& a)
	{
		m_ptr = new Resource();
		*m_ptr = *a.m_ptr;
	}

	Auto_ptr& operator=(Auto_ptr& a) // note: not const
	{
		if (&a == this)
			return *this;

		delete m_ptr; // make sure we deallocate any pointer the destination is already holding first
		m_ptr = new Resource(); // then transfer our dumb pointer from the source to the local object
		*m_ptr = *a.m_ptr;
		return *this;
	}

	Auto_ptr(Auto_ptr&& a) noexcept
		: m_ptr(a.m_ptr)
	{
		std::cout << "Move Contsructor\n";
		a.m_ptr = nullptr; // we'll talk more about this line below
	}
	Auto_ptr& operator=(Auto_ptr&& a) noexcept
	{
		std::cout << "Move Assignment\n";
		// Self-assignment detection
		if (&a == this)
			return *this;

		// Release any resource we're holding
		delete m_ptr;

		// Transfer ownership of a.m_ptr to m_ptr
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr; // we'll talk more about this line below

		return *this;
	}
};

Auto_ptr passbyValue()
{
	Auto_ptr obj1(new Resource());
	return obj1;// Assign oject to temporray object //call moveconstructore
}
int main()
{
	//Resource *res = new Resource(); // Not Required
	Auto_ptr obj(new Resource());
	Auto_ptr res;
	res = passbyValue();//move assignment
	return 0;
}