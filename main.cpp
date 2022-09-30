#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <limits>
bool safe_inp(double *arr[], int len, double err){
    double n;
    bool rs = true;
    for (int i = 0; i < len; i++) {
        if (!(std::wcin >> n)) {
            std::wcin.clear();
            std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            *arr[i] = err;
            rs = false;
        }
        else {
            *arr[i] = n;
        }
    }
    return rs;
}
bool safe_inp(double *x, double err){
    double n;
    if (!(std::wcin >> n)) {
        std::wcin.clear();
        std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        *x = err;
        return false;
    }
    else {
        *x = n;
        return true;
    }
}
bool safe_inp(int *arr[], int len, int err){
    int n;
    bool rs = true;
    for (int i = 0; i < len; i++) {
        if (!(std::wcin >> n)) {
            std::wcin.clear();
            std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            *arr[i] = err;
            rs = false;
        }
        else {
            *arr[i] = n;
        }
    }
    return rs;
}
bool safe_inp(int *x, int err = -1){
    int n;
    if (!(std::wcin >> n)) {
        std::wcin.clear();
        std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        *x = err;
        return false;
    }
    else {
       *x = n;
        return true;
    }
}
void tocifr() {
    std::wifstream in;
    std::wofstream out;
    out.open("cifri.txt");
    double n;
    for (int i = 0; i < 10; i++) {
        safe_inp(&n,0);
        out << n << std::endl;
    }
    out.close();
    in.open("cifri.txt");
    double sum = 0;
    double t = 0;
    if (!in.is_open()) {
        std::wcout << L"Файла test.txt не существует" << std::endl;
    }
    else {
        for (int i = 0; i < 10; i++) {
            in >> t;
            sum += t;
        }
    }
    in.close();
    std::wcout << sum << std::endl;
}
void znak() {
    double n;
    if (!safe_inp(&n,-1)){
        std::wcout << L"Неверный ввод" << std::endl;
        return;
    }
    if (n > 0) {
        std::wcout << 1 << std::endl;
    }
    else if (n == 0) {
        std::wcout << 0 << std::endl;
    }
    else {
        std::wcout << -1 << std::endl;
    }
}
void rect() {
    double a, b;
    double *ab[] = {&a,&b};
    if (!safe_inp(ab,2,-1)) {
        std::wcout << L"Неверный ввод" << std::endl;
        return;
    }
    std::wcout << L"S = "<< a*b << std::endl;
}
void tri() {
    double a, b, c;
    double *abc[] = {&a,&b,&c};
    if (!safe_inp(abc,3,-1) or a <= 0 or b <= 0 or c <= 0) {
        std::wcout << L"Неверный ввод" << std::endl;
        return;
    }
    if ((a + b > c) and (a + c > b) and (b + c > a)) {
        double p = (a + b + c) / 2;
        std::wcout << L"S = " << std::sqrt((p*(p-a)*(p-b)*(p-c))) << std::endl;
    }
    else {
        std::wcout << L"Неверный ввод" << std::endl;
    }
}
void okr() {
    const double PI = 3.14;
    double r;
    if (!safe_inp(&r,-1) or r <= 0) {
        std::wcout << L"Неверный ввод" << std::endl;
        return;
    }
    else {
        std::wcout << L"S = " << PI*r*r << std::endl;
    }
}
void geometry() {
    while (true) {
        std::wcout << L"Выберите функцию:\n1.Площадь прямоугольника\n2.Площадь треугольника\n3.Площадь круга" << std::endl;
        int n;
        if (!(std::wcin >> n)) {
            std::wcin.clear();
            std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::wcout << L"Неверный ввод" << std::endl;
            continue;
        }
        else {
            if (n == 1) {
            rect();
            break;
        }
        else if (n == 2) {
            tri();
            break;
        }
        else if (n == 3) {
            okr();
            break;
        }
        else {
            std::wcout << L"Неверный ввод" << std::endl;
            continue;
            }
        }
    }
}
void murica() {
    for (int i = 0;i<13;i++){
        if (i>0 and i<7){
            if (i%2==0){
                std::wcout << L"********████████████████████████████████████████" << std::endl;
            }
            else{
                std::wcout << L"********░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░" << std::endl;
            }
        }else{
            if (i%2==0){
                std::wcout << L"████████████████████████████████████████████████" << std::endl;
            }
            else{
                std::wcout << L"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░" << std::endl;
            }
        }
    }
}
void sinus(int leng, double step){
    wchar_t cords[20+1][leng];
    float num = 0;
    for (int i = 0; i<leng; i++){
        int sn = round(20/2) - std::round(sin(num)*10);
        cords[sn][i] = '*';
        num += step;
    }
    for (int i = 0; i<20+1; i++){
        for (int j = 0; j<leng; j++){
            if (cords[i][j] == '*'){
                std::wcout << cords[i][j];
            }
            else{
                if (j == 0){
                    if (i == 0){
                        std::wcout << '^';
                    }
                    else {
                        std::wcout << '|';
                    }
                }
                else if (i == 10){
                    if (j == leng-1){
                        std::wcout << '>';
                    }
                    else{
                        std::wcout << '-';
                    }
                }
                else{
                    std::wcout << ' ';
                }
            }
        }
        std::wcout << std::endl;
    }
}
void rimHelp(int *sum, int *pool, int num, int *prev){
    if (*prev == 0){
        *prev = num;
    }
    if (*prev < num){
        *sum = *sum - *pool + num - *pool;
        *pool = 0;
    }
    else if (*prev == num){
        *sum += num;
        *pool += num;
    }
    else{
        *pool = 0;
        *sum += num;
        *pool += num;
    }
    *prev = num;
}
void rim(std::wstring s) {
    int pool = 0;
    int sum = 0;
    int prev = 0;
    for (wchar_t a : s){
        switch (a){
            case 'I':
                rimHelp(&sum, &pool, 1, &prev);
                break;
            case 'V':
                rimHelp(&sum, &pool, 5, &prev);
                break;
            case 'X':
                rimHelp(&sum, &pool, 10, &prev);
                break;
            case 'L':
                rimHelp(&sum, &pool, 50, &prev);
                break;
            case 'C':
                rimHelp(&sum, &pool, 100, &prev);
                break;
            case 'D':
                rimHelp(&sum, &pool, 500, &prev);
                break;
            case 'M':
                rimHelp(&sum, &pool, 1000, &prev);
                break;
            default:
                break;
        }
    }
    std::wcout << sum;
}
int main() {
    setlocale(LC_ALL, "");
    tocifr();
    znak();
    geometry();
    murica();
    sinus(100,3.14/16);
    std::wstring s;
    std::wcin >> s;
    rim(s);

    return 0;
}
