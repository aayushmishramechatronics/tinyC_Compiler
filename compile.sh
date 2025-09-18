make

file=$1

sfile=${file%%.*}
sfile=${sfile##*/}

./a.out $sfile.c || { exit 1; }

# echo $sfile

cc -c -m32 $sfile.s -o $sfile.o || { exit 1; }
cc -c -m32 compiler_assembly_print.c -o compiler_assembly_print.o || { exit 1; }
cc -m32 $sfile.o compiler_assembly_print.o -o $sfile.out || { exit 1; }
rm $sfile.o compiler_assembly_print.o