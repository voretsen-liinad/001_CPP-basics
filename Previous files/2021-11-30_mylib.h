// 2021-11-30_mylib.h
// homework - Webinar of November, 30, 2021
// created by Daniil Nesterov (e-mail: maidanov1991@yandex.ru)


//Task 1 with a namespace (Task 5) - header "2021-11-30_mylib.h" ==============================================================================//
#pragma once

namespace MyLib {
	
	bool T1_InitFloatArr1D(float* arr, const size_t& size);

	void T1_PrintFloatArr1D(const float* arr, const size_t& size);

	struct NonZeroElements {
		size_t positives;
		size_t negatives;
	};

	NonZeroElements T1_CountNonZeroElementsInFloatArr1D(const float* arr, const size_t& size);
}
//End of Task 1 with a namespace (Task 5) - header "2021-11-30_mylib.h" =======================================================================//	