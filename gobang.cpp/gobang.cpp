#include<iostream>
using namespace std;

//C/C++:
// -------------------- 数据设计 --------------------
/*
    棋盘:
        board[i][j]表示坐标(i,j)的值
        0表示空地
        1表示黑子
        2表示白子
    如: board[3][6] = 1  表示(3,6)的位置是黑子
*/
int board[20][20];

// 表示当前回合数  偶数表示黑棋落子  奇数表示白棋落子
// 如: flag = 20 表示当前是第[20]次落子  由黑方落子
int flag;


// -------------------- 数据设计 --------------------


// -------------------- service --------------------
/*
    负责人: 张三
    功能: init: 初始化游戏数据
        将棋盘的值初始化为0
        当前回合设为黑棋(flag设为0)
    参数: void
    返回值: void
*/
void init();
/*
    *难点1
    负责人: 张三
    功能: isWin: 根据传入的坐标(board对应位置)和flag值 判断落点后是否获胜
    参数:
        x: 当前回合落子的x坐标
        y: 当前回合落子的y坐标
    返回值:
        0表示没有获胜
        1表示黑子胜利
        2表示白子胜利
*/
int isWin(int x, int y);
/*
    负责人: 张三
    功能: playerMove: 在指定位置落子
        如果board[x][y]是空地 则修改board[x][y]的值:改为相应颜色(flag对应颜色)        否则不操作
    参数:
        x: 当前回合落子的x坐标
        y: 当前回合落子的y坐标
    返回值:
        0表示落子失败 (棋盘已经有子)
        1表示落子成功

*/
int playerMove(int x, int y);
// -------------------- service --------------------



// -------------------- view --------------------
/*
    负责人: 张三
    功能: menuView: 展示选项, 玩家可以在这里选择进入游戏, 进入设置或退出游戏
        while(1){
            1. 展示选项
            2. 用户输入
            3. 根据输入进行对应处理
                进入游戏: 调用游戏界面函数gameView();
                进入设置: 打印敬请期待... 重新循环
                退出游戏: 调用exit(0);
        }
    参数: void
    返回值: void
*/
void menuView();
/*
    负责人: 张三
    功能: gameView_ShowBoard: 根据board数组 打印游戏棋盘
    参数: void
    返回值: void
*/
void gameView_ShowBoard();
/*
    负责人: 张三
    功能: winView:
        根据flag的值  打印游戏胜利界面  用户可以按任意键(使用getch函数)退出当前界面
    参数: void
    返回值: void
*/
void winView();
/*
    *难点2
    负责人: 张三
    功能: gameView: 游戏界面整合
        初始化游戏数据(调用函数init())
        while(1){
            打印游戏界面(调用函数gameView_ShowBoard())
            接收玩家坐标输入

            落子(调用落子函数playerMove())
                (如果落子失败 重新开始循环)

            判断游戏是否胜利(调用胜利判断函数isWin())
                (如果游戏胜利 调用胜利界面函数 然后结束当前界面)
            切换玩家(修改flag值)
        }
    参数: void
    返回值: void
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
    cout << "游戏已初始化" << endl;

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
        cout << "棋子超出棋盘！" << endl;
        return 0;
    }
    else if (board[x][y] != 0) {
        cout << "该位置已有棋子！" << endl;
        return 0;
    }

    if (flag % 2 == 0) {
        board[x][y] = 1;  // 黑棋
        cout << "黑棋落子于(" << x << "," << y << ")" << endl;
    }
    else {
        board[x][y] = 2;  // 白棋
        cout << "白棋落子于(" << x << "," << y << ")" << endl;
    }
    return 1;
}


void menuView() {
    cout << "五子棋游戏开始！" << endl;
    cout << "1.开始游戏" << endl;
    cout << "2.设置" << endl;
    cout << "3.退出游戏" << endl;
    cout << "请选择：" << endl;

    int choice;
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "开始游戏!" << endl;
        gameView();
            break;
    case 2:
        cout << "敬请期待..." << endl;
        break;
    case 3:
        cout << "退出游戏" << endl;
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
                cout << "· ";
            }
            else if (board[i][j] == 1) {
                cout << "● ";
            }
            else
            {
                cout << "○ ";
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
        cout << "黑方胜利！" << endl;
    }
    else
    {
        cout << "白方胜利！" << endl;
    }
    cout << "按任意键返回主菜单...";
    cin.ignore();
    cin.get();
}

void gameView() {
    //在此处完成代码
    init();
    while (true) {
        gameView_ShowBoard();
        if (flag % 2 == 0) {
            cout << "\n当前回合: 黑棋落子" << endl;
        }
        else
        {
            cout << "\n当前回合: 白棋落子" << endl;
        }
        int x, y;
        cout << "请输入棋子坐标" << endl;
        
        if (!(cin >> x >> y)) {
            cout << "输入错误，请输入两个整数！" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        while (!playerMove(x,y)) {
            cout << "坐标无效，请重新输入：" << endl;
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