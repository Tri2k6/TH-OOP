#include "Array.h"
#include "Fraction.h"

string Fraction::SEPERATOR = "/";

int main() {
    try
    {
        cout << "-------------------------Fraction-------------------------------\n";
        Fraction Frac1, Frac2;

        cout << "Nhap phan so thu 1: \n"; cin >> Frac1;
        cout << "Nhap phan so thu 2: \n"; cin >> Frac2;

        cout << "Frac1: " << Frac1 << ", Frac2: " << Frac2 << endl;
        cout << "Tong: " << Frac1 + Frac2 << endl;
        cout << "Hieu: " << Frac1 - Frac2 << endl;
        cout << "Tich: " << Frac1 * Frac2 << endl;
        cout << "Thuong: " << Frac1 / Frac2 << endl;

        cout << "Before Frac1++: " << Frac1++ << endl;
        cout << "After Fract1++: " << Frac1 << endl;

        cout << "Before ++Frac2: " << Frac2 << endl;
        cout << "After ++Frac2: " << ++Frac2 << endl;

        cout << "-----------------------Array<int>----------------------------------------\n";

        Dynamic_Array<int> ArrInt;
        int n,val;

        cout << "Nhap so luong phan tu cua mang so nguyen: "; cin >> n;
        for (int i = 0;i < n;i++) {
            cout << "Nhap phan tu thu " << i + 1 << ": ";
            cin >> val;
            ArrInt.PushBack(val);
        }

        ArrInt.print();

        cout << "Max Element: " << ArrInt.MaxElement() << endl;
 

        int idx;
        cout << "Nhap vi tri cua phan tu can lay (0 -> n - 1): "; cin >> idx;
        cout << "Gia tri tai vi tri " << idx << ": " << ArrInt.GetAt(idx) << endl;

        ArrInt.Sort();
        cout << "Sorted Array<int>: \n";
        ArrInt.print();


        cout << "----------------------------Array<Fraction>------------------------------\n";
        Dynamic_Array<Fraction> ArrFrac;
        Fraction Frac_tmp;
        cout << "Nhap so phan tu cua mang phan so: "; cin >> n;
        for (int i = 0;i < n;i++) {
            cout << "Nhap phan tu thu " << i + 1 << ": \n";
            cin >> Frac_tmp;
            ArrFrac.PushBack(Frac_tmp);
        }

        ArrFrac.print();

        cout << "Max Element: " << ArrFrac.MaxElement() << endl;


        cout << "Nhap vi tri cua phan tu can lay (0 -> n - 1): "; cin >> idx;
        cout << "Gia tri tai vi tri " << idx << ": " << ArrFrac.GetAt(idx) << endl;

        ArrFrac.Sort();
        cout << "Sorted Array<Fraction>: \n";
        ArrFrac.print();


    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}