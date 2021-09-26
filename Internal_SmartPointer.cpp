
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
	Auto_ptr(Resource *ptr1): m_ptr (ptr1)
	{
		
	}

	~Auto_ptr()
	{
		delete m_ptr;
	}
};


int main()
{
	//Resource *res = new Resource(); // Not Required
	Auto_ptr obj(new Resource());
	return 0;
}

// Do not use pass by value or copy of objects.