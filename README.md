<img src="./dotlook_banner.png" alt="Main Screen" />

# <img src="./dotlook_image.jpg" alt="magnifying_glass" style="vertical-align:middle; width:50px; height:50px; transform: translateY(50px);"> dotlook


**dotlook**는 시각 장애인들을 위해 책을 실시간으로 점자로 변환해주는 머신입니다. 라즈베리파이 카메라로 책을 촬영하면 Google Vision의 OCR을 사용하여 텍스트를 검출하고, ChatGPT를 통해 인식되지 않은 문장을 완성합니다.


## 개발자 소개
**김다연** - OCR 검출, ChatGPT 연동, 점자 출력 변환  
**박정환** - 하드웨어 설계 및 구동  
**송정윤** - OCR 검출, ChatGPT 연동, 점자 출력 변환  
**유서진** - 하드웨어 설계 및 구동  
**이은찬** - OCR 검출, ChatGPT 연동, 점자 출력 변환  


## 작품명
**시각장애인을 위한 도서관 도우미 보드**


## 배경
현대 사회에서 정보 접근성은 모든 사람의 기본적인 권리입니다. 그러나 시각장애인들은 인쇄된 책이나 문서에 접근하기 어려워 많은 불편을 겪고 있습니다. 정보의 접근성 부족은 시각장애인들의 학습, 직업 기회, 일상 생활 등에 큰 제약을 초래합니다.

기존의 기술적 수단들은 여전히 많은 한계와 비용 문제가 있습니다. 예를 들어, '한소네'와 같은 특수 독서 보조기기는 약 400만 원으로 매우 고가이며, 시각장애인들이 이를 구매하여 사용하기에는 큰 경제적 부담이 됩니다.


## 동기
시각장애인들이 더 나은 정보 접근성을 가질 수 있도록 하는 것은 매우 중요한 문제입니다. 현재 시중에 출시된 오디오북은 선택의 폭이 좁고, 모든 책이 등록되어 있지 않으며, 필기와 같은 기능 사용에 어려움이 있습니다. 이러한 문제를 해결하기 위해서는 보다 저렴하고 효율적인 해결책이 필요합니다.

저희 팀은 이러한 필요성을 인식하고 시각장애인들이 독서를 통해 학습하고 여가를 즐길 수 있는 기회를 제공하고자 본 프로젝트를 시작하게 되었습니다. 시각장애인들이 다양한 책을 쉽게 접근할 수 있도록 하기 위해 실시간 점자 변환 기능을 갖춘 도서관 도우미 보드를 개발하게 되었습니다.


## 목적 및 필요성
저희의 주된 목적은 시각장애인들이 어떤 책이든 즉석에서 점자로 변환하여 읽을 수 있도록 하는 것입니다. 이 도서관 도우미 보드는 책의 이미지를 찍기만 하면 자동으로 점자로 변환하여 실시간으로 점자 보드에서 읽을 수 있도록 합니다. 이를 통해 시각장애인들은 독서를 통해 학습하고 여가를 즐길 수 있는 기회를 확대할 수 있습니다.

이 기술은 비용과 시간을 절약할 뿐만 아니라, 시각장애인들이 독서 경험을 개선하고 정보 접근성을 높이는 데 큰 기여를 할 것입니다. 저희 프로젝트는 시각장애인들에게 실질적인 도움을 제공하려는 혁신적인 시도로서, 정보 접근성을 높이고 시각장애인들의 일상 생활에 큰 변화를 가져올 것입니다.


## 문제점 및 기존의 해결방법
시각장애인이 직면한 주된 문제는 시각적 정보에 대한 접근성 부족입니다. 현재 시장에는 이를 해결하기 위한 몇 가지 방법이 존재하나, 각각이 가진 한계점이 명확합니다:
- 고가의 독서 보조기기인 '한소네'는 400만 원에 육박하는 비용
- 오디오북은 모든 책을 커버하지 못하며, 메모 및 반복 청취에 불편함
- 점자 책은 제작 비용이 높고 시간이 오래 걸림


## 돋(dot)보기 팀의 해결방법
### 기술적 접근
저희 팀은 3D 프린터로 제작한 하드웨어와 라즈베리파이를 사용하여 책의 이미지를 촬영하고 Google Vision의 OCR 기술을 활용하여 텍스트를 추출합니다. 사용자는 겉표지 촬영 후 대략적인 내용을 받아 올 수 있습니다. 책 내용중 추출된 텍스트는 라즈베리파이에서 OCR 변환을 진행한 후, 오염된 글자를 Chat GPT API를 사용해 복원시킵니다. 아두이노로 정보를 전송하여 점자를 실시간으로 표시합니다.

### 점자 변환
점자 변환 알고리즘은 한글의 자모를 분리하여 초성, 중성, 종성 각각에 맞는 점자 코드를 할당하는 방식으로 작동합니다. 이는 hgtk 라이브러리를 사용하여 한글을 분해하고, 각 자모에 대해 미리 정의된 점자 매칭 테이블을 참조합니다. 

### 오타 수정 및 문장 보완
OCR로 추출한 텍스트는 불빛이나 책의 접힘 등으로 인해 정확하지 않을 수 있습니다. 이를 보완하기 위해 OpenAI의 GPT-3.5-turbo 모델을 사용하여 문장의 오타를 수정하고, 불완전한 문장을 완성합니다. 이를 통해 더 정확하고 읽기 쉬운 점자로 변환됩니다.

### 3D프린터로 설계한 점자책
휴대성은 떨어질수 있으나 도서관 혹은 공공기관에 설치할 목적으로 설계. 모터 6개를 사용하여 점자를 표현하기 때문에 비용이 크게 발생하지 않습니다.

### 라즈베리파이 보드를 사용하여 다양한 기능을 제시
hgtk 라이브러리를 사용하여 점자로 변환하는 것은 기본적인 기능입니다. 또한 겉표지를 촬영하면 책의 대략적인 줄거리를 알려주는 기능이 있어 사용자가 책을 읽은것인지 아닌지 쉽게 판단할 수 있습니다.


## 기능
- **책 표지 설명:** Open GPT API를 이용하여 책 표지만으로 간단한 설명 제공
  - 예: "죽고싶지만 떡볶이는 먹고 싶어"는 백세희의 에세이로, 현대인들의 삶과 내면을 다룬 책입니다.
- **빠른 OCR 변환:** 버튼을 눌러 사진 촬영 후 즉시 OCR 변환 및 점자 모듈에 점자 구현
- **문장 오류 수정:** OCR 변환 시 조명, 책 접힘으로 인한 오류를 GPT API가 수정
- **자동 책 넘김:** 한 페이지의 OCR 변환이 끝나면, 진동 센서로 알림 후 자동 책 넘김 장치로 다음 페이지 이동

이 시스템은 비용 효율성과 사용 편의성을 동시에 증진시키며, 시각장애인들의 정보 접근성과 독서 경험을 개선합니다.

## 사용된 기술
**google vision OCR api:** 텍스트를 추출합니다. 예) 책의 제목, 책의 내용, 저자, 출판사
**OpenAI api:** 제목을 촬영한다면 책의 내용을 알려줍니다. 텍스트를 받는 경우 훼손된 글자를 복원시켜줍니다.
**hgtk:** 온전한 문장을 점자로 변환시켜줍니다.
**하드웨어: ** 3D프린터로 설계하였습니다. (하드웨어친구들 설명필요)
