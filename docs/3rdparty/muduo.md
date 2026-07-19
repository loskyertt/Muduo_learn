# 1. 源码下载

[muduo 源码](https://github.com/chenshuo/muduo)

```shell
git clone https://github.com/chenshuo/muduo.git
```

---

# 2. 构建和安装

1. **构建**：

```shell
cmake -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=./install -DCMAKE_POLICY_VERSION_MINIMUM=3.5 -DMUDUO_BUILD_EXAMPLES=OFF 
```

`-DCMAKE_INSTALL_PREFIX=./install` 表示安装到当前目录下的 `install` 目录中。

可以执行下面这条命令查看 cmake 构建时的选项：

```shell
cmake -B build -LAH
```

2. **编译**：

```shell
cmake --build build/ -j4
```

在编译时可能会遇到这种错误：

```text
      • conversion of argument 1 would be ill-formed:
      • error: invalid conversion from ‘const char*’ to ‘char*’ [-fpermissive]
        /usr/include/absl/strings/resize_and_overwrite.h:140:64:
          140 |       static_cast<typename T::size_type>(std::move(op)(str.data(), n));
              |                                                        ~~~~~~~~^~
              |                                                                |
              |                                                                const char*
ninja: build stopped: subcommand failed.
```

这通常是 muduo 库的 CMakeLists.txt 中 C++ 标准设置太低，事实上 muduo-2.0.2 中设置的是 `-std=c++11`。因此，只需修改 `./CMakeLists.txt` 中的这部分：

```cmake
set(CXX_FLAGS
 -g
 # -DVALGRIND
 -DCHECK_PTHREAD_RETURN_VALUE
 -D_FILE_OFFSET_BITS=64
 -Wall
 -Wextra
 -Werror
 -Wconversion
 -Wno-unused-parameter
 -Wold-style-cast
 -Woverloaded-virtual
 -Wpointer-arith
 -Wshadow
 -Wwrite-strings
 -march=native
 # -MMD
 -std=c++11  <- 改这里
 -rdynamic
 )
```

把 `-std=c++11` 改为 `-std=c++17` 即可。

如果遇到和编译 exmaples 目录下的源码相关的错误，建议再把这部分注释掉：

```cmake
if(MUDUO_BUILD_EXAMPLES)
  add_subdirectory(contrib)
  add_subdirectory(examples)
else()
  if(CARES_INCLUDE_DIR AND CARES_LIBRARY)
    add_subdirectory(examples/cdns)
  endif()
endif()
```

3. **安装**：

```shell
cmake --install build/
```

目录结构：

```text
install/
├── include
│   └── muduo
│       ├── base
│       │   ├── AsyncLogging.h
│       │   ├── Atomic.h
│       │   ├── BlockingQueue.h
│       │   ├── BoundedBlockingQueue.h
│       │   ├── Condition.h
│       │   ├── copyable.h
│       │   ├── CountDownLatch.h
│       │   ├── CurrentThread.h
│       │   ├── Date.h
│       │   ├── Exception.h
│       │   ├── FileUtil.h
│       │   ├── GzipFile.h
│       │   ├── LogFile.h
│       │   ├── Logging.h
│       │   ├── LogStream.h
│       │   ├── Mutex.h
│       │   ├── noncopyable.h
│       │   ├── ProcessInfo.h
│       │   ├── Singleton.h
│       │   ├── StringPiece.h
│       │   ├── Thread.h
│       │   ├── ThreadLocal.h
│       │   ├── ThreadLocalSingleton.h
│       │   ├── ThreadPool.h
│       │   ├── Timestamp.h
│       │   ├── TimeZone.h
│       │   ├── Types.h
│       │   └── WeakCallback.h
│       └── net
│           ├── Buffer.h
│           ├── Callbacks.h
│           ├── Channel.h
│           ├── Endian.h
│           ├── EventLoop.h
│           ├── EventLoopThread.h
│           ├── EventLoopThreadPool.h
│           ├── http
│           │   ├── HttpContext.h
│           │   ├── HttpRequest.h
│           │   ├── HttpResponse.h
│           │   └── HttpServer.h
│           ├── InetAddress.h
│           ├── inspect
│           │   └── Inspector.h
│           ├── TcpClient.h
│           ├── TcpConnection.h
│           ├── TcpServer.h
│           └── TimerId.h
└── lib
    ├── libmuduo_base.a
    ├── libmuduo_http.a
    ├── libmuduo_inspect.a
    └── libmuduo_net.a

8 directories, 49 files
```

这里需要自己写 `Findmuduo.cmake` 或者 `muduoConfig.cmake` 脚本。
