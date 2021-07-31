#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool calculate(string equation)
{
    string number = "";
    char prev_op;
    int param1;
    int param2;
    bool filled = false;

    for (int i = 0; i < equation.length(); i++)
    {

        //Check current char is part of a number
        if (equation[i] != '+' && equation[i] != '*' && equation[i] != '-' && i != (equation.length() - 1))
        {
            number += equation[i];
        }
        //Code for first number
        else if (!filled)
        {
            param1 = stoi(number, nullptr, 10);
            number = "";
            filled = true;
            prev_op = equation[i];
        }
        //Perform calculation based on operator
        else
        {
            if (i == equation.length() - 1)
            {
                number += equation[i];
            }
            param2 = stoi(number, nullptr, 10);
            //cout << "param 1: " << param1 << " param2: " << param2 << " prevop: " << prev_op << endl;
            if (prev_op == '+')
            {
                param1 += param2;
            }
            else if (prev_op == '-')
            {
                param1 -= param2;
            }
            else if (prev_op == '*')
            {
                param1 = param1 * param2;
            }
            else
            {
                //should not occur
                cout << "error" << endl;
            }
            prev_op = equation[i];
            number = "";
        }
    }
    //Check if equation value is equal to 42
    if (param1 == 42)
    {
        //Uncomment to additionally output the final equation
        cout << "final equation: " << equation << " (left to right, not BEDMAS)" << endl;
        return true;
    }
    return false;
}

bool solve(string line)
{
    int current_num = 0;
    int nums[5];
    char operators[3] = {'+', '-', '*'};

    //Find numbers from input
    string num = "";
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] != ' ')
        {
            num += line[i];
        }
        else
        {
            nums[current_num] = (stoi(num, nullptr, 10));
            current_num++;
            num = "";
        }
    }

    if (num != "")
    {
        nums[current_num] = (stoi(num, nullptr, 10));
        current_num++;
    }

    //Sort numbers
    sort(nums, nums + 5);

    string equation = "";

    //Construct all possible equations using 5 numbers and 4 operators, (many are going to be redudant)
    do
    {
        for (int op1 = 0; op1 < 3; op1++)
        {
            for (int op2 = 0; op2 < 3; op2++)
            {
                for (int op3 = 0; op3 < 3; op3++)
                {
                    for (int op4 = 0; op4 < 3; op4++)
                    {
                        //Constructed equation
                        equation = to_string(nums[0]) + operators[op1] + to_string(nums[1]) + operators[op2] + to_string(nums[2]) + operators[op3] + to_string(nums[3]) + operators[op4] + to_string(nums[4]);

                        //Call calculate function to find if it is 42
                        if (calculate(equation) == true)
                        {
                            return true;
                        }
                    }
                }
            }
        }
    } while (next_permutation(nums, nums + 5));

    return false;
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        if (solve(line))
        {
            cout << "Possible" << endl;
        }
        else
        {
            cout << "Impossible" << endl;
        }
    }
}
