// 2021-11-23_Webinar_Homework.cpp 
// homework (task 1 - 5) - Webinar of November 23, 2021
// Created by Daniil Nesterov (e-mail: maidanov1991@yandex.ru)

#include <iostream>
#include <vector>

using namespace std; 

//Task 1 - first part=============================================================================================================================//
//Write a function that outputs on the screen an array of the type double numbers. 
//The function's parameters are the array itself and its size. 
//Call the function from the function "main".

void Print_dArray1D(const double* arr, const size_t& size) 
//function to print one-dimensional double array
{
    cout << "    "; 
    for (size_t i{ 0 }; i < size; i++)
    {
        cout << *(arr + i) << "  ";
    }
    cout << "\n\n"; 
}

void Print_dArray2D(const double* arr, const size_t& size1, const size_t& size2)
//function to print two-dimensional double array
{
    for (size_t i{ 0 }; i < size1; i++)
    {
        cout << "    "; 
        for (size_t j{ 0 }; j < size2; j++)
        {
            cout << *(arr + i * size2 + j) << "  "; 
        }
        cout << "\n"; 
    }
    cout << "\n";
}

void Print_dArray3D(const double* arr, const size_t& size1, const size_t& size2, const size_t& size3)
//function to print three-dimensional double array 
{
    for (size_t i{ 0 }; i < size1; i++)
    {
        for (size_t j{ 0 }; j < size2; j++)
        {
            cout << "    ";
            for (size_t k{ 0 }; k < size3; k++)
            {
                cout << *(arr + i * size2 * size3 + j * size3 + k) << "  "; 
            }
            cout << "\n";     
        }
        cout << "\n";
    }
    cout << "\n";
}

//End of the first part of Task 1.================================================================================================================//




//Task 2 - first part=============================================================================================================================//
//Set an integer array of elements 1 and 0. For examle [1, 1, 0, 0, 1, 0, 1, 1, 0, 0]. 
//Write a function changing 0 to 1, 1 to 0 in that array. 
//Output the array on the screen before the changes and after them. 

void Print_usiArray1D(const unsigned short int* arr, const size_t& size) 
//function to print one-dimensional unsigned short int array
{
    cout << "  ";
    for (size_t i{ 0 }; i < size; i++)
    {
        cout << *(arr + i) << "  ";
    }
    cout << "\n\n";
}

bool Change_1and0_usiArray1D(unsigned short int* arr, const size_t& size)
//function to change 1 to 0 and 0 to 1 in one-dimensional unsigned short int array
{
    for (size_t i{ 0 }; i < size; i++)
    {
        if (*(arr + i) == 1)
        {
            *(arr + i) = 0;
        }
        else
        {
            if (*(arr + i) == 0)
            {
                *(arr + i) = 1;
            }
        }
    }
    return true; 
}
//End of the first part of Task 2.================================================================================================================//




//Task 3 - first part=============================================================================================================================//
//Set an empty int array of size 8. 
//Write a function which fills in that array by the values 1 4 7 10 13 16 19 22. Display the array. 

bool FillIn_1plus3_iArray1D(int* arr, const size_t& size)
//function to fill in one-dimensional int array by the values 1 4 7 10 13 16 19 22...
{
    *arr = 1;  
    for (size_t i{ 1 }; i < size; i++)
    {
        *(arr + i) = *(arr + i - 1) + 3; 
    }
    return true; 
}

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
//End of the first part of Task 3.================================================================================================================//



/*Task 4 - first part============================================================================================================================ =//
//Write a function which input arguments are one-dimension array and number n (n can be positie or negative), 
//and that method should cyclically shift the array's elements by n positions.   

bool ShiftCyclyByN_cArr1D(char* arr, const int& n) 
{
    if (n == 0) return true; 

    int sign{ 0 }; 
    if (n < 0) sign = -1; 
    else sign = 1; 

    int shift{ (n * sign) % (sizeof(arr) / sizeof(char)) };
    
    if (shift == 0) return true;
    else
    {        
        int ArrSize{ sizeof(arr) / sizeof(char) }; 
        vector<char> buf(ArrSize);
        char buffer{' '}; 
        int i2{ 0 };

        if (sign == 1)
        {
            for (int i{ 0 }; i < ArrSize; i++)
            {
                if ((i + shift) > (ArrSize - 1)) i2 = i + shift - ArrSize;
                else i2 = i + shift; 
                buf[i2] = *(arr + i); 
                ...
            }
            return true;
        }
        else
        {
            for (int i{ ArrSize - 1 }; i >= 0; i--)
            {
                if ((i - shift) < 0) i2 = i - shift + ArrSize;
                else i2 = i - shift;
                ...
            }
            return true; 
        }
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
*/



/*Task 5 - first part============================================================================================================================ =//


//End of the first part of Task 5.================================================================================================================//
*/



