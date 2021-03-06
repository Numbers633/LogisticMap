"# LogisticMap" 
This is a guide to this logistic map program.
There are some limits for the X and R values.  The last 3 numbers entered should be integers (though the last number can be a decimal).

The progeam "CycleConformation1" is a very fast and accurate cycle conformation system.

--Logistic Map--

R must be between -2 and 4;
X must be between 0 and 1.

If you exeed R = 4, or make x less than 0 or more that 1, it will blow up to infinity.
ALL LIMITS APPLY.

--Input--

'R:': The program is asking for any value of r.
'Please enter the number of iterations before looking: ': The value needs to be an integer of at least 2,500.  For more advanced pruposes, the program supports up to 650,000,000.
'Please enter the maximum cycle length': The maximum cycle length is also needed.  The number can be as low as 500 for typical purposes, and as high as 2 billion.

--Bifurcation--

A few points will not be resolvable (such as 1 and 3) by the program.  3 is a true bifurcation point, and occurs because, at the intersection point, the parabola is inclined at 90 degrees to the axis.  1 is also not resolvable as a cycle because it is declining very slowly, constantly getting smaller.  After an infinity of iterations, however, it will stabillize at 0.  The program reports if it dosen't find a cycle by saying "Failed to find a cycle.  It is possible that it might actually be chaos or a bifurcation point.  Try adjusting R.".  This statement can also occur when the R value (above 3.569945671871) is chaotic.  However, at certain places, X is actually periodic (as described below.).


The application, when on high search quality, is very sensitive to bifurcations.  For example, entering R = 3.74 on high quality mode will return a 10-cycle, even though the bifurcation peices are still very close together.  This means the program is sensitive to bifurcations.

--Cycles--

If you ever find a new stable cycle with this program, please add it to the cycle dictionary below.  It is recommended that if you need high search quality that you also use higher numbers of pre-iterations for it to stabilize.  Good luck!

All of the numbers below are numbers to try out in this application:

Note: If you see a '?' after a cycle, then it is unconfirmed.

2-cycle:
3

3-cycle:
 3.8284271247461900976033774841939615713934375075389614635,

4-cycle:
3.44948974278317809819728407470589139196594748065667012843269256725096037745731502653985943310464023481,
3.96010188374002

5-cycle:
 3.7385,
 3.905573,
 3.990257307469,

6-cycle:
 3.625532464,
 3.9376,

7-cycle:
3.7016407641603495818246437898408892201442915,
3.774133387036,
3.886028805185,
3.96897435300104,

8-cycle:
3.6621089204554,

9-cycle:
3.853613109341,

10-cycle:
3.60524,
3.64700616067001,
3.6729992892,
3.80849273228745,

11-cycle:
3.69343,

12-cycle:
3.58202,
3.63186247,
3.85599016,

14-cycle:
3.59725,

15-cycle:
3.74400303220001,
3.8521,

18-cycle:
3.60057844925341,

20-cycle:
3.57751224576,
3.586275,

21-cycle:
3.85149263643446,
3.8526873,

22-cycle:
3.59911966,

25-cycle:
3.7443168186068,

28-cycle:
3.58057,
3.5758050324,

30-cycle:
3.84998135881,

32-cycle:
3.5741149,
3.584422,
3.58591,

33-cycle:
3.85136144589635,

40-cycle:
3.5715656,

48-cycle:
3.5704997245,

56-cycle:
3.5711999176,

80-cycle:
3.580966,

96-cycle:
3.84959795089101,

128-cycle:
3.5706099921585,

1,152-cycle:
3.56995665

610,432-cycle:
3.56995668

1,447,808-cycle:
3.56995659

1,521,408-cycle:
3.56995666

1,800,192-cycle:
3.56995669

2,563,392-cycle
3.56995667

2,957,504-cycle:
3.56995663

4,682,176-cycle:
3.569956585

4,920,448-cycle:
3.56995662

6,836,544-cycle:
3.5699566

7,955,840-cycle:
3.56995657

8,576,064-cycle:
3.56995658
3.56995659?

10,011,507-cycle:
3.828427

11,217,664-cycle:
3.56995664

19,469,184-cycle:
3.56995661

53,034,812-cycle:
3.641
