for file in ../Homework1/data/NewMCS10^7/L10T*;
do
  out=`basename $file`
  T=`basename $file | sed 's/T/ /' | sed 's/h/ /' | awk '{print $2}'`
  for v in $(seq -w 0.94 0.02 1.06);
  do
    ./fine_tau2.x 10 $T 2.27 $v 1.76 $file fine_tau2/v"$v"r1.76"$out" tau/L10T2.40000h0.0s1;
  done
done &

for file in ../Homework1/data/NewMCS10^7/L20T*;
do
  out=`basename $file`
  T=`basename $file | sed 's/T/ /' | sed 's/h/ /' | awk '{print $2}'`
  for v in $(seq -w 0.94 0.02 1.06);
  do
    ./fine_tau2.x 20 $T 2.27 $v 1.76 $file fine_tau2/v"$v"r1.76"$out" tau/L20T2.40000h0.0s1;
  done
done &
for file in ../Homework1/data/NewMCS10^7/L40T*;
do
  out=`basename $file`
  T=`basename $file | sed 's/T/ /' | sed 's/h/ /' | awk '{print $2}'`
  for v in $(seq -w 0.94 0.02 1.06);
  do
    ./fine_tau2.x 40 $T 2.27 $v 1.76 $file fine_tau2/v"$v"r1.76"$out" tau/L40T2.40000h0.0s1;
  done
done &
for file in ../Homework1/data/NewMCS10^7/L80T*;
do
  out=`basename $file`
  T=`basename $file | sed 's/T/ /' | sed 's/h/ /' | awk '{print $2}'`
  for v in $(seq -w 0.94 0.02 1.06);
  do
    ./fine_tau2.x 80 $T 2.27 $v 1.76 $file fine_tau2/v"$v"r1.76"$out" tau/L80T2.40000h0.0s1;
  done
done &
