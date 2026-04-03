#pragma once//한번만 포함되도록 하는 전처리 지시자
#include <iostream>//C++에서  input output 라이브러리 포함 ,cout, cin, endl등이 포함되어있음
class Rectangle { //사각형 클래스
private://멤버 변수는 private에
	double width;//사각형의 너비를 저장하는 멤버 변수
	double height;//사각형의 높이를 저장하는 멤버 변수
public://멤버 함수는 public에
	Rectangle(double w, double h) {//객체 생성, 2개의 매개변수를 받는다	,생성자 함수
		width = w;//매개변수로 받은 너비를 멤버 변수 width에 저장
		height = h;//매개변수로 받은 높이를 멤버 변수 height에 저장

	}
	//면적 구하기
	double getArea() {//사각형의 면적을 계산하여 반환하는 멤버 함수
		return width * height;//사각형의 면적은 너비와 높이를 곱한 값이므로 width와 height를 곱하여 반환

	}

	// 둘레 길이 구하기
	double getPerimeter() {//사각형의 둘레를 계산하여 반환하는 멤버 함수
		return 2 * (width + height);//사각형의 둘레는 너비와 높이를 더한 값에 2를 곱한 값이므로 (width + height)에 2를 곱하여 반환

	}

	//정사각형인지 판별 함수 인지 아닌지 0아니면 1을 담는 거 bool함수 출력값이 0아님 1 그걸  bool형태로
	bool isSquare() {//사각형이 정사각형인지 판별하는 멤버 함수
		return(width == height);//사각형이 정사각형이려면 너비와 높이가 같아야하므로 width와 height가 같은지 비교하여 그 결과를 반환, 같으면 1, 다르면 0이 반환됨

	}
};