#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;


//Music Class

class Music {
private:
	string title;
	string artist;
	string album;
	int year;
	

public:
	Music(string title, string artist, string albumm, int year) {
		this->title = title; //->*와 같은 역할
		this->artist = artist;
		this->album = album;
		this->year = year;

	}
	string getTitle() { return title; }
	string getArtist() { return artist; }
	string getAlbum() { return album; }
	int getYear() { return year; }

};


//Music Streaming Service Class

class MusicStreamingServiece {
private:
	string serviceName;
	vector<Music> musicList;

public:
	MusicStreamingServiece(string name) {
		this->serviceName = name;

	}
	//Add a music to the service
	void addMusic(string title, string artist, string album, int year) {
		Music newMusic(title, artist, album, year);
		musicList.push_back(newMusic);
		cout << title << "by" << artist << "added to " << serviceName << endl;

	}
	//Search by title

	Music* searchByTitle(string title) {//객체를 반환값으로 할때는 *를 붙인다냐
		for (int i = 0; i < musicList.size(); i++) {
			if (musicList[i].getTitle() == title) {
				return &musicList[i]; //& 주소값을 반환하려고
			}
		}
		return NULL;
	}
};
