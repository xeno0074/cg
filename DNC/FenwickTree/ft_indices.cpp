#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "pass a value to be checked"
             << "\n";
        return 0;
    }

    int x = atoi(argv[1]);

    cout << "Type 0: " << x << "\n";
    cout << "Previous index: " << (x & (x + 1)) << "\n";
    cout << "Next index: " << (x | (x + 1)) << "\n";

    cout << "Type 1: " << x << "\n";
    cout << "Previous index: " << (x - (x & -x)) << "\n";
    cout << "Next index: " << (x + (x & -x)) << "\n";

    return 0;
}