#include "./header/QLDatPhong.h"

/**
 * @brief Hàm hủy cho lớp QLDatPhong.
 */
QLDatPhong::~QLDatPhong() {
    Node<DatPhong *> *p = DSDP.begin();
    while(p != DSDP.end()) {
        delete p->data;
        p = p->next;
    }
}

/**
 * @brief Thêm đặt phòng.
 */
void QLDatPhong::themDatPhong(DatPhong *DP) {
    DSDP.add(DP);
}

/**
 * @brief Xóa đặt phòng.
 */
void QLDatPhong::xoaDatPhong(DatPhong *DP) {
    Node<DatPhong *> *p = DSDP.begin();
    while(p != DSDP.end()) {
        if(p->data == DP) {
            DSDP.remove(p);
            return;
        }
        p = p->next;
    }
}

/**
 * @brief Tìm kiếm đặt phòng theo mã đặt phòng.
 */
DatPhong *QLDatPhong::timKiemDatPhong(string MDP) {
    Node<DatPhong *> *p = DSDP.begin();
    while(p != DSDP.end()) {
        if(p->data->getMaDatPhong() == MDP) 
            return p->data;
        p = p->next;
    }
    return nullptr;
}

/**
 * @brief Lấy mã đặt phòng lớn nhất
 * Nếu danh sách rỗng thì trả về 00000
 */
string QLDatPhong::getMaxMaDatPhong() {
    string MDP;
    Node<DatPhong *> *p = DSDP.begin();
    if(p == DSDP.end()) {
        MDP = "00000";
    }
    else{
        MDP = p->prev->prev->data->getMaDatPhong();
    }
    return MDP;
}

/**
 * @brief Tạo mã đặt phòng mới
 * Nêu mã đặt phòng cuối cùng là 99999 thì trả về 000001
 */
string QLDatPhong::taoMaDatPhong(){
    string MDPNew;
    if (this->getMaxMaDatPhong() == "99999") {
        MDPNew = "000001";
    }
    else{
        MDPNew = Utils::intToString(Utils::stringToInt(getMaxMaDatPhong()) + 1);
        int size = MDPNew.size();
        for(int i=0; i<(SIZE_ID_DP-size); i++){
            MDPNew="0"+MDPNew;
        }
    }
    return MDPNew;
}

/**
 * @brief Lấy danh sách đặt phòng.
 */
LinkedList<DatPhong *> &QLDatPhong::getDSDP() {
    return this->DSDP;
}

/**
 * @brief In thông tin quản lí đặt phòng.
 */
ostream &operator<<(ostream &os, const QLDatPhong &ql) {
    Utils::outputData("-----------------THONG-TIN-QUAN-LI-DAT-PHONG-----------------\n", CONSOLE);
    Utils::outputData("Danh sach dat phong: \n", CONSOLE);
    Node<DatPhong *> *p = ql.DSDP.begin();
    while(p != ql.DSDP.end()) {
        os << *p->data;
        Utils::outputData("\n", CONSOLE);
        p = p->next;
    }
    return os;
}