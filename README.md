# basics-buttondebouncingwithinterrupts
Basics series: Button debouncing using interrupts

## Hardware

* Teensy 3.2
* What I thought was an average button

## Results

With the lockout time dropped down to 2ms I *still* couldn't get it to bounce so I'm happy with the testing. The code has to accept interrupts on both rising and falling edges so that it can sensibly distinguish between intentional state changes vs. bounces. The serial output below shows that a huge number of bounces occur for each succesfully interpreted button press. 

Serial output:

> 1/1: Button pressed<br>
> 2/11: Button pressed<br>
> 3/17: Button pressed<br>
> 4/89: Button pressed<br>
> 5/91: Button pressed<br>
> 6/94: Button pressed<br>
> 7/100: Button pressed<br>
> 8/102: Button pressed<br>
> 9/121: Button pressed<br>
> 10/131: Button pressed<br>
> 11/139: Button pressed<br>
> 12/141: Button pressed<br>
> 13/157: Button pressed<br>
> 14/201: Button pressed<br>
> 15/213: Button pressed<br>
> 16/216: Button pressed<br>
> 17/227: Button pressed<br>
> 18/237: Button pressed<br>
> 19/245: Button pressed<br>

