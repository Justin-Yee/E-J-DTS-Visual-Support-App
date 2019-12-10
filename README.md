# EJG-DTS-Trouble_Tracker

Functionality Demo Branch :: altered-format-(don't-marge)

Visual Studio Solution :: DefTracker.sln

2 files too large for Github : wt.pdb and wtd.pdb 

Visual Studio Solution Properties

C/C++ -> General -> Additional Include Directories -> (Wt 4.1.2 msvs2019 x86/include)

Linker -> General -> Additional Library Directories -> (Wt 4.1.2 msvs2019 x86/lib)

Run the Solution to use Output Stream to interact with Program

Following is the Layout of the Program

/* ***** ***** ***** ***** ***** */
  1. Home
	a. Upcoming Reports (What's due within the next n-days)
	b. Change Password
	c. About
  2. Reports
	a. Submit Report
	b. Existing Reports
	c. Historical Data
	d. Individual Report
  3. Contact
  4. Logout
  
/* ***** ***** ***** ***** ***** */   
 
Following is the Variable Type of each Report Member

  Work Order Number == int
  
  Material Group == string
  
  Defect Name == string 
  
  Machine Line == int
  
  Day, Month, Year == int
  
  Incident Classification == string 
  
  Defect Classification == string
  
  Defect Severity == string
  
  Supplier Name == string
  
  Item Number == int
  
  Cause Comment == string
  
  Action Comment == string
  
  
/* ***** ***** ***** ***** ***** */  
