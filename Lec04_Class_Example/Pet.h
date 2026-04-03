#pragma once//한번만 포함되도록 하는 전처리 지시자
#include <iostream>//C++에서  input output 라이브러리 포함 ,cout, cin, endl등이 포함되어있음
#include <string>//C++에서 문자열을 다루기 위한 라이브러리 포함, string 클래스가 포함되어있음
using namespace std;//std 네임스페이스를 사용하여 string, cout, cin 등을 사용할 때 std::를 생략할 수 있도록 함

class Pet {//Pet 클래스 정의
protected: //Pet 클래스의 멤버 변수는 protected로 선언되어 있어, Pet 클래스와 그 자식 클래스에서 접근할 수 있도록 함
	string name;//애완동물의 이름을 저장하는 멤버 변수, Pet 클래스의 생성자에서 초기화됨, Pet 클래스의 getName() 메서드에서 반환됨, Puppy 클래스에서도 name 멤버 변수를 사용할 수 있음
	int age;//애완동물의 나이를 저장하는 멤버 변수
	string type;//애완동물의 종류를 저장하는 멤버 변스, 예를 들어 "dog", "cat" 등, Pet 클래스의 생성자에서 초기화됨, Pet 클래스의 getName(), getAge(), getType() 메서드에서 반환됨, Puppy 클래스에서도 type 멤버 변수를 사용할 수 있음
public:
	//생성자 함수
	Pet(string n, int a, string t)	//Pet 클래스의 생성자 함수, 세 개의 매개변수를 받아서 name, age, type 멤버 변수를 초기화
		: name(n), age(a), type(t) {//생성자 초기화 리스트를 사용하여 name, age, type 멤버 변수를 초기화
		//n 매개변수로 받은 값을 name 멤버 변수에 저장, a 매개변수로 받은 값을 age 멤버 변수에 저장, t 매개변수로 받은 값을 type 멤버 변수에 저장
	}
	
	string getName() {//Pet 클래스의 getName() 메서드, name 멤버 변수를 반환
		return name;

	}
	int getAge() {//Pet 클래스의 getAge() 메서드, age 멤버 변수를 반환
		return age;
	}

	string getType() {//Pet 클래스의 getType() 메서드, type 멤버 변수를 반환
		return type;
	}
};
class Puppy : public Pet {//Puppy 클래스 정의, Pet 클래스를 상속받
private://Puppy 클래스의 멤버 변수는 private로 선언되어 있어, Puppy 클래스 내부에서만 접근할 수 있도록 함
	string breed;//강아지의 품종을 저장하는 멤버 변수, Puppy 클래스의 생성자에서 초기화됨, Puppy 클래스의 getBreed() 메서드에서 반환됨
public:
	Puppy(string n, int a, string t, string b)//Puppy 클래스의 생성자 함수, 네 개의 매개변수를 받아서 name, age, type 멤버 변수와 breed 멤버 변수를 초기화
		: Pet(n, a, t), breed(b) {//생성자 초기화 리스트를 사용하여 Pet 클래스의 생성자 함수를 호출하여 name, age, type 멤버 변수를 초기화하고, breed 멤버 변수를 초기화
		//Pet(n,a,t)의 의미는 pet클래스를 호출했기 때문에 Pet(n,a,t)라고 쓰는 것
	}
	string getBreed() {//Puppy 클래스의 getBreed() 메서드, breed 멤버 변수를 반환
		return breed;
	}
};