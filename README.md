# KIB_c_game_project
cmake project examples


# 2024-03-19 화
---
화, 수 -> 공통학습
목, 금 -> 프로젝트, 금요일엔 발표 1시간

1. github repo 하나 만들어서 프로젝트 진행
2. 발표는 PPT로 만들기(구글 슬라이드)
3. 프로젝트 기술서(어떤 언어를 썼고, 참고한 사이트, 결과물 사진 등등)
  역할이 중요하다
4. 문서화 작업 - file, class, struct, 변수 ...

프로그램 시작에는 항상 소스폴더를 만들기 src

소스 - 빌드 - 바이너리 - 배포
  배포는 알리기, pip, npm, apt -> 궁극적으로 실행파일 재배치
usr/local/(bin, include, src)
make install -> 자동으로 만든 바이너리 파일을 옮겨준다

게임로직 -> 실행흐름 Thread
                    interrupt

1. display_tetris -> 60hz로 실행되도록
  interrupt -> SIGNAL 설정

2. 키보드 입력
  ch = getch() 함수를 만들어서 사용(실시간으로 키보드를 받을 수 있는 기능)