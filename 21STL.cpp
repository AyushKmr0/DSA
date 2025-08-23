/*
    STL -> Standard Template Library

    STL comes in four parts -
        > Containers
        > Iterators
        > Algorithms
        > Functors

    
        => Sequence Containers
                > Vector 
                > List
                > Deque



    1. > VECTOR --  vector is implemented as a dynamic array
        
    // => Sequence Container

        // -> 01vector.cpp

*/

/*
    2. > LIST --    List is internally implemented as a doubly linked list

    // => Sequence Container


    list<int> l = {1, 2, 3};

    > push_back & puch_font
    > emplace_back & emplace_front
    > pop_back & pop_front

        push_front ->  __________________  <- push_back
    emplace_front ->  |__|__|__|__|__|__|   <- emplace_back
        pop_front  ->                      <- pop_back

    
    // function -> size, erase, clear, begin, end, rbegin, rend, insert, front, back
*/

#include<iostream>
#include<vector>
#include<list>
#include<deque>
#include<stack>
#include<queue>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<algorithm>

using namespace std;

bool comparator(pair<int, int> p1, pair<int, int> p2) {
    if(p1.second < p2.second)
        return true;
    if(p1.second > p2.second)
        return false;
    
        
    if(p1.first < p2.first)
        return true;
    else
        return false;
}
int main() {
    list<int> l;

    // l.push_back(1);
    // l.push_back(2);
    // l.push_front(3);
    // l.push_front(4);
    // l.emplace_front(5);
    // l.emplace_back(6);

    // l.pop_back();
    // l.pop_front();.

    list<int> l1 = {1, 2, 3, 4, 5};
    
    cout << "\nList : ";
    for(int val : l1) {
        cout << val << " ";
    }

    // cout << l1[2];   // -> Random Access is not possible in List

    cout << endl;

/*
    3. > DEQUE (Double Ended Queue) --  Deque is implemented as a double ended queue and it is very similar to a list.

    // => Sequence Container


    deque<int> d = {1, 2, 3};

    > push_back & puch_font
    > emplace_back & emplace_front
    > pop_back & pop_front


    // function -> size, erase, clear, begin, end, rbegin, rend, insert, front, back

*/

    deque<int> d = {1, 2, 3, 4, 5};

    cout << "\nDeque : ";
    for(int val : l1) {
        cout << val << " ";
    }
    
    cout << d[2];   // -> Random Access is possible in Deque
    
    cout << endl << endl;

    
/*
    > Pair - (part of utility library)

    pari<int, int> p = {2, 5};
    pair<char, int> p1 = {'a', 1};

*/

    pair<int, int> p = {2, 3};
    pair<string, int> p1 = {"Ayush", 7};
    pair<int, pair<char, int>> p2 = {1, {'a', 7}};

    cout << "Pair p : " << p.first << " : " << p.second << endl;

    cout << "Pair p1 : " << p1.first << " : " << p1.second << endl;

    cout << "Pair p2 : " << p2.first << " => " << p2.second.first << " : " << p2.second.second << endl;

    cout << endl;

    vector<pair<int, int>> vec = {{1, 2}, {3, 4}, {5, 6}};

    /* vec.push_back() */
    vec.push_back({4, 8});  // assume that we are inserting a pair
    vec.push_back(make_pair(3, 7)); // another way to insert a pair
    vec.emplace_back(5, 9); // emplace_back create object at the time of insertion

    cout << "Vector pair : " << endl;
    for(auto val : vec) {
        cout << val.first << " : " << val.second << endl;
    }
    
    // for(pair<int, int> val : vec) {
        //     cout << val.first << " : " << val.second << endl;
    // }
        
        
    cout << endl;
            
/*
        => Non-Sequence Containers
                > Stack
                > Queue


    1. > STACK --

    stack<int> s;

    functions -> push, emplace, top, pop, size, empty, swap

*/

    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);

    cout << "Stack top element : " << s.top() << endl;
    
    cout << "Stack top element : " << endl;
    while (!s.empty())
    {
        cout << "Top -> " << s.top() << endl;
        s.pop();
    }
    cout << endl;

    stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);

    cout << "size of s1 before swap : " << s1.size() << endl;

    stack<int> s2;
    s2.swap(s1);

    cout << "size of s1 : " << s1.size() << endl;
    cout << "size of s2 : " << s2.size() << endl;
        
        
    cout << endl;
            
/*

    2. > QUEUE --

    queue<int> q;

    functions -> push, emplace, front, pop, size, empty, swap

*/

    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);

    cout << "Queue front element : " << endl;
    while (!q.empty())
    {
        cout << "Font -> " << q.front() << endl;
        q.pop();
    }
    
    cout << endl;
            
