#include "Rectangle.h"//메인 함수 cpp에 렉탱글 해더파일을 불러와야해서 씀
#include "Pet.h"
#include "Music.h"
using namespace std; //를 쓰면 std를 안써도 됨
int main() {
	//Rectangle 클래스로 rect1객체 생성
	Rectangle rect1(4,6); //생성자 함수꼴을 2개의 인수로 받는다해서 rect1만 쓰면 에러
	std::cout << "Rectangle 1: " << std::endl;     //    std::endl; ?> ::endl      //줄바꿈 endl
	//printf("Rectangle 1: \n"); 과 같다.
	cout << "Area: " << rect1.getArea() << endl;
	//printf("Area: %lf\n", rect1.getArea());
	cout << "Perimeter: " << rect1.getPerimeter() << endl;
	cout << "Is Square? " << boolalpha << rect1.isSquare() << endl;
	//output이 bool형식이니까 그걸 false로 나오게 하기위해서 boolalpha사용 없애면 그냥 0으로 나옴
	printf("=====================================================");

	Pet myPet("Lucky", 5, "dog");
	cout << "My pet's name is " << myPet.getName() << endl;
	Puppy myPuppy("Kong", 3, "dog", "Puddle");
	cout << "My puppy's breed is " << myPuppy.getBreed() << endl;
	printf("=====================================================");


	//Create a new music streaming service
	MusicStreamingServiece myService("Melon");
	//Add some music to the service
	myService.addMusic("Jump", "Blackpink", "Jump_Album", 2025);
	myService.addMusic("Jggdf", "Bls", "Jdwmp_Album", 2035);
	myService.addMusic("sdfump", "Blasdfpink", "kkmp_Album", 2021);
	myService.addMusic("sdfmp", "aecackpink", "sump_Album", 2025);
	//Search by title
	string music_title;
	cout << "Enter the Music Title: ";
	cin >> music_title;
	Music* result = myService.searchByTitle(music_title);
	if (result != NULL) {
		cout << "Found: " << result->getTitle() << endl;

	}
	else {
		cout << "Not Found" << endl;
	}


	return 0;
}