for file in ../Homework1/data/NewMCS10^7/L10*s1;
do
out=`basename $file`;
./auto.x 10 $file auto/$out;
done &

for file in ../Homework1/data/NewMCS10^7/L20*s1;
do
out=`basename $file`;
./auto.x 20 $file auto/$out;
done &

for file in ../Homework1/data/NewMCS10^7/L40*s1;
do
out=`basename $file`;
./auto.x 40 $file auto/$out;
done &

for file in ../Homework1/data/NewMCS10^7/L80*s1;
do
out=`basename $file`;
./auto.x 80 $file auto/$out;
done &
