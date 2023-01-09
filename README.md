# DASTAK
“DASTAK” is a home-service program created in C language. It allows the user to book home-service providers such as a handy-man, electrician or plumber.

Out of many reasons “DASTAK” came into being, the most important one is the current situation due to COVID-19 pandemic, which has led people to prioritizing online services. Moreover, this service has been developed in order to facilitate all its users, by providing them with a platform where they can book different categories of home-service providers with just one click and hire trained, and reliable professionals.

## Project Specification - (Project Detail, Functionality and features):

1. In order to enter the program the user can sign up if he/she is using the program for the first time and has never been registered before however if the user has already signed up, he/she can login every time with the same email. This is made sure by the account check and validation functions.
Below are the functions used in making the login portal.

```cpp
//when user registers for the first time
void signup();

//once the user have saved his credentials
void login();

//checks if the user exist or not
void account_check();

//validates password
int validate();
```
![]()

2. In order to display a list in front of the user of the profession that they may have selected earlier, we are going to use different functions that have specific details of professionals of that particular profession.

```cpp
//each functions contains details of people with that specific profession
void search_Electrician(void);
void search_Plumber(void);
void search_Carpenter(void);
void search_Car_Services(void);
void search_Handyman_Services(void);
```
    
3. Here we will ask the user to mention any specific details that they might want the professional to follow or look into. The user will also be asked how long the task is for which they require the professional.
For every professional a separate detail function has been made.

```cpp
//details of the professional the user selects
void booking_detail_electrician(int professional_choice1);
void booking_detail_plumber(int professional_choice2);
void booking_detail_carpenter(int professional_choice3);
void booking_detail_carservices(int professional_choice4);
void booking_detail_handyman(int professional_choice5);
```
    
4. This will be the last function of the program where it will display details of the professional the user might have booked and the total payment with different options.

```cpp
void cart(int professional_choice, int work_hours);
```
    
5. In order to add different colours on the output screen we have used this function.

```cpp
void SetColor(int ForgC);
```

6. We have used two structures in this program, one is for the details of the user while the other one is for the details of the professional. As we included 5 main professions for house fixing works we have used 5 different variables for struct profession that is a[5], b[5], c[5], d[5], e[5].

```cpp
struct details {
  char uname[100];
  int age;
  char password[100];
  char email[100];
  char mobile[100];
};

struct profession {
  char pname[100];
  float rating;
  int charges_hour;
  char mobile_number[100];
  int previous_services;
  char skills[100];
};
```
     
## Programming Concepts used:
 We have tried to keep the program simple so that everyone can understand the concept behind it while using most of the programming concepts like
1. If and else statements
2. Local and Global Variables
3. Switch Statements
4. Structures
5. Nested Loops
6. With and without return type Functions
7. Passing Structure to Function
8. Arrays
9. String utility Functions
10.Filing

## Result:
As an output the user will receive his/her final bill on the output screen and on the back we will receive the email of the user and details of the professional who has been booked on that email. Here we will be receiving 5 files, as a record for each profession will be stored in a separate file.

