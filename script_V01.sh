#! /bin/sh

#preparation to blink
cd /sys/class/gpio
echo 21 > export
cd gpio21
echo out > direction

# check loop
while [ true ]
do

# key detection
if [ -d "/dev/sda1" ]; then

# mount key
mkdir /mnt/sda1
mount /dev/sda1 /mnt/sda1 

# unmount key
umount /dev/sda1

# blink
v=1
count=3
for i in `seq 1 $count`
do
echo $v > value
sleep 1s

# change value of v
if [ $v = 1 ]; then
v=0
else
v=1
fi

done
fi
done
