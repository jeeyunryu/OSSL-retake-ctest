#include <stdio.h>
#include <stdlib.h>

typedef struct reserv {
    int count[3];
    char name[20];
    char rank;
    char request[20];
    int price;
    char canceled;
} Reserv;

int selectMenu() {
    int menu;

    printf("***�츮 �Խ�Ʈ�Ͽ콺***\n");
    printf("1. ��ȸ 2. �߰� 3. ���� 4. ���� 5. �����ڰ˻� 0. ����>> ");
    scanf("%d", &menu);
    return menu;

}

void listReservation(Reserv* r[], int cnt);

int addReservation(Reserv* r);

int main(){
    int menu;
    Reserv* r[30];
    int cnt = 0;
    int idx = 0;

    while(1) {
        menu = selectMenu();
        if(menu == 0) break;
        if(menu == 1 || menu == 3 || menu == 5) {
            if(idx == 0) continue;
        }
        if(menu == 1) {
            listReservation(r, cnt);

        }
        if(menu == 2) {
    
            //int sum = 0;
            printf("\n**** �������� *****\n\n");
            printf("1. �����     1�� 30,000��\n");
            printf("1. Ʈ����     1�� 25,000��\n");
            printf("1. �йи���   1�� 60,000��\n\n");
            printf("*********\n\n");

            printf("������ ������? ");
           
            r[cnt] = (Reserv*)malloc(sizeof(Reserv));
            if (addReservation(r[cnt])==1) printf("=> �����! �� �ݾ�: %d\n\n", r[cnt]->price);;
                   
            cnt++;
            idx++;
        }
        if(menu == 3){
            listReservation(r, cnt);
            
            printf("��ȣ��? (���:0)? ");
            int num, confirm;
            scanf("%d", &num);
            if(num == 0) continue;
            printf("������ ����?(����:1) ");
            scanf("%d", &confirm);

            if(confirm != 1) continue;
            r[num-1]->canceled = 'Y';
        }
        if(menu == 4){}
        if (menu == 5){}
    
    }
    printf("�����!\n");
    
    return 0;

}

void listReservation(Reserv* r[], int cnt) {
    int idx = 0;
    printf("\nNo ���׹� ������ ��� ���� ��û����\n");
    printf("=====================================\n");
    for(int i = 0; i < cnt; i++) {
        if(r[i]->canceled == 'Y') continue;
        idx++;
        printf("%d %d-%d-%d %s %c %d %s\n", idx, r[i]->count[0], r[i]->count[1], r[i]->count[2], r[i]->name, r[i]->rank, r[i]->price, r[i]->request);
        
    }
    printf("=> �� ���� %d��\n", idx);
    return;
}

int addReservation(Reserv* r) {
    scanf("%d %d %d", &r->count[0], &r->count[1], &r->count[2]);
    printf("�����ڴ�? ");
    scanf("%s", r->name);
    printf("������ �����(B, S, G)? ");
    scanf(" %c", &r->rank);
    printf("��û������? ");
    scanf(" %[^\n]s", r->request);
    r->canceled = 'N';
    
    r->price = 30000 * r->count[0] + 25000 * r->count[1] + 60000 * r->count[2]; 
    return 1;

}
