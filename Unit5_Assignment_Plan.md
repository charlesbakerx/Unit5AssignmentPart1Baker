## Unit 5 Assignment Plan : Charles Baker

### Scenario
  - Write a function named weeklyPay that calculates and returns weekly pay.

### Variable Declarations
  - int empType
  - double payRate, hoursWorked, grossPay, netPay, fitRate
  - string name

### Input
  - We will be inputing hoursWorked, payRate, name, and empType into the function

### Processing
  - Is hoursWorked > 40?
    - Yes: Set grossPay = (hoursWorked - 40) * (payRate * 2)
      - Set hoursWorked = 40
  - Calculate payRate * hoursWorked += grossPay
  - Set netPay = grossPay
  - Check if the employee is full time.
    - Yes: subtract 17.00 and 77.00 from netPay
  - Check if payRate < $15
    - Yes: set fitRate to 0.12
    - No: Do nothing variable initialized to standard 0.15
  - Calculate netPay * fitRate, subtract it from netPay
  - Calculate grossPay * 0.062, subtract it from netPay
  - Calculate grossPay * 0.0145, subtract it from netPay

### Output
 - Output employees name in all caps, followed by weekly pay and employment type
 - Make sure to setprecision on weekly pay.
 - Make sure to highlight employee's name in color

### Error Conditions
 - No error conditions in this assignment due to not taking input from a user.