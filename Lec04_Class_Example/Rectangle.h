#pragma once
#include <iostream>//C++에서  input output 하기위해 불러옴 이게 입력 출력을 쉽게해ㅑㅑ줌 이걸 통해 std::cout << "Rectangle 1: " <<std::endl:   에서 std::cout만 
class Rectangle { //쓰면 출력
private:
	double width;
	double height;
public://method 는 public에
	Rectangle(double w, double h) {//객체 생성, 2개의 매개변수를 받는다	
		width = 2;
		height = h;


	}
	//면적 구하기
	double getArea() {
		return width * height;

	}

	// 둘레 길이 구하기
	double getPerimeter() {
		return 2 * (width + height);

	}

	//정사각형인지 판별 함수 인지 아닌지 0아니면 1을 담는 거 bool함수 출력값이 0아님 1 그걸  bool형태로
	bool isSquare() {
		return(width == height);//같으면 1출력  다르면 0출력

	}




};