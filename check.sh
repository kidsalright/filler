if [ $1 = 3 ]; then
map=3
p=1
b=2
cd vm
./filler_vm -f maps/map0$map -p2 champions/abanlin.filler -p1 ../yberries.filler
exit
fi
echo "Write map number [0, 1, 2 , ... ]"
read map
echo "Choose to be player 1 or 2"
read p
if [ $p = 1 ]; then
b=2
else
b=1
fi
cd vm
./filler_vm -f maps/map0$map -p$b champions/abanlin.filler -p$p ../yberries.filler
cd ..
