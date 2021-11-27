// 2021-11-23_Webinar_Homework.cpp 
// homework (task 4 - 5) - Webinar of November 23, 2021
// Created by Daniil Nesterov (e-mail: maidanov1991@yandex.ru)

#include <iostream>
#include <vector>

using namespace std;

void Print_iArray1D(const int* arr, const size_t& size)
//function to print one-dimensional int array
{
    cout << "    ";
    for (size_t i{ 0 }; i < size; i++)
    {
        cout << *(arr + i) << "  ";
    }
    cout << "\n\n";
}


//Task 4 - first part============================================================================================================================ =//
//Write a function which input arguments are one-dimension array and number n (n can be positie or negative), 
//and that method should cyclically shift the array's elements by n positions.   

bool ShiftCyclyByN_cArr1D(char* arr, const size_t& size, const int& n)
{
    if (n == 0)
        return true;

    size_t shift{ abs(n) % size };
    vector<char> Buffer(size - shift);

    if (n > 0)
    {
        for (size_t i{ shift }; i < size; i++)
        {
            Buffer[i - shift] = *(arr + i);
        }
        for (size_t i{ 0 }; i < size; i++)
        {
            if (i < shift)
            {
                if (i + shift < size)
                    *(arr + i + shift) = *(arr + i);
                else
                    *(arr + i + shift - size) = *(arr + i);
            }
            else
            {
                if (i + shift < size)
                    *(arr + i + shift) = Buffer[i - shift];
                else
                    *(arr + i + shift - size) = Buffer[i - shift];
            }
        }
        return true;
    }
    else
    {
        int iSize{ static_cast<int>(size) }, iShift{ static_cast<int>(shift) };
        for (int i{ iSize - 1 - iShift }; i >= 0; i--)
        {
            Buffer[i] = *(arr + i);
        }
        for (int i{ iSize - 1 }; i >= 0; i--)
        {
            if (i > (iSize - 1 - iShift))
            {
                if (i - iShift >= 0)
                    *(arr + i - iShift) = *(arr + i);
                else
                    *(arr + i - iShift + iSize) = *(arr + i);
            }
            else
            {
                if (i - iShift >= 0)
                    *(arr + i - iShift) = Buffer[i];
                else
                    *(arr + i - iShift + iSize) = Buffer[i];
            }
        }
        return true;
    }
    return false;
}

void Print_cArray1D(const char* arr, const size_t& size)
//function to print one-dimensional char array
{
    cout << "    ";
    for (size_t i{ 0 }; i < size; i++)
    {
        cout << *(arr + i) << "  ";
    }
    cout << "\n\n";
}
//End of the first part of Task 4.================================================================================================================//




//Task 5 - first part============================================================================================================================ =//
//Write a function which is passed a non-empty one-dimensional int array. 
//That function should return true if there is a balance point at that array where the array's left side sum and the array's right side sum are equal. 

bool CheckBalance_iArray1D(const int* arr, const size_t& size)
{
    if (size == 1)
        return false;

    int LeftSum{ *(arr) };
    int RightSum{ 0 };
    for (size_t i{ 1 }; i < size; i++)
    {
        RightSum += *(arr + i);
    }

    if (LeftSum == RightSum)
        return true;
    if (LeftSum > RightSum)
        return false;

    for (size_t i{ 1 }; i < size; i++)
    {
        LeftSum += *(arr + i);
        RightSum -= *(arr + i);
        if (LeftSum == RightSum)
            return true;
        if (LeftSum > RightSum)
            return false;
    }
}
//End of the first part of Task 5.================================================================================================================//



