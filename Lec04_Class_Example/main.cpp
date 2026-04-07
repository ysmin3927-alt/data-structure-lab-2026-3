#include "Rectangle.h"//메인 함수 cpp에 렉탱글 해더파일을 불러와야해서 씀
#include "Pet.h"//메인 함수 cpp에 펫 해더파일을 불러와야해서 씀
#include "Music.h"//메인 함수 cpp에 뮤직 해더파일을 불러와야해서 씀
using namespace std; //를 쓰면 std를 안써도 됨
int main() {
	//Rectangle 클래스로 rect1객체 생성
	Rectangle rect1(4,6); //생성자 함수꼴을 2개의 인수로 받는다해서 rect1만 쓰면 에러
	std::cout << "Rectangle 1: " << std::endl;     // 컴퓨터가 제공하는 함수에 cout가 있다면    std::endl; ?> ::endl      //줄바꿈 endl
	//printf("Rectangle 1: \n"); 과 같다.               //컴퓨터가 헷갈리기에  std를 사용해서 구분해주는 것(std에 있는 cout쓸거야)
	cout << "Area: " << rect1.getArea() << endl;//cout는 std::cout과 같다.  std::cout << "Area: " << rect1.getArea() << endl; 과 같다
	//printf("Area: %lf\n", rect1.getArea());
	cout << "Perimeter: " << rect1.getPerimeter() << endl;//printf("Perimeter: %lf\n", rect1.getPerimeter());
	cout << "Is Square? " << boolalpha << rect1.isSquare() << endl; //<<화살표를 타고 넘어오는 값이 bool형식이니까 o,1 true, false로 나오게 하기
	//output이 bool형식이니까 그걸 false로 나오게 하기위해서 boolalpha사용 없애면 그냥 0으로 나옴
	printf("=====================================================\n");

	Pet myPet("Lucky", 5, "dog");//Pet 클래스의 myPet 객체 생성
	cout << "My pet's name is " << myPet.getName() << endl;//myPet 객체의 getName() 메서드를 호출하여 애완동물
	Puppy myPuppy("Kong", 3, "dog", "Puddle");//Puppy 클래스의 myPuppy 객체 생성
	cout << "My puppy's breed is " << myPuppy.getBreed() << endl;//myPuppy 객체의 getBreed() 메서드를 호출하여 강아지의 품종을 출력
	printf("=====================================================\n");
 

	//Create a new music streaming service
	MusicStreamingServiece myService("Melon");//MusicStreamingServiece 클래스의 myService 객체 생성, "Melon"이라는 이름을 매개변수로 전달하여 생성자에서 serviceName 멤버 변수를 초기화
	//Add some music to the service
	myService.addMusic("Jump", "Blackpink", "Jump_Album", 2025);//myService 객체의 addMusic() 메서드를 호출하여 음악을 추가
	myService.addMusic("Flower", "Bls", "Jdwmp_Album", 2035);
	myService.addMusic("Lemon", "Blasdfpink", "kkmp_Album", 2021);
	myService.addMusic("Candy", "aecackpink", "sump_Album", 2025);
	myService.addMusic("DDuu", "Blackpink", "Jump_Album", 2028);
	//Search by title
	string music_title;//사용자로부터 검색할 음악 제목을 입력받기 위한 변수 선언
	cout << "\nEnter the Music Title: ";//사용자에게 음악 제목을 입력하라는 메시지를 출력
	cin >> music_title;//사용자로부터 음악 제목을 입력받아 music_title 변수에 저장
	Music* result = myService.searchByTitle(music_title);//myService 객체의 searchByTitle() 메서드를 호출하여 입력받은 음악 제목으로 검색하고 결과를 result 포인터에 저장
	if (result != NULL) {//검색 결과가 NULL이 아닌 경우, 즉 음악이 검색된 경우
		cout << "Found: " << result->getTitle() << endl; //검색된 음악의 제목을 출력, result 포인터를 사용하여 검색된 Music 객체의 getTitle() 메서드를 호출하여 제목을 가져와 출력
		//-> =*
	}
	else {
		cout << "Not Found" << endl;//검색된 음악이 없는 경우 "Not Found" 메시지를 출력
	}
	//Search by artist
	string artist_name;
	cout << "Enter the artist name: ";
	cin >> artist_name;
	vector <Music*> artistResult = myService.searchByArtist(artist_name);
	if (artistResult.size() > 0) {
		cout << "Found " << artistResult.size() << " songs  by " << artist_name << " : " << endl;
		for (int i = 0; i < artistResult.size(); i++) {
			cout << artistResult[i]->getTitle() << endl;

		}
	}
	else {
		cout << "Not Found" << endl;
	}

	return 0;
}