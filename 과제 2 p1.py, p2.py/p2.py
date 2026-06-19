import sys

## 입력 받는 코드입니다. 수정할 필요 없습니다.

#hidden case (가장자리만 무대공간인 경우, 팬스0개 무대공간 1개인경우, 팬스만 존재하는 경우)
sys.stdin = open('case.txt')
#sys.stdin = open('hidden_scattered.txt')
#sys.stdin = open('hidden_zeros.txt')
#sys.stdin = open('hidden_walls.txt')

# 첫 줄 N, M 읽기
input_data = sys.stdin.readline().split()
if not input_data:
    exit()
N, M = map(int, input_data)

concerts = []
sin=[]
for v in range(N):
    values = list(map(int, sys.stdin.readline().split()))
    concerts.append(values)
print(concerts)
# ###########################################
def count_stages(concerts):
    """
    [DFS 알고리즘 설계 설명]
    1. 전체 콘서트장(N x M)을 순회하며 빈 공간(0)을 찾습니다.
    2. 0을 발견하면 새로운 무대 공간이 시작된 것이므로, 카운트(answer)를 1 증가시킵니다.
    3. 해당 지점에서 DFS를 호출하여 상하좌우로 연결된 모든 0을 방문 완료(1) 처리합니다.
    4. 이미 방문 처리된 공간은 다시 탐색하지 않으므로, 독립된 무대 공간 개수만 정확히 산출됩니다.

    무대 공간의 개수가 아니라 "최단거리"를 구해야 했다면 BFS가 훨씬 유리
    하지만, 이 문제는 연결된 공간을 한번씩 모두 탐색하여 방문 처리하는것이 핵심입니다.
    DFS를 사용하면 별도의 자류구조(QUEUE)없어도 짧고 간결하게, 코드의 기독성까지 챙길수 있습니다.
    """
    answer = 0
    ## TODO : 콘서트 공간에서 무대의 개수를 계산해 반환해주는 함수를 작성해주세요.
    
    # 내부 DFS 함수 정의 (재귀적 탐색)
    def dfs(r, c):
        # 1. 경계 조건: 배열 범위를 벗어나면 종료
        if r < 0 or r >= N or c < 0 or c >= M:
            return
        # 2. 벽(1)이거나 이미 방문한 곳(1)이면 종료
        if concerts[r][c] == 1:
            return
        
        # 3. 현재 위치를 방문 처리 (1로 변경하여 다시 방문하지 않게 함)
        concerts[r][c] = 1
        
        # 4. 상하좌우 재귀 호출
        dfs(r - 1, c) # 상
        dfs(r + 1, c) # 하
        dfs(r, c - 1) # 좌
        dfs(r, c + 1) # 우

    # 전체 격자 순회
    for r in range(N):
        for c in range(M):
            # 빈 공간(0) 발견 시 DFS 탐색 시작
            if concerts[r][c] == 0:
                answer += 1
                dfs(r, c)
                
    return answer 

# 결과 출력
print(count_stages(concerts))