int main()
{
//Task 1 - second part============================================================================================================================//

    cout << "Task.1=========================================================================\n\n"; 
    
    double dArr1D[] = { 8, 14.5, 11, -73.0976, 854.09, 3, -4'315.57, 50, 1'001.1001, 56.99 };
    cout << "The function \"Print_dArray1D()\" displays\n"
         << "  the values of one-dimensional array \"dArr1D[" << sizeof(dArr1D) / sizeof(double) << "]\":\n";
    Print_dArray1D(dArr1D, sizeof(dArr1D) / sizeof(double));    
    
   
    const size_t SIZE_2D_1{ 3 }, SIZE_2D_2{ 4 }; 
    double dArr2D[SIZE_2D_1][SIZE_2D_2] = { {1.2, 2.3, -4.5},
                                           {9.76, -182.3049, 77.07, 12},
                                           { 42, 8} };
    cout << "The function \"Print_dArray2D()\" displays\n"
         << "  the values of two-dimensional array \"dArr2D[" << SIZE_2D_1 << "][" << SIZE_2D_2 << "]\":\n";
    Print_dArray2D(*dArr2D, SIZE_2D_1, SIZE_2D_2);

    
    const size_t SIZE_3D_1{ 3 }, SIZE_3D_2{ 3 }, SIZE_3D_3{ 2 }; 
    double dArr3D[SIZE_3D_1][SIZE_3D_2][SIZE_3D_3] = { { {9.73, 11.6}, {-80, 40.5056}, {0, 17.9} },
                                                      { {3.08, -101}, {12, 777.77} },
                                                      { {18.03, 11.6},{-80}, {300, -400} } }; 
    cout << "The function \"Print_dArray3D()\" displays\n"
         << "  the values of three-dimensional array \"dArr3D[" << SIZE_3D_1 << "][" << SIZE_3D_2 << "][" << SIZE_3D_3 << "]\":\n";
    Print_dArray3D(**dArr3D, SIZE_3D_1, SIZE_3D_2, SIZE_3D_3);
//End of Task 1.==================================================================================================================================//



//Task 2 - second part============================================================================================================================//
    
    cout << "Task.2=========================================================================\n\n"; 
         
    const size_t SIZE_usiArr1D{ 11 };
    unsigned short int usiArr1D[SIZE_usiArr1D] = { 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1 };
    
    cout << "  The array \"usiArr1D["<< SIZE_usiArr1D << "]\" before changes:";
    Print_usiArray1D(usiArr1D, SIZE_usiArr1D);

    if (Change_1and0_usiArray1D(usiArr1D, SIZE_usiArr1D))
    {
        cout << "    The function \"Change_1and0_usiArray1D()\" completed.\n\n"
             << "  The array \"usiArr1D[" << SIZE_usiArr1D << "]\" after changes: ";
        Print_usiArray1D(usiArr1D, SIZE_usiArr1D);
    }
    else
    {
        cerr << "Error: ChangePseudoBits_usiArray1D() does not return \"true\"\n"; 
    }
    cout << "\n"; 
//End of Task 2.==================================================================================================================================//



//Task 3 - second part============================================================================================================================//
    
    cout << "Task.3=========================================================================\n\n";

    int iArr1D[8];
    cout << "  The array \"iArr1D[" << sizeof(iArr1D) / sizeof(int) << "]\" before filling in:\n";
    Print_iArray1D(iArr1D, sizeof(iArr1D) / sizeof(int)); 
    

    if (FillIn_1plus3_iArray1D(iArr1D, sizeof(iArr1D) / sizeof(int)))
    {
        cout << "    The function \"FillIn_1plus3_iArray1D()\" completed.\n\n"
             << "  The array \"iArr1D[" << sizeof(iArr1D) / sizeof(int) << "]\" after filling in:\n";
        Print_iArray1D(iArr1D, sizeof(iArr1D) / sizeof(int)); 
    }
    else
    {
        cerr << "Error: FillIn_1plus3_iArray1D() does not return \"true\"\n"; 
    }
    cout << "\n";
//End of Task 3.==================================================================================================================================//



/*Task 4 - second part============================================================================================================================//

    cout << "Task.4=========================================================================\n\n"; 

    int N{ 2 };
    char cArr1D[] = { "abcdefg"}; 
    cout << "  The array \"cArr1D[" << sizeof(cArr1D) / sizeof(char) << "]\" before shifting by " << N << ": ";
    Print_cArray1D(cArr1D, sizeof(cArr1D) / sizeof(char)); 

    if (ShiftCyclyByN_cArr1D(cArr1D, N))
    {
        cout << "    The function \"ShiftCyclyByN_cArr1D()\" completed.\n\n"
             << "  The array \"cArr1D[" << sizeof(cArr1D) / sizeof(char) << "]\" after shifting by " << N << ":  ";
        Print_cArray1D(cArr1D, sizeof(cArr1D) / sizeof(char));
    }
    else
    {
        cerr << "Error: ShiftCyclyByN_cArr1D() does not return \"true\"\n";
    }
    cout << "\n";
//End of Task 4.==================================================================================================================================//
*/




/*Task 5 - second part============================================================================================================================//


//End of Task 5.==================================================================================================================================//
*/
    return 0; 
}