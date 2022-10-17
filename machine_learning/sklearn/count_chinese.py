import jieba
from sklearn.feature_extraction.text import CountVectorizer

def cut_word(text):
  # 中文文本特征抽取
  return " ".join(list(jieba.cut(text)))

def count_chinese():
  data = ["纵然青史已经成灰",
  "我爱不灭 繁华如三千东流水",
  "我只取一瓢爱了解 只恋你化身的蝶"]
  data_new = []
  for text in data:
    data_new.append(cut_word(text))
  transfer = CountVectorizer()
  data_new = transfer.fit_transform(data_new)
  print("data_new:\n", data_new.toarray())
  print("feature_name:\n", transfer.get_feature_names_out())

  return None

if __name__ == "__main__":
  count_chinese()
  # print(cut_word("纵然青史已经成灰"))