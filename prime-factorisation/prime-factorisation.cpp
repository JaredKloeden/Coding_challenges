#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    long int num;
    cout << "Enter a positive integer greater than 1: ";
    cin >> num;

    if (num < 2)
    {
        cout << "Please enter an integer greater than 1" << endl;
        return 1;
    }

    vector<int> factors;

    //Check for multiple of two
    if (num % 2 == 0)
    {
        factors.push_back(2);
    }

    //Check all remaining odd factors
    for (int i = 3; i < num; i = i + 2)
    {
        if (num % i == 0)
        {
            factors.push_back(i);
        }
    }

    cout << "The prime factors are:" << endl;

    //Prime number
    if (factors.size() == 0)
    {
        cout << num << endl;
        cout << "(It is a prime number)" << endl;
    }
    else
    //Ouput factors
    {
        for (int i = 0; i < factors.size(); i++)
        {
            bool repeated = false;

            //Ensure only output prime factors
            for (int k = 0; k < i; k++)
            {
                if (factors[i] % factors[k] == 0)
                {
                    repeated = true;
                }
            }

            if (!repeated)
            {
                cout << factors[i] << endl;
            }
        }
    }
    return 0;
}
