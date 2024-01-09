

***This file is the finel project of Hadar Yehuda and Andrey Oppenheimer with Holon Institute of Technology's Moderator:Dr. Simony Erez***
<br/><br/>
<br/><br/>

# EyeTracker

Tobii Pro SDK reference guide: https://developer.tobiipro.com/matlab/matlab-sdk-reference-guide.html
<br/><br/>

# Psychtoolbox-3

- Psychtoolbox git :https://github.com/Psychtoolbox-3/Psychtoolbox-3
- Site: http://psychtoolbox.org/
<br/><br/>

# PLUX Biosignals
- plux documentation : https://support.pluxbiosignals.com/wp-content/uploads/2021/11/OpenSignals_Manual.pdf
![External Image](http://biosignalplux.gentechmd.co/wp-content/uploads/2021/06/software-1024x585.jpg)
- the plux LSL repo for matlab documantation: https://github.com/pluxbiosignals/opensignals-samples/tree/master
<br/><br/>
# Getting Started 
- before running the code:
plux software should be running and recording: 



- LSL server should be enabled in plux using the guide in the plux documentation.


![image](https://github.com/Hadar0712/eyeTracker/assets/61351955/cbf746a8-c7e5-4981-b18e-d8d7e107afb7)
<br/><br/>
<br/><br/>
<br/><br/>
<br/><br/>


## Tobi.m file
![image](https://github.com/Hadar0712/eyeTracker/assets/61351955/5b83590e-a337-459f-b937-dc5d7d0485bc)
<br/><br/>
<br/><br/>

- to run the file you need sevral prameters: "Subject_name,domEye,randomized,run"

<br/><br/>
then you run it in the command window example: 
![image](https://github.com/Hadar0712/eyeTracker/assets/61351955/6ff8fcb0-5c8d-4648-99a2-179162d444f1)

<br/><br/>
<br/><br/>
## Output
<br/><br/>

- save for each subject the opensignals data .
<br/><br/>
all the out file sould look like this:
<br/><br/>
  ![image](https://github.com/Hadar0712/eyeTracker/assets/61351955/64d858aa-a092-4928-87b4-bfb9328cc86a)
<br/><br/>

## Resampling and orgenaizing using python
<br/><br/>

- final_project.ipynb will make .csv files for each movie :
 <br/><br/>
  ![image](https://github.com/Hadar0712/eyeTracker/assets/61351955/ebc12b87-811d-41dd-9203-7493b4526e03)
<br/><br/>
- change the paths in the python file:
<br/><br/>
![image](https://github.com/Hadar0712/eyeTracker/assets/61351955/7be43dbd-bd0e-4e09-8739-f377b19e6551)
<br/><br/>

## Statistics
- run "All_numbers.ipynb" to test the data and smoothen it out.
- then run "correlation.ipynb" to see the resolts.
  <br/><br/>
examples included in Notebooks folder.
  <br/><br/>
![image](https://github.com/Hadar0712/eyeTracker/assets/61351955/1393d6a2-d188-4bb4-9a4c-17e8ae71dee6)
  <br/><br/>
  ![image](https://github.com/Hadar0712/eyeTracker/assets/61351955/5ba0dae6-601a-40ce-88b4-253a3c5eb2f8)
   <br/><br/>
![image](https://github.com/Hadar0712/eyeTracker/assets/61351955/54244d7f-01b4-4467-8bf6-8564e686c5bc)
<br/><br/>

