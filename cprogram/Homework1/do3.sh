for T4 in $(seq -w 1.9640 0.002 2.40);
do
./Modify-Ising2Dex-2.x 80 $T4 0 -200000 6464000000 > data/L80T"$T4"h0.0s0;
./Modify-Ising2Dex-2.x 80 $T4 0 -200001 6464000000 > data/L80T"$T4"h0.0s1;
done &

for T6 in $(seq -w 1.9640 0.002 2.40);
do
./Modify-Ising2Dex-2.x 80 $T6 0 -200003 6464000000 > data/L80T"$T6"h0.0s3;
./Modify-Ising2Dex-2.x 80 $T6 0 -200004 6464000000 > data/L80T"$T6"h0.0s4;
done &

for T8 in $(seq -w 1.9640 0.002 2.40);
do
./Modify-Ising2Dex-2.x 80 $T8 0 -200007 6464000000 > data/L80T"$T8"h0.0s7;
./Modify-Ising2Dex-2.x 80 $T8 0 -200008 6464000000 > data/L80T"$T8"h0.0s8;
done &

for T10 in $(seq -w 1.9640 0.002 2.40);
do
./Modify-Ising2Dex-2.x 80 $T10 0 -200002 6464000000 > data/L80T"$T10"h0.0s2;
./Modify-Ising2Dex-2.x 80 $T10 0 -200009 6464000000 > data/L80T"$T10"h0.0s9;
done &

for T12 in $(seq -w 1.9640 0.002 2.40);
do
./Modify-Ising2Dex-2.x 80 $T12 0 -200005 6464000000 > data/L80T"$T12"h0.0s5;
./Modify-Ising2Dex-2.x 80 $T12 0 -200006 6464000000 > data/L80T"$T12"h0.0s6;
done &
