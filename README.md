# Project embsys


= Encryption project: Armadeus APF28 Board
:authors: Alice - Yiqian / Sisi - Philippe
:email: alice.danckaers@ensta-bretagne.org
:encoding: utf-8

# Généralités

-----
$ git clone https://github.com/AliceDanckaers/embsys
-----

# Version 1.x

=== V1.1
The script UsbMount.sh is launched by init.d when the Armadeus APF28 starts.
When a USB key is plugged in, it is mounted and the file /tocrypt.txt of the key is encrypted and saved on the key into the file /encrypted.txt. The file /todecrypt.txt of the key is decrypted and saved on the key into the file /decrypted.txt  
Finaly, the USB key is unmounted and the LED blink rapidly 3 times when you can unplug the key.
The script verify every 5 seconds if there is a new USB key. Each time it does this verification the LED blinks 3 times slowly.


=== V1.0
The script UsbMount.sh is launched by init.d when the Armadeus APF28 starts.
When a USB key is plugged in, it is mounted and the file /tocrypt.txt of the key is encrypted and saved on the key into the file /encrypted.txt 
Finaly, the USB key is unmounted and the LED blink rapidly 3 times when you can unplug the key.
The script verify every 5 seconds if there is a new USB key. Each time it does this verification the LED blinks 3 times slowly.


# Versions 0.x

=== V0.2

The script script_V02.sh is launched by init.d when the Armadeus APF28 starts.
When a USB key is plugged in, it is mounted and then unmounted. Finaly, the LED blink rapidly 3 times when you can unplug the key.
The script verify every 5 seconds if there is a new USB key. Each time it does this verification the LED blinks 3 times slowly.


=== V0.1

The script script_V01.sh is launched by init.d when the Armadeus APF28 starts.
When a USB key is plugged in, it is mounted. Finaly, the LED blink rapidly 3 times when you can unplug the key.
The script verify every 5 seconds if there is a new USB key.



