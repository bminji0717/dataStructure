# 시간복잡도
## 피보나치 복잡도
#### fibonacci()는 호출될 때마다 자기 자신을 두 번 다시 호출함.
#### 따라서 n이 증가할 수록 재귀호출 횟수 급격히 증가, cpu 사용량도 함께 증가.
####
#### n=5, n=10의 경우, fibonacci() 호출 횟수가 적어 cpu 사용량이 낮음.
#### https://github.com/bminji0717/dataStructure/blob/main/screenshot/5.png
#### https://github.com/bminji0717/dataStructure/blob/main/screenshot/10.png
####
#### n=30부터 n=40의 경우, cpu 사용량이 급증하는 것을 확인 가능.
#### (15 → 30 → 38 → 64 → 109 → 160 → 258 → 459 → 697 → 1172 → 1832)
#### https://github.com/bminji0717/dataStructure/blob/main/screenshot/30.png
#### https://github.com/bminji0717/dataStructure/blob/main/screenshot/31.png
#### https://github.com/bminji0717/dataStructure/blob/main/screenshot/32.png
#### https://github.com/bminji0717/dataStructure/blob/main/screenshot/33.png
#### https://github.com/bminji0717/dataStructure/blob/main/screenshot/34.png
#### https://github.com/bminji0717/dataStructure/blob/main/screenshot/35.png
#### https://github.com/bminji0717/dataStructure/blob/main/screenshot/36.png
#### https://github.com/bminji0717/dataStructure/blob/main/screenshot/37.png
#### https://github.com/bminji0717/dataStructure/blob/main/screenshot/38.png
#### https://github.com/bminji0717/dataStructure/blob/main/screenshot/39.png
#### https://github.com/bminji0717/dataStructure/blob/main/screenshot/40.png
#### 위 측정치는 피보나치 수열과 엇비슷한 형태를 보임
####
### 실제 cpu 사용량 대부분을 fibonacci 함수가 차지, 그 이유는 재귀호출
#### fibonacci 함수는 한 번 호출되면 두 번의 재귀호출 실행, 트리 구조
### 따라서 피보나치 수열의 시간복잡도는 O(x^n)
##
## GCD의 복잡도
#### 피보나치 수열의 GCD를 구하는 프로그램의 코드를 아래와 같이 수정하여 디버깅 하였을 때,
#### https://github.com/bminji0717/dataStructure/blob/main/screenshot/20260331Code2.png
#### n=5
#### https://github.com/bminji0717/dataStructure/blob/main/screenshot/20260331(1)(1).png
#### https://github.com/bminji0717/dataStructure/blob/main/screenshot/20260331(1)(2).png
#### n=10
#### https://github.com/bminji0717/dataStructure/blob/main/screenshot/20260331(2)(1).png
#### https://github.com/bminji0717/dataStructure/blob/main/screenshot/20260331(2)(2).png
#### n=20
#### https://github.com/bminji0717/dataStructure/blob/main/screenshot/20260331(3)(1).png
#### https://github.com/bminji0717/dataStructure/blob/main/screenshot/20260331(3)(2).png
#### n=100을 넣었을 때는 오버플로우 발생. (long long 범위 초과)
#### 그에 근접한 80, 90을 넣었을 때 아래와 같은 결과가 나옴.
#### https://github.com/bminji0717/dataStructure/blob/main/screenshot/20260331(4)(1).png
#### https://github.com/bminji0717/dataStructure/blob/main/screenshot/20260331(4)(2).png
#### https://github.com/bminji0717/dataStructure/blob/main/screenshot/20260331(5)(1).png
#### https://github.com/bminji0717/dataStructure/blob/main/screenshot/20260331(5)(2).png
####
#### n=5일 때와 n=90일 때 계산 과정의 횟수 차이가 크지 않음 (연산 증가량이 미미함)
### 이는 유클리드 호제법을 사용한 GCD 산출 과정에서, 계산 대상인 피보나치 수열의 값이 큼에도, GCD를 구하기 위한 CPU 사용량은 미미하게 증가하였음을 뜻함.
### 따라서 과제1에서 예측한 GCD의 복잡도 O(logN)은 옳은 판단이었을 것.
