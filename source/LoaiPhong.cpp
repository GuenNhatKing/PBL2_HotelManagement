#include "./header/LoaiPhong.h"
/**
 * @brief Hàm khởi tạo mặc định cho lớp LoaiPhong.
 */
LoaiPhong::LoaiPhong() {
    this->loaiPhong = "";
    this->loaiGiuong = 0;
    this->soLuongKhach = 0;
    this->dienTich = 0;
    this->giaPhong = 0;
    this->moTaPhong = "";
}

/**
 * @brief Hàm khởi tạo cho lớp LoaiPhong.
 */
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

/**
 * @brief Hàm sao chép cho lớp LoaiPhong.
 */
LoaiPhong::LoaiPhong(const LoaiPhong& other) {
    this->loaiPhong = other.loaiPhong;
    this->loaiGiuong = other.loaiGiuong;
    this->soLuongKhach = other.soLuongKhach;
    this->dienTich = other.dienTich;
    this->giaPhong = other.giaPhong;
    this->moTaPhong = other.moTaPhong;
    this->soLuongKhach = other.soLuongKhach;
}

/**
 * @brief Lấy mã loại phòng.
 */
string LoaiPhong::getLoaiPhong() const {
      return this->loaiPhong;
}

/**
 * @brief Lấy loại giường.
 */
int LoaiPhong::getLoaiGiuong() const {
    return this->loaiGiuong;
}

/**
 * @brief Lấy loại giường dưới dạng chuỗi.
 */
string LoaiPhong::getLoaiGiuongStr() const {
    if(this->loaiGiuong == 1) return "Single";
    if(this->loaiGiuong == 2) return "Double";
    if(this->loaiGiuong == 12) return "SingleDouble";
    return "";
}

/**
 * @brief Lấy số lượng khách.
 */
int LoaiPhong::getSoLuongKhach() const {
    return this->soLuongKhach;
}

/**
 * @brief Lấy diện tích.
 */
int LoaiPhong::getDienTich() const {
    return this->dienTich;
}

/**
 * @brief Lấy giá phòng.
 */
int LoaiPhong::getGiaPhong() const {
    return this->giaPhong;
}

/**
 * @brief Lấy mô tả phòng.
 */
string LoaiPhong::getMoTaPhong() const {
    return this->moTaPhong;
}

int LoaiPhong::getSoLuongPhong() const {
    return this->danhSachPhong.getSize();
}

/**
 * @brief Thiết lập loại phòng.
 */
bool LoaiPhong::setLoaiPhong(string LP){
    if(Utils::isAlphabetAndNumberOnly(LP)){
        this->loaiPhong = LP;
        return true;
    }
    else {
        return false;
    }
}

/**
 * @brief Thiết lập loại giường.
 */
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

/**
 * @brief Thiết lập số lượng khách.
 */
bool LoaiPhong::setSoLuongKhach(int SLK) {
    if(SLK > 0 && SLK < 9){
        this->soLuongKhach = SLK;
        return true;
    }
    else {
        return false;
    }
}

/**
 * @brief Thiết lập diện tích.
 */
bool LoaiPhong::setDienTich(int DT) {
    if(DT > 0 && DT < 1000){
        this->dienTich = DT;
        return true;
    }
    else {
        return false;
    }
}

/**
 * @brief Thiết lập giá phòng.
 */
bool LoaiPhong::setGiaPhong(int GP) {
    if(GP > 0 && GP < 100000000){
        this->giaPhong = GP;
        return true;
    }
    else {
        return false;
    }
}

/**
 * @brief Thiết lập mô tả phòng.
 */
bool LoaiPhong::setMoTaPhong(string MTP) {
    this->moTaPhong = MTP;
    return true;
}

/**
 * @brief Thêm phòng vào danh sách phòng.
 */
void LoaiPhong::themPhong(Phong *phong) {
    this->danhSachPhong.add(phong);
}

/**
 * @brief Xóa phòng khỏi danh sách phòng.
 */
void LoaiPhong::xoaPhong(Phong *phong) {
    Node<Phong *> *p = this->danhSachPhong.begin();
    while(p != this->danhSachPhong.end()) {
        if(p->data == phong) {
            this->danhSachPhong.remove(p);
            return;
        }
        p = p->next;
    }
}

