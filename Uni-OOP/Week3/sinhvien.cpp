#include "sinhvien.h"

SinhVien::SinhVien()
: m_Ten(new char[STR_SIZE]())
, m_MaSo(new char[STR_SIZE]())
, m_NgaySinh(new char[STR_SIZE]())
, m_Diem(new float[MARK_SIZE]())
{
}

SinhVien::~SinhVien()
{
    delete[] m_Ten;
    delete[] m_MaSo;
    delete[] m_NgaySinh;
    delete[] m_Diem;
}

// void SinhVien::Input()
// {
//     // set m_Ten value
//     std::string ten;
//     std::cout << "Nhap ten sinh vien: ";
//     getline(std::cin, ten);
//     strcpy_s(m_Ten, strlen(m_Ten), ten.c_str());

//     // set m_MaSo value
//     std::string maSo;
//     std::cout << "Nhap ma so sinh vien: ";
//     getline(std::cin, maSo);
//     strcpy_s(m_MaSo, strlen(m_MaSo), maSo.c_str());

//     // set m_NgaySinh value
//     std::string ngaySinh;
//     std::cout << "Nhap ngay sinh cua sinh vien: ";
//     getline(std::cin, ngaySinh);
//     strcpy_s(m_MaSo, strlen(m_NgaySinh), ngaySinh.c_str());

//     // set m_Diem value
//     std::cout << "Nhap diem bai tap cua sinh vien: ";
//     std::cin >> m_Diem[0];
//     std::cout << "Nhap diem giua ki cua sinh vien: ";
//     std::cin >> m_Diem[1];
//     std::cout << "Nhap diem cuoi ki cua sinh vien: ";
//     std::cin >> m_Diem[2];
// }

void SinhVien::SetValue(const std::string& val, int status)
{
    switch (status)
    {
    case 0:
        strcpy_s(m_Ten, val.size() + 1, val.c_str());
        break;
    case 1:
        strcpy_s(m_MaSo, val.size() + 1, val.c_str());
        break;
    case 2:
        strcpy_s(m_NgaySinh, val.size() + 1, val.c_str());
        break;
    default:
        m_Diem[status - 3] = std::atof(val.c_str());
        break;
    }
}

SinhVien::SinhVien(const SinhVien& sv)
: m_Ten(new char[STR_SIZE]())
, m_MaSo(new char[STR_SIZE]())
, m_NgaySinh(new char[STR_SIZE]())
, m_Diem(new float[MARK_SIZE]())
{ 
    // copy char*
    strcpy_s(m_Ten, strlen(m_Ten), sv.m_Ten);
    strcpy_s(m_MaSo, strlen(m_MaSo), sv.m_MaSo);
    strcpy_s(m_NgaySinh, strlen(m_NgaySinh), sv.m_NgaySinh);

    // copy array
    std::copy(sv.m_Diem, sv.m_Diem + MARK_SIZE, m_Diem);
}

SinhVien& SinhVien::operator=(SinhVien other)
{
    swap(*this, other);
    return *this;
}

void SinhVien::Output()
{
    std::cout << "Ten cua sinh vien: "  << m_Ten << "\n";
    std::cout << "Ma so sinh vien: " << m_MaSo << "\n";
    std::cout << "Ngay sinh cua sinh vien: " << m_NgaySinh << "\n";
    std::cout << "Diem bai tap cua sinh vien: " << m_Diem[0] << "\n";
    std::cout << "Diem giua ky cua sinh vien: " << m_Diem[1] << "\n";
    std::cout << "Diem cuoi ky cua sinh vien: " << m_Diem[2] << "\n";
}

float SinhVien::AvgMark() const
{
    return (m_Diem[0] * 0.25f) + (m_Diem[1] * 0.25f) + (m_Diem[2] * 0.5f);
}

/*
write in format: ten,ma so,ngay sinh,diembt,diemgk,diemck
*/
std::ostream& operator<<(std::ostream& os, const SinhVien& sv)
{
    os << sv.m_Ten << "," 
       << sv.m_MaSo << "," 
       << sv.m_NgaySinh << "," 
       << sv.m_Diem[0] << "," 
       << sv.m_Diem[1] << "," 
       << sv.m_Diem[2] << std::endl;
    return os;
}

void swap(SinhVien& sv1, SinhVien& sv2)
{
    using std::swap; // ADL
    swap(sv1.m_Ten, sv2.m_Ten);
    swap(sv1.m_MaSo, sv2.m_MaSo);
    swap(sv1.m_NgaySinh, sv2.m_NgaySinh);
    swap(sv1.m_Diem, sv2.m_Diem);
}