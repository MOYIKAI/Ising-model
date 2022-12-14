for T in $(seq -w 1.0 0.2 1.6);
do
./Modify-Ising2Dex-2.x 10 $T 0 -200000 1010000000 > data/L10T"$T"h0.0s0;
./Modify-Ising2Dex-2.x 10 $T 0 -200002 1010000000 > data/L10T"$T"h0.0s2;
./Modify-Ising2Dex-2.x 10 $T 0 -200003 1010000000 > data/L10T"$T"h0.0s3;
./Modify-Ising2Dex-2.x 10 $T 0 -200004 1010000000 > data/L10T"$T"h0.0s4;
./Modify-Ising2Dex-2.x 10 $T 0 -200005 1010000000 > data/L10T"$T"h0.0s5;
./Modify-Ising2Dex-2.x 10 $T 0 -200006 1010000000 > data/L10T"$T"h0.0s6;
./Modify-Ising2Dex-2.x 10 $T 0 -200007 1010000000 > data/L10T"$T"h0.0s7;
./Modify-Ising2Dex-2.x 10 $T 0 -200008 1010000000 > data/L10T"$T"h0.0s8;
./Modify-Ising2Dex-2.x 10 $T 0 -200009 1010000000 > data/L10T"$T"h0.0s9;
done &

for T20 in $(seq -w 1.5 0.1 1.7);
do
./Modify-Ising2Dex-2.x 20 $T20 0 -200000 4004000000 > data/L20T"$T20"h0.0s0;
./Modify-Ising2Dex-2.x 20 $T20 0 -200002 4004000000 > data/L20T"$T20"h0.0s2;
./Modify-Ising2Dex-2.x 20 $T20 0 -200003 4004000000 > data/L20T"$T20"h0.0s3;
./Modify-Ising2Dex-2.x 20 $T20 0 -200004 4004000000 > data/L20T"$T20"h0.0s4;
./Modify-Ising2Dex-2.x 20 $T20 0 -200005 4004000000 > data/L20T"$T20"h0.0s5;
./Modify-Ising2Dex-2.x 20 $T20 0 -200006 4004000000 > data/L20T"$T20"h0.0s6;
./Modify-Ising2Dex-2.x 20 $T20 0 -200007 4004000000 > data/L20T"$T20"h0.0s7;
./Modify-Ising2Dex-2.x 20 $T20 0 -200008 4004000000 > data/L20T"$T20"h0.0s8;
./Modify-Ising2Dex-2.x 20 $T20 0 -200009 4004000000 > data/L20T"$T20"h0.0s9;
done &
