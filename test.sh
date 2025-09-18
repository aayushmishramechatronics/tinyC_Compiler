make
cp ./compiler_assembly_print.c ./tests/compiler_assembly_print.c
cp ./myl.h ./tests/myl.h

#cc -Wall -S -m32 -fno-asynchronous-unwind-tables ass6_12CS30009_test.c -o test.s

cd tests

for i in {1..5}
do
file=ass6_12CS30009_test$i

../a.out $file.c
cp $file.s ass6_12CS30009_test.s

make
echo ""
echo $file.": ********************* Run starts *******************************"
echo ""
./a.out
echo ""
echo $file.": ******************** Run finished ******************************"
echo ""
make clean
done

rm myl.h compiler_assembly_print.c ass6_12CS30009_test.s

cd ..