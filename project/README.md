# Blinky-Buzzy Toy

## Description

MSP430 was programmed to act as a toy that uses the *buzzer*, *red led*, *green led*, and *switches*. Depending on which switch is pressed, the toy will perform non-sense like blinking leds, dimming leds, switching between different colored leds, and playing a song!

## How to compile

To start using this project, please go through the following:

* Compile the `timerLib` library inside the project directory

```
../project/timerLib> make install
```

* Compile program inside `src` 

```
../project/src> make
```

## How to run

Most of the setup is done! Now the toy only lacks the program to run. To upload the program into the `MSP430` do:

```
../project/src> make load
```
Congrats! By this point, the toy should now be working!

## How to use

To use your `MSP430` press any switches that you would like. And have fun!

*Something to notice, the first three switches involve playing with the leds, while the last switch plays a cool tune.*