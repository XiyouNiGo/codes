from sklearn.datasets import load_iris

def datasets_demo():
  iris = load_iris()
  print("iris datasets:\n", iris)
  print("desciption:\n", iris["DESCR"])
  print("feature name:\n", iris.feature_names)
  print("data:\n", iris.data, iris.data.shape)
  return None

# 作为模块被导入时不生效
if __name__ == "__main__":
  datasets_demo()