/*

    > PRIORITY_QUEUE --

    priority_queue<int> q;
    priority_queue<int, vector<int>, greater<int>> q;   // reverse order priority queue

    functions -> push, emplace, top, pop, size, empty

*/

    priority_queue<int, vector<int>, greater<int>> pq; 

    pq.push(5);
    pq.push(2);
    pq.push(3);
    pq.push(8);
    pq.push(4);
    pq.push(10);

    cout << "Priority Queue top element : " << endl;
    while (!pq.empty())
    {
        cout << "Font -> " << pq.top() << endl;
        pq.pop();
    }

    cout << endl;

/*

    > MAP --

    map<string,int> m;
    m[key] = value

    functions -> insert, emplace, count, erase, find, size, empty 

*/

    map<string, int> m;

    m["TV"] = 50;
    m["Laptop"] = 100;
    m["Headphones"] = 50;
    m["Tablet"] = 80;
    m["Watch"] = 70;

    m.insert({"Camera", 30});
    m.emplace("Phone", 60);

    m.erase("TV");

    cout << "MAP - " << endl;
    for(auto p : m) {
        cout << p.first << " : " << p.second << endl;
    }
    
    cout << "Count = " << m.count("Laptop") << endl;
    cout << "Value of Laptop = " << m["Laptop"] << endl;

    if(m.find("Camera") != m.end()) {
        cout << "Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }

    cout << endl;

/*

    > MULTI MAP --

    multimap<string,int> m;

*/

    multimap<string, int> mm; 

    // mm["tv"] = 100; we can't use this syntax with multimap
    mm.emplace("tv", 100);
    mm.emplace("tv", 110);
    mm.emplace("tv", 120);
    mm.emplace("tv", 130);

    // mm.erase("tv");
    mm.erase(mm.find("tv")); // erase one element with key "tv", this gives us the iterator which means the actual memory location of the element and we can use it to erase the element

    cout << "Multi Map -" << endl;
    for(auto p : mm) {
        cout << p.first << " : " << p.second << endl;
    }

    cout << endl;

/*

    > UNORDERED MAP --

    unordered_map<string,int> m;

*/

    unordered_map<string, int> um;

    um.emplace("tv", 100);
    um.emplace("laptop", 100);
    um.emplace("fridge", 100);
    um.emplace("watch", 100);

    cout << "Unordered Map -" << endl;
    for(auto p : um) {
        cout << p.first << " : " << p.second << endl;
    }

    cout << endl;

/*

    > SET --

    set<int> s;

    functions -> insert, emplace, erase, find, size, empty 

*/

    set<int> st;

    st.insert(5);
    st.insert(1);
    st.insert(2);
    st.insert(6);
    st.insert(3);

    st.insert(1);
    st.insert(2);
    st.insert(3);

    cout << "Set -" << endl;
    for(auto val : st) {
        cout << val << " ";
    }
    cout << "\nSize of set : " << st.size() << endl;

    cout << "Lower Bond value : " << *(st.lower_bound(5)) << endl;
    cout << "Upper Bond value : " << *(st.upper_bound(5)) << endl;

    cout << endl;

/*

    > MULTI SET --

    multiset<int> s;


*/

    multiset<int> mst;

    mst.insert(5);
    mst.insert(1);
    mst.insert(2);
    mst.insert(6);
    mst.insert(3);

    mst.insert(1);
    mst.insert(2);
    mst.insert(3);

    cout << "Multi Set -" << endl;
    for(auto val : mst) {
        cout << val << " ";
    }
    cout << "\nSize of set : " << mst.size() << endl;

    cout << "Lower Bond value : " << *(mst.lower_bound(5)) << endl;
    cout << "Upper Bond value : " << *(mst.upper_bound(5)) << endl;

    cout << endl;

/*

    > UNORDERED SET --

    unordered_set<int> s;


*/

    unordered_set<int> ust;

    ust.insert(5);
    ust.insert(1);
    ust.insert(2);
    ust.insert(6);
    ust.insert(3);

    ust.insert(1);
    ust.insert(2);
    ust.insert(3);

    cout << "Unordered Set -" << endl;
    for(auto val : ust) {
        cout << val << " ";
    }
    cout << "\nSize of set : " << ust.size() << endl;

    cout << endl;


/*

    ** ALGORITHMS **

    > SORTING -

        sort(arr, arr + n)
        sort(arr, arr + n, greater<int>()); // for Reverse Order

*/

    vector<int> arr = {4, 2, 6, 1, 0, 9};
    
    // sort(arr.begin(), arr.end());    // By Default Ascending Order
    sort(arr.begin(), arr.end(), greater<int>()); // For Descending Order
    
    cout << "Sort value - " << endl;
    for(int val : arr) {
        cout << val << " ";
    }

    
    vector<pair<int, int>> arr1 = {{9, 1}, {3, 5}, {4, 1}, {8, 6}};

    // sort(arr1.begin(), arr1.end());
    sort(arr1.begin(), arr1.end(), comparator);

    cout << "\nSort pari value - " << endl;
    for(auto p : arr1) {
        cout << p.first << " : " << p.second << endl;
    }



    return 0; 
}
