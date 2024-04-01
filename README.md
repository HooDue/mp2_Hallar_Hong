**Members: Hallar, Francine Marie F. & Hong, Letty V.  LBYARCH S11**

release and debug mode: x64
### **i.) comparative execution time and short analysis of the performance of the kernels**

![image](https://github.com/HooDue/mp2_Hallar_Hong/assets/127380830/615a062a-3b39-4713-bd1d-145c08722bf7)

**Analysis:**
Execution time was used to compare performance between (1) the C program version of the kernel and (2) the x86-64 assembly language version.  Kernel performs the DAXPY (A*X + Y) function where vectors X, Y, and Z are double-precision floats. 

In our code, we used a function to generate random inputs for vectors X and Y. We also did dynamic allocation of data on the heap; otherwise, the code would use a large amount of stack space, exceeding the stack size limit. 

In the tables above, the average execution time is captured by running 30 times each n-size of input, 2^20, 2^24, and 2^27, respectively. 2^28 and further was tested, but it resulted in computer lags. Our device could not run that amount of n inputs, although it sometimes permits, but it takes too long for the computer to respond. 

As shown in the tables, the x86-64 assembly version of the kernel happens to execute faster than the C version in some cases, like those in the debug mode. Because assembly language is directly assembled into CPU instructions, while C needs to be compiled first into the assembly, and it only uses minimal optimization; however, there are instances where the x86-64 is slower than the C. Likewise, for  n=2^24, the execution time is slower than C (small difference) and also it is slower in release mode. This might be due to various reasons, like the optimization strategies used in C or that the x86-64 assembly needs more memory for pointers and some data types, which can affect its performance.



### **ii.) Take a screenshot of the program output with the correctness check (C) and correctness check (x86-64).**
 
Average execution time for running 30 times for n^20
    ![2^20 Debug Mode](https://github.com/HooDue/mp2_Hallar_Hong/assets/98597121/5c73cccb-5aa8-4e02-a955-0f69a2bc2480)
    ![2^20 Release Mode](https://github.com/HooDue/mp2_Hallar_Hong/assets/98597121/27fdc013-d2ba-4f31-80ca-4b93ce5a6bc5)
        
Average execution time for running 30 times for n^24
  ![2^24 Debug Mode](https://github.com/HooDue/mp2_Hallar_Hong/assets/98597121/05c152ed-dc62-48f2-a3f9-ae19651cab5b)
  ![2^24 Release Mode](https://github.com/HooDue/mp2_Hallar_Hong/assets/98597121/c029ba51-130b-4d2c-a1e9-2576e4097b2d)

Average execution time for running 30 times for n^27
  ![2^27 Debug Mode](https://github.com/HooDue/mp2_Hallar_Hong/assets/98597121/6eebf007-3cbb-4944-89cf-08cebc1f4dc4)
  ![2^27 Release Mode](https://github.com/HooDue/mp2_Hallar_Hong/assets/98597121/17ea08fd-c934-497d-a02a-12834305a86f)     
