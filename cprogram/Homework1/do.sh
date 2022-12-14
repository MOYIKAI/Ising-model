for T1 in $(seq -w 1.80 0.07 2.50);
do
./Modify-Ising2Dex-2.x 10 $T1 0 -200000 1010000000 > data/L10T"$T1"h0.0s0;
./Modify-Ising2Dex-2.x 10 $T1 0 -200001 1010000000 > data/L10T"$T1"h0.0s1;
./Modify-Ising2Dex-2.x 10 $T1 0 -200002 1010000000 > data/L10T"$T1"h0.0s2;
./Modify-Ising2Dex-2.x 10 $T1 0 -200003 1010000000 > data/L10T"$T1"h0.0s3;
./Modify-Ising2Dex-2.x 10 $T1 0 -200004 1010000000 > data/L10T"$T1"h0.0s4;
./Modify-Ising2Dex-2.x 10 $T1 0 -200005 1010000000 > data/L10T"$T1"h0.0s5;
./Modify-Ising2Dex-2.x 10 $T1 0 -200006 1010000000 > data/L10T"$T1"h0.0s6;
./Modify-Ising2Dex-2.x 10 $T1 0 -200007 1010000000 > data/L10T"$T1"h0.0s7;
./Modify-Ising2Dex-2.x 10 $T1 0 -200008 1010000000 > data/L10T"$T1"h0.0s8;
./Modify-Ising2Dex-2.x 10 $T1 0 -200009 1010000000 > data/L10T"$T1"h0.0s9;
done &

for T2 in $(seq -w 1.80 0.035 2.50);
do
./Modify-Ising2Dex-2.x 20 $T2 0 -200000 4004000000 > data/L20T"$T2"h0.0s0;
./Modify-Ising2Dex-2.x 20 $T2 0 -200001 4004000000 > data/L20T"$T2"h0.0s1;
./Modify-Ising2Dex-2.x 20 $T2 0 -200002 4004000000 > data/L20T"$T2"h0.0s2;
./Modify-Ising2Dex-2.x 20 $T2 0 -200003 4004000000 > data/L20T"$T2"h0.0s3;
./Modify-Ising2Dex-2.x 20 $T2 0 -200004 4004000000 > data/L20T"$T2"h0.0s4;
./Modify-Ising2Dex-2.x 20 $T2 0 -200005 4004000000 > data/L20T"$T2"h0.0s5;
./Modify-Ising2Dex-2.x 20 $T2 0 -200006 4004000000 > data/L20T"$T2"h0.0s6;
./Modify-Ising2Dex-2.x 20 $T2 0 -200007 4004000000 > data/L20T"$T2"h0.0s7;
./Modify-Ising2Dex-2.x 20 $T2 0 -200008 4004000000 > data/L20T"$T2"h0.0s8;
./Modify-Ising2Dex-2.x 20 $T2 0 -200009 4004000000 > data/L20T"$T2"h0.0s9;
done &

for T3 in $(seq -w 1.80 0.0175 2.50);
do
./Modify-Ising2Dex-2.x 40 $T3 0 -200000 16160000000 > data/L40T"$T3"h0.0s0;
./Modify-Ising2Dex-2.x 40 $T3 0 -200001 16160000000 > data/L40T"$T3"h0.0s1;
./Modify-Ising2Dex-2.x 40 $T3 0 -200002 16160000000 > data/L40T"$T3"h0.0s2;
./Modify-Ising2Dex-2.x 40 $T3 0 -200003 16160000000 > data/L40T"$T3"h0.0s3;
./Modify-Ising2Dex-2.x 40 $T3 0 -200004 16160000000 > data/L40T"$T3"h0.0s4;
done &
for T5 in $(seq -w 1.80 0.0175 2.50);
do
./Modify-Ising2Dex-2.x 40 $T5 0 -200005 16160000000 > data/L40T"$T5"h0.0s5;
./Modify-Ising2Dex-2.x 40 $T5 0 -200006 16160000000 > data/L40T"$T5"h0.0s6;
./Modify-Ising2Dex-2.x 40 $T5 0 -200007 16160000000 > data/L40T"$T5"h0.0s7;
./Modify-Ising2Dex-2.x 40 $T5 0 -200008 16160000000 > data/L40T"$T5"h0.0s8;
./Modify-Ising2Dex-2.x 40 $T5 0 -200009 16160000000 > data/L40T"$T5"h0.0s9;
done &


for T4 in $(seq -w 1.840 0.002 2.40);
do
./Modify-Ising2Dex-2.x 80 $T4 0 -200000 6464000000 > data/L80T"$T4"h0.0s0;
./Modify-Ising2Dex-2.x 80 $T4 0 -200001 6464000000 > data/L80T"$T4"h0.0s1;
done &
for T6 in $(seq -w 1.840 0.002 2.40);
do
./Modify-Ising2Dex-2.x 80 $T6 0 -200003 6464000000 > data/L80T"$T6"h0.0s3;
./Modify-Ising2Dex-2.x 80 $T6 0 -200004 6464000000 > data/L80T"$T6"h0.0s4;
done &
for T8 in $(seq -w 1.840 0.002 2.40);
do
./Modify-Ising2Dex-2.x 80 $T8 0 -200007 6464000000 > data/L80T"$T8"h0.0s7;
./Modify-Ising2Dex-2.x 80 $T8 0 -200008 6464000000 > data/L80T"$T8"h0.0s8;
done &
for T10 in $(seq -w 1.840 0.002 2.40);
do
./Modify-Ising2Dex-2.x 80 $T10 0 -200002 6464000000 > data/L80T"$T10"h0.0s2;
./Modify-Ising2Dex-2.x 80 $T10 0 -200009 6464000000 > data/L80T"$T10"h0.0s9;
done &
for T12 in $(seq -w 1.840 0.002 2.40);
do
./Modify-Ising2Dex-2.x 80 $T12 0 -200005 6464000000 > data/L80T"$T12"h0.0s5;
./Modify-Ising2Dex-2.x 80 $T12 0 -200006 6464000000 > data/L80T"$T12"h0.0s6;
done &
