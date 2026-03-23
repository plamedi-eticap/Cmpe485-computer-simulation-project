# Cmpe485-computer-simulation-project
Class project 
CMPE485 Assignment 1
22209494	Plamedi Ntambue kapuya 
22207406	Yousef alyousefi
22316739	Adam Elboudali Zahid 
22110572	Mohmmed Musaed

Files Submitted
1.Source Code
rand_no.c → generates 1,000 random numbers and saves them to RN-file.txt.
rand_no2.c → reads RN-file.txt, bins the 1K numbers, generates 10K numbers into RN-file-10000.txt, bins them, and performs chi‑square test.

2.Data Files
RN-file.txt → contains 1,000 random numbers.
RN-file-10000.txt → contains 10,000 random numbers.

3.Excel Charts
Excel file with bin counts for 1K and 10K samples.
Bar charts (Bin No vs. Bin Count) for both datasets.

4.Report Document
Word file (CMPE485-MP1.docx)
Cover page
Table of contents
Abstract
Theory
Methodology (explaining use of rand_no.c and rand_no2.c)
Results (tables + charts)
Chi-square test analysis
Discussion
Conclusion
GitHub Codespaces with Visual Studio code

STEP 1 RUN: gcc rand_no.c -o rand_no && ./rand_no
   → RN-file.txt (1000 RNs, 10x100 table displayed)

STEP 2 RUN: gcc rand_no2.c -o rand_no2 && ./rand_no2
   → Reads RN-file.txt → 1K bins displayed
   → Creates RN-file-10000.txt → 10K bins displayed  
   → Chi-square test result displayed


Bin counts from terminal output for Excel charts.

