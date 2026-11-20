import requests
import pandas as pd

headers = {
	"Authorization":"Bearer xyz123",
}

params = {
	"userId":1
}

response = requests.get(
    "https://jsonplaceholder.typicode.com/users?username=Delphine",
    params=params,
    headers=headers
)

data = response.json()

df = pd.DataFrame(data)
print(df.head())

# df.to_csv("users.csv", index=False)

# print("Data extracted and saved to users.csv")