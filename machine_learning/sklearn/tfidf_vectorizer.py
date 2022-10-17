# TF:词频 IDF:逆向文档频率
# 作用：评估一个字词对于一个文件集中的一份文件的重要程度
from math import fabs
from sklearn.feature_extraction.text import TfidfVectorizer

def count_vectorizer():
  # 文本向量特征提取
  # 类别转换为one-hot编码
  data = ["life is short", "life is beautiful"]
  # 转换器（不转换为稀疏矩阵）
  transfer = TfidfVectorizer()
  data_new = transfer.fit_transform(data)
  print("data_new:\n", data_new.toarray())
  print("feature_name:\n", transfer.get_feature_names())
  return None

if __name__ == "__main__":
  count_vectorizer()