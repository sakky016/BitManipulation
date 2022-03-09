#include <assert.h>
#include <algorithm>
#include <cmath>
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
int findIntFromBinary(const string& binary)
{
    int result = 0;
    int power = binary.size() - 1;
    for (const auto& ch : binary)
    {
        assert(ch == '1' || ch == '0');
        int multiplier = (ch == '1') ? 1 : 0;
        result += pow(2, power) * multiplier;
        power--;
    }

    return result;
}


//-------------------------------------------------------------------------------
int reverseBits(const int input)
{
    string binary = findBinary(input);
    string tmp(binary);
    reverse(tmp.begin(), tmp.end());
    return findIntFromBinary(tmp);
}


//-------------------------------------------------------------------------------
// M A I N
//-------------------------------------------------------------------------------
int main()
{
    int num = 1023;
    string bin = findBinary(num);
    cout << "Reverse bits of " << num << ": " << reverseBits(num) << endl;
    cout << "Binary of " << num << ": " << findBinary(num) << endl;
    cout << "Integer of " << bin << ": " << findIntFromBinary(bin) << endl;

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

