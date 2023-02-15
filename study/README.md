# Data Structures & Algorithms

## Array

- 여러 data가 메모리 덩어리 안에 줄줄이 나열된 가장 간단한 구조
- data에는 index로 접근

### 시간복잡도

* Average
    * 검색 - O(n)
    * 삽입 - O(n)
    * 삭제 - O(n)
* Worst
    * 검색 - O(n)
    * 삽입 - O(n)
    * 삭제 - O(n)

## Stack

- First In, Last Out

### 시간복잡도

* Average
    * 검색 - O(n)
    * 삽입 - O(1)
    * 삭제 - O(1)
* Worst
    * 검색 - O(n)
    * 삽입 - O(1)
    * 삭제 - O(1)

## Queue

- First In, First Out

### 시간복잡도

* Average
    * 검색 - O(n)
    * 삽입 - O(1)
    * 삭제 - O(1)
* Worst
    * 검색 - O(n)
    * 삽입 - O(1)
    * 삭제 - O(1)

## Linked List

- 메모리에서 연속되어 있지 않음. 각 노드가 포인터로 연결되어 있음. 
- 빈번한 삽입, 삭제에 유리함. 

### 시간복잡도

* Average
    * 검색 - O(n)
    * 삽입 - O(1)
    * 삭제 - O(1)
* Worst
    * 검색 - O(n)
    * 삽입 - O(1)
    * 삭제 - O(1)

## Hash Table

- hash function: 임의의 길이의 데이터를 고정된 길이의 데이터로 매핑하는 함수
    - 입력값이 조금만 달라져도 결과값이 크게 달라진다. 
    - 결정론적으로 작동한다. 
    - 두 해시 값이 다르다면 그 해시 값에 대한 원래 데이터도 다르다. (역은 성립하지 않는다. 두 키 사이에 충돌이 존재할 수 있다.)
    - 해시 값을 토대로 입력값을 유추하기 어렵다.
    - ex) DJB2, FNV-1, CRC32...
- hash table의 크기는 데이터의 수의 2배보다 큰 소수를 사용하는 것이 충돌이 날 가능성이 낮다. 

### 시간복잡도

* Average
    * 검색 - O(1)
    * 삽입 - O(1)
    * 삭제 - O(1)
* Worst
    * 검색 - O(n)
    * 삽입 - O(n)
    * 삭제 - O(n)
