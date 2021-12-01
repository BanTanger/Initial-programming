//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<cstring>
//#include<cstdio>
//#include<algorithm>
//#define ll long long
//using namespace std;
//
//const int HorseMoveX[] = { 0, -2, -1, 1, 2, 2, 1, -1, -2 };
//const int HorseMoveY[] = { 0, 1, 2, 2, 1, -1, -2, -2, -1 };
////马可以走到的位置
////0，0是🐎本身坐标。
//
//int PawnX, PawnY, HorseX, HorseY;
//ll PawnMove[2][40];
//bool s[40][40]; 
//int main() {
//    scanf("%d%d%d%d", &PawnX, &PawnY, &HorseX, &HorseY);
//    PawnX += 2; PawnY += 2; HorseX += 2; HorseY += 2;
//    //坐标+2以防越界
//    PawnMove[2][1] = 1;//初始化
//    s[HorseX][HorseY] = 1;//标记马的位置
//    for (int i = 1; i <= 8; i++) 
//        s[HorseX + HorseMoveX[i]][HorseY + HorseMoveY[i]] = 1;//标记被马拦住的点为1
//    for (int i = 2; i <= PawnX; i++) {
//        for (int j = 2; j <= PawnY; j++) {
//            if (s[i][j]) {
//                PawnMove[i & 1][j] = 0;
//                continue; // 如果被马拦住就直接跳过
//            }
//            PawnMove[i & 1][j] = PawnMove[(i - 1) & 1][j] + PawnMove[i & 1][j - 1];
//            //状态转移方程
//        }
//    }
//    printf("%lld\n", PawnMove[PawnX & 1][PawnY]);
//    return 0;
//}
//
////
////const int HorseMoveX[] = { 0, -2, -1, 1, 2, 2, 1, -1, -2 };
////const int HorseMoveY[] = { 0, 1, 2, 2, 1, -1, -2, -2, -1 };
//////马可以走到的位置
//////0，0是🐎本身坐标。
////
////int PawnX, PawnY, HorseX, HorseY;
////ll PawnMove[40][40];
////bool s[40][40];
////int main() {
////    scanf("%d%d%d%d", &PawnX, &PawnY, &HorseX, &HorseY);
////    PawnX += 2; PawnY += 2; HorseX += 2; HorseY += 2;
////    //坐标+2以防越界
////    PawnMove[2][1] = 1;//初始化
////    s[HorseX][HorseY] = 1;//标记马的位置
////    for (int i = 1; i <= 8; i++)
////        s[HorseX + HorseMoveX[i]][HorseY + HorseMoveY[i]] = 1;//标记被马拦住的点为1
////    for (int i = 2; i <= PawnX; i++) {
////        for (int j = 2; j <= PawnY; j++) {
////            if (s[i][j]) continue; // 如果被马拦住就直接跳过
////            PawnMove[i][j] = PawnMove[i - 1][j] + PawnMove[i][j - 1];
////            //状态转移方程
////        }
////    }
////    printf("%lld\n", PawnMove[PawnX][PawnY]);
////    return 0;
////}