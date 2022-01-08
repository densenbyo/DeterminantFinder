# PJC semestrální práce - Výpočet determinantu
# Zadání
Výpočet determinantu při pomoci Gaussovou eliminací
# About
** Aplikace pracuje jenom jednovlakově **
** Nedoporučuju pro velké matice **

1) Zaprvé vstupem bere intový argument (1, 2, 3)
    - 1 vyzvé HELP info
    - 2 vyzvé RUN, což je spuštění aplikace
    - 3 vyzvé PRINT, což je print matice
2) Pro matice
    - Matice je rozměrem NxN, kde N musí byt stejné
    - Pak bere value matice
    - Pokud argumentem je 2, najde determinant
    - Pokud argumentem je 3, print matice
# Příklad
Argument RUN 
```
    Matrix determinant finder by Gaussian elimination method
    ARGUMENTS:
    [1 to get info]
    [2 to start app]
    [3 to show current matrix]
    
    Input argument :
    2
    MATRIX CONFIG
    
    Size of matrix NxN
    2 2
    Input values of matrix
    9 5 1 1
    Determinant is 4
     Time: 0ms
```
Argument PRINT 
```
    Matrix determinant finder by Gaussian elimination method
    ARGUMENTS:
    [1 to get info]
    [2 to start app]
    [3 to show current matrix]
    
    Input argument :
    3
    MATRIX CONFIG
    Size of matrix NxN
    2 2
    Input values of matrix
    9 5
    1 1
     | 9.00 | 5.00 |
     | 1.00 | 1.00 |
```
Argument HELP
```
    Matrix determinant finder by Gaussian elimination method
    ARGUMENTS:
    [1 to get info]
    [2 to start app]
    [3 to show current matrix]
    
    Input argument :
    1
    Application solves only in Single thread
    That is why I do not recommend to solve big matrix (it will be really slow)
    First input: Size of matrix NxN (N has to be same)
    Second input: Values of matrix
    Argument list :
    1 to show help info
    2 starts finding determinant
    3 show prints current matrix
```
# Čas
Od matice 2x2 do matice 10x10 spočitá rychlé.

Matice 100x100 spočitá ~5ms.

Matice 1000x1000 spočitá ~unknown ms (nechci čekat tak dlouho :D).

