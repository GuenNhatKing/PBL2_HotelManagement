#include <iostream>
#include <string>
#include <conio.h> // cho getch()
#include <cctype> // cho isdigit(), isalpha()
using namespace std;

string nhap(int kytu, int sl) {
    string temp = "";
    int a = 0;
    char ch;
    if(kytu == 1 || kytu == 2 || kytu == 3) {
        while (((ch = getch()) != '\r' && ch != '\n') || a <= 0) {
            if(((kytu == 1 && isdigit(ch)) ||
                (kytu == 2 && (isalpha(ch) || ch == ' ')) ||
                (kytu == 3 && (isalpha(ch) || isdigit(ch)))) && a < sl-1) {
                cout << ch;
                temp += ch;
                a++;
            }
            else if (ch == '\b' && a > 0) {
                cout << "\b \b";
                temp.pop_back();
                a--;
            }
        }
        cout << endl;
    }
    return temp;
}
int main(){
    string s;
    s = nhap(1, 2);
    if(s == "1") cout << "1";
    else cout << "0";
    return 0;
}