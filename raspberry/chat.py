import openai

# OpenAI API 키 설정
#OPENAI_API_KEY = "your_path"
#openai.api_key = OPENAI_API_KEY

# 사용할 모델 설정
model = "gpt-3.5-turbo"

# 사용자 질문 설정
query = "tell me about konkuk univercity"

# 메시지 리스트 설정
messages = [
    {
        "role": "system",
        "content": "You are a helpful assistant"
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
print(answer)
