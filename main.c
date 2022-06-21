/************************PREPROCESSOR************************/
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/************************GLOBAL VARIABLES************************/
// ALl the global variables and the composite data types will be declared here
typedef struct
{
  char name[50];
  int train_num;
  int num_of_seats;
} pd;

/************************FUNCTION
 * PROTOTYPE************************/
// function prototypes to be used
void reservation(void);                          // main reservation function
void view_details(void);                         // view details of all the trains
void print_ticket(char name[], int, int, float); // print ticket
void specific_train(int);                        // print data related to specific train
float charge(int, int);                          // charge automatically w.r.t number of seats and train
void login();

/************************FUNCTION
 * DECLARATION************************/

/************************MAIN************************/

int main()

{
  system("cls");
  printf("\t\t=================================================\n");
  printf("\t\t|                                               |\n");
  printf("\t\t|        -----------------------------          |\n");
  printf("\t\t|       TRAIN TICKET RESERVATION SYSTEM         |\n");
  printf("\t\t|        -----------------------------          |\n");
  printf("\t\t|                                               |\n");
  printf("\t\t|                                               |\n");
  printf("\t\t|                                               |\n");
  printf("\t\t|         UJJWAL SHARMA AND MANVEESH            |\n");
  printf("\t\t|          |  Reg.No.: 310 & 328  |             |\n");
  printf("\t\t|                                               |\n");
  printf("\t\t=================================================\n\n\n");

  printf(" \n Press any key to continue:");

  getch();
  system("cls");
  login();
  int menu_choice, choice_return;
start:
  system("cls");
  printf("\n=================================\n");
  printf("    TRAIN RESERVATION SYSTEM");
  printf("\n=================================");
  printf("\n1>> Reserve A Ticket");
  printf("\n------------------------");
  printf("\n2>> View All Available Trains");
  printf("\n------------------------");
  printf("\n3>> Exit");
  printf("\n------------------------");
  printf("\n\n-->");
  scanf("%d", &menu_choice);
  switch (menu_choice)
  {
  case 1:
    reservation();
    break;
  case 2:
    view_details();
    printf("\n\nPress any key to go to Main Menu..");
    getch();
    break;
  case 3:
    return (0);
  default:
    printf("\nInvalid choice");
  }
  goto start;
  return (0);
}

/************************VIEW_DETAILS************************/
void view_details(void)
{
  system("cls");
  printf("---------------------------------------------------------------------"
         "--------");
  printf("\nTr.No\tName\t\t\tDestinations\t\tCharges\t\tTime\n");
  printf("---------------------------------------------------------------------"
         "--------");
  printf("\n1001\tRed Lines Express\tBoston to Manhattan\tRs.5000\t\t9am");
  printf("\n1002\tRed Lines Express\tManhattan To Boston\tRs.5000\t\t12pm");
  printf("\n1003\tLA City Express\t\tBoston To L.A\t\tRs.4500\t\t8am");
  printf("\n1004\tLA City Express\t\tL.A To Boston\t\tRs.4500\t\t11am");
  printf("\n1005\tIron City Express\tBoston To Chicago\tRs.4000\t\t7am");
  printf("\n1006\tIron City Express\tChicago To Boston\tRs.4000\t\t9.30am");
  printf("\n1007\tKeystone Express\tBoston To Washington\tRs.3500\t\t1pm");
  printf("\n1008\tKeystone Express\tWashington To Boston\tRs.3500\t\t4pm");
  printf("\n1009\tMeteor Express\t\tBoston To Miami\t\tRs.6000\t\t3.35pm");
  printf("\n1009\tMeteor Express\t\tMiami To Boston\t\tRs.6000\t\t4.15pm");
}

/************************RESERVATION************************/
void reservation(void)
{
  char confirm;
  int i = 0;
  float charges;
  pd pass_details;
  FILE *fp;
  fp = fopen("seats_reserved.txt", "a");
  system("cls");

  printf("\nEnter Your Name:> ");
  scanf("%s", &pass_details.name);
  printf("\nEnter Number of seats:> ");
  scanf("%d", &pass_details.num_of_seats);
  printf("\n\n>>Press Enter To View Available Trains<< ");
  getch();
  system("cls");
  view_details();
  printf("\n\nEnter train number:> ");
start1:
  scanf("%d", &pass_details.train_num);
  if (pass_details.train_num >= 1001 && pass_details.train_num <= 1010)
  {
    charges = charge(pass_details.train_num, pass_details.num_of_seats);
    print_ticket(pass_details.name, pass_details.num_of_seats,
                 pass_details.train_num, charges);
  }
  else
  {
    printf("\nInvalid train Number! Enter again--> ");
    goto start1;
  }

  printf("\n\nConfirm Ticket (y/n):>");
start:
  scanf(" %c", &confirm);
  if (confirm == 'y')
  {
    fprintf(fp, "%s\t\t%d\t\t%d\t\t%.2f\n", &pass_details.name,
            pass_details.num_of_seats, pass_details.train_num, charges);
    printf("==================");
    printf("\n Reservation Done\n");
    printf("==================");
    printf("\nPress any key to go back to Main menu");
  }
  else
  {
    if (confirm == 'n')
    {
      printf(
          "\nReservation Not Done!\nPress any key to go back to  Main menu!");
    }
    else
    {
      printf("\nInvalid choice entered! Enter again-----> ");
      goto start;
    }
  }
  fclose(fp);
  getch();
}

