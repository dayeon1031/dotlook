import os
import io  # 정규 표현식 모듈 추가
import openai

# JSON 파일 경로 설정
os.environ["GOOGLE_APPLICATION_CREDENTIALS"] = "/home/jeongyun/final.json"
from google.cloud import vision

# OpenAI API 키 설정
#OPENAI_API_KEY = "your_path"
#openai.api_key = OPENAI_API_KEY

# 사용할 모델 설정
model = "gpt-3.5-turbo"

# 이미지에서 텍스트를 추출하고 점자로 변환하는 전체 프로세스
client = vision.ImageAnnotatorClient()
path = r'/home/jeongyun/test6.jpg'

with io.open(path, 'rb') as image_file:
    content = image_file.read()

image = vision.Image(content=content)
response = client.text_detection(image=image)
texts = response.text_annotations

print("변환전 : "+texts[0].description)


# 사용자 질문 설정
query = texts[0].description + "\n 문장을 내가 준 그대로 출력하되, 오타만 수정해서 출력해줘. "

# 메시지 리스트 설정
messages = [
    {
        "role": "system",
        "content": "내가 보내줄 문장은 책에서 OCR을 돌린 문장들이야. 하지만 불빛, 책의 접힘 때문에 글자에 오타가 좀 있을 수도 있어. 그럼 글자 그대로 출력하되, 오타만 수정해서 보내줘. 특수문자도 삭제나 변경하지 말고 그대로 출력해줘\n"
    },
    {
        "role": "user",
        "content": query
    }
]

# OpenAI API 호출
response = openai.ChatCompletion.create(
    model=model,
    messages=messages
)

# 응답 출력
answer = response['choices'][0]['message']['content']
print("변환후 : "+answer)
