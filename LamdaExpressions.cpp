#include<iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1 = { 3, 1, 7, 9 };
    vector<int> v2 = { 10, 2, 7, 16, 9 };

    auto func = [&](int m)
    {
        v1.push_back(m);
        v2.push_back(m);
    };

    func(20);


}
