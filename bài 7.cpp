#include <stdio.h>
#include <string.h>

struct SinhVien {
    int id;
    char name[100];
    int age;
    char phoneNumber[15];
};

void xoaSinhVien(int idXoa, struct SinhVien sinhVien[], int *currentSize) {
    int found = 0;
    for (int i = 0; i < *currentSize; i++) {
        if (sinhVien[i].id == idXoa) {
            found = 1;
            for (int j = i; j < *currentSize - 1; j++) {
                sinhVien[j] = sinhVien[j + 1];
            }
            (*currentSize)--;
            printf("\nSinh vien voi ID %d da bi xoa.\n", idXoa);
            break;
        }
    }
    if (!found) {
        printf("\nKhong tim thay sinh vien voi ID: %d\n", idXoa);
    }
}

void hienThiDanhSach(struct SinhVien sinhVien[], int currentSize) {
    printf("\nThong tin toan bo sinh vien trong mang:\n");
    for (int i = 0; i < currentSize; i++) {
        printf("\nSinh vien %d:\n", sinhVien[i].id);
        printf("Ten: %s\n", sinhVien[i].name);
        printf("Tuoi: %d\n", sinhVien[i].age);
        printf("So dien thoai: %s\n", sinhVien[i].phoneNumber);
    }
}

int main() {
    struct SinhVien sinhVien[50] = {
        {1, "Decade", 20, "0123456789"},
        {2, "Zio", 21, "0987654321"},
        {3, "OOO", 22, "0980808800"},
        {4, "Fang", 23, "0965412548"},
        {5, "Thien", 24, "025327698"}
    };
    int currentSize = 5;
    hienThiDanhSach(sinhVien, currentSize);

    int idXoa;
    printf("\nNhap ID sinh vien can xoa: ");
    scanf("%d", &idXoa);
    xoaSinhVien(idXoa, sinhVien, &currentSize);
    hienThiDanhSach(sinhVien, currentSize);

    return 0;
}

