#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
bool visited[1000001] = { 0, }; // 전역으로 선언하면 모두 false로 초기화 됨. 
vector<int> graph[1000001]; // 벡터 자체가 9개
vector<int> num[1000001];
int tomato_box[1001][1001] = { {0,}, };
int max_num = 0;
void bfs(bool visited[],vector<int> graph[],vector<int> tomato) {
    queue<int> q;
    int i = 0;
    for (int i = 0; i < tomato.size(); i++) {
        q.push(tomato[i]);
        num[tomato[i]].push_back(0);
        visited[tomato[i]] = true;
    }
     // 첫 노드를 방문 처리

    // 큐가 빌 때까지 반복
    while (!q.empty()) {
        // 큐에서 하나의 원소를 뽑아 출력
        int x = q.front();
        q.pop();
        // 해당 원소와 연결된, 아직 방문하지 않은 원소들을 큐에 삽입
        for (int i = 0; i < graph[x].size(); i++) {
            int y = graph[x][i];
            if (!visited[y]) {
                num[y].push_back(num[x][0] + 1);
                max_num = max(max_num, num[y][0]);
                q.push(y);
                visited[y] = true;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
     
    vector<int> tomato;
    int blank = 0;
    int result = 0;
    
    int x, y;
    cin >> x >> y;
    for (int i = 0; i < y; i++) {//토마토 농장 자료 받기
        for (int j = 0; j < x; j++) {
            int temp_tomato;
            cin >> temp_tomato;
            tomato_box[i][j] = temp_tomato;
        }
    }
    for (int i = 0; i < y; i++) {//토마토를 그래프로 만들었음
        for (int j = 0; j < x; j++) {
            if (tomato_box[i][j] == 1) {
                tomato.push_back(x * i + j + 1);
            }
            if (tomato_box[i][j] != -1) {
                if (i != 0) {
                    if (tomato_box[i - 1][j] == 0) {
                        graph[x * i + j + 1].push_back(((x) * (i - 1)) + j + 1);
                        graph[((x) * (i - 1)) + j + 1].push_back(x * i + j + 1);
                    }
                }
                if (j != 0) {
                    if (tomato_box[i][j - 1] == 0) {
                        graph[x * i + j + 1].push_back(((x)*i) + j);
                        graph[((x)*i) + j].push_back(x * i + j + 1);
                    }
                }
                if (i != (y - 1)) {
                    if (tomato_box[i + 1][j] == 0) {
                        graph[x * i + j + 1].push_back(((x) * (i + 1)) + j + 1);
                        graph[((x) * (i + 1)) + j + 1].push_back(x * i + j + 1);
                    }
                }
                if (j != (x - 1)) {
                    if (tomato_box[i][j + 1] == 0) {
                        graph[x * i + j + 1].push_back(((x)*i) + j + 2);
                        graph[((x)*i) + j + 2].push_back(x * i + j + 1);
                    }
                }
            }
            else{
                blank++;
            }
        }
    }
    /*for (int i = 0; i < (x * y); i++) {//그래프 정렬(작은것부터)
        sort(graph[i].begin(), graph[i].end());
    }*/
    bfs(visited, graph, tomato);
    for (int i = 0; i < y; i++) {//토마토를 그래프로 만들었음
        for (int j = 0; j < x; j++) {
            if (tomato_box[i][j] != -1) {
                if (visited[x*i+j+1] == false) {
                    cout << "-1";
                    result = 1;
                    break;
                }
            }
        }
        if (result == 1) {
            break;
        }
    }
    if (result == 0) {
        if (blank + tomato.size() == (x * y)) {
            cout << "0";
        }
        else {
            cout << max_num;
        }
    }
}