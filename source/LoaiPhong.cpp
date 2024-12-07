#include "./header/LoaiPhong.h"
#include <bits/stdc++.h>
LoaiPhong::LoaiPhong(){
    this->loaiPhong = "";
    this->loaiGiuong = 0;
    this->soLuongKhach = 0;
    this->dienTich = 0;
    this->giaPhong = 0;
    this->moTaPhong = "";
}

LoaiPhong::LoaiPhong(string LoaiPhong, int LoaiGiuong, int SoLuongKhach, int DienTich, int GiaPhong, string MoTaPhong) {
    this->loaiPhong = "";
    this->loaiGiuong = 0;
    this->soLuongKhach = 0;
    this->dienTich = 0;
    this->giaPhong = 0;
    this->moTaPhong = "";
    
    setLoaiPhong(LoaiPhong);
    setLoaiGiuong(LoaiGiuong);
    setSoLuongKhach(SoLuongKhach);
    setDienTich(DienTich);
    setGiaPhong(GiaPhong);
    setMoTaPhong(MoTaPhong);
}

LoaiPhong::LoaiPhong(const LoaiPhong& other) {
    this->loaiPhong = other.loaiPhong;
    this->loaiGiuong = other.loaiGiuong;
    this->soLuongKhach = other.soLuongKhach;
    this->dienTich = other.dienTich;
    this->giaPhong = other.giaPhong;
    this->moTaPhong = other.moTaPhong;
    this->soLuongKhach = other.soLuongKhach;
}
LoaiPhong::~LoaiPhong() {}

// Getters
string LoaiPhong::getLoaiPhong() const {
      return this->loaiPhong;
}

int LoaiPhong::getLoaiGiuong() const {
    return this->loaiGiuong;
}

int LoaiPhong::getSoLuongKhach() const {
    return this->soLuongKhach;

}

int LoaiPhong::getDienTich() const {
    return this->dienTich;
}

int LoaiPhong::getGiaPhong() const {
    return this->giaPhong;
}

string LoaiPhong::getMoTaPhong() const {
    return this->moTaPhong;
}

bool LoaiPhong::setLoaiPhong(string LP){
    if(Utils::isAlphabetAndNumberOnly(LP)){
        this->loaiPhong = LP;
        return true;
    }
    else {
        return false;
    }
}

bool LoaiPhong::setLoaiGiuong(int LG) {
    int s = LG;
        int roomBedTypes[] = {1, 2, 12};
        for (int roomBedType : roomBedTypes) {
            if (s == roomBedType) {
                this->loaiGiuong = LG;
                return true;
            }
        }
        return false;
}

bool LoaiPhong::setSoLuongKhach(int SLK) {
    if(SLK > 0 && SLK < 9){
        this->soLuongKhach = SLK;
        return true;
    }
    else {
        return false;
    }
}

bool LoaiPhong::setDienTich(int DT) {
    if(DT > 0 && DT < 1000){
        this->dienTich = DT;
        return true;
    }
    else {
        return false;
    }
}

bool LoaiPhong::setGiaPhong(int GP) {
    if(GP > 0 && GP < 100000000){
        this->giaPhong = GP;
        return true;
    }
    else {
        return false;
    }
}

bool LoaiPhong::setMoTaPhong(string MTP) {
    this->moTaPhong = MTP;
    return true;
}

void LoaiPhong::themPhong(Phong *phong) {
    this->danhSachPhong.add(phong);
}

LoaiPhong LoaiPhong::nhapThongTin() {
    string temp;
    LoaiPhong tempLoaiPhong;
    
    temp = Utils::inputWithCondition("Nhap Loai Phong: ", 4, MAX_IDLOAIPHONG, ALPHABET_AND_NUMBER_ONLY);
    tempLoaiPhong.setLoaiPhong(temp);

    temp = Utils::inputWithCondition("Nhap Loai Giuong (Single,Double,SingleDouble): ", 6, 12, ROOM_BED_TYPE);
    if(temp == "Single") temp = "1";
    else if(temp == "Double") temp = "2";
    else if(temp == "SingleDouble" || temp == "DoubleSingle")temp = "12";
    tempLoaiPhong.setLoaiGiuong(Utils::stringToInt(temp));

    temp = Utils::inputWithCondition("Nhap So Luong Khach: ", 1, 2, NUMBER_ONLY);
    tempLoaiPhong.setSoLuongKhach(Utils::stringToInt(temp));

    temp = Utils::inputWithCondition("Nhap Dien Tich: ", 1, 3, NUMBER_ONLY);
    tempLoaiPhong.setDienTich(Utils::stringToInt(temp));

    temp = Utils::inputWithCondition("Nhap Gia Phong: ", 1, 7, NUMBER_ONLY);
    tempLoaiPhong.setGiaPhong(Utils::stringToInt(temp));

    temp = Utils::inputWithCondition("Nhap Mo Ta Phong: ", 3, 150, ALPHABET_AND_NUMBER_AND_SPACE_ONLY);
    tempLoaiPhong.setMoTaPhong(temp);
    Utils::outputData("Tao loai phong thanh cong!\n", CONSOLE);
    Utils::pauseConsole();
    return tempLoaiPhong;
}
//MENU
void LoaiPhong::menuSuaThongTin(){
    cout << "1. Sua Loai Giuong " << endl;
    cout << "2. Sua So Luong Khach " << endl;
    cout << "3. Sua Dien Tich: " << endl;
    cout << "4. Sua Gia " << endl;
    cout << "5. Sua Mo Ta Phong " << endl;
    cout << "6. Thoat Chinh Sua Loai Phong" << endl;
}

