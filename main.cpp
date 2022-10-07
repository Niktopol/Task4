#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <limits>
#include <regex>

bool safe_inp(double* arr[], int len, double err) {
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
bool safe_inp(double* x, double err) {
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
bool safe_inp(int* arr[], int len, int err) {
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
bool safe_inp(int* x, int err = -1) {
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
        safe_inp(&n, 0);
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
    if (!safe_inp(&n, -1)) {
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
    double* ab[] = { &a,&b };
    std::wcout << L"Введите длину и ширину" << std::endl;
    if (!safe_inp(ab, 2, -1)) {
        std::wcout << L"Неверный ввод" << std::endl;
        return;
    }
    std::wcout << L"S = " << a * b << std::endl;
}
void tri() {

    while (true) {
        std::wcout << L"Формулу площади:\n1.По трём сторонам\n2.По двум сторонам и углу между ними\n3.По стороне и высоте к ней\n4.По стороне и двум прилежащим углам" << std::endl;
        int n;
        if (!(std::wcin >> n)) {
            std::wcin.clear();
            std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::wcout << L"Неверный ввод" << std::endl;
            continue;
        }
        else {
            if (n == 1) {
                double a, b, c;
                double* abc[] = { &a,&b,&c };
                std::wcout << L"Введите длины сторон" << std::endl;
                if (!safe_inp(abc, 3, -1) or a <= 0 or b <= 0 or c <= 0) {
                    std::wcout << L"Неверный ввод" << std::endl;
                    return;
                }
                if ((a + b > c) and (a + c > b) and (b + c > a)) {
                    double p = (a + b + c) / 2;
                    std::wcout << L"S = " << std::sqrt((p * (p - a) * (p - b) * (p - c))) << std::endl;
                }
                else {
                    std::wcout << L"Неверный ввод" << std::endl;
                }
                break;
            }
            else if (n == 2) {
                double a, b, c;
                double* abc[] = { &a,&b,&c };
                std::wcout << L"Введите длины сторон и угол в градусах" << std::endl;
                if (!safe_inp(abc, 3, -1) or a <= 0 or b <= 0 or c <= 0 or c >= 180) {
                    std::wcout << L"Неверный ввод" << std::endl;
                    return;
                }
                c = (c * 3.14) / 180;
                std::wcout << L"S = " << 0.5*a*b*sin(c) << std::endl;
                break;
            }
            else if (n == 3) {
                double a, b;
                double* abc[] = { &a,&b};
                std::wcout << L"Введите длины сторон и угол в градусах" << std::endl;
                if (!safe_inp(abc, 3, -1) or a <= 0 or b <= 0) {
                    std::wcout << L"Неверный ввод" << std::endl;
                    return;
                }
                std::wcout << L"S = " << 0.5 * a * b << std::endl;
                break;
            }
            else if (n == 4) {
                double a, b, c;
                double* abc[] = { &a,&b,&c };
                std::wcout << L"Введите длину стороны величины углов в градусах" << std::endl;
                if (!safe_inp(abc, 3, -1) or a <= 0 or b >= 180 or c <= 0 or c >= 180) {
                    std::wcout << L"Неверный ввод" << std::endl;
                    return;
                }
                b = (b * 3.14) / 180;
                c = (c * 3.14) / 180;
                std::wcout << L"S = " << a*a*sin(b)*sin(c)/(2*sin(b+c)) << std::endl;
                break;
            }
            else {
                std::wcout << L"Неверный ввод" << std::endl;
                continue;
            }
        }
    }
}
void okr() {
    const double PI = 3.14;
    double r;
    std::wcout << L"Введите радиус" << std::endl;
    if (!safe_inp(&r, -1) or r <= 0) {
        std::wcout << L"Неверный ввод" << std::endl;
        return;
    }
    else {
        std::wcout << L"S = " << PI * r * r << std::endl;
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
    for (int i = 0; i < 13; i++) {
        if (i > 0 and i < 7) {
            if (i % 2 == 0) {
                std::wcout << L"********████████████████████████████████████████" << std::endl;
            }
            else {
                std::wcout << L"********░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░" << std::endl;
            }
        }
        else {
            if (i % 2 == 0) {
                std::wcout << L"████████████████████████████████████████████████" << std::endl;
            }
            else {
                std::wcout << L"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░" << std::endl;
            }
        }
    }
}
void sinus(double step) {
    wchar_t cords[20 + 1][100];
    float num = 0;
    for (int i = 0; i < 100; i++) {
        int sn = round(20 / 2) - std::round(sin(num) * 10);
        cords[sn][i] = '*';
        num += step;
    }
    for (int i = 0; i < 20 + 1; i++) {
        for (int j = 0; j < 100; j++) {
            if (cords[i][j] == '*') {
                std::wcout << cords[i][j];
            }
            else {
                if (j == 0) {
                    if (i == 0) {
                        std::wcout << L'^';
                    }
                    else {
                        std::wcout << L'|';
                    }
                }
                else if (i == 10) {
                    if (j == 100 - 1) {
                        std::wcout << L'>';
                    }
                    else {
                        std::wcout << L'-';
                    }
                }
                else {
                    std::wcout << L' ';
                }
            }
        }
        std::wcout << std::endl;
    }
}
void rimHelp(int* sum, int* pool, int num, int* prev) {
    if (*prev == 0) {
        *prev = num;
    }
    if (*prev < num) {
        *sum = *sum - *pool + num - *pool;
        *pool = 0;
    }
    else if (*prev == num) {
        *sum += num;
        *pool += num;
    }
    else {
        *pool = 0;
        *sum += num;
        *pool += num;
    }
    *prev = num;
}
void rim(std::wstring s) {
    static const std::wregex r(LR"((.*[^I^V^X^L^C^D^M].*)||(.*[IXCM]{4}.*)||(.*[VLD]{2}.*))");
    if (std::regex_match(s,  r)){
        std::wcout << L"Неверный ввод" << std::endl;
        return;
    }
    int pool = 0;
    int sum = 0;
    int prev = 0;
    for (wchar_t a : s) {
        switch (a) {
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
    std::wcout << sum << std::endl;
}
int myrand(int m, int b, int c, int i) {
    if (i == 0) {
        return b%c;
    }
    return (m * myrand(m, b, c, i - 1) + b)%c;
}
double multix(double a[], double b[], int len) {
    double sum = 0;
    for (int i = 0; i < len; i++) {
        sum += a[i]*b[i];
    }
    return sum;
}
int fnd(double arr[], bool t){
    int a = 0;
    double pool = arr[0];
    if(t){;
        for (int i = 0; i < 3; i++) {
            if (arr[i] < pool){
                a = i;
            }
        }
    }
    else{
        for (int i = 0; i < 3; i++) {
            if (arr[i] > pool){
                a = i;
            }
        }
    }
    return a+1;
}
void matrix() {
    double tovar[3][4] = {
            {5,2,0,10},
            {3,5,2,5},
            {20,0,0,0}
    };
    double price[2][4] = {{1.2,2.8,5,2},{0.5,0.4,1,1.5}};

    double res[3][2] = { { 0,0 }, { 0,0 }, { 0,0 }};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            res[i][j] = multix(tovar[i],price[j],4);
        }
    }
    double msum[3], mkom[3], sum, kom;
    for (int i = 0; i < 3; i++) {
        msum[i] = res[i][0];
        sum += res[i][0];
        mkom[i] = res[i][1];
        kom += res[i][1];
    }
    std::wcout << fnd(msum, false) << " " << fnd(msum, true) << std::endl;
    std::wcout << fnd(mkom, false) << " " << fnd(mkom, true) << std::endl;
    std::wcout << sum << std::endl;
    std::wcout << kom << std::endl;
    std::wcout << sum-kom << std::endl;
}
int main() {
    setlocale(0, "");

    tocifr();
    znak();
    geometry();
    murica();
    sinus(3.14 / 16);
    std::wstring s;
    std::wcin >> s;
    rim(s);
    std::wcout << myrand(37, 3, 64, 8) << std::endl;
    std::wcout << myrand(25137, 13849, 65537, 8) << std::endl;
    matrix();
    return 0;
}
