/**
 * 歌手类
*/
#ifndef SINGER_H
#define SINGER_H
#include <iostream>
#include <string>

using namespace std;

class Singer
{
    public:
        Singer();
        Singer(int singerNumber, string singerName, double *singerGrade);
        ~Singer();
        void sortGrade();
        int getNumber();
        string getName();
        double getGrade(int);
        double getArg();
        double getSum();

    private:
        int singerNumber = 0; //歌手编号
        string singerName; //stl里面的string存储姓名
        bool ifSorted = false; // 判断是否已经排序
        double *singerGrade; //用简单的数组存储成绩
        double arg = 0; // 平均数储存(掐头去尾)
        double sum = 0; // 成绩总和
        void caculateArg();
        int sort(int lo, int hi); // 次排序
};

Singer::Singer(){
    singerNumber = 0;
}

//构造函数
Singer::Singer(int singerNumber, string singerName, double *singerGrade){
    this->singerNumber = singerNumber;
    this->singerName = singerName;
    this->singerGrade = singerGrade;
}

//析构函数
Singer::~Singer(){
    // delete singerGrade; // 防止内存泄漏
}

int Singer::getNumber(){ // getter方法
    return singerNumber;
}

string Singer::getName(){ // getter方法
    return singerName;
}

double Singer::getGrade(int i){ // getter方法
    return singerGrade[i];
}

double Singer::getArg(){ // getter方法
    return arg;
}

void Singer::caculateArg(){
    int i = 0;
    if(ifSorted){
        for(i = 1;i < 9;i++){
            sum += singerGrade[i];
        }
        arg = sum/8;
    }else{
        sortGrade();
        caculateArg();
    }

}

int Singer::sort(int lo, int hi){
    int last = lo;
    double temp;

    while(++lo <= hi){
        if(singerGrade[lo - 1] > singerGrade[lo]){
            last = lo;

            temp = singerGrade[lo - 1];
            singerGrade[lo - 1] = singerGrade[lo];
            singerGrade[lo] = temp;
        }
    }

    return last;
}

// 成绩内排序 从小到大(小数据所以用了冒泡)
void Singer::sortGrade(){
    int lo = 0, hi = 9;
    while(lo < (hi = sort(lo, hi))); // 排序本体

    ifSorted = true;
}

#endif // SINGER_H