int main()
{

    //Task 4 - second part============================================================================================================================//

    cout << "Task.4=========================================================================\n\n";

    int N{ 12 }, M{ -5 };
    const size_t SIZE_cArr1D{ 9 };
    char cArr1D[SIZE_cArr1D] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'j' };

    cout << "  The array \"cArr1D[" << SIZE_cArr1D << "]\" before shifting:       ";
    Print_cArray1D(cArr1D, SIZE_cArr1D);

    if (ShiftCyclyByN_cArr1D(cArr1D, SIZE_cArr1D, N))
    {
        cout << "    The function \"ShiftCyclyByN_cArr1D()\" completed.\n\n"
             << "  The array \"cArr1D[" << SIZE_cArr1D << "]\" after shifting by " << N << ":  ";
        Print_cArray1D(cArr1D, SIZE_cArr1D);
    }
    else
    {
        cerr << "Error: ShiftCyclyByN_cArr1D() does not return \"true\"\n";
    }

    if (ShiftCyclyByN_cArr1D(cArr1D, SIZE_cArr1D, M))
    {
        cout << "    The function \"ShiftCyclyByN_cArr1D()\" completed.\n\n"
             << "  The array \"cArr1D[" << SIZE_cArr1D << "]\" after shifting by " << M << ":  ";
        Print_cArray1D(cArr1D, SIZE_cArr1D);
    }
    else
    {
        cerr << "Error: ShiftCyclyByN_cArr1D() does not return \"true\"\n";
    }
    cout << "\n";
    //End of Task 4.==================================================================================================================================//




    //Task 5 - second part============================================================================================================================//

    cout << "Task.5=========================================================================\n\n";

    const size_t SIZE_iArr1D_1{ 1 };
    int iArr1D_1[SIZE_iArr1D_1] = { 2 };

    const size_t SIZE_iArr1D_2{ 7 };
    int iArr1D_2[SIZE_iArr1D_2] = { -14, 2, 10, 5, 100, 200, -97 }; 

    const size_t SIZE_iArr1D_3{ 4 };
    int iArr1D_3[SIZE_iArr1D_3] = { 2, 2, 4, 5 };

    cout << "  The array \"iArr1D_1[" << SIZE_iArr1D_1 << "]\": ";
    Print_iArray1D(iArr1D_1, SIZE_iArr1D_1);

    if (CheckBalance_iArray1D(iArr1D_1, SIZE_iArr1D_1))
    {
        cout << "    The function \"CheckBalance_iArray1D()\" completed.\n\n"
             << "      The array \"iArr1D_1[" << SIZE_iArr1D_1 << "]\" has a balance point.\n\n\n";
    }
    else
    {
        cout << "    The function \"CheckBalance_iArray1D()\" completed.\n\n"
             << "      The array \"iArr1D_1[" << SIZE_iArr1D_1 << "]\" has no balance point.\n\n\n";
    }

    cout << "  The array \"iArr1D_2[" << SIZE_iArr1D_2 << "]\": ";
    Print_iArray1D(iArr1D_2, SIZE_iArr1D_2);

    if (CheckBalance_iArray1D(iArr1D_2, SIZE_iArr1D_2))
    {
        cout << "    The function \"CheckBalance_iArray1D()\" completed.\n\n"
             << "      The array \"iArr1D_2[" << SIZE_iArr1D_2 << "]\" has a balance point.\n\n\n";
    }
    else
    {
        cout << "    The function \"CheckBalance_iArray1D()\" completed.\n\n"
            << "       The array \"iArr1D_2[" << SIZE_iArr1D_2 << "]\" has no balance point.\n\n\n";
    }

    cout << "  The array \"iArr1D_3[" << SIZE_iArr1D_3 << "]\": ";
    Print_iArray1D(iArr1D_3, SIZE_iArr1D_3);

    if (CheckBalance_iArray1D(iArr1D_3, SIZE_iArr1D_3))
    {
        cout << "    The function \"CheckBalance_iArray1D()\" completed.\n\n"
            << "      The array \"iArr1D_3[" << SIZE_iArr1D_3 << "]\" has a balance point.\n\n\n";
    }
    else
    {
        cout << "    The function \"CheckBalance_iArray1D()\" completed.\n\n"
            << "       The array \"iArr1D_3[" << SIZE_iArr1D_3 << "]\" has no balance point.\n\n\n";
    }
    //End of Task 5.==================================================================================================================================//
    
    return 0;
}