/************************CHARGE************************/
float charge(int train_num, int num_of_seats)
{
  if (train_num == 1001)
  {
    return (5000.0 * num_of_seats);
  }
  if (train_num == 1002)
  {
    return (5000.0 * num_of_seats);
  }
  if (train_num == 1003)
  {
    return (4500.0 * num_of_seats);
  }
  if (train_num == 1004)
  {
    return (4500.0 * num_of_seats);
  }
  if (train_num == 1005)
  {
    return (4000.0 * num_of_seats);
  }
  if (train_num == 1006)
  {
    return (4000.0 * num_of_seats);
  }
  if (train_num == 1007)
  {
    return (3500.0 * num_of_seats);
  }
  if (train_num == 1008)
  {
    return (3500.0 * num_of_seats);
  }
  if (train_num == 1009)
  {
    return (6000.0 * num_of_seats);
  }
  if (train_num == 1010)
  {
    return (6000.0 * num_of_seats);
  }
}

/************************PRINT_TICKET************************/
void print_ticket(char name[], int num_of_seats, int train_num, float charges)
{
  system("cls");
  printf("-------------------\n");
  printf("\tTICKET\n");
  printf("-------------------\n\n");
  printf("Name:\t\t\t%s", name);
  printf("\nNumber Of Seats:\t%d", num_of_seats);
  printf("\nTrain Number:\t\t%d", train_num);
  specific_train(train_num);
  printf("\nCharges:\t\t%.2f", charges);
}

/************************SPECIFIC_TRAIN************************/
void specific_train(int train_num)
{

  if (train_num == 1001)
  {
    printf("\nTrain:\t\t\tRed Lines Express");
    printf("\nDestination:\t\tBoston to Manhattan");
    printf("\nDeparture:\t\t9am ");
  }
  if (train_num == 1002)
  {
    printf("\nTrain:\t\t\tRed Lines Express");
    printf("\nDestination:\t\tManhattan to Boston");
    printf("\nDeparture:\t\t12pm");
  }
  if (train_num == 1003)
  {
    printf("\nTrain:\t\t\tLA City Express");
    printf("\nDestination:\t\tBoston to L.A");
    printf("\nDeparture:\t\t8am");
  }
  if (train_num == 1004)
  {
    printf("\nTrain:\t\t\tLA City Express");
    printf("\nDestination:\t\tL.A to Boston");
    printf("\nDeparture:\t\t11am ");
  }
  if (train_num == 1005)
  {
    printf("\nTrain:\t\t\tIron City Express");
    printf("\nDestination:\t\tBoston to Chicago");
    printf("\nDeparture:\t\t7am");
  }
  if (train_num == 1006)
  {
    printf("\ntrain:\t\t\tIron City Express");
    printf("\nDestination:\t\tChicago to Boston");
    printf("\nDeparture:\t\t9.30am ");
  }
  if (train_num == 1007)
  {
    printf("\ntrain:\t\t\tKeystone Express");
    printf("\nDestination:\t\tBoston to Washington");
    printf("\nDeparture:\t\t1pm ");
  }
  if (train_num == 1008)
  {
    printf("\ntrain:\t\t\tKeystone Express");
    printf("\n Destination:\t\tWashington to Boston");
    printf("\nDeparture:\t\t4pm ");
  }
  if (train_num == 1009)
  {
    printf("\ntrain:\t\t\tMeteor Express");
    printf("\nDestination:\t\tBoston to Miami");
    printf("\nDeparture:\t\t3.35pm ");
  }
  if (train_num == 1010)
  {
    printf("\ntrain:\t\t\tMeteor Express");
    printf("\nDestination:\t\tMiami to Boston");
    printf("\nDeparture:\t\t4.15 ");
  }
}

void login()
{
  int a = 0, i = 0;
  char uname[10], c = ' ';
  char pword[10], code[10];
  char user[10] = "user";
  char pass[10] = "pass";
  do
  {

    printf(
        "\n  =======================  LOGIN FORM  =======================\n  ");
    printf(" \n                       ENTER USERNAME:-");
    scanf("%s", &uname);
    printf(" \n                       ENTER PASSWORD:-");
    while (i < 10)
    {
      pword[i] = getch();
      c = pword[i];
      if (c == 13)
        break;
      else
        printf("*");
      i++;
    }
    pword[i] = '\0';
    // char code=pword;
    i = 0;
    // scanf("%s",&pword);
    if (strcmp(uname, "user") == 0 && strcmp(pword, "pass") == 0)
    {
      printf(
          "  \n\n\n       WELCOME TO OUR SYSTEM !! YOUR LOGIN IS SUCCESSFUL");
      printf("\n\n\n\t\t\t\tPress any key to continue...");
      getch(); // holds the screen
      break;
    }
    else
    {
      printf("\n        SORRY !!!!  LOGIN IS UNSUCCESSFUL");
      a++;

      getch(); // holds the screen
      system("cls");
    }
  } while (a <= 2);
  if (a > 2)
  {
    printf("\nSorry you have entered the wrong username and password for four "
           "times!!!");

    getch();
  }
  system("cls");
}
