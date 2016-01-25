#! /bin/sh

# verification if update needed

if [ -d "/mnt/sda1/newVersion" ]; then 
	# suppression of old files
	rm -f /etc/init.d/S99app
	rm -f /UsbMount.sh
	rm -f /root/encryptDecrypt

	# copy of new files
	cp /mnt/sda1/newVersion/S99app /etc/init.d/S99app
	cp /mnt/sda1/newVersion/UsbMount.sh /UsbMount.sh
	cp /mnt/sda1/newVersion/encryptDecrypt /root/encryptDecrypt

	chmod a+rx /etc/init.d/S99app
	chmod a+x /root/encryptDecrypt
	chmod a+x /UsbMount.sh

	sync
	reboot
fi
