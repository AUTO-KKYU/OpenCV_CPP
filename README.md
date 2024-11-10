## [OPENCV][C++] OpenCV Install 

1. OpenCV Library 설치
  - https://opencv.org/releases/
  - 자신의 환경에 맞게 ex) Windows, iOS Pack, Android, ...
  - 폴더 구조 확인 및 핵심 opencv 라이브러리 위치 확인
      - opencv\build\x64\vc14 or vc15 or vc 16, ..\lib
          - opencv_world000d.lib
          - opencv_world000.lib
      - opencv\build\include
          - opencv 라이브러리용 헤더 파일들 
2. Visual Studio Code에서 C++ Project 생성
  - 파일 ⭢ 새로만들기 ⭢ Project
  - 빈 프로젝트 선택
  - 생성 후, 프로젝트 구성 선택 (빌드 ⭢ 구성관리자 메뉴)
      - Debug, X64 되도록 활성화  
3. 생성한 Project 속성 설정
  - 추가 포함 디렉토리 (구성 속성 ⭢ VC++ 디렉토리)
      - opencv\build\include\opencv2
      - opencv\build\include   
  - 추가 라이브러리 디렉토리 (링커 ⭢ 일반)
      - opencv\build\x64\vc14 or vc15 or vc16, ..\lib
  - 추가 종속성 (링커 ⭢ 입력)
      - opencv_world000d.lib
4. C:\Windows\SysWOW64 해당 위치에 dll 파일들 전부다 넣기
5. 추가적으로 dll 관련된 문제 발생 시, 환경 변수에 들어가 아래 사진과 같이 셋팅하면 된다

| ![스크린샷 2024-11-10 203732](https://github.com/user-attachments/assets/96e75777-1fca-40f2-9b34-dde2824c08f8) | ![스크린샷 2024-11-10 204032](https://github.com/user-attachments/assets/0d4ea72f-4ef4-4d43-83a9-8ba48f26a47a)|
| --- | --- |



