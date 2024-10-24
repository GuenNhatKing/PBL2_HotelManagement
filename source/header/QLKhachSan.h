#ifndef QLKHACHSAN_H
#define QLKHACHSAN_H
#include <fstream>
#include <sstream>
#include <cctype>
#include <conio.h>
#include "DatPhong.h"
#include "KhachHang.h"
#include "LoaiPhong.h"
#include "Phong.h"
#include "TaiKhoan.h"
#include "QLKhachHang.h"
#include "QLDatPhong.h"
#include "QLLoaiPhong.h"
#include "QLPhong.h"
#include "NhanVien.h"
#include "QuanLi.h"
#include "LinkedList.h"
#include <iostream> 
#include <fstream>

#define MAX_NAME 50

class QLKhachSan {
    QLKhachHang QLKH;
    LinkedList<TaiKhoan> DSTKKH;

    NhanVien NV;
    TaiKhoan TKNhanVien;

    QuanLi QL;
    TaiKhoan TKQuanLi;
    
    QLDatPhong QLDP;
    QLLoaiPhong QLLP;
    QLPhong QLP;

    enum role_value {
        UNDEFINED = -1,
        KHACHHANG,
        NHANVIEN,
        QUANLI,
    };       
    role_value role = UNDEFINED;         
public:
    QLKhachSan();
    ~QLKhachSan();

    void inputTaiKhoan(string);
    void inputKhachHang(string);
    void inputLoaiPhong(string);
    void inputPhong(string);
    void inputDatPhong(string);

    void outputTaiKhoan(string);
    void outputKhachHang(string);
    void outputLoaiPhong(string);
    void outputPhong(string);
    void outputDatPhong(string);

    void work();
    NguoiDung *dangNhap();
    void dangXuat();
    void kiemTraTraPhong();
    void thongBao(string, string);
    void chuanHoaTen(string &);
    string Nhap(int ,int );
};
#endif