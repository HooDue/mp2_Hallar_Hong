Members: Hallar, Francine Marie F. & Hong, Letty V.  LBYARCH S11

i.) comparative execution time and short analysis of the performance of the kernels
    
Average execution time for running 30 times for n^20:
Debug Mode:
      C: 0.0101
      x86-64:0.0060
Release Mode:
      C: 0.0025
      x86-64:0.0028
    
Average execution time for running 30 times for n^24:
Debug Mode:
        C: 
        x86-64: 
Release Mode:
        C: 
        x86-64:

Average execution time for running 30 times for n^27:
Debug Mode:
        C: 
        x86-64:
Release Mode:
        C: 
        x86-64:

        ![image](https://github.com/HooDue/mp2_Hallar_Hong/assets/127380830/20448e3c-a19c-4e6f-9669-077d284b8ba0)

Analysis:
    Execution time was used to compare performance between (1) the C program version of the kernel and (2) the x86-64 assembly language version.  Kernel performs the DAXPY (A*X + Y) function where vectors X, Y, and Z are double-precision floats. 

In our code, we used a function to generate random inputs for vectors X and Y. We also did dynamic allocation of data on the heap; otherwise, the code would use a large amount of stack space, exceeding the stack size limit. 

In the tables above, the average execution time is captured by running 30 times each n-size of input, 220 224 and 227 respectively. 228 and further was tested, but it resulted in computer lags. Our device could not run that amount of n inputs, although it sometimes permits, but it takes too long for the computer to respond. 

As shown in the tables, the x86-64 assembly version of the kernel happens to execute faster than the C version in some cases because assembly language is directly assembled into CPU instructions, while C needs to be compiled first into the assembly.  But there are instances where the x86-64 is slower than the C. Likewise, for  n=224  , the execution time is slower than C (small difference). This might be due to various reasons, like the optimization strategies used in C that differ from the assembly, or that x86-64 assembly needs more memory for pointers and some data types which can affect its performance.



 ii.) Take a screenshot of the program output with the correctness check (C) and correctness check (x86-64).
 
Average execution time for running 30 times for n^20
    ![2^20 Debug Mode](https://github.com/HooDue/mp2_Hallar_Hong/assets/98597121/5c73cccb-5aa8-4e02-a955-0f69a2bc2480)
    ![2^20 Release Mode](https://github.com/HooDue/mp2_Hallar_Hong/assets/98597121/27fdc013-d2ba-4f31-80ca-4b93ce5a6bc5)
        
Average execution time for running 30 times for n^24
  ![2^24 Debug Mode](https://github.com/HooDue/mp2_Hallar_Hong/assets/98597121/05c152ed-dc62-48f2-a3f9-ae19651cab5b)
  ![2^24 Release Mode](https://github.com/HooDue/mp2_Hallar_Hong/assets/98597121/c029ba51-130b-4d2c-a1e9-2576e4097b2d)

Average execution time for running 30 times for n^27
  ![2^27 Debug Mode](https://github.com/HooDue/mp2_Hallar_Hong/assets/98597121/6eebf007-3cbb-4944-89cf-08cebc1f4dc4)
  ![2^27 Release Mode](https://github.com/HooDue/mp2_Hallar_Hong/assets/98597121/17ea08fd-c934-497d-a02a-12834305a86f)     
