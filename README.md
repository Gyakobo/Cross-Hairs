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
>This is a project which I presented for the [2021 Hackathon @ NJIT](https://devpost.com/software/cross-hairs).  

>[!WARNING]
>This project is very raw and indelicate, and honestly could be furnished a bit more. Most prominently I want to point out that I should have definitely utilized `malloc` and allocated and managed memory way more efficiently. Apart from that there's a ton of memory leaks and code errors. Moreover, I ought to have used a struct or a class for each particle in this engine.  

## Introduction

To start off, I always had a passion for mathematics, physics and programming. The world always seemed quantifiable and boring to me, thus I always reverted to coding. I specifically loved exploiting game and physics engines. Making up glamorous formulas predicting the gravitational trajectory of an object always fascinated me. Having heard of the Hackathon, I was sort of pushed into making my own physics from scratch.

This project tries to simulate fluid dynamics, and fluid viscosity. In particular I drew inspiration from the game [Noita](https://store.steampowered.com/app/881100/Noita/) (cool game btw) to develop this project. More details can be found on this [video](https://youtu.be/mcoHVF-JWog?si=MOAMeUlSdaGBlRED)

## Methodolgy

The game is divided into small grids which pertain to a specific.

* The dynamics of this game are painfully simple. Each `particale` in the grid follows a specific behaviour and interacts with other particles which also conform to the same move set.

In particular each particle moves in the following manner:

1. If there isn't anything underneath a select particle then the said particle just moves down:

<p><p>

|   | X |   |
|---|---|---|
| X |   | X |

</p><p>

&nbsp;
=>
&nbsp;

</p><p>

| &nbsp;  |   |   |
|---|---|---|
| X | X | X |

</p></p>

2. If there's however another object underneath the existing one then the particle moves to the left of the object.

<p><p>

| &nbsp; | X | &nbsp; |
|---|---|---|
|   | X |   |

</p><p>

=>

</p><p>

|   |   | &nbsp; |
|---|---|---|
| X | X |   |

</p></p>

3. And subsequently the element would seek to occupy the next available space on the right. 


<p><p>

| &nbsp; | X | &nbsp; |
|---|---|---|
| X | X |   |

</p><p>

=>

</p><p>

|   |   | &nbsp; |
|---|---|---|
| X | X | X |

</p></p>

4. Lastly if all the avaiable space below are occupied then the particle in question would remain at the same place.
