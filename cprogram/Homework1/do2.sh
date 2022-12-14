for T1 in `ls data/L10T*s0 | sed 's/h/ /' | sed 's/T/ /' | awk '{print $2}'`;
do
./Modify-Ising2Dex-2.x 10 $T1 0 -2000000 101000000 > data/L10T"$T1"h0.0s00;
./Modify-Ising2Dex-2.x 10 $T1 0 -2000001 101000000 > data/L10T"$T1"h0.0s01;
./Modify-Ising2Dex-2.x 10 $T1 0 -2000002 101000000 > data/L10T"$T1"h0.0s02;
./Modify-Ising2Dex-2.x 10 $T1 0 -2000003 101000000 > data/L10T"$T1"h0.0s03;
./Modify-Ising2Dex-2.x 10 $T1 0 -2000004 101000000 > data/L10T"$T1"h0.0s04;
./Modify-Ising2Dex-2.x 10 $T1 0 -2000005 101000000 > data/L10T"$T1"h0.0s05;
./Modify-Ising2Dex-2.x 10 $T1 0 -2000006 101000000 > data/L10T"$T1"h0.0s06;
./Modify-Ising2Dex-2.x 10 $T1 0 -2000007 101000000 > data/L10T"$T1"h0.0s07;
./Modify-Ising2Dex-2.x 10 $T1 0 -2000008 101000000 > data/L10T"$T1"h0.0s08;
./Modify-Ising2Dex-2.x 10 $T1 0 -2000009 101000000 > data/L10T"$T1"h0.0s09;
done &

for T2 in `ls data/L20T*s0 | sed 's/h/ /' | sed 's/T/ /' | awk '{print $2}'`;
do
./Modify-Ising2Dex-2.x 20 $T2 0 -2000000 400400000 > data/L20T"$T2"h0.0s00;
./Modify-Ising2Dex-2.x 20 $T2 0 -2000001 400400000 > data/L20T"$T2"h0.0s01;
./Modify-Ising2Dex-2.x 20 $T2 0 -2000002 400400000 > data/L20T"$T2"h0.0s02;
./Modify-Ising2Dex-2.x 20 $T2 0 -2000003 400400000 > data/L20T"$T2"h0.0s03;
./Modify-Ising2Dex-2.x 20 $T2 0 -2000004 400400000 > data/L20T"$T2"h0.0s04;
./Modify-Ising2Dex-2.x 20 $T2 0 -2000005 400400000 > data/L20T"$T2"h0.0s05;
./Modify-Ising2Dex-2.x 20 $T2 0 -2000006 400400000 > data/L20T"$T2"h0.0s06;
./Modify-Ising2Dex-2.x 20 $T2 0 -2000007 400400000 > data/L20T"$T2"h0.0s07;
./Modify-Ising2Dex-2.x 20 $T2 0 -2000008 400400000 > data/L20T"$T2"h0.0s08;
./Modify-Ising2Dex-2.x 20 $T2 0 -2000009 400400000 > data/L20T"$T2"h0.0s09;
done &

for T3 in `ls data/L40T*s0 | sed 's/h/ /' | sed 's/T/ /' | awk '{print $2}'`;
do
./Modify-Ising2Dex-2.x 40 $T3 0 -2000000 1616000000 > data/L40T"$T3"h0.0s00;
./Modify-Ising2Dex-2.x 40 $T3 0 -2000001 1616000000 > data/L40T"$T3"h0.0s01;
./Modify-Ising2Dex-2.x 40 $T3 0 -2000002 1616000000 > data/L40T"$T3"h0.0s02;
./Modify-Ising2Dex-2.x 40 $T3 0 -2000003 1616000000 > data/L40T"$T3"h0.0s03;
./Modify-Ising2Dex-2.x 40 $T3 0 -2000004 1616000000 > data/L40T"$T3"h0.0s04;
done &

for T5 in `ls data/L40T*s0 | sed 's/h/ /' | sed 's/T/ /' | awk '{print $2}'`;
do
./Modify-Ising2Dex-2.x 40 $T5 0 -2000005 1616000000 > data/L40T"$T5"h0.0s05;
./Modify-Ising2Dex-2.x 40 $T5 0 -2000006 1616000000 > data/L40T"$T5"h0.0s06;
./Modify-Ising2Dex-2.x 40 $T5 0 -2000007 1616000000 > data/L40T"$T5"h0.0s07;
./Modify-Ising2Dex-2.x 40 $T5 0 -2000008 1616000000 > data/L40T"$T5"h0.0s08;
./Modify-Ising2Dex-2.x 40 $T5 0 -2000009 1616000000 > data/L40T"$T5"h0.0s09;
done &
