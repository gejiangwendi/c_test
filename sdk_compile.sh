#清除旧版本
rm ./out/source/*.o
rm ./out/lib.a
rm main.app
printf 'delete old output files ... ...\n\n'

i=0

#编译sdk文件夹内的所有.c文件
for file in ./sdk/dh_*.c; do
    let "i=i+1"
    printf 'compile %s ...\n' "$file"
    gcc -c $file -o ./out/source/file_$i.o
    sleep 0.005   #5ms
done

printf '... ...\n'
#链接所有.o文件生成lib.a库
ar -r ./out/lib.a ./out/source/file_*.o

#编译main.c 链接库 生成可执行文件
gcc -o main.app main.c ./out/lib.a 
printf '\nok! new main.app is created.\n\n'




