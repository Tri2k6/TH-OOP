// #include "Array.h"

// template<class T>
// void Dynamic_Array<T>::resize(size_t sz) {
//     if (size == sz) return;

//     T* newArr = new T[sz];

//     if (newArr == nullptr) {
//         std::cerr << "Loi: Khong du bo nho de cap phat (resize)!" << std::endl;
//         return; 
//     }

//     if (arr != nullptr) {
//         size_t n = (size < sz) ? size : sz;
//         for (size_t i = 0; i < n; ++i) {
//             newArr[i] = arr[i];
//         }
//     }

//     if (arr != nullptr) {
//         delete[] arr;
//         arr = nullptr; 
//     }

//     arr = newArr;
//     size = sz;
// }


// template<class T>
// Dynamic_Array<T>::Dynamic_Array() {
//     size = 0;
//     arr = nullptr; 
// }

// template<class T>
// Dynamic_Array<T>::Dynamic_Array(size_t sz, const T* Arr) {
//     size = sz;
//     arr = nullptr;

//     if (size > 0 && Arr != nullptr) {
//         arr = new (std::nothrow) T[size];
//         if (arr == nullptr) {
//             std::cerr << "Loi: Khong du bo nho de khoi tao!" << std::endl;
//             size = 0; 
//         } else {
//             for (size_t i = 0; i < size; ++i) {
//                 arr[i] = Arr[i];
//             }
//         }
//     }
// }

// template<class T>
// Dynamic_Array<T>::Dynamic_Array(const Dynamic_Array& other) {
//     size = other.size;
//     arr = nullptr;

//     if (size > 0) {
//         arr = new T[size];
//         if (arr == nullptr) {
//             std::cerr << "Loi: Khong du bo nho de sao chep!" << std::endl;
//             size = 0;
//         } else {
//             for (size_t i = 0; i < size; ++i) {
//                 arr[i] = other.arr[i];
//             }
//         }
//     }
// }

// template<class T>
// Dynamic_Array<T>& Dynamic_Array<T>::operator=(const Dynamic_Array& other) {
//     if (this != &other) {
//         if (arr != nullptr) {
//             delete[] arr;
//             arr = nullptr;
//         }
        
//         size = other.size;

//         if (size > 0) {
//             arr = new T[size];
//             if (arr == nullptr) {
//                 std::cerr << "Loi: Khong du bo nho de gan gia tri!" << std::endl;
//                 size = 0;
//             } else {
//                 for (size_t i = 0; i < size; ++i) {
//                     arr[i] = other.arr[i];
//                 }
//             }
//         }
//     }
//     return *this;
// }

// template<class T>
// Dynamic_Array<T>::~Dynamic_Array() {
//     if (arr != nullptr) {
//         delete[] arr;
//         arr = nullptr;
//     }
//     size = 0;
// }

// template<class T>
// void Dynamic_Array<T>::PushBack(const T& value) {
//     resize(size + 1);

//     if (arr != nullptr) {
//         arr[size - 1] = value;
//     }
// }

// template<class T>
// T& Dynamic_Array<T>::GetAt(size_t idx) {
//     if (arr == nullptr || idx >= size) {
//         throw std::out_of_range("Loi: Truy cap vuot qua kich thuoc mang hoac mang rong!");
//     }
//     return arr[idx];
// }

// template<class T>
// T Dynamic_Array<T>::MaxElement() const {
//     if (arr == nullptr || size == 0) {
//         throw std::logic_error("Loi: Mang rong, khong co Max Element!");
//     }
    
//     T maxVal = arr[0];
//     for (size_t i = 1; i < size; ++i) {
//         if (arr[i] > maxVal) {
//             maxVal = arr[i];
//         }
//     }
//     return maxVal;
// }

// template<class T>
// void Dynamic_Array<T>::Sort() {
//     if (arr != nullptr && size > 1) {
//         for (int i = 0;i < size;i++) {
//             for (int j = i + 1;j < size;j++) {
//                 if (arr[i] > arr[j]) {
//                     T tmp = arr[i];
//                     arr[i] = arr[j];
//                     arr[j] = tmp;
//                 }
//             }
//         }
//     }
// }

// template<class T>
// void Dynamic_Array<T>::print() {
//     cout << size << endl;
//     for (int i = 0;i < size;i++) {
//         cout << arr[i] << ' ';
//     }
//     cout << endl;
// }