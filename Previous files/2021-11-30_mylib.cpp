// 2021-11-30_mylib.cpp 
// homework - Webinar of November, 30, 2021
// created by Daniil Nesterov (e-mail: maidanov1991@yandex.ru)


//Task 1 with a namespace (Task 5) - module "2021-11-30_mylib.cpp" ============================================================================//
#include <iostream>
#include <cstdlib>
#include <ctime>

namespace MyLib {

	bool T1_InitFloatArr1D(float* arr, const size_t& size)
	{
		if (size < 1)
			return false; 
		
		float fsize{ static_cast<float>(size) }; 
		for (size_t i{ 0 }; i < size; i++)
		{
			if (i > 0 && (i % 7 == 0))
				arr[i] = 0; 
			else
			{
				(i % 3 == 0) ? (arr[i] = fsize - i * i) : (arr[i] = fsize / i + 12.5);
			}
		}
		return true; 
	}

	void T1_PrintFloatArr1D(const float* arr, const size_t& size)
	{
		for (size_t i{ 0 }; i < size; i++)
		{
			std::cout << arr[i] << "  ";
		}
	}

	struct NonZeroElements {
		size_t positives; 
		size_t negatives;
	};

	NonZeroElements T1_CountNonZeroElementsInFloatArr1D(const float* arr, const size_t& size)
	{
		NonZeroElements result{ 0, 0 };
		if (size > 0)
		{
			for (size_t i{ 0 }; i < size; i++)
			{
				if (arr[i] != 0)
					(arr[i] > 0) ? result.positives++ : result.negatives++; 
			}
		}
		return result; 
	}
}
//End of Task 1 with a namespace (Task 5) - module "2021-11-30_mylib.cpp" =====================================================================//	