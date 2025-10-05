#include<iostream>
using namespace std;

//C/C++:
// -------------------- ������� --------------------
/*
    ����:
        board[i][j]��ʾ����(i,j)��ֵ
        0��ʾ�յ�
        1��ʾ����
        2��ʾ����
    ��: board[3][6] = 1  ��ʾ(3,6)��λ���Ǻ���
*/
int board[20][20];

// ��ʾ��ǰ�غ���  ż����ʾ��������  ������ʾ��������
// ��: flag = 20 ��ʾ��ǰ�ǵ�[20]������  �ɺڷ�����
int flag;


// -------------------- ������� --------------------


// -------------------- service --------------------
/*
    ������: ����
    ����: init: ��ʼ����Ϸ����
        �����̵�ֵ��ʼ��Ϊ0
        ��ǰ�غ���Ϊ����(flag��Ϊ0)
    ����: void
    ����ֵ: void
*/
void init();
/*
    *�ѵ�1
    ������: ����
    ����: isWin: ���ݴ��������(board��Ӧλ��)��flagֵ �ж������Ƿ��ʤ
    ����:
        x: ��ǰ�غ����ӵ�x����
        y: ��ǰ�غ����ӵ�y����
    ����ֵ:
        0��ʾû�л�ʤ
        1��ʾ����ʤ��
        2��ʾ����ʤ��
*/
int isWin(int x, int y);
/*
    ������: ����
    ����: playerMove: ��ָ��λ������
        ���board[x][y]�ǿյ� ���޸�board[x][y]��ֵ:��Ϊ��Ӧ��ɫ(flag��Ӧ��ɫ)        ���򲻲���
    ����:
        x: ��ǰ�غ����ӵ�x����
        y: ��ǰ�غ����ӵ�y����
    ����ֵ:
        0��ʾ����ʧ�� (�����Ѿ�����)
        1��ʾ���ӳɹ�

*/
int playerMove(int x, int y);
// -------------------- service --------------------



// -------------------- view --------------------
/*
    ������: ����
    ����: menuView: չʾѡ��, ��ҿ���������ѡ�������Ϸ, �������û��˳���Ϸ
        while(1){
            1. չʾѡ��
            2. �û�����
            3. ����������ж�Ӧ����
                ������Ϸ: ������Ϸ���溯��gameView();
                ��������: ��ӡ�����ڴ�... ����ѭ��
                �˳���Ϸ: ����exit(0);
        }
    ����: void
    ����ֵ: void
*/
void menuView();
/*
    ������: ����
    ����: gameView_ShowBoard: ����board���� ��ӡ��Ϸ����
    ����: void
    ����ֵ: void
*/
void gameView_ShowBoard();
/*
    ������: ����
    ����: winView:
        ����flag��ֵ  ��ӡ��Ϸʤ������  �û����԰������(ʹ��getch����)�˳���ǰ����
    ����: void
    ����ֵ: void
*/
void winView();
/*
    *�ѵ�2
    ������: ����
    ����: gameView: ��Ϸ��������
        ��ʼ����Ϸ����(���ú���init())
        while(1){
            ��ӡ��Ϸ����(���ú���gameView_ShowBoard())
            ���������������

            ����(�������Ӻ���playerMove())
                (�������ʧ�� ���¿�ʼѭ��)

            �ж���Ϸ�Ƿ�ʤ��(����ʤ���жϺ���isWin())
                (�����Ϸʤ�� ����ʤ�����溯�� Ȼ�������ǰ����)
            �л����(�޸�flagֵ)
        }
    ����: void
    ����ֵ: void
*/
void gameView();




// -------------------- view --------------------

int main()
{
    menuView();
    return 0;
}


void init() {
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            board[i][j] = 0;
        }
    }
    flag = 0;
    cout << "��Ϸ�ѳ�ʼ��" << endl;

}

int isWin(int x, int y) {
    int color = board[x][y];
    
    int dir[4][2] = {
        {0,1},
        {1,0},
        {1,1},
        {-1,1}
    };
    for (int d = 0; d < 4; d++) {
        int count = 1;
        int dx = x + dir[d][0], dy = y + dir[d][1];
        while (board[dx][dy] == color) {
            count++;
            dx += dir[d][0];
            dy += dir[d][1];
        }
        dx = x - dir[d][0], dy = y - dir[d][1];
        while (board[dx][dy] == color) {
            count++;
            dx -= dir[d][0];
            dy -= dir[d][1];        
        }
        if (count == 5) return color;
    }
    return 0;
}

int playerMove(int x, int y) {
    if (x < 1 || y < 1 || x > 19 || y > 19) {
        cout << "���ӳ������̣�" << endl;
        return 0;
    }
    else if (board[x][y] != 0) {
        cout << "��λ���������ӣ�" << endl;
        return 0;
    }

    if (flag % 2 == 0) {
        board[x][y] = 1;  // ����
        cout << "����������(" << x << "," << y << ")" << endl;
    }
    else {
        board[x][y] = 2;  // ����
        cout << "����������(" << x << "," << y << ")" << endl;
    }
    return 1;
}


void menuView() {
    cout << "��������Ϸ��ʼ��" << endl;
    cout << "1.��ʼ��Ϸ" << endl;
    cout << "2.����" << endl;
    cout << "3.�˳���Ϸ" << endl;
    cout << "��ѡ��" << endl;

    int choice;
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "��ʼ��Ϸ!" << endl;
        gameView();
            break;
    case 2:
        cout << "�����ڴ�..." << endl;
        break;
    case 3:
        cout << "�˳���Ϸ" << endl;
        exit(0);
        break;


    }



}

void gameView_ShowBoard() {
    cout << "  ";
    for (int i = 1; i < 20; i++) {
        printf(" %2d", i);
    }
    cout << endl;
    for (int j = 19; j > 0; j--) {
        printf("%3d", j);
        for (int i = 1; i < 20; i++) {
            if (board[i][j] == 0) {
                cout << "�� ";
            }
            else if (board[i][j] == 1) {
                cout << "�� ";
            }
            else
            {
                cout << "�� ";
            }
        }
        cout << endl;

    }
    cout << "  ";
    for (int i = 1; i < 20; i++) {
        printf(" %2d", i);
    }
    cout << endl;
}

void winView() {
    if (flag % 2 == 0) {
        cout << "�ڷ�ʤ����" << endl;
    }
    else
    {
        cout << "�׷�ʤ����" << endl;
    }
    cout << "��������������˵�...";
    cin.ignore();
    cin.get();
}

void gameView() {
    //�ڴ˴���ɴ���
    init();
    while (true) {
        gameView_ShowBoard();
        if (flag % 2 == 0) {
            cout << "\n��ǰ�غ�: ��������" << endl;
        }
        else
        {
            cout << "\n��ǰ�غ�: ��������" << endl;
        }
        int x, y;
        cout << "��������������" << endl;
        
        if (!(cin >> x >> y)) {
            cout << "�����������������������" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        while (!playerMove(x,y)) {
            cout << "������Ч�����������룺" << endl;
            cin >> x >> y;
        }

        if (isWin(x, y)) {
            gameView_ShowBoard();
            winView();
            return;        
        }
        flag++;


    }
}