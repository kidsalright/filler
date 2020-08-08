if [ $1 = 01 ]; then
map=0
p=1
b=2
cd vm
./filler_vm -f maps/map0$map -p$b champions/abanlin.filler -p$p ../yberries.filler
exit
fi
if [ $1 = 02 ]; then
map=0
p=2
b=1
cd vm
./filler_vm -f maps/map0$map -p$b champions/abanlin.filler -p$p ../yberries.filler
exit
fi
if [ $1 = 11 ]; then
map=1
p=1
b=2
cd vm
./filler_vm -f maps/map0$map -p$b champions/abanlin.filler -p$p ../yberries.filler
exit
fi
if [ $1 = 12 ]; then
map=1
p=2
b=1
cd vm
./filler_vm -f maps/map0$map -p$b champions/abanlin.filler -p$p ../yberries.filler
exit
fi
if [ $1 = 21 ]; then
map=2
p=1
b=2
cd vm
./filler_vm -f maps/map0$map -p$b champions/abanlin.filler -p$p ../yberries.filler
exit
fi
if [ $1 = 22 ]; then
map=2
p=2
b=1
cd vm
./filler_vm -f maps/map0$map -p$b champions/abanlin.filler -p$p ../yberries.filler
exit
fi
