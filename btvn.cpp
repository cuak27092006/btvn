#include <stdio.h>

int main() {
    int Mang[100], n = 0;
    int chon;

    do {
        printf("\nMENU\n");
        printf("1. Nhap so phan tu va gia tri phan tu trong mang\n");
        printf("2. In mang ra man hinh\n");
        printf("3. Dem so luong so hoan hao\n");
        printf("4. Dem so luong so nguyen to\n");
        printf("5. Tim gia tri lon thu 2\n");
        printf("6. Tim gia tri nho thu 2\n");
        printf("7. Them phan tu tai vi tri\n");
        printf("8. Xoa phan tu tai vi tri\n");
        printf("9. Sap xep mang tang dan (thao tac chen)\n");
        printf("10. Sap xep mang giam dan (thao tac chen)\n");
        printf("11. Tim kiem phan tu trong mang\n");
        printf("12. Xoa cac phan tu trung lap va in cac phan tu duy nhat\n");
        printf("13. Sap xep va hien thi so chan dung truoc, so le dung sau\n");
        printf("14. Dao nguoc mang\n");
        printf("15. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &chon);

        switch (chon) {
            case 1:
                do {
                    printf("Nhap so phan tu trong mang (1-100): ");
                    scanf("%d", &n);
                    if (n < 1 || n > 100) {
                        printf("So phan tu phai trong khoang 1 den 100. Vui long nhap lai.\n");
                    }
                } while (n < 1 || n > 100);

                for (int i = 0; i < n; i++) {
                    printf("Nhap phan tu thu %d: ", i);
                    scanf("%d", &Mang[i]);
                }
                break;

            case 2:
                if (n == 0) {
                    printf("Mang chua co phan tu nao.\n");
                } else {
                    printf("Cac phan tu trong mang: ");
                    for (int i = 0; i < n; i++) {
                        printf("Mang[%d] = %d; ", i, Mang[i]);
                    }
                    printf("\n");
                }
                break;

            case 3: {
                int sohoanhao = 0;
                for (int i = 0; i < n; i++) {
                    int tong = 0;
                    for (int j = 1; j < Mang[i]; j++) {
                        if (Mang[i] % j == 0) {
                            tong += j;
                        }
                    }
                    if (tong == Mang[i]) {
                        sohoanhao++;
                    }
                }
                printf("So luong so hoan hao: %d\n", sohoanhao);
                break;
            }

            case 4: {
                int songuyento = 0;
                for (int i = 0; i < n; i++) {
                    int nguyento = 1;
                    if (Mang[i] < 2) nguyento = 0;
                    for (int j = 2; j * j <= Mang[i]; j++) {
                        if (Mang[i] % j == 0) {
                            nguyento = 0;
                            break;
                        }
                    }
                    if (nguyento) songuyento++;
                }
                printf("So luong so nguyen to: %d\n", songuyento);
                break;
            }

            case 5:
                if (n < 2) {
                    printf("Khong du phan tu de tim gia tri lon thu 2.\n");
                } else {
                    int max = Mang[0], secondMax = -1;
                    for (int i = 1; i < n; i++) {
                        if (Mang[i] > max) {
                            secondMax = max;
                            max = Mang[i];
                        } else if (Mang[i] > secondMax && Mang[i] != max) {
                            secondMax = Mang[i];
                        }
                    }
                    if (secondMax == -1) {
                        printf("Khong co gia tri lon thu 2 trong mang.\n");
                    } else {
                        printf("Gia tri lon thu 2: %d\n", secondMax);
                    }
                }
                break;

            case 6:
                if (n < 2) {
                    printf("Khong du phan tu de tim gia tri nho thu 2.\n");
                } else {
                    int min = Mang[0], secondMin = -1;
                    for (int i = 1; i < n; i++) {
                        if (Mang[i] < min) {
                            secondMin = min;
                            min = Mang[i];
                        } else if (Mang[i] < secondMin && Mang[i] != min) {
                            secondMin = Mang[i];
                        }
                    }
                    if (secondMin == -1) {
                        printf("Khong co gia tri nho thu 2 trong mang.\n");
                    } else {
                        printf("Gia tri nho thu 2: %d\n", secondMin);
                    }
                }
                break;

            case 7:
                if (n < 100) {
                    int them, vitrithem;
                    printf("Nhap gia tri can them: ");
                    scanf("%d", &them);
                    printf("Nhap vi tri can them (0-%d): ", n);
                    scanf("%d", &vitrithem);
                    if (vitrithem < 0 || vitrithem > n) {
                        printf("Vi tri khong hop le.\n");
                    } else {
                        for (int i = n; i > vitrithem; i--) {
                            Mang[i] = Mang[i - 1];
                        }
                        Mang[vitrithem] = them;
                        n++;
                    }
                } else {
                    printf("Khong the them, mang da day.\n");
                }
                break;

            case 8: {
                int vitrixoa;
                printf("Nhap vi tri can xoa (0-%d): ", n - 1);
                scanf("%d", &vitrixoa);
                if (vitrixoa < 0 || vitrixoa >= n) {
                    printf("Vi tri khong hop le.\n");
                } else {
                    for (int i = vitrixoa; i < n - 1; i++) {
                        Mang[i] = Mang[i + 1];
                    }
                    n--;
                }
                break;
            }

            case 9:
                for (int i = 1; i < n; i++) {
                    int key = Mang[i];
                    int j = i - 1;
                    while (j >= 0 && Mang[j] > key) {
                        Mang[j + 1] = Mang[j];
                        j--;
                    }
                    Mang[j + 1] = key;
                }
                printf("Mang sau khi sap xep tang dan.\n");
                break;

            case 10:
                for (int i = 1; i < n; i++) {
                    int key = Mang[i];
                    int j = i - 1;
                    while (j >= 0 && Mang[j] < key) {
                        Mang[j + 1] = Mang[j];
                        j--;
                    }
                    Mang[j + 1] = key;
                }
                printf("Mang sau khi sap xep giam dan.\n");
                break;

            case 11: {
                int tim, check = 0;
                printf("Nhap gia tri can tim: ");
                scanf("%d", &tim);
                for (int i = 0; i < n; i++) {
                    if (Mang[i] == tim) {
                        printf("Gia tri %d o vi tri %d\n", tim, i);
                        check = 1;
                    }
                }
                if (!check) printf("Khong tim thay gia tri trong mang.\n");
                break;
            }

            case 12: 
             break;
            case 13: 
             break;
            case 14: 
             break;
            case 15:
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
        }
    } while (chon != 15);

    return 0;
}









