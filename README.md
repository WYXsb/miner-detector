# Introduction
Miner detector is used to detect miner malware, such as kinsing.

# Build
mkdir build & cd build
cmake ../src/c
make

# eBPF 程序劫持read系统调用
<p>仅仅对于comm = “test”的进程hook了read系统调用，它读/etc/passwd文件读到的内容是helloworld</p>
<p>源代码为/src/c中的 hello.c hello.h hello.bpf.c 。</p>
<p>编译前需要删除build目录，重新创建后再执行cmake的步骤。</p>
<p>运行/test目录下的test文件，会打开/etc/passwd.</p>

# 使用方法

<p>git checkout ResoucehijackDetect</p>
<p>rm -r ./build</p>
<p>mkdir build</p>
<p>cmake ../src/c </p>
<p>make hello </p>
<p>sudo ./hello [target_file_path] [target_comm]</p>
