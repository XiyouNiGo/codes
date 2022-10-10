from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split

def datasets_demo():
  iris = load_iris()
  # 划分训练集和测试集
  feat_train, test_train, feat_target, test_target = train_test_split(iris.data, iris.target, test_size = 0.2, random_state=22)
  print(feat_train, feat_train.data.shape)
  return None

if __name__ == "__main__":
  datasets_demo()