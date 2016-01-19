#! /bin/sh

#preparation to blink
echo 21 > /sys/class/gpio/export
echo out > /sys/class/gpio/gpio21/direction

# check loop
while [ true ]
do

# blink slowly
v=1
count=6
for i in `seq 1 $count`
do
echo $v > /sys/class/gpio/gpio21/value
usleep 500000
# change value of v
if [ $v = 1 ]; then
v=0
else
v=1
fi

done

# key detection
if [ -b "/dev/sda1" ]; then

# mount key
if ![ -d "/mnt/sda1"]; then mkdir /mnt/sda1; fi
mount /dev/sda1 /mnt/sda1 
echo "USB Key is ready to be used"

# blink rapidly
v=1
count=6
for i in `seq 1 $count`
do
echo $v > /sys/class/gpio/gpio21/value
usleep 100000
# change value of v
if [ $v = 1 ]; then
v=0
else
v=1
fi

done

# unmount key
umount /dev/sda1
echo "You can unplug your USB key safely"




fi
sleep 5
done