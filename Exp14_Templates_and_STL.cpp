// Exp14_Templates_and_STL.cpp
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
using namespace std;

template<typename T>
T myMax(T a, T b) { return (a > b) ? a : b; }

int main() {
    // Template demo
    cout << "Max of 3 and 7: " << myMax(3,7) << '\n';
    cout << "Max of 2.5 and 1.7: " << myMax(2.5,1.7) << '\n';

    // vector demo
    vector<int> v = {1,2,3};
    v.push_back(4);
    cout << "Vector contents: ";
    for (int x: v) cout << x << ' ';
    cout << '\n';
    v.pop_back();

    // list demo
    list<string> lst;
    lst.push_back("apple");
    lst.push_front("banana");
    cout << "List contents: ";
    for (auto &s: lst) cout << s << ' ';
    cout << '\n';

    // map demo
    map<string,int> mp;
    mp["Alice"] = 90;
    mp["Bob"] = 85;
    cout << "Map entries:\n";
    for (auto &p: mp) cout << p.first << " -> " << p.second << '\n';

    // find in map
    auto it = mp.find("Bob");
    if (it != mp.end()) cout << "Found Bob: " << it->second << '\n';
    return 0;
}
