#获取依赖文件并重定向输出到文件
ldd barcode > lib1.txt
#获取依赖文件路径
awk '{print $3}' lib1.txt > lib2.txt
#逐行拷贝到当前文件夹
cat lib2.txt | while read line
 
do
 echo "line->${line}"
 cp $line ./
done
rm lib1.txt lib2.txt
