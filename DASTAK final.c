#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <dos.h>
#include <dir.h>

struct details 
{ 
    char uname[100]; 
    int age; 
    char password[100]; 
    char email[100]; 
    char mobile[100]; 
}; 
  

struct profession 
{ 
    char pname[100]; 
    float rating; 
    int charges_hour; 
    char mobile_number[100]; 
    int previous_services; 
    char skills[100];
}; 

struct address
{
	int house_no;
	char block;
	char area[20];
	char city[20];
};
  
struct profession a[5],b[5],c[5],d[5],e[5]; 
struct details s[100]; 
struct address add;
int flag = 1, i, j=0, count = 0; 
int small = 0, special = 0, numbers = 0 , caps = 0; 
int success = 0, x, choice; 
char name[100], password1[100],password2[100], email[100],details[100]; 
char mobile[100], age,ch1,ch2;
int total = 0, n; 
int professional_choice1, professional_choice2, professional_choice3,professional_choice4,professional_choice5,professional_choice,search_choice, confirm; 
int ch,cash,credit_num;
int work_hours;

void signup();  
void login(); 
void account_check(); 
int validate();

void search_Electrician(void);
void search_Plumber(void);
void search_Carpenter(void);
void search_Car_Services(void);
void search_Handyman_Services(void);
void booking_detail_electrician(int professional_choice1);
void booking_detail_plumber(int professional_choice2);
void booking_detail_carpenter(int professional_choice3);
void booking_detail_carservices(int professional_choice4);
void booking_detail_handyman(int professional_choice5);
void cart(int professional_choice, int work_hours);


void SetColor(int ForgC);

int main() 
{ 
    
	while (1) { 
        SetColor(9);
        printf("          ======================================"); 
        printf("\n            DASTAK-Service on your door steps! \n"); 
        printf("          ======================================");    
		SetColor(8); 
		
            printf("\n\n1)SIGNUP\n"); 
            printf("2)LOGIN\n3)EXIT\n\n"); 
            printf("Enter your choice: "); 
            scanf("%d", &choice);
            system("cls");
            switch (choice) 
			{ 
            case 1: { 
                signup(); 
                break; 
            } 
            case 2: { 
                login(); 
                break; 
            } 
            case 3: {  
                return(0); 
            } 
            default: { 
                SetColor(4);
                printf("\nPlease enter the valid number\n"); 
                break; 
            } 
            } 
    
         
    } 
} 
  


 
void signup() 
{ 
    SetColor(9);
    printf("          ======================================"); 
    printf("\n                    SIGN UP \n"); 
    printf("          ======================================");    
   
    SetColor(8);
    
    printf("\n\nEnter Your name: "); 
    scanf("%s", &name); 
  
    printf("Enter Your Age: "); 
    scanf("%d", &age); 
  
    printf("Enter Your Email: "); 
    scanf("%s", &email); 
  
    printf("Enter Password(10 characters): "); 
    for(i=0;i<10;i++)
    {
        ch1 = getch();
        password1[i] = ch1;
        ch1 = '*' ;
        printf("%c",ch1);
    } 
    printf("\n");
    printf("Confirm Password: "); 
    for(i=0;i<10;i++)
    {
        ch2 = getch();
        password2[i] = ch2;
        ch2 = '*' ;
        printf("%c",ch2);
    } 
  
    printf("\nEnter Your Mobile Number: "); 
    scanf("%s", mobile); 
  
    x = validate(); 
    
	if (x == 1) 
    {
    	account_check();	
	}
	FILE *fp;
	fp=fopen("employee.txt","a");
    fprintf ( fp, "\n%s %s %d",email,password1);
	fclose(fp);     
}

