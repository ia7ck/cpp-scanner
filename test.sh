for f in *.in
do
  g++ ${f%.*}_test.cpp -std=c++11 && ./a.out < $f
done
