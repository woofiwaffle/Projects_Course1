#include <iostream>
#include <string>
#include <limits>
#include <fstream> /*provides functionality for reading data from a file and for writing to a file
                    (предоставляет функционал для считывания данных из файла и для записи в файл)*/

#include "strings.h"

using namespace std;



string text(){
    cout << "\nEnter number:";
    int n;
    cin >> n;
    cin.ignore((numeric_limits<streamsize>::max)(), '\n');

    string s;


    if(n == 1){
        getline(cin, s);
    }
    else if(n == 2){
        ifstream File;
        File.open("C:\\Users\\User\\CLionProjects\\practics\\gaaga.txt");
        if (File.is_open()) {
            while (!File.eof()) {
                string s1;
                getline(File, s1);
                s = s + s1;
            }
        }
    }
    else{
        cout << "Error";
    }
    return s;
}



void newFile(string s){
    fstream File("C:\\Users\\User\\CLionProjects\\practics\\gaaga.txt", ios::out | ios::trunc);
    if(File.is_open()){
        File << s;
    }
    else{
        cout << "file could not be opened";
    }
}



string charact(string s){

    int i = 0;
    if(s[i] == ' '){
        while(s[i] != '\0') {
            i++;
        }
    }
    int word = 0;
    int count = 0;
    while(s[i] != '\0'){
        if(s[i] != ' ' && word == 0){
            word = 1;
            count++;
        }
        else if(s[i] == ' '){
            word = 0;
        }
        i++;
    }
    cout << "\n<<Displays the number of characters in each word of the source sequence(Ex.4.2)>>\n";
    cout << "\nNumber of words per line: " << count;
    cout << endl;

    while(s[i] != '\0'){
        i++;
    }
    cout <<"Numbers of characters per line: " << i;
}



string convertion(string s) {
    string str = "";
    cout << "String before conversion: " << "\n" << s << "\n";

    bool a = true;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == ' '){
            if(a){
                continue;
            }
            else{
                a = true;
                str = str + s[i];
            }
        }
        else if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z' || s[i] >= '0' && s[i] <= '9'){
            if(s[i] >= 'A' && s[i] <= 'Z' && !a){
                str += s[i] + 32;
            }
            else{
                str = str + s[i];
            }
            a = false;
        }
        else{
            a = false;
            if(s[i] == '.' && s[i + 1] == '.' && s[i + 2] == '.'){
                i = i + 2;
                str = str + "...";
                continue;
            }
            else if(s[i] == '.'){
                str = str + '.';
                break;
            }
            if(s[i] != s[i - 1]){
                str = str + s[i];
            }
        }
    }
    cout << "\n" << "String after conversion: " << "\n" << str;
    return str;
}



string amount(){

    int words;
    cout << "Enter amount words: ";
    cin >> words;

    string *Text = new string[words];

    cout << "Enter text: ";
    for(int i = 0; i < words; i++){
        cin >> Text[i];
    }

    for(int i = words - 1; i >= 0; i--){
        cout << Text[i] << " ";
    }
}



void linearS(string s){
    string sub;
    int c = 0;

    cout << "Enter substring:";
    getline(cin, sub);

    cout << "Indexes:\n";

    string s1 = "";
    for(int i = 0; i <= s.length() - sub.length(); i++){
        s1 = "";
        for(int j = i; j < sub.length() + i; j++){
            if(s[j] == sub[j - i]){
                s1 = s1 + s[j];
            }
            else{
                continue;
            }
        }
        if (sub == s1) {
            cout << i + 1 << " ";
            c = c + 1;
        }
    }
    cout << "\nfound: " << c << " substring\n";
}



int max(int a, int b){
    if(a > b){
        return a;
    }
    else{
        return b;
    }
}



void charH(string s, int size, int chard[256]){

    for(int i = 0; i < 256; i++){
        chard[i] = -1;
    }
    for(int i = 0; i < size; i++){
        chard[(int)s[i]] = i;
    }
}



void boyer(string s){
    string sub;
    cout << "Enter substring:";
    getline(cin, sub);
    cout << "Indexes:\n";
    int g = sub.size();
    int k = s.size();
    int c = 0;
    int chard[256];

    charH(sub, g, chard);

    int s1 = 0;
    while(s1 <= (k - g)){
        int j = g - 1;

        while(j >= 0 && sub[j] == s[s1 + j]){
            j--;
        }
        if(j < 0){
            cout << s1 << " ";
            c = c + 1;
            if (s1 + g < k){
                s1 += g - chard[s[s1 + g]];
            }
            else{
                s1 = s1 + 1;
            }
        }
        else{
            s1 += max(1, j - chard[s[s1 + j]]);
        }
    }
    cout << "\nfound: " << c << " substring\t";
}



int strings() {
    string s;
    string sub;

    cout << "\n\nInput method(Ex.1):\n";
    cout << "1 - from keyboard\n";
    cout << "2 - from file\n";
    s = text();
    cout << "\n";

    cout << "\n<<You need to edit the input text(Ex.2)>>\n\n";
    s = convertion(s);
    cout << "\n";

    cout << "\n";
    charact(s);
    cout << "\n";

    cout << "\n<<Boyer-Moore algorithm>>\n";
    boyer(s);
    cout << "\n";

    cout << "\n<<Linear search algorithm>>\n";
    linearS(s);
    cout << "\n";

    cout << "\n<<Displays the words of the sequence in reverse order(Ex.3.1)>>\n";
    amount();
    cout << "\n";


    newFile(s);
    return 0;
}