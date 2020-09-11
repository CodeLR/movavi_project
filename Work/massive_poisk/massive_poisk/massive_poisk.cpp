

#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
    std::vector<int>myVec;
    
    myVec.push_back(10);
    myVec.push_back(3);
    myVec.push_back(43);
    myVec.push_back(65);
    myVec.push_back(2);
    myVec.push_back(18);
    myVec.push_back(44);
    myVec.push_back(65);
    myVec.push_back(3);
    myVec.push_back(99);
    

    // 10 , 43 , 2 , 18 , 44 , 99 
   
    for (int i = 0; i < myVec.size(); ++i)
    {
        for (int j = 0; j < myVec.size(); ++j)
        {   
            if (myVec[i] == myVec[j] && i != j)
            {
                myVec.erase(myVec.begin() + j);
                j--; 
            }
        }
    }
            for (int i = 0; i < myVec.size(); ++i) {
            cout << myVec[i] << " ";
        }
}



