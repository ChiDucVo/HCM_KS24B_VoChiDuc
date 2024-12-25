#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
    int flag = 1, option, num_elements, count_even = 0, count_odd = 0;
    int array[100];
    while (flag == 1) {
       
        printf("1. Nhap so phan tu va gia tri cho mang \n");
        printf("2. In ra gia tri cac phan tu trong mang theo dang(array[0]=1, array[1]=5...) \n");
        printf("3. Dem so luong cac phan tu chan le trong mang \n");
        printf("4. Tim gia tri lon thu hai trong mang \n");
        printf("5. Them mot phan tu vao dau mang \n");
        printf("6. Xoa phan tu tai mot vi tri cu the \n");
        printf("7. Sap xep mang theo thu tu giam dan \n");
        printf("8. Nhap vao mot phan tu va tim kiem \n");
        printf("9. In ra toan bo so nguyen to trong mang da duoc binh phuong \n");
        printf("10. Sap xep mang theo thu tu giam dan \n");
        printf("\n Vui long nhap lua chon: ");
        scanf("%d", &option);
        
        switch (option) {
            
            case 1:
                printf("Vui long nhap so luong phan tu: ");
                scanf("%d", &num_elements);
                while (num_elements <= 0) {
                    printf("Vui long nhap so luong phan tu > 0: ");
                    scanf("%d", &num_elements);
                }
                for (int index = 0; index < num_elements; index++) {
                    printf("Nhap gia tri cho phan tu thu %d: ", index + 1);
                    scanf("%d", &array[index]);
                }
                break;
            
            case 2:
                for (int index = 0; index < num_elements; index++) {
                    printf("array[%d] = %d, ", index, array[index]);
                }
                printf("\n");
                break;
            
            case 3:
                for (int index = 0; index < num_elements; index++) {
                    if (array[index] % 2 == 0) {
                        count_even++;
                    } else {
                        count_odd++;
                    }
                }
                printf("So luong so chan: %d\n", count_even);
                printf("So luong so le: %d\n", count_odd);
                break;
            
            case 4: {
                int max = array[0], second_max = -1;
                if (num_elements < 2) {
                    printf("Khong co gia tri lon thu hai\n");
                } else 
                    for (int index = 1; index < num_elements; index++) {
                        if (array[index] > max) {
                            second_max = max;
                            max = array[index];
                        } else if (array[index] > second_max && array[index] < max) {
                            second_max = array[index];
                        }
                    }
                    if (second_max == -1) {
                        printf("Khong co gia tri lon thu hai\n");
                    } else {
                        printf("Gia tri lon thu hai: %d\n", second_max);
                    }
                }
                break;
            }
            case 5: {
                int new_element;
                printf("Nhap phan tu moi: ");
                scanf("%d", &new_element);
                for (int index = num_elements; index > 0; index--) {
                    array[index] = array[index - 1];
                }
                array[0] = new_element;
                num_elements++;
               break;

            }
            case 6: {
                int position;
                printf("Nhap vi tri muon xoa: ");
                scanf("%d", &position);
                if (position < 0 || position >= num_elements) {
                    printf("Vi tri khong hop le \n");
                } else {
                    for (int index = position; index < num_elements - 1; index++) {
                        array[index] = array[index + 1];
                    }
                    num_elements--;
                }
                break;
            }
            case 7: {
                for (int index = 1; index < num_elements; index++) {
                    int key = array[index];
                    int j = index - 1;
                    while (j >= 0 && array[j] < key) {
                        array[j + 1] = array[j];
                        j--;
                    }
                    array[j + 1] = key;
                }
                printf("Mang sau khi sap xep theo thu tu giam dan: ");
                for (int index = 0; index < num_elements; index++) {
                    printf("%d ", array[index]);
                }
                printf("\n");
                break;
            }
            case 8: {
                int target;
                printf("Nhap phan tu can tim: ");
                scanf("%d", &target);
                int left = 0, right = num_elements - 1;
                int found = 0;
                while (left <= right) {
                    int mid = (left + right) / 2;
                    if (array[mid] == target) {
                        printf("Phan tu %d ton tai trong mang tai vi tri %d\n", target, mid);
                        found = 1;
                        break;
                    } else if (array[mid] < target) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
                if (!found) {
                    printf("Phan tu %d khong ton tai trong mang\n", target);
                }
                break;
            }
            case 9: {
                int prime_found = 0;
                printf("Cac so nguyen to trong mang sau khi binh phuong: ");
                for (int index = 0; index < num_elements; index++) {
                    int is_prime = 1;
                    if (array[index] < 2) {
                        is_prime = 0;
                    } else {
                        for (int j = 2; j <= sqrt(array[index]); j++) {
                            if (array[index] % j == 0) {
                                is_prime = 0;
                                break;
                            }
                        }
                    }
                    if (is_prime) {
                        prime_found = 1;
                        printf("%d ", array[index] * array[index]);
                    }
                }
                if (!prime_found) {
                    printf("Khong co so nguyen to nao trong mang\n");
                }
                printf("\n");
                break;
            }
            case 10: {
                for (int index = 0; index < num_elements - 1; index++) {
                    for (int j = index + 1; j < num_elements; j++) {
                        if (array[index] < array[j]) {
                            int temp = array[index];
                            array[index] = array[j];
                            array[j] = temp;
                        }
                    }
                }
                printf("Mang sau khi sap xep theo thu tu giam dan: ");
                for (int index = 0; index < num_elements; index++) {
                    printf("%d ", array[index]);
                }
                printf("\n");
                break;
            }
            case 0:
                printf("Thoat chuong trinh...\n");
                return 0;
        
            default:
                printf("Lua chon khong hop le.\n");
                break;
        }
    }
    return 0;
}
