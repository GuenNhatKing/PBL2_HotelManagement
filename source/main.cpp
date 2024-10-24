#include <iostream>
#include "./header/QLKhachSan.h"
using namespace std;

int main() {
    // g++ .\DatPhong.cpp .\KhachHang.cpp .\LoaiPhong.cpp .\NhanVien.cpp .\Phong.cpp .\QuanLi.cpp .\TaiKhoan.cpp .\QLKhachHang.cpp .\QLDatPhong.cpp .\QLLoaiPhong.cpp .\QLPhong.cpp .\QLKhachSan.cpp .\main.cpp
    QLKhachSan db;
    db.inputTaiKhoan("data/TaiKhoan.txt");
    db.inputKhachHang("data/KhachHang.txt");
    db.inputLoaiPhong("data/LoaiPhong.txt");
    db.inputPhong("data/Phong.txt");
    db.inputDatPhong("data/DatPhong.txt");
    db.work();
    return 0;
}