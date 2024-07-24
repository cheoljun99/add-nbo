# 컴파일러 설정
CC = gcc

# 컴파일러 옵션
CFLAGS = -Wall

# 대상 파일
TARGET = main

# 소스 파일
SRC = main.c

#파일 생성
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) 

#삭제
clean:
	rm -f $(TARGET)