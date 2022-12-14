for file in ../Homework1/data/NewMCS10^7/L10T*;
do
  out=`basename $file`
  T=`basename $file | sed 's/T/ /' | sed 's/h/ /' | awk '{print $2}'`
  for r in $(seq -w 1.60 0.04 1.90);
  do
    ./fine_tau2.x 10 $T 2.27 1.00 $r $file fine_tau2/v1.00r"$r""$out" tau/L10T2.40000h0.0s1;
  done
done &

for file in ../Homework1/data/NewMCS10^7/L20T*;
do
  out=`basename $file`
  T=`basename $file | sed 's/T/ /' | sed 's/h/ /' | awk '{print $2}'`
  for r in $(seq -w 1.60 0.04 1.90);
  do
    ./fine_tau2.x 20 $T 2.27 1.00 $r $file fine_tau2/v1.00r"$r""$out" tau/L20T2.40000h0.0s1;
  done
done &

for file in ../Homework1/data/NewMCS10^7/L40T*;
do
  out=`basename $file`
  T=`basename $file | sed 's/T/ /' | sed 's/h/ /' | awk '{print $2}'`
  for r in $(seq -w 1.60 0.04 1.90);
  do
    ./fine_tau2.x 40 $T 2.27 1.00 $r $file fine_tau2/v1.00r"$r""$out" tau/L40T2.40000h0.0s1;
  done
done &

for file in ../Homework1/data/NewMCS10^7/L80T*;
do
  out=`basename $file`
  T=`basename $file | sed 's/T/ /' | sed 's/h/ /' | awk '{print $2}'`
  for r in $(seq -w 1.60 0.04 1.90);
  do
    ./fine_tau2.x 80 $T 2.27 1.00 $r $file fine_tau2/v1.00r"$r""$out" tau/L80T2.40000h0.0s1;
  done
done &
