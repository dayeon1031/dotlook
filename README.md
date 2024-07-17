<img src="./dotlook_banner.png" alt="dotlook_banner" style="width:100%; height:220px; object-fit:cover;">

# <img src="./dotlook_image.jpg" style="vertical-align:middle; width:50px; height:50px; margin-bottom: -30px;"> dotlook


시각 장애인들을 위해 실시간으로 책을 점자로 변환할 수 있게해주는 머신입니다. 라즈베리파이 카메라를 사용하여 책을 촬영하면 google vision의 OCR을 사용하여 텍스트를 검출합니다. 이후 OCR이 완벽하게 인식하지 못한 경우 Chat GPT를 사용하여 문장을 완성시킵니다.

## 개발자 소개
**김다연**  OCR검출, chat gpt 연동, 점자 출력 변환

**박정환**  하드웨어 설계 및 구동

**송정윤**  OCR검출, chat gpt 연동, 점자 출력 변환

**유서진**  하드웨어 설계 및 구동

**이은찬**  OCR검출, chat gpt 연동, 점자 출력 변환

### History
1. 안드로이드 스튜디오
  + 핸드폰으로 촬영 후 firebase에 사진을 올려 OCR및 점자변환을 진행하려고 함

> 실패이유 : 핸드폰으로 촬영 후 특정 파일에 저장이 불가함. 따라서 firebase에 사진을 올릴수 없음.
2. 라즈베리파이 사용

+ 사진 촬영 후 바로 OCR 사용 가능
> 라즈베리파이에 google 패키지를 설치하면 external error가 생김. 따라서 python 가상환경으로 패키지를 다운받음

+ 라즈베리파이에서 ChatGPT API를 활용하여 조명, 접힘으로 인한 문장의 오염된 훼손된 부분을 완성시킴
> 이 또한 패키지를 설치하면 external error 발생함. 따라서 python 가상환경으로 패키지를 다운받음
