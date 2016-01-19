#! /bin/sh

#preparation to blink
echo 21 > /sys/class/gpio/export
echo out > /sys/class/gpio/gpio21/direction
echo "phase1 ok"
# check loop
while [ true ]
do
echo "phase2 ok"
# key detection
if [ -d "/dev/sda1" ]; then
echo "phase3 ok"
# mount key
mkdir /mnt/sda1
mount /dev/sda1 /mnt/sda1 
echo "phase4 ok"
# unmount key
umount /dev/sda1
echo "phase5 ok"
# blink
v=1
count=3
for i in `seq 1 $count`
do
echo $v > /sys/class/gpio/gpio21/value
sleep 1s
echo "phase6 ok"
# change value of v
if [ $v = 1 ]; then
v=0
else
v=1
fi

done
fi
done
