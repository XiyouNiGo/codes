import pandas
from sklearn.preprocessing import StandardScaler

def standard_scaler():
  # 数据预处理：标准化（范围-1~1）
  # 出现异常值时稳定
  data = pandas.read_csv("test.csv")
  data = data.iloc[:, :3]
  tranfer = StandardScaler(feature_range=[2, 3])
  data_new = tranfer.fit_transform(data)
  print(data_new)
  return None

if __name__ == "__main__":
  standard_scaler()