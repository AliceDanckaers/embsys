# projet embsys


= TP4 : La carte Armadeus APF28
:authors: Alice - Yiqian / Sisi - Philippe
:email: 
:encoding: utf-8

== Généralités

-----
$ git clone https://github.com/AliceDanckaers/embsys
-----

=== V0.1

The script script_V01.sh is launched by init.d when the Armadeus APF28 starts.
When a USB key is plugged in, it is mounted. Finaly, the LED blink rapidly 3 times when you can unplug the key.
The script verify every 5 seconds if there is a new USB key.

=== V0.2

The script script_V02.sh is launched by init.d when the Armadeus APF28 starts.
When a USB key is plugged in, it is mounted and then unmounted. Finaly, the LED blink rapidly 3 times when you can unplug the key.
The script verify every 5 seconds if there is a new USB key. Each time it does this verification the LED blinks 3 times slowly.

