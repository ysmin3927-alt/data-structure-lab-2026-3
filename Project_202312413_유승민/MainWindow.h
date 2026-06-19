#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <string>
#include <vector>

/**
 * @brief 캠퍼스 내의 개별 건물(노드) 데이터를 정의하는 구조체
 */
struct Building { 
    int id;             // 건물을 고유하게 식별하기 위한 정수형 ID
    std::string name;   // 화면에 출력될 건물 이름 (예: "정문", "공대 7호관")
};

/**
 * @brief 건물과 건물 사이를 잇는 이동 경로(간선) 정보를 정의하는 구조체
 */
struct Route { 
    std::string method;     // 이동 수단 (예: "도보", "셔틀", "자전거")
    int start_id;           // 출발 건물의 고유 ID
    int end_id;             // 도착 건물의 고유 ID
    int calories;           // 해당 구간 이동 시 소모되는 칼로리 (가중치 1)
    int duration;           // 해당 구간 이동 시 소요되는 시간 (가중치 2)
};

/**
 * @brief 캠퍼스 내 데이터(건물/경로) 관리 및 경로 탐색 알고리즘을 수행하는 핵심 로직 클래스
 */
class Server {
public:
    /**
     * @brief 출발지에서 목적지까지 탐색된 하나의 경로 결과 전체 정보를 담는 구조체
     */
    struct PathResult {
        std::vector<Route> routes; // 경로를 구성하는 개별 구간(Route)들의 순차 리스트
        int total_time;            // 전체 경로의 소요 시간 합계
        int total_calories;        // 전체 경로의 칼로리 소모 합계
    };

protected:
    std::vector<Building> campus_buildings; // 등록된 모든 캠퍼스 건물 리스트
    std::vector<Route> campus_routes;       // 건물 간 연결된 전체 도로망(간선) 리스트

public:
    /**
     * @brief 생성자: 프로그램 시작 시 캠퍼스 내 데이터베이스를 초기화함
     */
    Server();

    /**
     * @brief 캠퍼스 내 건물 정보 및 이들을 연결하는 도로망을 생성/초기화함
     */
    void initialize_campus_data();

    /**
     * @brief 특정 건물 ID를 입력받아 해당하는 건물 명칭을 반환
     */
    std::string get_building_name(int id);

    /**
     * @brief 건물 ID를 내부 배열에서 접근 가능한 인덱스 값으로 변환
     */
    int get_building_index(int id);
    
    /**
     * @brief DFS(깊이 우선 탐색)를 사용하여 출발지부터 목적지까지 가능한 모든 경로를 재귀적으로 탐색
     * @param curr_id 현재 노드 ID, dest_id 목적지 ID, time/cal 누적값, current_path 현재 경로, visited 방문 상태, all_paths 결과 저장소
     */
    void findPathsDFS(int curr_id, int dest_id, int& time, int& cal, std::vector<Route>& current_path, 
                      std::vector<bool>& visited, std::vector<PathResult>& all_paths);
                      
    /**
     * @brief DFS로 찾은 모든 경로 중 시간/칼로리 기준으로 상위 3개의 최적 경로를 정렬하여 반환
     */
    std::vector<PathResult> get_top_3_paths(int start_id, int dest_id);
};

/**
 * @brief GUI 화면 구성, 사용자 입력 처리 및 결과 출력을 담당하는 메인 윈도우 클래스
 */
class MainWindow : public QMainWindow {
    Q_OBJECT // Qt의 시그널-슬롯 기능을 활성화하는 매크로

private:
    Server campus_server;                       // 비즈니스 로직(데이터/알고리즘) 담당 객체
    QLabel* map_label;                          // 캠퍼스 지도를 보여줄 배경 라벨
    std::vector<QPushButton*> building_buttons; // 지도 위에 배치된 건물 클릭 버튼들
    
    int start_node_id;                          // 현재 설정된 출발지 건물 ID (-1이면 미설정)
    int dest_node_id;                           // 현재 설정된 목적지 건물 ID (-1이면 미설정)
    
    QLineEdit* start_input;                     // 출발지 이름을 표시하는 입력창 (읽기 전용)
    QLineEdit* dest_input;                      // 목적지 이름을 표시하는 입력창 (읽기 전용)
    QLabel* status_label;                       // 사용자에게 현재 상태를 알리는 안내 라벨
    QPushButton* reset_button;                  // 선택된 출발/도착지 정보를 초기화하는 버튼

public:
    /**
     * @brief MainWindow 생성자: UI 컴포넌트 생성 및 초기 배치를 수행
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * @brief 지도상의 건물 버튼 클릭 시 출발/도착지를 지정하고 경로 계산을 유도
     */
    void handle_building_selection(int building_id);

    /**
     * @brief 계산된 최적 경로(Top 3)를 다이얼로그 형태로 시각화하여 사용자에게 보여줌
     */
    void display_path_results();

    /**
     * @brief 모든 선택을 초기화하고 처음 단계로 돌아감
     */
    void clear_all_selections();
    
    /**
     * @brief 상위 3개 경로 목록을 별도의 대화창으로 보여주는 기능
     */
    void show_top_3_paths_dialog();
};

#endif // MAINWINDOW_H