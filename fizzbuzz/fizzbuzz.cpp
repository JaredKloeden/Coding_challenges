#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char const *argv[])
{
    for (int i = 1; i <= 100; i++)
    {
        string output = "";

        //Check mod 3
        if (i % 3 == 0)
        {
            output += "fizz";
        }
        //Check mod 5
        if (i % 5 == 0)
        {
            output += "buzz";
        }
        //Check either mod 3 or mod 5
        if (output == "")
        {
            cout << i;
        }
        else
        {
            cout << output;
        }
        cout << endl;
    }

    return 0;
}
