from google.cloud import storage
import os

# 환경 변수 설정 (스크립트 내에서 설정하는 방법)
os.environ["GOOGLE_APPLICATION_CREDENTIALS"] = "/home/jeongyun/final.json"

def test_google_api():
    try:
        # 클라이언트 초기화
        storage_client = storage.Client()
       
        # 버킷 목록 가져오기
        buckets = list(storage_client.list_buckets())
       
        # 버킷 목록 출력
        print("Buckets:", buckets)
       
    except Exception as e:
        print(f"An error occurred: {e}")

# 함수 실행
test_google_api()
