#include <iostream>
#include <List.h>

int main()
{

    List<int> test;

    int vec[14] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    // int vec[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

    for (int x : vec)
    {
        test.add(x);
    }

    cout << test;

    return 0;
}