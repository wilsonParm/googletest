## 1. 生成所需gtest.a和.h文件

- 参考文档[CONTRIBUTING.md](../CONTRIBUTING.md) 里面的`Developing Google Test and Google Mock`
```shell
mkdir mybuild
cd mybuild
cmake -Dgtest_build_tests=ON -Dgmock_build_tests=ON ${GTEST_REPO_DIR} 
```

- #↑这里不要Dgmock_build_tests=ON只要Dgtest_build_tests
- GTEST_REPO_DIR} 为gtest目标文件夹 = .即可
- 所以执行以下，即可生成.a和.h文件

```shell
mkdir mybuild
cd mybuild
cmake -Dgtest_build_tests=ON .
make;make install
```

~~卧槽.h呢~~

- {ws} = /googletest `workspace` 

  复制ws/googletest/include到project目录 `.h文件`

  复制ws/mybuild/lib到project目录 `.a文件`

## 2.使用cmake生成工程makefile

- 可以通过cmake来生成makefile，或者自己编写

- 项目目录为{project}

- 创建CMakeLists.txt文件并编写执行

  ```shell
  {projuect} $ vi CMakeLists.txt
  					mkdir cmake && cd cmake #创建执行文件目录cmake，目录名随便
  					cmake .. 	#目标为上级目录的CMakeLists.txt
  					make
  					./main		#执行生成文件
  ```

  

- 创建执行文件所在文件夹/bin

  