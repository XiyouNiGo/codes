from setuptools import setup, find_packages
 
setup(
    name="example",  # 包名
    version="1.0.0",  # 版本号
    author="Your Name",  # 作者名字
    author_email="you@example.com",  # 作者邮箱
    description="A short description of this project",  # 描述
    long_description="A longer description of this project",  # 详细描述
    url="https://github.com/yourusername/example",  # 主页 URL
    packages=find_packages(),  # 包列表
    install_requires=["numpy", "scipy"],  # 运行时依赖关系
    classifiers=[
        "Development Status :: 3 - Alpha",
        "Intended Audience :: Developers",
        "License :: OSI Approved :: MIT License",
        "Operating System :: OS Independent",
        "Programming Language :: Python :: 3",
        "Programming Language :: Python :: 3.6",
        "Programming Language :: Python :: 3.7",
        "Programming Language :: Python :: 3.8",
        "Topic :: Software Development :: Libraries :: Python Modules",
    ],  # 分类标签
)