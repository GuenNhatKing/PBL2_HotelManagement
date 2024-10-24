#ifndef QLKHACHHANG_H
#define QLKHACHHANG_H
#include "KhachHang.h"
#include "LinkedList.h"
class QLKhachHang {
    LinkedList<KhachHang> DSKH; // Danh sach khach hang
public:
    QLKhachHang();
    ~QLKhachHang();

    void themKhachHang(KhachHang);
    KhachHang *timKiemKhachHang(string); // Tim kiem theo id
    void suaThongTin(string);
    void xoaKhachHang(KhachHang); // xóa khách hàng theo id và ten
};
#endif