int validate() 
{ 
    for (i = 0; name[i] != '\0'; i++) { 
        if (!((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z')))
		{ 
		    SetColor(4);
            printf("\nPlease enter a valid name\n"); 
            flag = 0; 
            break; 
        } 
    } 
    if (flag == 1) { 
        count = 0; 
  
        // Validate the Email ID 
        for (i = 0; email[i] != '\0'; i++)
		{ 
            if (email[i] == '@' || email[i] == '.') 
                count++; 
        } 
        if (count >= 2 && strlen(email) >= 5) { 
            // Validating the Password and 
            // Check whether it matches 
            // with Conform Password 
            if (!strcmp(password1, password2)) 
			{ 
                if (strlen(password1) >= 8 && strlen(password1) <= 20)
				{ 
                    caps = 0; 
                    small = 0; 
                    numbers = 0; 
                    special = 0; 
                    for (i = 0; password1[i] != '\0';  i++)
					{ 
                        if (password1[i] >= 'A' && password1[i] <= 'Z') 
                        {
                        	caps++; 
					    }
                        else if (password1[i] >= 'a' && password1[i] <= 'z') 
						{
							small++;
						} 
                        else if (password1[i] >= '0' && password1[i] <= '9') 
                        {
                            numbers++; 
                        }
                        else if (password1[i] == '@' || password1[i] == '&' || password1[i] == '#' || password1[i] == '*') 
                        {
                        	special++; 
						}    
                    } 
                    if (caps >= 1 && small >= 1 && numbers >= 1 && special >= 1)
					{ 
                        if (age != 0 && age > 0) 
						{ 
                            if (strlen(mobile) == 11) 
							{ 
                                for (i = 0; i < 10; i++) 
								{ 
                                    if (mobile[i] >= '0' && mobile[i] <= '9') 
									{ 
                                        success = 1; 
                                    } 
                                    else 
									{ 
									    SetColor(4);
                                        printf("\n\nPlease enter valid Mobile Number.\n\n"); 
                                        return 0; 
                                        break; 
                                    } 
                                } 
  
                                // Success is assigned with 
                                // value 1, Once every 
                                // inputs are correct. 
                                if (success == 1) 
                                    return 1; 
                            } 
                            else { 
                                SetColor(4);
                                printf("\n\nPlease enter 11 digit mobile number\n\n"); 
                                return 0; 
                            } 
                        } 
                        else 
						{ 
						    SetColor(4);
                            printf("\n\nPlease enter valid age\n\n"); 
                            return 0; 
                        } 
                    } 
                    else 
					{ 
					    SetColor(4);
                        printf("\n\nPlease enter a strong password, your password must contain atleast one uppercase, lowercase, number and special character.\n\n"); 
                        return 0; 
                    } 
                } 
                else 
				{ 
				    SetColor(4);
                    printf("\nYour Password is very short, length must between 8 to 12\n\n"); 
                    return 0; 
                } 
            } 
            else 
			{ 
			    SetColor(4);
                printf("\nPassword Mismatch\n\n"); 
                return 0; 
            } 
        } 
        else 
		{ 
		    SetColor(4);
            printf("\nPlease enter valid E-Mail address\n\n"); 
            return 0; 
        } 
    } 
} 

void account_check() 
{ 
    for (i = 0; i < 100; i++) 
	{ 
        if (!(strcmp(email, s[i].email) && strcmp(password1, s[i].password))) 
		{ 
		    SetColor(4);
            printf("\n\nAccount already exist. Please login!\n\n"); 
            main(); 
            break; 
        } 
    } 
    if (i == 100) { 
        strcpy(s[j].uname, name); 
        s[j].age = age; 
        strcpy(s[j].password, password1); 
        strcpy(s[j].email, email); 
        strcpy(s[j].mobile, mobile); 
        j++; 
        SetColor(2);
        printf("\n\n\n            SignUp Succesful!\n\n"); 
        getch();
        system("cls");
    } 
} 

void login() 
{ 
	int flag1;
	int flag2;
    SetColor(9);
    printf("          ======================================");
    printf("\n                       LOGIN\n"); 
    printf("          ======================================");
    SetColor(8);
    printf("\n\nEnter Your Email: "); 
    scanf("%s", email); 
    printf("Enter Your Password: "); 
    for(i=0;i<10;i++)
    {
        ch1 = getch();
        password1[i] = ch1;
        ch1 = '*' ;
        printf("%c",ch1);
    } 
    system("cls");
    FILE *fp;
	fp = fopen("EMPLOYEE.txt","r");
	if ( fp == NULL )
	{
		SetColor(4);
 		puts( "Cannot open file\n" );
 	} 
	char eml[100];
	while (fscanf(fp, "%s", eml) != EOF)       //validating username loop continues and checks each username in the file till end of file
 	{													// and if it does not find match then prints wrong user name.
 		
 		flag1 = strcmp(email,eml);
 	
	 	if (flag1 == 0)
	 	{
	 		break;
		}
	}
	if (flag1 != 0)
	{
		SetColor(4);
		printf("Wrong username! press any key to try again.\n");
		getch();
		login();
	}
			
 	char pass[100];
 	while (fscanf(fp, "%s", pass) != EOF)       //validating username loop continues and checks each password in the file till end of file
 	{													// and if it does not find match then prints wrong password.
 		flag2 = strcmp(password1,pass);
 	
	 	if (flag2 == 0)
	 	{
	 		break;
		}
	}
	if (flag2 != 0)
	{
		SetColor(4);
	 	printf("Wrong password! press any key to try again.\n");
		getch();
		login();
	}
	
	
    SetColor(9);
	printf("          ======================================");
    printf("\n                   Welcome %s!\n ", s[i].uname); 
    printf("          ======================================");
                
    SetColor(2);
    printf("\n\nYou have successfully logged in!\n\n");  
	SetColor(8); 
    printf("Search by profession, whatever service you need.\n"); 
                printf("1) Electrician\n"); 
                printf("2) Plumber\n"); 
                printf("3) Carpenter\n"); 
                printf("4) Car Services\n"); 
                printf("5) Handyman Services\n"); 
                printf("6) Exit\n"); 
                printf("\nPlease enter your choice: "); 
                scanf("%d", &search_choice); 
                system("cls"); 
                
                switch (search_choice) 
				{ 
                    case 1: 
				    { 
                        search_Electrician(); 
                        break; 
                    } 
                case 2: 
				    { 
                        search_Plumber(); 
                        break; 
                    } 
                case 3: 
			    	{ 
                        search_Carpenter(); 
                        break; 
                    } 
                case 4: 
				    { 
                        search_Car_Services(); 
                        break; 
                    }
                case 5:
				    { 
                        search_Handyman_Services(); 
                        break; 
                    } 
                case 6: 
				    {  
                        return; 
                    } 
                default: 
				    { 
				        SetColor(4);
                        printf("Please enter a valid choice\n\n"); 
                        break; 
                    } 
                }  
} 

void search_Electrician(void)
{
	struct profession a[5]={{"Zahid Ali", 4.5, 200, "03007082332", 432, "Efficient, Good Customer dealing"},
	{"Hassan Raza", 4, 150, "03004532332", 300, "Systematic, Good Communication skills"},
	{"Shoaib Riaz", 4.5, 200, "03107282987", 450, "Productive, Methodical"},
	{"Haider Khan", 5, 150, "03512382389", 100, "Quick, Well organized"},
	{"Hamza Tariq", 3.5, 100, "030074542332",380,"Orderly, Low rates"}};
	
	SetColor(9);
	printf("          ======================================\n");
	printf("            List of professionals we have.\n");
	printf("          ======================================\n");
	SetColor(3);
	printf("1)Name: %s\nRating: %f\nHourly Rates: %d\nMobile Number: %s\nPrevious Bookings: %d\nSkills: %s\n\n", a[0].pname, a[0].rating,a[0].charges_hour,
	a[0].mobile_number,a[0].previous_services,a[0].skills);
	
	SetColor(11);
	printf("2)Name: %s\nRating: %f\nHourly Rates: %d\nMobile Number: %s\nPrevious Bookings: %d\nSkills: %s\n\n", a[1].pname, a[1].rating,a[1].charges_hour,
	a[1].mobile_number,a[1].previous_services,a[1].skills);
	
	SetColor(3);
	printf("3)Name: %s\nRating: %f\nHourly Rates: %d\nMobile Number: %s\nPrevious Bookings: %d\nSkills: %s\n\n", a[2].pname, a[2].rating,a[2].charges_hour,
	a[2].mobile_number,a[2].previous_services,a[2].skills);
	
	SetColor(11);
	printf("4)Name: %s\nRating: %f\nHourly Rates: %d\nMobile Number: %s\nPrevious Bookings: %d\nSkills: %s\n\n", a[3].pname, a[3].rating,a[3].charges_hour,
	a[3].mobile_number,a[3].previous_services,a[3].skills);
	
	SetColor(3);
	printf("5)Name: %s\nRating: %f\nHourly Rates: %d\nMobile Number: %s\nPrevious Bookings: %d\nSkills: %s\n\n", a[4].pname, a[4].rating,a[4].charges_hour,
	a[4].mobile_number,a[4].previous_services,a[4].skills);
	
	
	SetColor(8);
	printf("Please select the professional you want to call:\t"); 
    scanf("%d", &professional_choice1); 
    system("cls");
    if (professional_choice1 > 6) 
    { 
        SetColor(4);
        printf("Please Enter the valid choice\n\n");
		system("cls");
        search_Electrician(); 
    } 
    else if (professional_choice1 == 6) 
    {
        return;
    } 
    else
    {
    	booking_detail_electrician(professional_choice1); 
	}
}

void search_Plumber()
{
	struct profession b[5]={{"Ali Zahid", 4.5, 200, "03007650132", 432, "Capable, Orderly"},
	{"Raza Hassan", 4, 150, "03007604813", 300, "Good Communication Skills"},
	{"Riaz Shoaib", 4.5, 200, "03004532365", 450, "Qualified, Proficient"},
	{"Khan Saud", 5, 150, "03007382988", 100, "Skilled, Systematic"},
	{"Tariq Hamza", 3.5, 100, "03007486240",380,"Efficient, Low rates"}};
	
SetColor(9);
	printf("          ======================================\n");
	printf("            List of professionals we have.\n");
	printf("          ======================================\n");
	SetColor(3);
	
	printf("1)Name: %s\nRating: %f\nHourly Rates: %d\nMobile Number: %s\nPrevious Bookings: %d\nSkills: %s\n\n", b[0].pname, b[0].rating,b[0].charges_hour,
	b[0].mobile_number,b[0].previous_services,b[0].skills);
	
	SetColor(11);
	printf("2)Name: %s\nRating: %f\nHourly Rates: %d\nMobile Number: %s\nPrevious Bookings: %d\nSkills: %s\n\n", b[1].pname, b[1].rating,b[1].charges_hour,
	b[1].mobile_number,b[1].previous_services,b[1].skills);
	
	SetColor(3);
	printf("3)Name: %s\nRating: %f\nHourly Rates: %d\nMobile Number: %s\nPrevious Bookings: %d\nSkills: %s\n\n", b[2].pname, b[2].rating,b[2].charges_hour,
	b[2].mobile_number,b[2].previous_services,b[2].skills);
	
	SetColor(11);
	printf("4)Name: %s\nRating: %f\nHourly Rates: %d\nMobile Number: %s\nPrevious Bookings: %d\nSkills: %s\n\n", b[3].pname, b[3].rating,b[3].charges_hour,
	b[3].mobile_number,b[3].previous_services,b[3].skills);
	
	SetColor(3);
	printf("5)Name: %s\nRating: %f\nHourly Rates: %d\nMobile Number: %s\nPrevious Bookings: %d\nSkills: %s\n\n", b[4].pname, b[4].rating,b[4].charges_hour,
	b[4].mobile_number,b[4].previous_services,b[4].skills);
	                        
	SetColor(8);
	printf("Please select the professional you want to call:\t"); 
    scanf("%d", &professional_choice2); 
    system("cls");
    if (professional_choice2 > 6) 
    { 
        SetColor(4);
        printf("Please Enter the valid choice\n\n");
		system("cls"); 
        search_Plumber(); 
    } 
    else if (professional_choice2 == 6) 
    {
        return;
    } 
    else
    {
    	booking_detail_plumber(professional_choice2); 
	}
}

void search_Carpenter()
{
	struct profession c[5]={{"Zahid Ali", 4.5, 200, "03007082332", 432, "Strong communication skills"},
	{"Hassan Raza", 4, 150, "03007182332", 300, "Patience"},
	{"Shoaib Riaz", 4.5, 200, "03007282332", 450, "Active listening skills"},
	{"Haider Khan", 5, 150, "03007382332", 100, "Good personality"},
	{"Hamza Tariq", 3.5, 100, "03007482332",380 ,"Good judgment"}};
	
	SetColor(9);
	printf("          ======================================\n");
	printf("            List of professionals we have.\n");
	printf("          ======================================\n");
	SetColor(3);
	
	printf("1)Name: %s\nRating: %f\nHourly Rates: %d\nMobile Number: %s\nPrevious Bookings: %d\nSkills: %s\n\n", c[0].pname, c[0].rating,c[0].charges_hour,
	c[0].mobile_number,c[0].previous_services,c[0].skills);
	
	SetColor(11);
	printf("2)Name: %s\nRating: %f\nHourly Rates: %d\nMobile Number: %s\nPrevious Bookings: %d\nSkills: %s\n\n", c[1].pname, c[1].rating,c[1].charges_hour,
	c[1].mobile_number,c[1].previous_services,c[1].skills);
	
	SetColor(3);
	printf("3)Name: %s\nRating: %f\nHourly Rates: %d\nMobile Number: %s\nPrevious Bookings: %d\nSkills: %s\n\n", c[2].pname, c[2].rating,c[2].charges_hour,
	c[2].mobile_number,c[2].previous_services,c[2].skills);
	
	SetColor(11);
	printf("4)Name: %s\nRating: %f\nHourly Rates: %d\nMobile Number: %s\nPrevious Bookings: %d\nSkills: %s\n\n", c[3].pname, c[3].rating,c[3].charges_hour,
	c[3].mobile_number,c[3].previous_services,c[3].skills);

    SetColor(3);
	printf("5)Name: %s\nRating: %f\nHourly Rates: %d\nMobile Number: %s\nPrevious Bookings: %d\nSkills: %s\n\n", c[4].pname, c[4].rating,c[4].charges_hour,
	c[4].mobile_number,c[4].previous_services,c[4].skills);
	                        
    SetColor(8);
	printf("Please select the professional you want to call:\t"); 
    scanf("%d", &professional_choice3); 
    system("cls");
    if (professional_choice3 > 6) 
    { 
        SetColor(4);
        printf("Please Enter the valid choice\n\n");
		system("cls");
        search_Carpenter(); 
    } 
    else if (professional_choice3 == 6) 
    {
        return;
    } 
    else
    {
    	booking_detail_carpenter(professional_choice3); 
	}	                        
}

 void search_Car_Services()
 {
 	struct profession d[5]={{"Zahid Ali", 4.5, 200, "03007082332", 432, "Good Personality"},
	{"Hassan Raza", 4, 150, "03007182332", 300, "Stong Communication Edit"},
	{"Shoaib Riaz", 4.5, 200, "03007282332", 450, "Negotiation skills"},
	{"Haider Khan", 5, 150, "03007382332", 100, "Qualified, Proficient"},
	{"Hamza Tariq", 3.5, 100, "03007482332",380 ,"Honesty"}};
	
	SetColor(9);
	printf("          ======================================\n");
	printf("            List of professionals we have.\n");
	printf("          ======================================\n");
	SetColor(3);
	
	printf("1)Name: %s\nRating: %f\nHourly Rates: %d\nMobile Number: %s\nPrevious Bookings: %d\nSkills: %s\n\n", d[0].pname, d[0].rating,d[0].charges_hour,
	d[0].mobile_number,d[0].previous_services,d[0].skills);
	
	SetColor(11);
	printf("2)Name: %s\nRating: %f\nHourly Rates: %d\nMobile Number: %s\nPrevious Bookings: %d\nSkills: %s\n\n", d[1].pname, d[1].rating,d[1].charges_hour,
	d[1].mobile_number,d[1].previous_services,d[1].skills);
	
	SetColor(3);
	printf("3)Name: %s\nRating: %f\nHourly Rates: %d\nMobile Number: %s\nPrevious Bookings: %d\nSkills: %s\n\n", d[2].pname, d[2].rating,d[2].charges_hour,
	d[2].mobile_number,d[2].previous_services,d[2].skills);
	
	SetColor(11);
	printf("4)Name: %s\nRating: %f\nHourly Rates: %d\nMobile Number: %s\nPrevious Bookings: %d\nSkills: %s\n\n", d[3].pname, d[3].rating,d[3].charges_hour,
	d[3].mobile_number,d[3].previous_services,d[3].skills);
	
	SetColor(3);
	printf("5)Name: %s\nRating: %f\nHourly Rates: %d\nMobile Number: %s\nPrevious Bookings: %d\nSkills: %s\n\n", d[4].pname, d[4].rating,d[4].charges_hour,
	d[4].mobile_number,d[4].previous_services,d[4].skills);
	                    
	SetColor(8);
	printf("Please select the professional you want to call:\t"); 
    scanf("%d", &professional_choice4); 
    system("cls");
    if (professional_choice4 > 6) 
    { 
        SetColor(4);
        printf("Please Enter the valid choice\n\n");
		system("cls"); 
        search_Car_Services(); 
    } 
    else if (professional_choice4 == 6) 
    {
        return;
    } 
    else
    {
    	 booking_detail_carservices(professional_choice4); 
	}
 }
 
 void search_Handyman_Services()
 {
 	struct profession e[5]={{"Zahid Ali", 4.5, 200, "03007082332", 432, "Quick Service"},
	{"Hassan Raza", 4, 150, "03007182332", 300, "Qualified, Proficient"},
	{"Shoaib Riaz", 4.5, 200, "03007282389", 450, "Honest"},
	{"Haider Khan", 5, 150, "03007382307", 100, "Quick Response"},
	{"Hamza Tariq", 3.5, 100, "03007482332",380 ,"Proactive problem solving"}};
	
	SetColor(9);
	printf("          ======================================\n");
	printf("            List of professionals we have.\n");
	printf("          ======================================\n");
	SetColor(3);
	printf("1)Name: %s\nRating: %f\nHourly Rates: %d\nMobile Number: %s\nPrevious Bookings: %d\nSkills: %s\n\n", e[0].pname, e[0].rating,e[0].charges_hour,
	e[0].mobile_number,e[0].previous_services,e[0].skills);
	
	SetColor(11);
	printf("2)Name: %s\nRating: %f\nHourly Rates: %d\nMobile Number: %s\nPrevious Bookings: %d\nSkills: %s\n\n", e[1].pname, e[1].rating,e[1].charges_hour,
	e[1].mobile_number,e[1].previous_services,e[1].skills);
	
	SetColor(3);
	printf("3)Name: %s\nRating: %f\nHourly Rates: %d\nMobile Number: %s\nPrevious Bookings: %d\nSkills: %s\n\n", e[2].pname, e[2].rating,e[2].charges_hour,
	e[2].mobile_number,e[2].previous_services,e[2].skills);
	
	SetColor(11);
	printf("4)Name: %s\nRating: %f\nHourly Rates: %d\nMobile Number: %s\nPrevious Bookings: %d\nSkills: %s\n\n", e[3].pname, e[3].rating,e[3].charges_hour,
	e[3].mobile_number,e[3].previous_services,e[3].skills);
	
	SetColor(3);
	printf("5)Name: %s\nRating: %f\nHourly Rates: %d\nMobile Number: %s\nPrevious Bookings: %d\nSkills: %s\n\n", e[4].pname, e[4].rating,e[4].charges_hour,
	a[4].mobile_number,a[4].previous_services,e[4].skills);
	                        
    SetColor(8);
	printf("Please select the professional you want to call:\t"); 
    scanf("%d", &professional_choice5); 
    system("cls");
    if (professional_choice5 > 6) 
    { 
        SetColor(4);
        printf("Please Enter the valid choice\n\n");
		system("cls"); 
        search_Handyman_Services(); 
    } 
    else if (professional_choice5 == 6) 
    {
        return;
    } 
    else
    {
    	booking_detail_handyman(professional_choice5); 
	}
 }

  
void booking_detail_electrician(int professional_choice1) 
{ 
    
    
        SetColor(9);
        printf("          ======================================");
        printf("\n                     Details of Order\n");
        printf("          ======================================");    
        SetColor(8);
        printf("\n\nFor how many hours do you require the professional: \n");
        scanf("%d",&work_hours);
        printf("\n\nMention if there are any instructions you would want to give to the professional.");
        printf("\nIf there aren't any write None.\n");
        scanf("%s", &details); 
        printf("Lets move to your cart now");
        system("cls"); 
    
    cart(professional_choice1, work_hours);
}

void booking_detail_plumber(int professional_choice2) 
{ 
    
    
        SetColor(9);
        printf("          ======================================");
        printf("\n                     Details of Order\n");
        printf("          ======================================");    
        SetColor(8); 
        printf("\n\nFor how many hours do you require the professional: \n");
        scanf("%d",&work_hours);
        printf("\n\nMention if there are any instructions you would want to give to the professional.");
        printf("\nIf there aren't any write None.\n");
        scanf("%s", &details); 
        printf("Lets move to your cart now");
        system("cls"); 
        
    
    cart(professional_choice2, work_hours);
}

void booking_detail_carpenter(int professional_choice3) 
{ 
  
    
        SetColor(9);
        printf("          ======================================");
        printf("\n                     Details of Order\n");
        printf("          ======================================");    
        SetColor(8);
        printf("\n\nFor how many hours do you require the professional: \n");
        scanf("%d",&work_hours);
        printf("\n\nMention if there are any instructions you would want to give to the professional.");
        printf("\nIf there aren't any write None.\n");
        scanf("%s", &details); 
        printf("Lets move to your cart now");
        system("cls"); 
    
    cart(professional_choice3, work_hours);
}

void booking_detail_carservices(int professional_choice4) 
{ 
    
    
        SetColor(9);
        printf("          ======================================");
        printf("\n                     Details of Order\n");
        printf("          ======================================");    
        SetColor(8);
        printf("\n\nFor how many hours do you require the professional: \n");
        scanf("%d",&work_hours);
        printf("\n\nMention if there are any instructions you would want to give to the professional.");
        printf("\nIf there aren't any write None.\n");
        scanf("%s", &details);
		printf("Lets move to your cart now"); 
		system("cls"); 
        
    
    cart(professional_choice4, work_hours);
}

void booking_detail_handyman(int professional_choice5) 
{ 
   
    
	
        SetColor(9);
        printf("          ======================================");
        printf("\n                     Details of Order\n");
        printf("          ======================================");    
        SetColor(8);
        printf("\n\nFor how many hours do you require the professional: \n");
        scanf("%d",&work_hours);
        printf("\n\nMention if there are any instructions you would want to give to the professional.");
        printf("\nIf there aren't any write None.\n");
        scanf("%s", &details); 
        printf("Lets move to your cart now");
        system("cls"); 
        
    
    cart(professional_choice5,work_hours);
}


void cart(int professional_choice, int work_hours) 
{ 
    struct details s[100];
    struct profession a[5]={{"Zahid Ali", 4.5, 200, "03007082332", 432, "Efficient, Good Customer dealing"},
	{"Hassan Raza", 4, 150, "03004532332", 300, "Systematic, Good Communication skills"},
	{"Shoaib Riaz", 4.5, 200, "03107282987", 450, "Productive, Methodical"},
	{"Haider Khan", 5, 150, "03512382389", 100, "Quick, Well organized"},
	{"Hamza Tariq", 3.5, 100, "030074542332",380,"Orderly, Low rates"}};
    struct profession b[5]={{"Zahid Ali", 4.5, 200, "03007082332", 432, "Efficient, Good Customer dealing"},
	{"Hassan Raza", 4, 150, "03004532332", 300, "Systematic, Good Communication skills"},
	{"Shoaib Riaz", 4.5, 200, "03107282987", 450, "Productive, Methodical"},
	{"Haider Khan", 5, 150, "03512382389", 100, "Quick, Well organized"},
	{"Hamza Tariq", 3.5, 100, "030074542332",380,"Orderly, Low rates"}};
    struct profession c[5]={{"Zahid Ali", 4.5, 200, "03007082332", 432, "Efficient, Good Customer dealing"},
	{"Hassan Raza", 4, 150, "03004532332", 300, "Systematic, Good Communication skills"},
	{"Shoaib Riaz", 4.5, 200, "03107282987", 450, "Productive, Methodical"},
	{"Haider Khan", 5, 150, "03512382389", 100, "Quick, Well organized"},
	{"Hamza Tariq", 3.5, 100, "030074542332",380,"Orderly, Low rates"}};
    struct profession d[5]={{"Zahid Ali", 4.5, 200, "03007082332", 432, "Efficient, Good Customer dealing"},
	{"Hassan Raza", 4, 150, "03004532332", 300, "Systematic, Good Communication skills"},
	{"Shoaib Riaz", 4.5, 200, "03107282987", 450, "Productive, Methodical"},
	{"Haider Khan", 5, 150, "03512382389", 100, "Quick, Well organized"},
	{"Hamza Tariq", 3.5, 100, "030074542332",380,"Orderly, Low rates"}};
    struct profession e[5]={{"Zahid Ali", 4.5, 200, "03007082332", 432, "Efficient, Good Customer dealing"},
	{"Hassan Raza", 4, 150, "03004532332", 300, "Systematic, Good Communication skills"},
	{"Shoaib Riaz", 4.5, 200, "03107282987", 450, "Productive, Methodical"},
	{"Haider Khan", 5, 150, "03512382389", 100, "Quick, Well organized"},
	{"Hamza Tariq", 3.5, 100, "030074542332",380,"Orderly, Low rates"}};
	
	
	FILE *fp2,*fp3,*fp4,*fp5,*fp6;
	
	int num=0;
	float total; 
	struct address add;
	
    SetColor(9);
    printf("          ======================================");
    printf("\n                         Cart\n"); 
    printf("          ======================================");
    printf("\n\n\n----------------"); 
    SetColor(8);
    printf("\n\nYour Final Booking:\n"); 
    if(search_choice == 1)
    {
    	printf("Name: %s\nCharges per Hour:%d\nMobile Number:%s\nCustomer Ratings:%f",a[professional_choice-1].pname, a[professional_choice-1].charges_hour,a[professional_choice-1].mobile_number,a[professional_choice-1].rating);
        total = a[professional_choice-1].charges_hour * work_hours;
        printf("\n\n************");
		printf("\nTotal Amount: %f\n", total);
		
        fp2=fopen("electricianbookinghistory.txt","a");
        fprintf ( fp2, "%s\t%s\t%d\t%s\t%f\t%f\n",email,a[professional_choice-1].pname, a[professional_choice-1].charges_hour,a[professional_choice-1].mobile_number,a[professional_choice-1].rating,total);
		fclose(fp2);
			
	}
	else if(search_choice == 2)
    {
    	printf("Name: %s\nCharges per Hour:%d\nMobile Number:%s\nCustomer Ratings:%f",b[professional_choice-1].pname, b[professional_choice-1].charges_hour,b[professional_choice-1].mobile_number,b[professional_choice-1].rating);
        total = b[professional_choice-1].charges_hour * work_hours;
		printf("\n\n************");
		printf("\nTotal Amount: %f\n", total);
		
		fp3=fopen("plumberbookinghistory.txt","a");
        fprintf ( fp3, "%s\t%s\t%d\t%s\t%f\t%f\n",email,b[professional_choice-1].pname, b[professional_choice-1].charges_hour,b[professional_choice-1].mobile_number,b[professional_choice-1].rating,total);
		fclose(fp3);
	}
	else if(search_choice == 3)
    {
    	printf("Name: %s\nCharges per Hour:%d\nMobile Number:%s\nCustomer Ratings:%f",c[professional_choice-1].pname, c[professional_choice-1].charges_hour,c[professional_choice-1].mobile_number,c[professional_choice-1].rating);
        total = c[professional_choice-1].charges_hour * work_hours;
		printf("\n\n************");
		printf("\nTotal Amount: %f\n", total);
		
		fp4=fopen("carpenterbookinghistory.txt","a");
        fprintf ( fp4, "%s\t%s\t%d\t%s\t%f\t%f\n",email,c[professional_choice-1].pname, c[professional_choice-1].charges_hour,c[professional_choice-1].mobile_number,c[professional_choice-1].rating,total);
		fclose(fp4);
	}
	else if(search_choice == 4)
    {
    	printf("Name: %s\nCharges per Hour:%d\nMobile Number:%s\nCustomer Ratings:%f",d[professional_choice-1].pname, d[professional_choice-1].charges_hour,d[professional_choice-1].mobile_number,d[professional_choice-1].rating);
        total = d[professional_choice-1].charges_hour * work_hours;
		printf("\n\n************");
		printf("\nTotal Amount: %f\n", total);
		
		fp5=fopen("carservicesbookinghistory.txt","a");
        fprintf ( fp5, "%s\t%s\t%d\t%s\t%f\t%f\n",email,d[professional_choice-1].pname, d[professional_choice-1].charges_hour,d[professional_choice-1].mobile_number,d[professional_choice-1].rating,total);
		fclose(fp5);
	}
	else if(search_choice == 5)
    {
    	printf("Name: %s\nCharges per Hour:%d\nMobile Number:%s\nCustomer Ratings:%f",e[professional_choice-1].pname, e[professional_choice-1].charges_hour,e[professional_choice-1].mobile_number,e[professional_choice-1].rating);
        total = e[professional_choice-1].charges_hour * work_hours;
		printf("\n\n************");
		printf("\nTotal Amount: %f\n", total);
		
		fp6=fopen("handymanbookinghistory.txt","a");
        fprintf ( fp6, "%s\t%s\t%d\t%s\t%f\t%f\n",email,e[professional_choice-1].pname,e[professional_choice-1].charges_hour,e[professional_choice-1].mobile_number,e[professional_choice-1].rating,total);
		fclose(fp6);
	}
    
	 
    printf("\n\nDo You wish to order (yes=1/no=0):"); 
    scanf("%d", &ch); 
    if (ch == 1) 
	{
		printf("\nEnter your House no:");
		scanf("%d",&add.house_no);
		printf("Enter your Block:");
		scanf(" %c",&add.block);
        printf("Enter your Area:");
        scanf("%s",add.area);
        printf("Enter your City Name:");
        scanf("%s",&add.city);
        
        printf("\n\nYour Address:\nHouse No.%d, Block %c, %s, %s\n",add.house_no,add.block,add.area,add.city);
    
        printf("\nPayment Options:\n"); 
        printf("**********");
        printf("\n1)Cash on Delivery"); 
        printf("\n2)Via Credit card\n\n"); 
        scanf("%d",&cash);
        if(cash==1)
        {
        	SetColor(2);
        	printf("\n\nThank You for your order!! Our professional is on the way.\n\n");
        	return;
		}
		else if(cash==2)
		{
			printf("\n\nEnter Credit card number: \n");
			scanf("%d",&credit_num);
			printf("\nCash withdrawn from account number: %d\n", credit_num);
			SetColor(2);
			printf("\n\nPayment process completed.\n\n");
			printf("\n\nThank You for your order!! Our professional is on the way.\n\n");
			return;
		}
        
    } 
    else if (ch == 0) 
	{ 
        printf("If you want to exit press - 1 or if you want to go back press - 0"); 
        scanf("%d", &confirm); 
        if (confirm == 1)
		{ 
		    SetColor(4);
            printf("\n\nYour order has been cancelled!"); 
            printf("Thank You visit again!\n"); 
            // exit(1); 
            return; 
        } 
        else 
		{ 
		    SetColor(4);
            printf("\n\nThank You\n\n"); 
            login(); 
        } 
    } 
    else { 
    SetColor(4);
        printf("\n\nPlease Enter the correct choice\n\n");      
    } 
    
    

}

void SetColor(int ForgC)
{
 WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
 return;
 }
