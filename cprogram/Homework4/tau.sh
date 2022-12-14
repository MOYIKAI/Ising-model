for file in ./auto/L10*s1;
do
out=`basename $file`;
./tau.x $file tau/$out;
done &

for file in ./auto/L20*s1;
do
out=`basename $file`;
./tau.x $file tau/$out;
done &

for file in ./auto/L40*s1;
do
out=`basename $file`;
./tau.x $file tau/$out;
done &

for file in ./auto/L80*s1;
do
out=`basename $file`;
./tau.x $file tau/$out;
done &