/**
 * @brief Nhập thông tin loại phòng.
 */
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

    temp = Utils::inputWithCondition("Nhap Gia Phong: ", 1, 8, NUMBER_ONLY);
    tempLoaiPhong.setGiaPhong(Utils::stringToInt(temp));

    Utils::inputData(temp, CONSOLE_OR_UI);
    tempLoaiPhong.setMoTaPhong(temp);
    Utils::outputData("Tao loai phong thanh cong!\n", CONSOLE);
    Utils::pauseConsole();
    return tempLoaiPhong;
}

/**
 * @brief In menu sửa thông tin.
 */
void LoaiPhong::menuSuaThongTin(){
    Utils::outputData("1. Sua Loai Giuong\n", CONSOLE);
    Utils::outputData("2. Sua So Luong Khach\n", CONSOLE);
    Utils::outputData("3. Sua Dien Tich\n", CONSOLE);
    Utils::outputData("4. Sua Gia\n", CONSOLE);
    Utils::outputData("5. Sua Mo Ta Phong\n", CONSOLE);
    Utils::outputData("6. Thoat\n", CONSOLE);
}

/**
 * @brief Cập nhật thông tin.
 */
void LoaiPhong::capNhatThongTin(){
    int choice;
    string temp;
    while (true) {
        system("cls");
        menuSuaThongTin();
        choice = Utils::stringToInt(Utils::inputWithCondition("Hay nhap lua chon: ", 1, 1, NUMBER_ONLY));
        cout << "choice: " << choice << endl;   
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
                temp = Utils::inputWithCondition("Sua Dien Tich: ", 1, 3, NUMBER_ONLY);
                this->setDienTich(Utils::stringToInt(temp));
                Utils::outputData("Cap nhat thong tin thanh cong!\n", CONSOLE);
                Utils::pauseConsole();
                break;
            case 4:
                temp = Utils::inputWithCondition("Sua Gia: ", 1, 8, NUMBER_ONLY);
                this->setGiaPhong(Utils::stringToInt(temp));
                Utils::outputData("Cap nhat thong tin thanh cong!\n", CONSOLE);
                Utils::pauseConsole();
                break;
            case 5:
                Utils::outputData("Sua Mo Ta Phong: ", CONSOLE);
                Utils::inputData(temp, CONSOLE_OR_UI);
                this->setMoTaPhong(temp);
                Utils::outputData("Cap nhat thong tin thanh cong!\n", CONSOLE);
                Utils::pauseConsole();
                break;
            case 6:
                cout << "Done" << endl;
                Utils::outputData("Thoat khoi chuc nang sua thong tin\n", CONSOLE);
                return;
            default:
                Utils::outputData("Lua chon khong hop le. Vui long thu lai\n", CONSOLE);
                Utils::pauseConsole();
                break;
        }  
    }
}

/**
 * @brief In thông tin loại phòng.
 */
ostream& operator<<(ostream& out, const LoaiPhong& lp) {
    Utils::outputData("-----------THONG-TIN-LOAI-PHONG---------\n", CONSOLE);
    Utils::outputData("Loai Phong: ", CONSOLE);
    Utils::outputData(lp.loaiPhong + "\n", CONSOLE_OR_UI);
    Utils::outputData("Loai Giuong: ", CONSOLE);
    Utils::outputData(lp.getLoaiGiuongStr() + "\n", CONSOLE_OR_UI);
    Utils::outputData("So Luong Khach: ", CONSOLE);
    Utils::outputData(Utils::intToString(lp.soLuongKhach) + "\n", CONSOLE_OR_UI);
    Utils::outputData("Dien Tich: ", CONSOLE);
    Utils::outputData(Utils::intToString(lp.dienTich) + " m2\n", CONSOLE_OR_UI);
    Utils::outputData("Gia: ", CONSOLE);
    Utils::outputData(Utils::chuanHoaSo(Utils::intToString(lp.giaPhong)) + " VND\n", CONSOLE_OR_UI);
    Utils::outputData("Mo ta Phong:\n", CONSOLE);
    Utils::wrapText(lp.moTaPhong, 40, 0);
    Utils::outputData("So luong phong: ", CONSOLE);
    Utils::outputData(Utils::intToString(lp.danhSachPhong.getSize()) + "\n", CONSOLE_OR_UI);
    Utils::outputData("------NhatHoang-DuongHuy-ThaoDuyen------\n", CONSOLE);
    return out;
}