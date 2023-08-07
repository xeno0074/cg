#include "doctest.h"
#include <bits/stdc++.h>

using namespace std;

void sort012(vector<int> &nums)
{
}

TEST_CASE("test")
{
    MESSAGE("test_start");

    vector<int> arr{0, 2, 1, 2, 0, 2, 1, 1, 2, 0, 1, 1, 0, 1, 2, 1, 0, 0, 0};

    sort012(arr);

    MESSAGE("test_end");
}