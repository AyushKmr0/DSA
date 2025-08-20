#include <iostream>
#include <vector>

using namespace std;

void printArr(vector<int>& arr) {
    for(int val : arr) {
        cout << val << " ";
    }
}

int main()
{
    /* SYNTAX */

    // vector<int> vec1;

    /*
    // vector<int> vec2(4, 1);
    vector<char> vec = {'a', 'b' , 'c', 'd', 'e'};
    for(char value : vec) {
        cout<< value << " ";
    }
    */




    /*
    vector Function:
    - size()
    - capacity()
    - push_back()
    - pop_back()
    - emplace_back()
    - front()
    - back()
    - at(), []

    - erase()
    - insert()
    - clear()
    - empty()
    */




    vector<int> vec;

    /* push_back */
    vec.push_back(23);
    vec.push_back(12);
    vec.push_back(65);
    vec.push_back(11);
    vec.push_back(62);

    /* size() */
    cout << "Size: " << vec.size() << endl;

    for (int value : vec)
    {
        cout << "Push back : " << value << endl;
    }


    /* pop_back() */
    vec.pop_back(); // 62

    for (int value : vec)
    {
        cout << "Last element popped : " << value << endl;
    }
    

    /* front() */
    cout << "First element: " << vec.front() << endl;


    /* back() */
    cout << "last element: " << vec.back() << endl;


    /* at(), [] */
    cout << "Access element: " << vec.at(2) << endl;
    cout << "Access element: " << vec[2] << endl;

    /* capacity() */
    cout << "Capacity: " <<vec.capacity() << endl;

    vector<int> arr = {1, 2, 3, 4, 5, 6};

    cout << "Array: ";
    printArr(arr);

    /* erase() */
    arr.erase(arr.begin());  // 1 -> erase
    arr.erase(arr.begin() + 2); // 3 -> erase

    cout << "\nErase element: ";
    printArr(arr);

    /* insert() */
    arr.insert(arr.begin() + 2, 100);

    cout << "\nInsert element 100 at idx 2 : ";
    printArr(arr);

    /* clear() */
    arr.clear();
    cout<<"\nClear Array: ";
    printArr(arr);
    cout << "\nsize of array: " << arr.size() << endl;
    cout << "capacity of array: " << arr.capacity() << endl;

    /* empty() */
    cout << "Array is empty or not (i.e., 1 -> True / 0 -> False) : " << arr.empty() << endl;



    cout << endl
         << endl;



    /*  VECTOR ITERATORS */


    /*
        > vec.begin()
        > vec.end()
        > vec.rbegin()
        > vec.rend()
    */

    vector<int> vec2 = {1, 2, 3, 4, 5, 6};

    /* .begin(), .end()*/
    vector<int>::iterator it;

    cout << "Iterator begin(), end() : ";
    for (it = vec2.begin(); it != vec2.end(); it++) {
        cout << *(it) << " ";
    }

    /* .rbegin(), .rend()*/
    cout << "\nReverse Iterator rbegin(), rend() : ";

    // for (vector<int>::iterator it = vec2.begin(); it != vec2.end(); it++) { }

    for (auto it = vec2.rbegin(); it != vec2.rend(); it++) {
        cout << *(it) << " ";
    }

        return 0;
}
