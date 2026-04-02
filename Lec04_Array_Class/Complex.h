#pragma once
#include <cstdio>

class Complex
{
    double real;
    double imag;  

public:
    void set(double r, double i) {
        real = r; //a.read줄이되면 이함수가실행이되느거고 이하뭇보면 p
        imag = i; //class에서 변수를 선언했기에 쓸수 잇다. 
    }

    // 따옴표를 " " 로 수정하고 기본값 대입(=) 확인
    void read(const char* msg = "복소수 = ") {
        printf(" %s ", msg);//이 ㅣ드라는 함수의 매게변수는 msg라는건데  a.read라는 함수의 입력값이 들어가있다고 하고 인수가 있다고 하면 a=이라는ㄴ 문자열이 msg로 들어각ㄴ다
        //msg는 문자열이라  %s를쓴다
        // %lf%lf 사이에 공백을 주면 입력받기 더 편합니다.
       scanf_s("%lf \t %lf", &real, &imag); //scanf는 키보드 입력을 받는다. lf는 실수형 데이터 타입의 값을 2개를 받겠다. 연속으로  

    }

    // 매개변수 부분에 = " " 추가
    void print(const char* msg = " 복소수 = ") {

        printf(" %s %4.2f + %4.2fi\n", msg, real, imag);
    }



    void add(Complex a, Complex b) {//add(a,b) 
        //c의 real에 areal과 b.real을 더해서 넣어라
        real = a.real + b.real;
        imag = a.imag + b.imag;
    }
};

//class real : public Complex{
//} 상속
