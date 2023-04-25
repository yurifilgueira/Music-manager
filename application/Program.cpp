#include <iostream>
#include <List.h>

using std::cin;

int main()
{

    List<int> test;

    int x;

    cin >> x;

    int y = 0;
    for (int i = 0; i < x; i++)
    {
        test.add(y);
        y++;
    }

    cout << test;

    return 0;
}