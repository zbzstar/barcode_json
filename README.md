# 读取条码
## 依赖项
- opencv
- zbar(sudo apt-get install libzbar-dev)
- jsoncpp  
   安装：https://blog.csdn.net/deyuzhi/article/details/51747221
   安装包在dependences下
## 编译
mkdir build  
cd build  
cmake..  
make  

提取依赖库文件，做静态链接  
cp ../tmp.sh ../barcode.sh .   
./tmp.sh
## 运行
./barcode.sh ../imgs/barcode_2.jpg
## 输出
{
   "output" : {
      "code_type" : "CODE-128",
      "decode_string" : "6944910334609",
      "pic_name" : "../imgs/barcode_2.jpg"
   }
}

