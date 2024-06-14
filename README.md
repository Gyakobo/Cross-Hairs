# Cross-Hairs

![image](https://img.shields.io/badge/Devpost-003E54?style=for-the-badge&logo=Devpost&logoColor=white)
![image](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![image](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![image](https://img.shields.io/badge/Python-FFD43B?style=for-the-badge&logo=python&logoColor=blue)
![image](https://img.shields.io/badge/OpenCV-27338e?style=for-the-badge&logo=OpenCV&logoColor=white)
![image](https://img.shields.io/badge/CMake-064F8C?style=for-the-badge&logo=cmake&logoColor=white)
![image](https://img.shields.io/badge/windows%20terminal-4D4D4D?style=for-the-badge&logo=windows%20terminal&logoColor=white)

Author: [Andrew Gyakobo](https://github.com/Gyakobo)

>[!NOTE]
>This is a project which I presented and subsequently won 1st place in the [2021 Hackathon @ NJIT](https://devpost.com/software/cross-hairs).  

>[!WARNING]
>This project is very raw and indelicate, and honestly could be furnished slightly more. Most prominently I want to point out that I should have definitely utilized `malloc` and allocated and managed memory way more efficiently. Apart from that there's a ton of memory leaks and code errors. Moreover, I ought to have used a struct or a class for each particle in this engine.  

## Introduction

To start off, I always had a passion for mathematics, physics and programming. The world always seemed quantifiable and boring to me, thus I always reverted to coding. I specifically loved exploiting game and physics engines. Making up glamorous formulas predicting the gravitational trajectory of an object always fascinated me. Having heard of the Hackathon, I was sort of pushed into making my own physics from scratch.

This project tries to simulate fluid dynamics, and fluid viscosity. In particular I drew inspiration from the game [Noita](https://store.steampowered.com/app/881100/Noita/) (cool game btw) to develop this project. More details can be found on this [video](https://youtu.be/mcoHVF-JWog?si=MOAMeUlSdaGBlRED)

## Methodolgy

The game is divided into small grids which pertain to a specific.

* The dynamics of this game are painfully simple. Each `particale` in the grid follows a specific behaviour and interacts with other particles which also conform to the same move set.

In particular each particle moves in the following manner:

1. If there simply isn't anything underneath a select particle then the said particle just moves down:

<table>

<tr><td>

|   | █ |   |
|---|---|---|
| █ | □ | █ |

</td><td>

&nbsp;
→
&nbsp;

</td><td>

|   | &nbsp; |   |
|---|---|---|
| █ | █ | █ |

</td></tr>

</table>

2. If there's however another object underneath the existing one then the particle moves to the left of the object:

<table>

<tr><td>

|   | █ |   |
|---|---|---|
| □ | █ |   |

</td><td>

&nbsp;
→
&nbsp;

</td><td>

|   | &nbsp; |   |
|---|---|---|
| █ | █ |   |

</td></tr>

</table>

3. And subsequently the element would seek to occupy the next available space on the right: 

<table>

<tr><td>

|   | █ |   |
|---|---|---|
| █ | █ | □ |

</td><td>

&nbsp;
→
&nbsp;

</td><td>

|   | &nbsp; |   |
|---|---|---|
| █ | █ | █ |

</td></tr>

</table>

4. Lastly if all the avaiable space below are occupied then the particle in question would remain at the same place. There is however another methodolgy that I glossed over. There exists an additional step on making the viscosity aspect of this game even more prominent adding another relation: each particle that has nowhere to go would simply 'slide' down left and cocomitantly right if there's already a particle on the left:

<table>

<tr><td>

| □ | █ |   |
|---|---|---|
| █ | █ | █ |

</td><td>

&nbsp;
→
&nbsp;

</td><td>

| █ |   |   |
|---|---|---|
| █ | █ | █ |

</td></tr>

</table>


<table>

<tr><td>

| █ | █ | □ |
|---|---|---|
| █ | █ | █ |

</td><td>

&nbsp;
→
&nbsp;

</td><td>

| █ |   | █ |
|---|---|---|
| █ | █ | █ |

</td></tr>

</table>

## What I'd have done differently

1. Most definitely I should have just instantiated a struct `struct Particle` and created them with `malloc` and freed memory with `free` respectively. The contents of this data structure would be as follows: the coordinate `int x, y` and the color `char color`. 

>[!NOTE]
>From a memory management perspective, you ought to have the smallest element first in the `struct` in order to minimize memory usage. This way a select `struct` object would be of size `9 bytes`.

```c
struct Particle {
    char color; /* 1 byte */
    int x, y; /* 4 bytes per variable */
}
```

2. The particle grid could also be operated with the use of threads. Let say we have an adustable 640 x 480 grid. For now it's very easy to work with this grid, however, as soon as you add more elements or increase the grid size, there becomes an overhead and latency increases. This is where you should use multi-threading.

### The OpenMP - open Multi-processing library 

Just as a side note the **OpenMP** library comprises of the following parts. Also feel free to download, edit, commit and leave feedback to the project.

For more details about parallelism in C please refer to my previous [multi-threading project](https://github.com/Gyakobo/multi-threading) where I utilized and explained the `<omp.h>` C library. 

#### Compiler Directives

```c
#pragma omp parallel
#pragma omp critical
#pragma omp barrier
#pragma omp master
```

#### Functions

```c
#include <omp.h>
int omp_get_thread_num()
int omp_get_num_threads()
```

#### Compiling and Linking

```bash
gcc -fopenmp # C compiler
g++ -fopenmp # C++ compiler
```

#### Environmental variables

```bash
export OMP_NUM_THREADS=8
export OMP_NESTED=TRUE
```

## How to execute 

To execute this project please first give exec permissions to [build.sh](https://github.com/Gyakobo/Cross-Hairs/blob/main/Cross-Hairs/build.sh) and of course run it:

```shell
$ sudo chmod +x build.sh
$ sudo ./build.sh
```

## License
MIT
