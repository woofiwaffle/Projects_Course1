#include <iostream>
#include "practics1234/types.h"
#include "practics1234/arrays.h"
#include "practics1234/2d_arrays.h"
#include "practics1234/strings.h"

using namespace std;



void clr(){
    system("cls");
}



int main(){
    while(true){

        clr();
        cout << "\n\nChoose of practical:\n";
        cout << "1 - data types\n";
        cout << "2 - arrays\n";
        cout << "3 - 2d arrays\n";
        cout << "4 - strings\n";

        char number;
        cin.sync();
        cin >> number;

        if(number == '0'){
            break;
        }

        switch (number) {

            case '1':{
                clr();
                types();
                break;
            }

            case '2':{
                clr();
                arrays();
                break;
            }

            case '3':{
                clr();
                arraysTwoD();
                break;
            }

            case '4':{
                clr();
                strings();
                break;
            }

            default:{
                cout << "\nError\n";
            }

        }
    }
    return 0;
}