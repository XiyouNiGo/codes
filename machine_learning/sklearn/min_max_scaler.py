import pandas
from sklearn.preprocessing import MinMaxScaler

def min_max_scaler():
  # 数据预处理：归一化（无量纲化）
  # 出现异常值时不稳定
  data = pandas.read_csv("test.csv")
  data = data.iloc[:, :3]
  tranfer = MinMaxScaler(feature_range=[2, 3])
  data_new = tranfer.fit_transform(data)
  print(data_new)
  return None

if __name__ == "__main__":
  min_max_scaler()