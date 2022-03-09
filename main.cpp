#include <iostream>

using namespace std;


//-------------------------------------------------------------------------------
int resetBit(const int input, int bit)
{
    // 00000100        (1 << bit)
    // 11111011  mask ~(1 << bit)
    // 00001111  input
    //----------------
    // 00001011  result

    int mask = ~(1 << bit);
    return (mask & input);
}


//-------------------------------------------------------------------------------
int flipBit(const int input, int bit)
{
    return (input ^ (1 << bit));
}


//-------------------------------------------------------------------------------
bool isBitSet(const int input, int bit)
{
    return ((input & (1 << bit)) != 0);
}


//-------------------------------------------------------------------------------
string findBinary(const int input)
{
    string result;

    for (int i = (sizeof(input) * 8) - 1; i >= 0; i--)
    {
        char bit = ((input & (1 << i)) != 0) ? '1' : '0';
        result.push_back(bit);
    }

    return result;
}


//-------------------------------------------------------------------------------
// M A I N
//-------------------------------------------------------------------------------
int main()
{
    int num = 4;

    cout << "Binary of " << num << ": " << findBinary(num) << endl;
    cout << "Binary of " << (num >> 2) << ": " << findBinary(num >> 2) << endl;

    int num2 = 255;
    int bitToReset = 4;
    cout << "Binary of " << num2 << ": " << findBinary(num2) << endl;
    cout << "Reset bit " << bitToReset << " of " << num2 << ": " << findBinary(resetBit(num2, bitToReset)) << endl;

    int bitToFlip = 4;
    cout << "Binary of " << num2 << ": " << findBinary(num2) << endl;
    cout << "Flip bit " << bitToFlip << " of " << num2 << ": " << findBinary(flipBit(num2, bitToFlip)) << endl;

    int bitToCheck = 10;
    cout << "Is bit " << bitToCheck << " of " << findBinary(num2) << " set? " << (isBitSet(num2, bitToCheck) ? "Yes" : "No") << endl;

    return 0;
}

