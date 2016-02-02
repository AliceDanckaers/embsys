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

=== V1.2 and V1.3

We modified the fonction encryptDecryptc in order to implement the function on all files present in the file /mnt/sda1.
The only issue we had is that some hidden file can be present according to the type of key and the result is sometimes unexpected.
The program worked perfectly when we tried it on a simple folder.

Furthermore, we created the script autoUpdate.sh in ordeer to update the files we use during our program. In order to use it, you had to put all the new files in a folder NewVersion and the script will check if this folder exist. In that case, the program will update the scripts and reboot the card.

We also had our file S99app to the project.

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



