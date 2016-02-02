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

=== V1.3

The script UsbMount.sh is launched by init.d when the Armadeus APF28 starts.
When a USB drive is plugged in, there are two cases:
      *  If the file autoUpdate.sh and the folder newVersion are present on the USB drive then the version of the programme is updated automatically using the source files present in the folder newVersion.
      * Else, the USB drive is mounted and all the files of the key are encrypted and saved back on the key.

Finaly, the USB drive is unmounted and the LED blink rapidly 3 times when you can unplug the drive.
The script verify every 5 seconds if there is a new USB drive. Each time it does this verification the LED blinks 3 times slowly.

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



