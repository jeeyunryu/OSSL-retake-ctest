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

    printf("***우리 게스트하우스***\n");
    printf("1. 조회 2. 추가 3. 삭제 4. 저장 5. 예약자검색 0. 종료>> ");
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
            printf("\n**** 객실유형 *****\n\n");
            printf("1. 더블룸     1박 30,000원\n");
            printf("1. 트윈룸     1박 25,000원\n");
            printf("1. 패밀리룸   1박 60,000원\n\n");
            printf("*********\n\n");

            printf("유형별 개수는? ");
           
            r[cnt] = (Reserv*)malloc(sizeof(Reserv));
            if (addReservation(r[cnt])==1) printf("=> 예약됨! 총 금액: %d\n\n", r[cnt]->price);;
                   
            cnt++;
            idx++;
        }
        if(menu == 3){
            listReservation(r, cnt);
            
            printf("번호는? (취소:0)? ");
            int num, confirm;
            scanf("%d", &num);
            if(num == 0) continue;
            printf("정말로 삭제?(삭제:1) ");
            scanf("%d", &confirm);

            if(confirm != 1) continue;
            r[num-1]->canceled = 'Y';
        }
        if(menu == 4){}
        if (menu == 5){}
    
    }
    printf("종료됨!\n");
    
    return 0;

}

void listReservation(Reserv* r[], int cnt) {
    int idx = 0;
    printf("\nNo 예액방 예약자 등급 가격 요청사항\n");
    printf("=====================================\n");
    for(int i = 0; i < cnt; i++) {
        if(r[i]->canceled == 'Y') continue;
        idx++;
        printf("%d %d-%d-%d %s %c %d %s\n", idx, r[i]->count[0], r[i]->count[1], r[i]->count[2], r[i]->name, r[i]->rank, r[i]->price, r[i]->request);
        
    }
    printf("=> 총 예약 %d건\n", idx);
    return;
}

int addReservation(Reserv* r) {
    scanf("%d %d %d", &r->count[0], &r->count[1], &r->count[2]);
    printf("예약자는? ");
    scanf("%s", r->name);
    printf("예약자 등급은(B, S, G)? ");
    scanf(" %c", &r->rank);
    printf("요청사항은? ");
    scanf(" %[^\n]s", r->request);
    r->canceled = 'N';
    
    r->price = 30000 * r->count[0] + 25000 * r->count[1] + 60000 * r->count[2]; 
    return 1;

}
