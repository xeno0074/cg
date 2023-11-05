// https://leetcode.com/explore/learn/card/hash-table/187/conclusion-hash-table/1141/

#include <bits/stdc++.h>

using namespace std;

class RandomizedSet
{
    unordered_set<int> st;

public:
    RandomizedSet() {}

    bool insert(int val)
    {
        if (st.count(val) > 0)
        {
            return false;
        }
        else
        {
            st.insert(val);
            return true;
        }
    }

    bool remove(int val)
    {
        if (st.count(val) > 0)
        {
            st.erase(val);
            return true;
        }
        else
        {
            return false;
        }
    }

    int getRandom()
    {
        int rn = rand() % (st.size());

        auto it = begin(st);
        advance(it, rn);

        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main()
{
    RandomizedSet *obj = new RandomizedSet();

    cout << obj->insert(3) << endl;
    cout << obj->remove(3) << endl;
    cout << obj->insert(4) << endl;
    cout << obj->getRandom() << endl;

    return 0;
}