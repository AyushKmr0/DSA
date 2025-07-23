#include <iostream>
#include <vector>

using namespace std;

int main()
{
    /* SYNTAX */

    // vector<int> vec1;
    // vector<int> vec2(4, 1);

    // vector<char> vec = {'a', 'b' , 'c', 'd', 'e'};
    // for(char value : vec) {
    //     cout<< value << " ";
    // }




    /*
    vector Function:
    - size
    - push_back
    - pop_back
    - front
    - back
    - at
    */




    vector<int> vec;

    /* push_back */
    vec.push_back(23);
    vec.push_back(12);
    vec.push_back(65);
    vec.push_back(11);
    vec.push_back(62);

    /* size*/
    cout << "Size: " << vec.size() << endl;

    for (int value : vec)
    {
        cout << "Push back : " << value << endl;
    }


    /* pop_back */
    vec.pop_back(); // 62

    for (int value : vec)
    {
        cout << "Last element popped : " << value << endl;
    }
    

    /* front */
    cout << "First element: " << vec.front() << endl;


    /* back */
    cout << "last element: " << vec.back() << endl;


    /* at */
    cout << "Access element: " << vec.at(2) << endl;


    /* capacity */
    cout << "Capacity: " <<vec.capacity() << endl;

    return 0;
}
