#include "MainWindow.h" // GUI 메인 윈도우 헤더 파일을 포함합니다.
#include <QApplication> // Qt 애플리케이션 객체를 생성하고 관리하는 헤더입니다.
#include <QPixmap> // 지도 이미지 등을 처리하기 위한 클래스 헤더입니다.
#include <QMessageBox> // 사용자에게 경고나 정보를 알리는 메시지 박스 헤더입니다.
#include <QTextEdit> // 텍스트를 입력하거나 표시하기 위한 위젯 헤더입니다.
#include <QDialog> // 대화창을 생성하기 위한 헤더입니다.
#include <QTableWidget> // 테이블 형태의 데이터를 보여주기 위한 헤더입니다.
#include <QVBoxLayout> // 위젯을 수직으로 배치하기 위한 레이아웃 헤더입니다.
#include <QHeaderView> // 테이블 등의 헤더를 제어하기 위한 헤더입니다.
#include <QLabel> // 텍스트나 이미지를 표시하는 라벨 위젯 헤더입니다.
#include <QListWidget> // 항목 리스트를 보여주는 위젯 헤더입니다.
#include <vector> // C++의 동적 배열 컨테이너를 사용하기 위한 헤더입니다.
#include <algorithm> // 정렬(sort) 등의 알고리즘 함수를 사용하기 위한 헤더입니다.

// Server 클래스의 생성자입니다.
Server::Server() {
    initialize_campus_data(); // 객체가 생성될 때 캠퍼스 정보를 메모리에 로드하는 함수를 호출합니다.
}

// 캠퍼스 내 건물 정보와 경로 데이터를 초기화하는 함수입니다.
void Server::initialize_campus_data() {
    // 건물 ID와 이름을 매핑하여 campus_buildings 벡터에 저장합니다 (그래프의 정점 리스트).
    campus_buildings = {
        {138, "정문 (1-38)"}, {127, "구정문 (1-27)"}, {27, "공대 7호관 (2-7)"},
        {21, "공대 1호관 (2-1)"}, {161, "중앙도서관 (16-1)"}, {141, "진수당 (1-41)"},
        {13, "제1학생회관 (1-3)"}, {14, "제2학생회관 (1-4)"}, {51, "사회과학대 (5-1)"},
        {61, "상대/경영대 (6-1)"}, {71, "자연과학대 (7-1)"}, {81, "인문대학 (8-1)"},
        {91, "농생대 (9-1)"}, {212, "생활관 진리관"}
    };

    // 건물 간 이동수단, 시간, 칼로리를 포함한 경로 데이터를 campus_routes에 저장합니다 (그래프의 간선 리스트).
    campus_routes = {
        {"도보", 138, 13, 10, 3}, {"도보", 13, 138, 10, 3},
        {"도보", 13, 127, 8, 2}, {"도보", 127, 13, 8, 2},
        {"도보", 127, 81, 6, 2}, {"도보", 81, 127, 6, 2},
        {"도보", 13, 141, 7, 2}, {"도보", 141, 13, 7, 2},
        {"도보", 141, 161, 10, 3}, {"도보", 161, 141, 10, 3},
        {"도보", 161, 14, 6, 2}, {"도보", 14, 161, 6, 2},
        {"셔틀", 138, 21, 5, 3}, {"도보", 21, 138, 15, 4},
        {"도보", 21, 27, 8, 2}, {"도보", 27, 21, 8, 2},
        {"도보", 27, 51, 10, 3}, {"도보", 51, 27, 10, 3},
        {"도보", 51, 61, 5, 1}, {"도보", 61, 51, 5, 1},
        {"도보", 61, 141, 12, 3}, {"도보", 141, 61, 12, 3},
        {"자전거", 81, 71, 5, 2}, {"자전거", 71, 81, 5, 2},
        {"도보", 71, 161, 12, 3}, {"도보", 161, 71, 12, 3},
        {"도보", 161, 91, 15, 4}, {"도보", 91, 161, 15, 4},
        {"도보", 91, 212, 10, 3}, {"도보", 212, 91, 10, 3},
        {"자전거", 27, 212, 18, 4}, {"자전거", 212, 27, 18, 4},
        {"셔틀", 212, 138, 20, 6}
    };
}

