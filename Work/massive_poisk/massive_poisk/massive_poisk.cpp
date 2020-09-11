

#include <iostream>
#include <vector>
#include <iterator>

using namespace std;
void Foo(vector<int>& vec);
int main()
{
    std::vector<int>myVec;
    
    myVec.push_back(10);
    myVec.push_back(3);
    myVec.push_back(43);
    myVec.push_back(43);
    myVec.push_back(43);
    myVec.push_back(65);
    myVec.push_back(2);
    myVec.push_back(18);
    myVec.push_back(44);
    myVec.push_back(65);
    myVec.push_back(3);
    myVec.push_back(43);
    myVec.push_back(99);
    Foo(*&myVec);
    for (int i = 0; i < myVec.size(); ++i) {
        cout << myVec[i] << " ";
    }
}
void Foo(vector<int>& vec) {
    for (int i = 0; i < vec.size(); ++i)
    {
        for (int j = 0; j < vec.size(); ++j)
        {
            if (vec[i] == vec[j] && i != j)
            {
                cout << i <<endl;
                vec.erase(vec.begin() + j);
                j--;
            }
        }
    }
}



