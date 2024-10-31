#ifndef UTILS_H
#define UTILS_H
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <time.h>
#include <ctime>
#include <cctype>
#include <conio.h>
#include <iomanip>
#include <set>

#define MAX_NAME 50
using namespace std;


enum role_value {
    UNDEFINED_ROLE = -1,
    KHACHHANG,
    NHANVIEN,
    QUANLI,
};    
enum gender_value {
    UNDEFINED_GENDER = -1,
    NAM,
    NU,
};

/**
 * Chứa các hàm tiện ích
 */
class Utils {
public:
    static string intToString(int n) {
        stringstream ss;
        ss << n;
        return ss.str();
    }

    static int stringToInt(string s) {
        stringstream ss(s);
        int n;
        ss >> n;
        return n;
    }

    static string timeToString(time_t t) {
        struct tm *timeinfo = localtime(&t);
        string buffer = "";
        try {
            if(timeinfo == NULL) {
                throw runtime_error("Loi: khong the lay timeinfo.");
            }
            buffer += intToString(timeinfo->tm_hour) + ':'
                + intToString(timeinfo->tm_min) + ':'
                + intToString(timeinfo->tm_sec) + ' '
                + intToString(timeinfo->tm_mday) + '/'
                + intToString(timeinfo->tm_mon + 1) + '/'
                + intToString(timeinfo->tm_year + 1900);
        }
        catch (const runtime_error &e){
            cout << e.what() << endl;
        }
        catch (const exception &e) {
            cout << e.what() << endl;
        }
        
        return buffer;
    }

    /**
     * Định dạng của chuỗi s: "HH-MM-SS DD/MM/YYYY"
     */
    static time_t stringToTime(string s) {
        struct tm timeinfo;
        try {
            if(s.size() != 19) {
                throw runtime_error("Loi: do dai thoi gian khong hop le.");
            }
            timeinfo.tm_hour = stringToInt(s.substr(0, 2));
            timeinfo.tm_min = stringToInt(s.substr(3, 2));
            timeinfo.tm_sec = stringToInt(s.substr(6, 2));
            timeinfo.tm_mday = stringToInt(s.substr(9, 2));     
            timeinfo.tm_mon = stringToInt(s.substr(12, 2)) - 1;    
            timeinfo.tm_year = stringToInt(s.substr(15, 4)) - 1900;            
        }
        catch (const runtime_error& e) {
            cout << e.what() << endl;
        }
        catch (const exception &e) {
            cout << e.what() << endl;
        }
        return mktime(&timeinfo);
    }

    static string dateToString(time_t t) {
        struct tm *timeinfo = localtime(&t);
        string buffer = "";
        try {
            if(timeinfo == NULL) {
                throw runtime_error("Loi: khong the lay timeinfo.");
            }
            buffer += intToString(timeinfo->tm_mday) + '/'
                + intToString(timeinfo->tm_mon + 1)+ '/'
                + intToString(timeinfo->tm_year + 1900);
        }
        catch (const runtime_error &e){
            cout << e.what() << endl;
        }
        catch (const exception &e) {
            cout << e.what() << endl;
        }
        
        return buffer;
    }

    /**
     * Định dạng của chuỗi s: "DD/MM/YYYY"
     */
    static time_t stringToDate(string s) {
        struct tm timeinfo;
        try {
            if(s.size() != 10) {
                throw runtime_error("Loi: do dai thoi gian khong hop le.");
            }
            timeinfo.tm_mday = stringToInt(s.substr(0, 2));
            timeinfo.tm_mon = stringToInt(s.substr(3, 2)) - 1;
            timeinfo.tm_year = stringToInt(s.substr(6, 4)) - 1900;
            timeinfo.tm_hour = 0;
            timeinfo.tm_min = 0;
            timeinfo.tm_sec = 0;
        }
        catch (const runtime_error& e) {
            cout << e.what() << endl;
        }
        catch (const exception &e) {
            cout << e.what() << endl;
        }
        return mktime(&timeinfo);
    }

    /**
     * khi dùng sl phải tăng thêm 1 vì còn ký tự '\0'     
     * kytu:
     * 1: Chỉ được nhập số.
     * 2: Chỉ được nhập chữ và khoảng trắng. 
     * 3: Được nhập số, chữ và khoảng trắng.
     */
    static string nhap(int kytu, int sl) { 
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

    /**
     * Hàm này dùng để lấy chuỗi con từ chuỗi s từ vị trí pos
     * cho đến khi gặp kí tự x
     */
    static string getSubstringUntilX(const string &s, int &pos, char x) {
        string substring = "";
        for(int i = pos; i < s.size(); ++i) {
            if(s[i] == x) {
                pos = i + 1;
                break;
            }
            substring += s[i];
        }
        return substring;
    }

    static string trim(const string &s) {
        int begin_s, end_s;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] != ' ' && s[i] != '\n' && s[i] != '\t') {
                begin_s = i;
                break;
            }
        }

        for(int i = s.size() - 1; i >= 0; --i) {
            if(s[i] != ' ' && s[i] != '\n' && s[i] != '\t') {
                end_s = i;
                break;
            }
        }

        if(end_s > begin_s) {
            return s.substr(begin_s, end_s - begin_s + 1);
        }
        else return "";
    }

    const string chuanHoaTen(const string& ten) {
        string tenChuanHoa;
        bool vietHoa = true;

        for (char c : ten) {
            if (c == ' ') { // Kiểm tra khoảng trắng
                vietHoa = true;
                tenChuanHoa += c;
            } else if (vietHoa) {
                tenChuanHoa += toupper(c);
                vietHoa = false;
            } else {
                tenChuanHoa += tolower(c);
            }
        }
    return tenChuanHoa; 
    }

    static string toLower(const string &s) {
        string newS = "";
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] >= 'A' && s[i] <= 'Z') {
                newS += s[i] - 'A' + 'a';
            }
            else {
                newS += s[i];
            }
        }
        return newS;
    }

    static string genderToString(gender_value gender) {
        if(gender == NAM) return "Nam";
        if(gender == NU) return "Nu";
        return "Undefined";
    }

    static gender_value stringToGender(string s) {
        string tmp = trim(toLower(s));
        if(tmp == "nam") return NAM;
        if(tmp == "nu") return NU;
        return UNDEFINED_GENDER;
    }

    
    // add utils function here . . . 
};
#endif