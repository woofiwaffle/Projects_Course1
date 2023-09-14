#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    while(true){
        char number;
        cout << "\nEnter a number from 1 to 4(the number is a task in practice), 5 - idz\n";
        cin.sync();
        cin >> number;

        switch (number) {

            case '1': {
                cout << "Display how much memory is allocated for different types of data: \n";
                int a;
                short int b;
                long int c;
                float d;
                double e;
                long double f;
                char g;
                bool h;
                cout << "int: " << sizeof(a) << "\n" << "short int: " << sizeof(b) << "\n" << "long int: "
                     << sizeof(c) << "\n" << "float: " << sizeof(d) << "\n" << "double: " << sizeof(e) <<
                     "\n" << "long double: " << sizeof(f) << "\n" << "char: " << sizeof(g) << "\n" << "bool: "
                     << sizeof(h)
                     << "\n";
                break;
            }


            case '2': {
                cout << "\nDisplay the binary representation in memory of an integer: \n";
                cout << "Enter integer number:\n";
                int n;
                cin >> n;
                int m = sizeof(n) * 8 - 1;
                int mask = 1 << m;
                for (int i = 0; i <= m; i++) {
                    if (i == 1 || i % 8 == 0) {
                        putchar(' ');

                    }
                    putchar(n & mask ? '1' : '0');
                    mask = (unsigned) mask >> 1;

                }
                cout << " " << "\n";
                break;
            }

            case '3': {
                cout << "\nDisplay the binary representation in memory of a float: \n";
                cout << "Enter float number: \n";
                union {
                    float fl;
                    int nt;
                };
                cin >> fl;
                unsigned int line = 32;
                int m = sizeof(fl) * 8 - 1;
                int mask = 1 << m;
                mask = 1 << line - 1;
                for (int p = 1; p <= line; p++) {
                    putchar(nt & mask ? '1' : '0');
                    nt <<= 1;
                    if (p == 9) {
                        putchar(' ');
                    }
                    if (p == 1) {
                        putchar(' ');

                    }
                }
                cout << " " << "\n";
                break;
            }
            case '4': {
                cout << "\nDisplay the binary representation in memory of a double: \n";
                cout << "Enter double number: \n";
                int qa = 0;
                union {
                    double dbl;
                    int mas[2];
                };
                cin >> dbl;
                unsigned int lines = 32;
                int m = sizeof(dbl) * 8 - 1;
                int mask = 1 << m;
                mask = 1;
                mask <<= (lines - 1);
                for (int v = 0; v < 2; v++) {
                    if (v == 0) {
                        qa = qa + 1;
                    }
                    else {
                        qa = qa - 1;
                    }
                    for (int po = 0; po < lines; po++) {
                        putchar(mas[qa] & mask ? '1' : '0');
                        mas[qa] <<= 1;
                        if ((po == 0) and (v == 0)) {
                            putchar(' ');
                        }
                        if ((po == 11) and (v == 0)) {
                            putchar(' ');
                        }
                    }
                }
                break;
            }

            case '5': {
                cout << "\n\nBit mirroring: \n";
                cout << "Enter number: ";
                unsigned int ab, value;
                unsigned int cd;
                cin >> cd;
                cout << endl;
                cout << setbase(8) << cd << endl;

                ab = 1 << ((sizeof(cd) << 3) - 1);
                for (int i = 0; i < (sizeof(cd) << 3); i++) {
                    if (cd & ab)
                        cout << "1";

                    else
                        cout << "0";
                    ab = ab >> 1;
                }
                cout << endl;

                ab = 1;
                value = 0;
                for (int k = 0; k < (sizeof(cd) << 3); k++) {
                    value = value << 1;
                    if (cd & ab)
                        value = value | 1;
                    ab = ab << 1;
                }
                cout << endl;

                cout << setbase(8) << value << endl;

                ab = 1 << ((sizeof(cd) << 3) - 1);
                for (int i = 0; i < (sizeof(cd) << 3); i++) {
                    if (value & ab) {
                        cout << "1";
                    } else {
                        cout << "0";
                    }
                    ab = ab >> 1;
                }

                cout << endl;
                break;
            }
            default: {
                cout << "Error\n";
            }
        }
    }
}