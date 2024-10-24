#include "./header/KhachHang.h"
KhachHang::KhachHang() {
    IDKhachHang = "";   
    hoTen = "";
    ngaySinh = 0;
    soDienThoai = "";
    gioiTinh = false;
}

KhachHang::KhachHang(string IDKhachHang, string hoTen, time_t ngaySinh, string soDienThoai, bool gioiTinh) {
    this->IDKhachHang = IDKhachHang;
    this->hoTen = hoTen;
    this->ngaySinh = ngaySinh;
    this->soDienThoai = soDienThoai;
    this->gioiTinh = gioiTinh;
}

KhachHang::KhachHang(const KhachHang& KhachHang) {
    this->IDKhachHang = KhachHang.IDKhachHang;
    this->hoTen = KhachHang.hoTen;
    this->ngaySinh = KhachHang.ngaySinh;
    this->soDienThoai = KhachHang.soDienThoai;
    this->gioiTinh = KhachHang.gioiTinh;
}

KhachHang::~KhachHang() {
    
}

string KhachHang::getIDKhachHang() const {
    return this->IDKhachHang;
}

string KhachHang::getHoTen() const {
    return this->hoTen;
}

time_t KhachHang::getNgaySinh() const {
    return this->ngaySinh;
}

string KhachHang::getSoDienThoai() const {
    return this->soDienThoai;
}

bool KhachHang::getGioiTinh() const {
    return this->gioiTinh;
} 


void KhachHang::setIDKhachHang(string IDKhachHang) {
    this->IDKhachHang = IDKhachHang;
}

void KhachHang::setHoTen(string hoTen) {
    this->hoTen = hoTen;
}

void KhachHang::setNgaySinh(time_t ngaySinh) {
    this->ngaySinh = ngaySinh;
}

void KhachHang::setSoDienThoai(string soDienThoai) {
    this->soDienThoai = soDienThoai;
}

void KhachHang::setGioiTinh(bool gioiTinh) {
    this->gioiTinh = gioiTinh;
} 

string KhachHang::nhapNgaySinh() {
    string input;
    int day, month, year;
    int check;
    int maxDaysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};  // Số ngày trong tháng

    while (1) {  // Lặp lại nếu nhập sai
        cout << "Nhap ngay thang nam sinh (dinh dang dd/mm/yyyy): ";
        getline(cin, input);

        // Tách chuỗi thành ngày, tháng, năm
        stringstream ss(input);
        string temp_day, temp_month, temp_year;

        getline(ss, temp_day, '/');
        getline(ss, temp_month, '/');
        getline(ss, temp_year, '/');

        // Chuyển chuỗi sang số nguyên
        day = atoi(temp_day.c_str());
        month = atoi(temp_month.c_str());
        year = atoi(temp_year.c_str());

        check = 1;

        // Kiểm tra tháng và năm hợp lệ
        if (month <= 0 || month > 12 || year <= 1900 || year > localTimeInfo->tm_year + 1900 - 18) {
            check = 0;
        }

        // Kiểm tra năm nhuận
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
            if (month == 2 && (day > 29 || day <= 0)) {
                check = 0;
            }
        } else {
            // Kiểm tra ngày hợp lệ
            if (day <= 0 || day > maxDaysInMonth[month - 1]) {
                check = 0;
            }
        }

        if (check != 1) {
            std::cout << "Ban nhap sai, vui long nhap lai!\n";
            continue;
        }

        return input;
    }
}

void KhachHang::menuSuaThongTin(){        //in menu sửa thông tin
    cout << "1. Sua ID Khach Hang" << endl;
    cout << "2. Sua Ho Ten" << endl;
    cout << "3. Sua Ngay Sinh" << endl;
    cout << "4. Sua So Dien Thoai" << endl;
    cout << "5. Sua Gioi Tinh" << endl;
    cout << "6. Thoat" << endl;
    cout << "Hay nhap lua chon: ";
}
void KhachHang::suaThongTin() {
    string choice;          //lựa chọn
    string temp;            //biến tạm

    while (true) {
        menuSuaThongTin();
        choice = nhap(1, 2);         //chọn 2 vì 1 số và 1 ký tự '\0'
        switch(choice) {
            case '1':
                cout << "Nhap ID Khach Hang moi: ";
                temp = nhap(1, 10);           //id khách hàng có 9 ký tự
                this->setIDKhachHang(temp);
                system("clear");
                cout<< "Chinh sua thong tin thanh cong!" << endl;
                break;
            case "2":
                cout << "Nhap ho ten moi: ";
                temp = nhap(2, MAX_NAME+1);
                this->setHoTen(temp);
                system("clear");
                cout<< "Chinh sua thong tin thanh cong!" << endl;
                break;
            case "3":
                temp = nhapNgaySinh();
                system("clear");
                cout<< "Chinh sua thong tin thanh cong!" << endl;
                break;
            case "4":
                cout << "Nhap So dien thoai moi: ";
                temp = nhap(1, 11);           //số điện thoại có 10 ký tự
                this->setSoDienThoai(temp);
                system("clear");
                cout<< "Chinh sua thong tin thanh cong!" << endl;
                break;
            case "5":
                cout << "Nhap gioi tinh moi (Nam nhap 0, Nu nhap 1): ";
                temp = nhap(1, 2);           //giới tính có 1 ký tự
                this->setGioiTinh(temp);
                system("clear");
                cout<< "Chinh sua thong tin thanh cong!" << endl;
                break;
            case "6":
                return;
            default:
                system("clear");
                cout << "Lua chon khong hop le." << endl;
                cout<< "Vui long chon lai!" << endl;
                break;
        }  
    }
}

void KhachHang::work() {
    cout << "ID Khach Hang: " << this->IDKhachHang << endl;
    cout << "Ho Ten: " << this->hoTen << endl;
    cout << "Ngay Sinh: " << this->ngaySinh << endl;
    cout << "So Dien Thoai: " << this->soDienThoai << endl;
    cout << "Gioi Tinh: " << this->gioiTinh << endl;
}

string KhachHang::taoIDKhachHang() {        //tạo ID khách hàng bằng cách lấy ID khách hàng cuối cùng tăng lên 1
                                            //chứ ko lưu vào file
    string IDKhachHang;
    if(DSKH->prev == DSKH->head) {
        IDKhachHang = "100001";    //số đầu tên là chia đối tượng kh, nhân viên,...
    }
    else if(DSKH->prev->data.getIDKhachHang() == "199999") {
        return -1;      //đã đạt giới hạn số khách hàng
    }
    else{
        string head = DSKH->prev->data.getIDKhachHang().substr(0, 1);   //lấy số đầu
        string tail = DSKH->prev->data.getIDKhachHang().substr(1);      //lấy số sau
        int num = stoi(tail) + 1;
        IDKhachHang = head + to_string(num);
    }
    return IDKhachHang;
}
void KhachHang::huyDatPhong(string IDDatPhong) {

}