// 건물 ID를 입력받아 해당하는 건물 이름을 반환하는 함수입니다.
std::string Server::get_building_name(int id) {
    for (const auto& b : campus_buildings) if (b.id == id) return b.name; // 건물 리스트를 찾아 ID가 일치하면 이름을 반환합니다.
    return "미확인 구역"; // 찾지 못할 경우 기본 메시지를 반환합니다.
}

// 건물 ID를 입력받아 리스트 내의 인덱스를 반환하는 함수입니다.
int Server::get_building_index(int id) {
    for (size_t i = 0; i < campus_buildings.size(); ++i) if (campus_buildings[i].id == id) return i; // ID가 일치하는 인덱스를 찾습니다.
    return -1; // 찾지 못하면 -1을 반환합니다.
}

// DFS 알고리즘을 사용하여 목적지까지의 경로를 모두 탐색하는 재귀 함수입니다.
void Server::findPathsDFS(int curr_id, int dest_id, int& time, int& cal, std::vector<Route>& current_path, 
                          std::vector<bool>& visited, std::vector<PathResult>& all_paths) {
    int curr_idx = get_building_index(curr_id); // 현재 건물의 인덱스를 구합니다.
    
    // 목적지에 도착한 경우 지금까지 탐색한 경로 정보를 결과 리스트에 추가합니다.
    if (curr_id == dest_id) {
        all_paths.push_back({current_path, time, cal});
        return;
    }
    
    visited[curr_idx] = true; // 현재 정점을 방문 처리하여 중복 방문을 막습니다.
    
    // 연결된 모든 경로(간선)를 순회합니다.
    for (const auto& r : campus_routes) {
        if (r.start_id == curr_id) { // 현재 위치에서 출발하는 경로를 찾습니다.
            int next_idx = get_building_index(r.end_id); // 이동할 건물의 인덱스를 구합니다.
            if (next_idx != -1 && !visited[next_idx]) { // 아직 방문하지 않은 건물일 때 진입합니다.
                current_path.push_back(r);      // 경로에 추가합니다.
                time += r.duration;             // 소요 시간을 누적합니다.
                cal += r.calories;              // 칼로리를 누적합니다.
                
                findPathsDFS(r.end_id, dest_id, time, cal, current_path, visited, all_paths); // 재귀적으로 다음 단계를 탐색합니다.
                
                // [백트래킹] 재귀 탐색이 끝난 후, 다른 경로를 찾기 위해 다시 원상 복구합니다.
                time -= r.duration; 
                cal -= r.calories;
                current_path.pop_back();
            }
        }
    }
    visited[curr_idx] = false; // 현재 정점의 방문 상태를 해제하여 다른 경로 탐색에서 활용 가능하게 합니다.
}

// 경로들을 탐색하고 소요 시간 및 칼로리 기준으로 상위 3개 결과를 정렬하여 반환합니다.
std::vector<Server::PathResult> Server::get_top_3_paths(int start_id, int dest_id) {
    std::vector<PathResult> all_paths; // 탐색된 모든 경로를 담을 벡터입니다.
    std::vector<Route> p; // 탐색 중인 현재 경로입니다.
    std::vector<bool> v(campus_buildings.size(), false); // 방문 기록용 벡터입니다.
    int t = 0, c = 0; // 임시 시간과 칼로리 누적 변수입니다.
    
    findPathsDFS(start_id, dest_id, t, c, p, v, all_paths); // DFS 알고리즘을 호출합니다.
    
    // 정렬 함수: 시간(time)을 우선 기준으로, 같으면 칼로리(calories) 기준으로 정렬합니다.
    std::sort(all_paths.begin(), all_paths.end(), [](const PathResult& a, const PathResult& b) {
        if (a.total_time != b.total_time) return a.total_time < b.total_time;
        return a.total_calories < b.total_calories;
    });

    if (all_paths.size() > 3) all_paths.resize(3); // 결과가 3개보다 많으면 상위 3개만 남깁니다.
    return all_paths;
}

