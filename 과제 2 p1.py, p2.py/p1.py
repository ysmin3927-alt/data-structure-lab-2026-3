A = {
    0: [1, 2, 3],
    1: [0, 2, 4, 5],
    2: [0, 1, 6],
    3: [0],
    4: [1],
    5: [1],
    6: [2]
}

def bfs(A):
    """
    [기능] 인접 리스트로 표현된 그래프를 너비 우선 탐색(BFS)하는 함수
    
    [동작 원리] 
    시작 노드(0번)로부터 거리가 가까운 노드들을 레벨 단위로 순차 방문합니다.
    선입선출(FIFO) 구조인 큐(Queue) 자료구조를 'while' 문을 통해 제어하며,
    동일 레벨의 인접 노드들을 확인할 때도 'while' 루프 인덱스를 활용해 
    낮은 번호의 노드부터 순서대로 대기열에 진입시킵니다.
    
    Args:
        A (dict): 노드 번호(int)를 Key로, 인접 노드 리스트(list)를 Value로 갖는 그래프
        
    Returns:
        list: 0번 노드부터 시작하여 너비 우선 탐색으로 최종 방문 완료한 노드 순서 리스트
    """
    answer = []
    visited = [False] * len(A)
    queue = [0]
    visited[0] = True
    
    # 대기열(Queue)에 처리할 노드가 남아있는 동안 탐색을 계속합니다.
    while len(queue) > 0:
        print("현재 Queue :", queue, "-> 방문 기록 :", answer, "\n")
        
        current = queue.pop(0)
        answer.append(current)
        
        neighbors = A[current]
        i = 0
        # while 문을 사용해 인접 노드 리스트의 첫 번째 원소(인덱스 0)부터 순방향으로 확인합니다.
        while i < len(neighbors):
            neighbor = neighbors[i]
            if not visited[neighbor]:
                queue.append(neighbor)
                visited[neighbor] = True
            i += 1
                
    print("최종 BFS 결과 :", answer, "\n")
    return answer

def dfs(A):
    """
    [기능] 인접 리스트로 표현된 그래프를 깊이 우선 탐색(DFS)하는 함수
    
    [동작 원리]
    시작 노드(0번)로부터 한 경로를 택해 갈 수 있는 가장 깊은 곳까지 우선 탐색합니다.
    후입선출(LIFO) 구조인 스택(Stack) 자료구조를 'while' 문을 통해 제어하며,
    스택에서 꺼낼 때 번호가 작은 노드가 먼저 나오도록 유도하기 위해 
    인접 노드 리스트의 맨 뒤 인덱스부터 거꾸로('i = len - 1') 역추적하며 스택에 삽입합니다.
    
    Args:
        A (dict): 노드 번호(int)를 Key로, 인접 노드 리스트(list)를 Value로 갖는 그래프
        
    Returns:
        list: 0번 노드부터 시작하여 깊이 우선 탐색으로 최종 방문 완료한 노드 순서 리스트
    """
    answer = []
    visited = [False] * len(A)
    stack = [0]
    visited[0] = True
    
    # 대기열(Stack)에 처리할 노드가 남아있는 동안 탐색을 계속합니다.
    while len(stack) > 0:
        print("현재 Stack :", stack, "-> 방문 기록 :", answer, "\n")
        
        current = stack.pop()
        answer.append(current)
        
        neighbors = A[current]
        # 후입선출(LIFO) 특성을 고려해, 번호가 작은 노드가 먼저 팝되도록 맨 마지막 인덱스부터 거꾸로 제어합니다.
        i = len(neighbors) - 1
        # while 문을 사용해 인접 노드 리스트를 끝에서부터 앞으로 오며 역방향으로 확인합니다.
        while i >= 0:
            neighbor = neighbors[i]
            if not visited[neighbor]:
                stack.append(neighbor)
                visited[neighbor] = True
            i -= 1
                    
    print("최종 DFS 결과 :", answer, "\n")
    return answer

# 아래는 체크함수입니다. 수정하실 필요 없습니다.
bfs_result = bfs(A)
dfs_result = dfs(A)

assert bfs_result == [0, 1, 2, 3, 4, 5, 6]
assert dfs_result == [0, 1, 4, 5, 2, 6, 3]
print('PASSED!')
