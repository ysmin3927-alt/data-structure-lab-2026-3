#pragma once//한번만 포함되도록 하는 전처리 지시자
#include <iostream>//C++에서  input output 라이브러리 포함 ,cout, cin, endl등이 포함되어있음
#include <string>//C++에서 문자열을 다루기 위한 라이브러리 포함, string 클래스가 포함되어있음
#include <vector>//C++에서 동적 배열을 다루기 위한 라이브러리 포함, vector 클래스가 포함되어있음
using namespace std;//std 네임스페이스를 사용하여 string, cout, cin 등을 사용할 때 std::를 생략할 수 있도록 함

//Music Class

class Music {//Music 클래스 정의
private://Music 클래스의 멤버 변수는 private로 선언되어 있어, Music 클래스 내부에서만 접근할 수 있도록 함
	string title;//음악의 제목을 저장하는 멤버 변수, Music 클래스의 생성자에서 초기화됨, Music 클래스의 getTitle() 메서드에서 반환됨
	string artist;//음악의 아티스트를 저장하는 멤버 변수, Music 클래스의 생성자에서 초기화됨, Music 클래스의 getArtist() 메서드에서 반환됨
	string album;//음악의 앨범을 저장하는 멤버 변수, Music 클래스의 생성자에서 초기화됨, Music 클래스의 getAlbum() 메서드에서 반환됨
	int year;//음악의 발매 연도를 저장하는 멤버 변수, Music 클래스의 생성자에서 초기화됨, Music 클래스의 getYear() 메서드에서 반환됨

public://Music 클래스의 멤버 함수는 public으로 선언되어 있어, Music 클래스 외부에서도 접근할 수 있도록 함
	Music(string title, string artist, string albumm, int year) {//Music 클래스의 생성자 함수, 네 개의 매개변수를 받아서 title, artist, album, year 멤버 변수를 초기화
		this->title = title; //->*와 같은 역할, this는 현재 객체를 가리키는 포인터, this->title은 현재 객체의 title 멤버 변수에 접근, 매개변수로 받은 title 값을 현재 객체의 title 멤버 변수에 저장
		this->artist = artist;
		this->album = album;//매개변수로 받은 album 값을 현재 객체의 album 멤버 변수에 저장
		this->year = year;

	}
	string getTitle() { return title; }//Music 클래스의 getTitle() 메서드, title 멤버 변수를 반환
	string getArtist() { return artist; }
	string getAlbum() { return album; }
	int getYear() { return year; }

};

//Music Streaming Service Class

class MusicStreamingServiece {//MusicStreamingServiece 클래스 정의
private://MusicStreamingServiece 클래스의 멤버 변수는 private로 선언되어 있어, MusicStreamingServiece 클래스 내부에서만 접근할 수 있도록 함
	string serviceName;//음악 스트리밍 서비스의 이름을 저장하는 멤버 변수, MusicStreamingServiece 클래스의 생성자에서 초기화됨
	//MusicStreamingServiece 클래스의 addMusic() 메서드에서 사용됨, MusicStreamingServiece 클래스의 searchByTitle() 메서드에서 사용됨
	std::vector<Music> musicList;//musicList라는 vector를 선언하고 Music클래스의 객체만 저장하는 벡터

public://MusicStreamingServiece 클래스의 멤버 함수는 public으로 선언되어 있어, MusicStreamingServiece 클래스 외부에서도 접근할 수 있도록 함
	MusicStreamingServiece(string name) {//MusicStreamingServiece 클래스의 생성자 함수, 하나의 매개변수를 받아서 serviceName 멤버 변수를 초기화
		this->serviceName = name;//매개변수로 받은 name 값을 현재 객체의 serviceName 멤버 변수에 저장

	}
	//Add a music to the service
	void addMusic(string title, string artist, string album, int year) {//addMusic() 메서드 정의, 네 개의 매개변수를 받아서 새로운 Music 객체를 생성하고 musicList 벡터에 추가
		Music newMusic(title, artist, album, year);//매개변수로 받은 title, artist, album, year 값을 사용하여 새로운 Music 객체를 생성
		musicList.push_back(newMusic);//생성된 Music 객체를 musicList 벡터에 추가
		cout << title << " by " << artist << " added to " << serviceName << endl;
		//새로운 음악이 추가되었다는 메시지를 출력, title과 artist를 사용하여 추가된 음악의 제목과 아티스트를 표시하고, serviceName을 사용하여 음악이 추가된 스트리밍 서비스의 이름을 표시

	}
	//Search by title

	Music* searchByTitle(string title) {//Music이라는 객체를 반환값으로 할때는 *를 붙인다, searchByTitle() 메서드 정의,
		//하나의 매개변수를 받아서 musicList 벡터에서 해당 제목을 가진 Music 객체를 검색하고 그 주소를 반환
		for (int i = 0; i < musicList.size(); i++) {//musicList 벡터의 크기만큼 반복하여 각 Music 객체의 제목을 검색
			if (musicList[i].getTitle() == title) {//현재 반복 중인 Music 객체의 제목이 검색하려는 제목과 일치하는지 비교
				return &musicList[i]; //일치하는 제목이 발견되면 해당 Music 객체의 주소를 반환, & 연산자를 사용하여 Music 객체의 주소를 반환
			}//&musicList[i]의 주소를 반환한다는것은 Music 객체의 주소를 반환한다는것을 의미, Music 객체의 주소를 말하는 Music* 를 사용하여 변수자료형을 선언해야함.
		}//musiclist[i]는 저장된 객체를 말하는것이고 &musiclist[i]는 저장된 객체의 주소를 말하는것이다.
		return NULL;//검색하려는 제목이 musicList 벡터에 없는 경우 NULL을 반환, NULL은 포인터가 유효한 객체를 가리키지 않음을 나타내는 값
	}
};