// 메인 윈도우 생성자: UI를 설정하고 초기화합니다.
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), start_node_id(-1), dest_node_id(-1) {
    setWindowTitle("Chonbuk National University Navigation System"); // 윈도우 제목을 설정합니다.
    setFixedSize(1000, 780); // 윈도우 크기를 고정합니다.

    status_label = new QLabel("안내: 지도에서 출발할 건물을 선택해 주세요.", this); // 안내 라벨을 생성합니다.
    status_label->setGeometry(20, 15, 600, 25); // 라벨 위치를 설정합니다.
    status_label->setStyleSheet("font-weight: bold; color: #2c3e50; font-size: 13px;"); // 스타일을 적용합니다.

    start_input = new QLineEdit(this); start_input->setGeometry(75, 50, 180, 25); start_input->setReadOnly(true); // 출발지 표시창을 만듭니다.
    dest_input = new QLineEdit(this); dest_input->setGeometry(335, 50, 180, 25); dest_input->setReadOnly(true); // 목적지 표시창을 만듭니다.

    reset_button = new QPushButton("선택 초기화", this); // 초기화 버튼을 생성합니다.
    reset_button->setGeometry(540, 48, 100, 28);
    reset_button->setStyleSheet("background-color: #e74c3c; color: white;"); // 버튼 스타일을 설정합니다.
    connect(reset_button, &QPushButton::clicked, this, &MainWindow::clear_all_selections); // 버튼 클릭 시 선택 초기화 함수를 연결합니다.

    map_label = new QLabel(this); // 지도 이미지를 보여줄 라벨을 생성합니다.
    QPixmap pixmap("전주캠퍼스_지도.jpg"); // 이미지 파일을 로드합니다.
    if (!pixmap.isNull()) map_label->setPixmap(pixmap.scaled(1000, 650)); // 이미지 크기를 조절하여 설정합니다.
    map_label->setGeometry(0, 90, 1000, 650); // 지도 위치를 설정합니다.

    // 지도 상의 건물 좌표 및 이름을 정의합니다.
    struct BtnPos { int id; QString name; int x; int y; };
    std::vector<BtnPos> targets = {
        {138, "정문", 740, 580}, {127, "구정문", 480, 600}, {27, "공대7호관", 730, 310},
        {21, "공대1호관", 820, 410}, {161, "중앙도서관", 440, 300}, {141, "진수당", 610, 470},
        {13, "제1학생회관", 530, 530}, {14, "제2학생회관", 340, 370}, {51, "사회과학대", 850, 500},
        {61, "상대/경영대", 710, 480}, {71, "자연과학대", 320, 260}, {81, "인문대학", 380, 480},
        {91, "농생대", 250, 190}, {212, "기숙사(진리관)", 110, 210}
    };

    // 각 건물을 버튼으로 생성하여 화면에 배치합니다.
    for (const auto& t : targets) {
        QPushButton* btn = new QPushButton(t.name, map_label); // 버튼을 생성합니다.
        btn->resize(105, 30); btn->move(t.x, t.y); // 크기와 위치를 정합니다.
        btn->setStyleSheet("background-color: rgba(255, 255, 255, 225); border: 2px solid #27ae60;"); // 버튼 스타일을 설정합니다.
        connect(btn, &QPushButton::clicked, this, [this, t]() { handle_building_selection(t.id); }); // 클릭 시 건물을 선택하는 함수를 연결합니다.
        building_buttons.push_back(btn); // 리스트에 버튼을 추가합니다.
    }
}

// 건물 선택 시 동작하는 함수입니다.
void MainWindow::handle_building_selection(int building_id) {
    std::string bName = campus_server.get_building_name(building_id); // 선택한 건물의 이름을 가져옵니다.
    if (start_node_id == -1) { // 출발지가 선택되지 않았다면 설정합니다.
        start_node_id = building_id;
        start_input->setText(QString::fromStdString(bName));
        status_label->setText("안내: 다음으로 목적지 건물을 클릭해 주세요.");
    } else if (dest_node_id == -1) { // 목적지가 선택되지 않았다면 설정하고 결과를 보여줍니다.
        if (start_node_id == building_id) {
            QMessageBox::warning(this, "경로 오류", "출발지와 목적지는 같을 수 없습니다."); // 출발지와 목적지가 같으면 경고창을 띄웁니다.
            return;
        }
        dest_node_id = building_id;
        dest_input->setText(QString::fromStdString(bName));
        display_path_results(); // 탐색 결과를 보여줍니다.
    } else { // 이미 두 곳이 다 선택되었다면 초기화하고 새로운 출발지로 설정합니다.
        clear_all_selections();
        start_node_id = building_id;
        start_input->setText(QString::fromStdString(bName));
        status_label->setText("안내: 다음으로 목적지 건물을 클릭해 주세요.");
    }
}

