#include "./header/QLKhachSan.h"


QLKhachSan::QLKhachSan() {
    
}

QLKhachSan::~QLKhachSan() {

}

void QLKhachSan::inputTaiKhoan(string) {

}

void QLKhachSan::inputKhachHang(string) {

}

void QLKhachSan::inputLoaiPhong(string) {

}

void QLKhachSan::inputPhong(string) {

}

void QLKhachSan::inputDatPhong(string) {

}


void QLKhachSan::outputTaiKhoan(string) {

}

void QLKhachSan::outputKhachHang(string) {

}

void QLKhachSan::outputLoaiPhong(string) {

}

void QLKhachSan::outputPhong(string) {

}

void QLKhachSan::outputDatPhong(string) {

}

void QLKhachSan::work() {
    NguoiDung *p;
    while(role == UNDEFINED) {
        if(role == -1) p = dangNhap();
        if(p != NULL) p->work();
    }
}

NguoiDung *QLKhachSan::dangNhap() {
    string username, password;
    cout << "Nhap username: ";
    cin >> username;
    cout << "Nhap password: ";
    cin >> password;
    Node<TaiKhoan> *i = DSTKKH.head->next;
    while(i != DSTKKH.head) {
        if(i->data.getUsername() == username && i->data.getPassword() == password) {
            role = KHACHHANG;
            return QLKH.timKiemKhachHang(i->data.getID()); 
        }
        i = i->next;
    }

    if(username == TKNhanVien.getUsername() && password == TKNhanVien.getPassword()) {
        role = NHANVIEN;
        return &NV;
    }

    if(username == TKQuanLi.getUsername() && password == TKQuanLi.getPassword()) {
        role = QUANLI;
        return &QL;
    }
    cout << "Sai username hoac password" << endl;
    return NULL;
}

void QLKhachSan::dangXuat() {
    role = UNDEFINED;
}

void QLKhachSan::kiemTraTraPhong() {

}

void QLKhachSan::thongBao(string, string) {

}
void QLKhachSan::chuanHoaTen(string &str) {
    // Chuyển tất cả các ký tự thành chữ thường
    for (char &c : str) {
        c = tolower(c);
    }
    // Chuyển ký tự đầu tiên và ký tự sau dấu cách thành chữ hoa
    for (size_t i = 0; i < str.size(); ++i) {
        if (i == 0 || str[i-1] == ' ') {
            str[i] = toupper(str[i]);
        }
    }
}
string QLKhachSan::nhap(int kytu, int sl) { 
    //khi dùng sl phải tăng thêm 1 vì còn ký tự '\0'     
    //kytu 1: Chỉ số; 2: Chữ và khoản trắng; 3: Cả 2
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