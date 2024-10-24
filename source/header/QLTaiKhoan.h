#ifndef QLTAIKHOAN_H
#define QLTAIKHOAN_H
#include "TaiKhoan.h"
class QLTaiKhoan {
    TaiKhoan *DSTK; // Danh sach tai khoan
public:
    QLTaiKhoan();  // Tao danh sach
    ~QLTaiKhoan();

    void themTaiKhoan(TaiKhoan);
    void timKiemTaiKhoan(string); // Tim kiem theo id hay ten?
    void suaThongTin(string);
    void xoaTaiKhoan(TaiKhoan); // string?
};
#endif