// 경로 탐색 결과를 보여주는 다이얼로그 창을 띄우는 함수입니다.
void MainWindow::display_path_results() {
    std::vector<Server::PathResult> top3 = campus_server.get_top_3_paths(start_node_id, dest_node_id); // 최적 경로 3개를 받아옵니다.
    if (top3.empty()) return; // 결과가 없으면 종료합니다.

    QDialog* dlg = new QDialog(this); // 결과를 보여줄 다이얼로그 객체를 생성합니다.
    dlg->setWindowTitle("경로 탐색 결과 (Top 3)");
    dlg->resize(500, 400);
    QVBoxLayout* layout = new QVBoxLayout(dlg); // 레이아웃을 설정합니다.
    
    QListWidget* list = new QListWidget(dlg); // 결과 리스트를 담을 위젯을 만듭니다.
    for (size_t i = 0; i < top3.size(); ++i) { // 각 경로를 리스트 항목으로 변환합니다.
        QString rank = (i == 0) ? "【 1순위 (최단 경로) 】" : QString("【 %1순위 경로 】").arg(i + 1);
        
        std::vector<std::string> unique_methods; // 사용된 이동수단 리스트를 추출합니다.
        for (const auto& r : top3[i].routes) {
            bool found = false;
            for (const auto& m : unique_methods) {
                if (m == r.method) { found = true; break; }
            }
            if (!found) unique_methods.push_back(r.method);
        }

        QString methods;
        for (size_t j = 0; j < unique_methods.size(); ++j) {
            if (j > 0) methods += ", ";
            methods += QString::fromStdString(unique_methods[j]);
        }
        
        QString itemText = QString("%1 - 시간: %2분 / 칼로리: %3kcal / 수단: [%4]")
                           .arg(rank).arg(top3[i].total_time).arg(top3[i].total_calories).arg(methods); // 표시할 텍스트를 구성합니다.
        
        QListWidgetItem* item = new QListWidgetItem(itemText, list); // 리스트 아이템을 만듭니다.
        item->setData(Qt::UserRole, QVariant::fromValue(i)); // 아이템에 인덱스 데이터를 저장합니다.
        list->addItem(item); // 리스트에 추가합니다.
    }

    // 리스트 항목을 클릭했을 때 상세 정보를 띄우는 함수입니다.
    connect(list, &QListWidget::itemClicked, this, [this, top3](QListWidgetItem* item) {
        int index = item->data(Qt::UserRole).toInt(); // 클릭한 경로의 인덱스를 가져옵니다.
        const auto& path = top3[index];
        QString detail = QString("총 소요 시간: %1분\n총 소모 칼로리: %2kcal\n\n상세 경로:\n")
                         .arg(path.total_time).arg(path.total_calories);
        
        detail += QString::fromStdString(campus_server.get_building_name(start_node_id));
        for (const auto& r : path.routes) { // 상세 경로를 텍스트로 합칩니다.
            detail += QString(" -> [%1 (%2분, %3kcal)] -> %4")
                      .arg(QString::fromStdString(r.method)).arg(r.duration).arg(r.calories)
                      .arg(QString::fromStdString(campus_server.get_building_name(r.end_id)));
        }
        QMessageBox::information(this, "길 안내 상세 정보", detail); // 상세 정보를 메시지 박스로 보여줍니다.
    });

    layout->addWidget(list); // 리스트를 다이얼로그에 추가합니다.
    dlg->show(); // 다이얼로그를 화면에 띄웁니다.
}

// 모든 선택을 초기화하는 함수입니다.
void MainWindow::clear_all_selections() {
    start_node_id = -1; dest_node_id = -1; // 선택된 건물 ID를 초기화합니다.
    start_input->clear(); dest_input->clear(); // 입력창을 비웁니다.
    status_label->setText("안내: 지도에서 출발할 건물을 선택해 주세요."); // 안내 문구를 원상복구합니다.
}

// 메인 함수: 프로그램의 시작점입니다.
int main(int argc, char *argv[]) {
    QApplication app(argc, argv); // Qt 앱 객체를 생성합니다.
    MainWindow window; // 메인 윈도우 객체를 생성합니다.
    window.show(); // 윈도우를 화면에 표시합니다.
    return app.exec(); // 이벤트 루프를 시작합니다.
}