void LoaiPhong::capNhatThongTin(){
    int choice;
    string temp;
    while (true) {
        system("cls");
        menuSuaThongTin();
        choice = Utils::stringToInt(Utils::inputWithCondition("Hay nhap lua chon: ", 1, 1, NUMBER_ONLY));
        switch(choice) {
            case 1:
                temp = Utils::inputWithCondition("Sua Loai Giuong: ", 6, 12, ROOM_BED_TYPE);
                if(temp == "Single") temp = "1";
                else if(temp == "Double") temp = "2";
                else if(temp == "SingleDouble" || temp == "DoubleSingle")temp = "12";
                this->setLoaiGiuong(stoi(temp));
                Utils::outputData("Cap nhat thong tin thanh cong!\n", CONSOLE);
                Utils::pauseConsole();
                break;
            case 2:
                temp = Utils::inputWithCondition("Sua So Luong Khach: ", 1, 2, NUMBER_ONLY);
                this->setSoLuongKhach(Utils::stringToInt(temp));
                Utils::outputData("Cap nhat thong tin thanh cong!\n", CONSOLE);
                Utils::pauseConsole();
                break;
            case 3:
                temp = Utils::inputWithCondition("Sua Dien Tich: ", 1, 2, NUMBER_ONLY);
                this->setDienTich(Utils::stringToInt(temp));
                Utils::outputData("Cap nhat thong tin thanh cong!\n", CONSOLE);
                Utils::pauseConsole();
                break;
            case 4:
                temp = Utils::inputWithCondition("Sua Gia: ", 1, 3, NUMBER_ONLY);
                this->setGiaPhong(Utils::stringToInt(temp));
                Utils::outputData("Cap nhat thong tin thanh cong!\n", CONSOLE);
                Utils::pauseConsole();
                break;
            case 5:
                temp = Utils::inputWithCondition("Sua Mo Ta Phong: ", 3, 150, ALPHABET_AND_NUMBER_AND_SPACE_ONLY);
                this->setMoTaPhong(temp);
                Utils::outputData("Cap nhat thong tin thanh cong!\n", CONSOLE);
                Utils::pauseConsole();
                break;
            case 6:
                Utils::outputData("Thoat khoi chuc nang sua thong tin\n", CONSOLE);
                return;
            default:
                Utils::outputData("Lua chon khong hop le. Vui long thu lai\n", CONSOLE);
                Utils::pauseConsole();
                break;
        }  
    }
}

// XUAT THONG TIN
// void LoaiPhong::xuatThongTin() {
//     string temp;
//     if(loaiGiuong == 1) temp = "Single";
//     else if(loaiGiuong == 2) temp = "Double";
//     else if(loaiGiuong == 12) temp = "SingleDouble";
//     cout << left << setw(16) << loaiPhong << setw(14) << temp << setw(13) << soLuongKhach
//     << setw(9) << dienTich << setw(13) << giaPhong; 
//     Utils::wrapText(moTaPhong, 40, 65);
//     cout << string(105, '-') << endl;
// }   

ostream& operator<<(ostream& out, const LoaiPhong& lp) {
    string temp;
    if(lp.loaiGiuong == 1) temp = "Single";
    else if(lp.loaiGiuong == 2) temp = "Double";
    else if(lp.loaiGiuong == 12) temp = "SingleDouble";

    Utils::outputData("-----------THONG-TIN-LOAI-PHONG---------\n", CONSOLE);
    Utils::outputData("Loai Phong: ", CONSOLE);
    Utils::outputData(lp.loaiPhong + "\n", CONSOLE_OR_UI);
    Utils::outputData("Loai Giuong: ", CONSOLE);
    Utils::outputData(temp + "\n", CONSOLE_OR_UI);
    Utils::outputData("So Luong Khach: ", CONSOLE);
    Utils::outputData(Utils::intToString(lp.soLuongKhach) + "\n", CONSOLE_OR_UI);
    Utils::outputData("Dien Tich: ", CONSOLE);
    Utils::outputData(Utils::intToString(lp.dienTich) + " m2\n", CONSOLE_OR_UI);
    Utils::outputData("Gia: ", CONSOLE);
    Utils::outputData(Utils::chuanHoaSo(Utils::intToString(lp.giaPhong)) + " VND\n", CONSOLE_OR_UI);
    Utils::outputData("Mo ta Phong:\n", CONSOLE);
    Utils::wrapText(lp.moTaPhong, 40, 0);
    Utils::outputData(string(40, '-') + "\n", CONSOLE);
    return out;
}