#include <stdio.h>
#include <string.h>

struct SinhVien {
    int id;
    char name[100];
    int age;
    char phoneNumber[15];
};

void hienThiDanhSach(struct SinhVien sinhVien[], int currentSize) {
    printf("\nDanh sach sinh vien:\n");
    for (int i = 0; i < currentSize; i++) {
        printf("\nSinh vien %d:\n", sinhVien[i].id);
        printf("Ten: %s\n", sinhVien[i].name);
        printf("Tuoi: %d\n", sinhVien[i].age);
        printf("So dien thoai: %s\n", sinhVien[i].phoneNumber);
    }
}

void themSinhVien(struct SinhVien sinhVien[], int *currentSize) {
    printf("\nNhap thong tin sinh vien moi:\n");
    printf("ID: ");
    scanf("%d", &sinhVien[*currentSize].id);
    getchar();
    printf("Ten: ");
    fgets(sinhVien[*currentSize].name, sizeof(sinhVien[*currentSize].name), stdin);
    sinhVien[*currentSize].name[strcspn(sinhVien[*currentSize].name, "\n")] = 0;
    printf("Tuoi: ");
    scanf("%d", &sinhVien[*currentSize].age);
    getchar(); 
    printf("So dien thoai: ");
    fgets(sinhVien[*currentSize].phoneNumber, sizeof(sinhVien[*currentSize].phoneNumber), stdin);
    sinhVien[*currentSize].phoneNumber[strcspn(sinhVien[*currentSize].phoneNumber, "\n")] = 0;
    (*currentSize)++;
    printf("\nDa them sinh vien thanh cong!\n");
}

void suaThongTinSinhVien(struct SinhVien sinhVien[], int currentSize) {
    int idSua;
    printf("\nNhap ID sinh vien can sua: ");
    scanf("%d", &idSua);
    for (int i = 0; i < currentSize; i++) {
        if (sinhVien[i].id == idSua) {
            getchar(); 
            printf("Nhap ten moi: ");
            fgets(sinhVien[i].name, sizeof(sinhVien[i].name), stdin);
            sinhVien[i].name[strcspn(sinhVien[i].name, "\n")] = 0;
            printf("Nhap tuoi moi: ");
            scanf("%d", &sinhVien[i].age);
            getchar(); 
            printf("Nhap so dien thoai moi: ");
            fgets(sinhVien[i].phoneNumber, sizeof(sinhVien[i].phoneNumber), stdin);
            sinhVien[i].phoneNumber[strcspn(sinhVien[i].phoneNumber, "\n")] = 0;
            printf("\nDa cap nhat thong tin sinh vien!\n");
            return;
        }
    }
    printf("\nKhong tim thay sinh vien voi ID: %d\n", idSua);
}

void xoaSinhVien(struct SinhVien sinhVien[], int *currentSize) {
    int idXoa;
    printf("\nNhap ID sinh vien can xoa: ");
    scanf("%d", &idXoa);
    for (int i = 0; i < *currentSize; i++) {
        if (sinhVien[i].id == idXoa) {
            for (int j = i; j < *currentSize - 1; j++) {
                sinhVien[j] = sinhVien[j + 1];
            }
            (*currentSize)--;
            printf("\nSinh vien voi ID %d da bi xoa.\n", idXoa);
            return;
        }
    }
    printf("\nKhong tim thay sinh vien voi ID: %d\n", idXoa);
}

void timKiemSinhVien(struct SinhVien sinhVien[], int currentSize) {
    int idTim;
    printf("\nNhap ID sinh vien can tim: ");
    scanf("%d", &idTim);
    for (int i = 0; i < currentSize; i++) {
        if (sinhVien[i].id == idTim) {
            printf("\nThong tin sinh vien:\n");
            printf("ID: %d\n", sinhVien[i].id);
            printf("Ten: %s\n", sinhVien[i].name);
            printf("Tuoi: %d\n", sinhVien[i].age);
            printf("So dien thoai: %s\n", sinhVien[i].phoneNumber);
            return;
        }
    }
    printf("\nKhong tim thay sinh vien voi ID: %d\n", idTim);
}

void sapXepDanhSach(struct SinhVien sinhVien[], int currentSize) {
    for (int i = 0; i < currentSize - 1; i++) {
        for (int j = i + 1; j < currentSize; j++) {
            if (strcmp(sinhVien[i].name, sinhVien[j].name) > 0) {
                struct SinhVien temp = sinhVien[i];
                sinhVien[i] = sinhVien[j];
                sinhVien[j] = temp;
            }
        }
    }
    printf("\nDanh sach da duoc sap xep theo ten.\n");
}

int main() {
    struct SinhVien sinhVien[50];
    int currentSize = 0;
    int luaChon;

    do {
        printf("\nMENU\n");
        printf("1. Hien thi danh sach sinh vien\n");
        printf("2. Them sinh vien\n");
        printf("3. Sua thong tin sinh vien\n");
        printf("4. Xoa sinh vien\n");
        printf("5. Tim kiem sinh vien\n");
        printf("6. Sap xep danh sach sinh vien\n");
        printf("7. Thoat\n");
        printf("\nLua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                hienThiDanhSach(sinhVien, currentSize);
                break;
            case 2:
                themSinhVien(sinhVien, &currentSize);
                break;
            case 3:
                suaThongTinSinhVien(sinhVien, currentSize);
                break;
            case 4:
                xoaSinhVien(sinhVien, &currentSize);
                break;
            case 5:
                timKiemSinhVien(sinhVien, currentSize);
                break;
            case 6:
                sapXepDanhSach(sinhVien, currentSize);
                break;
            case 7:
                printf("\nThoat chuong trinh.\n");
                break;
            default:
                printf("\nLua chon khong hop le!\n");
        }
    } while (luaChon != 7);

    return 0;
}

