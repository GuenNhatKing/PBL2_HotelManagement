#ifndef QLDATPHONG_H
#define QLDATPHONG_H
#include "DatPhong.h"
class KhachHang;
#include "KhachHang.h"
#include "Phong.h"

class QLDatPhong {
    DatPhong *DSDP; // Danh sach dat phong
public:
    QLDatPhong();
    ~QLDatPhong();

    void themDatPhong(DatPhong);
    void xoaDatPhong(DatPhong);
    void suaThongTin(string);
    void danhSachPhongTrong(time_t, time_t);

    void datPhong(KhachHang, Phong);
    void huyPhong(string);
};
#endif