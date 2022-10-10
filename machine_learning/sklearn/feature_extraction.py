from math import fabs
from sklearn.feature_extraction import DictVectorizer

def feature_extraction():
  # 字典向量特征提取
  # 类别转换为one-hot编码
  data = [{'city': '北京', 'temperature': "100"}, {'city': '上海', 'temperature': "60"}, {'city': '深圳', 'temperature': "30"}]
  # 转换器（不转换为稀疏矩阵）
  transfer = DictVectorizer(sparse=False)
  data_new = transfer.fit_transform(data)
  print("data_new:\n", data_new)
  print("feature_name:\n", transfer.get_feature_names)
  return None

if __name__ == "__main__":
  feature_extraction()