# basics-buttondebouncingwithinterrupts
Basics series: Button debouncing using interrupts

## Hardware

* Teensy 3.2
* What I thought was an average button

## Results

With the lockout time dropped down to 2ms I *still* couldn't get it to bounce so I'm happy with the testing. The code has to accept interrupts on both rising and falling edges so that it can sensibly distinguish between intentional state changes vs. bounces. The serial output below shows that a huge number of bounces occur for each succesfully interpreted button press. 

Serial output:

> 1/1: Button pressed
> 2/11: Button pressed
> 3/17: Button pressed
> 4/89: Button pressed
> 5/91: Button pressed
> 6/94: Button pressed
> 7/100: Button pressed
> 8/102: Button pressed
> 9/121: Button pressed
> 10/131: Button pressed
> 11/139: Button pressed
> 12/141: Button pressed
> 13/157: Button pressed
> 14/201: Button pressed
> 15/213: Button pressed
> 16/216: Button pressed
> 17/227: Button pressed
> 18/237: Button pressed
> 19/245: Button pressed

