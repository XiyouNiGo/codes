from math import fabs
from sklearn.feature_extraction.text import CountVectorizer

def count_vectorizer():
  # 文本向量特征提取
  # 类别转换为one-hot编码
  data = ["life is short", "life is beautiful"]
  # 转换器（不转换为稀疏矩阵）
  transfer = CountVectorizer(stop_words=["to"]) # 停用词语
  data_new = transfer.fit_transform(data)
  print("data_new:\n", data_new.toarray())
  print("feature_name:\n", transfer.get_feature_names())
  return None

if __name__ == "__main__":
  count_vectorizer()